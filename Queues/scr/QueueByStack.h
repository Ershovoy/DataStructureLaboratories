#pragma once

#include "Stack.h"
#include "RingBuffer.h"

class QueueByStack
{
public:
	/// <summary>
	/// Добавляет элемент в очеред.
	/// </summary>
	/// <param name="value">- значение элемента.</param>
	void Enqueue(int value);

	/// <summary>
	/// Возвращает ранее всех вошедший элемент из очереди.
	/// </summary>
	/// <returns>Значение возвращённого элемента.</returns>
	int Dequeue();

	/// <summary>
	/// Позволяет узнать остались ли ещё элементы в очереде.
	/// </summary>
	/// <returns>Возвращает true если очередь пуста.</returns>
	bool Empty()
	{
		return _queueBegin.Empty();
	}

private:
	Stack _queueBegin;
	Stack _queueEnd;
};

