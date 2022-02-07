#pragma once

#include "Node.h"

class List
{
public:
	List() : _length{ 0 }, _head{ nullptr }, _tail{ nullptr } {}
	~List();

	/// <summary>
	/// �������� ������� � ������ ������ O(1)
	/// </summary>
	/// <param name="value">- �������� ��� �������.</param>
	void AddHead(int value);

	/// <summary>
	/// �������� ������� � ����� ������. O(1)
	/// </summary>
	/// <param name="value">- �������� ��� �������.</param>
	void AddTail(int value);

	/// <summary>
	/// �������� ������� �� ����������� �������. O(n)
	/// </summary>
	/// <param name="index">- ������ �������� ����� �������� ����� ��������� �������.</param>
	/// <param name="value">- �������� ��� �������.</param>
	void InsertBefore(int index, int value);

	/// <summary>
	/// �������� ������� ����� ����������� �������. O(n)
	/// </summary>
	/// <param name="index">- ������ �������� ����� ������� ����� ��������� �������.</param>
	/// <param name="value">- �������� ��� �������.</param>
	void InsertAfter(int index, int value);

	/// <summary>
	/// ������� ������� ��� ����������� ������� �� ������. O(n)
	/// </summary>
	/// <param name="index">- ������ �������� ��� ��� ��������.</param>
	void Erase(int index);

	/// <summary>
	/// ������� ��� �������� ������.
	/// </summary>
	void Clear();

	/// <summary>
	/// ��������� �������� ������ �� �����������.
	/// </summary>
	void SelectionSort();

	/// <summary>
	/// ����� ������ �������� �� ��������, ����� �������������� �������.
	/// </summary>
	/// <param name="value">- �������� ������ �������� ���� �����.</param>
	/// <returns>������ �������� � �������� ���������.</returns>
	int Find(int value);

	/// <summary>
	/// ������� ��� ��������� �������� �������� ��� ����������� ��������.
	/// </summary>
	/// <param name="index">- ������ ��������.</param>
	/// <returns>�������� �������� ��� ����������� ��������.</returns>
	int GetData(int index)
	{
		return _head->MoveRight(index)->GetData();
	}
	
	/// <summary>
	/// ������� ��� ��������� ����� ������.
	/// </summary>
	/// <returns>����� ������</returns>
	int GetLength()
	{
		return _length;
	}

private:
	int _length;
	Node* _head;
	Node* _tail;
};