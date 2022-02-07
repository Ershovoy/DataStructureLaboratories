#pragma once

struct Element
{
	int data;
	Element* next;
};

class Stack
{
public:
	Stack() : _iternalElements{ nullptr } {}
	~Stack();

	/// <summary>
	/// 
	/// </summ��������� ������� � �������� �����.ary>
	/// <param name="data">- ������ ���������� � ��������.</param>
	void Push(int data);

	/// <summary>
	/// ������� ��������� ���������� ������� � ����.
	/// </summary>
	/// <returns>���������� �������� ����� ��������.</returns>
	int Pop();

	/// <summary>
	/// ������� ��� �������� �����.
	/// </summary>
	void Clear();

	/// <summary>
	/// ��������� ������ �������� �� ��� �������� � �����.
	/// </summary>
	/// <returns>���������� true ���� ���� ����.</returns>
	bool Empty();

private:
	Element* _iternalElements;
};

