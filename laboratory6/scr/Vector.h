#pragma once

template<typename Type>
class Vector
{
public:
	Vector();
	~Vector();

	/// <summary>
	/// Вставка элемента в массив.
	/// </summary>
	/// <param name="value">- значение элемента для вставки.</param>
	/// <param name="index">- в какой индекс массива вставить элемент.</param>
	void InsertElement(Type value, unsigned int index);

	/// <summary>
	/// Удалить элемент массива под определённым индексом.
	/// </summary>
	/// <param name="index">- индекс элемента.</param>
	void DeleteElement(unsigned int index);

	/// <summary>
	/// Вставка элемента в начало массива.
	/// </summary>
	/// <param name="value">- значение для вставки.</param>
	void PushFront(Type value);

	/// <summary>
	/// Вставка элемента в конец массива.
	/// </summary>
	/// <param name="value">- значение для вставки.</param>
	void PushBack(Type value);

	/// <summary>
	/// Удаление элемента из начала массива.
	/// </summary>
	void PopFront();

	/// <summary>
	/// Удаление элемента из конца массива.
	/// </summary>
	void PopBack();

	/// <summary>
	/// Найти индекс элемента по значению, вернёт -1 если элемент не найдет, поиск осуществляется линейно.
	/// </summary>
	/// <param name="value">- значение, индекс которого надо найти.</param>
	/// <returns>Индекс элемента с заданным значением или -1 если такого элемента с таким значением нет.</returns>
	int FindLinary(Type value);

	/// <summary>
	/// Найти индекс элемента по значению, вернёт -1 если элемент не найдет, поиск осуществляется бинарно.
	/// </summary>
	/// <param name="value">- значение, индекс которого надо найти.</param>
	/// <returns>Индекс элемента с заданным значением или -1 если такого элемента с таким значением нет.</returns>
	int FindBinary(Type value);

	/// <summary>
	/// Сортирует элементы массива по возрастанию. (Сортировка выбором)
	/// </summary>
	void Sort();

	/// <summary>
	/// Получить элемент динамического массива по его индексу.
	/// </summary>
	/// <param name="index">- индекс получаемого элемента.</param>
	/// <returns>Элемент под данным индексом.</returns>
	Type GetElement(unsigned int index);
	Type operator[](unsigned int index);

	/// <summary>
	/// Возвращает текущий размер массива.
	/// </summary>
	/// <returns>Беззнаковое целое число.</returns>
	unsigned int GetSize() const;

	/// <summary>
	/// Возвращает вместимость массива.
	/// </summary>
	/// <returns>Беззнаковое целое число</returns>
	unsigned int GetCapacity() const;

private:
	/// <summary>
	/// Проверяет не выходит ли индекс за размеры массива (0 <= index < size).
	/// </summary>
	/// <param name="index">- проверяемый индекс.</param>
	/// <returns>Возвращает true если индекс не выходит за границы массива, иначе false</returns>
	bool IsIndexCorrect(int index);

	/// <summary>
	/// Позволяет задать вместимость массиву (максимальное возможное число хранимых элементов).
	/// </summary>
	/// <param name="capacity">- новая вместимость массива.</param>
	void Reserve(unsigned int capacity);

	Type* _iternalElements;

	unsigned int _capacity;
	unsigned int _size;
	const double _growthFactor;
};