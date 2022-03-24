#pragma once

#include <iostream>

/// <summary>
/// Структура данных динамический массив, способная теоретически хранить бесконечное число элементво.
/// </summary>
struct Vector
{
	Vector()
	{
		Capacity = 8;
		Size = 0;
		IternalElements = new int[Capacity] {0, 0, 0, 0, 0, 0, 0, 0};
	}
	~Vector()
	{
		delete[] IternalElements;
	}

	/// <summary>
	/// Вместимость динамического массива.
	/// </summary>
	int Capacity;

	/// <summary>
	/// Текущее количество элементов в динамическом массиве.
	/// </summary>
	int Size;

	/// <summary>
	/// Указатель на элементы динамического массива.
	/// </summary>
	int* IternalElements;

	/// <summary>
	/// Во сколько раз мы увеличиваем вместимость массива, когда он переполниться.
	/// </summary>
	const int GrowthFactor = 2;
};

/// <summary>
/// Позволяет задать максимальную вместимость массиву.
/// </summary>
/// <param name="vector">- искомый массив</param>
/// <param name="capacity">- новая вместимость массива</param>
void Reserve(Vector& vector, int capacity);

/// <summary>
/// Вставка элемента в конец массива.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение для вставки.</param>
void PushBack(Vector& vector, int value);

/// <summary>
/// Удаление элемента из конца массива
/// </summary>
/// <param name="vector">- искомый массив.</param>
void PopBack(Vector& vector);

/// <summary>
/// Вставка элемента массив.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="offset">- смешение относительно начала массива, задаётся для позиции вставки.</param>
/// <param name="value">- значение для вставки.</param>
void Insert(Vector& vector, int offset, int value);

/// <summary>
/// Вставка элемента в начало массива.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение для вставки.</param>
void PushFront(Vector& vector, int value);

/// <summary>
/// Удаление элемента из начала массива
/// </summary>
/// <param name="vector">- искомый массив.</param>
void PopFront(Vector& vector);

/// <summary>
/// Сортирует элементы массива по возрастанию. (Сортировка выбором)
/// </summary>
/// <param name="vector">- искомый массив.</param>
void Sort(Vector& vector);

/// <summary>
/// Найти индекс элемента по значению, поиск осуществляется линейно.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение индекс которого надо найти.</param>
/// <returns>Индекс элемента с заданным значением.</returns>
int FindLineary(Vector& vector, int value);

/// <summary>
/// Найти индекс элемента по значению, поиск осуществляется бинарно.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение, индекс которого надо найти.</param>
/// <returns>Индекс элемента с заданным значением.</returns>
int FindBinary(Vector& vector, int value);
