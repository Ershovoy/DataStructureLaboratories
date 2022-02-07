#pragma once

#include "RingBuffer.h"

class QueueByRingBuffer
{
public:
	QueueByRingBuffer() : _iternalElements{ nullptr }, _size{ 0 }, _capacity{ 8 }{}
	~QueueByRingBuffer();

	/// <summary>
	/// ��������� ������� � ������.
	/// </summary>
	/// <param name="value">- �������� ��������.</param>
	void Enqueue(int value);

	/// <summary>
	/// ���������� ����� ���� �������� ������� �� �������.
	/// </summary>
	/// <returns>�������� ������������� ��������.</returns>
	int Dequeue();

	/// <summary>
	/// ��������� ������ �������� �� ��� �������� � �������.
	/// </summary>
	/// <returns>���������� true ���� ������� �����.</returns>
	bool Empty();

private:
	RingBuffer* _iternalElements = nullptr;
	int _size;
	int _capacity;
	const int _growthFactor = 2;
};

