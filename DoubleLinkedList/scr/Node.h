#pragma once

class Node
{
public:
	Node(int data) : _iternalData{ data }, _previousNode{ nullptr }, _nextNode{ nullptr } {};

	/// <summary>
	/// ������ ����, ������ ��������� �������� ��������� �� �������, � ����� ��������� ������� �� �����.
	/// </summary>
	/// <param name="value">- �������� ������ �����.</param>
	/// <returns>���������� ��������� �� ������ ��� ��������� ����.</returns>
	Node* InsertLeft(int value);

	/// <summary>
	/// ������ ����, ����� ��������� �������� ��������� �� �������, � ������ ��������� ������� �� �����.
	/// </summary>
	/// <param name="value">- �������� ������ �����.</param>
	/// <returns>���������� ��������� �� ������ ��� ��������� ����.</returns>
	Node* InsertRight(int value);

	/// <summary>
	/// ������� ������� ����.
	/// </summary>
	void Erase();

	/// <summary>
	/// �������� �� ������ ��������� �� ����� ����, N ���������� ���.
	/// </summary>
	/// <param name="moveCount">- ���������� ��������� �� ������ ���������.</param>
	/// <returns>���������� ��������� �� ����, �� ������� ������������.</returns>
	Node* MoveLeft(int moveCount = 1);

	/// <summary>
	/// �������� �� ������� ��������� �� ����� ����, N ���������� ���.
	/// </summary>
	/// <param name="moveCount">- ���������� ��������� �� ������� ���������.</param>
	/// <returns>���������� ��������� �� ����, �� ������� ������������.</returns>
	Node* MoveRight(int moveCount = 1);

	/// <summary>
	/// ����� ����� ������ ��� �������� ����.
	/// </summary>
	/// <param name="value">- �������� ������.</param>
	void SetData(int value)
	{
		_iternalData = value;
	}

	/// <summary>
	/// �������� ������, ���������� � ������� ����.
	/// </summary>
	/// <returns>���������� ��������, ���������� � ������� ����.</returns>
	int GetData()
	{
		return _iternalData;
	}

private:
	int _iternalData;
	Node* _nextNode;
	Node* _previousNode;
};