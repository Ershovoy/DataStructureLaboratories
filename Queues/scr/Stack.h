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
	/// </summДобавляет элемент в верхушку стэка.ary>
	/// <param name="data">- Данные хранящиеся в элементе.</param>
	void Push(int data);

	/// <summary>
	/// Удаляет последний добавленый элемент в стэк.
	/// </summary>
	/// <returns>Возвращает значение этого элемента.</returns>
	int Pop();

	/// <summary>
	/// Удаляет все элементы стэка.
	/// </summary>
	void Clear();

	/// <summary>
	/// Позволяет узнать остались ли ещё элементы в стэке.
	/// </summary>
	/// <returns>Возвращает true если стэк пуст.</returns>
	bool Empty();

private:
	Element* _iternalElements;
};

