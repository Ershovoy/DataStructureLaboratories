#include "Treap.h"

Treap::Treap() : _root{ nullptr }
{
}

Treap::~Treap()
{
	while (_root != nullptr)
	{
		RemoveOptimized(_root->Key);
	}
}

void Treap::InsertNotOptimized(int key)
{
	if (_root == nullptr)
	{
		_root = new TreapNode{ key, short(rand()), nullptr, nullptr };
	}
	else if(Find(key, _root) == nullptr)
	{
		TreapNode* lessThanKey = nullptr;
		TreapNode* greaterThanKey = nullptr;
		Split(_root, key, lessThanKey, greaterThanKey);
		
		lessThanKey = Merge(lessThanKey, new TreapNode{ key, short(rand()), nullptr, nullptr });

		_root = Merge(lessThanKey, greaterThanKey);
	}
	else
	{
		throw "Element with this key value already exists. Treep can't store two element with the same key.";
	}
}

void Treap::InsertOptimized(int key)
{
	if (_root == nullptr)
	{
		_root = new TreapNode{ key, short(rand()), nullptr, nullptr };
	}
	else if (Find(key, _root) == nullptr)
	{
		short priority = short(rand());

		TreapNode** node = FindPointerToLessPriorityNode(&_root, priority);
		
		TreapNode* lessThanKey = nullptr;
		TreapNode* greaterThanKey = nullptr;

		Split(*node, key, lessThanKey, greaterThanKey);

		*node = new TreapNode{ key, priority, lessThanKey, greaterThanKey };
	}
	else
	{
		throw "Element with this key value already exists. Treep can't store two element with the same key.";
	}
}

void Treap::RemoveNotOptimized(int key)
{
	if (Find(key, _root) != nullptr)
	{
		TreapNode* lessThanKey = nullptr;
		TreapNode* greaterThanKey = nullptr;
		TreapNode* equalToKey = nullptr;

		Split(_root, key, lessThanKey, greaterThanKey);
		Split(greaterThanKey, key + 1, equalToKey, greaterThanKey);
		_root = Merge(lessThanKey, greaterThanKey);

		delete equalToKey;
	}
	else
	{
		throw "Element with that key value didn't exists, so can't delete nor element.";
	}
}

void Treap::RemoveOptimized(int key)
{
	if (Find(key, _root) != nullptr)
	{
		TreapNode** pointerToReleased = FindPointerToNode(key, &_root);
		TreapNode* released = *pointerToReleased;

		TreapNode* newNode = Merge(released->Left, released->Right);

		*pointerToReleased = newNode;

		delete released;
	}
	else
	{
		throw "Element with that key value didn't exists, so can't delete nor element.";
	}
}

TreapNode* Treap::Find(int key, TreapNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key < node->Key)
	{
		return Find(key, node->Left);
	}
	else if (key > node->Key)
	{
		return Find(key, node->Right);
	}
	else
	{
		return node;
	}
}

int Treap::GetDepth()
{
	if (_root == nullptr)
	{
		return 0;
	}
	else
	{
		int depth = 1;

		std::stack<TreapNode*> stack;
		std::vector<TreapNode*> visitedNode;
		stack.push(_root);
		visitedNode.push_back(_root);

		while (!stack.empty())
		{
			TreapNode* current = stack.top();

			//TODO: 
			if (current->Left != nullptr && std::find(visitedNode.begin(), visitedNode.end(), current->Left) == visitedNode.end())
			{
				visitedNode.push_back(current->Left);
				stack.push(current->Left);
			}
			else if (current->Right != nullptr && std::find(visitedNode.begin(), visitedNode.end(), current->Right) == visitedNode.end())
			{
				visitedNode.push_back(current->Right);
				stack.push(current->Right);
			}
			else
			{
				if (depth < stack.size())
				{
					depth = stack.size();
				}
				stack.pop();
			}
		}
		return depth;
	}
}

TreapNode** Treap::FindPointerToNode(int key, TreapNode** node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key < (*node)->Key)
	{
		return FindPointerToNode(key, &(*node)->Left);
	}
	else if (key > (*node)->Key)
	{
		return FindPointerToNode(key, &(*node)->Right);
	}
	else
	{
		return node;
	}
}

TreapNode** Treap::FindPointerToLessPriorityNode(TreapNode** node, int priority)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	std::queue<TreapNode**> queue;
	queue.push(node);
	while (!queue.empty())
	{
		TreapNode** current = queue.front();
		queue.pop();

		if (priority > (*current)->Priority)
		{
			return current;
		}

		if ((*current)->Left != nullptr)
		{
			queue.push(&(*current)->Left);
		}
		if ((*current)->Right != nullptr)
		{
			queue.push(&(*current)->Right);
		}
	}
	return nullptr;
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left ? left : right;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key < key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}
