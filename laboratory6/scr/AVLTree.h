#pragma once

#include "TreeNodes.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	/// <summary>
	/// ������ ���� � ��� ������ � �������� ������.
	/// </summary>
	/// <param name="key">
	/// ����, ���������� ����.
	/// </param>
	void Insert(int key);

	/// <summary>
	/// ������� ������� �� ��� ������ � �������� ������.
	/// </summary>
	/// <param name="key">
	/// �������� �����
	/// </param>
	void Delete(int key);

	/// <summary>
	/// ���������� ������� ��� ������ � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	/// </summary>
	/// <param name="key">���� �� �������� ������������� ����� ��������.</param>
	/// <returns>
	/// ������� ��� nullptr ���� ������� �� ������.
	/// </returns>
	AVLTreeNode* Find(int key);

	/// <summary>
	/// ���������� ������ ��� ������ ��� nullptr.
	/// </summary>
	/// <returns>
	/// ����, ���������� ������ ��� nullptr.
	/// </returns>
	AVLTreeNode* GetRoot();

	/// <summary>
	/// ���������� ���������� ���������� ��������� ��� ������ �� ����� ������������� ������.
	/// </summary>
	int GetNodeRotateCount()
	{
		return _nodeRotateCount;
	}

	/// <summary>
	/// ���������� ���������� ���������� ������� ��� ����� �� ����.
	/// </summary>
	void ResetNodeRotateCount()
	{
		_nodeRotateCount = 0;
	}

private:
	/// <summary>
	/// ���������� ������ ���� � �������� ������ � �������� ���������, ����������� ����� ��������
	/// BalanceNode() ��� ������� ����, ��� �� ��������� ������������� ���������� � �������� ���������.
	/// </summary>
	/// <param name="node">������ ��������� �� ���� ����� �������������� �������.</param>
	/// <param name="key">����, ���������� ����.</param>
	/// <returns>
	/// ������, ����������������� ���������.
	/// </returns>
	AVLTreeNode* Insert(AVLTreeNode* node, int key);

	/// <summary>
	/// ���������� ������� ���� � �������� ������ � �������� ���������, ����������� ����� ��������
	/// BalanceNode() ��� ������� ����, ��� �� ��������� ������������� ���������� � �������� ���������.
	/// </summary>
	/// <param name="node">������ ��������� � �������� ����� �������������� ����� ���� � �������� ������.</param>
	/// <param name="key">����, ���������� ����</param>
	/// <returns>
	/// ������, ����������������� ��������� ��� ������� ���������.
	/// </returns>
	AVLTreeNode* Delete(AVLTreeNode* node, int key);

	/// <summary>
	/// ���������� ���� ���� � �������� ������ � �������� ����� ���������.
	/// </summary>
	/// <param name="node">������ ���������.</param>
	/// <param name="key">���� �� �������� ������������� ����� ��������.</param>
	/// <returns>
	/// ������� ��� nullptr ���� �� ������ �������.
	/// </returns>
	AVLTreeNode* Find(AVLTreeNode* node, int key);

	/// <summary>
	/// ����������� ����� ������������ ���� � �������� ���������.
	/// </summary>
	/// <param name="node">����, � ������� �������������� �����.</param>
	/// <returns>
	/// ����������� ���� � �������� ���������.
	/// </returns>
	AVLTreeNode* FindMin(AVLTreeNode* node);

	/// <summary>
	/// ���������� ������� ����������� ���� �� ��������� ���������, ����������� ����� ��������
	/// BalanceNode() ��� ������� ����, ��� �� ��������� ������������� ���������� � �������� ���������.
	/// </summary>
	/// <param name="node">����, � �������� �������������� ����� � ���������� ��������.</param>
	/// <returns>
	/// ����� ������ ����������� ���������, ����� ���� nullptr.
	/// </returns>
	AVLTreeNode* DeleteMin(AVLTreeNode* node);

	/// <summary>
	/// �����/������ ������� ������ ��������� ���� � �������� �����������. 
	/// ��� �����/������ ��������� ����������� �����, ������� ���� �����/������ �������� ����
	/// �� ��������, � ������/����� �������� ���� ��������� ���� �� ������ ���������.
	/// </summary>
	/// <param name="node">����, ������ �������� ����� �������� �������.</param>
	/// <param name="direction">����������� ��������: 0 - �����, 1 - ������.</param>
	/// <returns>
	/// ����� ������ ����������� ���������.
	/// </returns>
	AVLTreeNode* Rotate(AVLTreeNode* node, bool direction);

	/// <summary>
	/// ���������� ��������� ��������� ����, �������� ������� ��� ��������� �������.
	/// </summary>
	/// <param name="node">����, ��������� �������� ���� ���������.</param>
	/// <returns>
	/// ����� ������ ������������� ����.
	/// </returns>
	AVLTreeNode* BalanceNode(AVLTreeNode* node);

	/// <summary>
	/// ��������� ������ ��������� ����.
	/// </summary>
	/// <param name="node">����, ������ �������� ���� �����.</param>
	/// <returns>
	/// ������ ���� ��� -1 ���� node == nullptr.
	/// </returns>
	short int GetHeight(AVLTreeNode* node);

	/// <summary>
	/// ��������� ������� ����� ������� � ������ ��������� ��������� ����.
	/// </summary>
	/// <param name="node">����, ������� ������ ����������� �������� ���� ���������.</param>
	/// <returns>
	/// ����� ������������� �����, ���� ������ ������� ��������� ������ ������.	
	/// ���� 0, ���� ������ ����������� �����. ����� �������������.
	/// </returns>
	short int GetBalanceFactor(AVLTreeNode* node);

	/// <summary>
	/// ������������ ������ ��������� ���� (��� �������, ��� ������ ��� ����������� �����).
	/// </summary>
	/// <param name="node">
	/// ����, ������ �������� ���� ��������������.
	/// </param>
	void UpdateHeight(AVLTreeNode* node);

	/// <summary>
	/// ������ ��� ������.
	/// </summary>
	AVLTreeNode* _root;

	/// <summary>
	/// ���������� ���������� ��������� �� ����� ������������� ������.
	/// </summary>
	int _nodeRotateCount;
};

