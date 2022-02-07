#pragma once

#include "Node.h"

class List
{
public:
	List() : _length{ 0 }, _head{ nullptr }, _tail{ nullptr } {}
	~List();

	/// <summary>
	/// Добавить элемент в начало списка O(1)
	/// </summary>
	/// <param name="value">- значение для вставки.</param>
	void AddHead(int value);

	/// <summary>
	/// Добавить элемент в конец списка. O(1)
	/// </summary>
	/// <param name="value">- значение для вставки.</param>
	void AddTail(int value);

	/// <summary>
	/// Вставить элемент до определённой позиции. O(n)
	/// </summary>
	/// <param name="index">- индекс элемента после которого нужно выполнить вставку.</param>
	/// <param name="value">- значение для вставки.</param>
	void InsertBefore(int index, int value);

	/// <summary>
	/// Вставить элемент после определённой позиции. O(n)
	/// </summary>
	/// <param name="index">- индекс элемента перед которым нужно выполнить вставку.</param>
	/// <param name="value">- значение для вставки.</param>
	void InsertAfter(int index, int value);

	/// <summary>
	/// Удалить элемент под определённым номером из списка. O(n)
	/// </summary>
	/// <param name="index">- индекс элемента для его удаления.</param>
	void Erase(int index);

	/// <summary>
	/// Удаляет все элементы списка.
	/// </summary>
	void Clear();

	/// <summary>
	/// Сортирует элементы списка по возрастанию.
	/// </summary>
	void SelectionSort();

	/// <summary>
	/// Найти индекс элемента по значению, поиск осуществляется линейно.
	/// </summary>
	/// <param name="value">- значение индекс которого надо найти.</param>
	/// <returns>Индекс элемента с заданным значением.</returns>
	int Find(int value);

	/// <summary>
	/// Функция для получения значения элемента под определённым индексом.
	/// </summary>
	/// <param name="index">- индекс элемента.</param>
	/// <returns>Значение элемента под определённым индексом.</returns>
	int GetData(int index)
	{
		return _head->MoveRight(index)->GetData();
	}
	
	/// <summary>
	/// Функция для получения длины списка.
	/// </summary>
	/// <returns>Длина списка</returns>
	int GetLength()
	{
		return _length;
	}

private:
	int _length;
	Node* _head;
	Node* _tail;
};