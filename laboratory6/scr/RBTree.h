#pragma once

#include "TreeNodes.h"

class RBTree
{
public:
	RBTree();
	~RBTree();

	/// <summary>
	/// ������ ���� � ������-������ ������ � �������� ������.
	/// </summary>
	/// <param name="key">
	/// ����, ���������� ����.
	/// </param>
	void Insert(int key);

	/// <summary>
	/// ������� ����� ������� ���� ��� ������ ���� � ����� ������� �� ������-������� ������.
	/// </summary>
	/// <param name="key">
	/// ���� ���������� ����.
	/// </param>
	void Delete(int key);

	/// <summary>
	/// ���������� ������� ������-������� ������ � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	/// </summary>
	/// <param name="key">���� �� �������� ������������� ����� ��������.</param>
	/// <returns>
	/// ������� ��� nullptr ���� ������� �� ������.
	/// </returns>
	RBTreeNode* Find(int key);

	/// <summary>
	/// ���������� ������ ������-������� ������ ��� nullptr.
	/// </summary>
	/// <returns>
	/// ����, ���������� ������ ��� nil (��������� ����).
	/// </returns>
	RBTreeNode* GetRoot()
	{
		return _root;
	}

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
	/// ��������� ������� �� �������� ����.
	/// </summary>
	/// <returns>true ���� ���� ������� � �� ����� nullptr, ����� false</returns>
	bool IsRed(RBTreeNode* node);

	/// <summary>
	/// ���������� ������ ���� � �������� ������ � �������� ���������, ����������� ����� ��������
	/// InsertFixLeft() ��� ������ �� ������ ���� � InsertFixRight() ��� �������, ��� ������������ �����.
	/// </summary>
	/// <param name="node">������ ��������� �� ���� ����� �������������� �������.</param>
	/// <param name="key">����, ���������� ����.</param>
	/// <returns>
	/// ������, ����������������� ���������.
	/// </returns>
	RBTreeNode* Insert(RBTreeNode* node, int key);

	/// <summary>
	/// ���������� ������� ����� ������� ���� ��� ������ ���� � ����� ������� � �������� ���������
	/// </summary>
	/// <param name="node">������ ��������� � �������� ����� �������������� ����� ���� � �������� ������.</param>
	/// <param name="key">����, ���������� ����.</param>
	/// <param name="isBalanced">���� ������ ����� ��������������� ��������� ���� ����.</param>
	/// <returns>
	/// ������, ����������������� ��������� ��� ������� ���������.
	/// </returns>
	RBTreeNode* Delete(RBTreeNode* node, int key, bool& isBalanced);

	/// <summary>
	/// ���������� �� ����� ������ �� �������� ��� ������� ���� � �������� �������.
	/// ���������� ������ ����� ��������� ���� ������, ���������� ������ ����� ������ ��� �������.
	/// </summary>
	/// <param name="node">������� ���� �������� � ��������</param>
	/// <param name="isBalanced">��������� ���� ���� ����� � ������ ������ ������� ���������</param>
	/// <returns>����� ������ ����������������� ��� ��� ���������.</returns>
	RBTreeNode* DeleteFix(RBTreeNode* node, bool direction, bool& isBalanced);

	/// <summary>
	/// ���������� ���� ���� � �������� ������ � �������� ����� ���������.
	/// </summary>
	/// <param name="node">������ ���������.</param>
	/// <param name="key">���� �� �������� ������������� ����� ��������.</param>
	/// <returns>
	/// ������� ��� nullptr ���� �� ������ �������.
	/// </returns>
	RBTreeNode* Find(RBTreeNode* node, int key);

	/// <summary>
	/// ���������� �� ����� ������ �� �������� ��� ������� ���� � �������� �������
	/// ���������� ��� ������� ���� ������ ������.
	/// </summary>
	/// <param name="node">������� ���� �������� � ����������</param>
	/// <returns>����� ������ ����������������� ��������� ������ ������.</returns>
	RBTreeNode* InsertFix(RBTreeNode* node, bool direction);

	/// <summary>
	/// ����������� ���� ������ ��������� ���� � ��� �����.
	/// </summary>
	void FlipColor(RBTreeNode* node);

	/// <summary>
	/// �����/������ ������� ������ ��������� ���� � �������� �����������. ��� �����/������ ��������� ����������� �����, ������� ���� �����/������ �������� ����
	/// �� ��������, � ������/����� �������� ���� ��������� ���� �� ������ ���������.
	/// </summary>
	/// <param name="node">����, ������ �������� ����� �������� �������.</param>
	/// <param name="direction">����������� ��������: 0 - �����, 1 - ������.</param>
	/// <returns>
	/// ����� ������ ����������� ���������.
	/// </returns>
	RBTreeNode* Rotate(RBTreeNode* node, bool direction);

	/// <summary>
	/// ������ ������-������� ������.
	/// </summary>
	RBTreeNode* _root;

	/// <summary>
	/// ���������� ���������� ��������� �� ����� ������������� ������.
	/// </summary>
	int _nodeRotateCount;
};