#pragma once

#include <string>

struct HashMapElement
{
	std::string key;
	std::string value;
	HashMapElement* next;
};

class HashMap
{
public:
	HashMap();
	~HashMap();

	/// <summary>
	/// Добавляет элемент в хэш-таблицу.
	/// </summary>
	/// <param name="key">- ключ по которому осуществляется доступ к значению элемента.</param>
	/// <param name="value">- значение элемента.</param>
	void Insert(std::string key, std::string value);

	/// <summary>
	/// Удаляет элемент из хэш-таблицы по ключу.
	/// </summary>
	/// <param name="key">- ключ элемента, элемент которого надо удалить.</param>
	void Erase(std::string key);

	/// <summary>
	/// Возвращает элемент хэш-таблицы с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	/// </summary>
	/// <param name="key">- ключ по которому осуществяется поиск элемента.</param>
	/// <returns>Элемент или nullptr если не найден элемент.</returns>
	HashMapElement* Get(std::string key);

	/// <summary>
	/// Возвращает элемент по оффсету и глубине, вернёт nullptr если элемента с такими индексами нету.
	/// </summary>
	/// <param name="offset">- Номер односвязного списка по офсету.</param>
	/// <param name="depth">- Количество шагов вглубь по односвязному списку.</param>
	/// <returns>Элемент или нулевой указатель.</returns>
	HashMapElement* GetElementByIndexes(int offset, int depth);
	
	/// <summary>
	/// Возвращает вместимость хеш-таблицы.
	/// </summary>
	/// <returns>Целочисленное значение.</returns>
	int GetCapacity()
	{
		return _capacity;
	}

	/// <summary>
	/// Возвращает текущий размер хеш-таблицы.
	/// </summary>
	/// <returns>Целочисленное значение.</returns>
	int GetSize()
	{
		return _size;
	}

private:
	/// <summary>
	/// Хеширует строку, возвращая её хеш.
	/// </summary>
	/// <param name="string">- входная строка - ключ.</param>
	/// <returns>Целочисленный результат хеширования хеш в пределах [0, _size).</returns>
	int PearsonHashing(std::string string);

	/// <summary>
	/// Полностью перехиширует все элементы хеш-таблицы и резервирует дополнительное место под новые. 
	/// </summary>
	void Rehashing();

	HashMapElement** _iternalData;
	int _capacity;
	int _size;

	const double _growthFactor = 1.5;
	const double _fillFactor = 0.75;
};

