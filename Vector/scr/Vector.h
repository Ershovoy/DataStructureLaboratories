#pragma once

#include <iostream>

/// <summary>
/// —труктура данных динамический массив, способна€ теоретически хранить бесконечное число элементво.
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
	/// ¬местимость динамического массива.
	/// </summary>
	int Capacity;

	/// <summary>
	/// “екущее количество элементов в динамическом массиве.
	/// </summary>
	int Size;

	/// <summary>
	/// ”казатель на элементы динамического массива.
	/// </summary>
	int* IternalElements;

	/// <summary>
	/// ¬о сколько раз мы увеличиваем вместимость массива, когда он переполнитьс€.
	/// </summary>
	const int GrowthFactor = 2;
};

/// <summary>
/// ѕозвол€ет задать максимальную вместимость массиву.
/// </summary>
/// <param name="vector">- искомый массив</param>
/// <param name="capacity">- нова€ вместимость массива</param>
void Reserve(Vector& vector, int capacity);

/// <summary>
/// ¬ставка элемента в конец массива.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение дл€ вставки.</param>
void PushBack(Vector& vector, int value);

/// <summary>
/// ”даление элемента из конца массива
/// </summary>
/// <param name="vector">- искомый массив.</param>
void PopBack(Vector& vector);

/// <summary>
/// ¬ставка элемента массив.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="offset">- смешение относительно начала массива, задаЄтс€ дл€ позиции вставки.</param>
/// <param name="value">- значение дл€ вставки.</param>
void Insert(Vector& vector, int offset, int value);

/// <summary>
/// ¬ставка элемента в начало массива.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение дл€ вставки.</param>
void PushFront(Vector& vector, int value);

/// <summary>
/// ”даление элемента из начала массива
/// </summary>
/// <param name="vector">- искомый массив.</param>
void PopFront(Vector& vector);

/// <summary>
/// —ортирует элементы массива по возрастанию. (—ортировка выбором)
/// </summary>
/// <param name="vector">- искомый массив.</param>
void Sort(Vector& vector);

/// <summary>
/// Ќайти индекс элемента по значению, поиск осуществл€етс€ линейно.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение индекс которого надо найти.</param>
/// <returns>»ндекс элемента с заданным значением.</returns>
int FindLineary(Vector& vector, int value);

/// <summary>
/// Ќайти индекс элемента по значению, поиск осуществл€етс€ бинарно.
/// </summary>
/// <param name="vector">- искомый массив.</param>
/// <param name="value">- значение, индекс которого надо найти.</param>
/// <returns>»ндекс элемента с заданным значением.</returns>
int FindBinary(Vector& vector, int value);
