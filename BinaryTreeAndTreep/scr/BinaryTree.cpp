#include "BinaryTree.h"

BinaryTree::BinaryTree() : _root(nullptr), _depth{ 0 }
{
}

BinaryTree::~BinaryTree()
{
	while (_root != nullptr)
	{
		Remove(_root->Key);
	}
}

void BinaryTree::Insert(int key, BinaryTreeNode* subgraph)
{
	if (_root == nullptr)
	{
		_root = new BinaryTreeNode{ key, nullptr, nullptr, nullptr };
	}
	else if (key < subgraph->Key)
	{
		if (subgraph->Left == nullptr)
		{
			subgraph->Left = new BinaryTreeNode{ key, nullptr, nullptr, subgraph };
		}
		else
		{
			return Insert(key, subgraph->Left);
		}
	}
	else if (key > subgraph->Key)
	{
		if (subgraph->Right == nullptr)
		{
			subgraph->Right = new BinaryTreeNode{ key, nullptr, nullptr, subgraph };
		}
		else
		{
			return Insert(key, subgraph->Right);
		}
	}
	else
	{
		throw "Element with this key value already exists. Binary Tree can't store two element with the same key.";
	}
}

//TODO: naming (remove)
void BinaryTree::Remove(int key)
{
	BinaryTreeNode* released = Find(key, _root);

	if (released != nullptr)
	{
		if (released->Right != nullptr)
		{
			BinaryTreeNode* subgraphMinimum = FindMinimum(released->Right);
			if (released->Left != nullptr)
			{
				subgraphMinimum->Left = released->Left;
				released->Left->Parent = subgraphMinimum;
			}
			if (subgraphMinimum != released->Right)
			{
				subgraphMinimum->Parent->Left = nullptr;
				subgraphMinimum->Right = released->Right;
				released->Right->Parent = subgraphMinimum;
			}

			if (released != _root)
			{
				subgraphMinimum->Parent = released->Parent;

				if (key < released->Parent->Key)
				{
					released->Parent->Left = subgraphMinimum;
				}
				else
				{
					released->Parent->Right = subgraphMinimum;
				}
			}
			else
			{
				_root = subgraphMinimum;
				_root->Parent = nullptr;
			}
		}
		else if (released->Left != nullptr)
		{
			if (released != _root)
			{
				released->Left->Parent = released->Parent;

				if (key < released->Parent->Key)
				{
					released->Parent->Left = released->Left;
				}
				else
				{
					released->Parent->Right = released->Left;
				}
			}
			else
			{
				_root = released->Left;
				_root->Parent = nullptr;
			}
		}
		else
		{
			if (released != _root)
			{
				if (key < released->Parent->Key)
				{
					released->Parent->Left = nullptr;
				}
				else
				{
					released->Parent->Right = nullptr;
				}
			}
			else
			{
				_root = nullptr;
			}
		}
		delete released;
	}
	else
	{
		throw "Element with that key value didn't exists, so can't delete nor element.";
	}
}

BinaryTreeNode* BinaryTree::Find(int key, BinaryTreeNode* subgraph)
{
	if (subgraph == nullptr)
	{
		return nullptr;
	}

	if (key < subgraph->Key)
	{
		return Find(key, subgraph->Left);
	}
	else if (key > subgraph->Key)
	{
		return Find(key, subgraph->Right);
	}
	else
	{
		return subgraph;
	}
}

BinaryTreeNode* BinaryTree::FindMinimum(BinaryTreeNode* subgraph)
{
	if (subgraph->Left == nullptr)
	{
		return subgraph;
	}
	else
	{
		return FindMinimum(subgraph->Left);
	}
}

BinaryTreeNode* BinaryTree::FindMaximum(BinaryTreeNode* subgraph)
{
	if (subgraph->Right == nullptr)
	{
		return subgraph;
	}
	else
	{
		return FindMaximum(subgraph->Right);
	}
}

int BinaryTree::GetDepth()
{
	_depth = 0;
	UpdateDepth(_root, 1);
	return _depth;
}

void BinaryTree::UpdateDepth(BinaryTreeNode* node, int nodeDepth)
{
	if (node == nullptr)
	{
		return;
	}
	UpdateDepth(node->Left, nodeDepth + 1);
	UpdateDepth(node->Right, nodeDepth + 1);
	if (nodeDepth > _depth)
	{
		_depth = nodeDepth;
	}
}