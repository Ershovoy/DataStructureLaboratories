#pragma once

// �������� ������, ��� ���� ������ ���� ������ ����� ������������� ����, � ���� ������� ������.
struct BinaryTreeNode
{
	// ���� �������� ����.
	int Key;
	// ��������� �� ����� ����.
	BinaryTreeNode* Left;
	// ��������� �� ������ ����.
	BinaryTreeNode* Right;
	// ��������� �� ������������ ����.
	BinaryTreeNode* Parent;
	// ��������� �������� ����.
	int Priority;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	/**
	 * @brief ��������� ������� � �������� ������.
	 * @param Key - ���� ��������.
	 * @param subgraph - ������� � ������� ����� �������� ����� �������.
	*/
	void Insert(int key, BinaryTreeNode* subgraph);

	/**
	 * @brief ������� ������� �� ��������� ������ �� �����.
	 * @param Key - ���� ���������� ��������.
	*/
	void Remove(int key);

	/**
	 * @brief ���������� ������� ��������� ������ � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	 * @param Key - ���� �� �������� ������������� ����� ��������.
	 * @param subgraph - ������� � ������� ����� �������������� �����.
	 * @return ������� ��� nullptr ���� �� ������ �������.
	*/
	BinaryTreeNode* Find(int key, BinaryTreeNode* subgraph);

	/**
	 * @brief ����� �������� ������� ��������.
	 * @param subgraph - ������� � ������� ����� �������������� ����� ��������.
	 * @return ����������� ������� ��������.
	*/
	BinaryTreeNode* FindMinimum(BinaryTreeNode* subgraph);

	/**
	 * @brief ����� ��������� ������� ��������.
	 * @param subgraph - ������� � ������� ����� �������������� ����� ���������.
	 * @return ������������ ������� ��������.
	*/
	BinaryTreeNode* FindMaximum(BinaryTreeNode* subgraph);

	/**
	 * @brief ���������� ��������� �� ������ �����.
	 * @return ��������� �� �������.
	*/
	BinaryTreeNode* GetRoot()
	{
		return _root;
	}

	/**
	 * @brief ���������� ������� �����.
	 * @return ������� �����.
	*/
	int GetDepth();

private:
	/**
	 * @brief ����������� �������, ������� ��������� ������� ������.
	 *		  ��������� ������� ������ � ������� �������, ������� ����� �������������� ����� �������� ������� �������� �������.
	 * @param node - ������ ������.
	 * @param nodeDepth - ������� ������� ����, ��� ����� ��� ����� 1.
	*/
	void UpdateDepth(BinaryTreeNode* node, int nodeDepth);

	BinaryTreeNode* _root;
	int _depth;
};

