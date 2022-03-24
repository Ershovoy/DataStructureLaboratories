#include "AVLTree.h"

AVLTree::AVLTree() : _root{ nullptr }, _nodeRotateCount{ 0 }
{
}

AVLTree::~AVLTree()
{
	while (_root != nullptr)
	{
		Delete(_root->Key);
	}
}

void AVLTree::Insert(int key)
{
	_root = Insert(_root, key);
}

void AVLTree::Delete(int key)
{
	_root = Delete(_root, key);
}

AVLTreeNode* AVLTree::Find(int key)
{
	return Find(_root, key);
}

AVLTreeNode* AVLTree::Delete(AVLTreeNode* node, int key)
{
	if (node == nullptr)
	{
		throw "Element with that key value didn't exists, so can't delete nor element.";
	}


	if (key < node->Key)
	{
		node->Child[Left] = Delete(node->Child[Left], key);
	}
	else if (key > node->Key)
	{
		node->Child[Right] = Delete(node->Child[Right], key);
	}
	else
	{
		AVLTreeNode* left = node->Child[Left];
		AVLTreeNode* right = node->Child[Right];
		delete node;

		if (right == nullptr)
		{
			return left;
		}
		else
		{
			AVLTreeNode* minimumNode = FindMin(right);
			minimumNode->Child[Right] = DeleteMin(right);
			minimumNode->Child[Left] = left;
			return BalanceNode(minimumNode);
		}
	}
	return BalanceNode(node);
}

AVLTreeNode* AVLTree::Insert(AVLTreeNode* node, int key)
{
	if (!node)
	{
		return new AVLTreeNode{ key, 0, nullptr, nullptr };
	}
	else if (key < node->Key)
	{
		node->Child[Left] = Insert(node->Child[Left], key);
	}
	else if (key > node->Key)
	{
		node->Child[Right] = Insert(node->Child[Right], key);
	}
	else
	{
		throw "Element with that key already exists. AVLTree can't store two element with the same key.";
	}
	return BalanceNode(node);
}

AVLTreeNode* AVLTree::Find(AVLTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key < node->Key)
	{
		return Find(node->Child[Left], key);
	}
	else if (key > node->Key)
	{
		return Find(node->Child[Right], key);
	}
	else
	{
		return node;
	}
}

AVLTreeNode* AVLTree::FindMin(AVLTreeNode* node)
{
	if (node->Child[Left] != nullptr)
	{
		return FindMin(node->Child[Left]);
	}
	else
	{
		return node;
	}
}

AVLTreeNode* AVLTree::DeleteMin(AVLTreeNode* node)
{
	if (node->Child[Left] == nullptr)
	{
		return node->Child[Right];
	}
	else
	{
		node->Child[Left] = DeleteMin(node->Child[Left]);
		return BalanceNode(node);
	}
}

AVLTreeNode* AVLTree::Rotate(AVLTreeNode* node, bool direction)
{
	AVLTreeNode* newRoot = node->Child[!direction];
	node->Child[!direction] = newRoot->Child[direction];
	newRoot->Child[direction] = node;

	UpdateHeight(node);
	UpdateHeight(newRoot);

	_nodeRotateCount += 1;

	return newRoot;
}

AVLTreeNode* AVLTree::BalanceNode(AVLTreeNode* node)
{
	UpdateHeight(node);

	if (GetBalanceFactor(node) == 2)
	{
		if (GetBalanceFactor(node->Child[Right]) < 0)
		{
			node->Child[Right] = Rotate(node->Child[Right], 1);
		}
		return Rotate(node, 0);
	}
	if (GetBalanceFactor(node) == -2)
	{
		if (GetBalanceFactor(node->Child[Left]) > 0)
		{
			node->Child[Left] = Rotate(node->Child[Left], 0);
		}
		return Rotate(node, 1);
	}

	return node;
}

short int AVLTree::GetHeight(AVLTreeNode* node)
{
	return node ? node->Height : -1;
}

short int AVLTree::GetBalanceFactor(AVLTreeNode* node)
{
	return GetHeight(node->Child[Right]) - GetHeight(node->Child[Left]);
}

void AVLTree::UpdateHeight(AVLTreeNode* node)
{
	short int leftHeight = GetHeight(node->Child[Left]);
	short int rightHeight = GetHeight(node->Child[Right]);

	if (leftHeight < rightHeight)
	{
		node->Height = rightHeight + 1;
	}
	else
	{
		node->Height = leftHeight + 1;
	}
}

AVLTreeNode* AVLTree::GetRoot()
{
	return _root;
}