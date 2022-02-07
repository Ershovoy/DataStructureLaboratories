#pragma once

class RingBuffer
{
public:
	RingBuffer(int capacity = 8) : _iternalElements{ new int[capacity] }, _headIndex{ 0 },
		_tailIndex{ 0 }, _capacity{ capacity }, _isFull{ false }{}
	~RingBuffer();

	/// <summary>
	/// ��������� ������� � ��������� ������ ���������� ������
	/// ��� ������������ ��������� ����������� ���� ��������� ����� �� ��������.
	/// </summary>
	/// <param name="value">- �������� ��������.</param>
	void Add(int value);

	/// <summary>
	/// ���������� ����� ���� �������� ������� �� ���������� ������, ���������� ����� ��� ������ ��������.
	/// </summary>
	/// <returns>�������� ������������� ��������.</returns>
	int Pop();

	/// <summary>
	/// ��������� ������ �������� �� ��� �������� � ��������� ������.
	/// </summary>
	/// <returns>���������� true ���� ��������� ����� ����.</returns>
	bool Empty();

private:
	int* _iternalElements;
	int _headIndex;
	int _tailIndex;
	const int _capacity;
	bool _isFull;
};