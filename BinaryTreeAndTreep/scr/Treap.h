#pragma once

#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>

//TODO: rsdn
// ��������� ������, ��� ���� ������ ����� ������ ����� ������������� ����, � ���� ������� ������.
struct TreapNode
{
	// ���� �������� ����.
	int Key;
	// ��������� �������� ����.
	short Priority;
	// ��������� �� ����� ����.
	TreapNode* Left;
	// ��������� �� ������ ����.
	TreapNode* Right;
};

class Treap
{
public:
	Treap();
	~Treap();

	/**
	 * @brief ��������� ������� � ��������� ������ �� ���������������� ����������, ������������ 2 merge() � 1 split().
	 * @param Key - ���� ��������.
	*/
	void InsertNotOptimized(int key);

	/**
	 * @brief ��������� ������� � ��������� ������ ���������������� ����������, ������������ 1 split().
	 * @param Key - ���� ��������.
	*/
	void InsertOptimized(int key);

	/**
	 * @brief ������� ������� �� ��������� ������ �� ����� (������������ 1 merge(), 2 split()).
	 * @param Key - ���� ���������� ��������.
	*/
	void RemoveNotOptimized(int key);

	/**
	 * @brief ������� ������� �� ��������� ������ �� ����� (������������ 1 merge()).
	 * @param Key - ���� ���������� ��������.
	*/
	void RemoveOptimized(int key);

	/**
	 * @brief ���������� ������� ��������� ������ � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	 * @param Key - ���� �� �������� ������������� ����� ��������.
	 * @param subgraph - ������� � ������� ����� �������������� �����.
	 * @return ������� ��� nullptr ���� �� ������ �������.
	*/
	TreapNode* Find(int key, TreapNode* node);

	//TODO: rsdn
	
	/**
	 * @brief �������� ������� ������.
	 * @return �������� �������.
	*/
	int GetDepth();

	/**
	 * @brief �������� ������ ������.
	 * @return ��������� �� ���� �����.
	*/
	TreapNode* GetRoot()
	{
		return _root;
	}

private:
	//TODO: rsdn 
	
	/**
	 * @brief ���������� ��������� �� ������� ��������� ������ � �������� ������, 
	 * ���� ������� � �������� ������ �� ������, �� nullptr. ������������ ����� �������� ��������� ������������� �����.
	 * @param key - ���� �� �������� ������������� ����� ��������.
	 * @param node - ������� � ������� ����� �������������� �����.
	 * @return ��������� �� ������� ��� nullptr ���� �� ������ �������.
	*/
	TreapNode** FindPointerToNode(int key, TreapNode** node);

	/**
	 * @brief ���������� ��������� �� ������ ������� ��������� ������ � ��������� �������� ������ ���������, 
	 * @param node - ���� � �������� ����� �������������� �����.
	 * @param priority - �������� ���������.
	 * @return ��������� �� ���� ��������� �������� ������ ���������.
	*/
	TreapNode** FindPointerToLessPriorityNode(TreapNode** node, int priority);

	/**
	 * @brief ������� ��� ���������� ������ � ����. 
	 *        �������: ��� ����� � ����� ������ ������ ���� ������, ��� ����� � ������.
	 * @param left - ����� ������ (��� ���� < ����� ������� ������).
	 * @param right - ������ ������ (��� ���� > ����� ������ ������).
	 * @return ��������� ������ ���������� ��� ���� �� ������ � ������� ������.
	*/
	TreapNode* Merge(TreapNode* left, TreapNode* right);

	/**
	 * @brief ��������� �������� ������ �� �����, ����� �������� ������ ��� ��� ����� ������, ���������
	 * � ������ ��� ����� ������ ���������.
	 * @param node - ������ ������
	 * @param key - ���� �� �������� ����� ��������� ������
	 * @param left - ������ ��������� ��� ������, ��� ��� ����� ������.
	 * @param right - ������ ��������� ��� ������, ��� ��� ����� ������.
	*/
	void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

	TreapNode* _root;
};

