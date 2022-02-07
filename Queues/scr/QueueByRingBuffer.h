#pragma once

#include "RingBuffer.h"

class QueueByRingBuffer
{
public:
	QueueByRingBuffer() : _iternalElements{ nullptr }, _size{ 0 }, _capacity{ 8 }{}
	~QueueByRingBuffer();

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
	bool Empty();

private:
	RingBuffer* _iternalElements = nullptr;
	int _size;
	int _capacity;
	const int _growthFactor = 2;
};

