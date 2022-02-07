#pragma once

#include "Stack.h"
#include "RingBuffer.h"

class QueueByStack
{
public:
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
	bool Empty()
	{
		return _queueBegin.Empty();
	}

private:
	Stack _queueBegin;
	Stack _queueEnd;
};

