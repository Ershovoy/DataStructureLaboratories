#pragma once

class RingBuffer
{
public:
	RingBuffer(int capacity = 8) : _iternalElements{ new int[capacity] }, _headIndex{ 0 },
		_tailIndex{ 0 }, _capacity{ capacity }, _isFull{ false }{}
	~RingBuffer();

	/// <summary>
	/// Добавляет элемент в свободную ячейку кольцевого буфера
	/// или переписывает последнюю добавленную если свободных ячеек не осталось.
	/// </summary>
	/// <param name="value">- значение элемента.</param>
	void Add(int value);

	/// <summary>
	/// Возвращает ранее всех вошедший элемент из колцьевого буфера, освобожная место для нового элемента.
	/// </summary>
	/// <returns>Значение возвращённого элемента.</returns>
	int Pop();

	/// <summary>
	/// Позволяет узнать остались ли ещё элементы в кольцевой буфере.
	/// </summary>
	/// <returns>Возвращает true если кольцевой буфер пуст.</returns>
	bool Empty();

private:
	int* _iternalElements;
	int _headIndex;
	int _tailIndex;
	const int _capacity;
	bool _isFull;
};