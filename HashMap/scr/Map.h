#pragma once

#include "HashMap.h"

class Map
{
public:
	/**
	 * @brief Добавляет элемент в словаь.
	 * @param key - ключ по которому осуществляется доступ к значению элемента.
	 * @param value - значение элемента.
	*/
	void Insert(std::string key, std::string value);

	/**
	 * @brief Удаляет элемент из хэш-таблицы по ключу.
	 * @param key - ключ элемента, элемент которого надо удалить.
	*/
	void Erase(std::string key);

	/**
	 * @brief Возвращает элемент словаря с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	 * @param key - ключ по которому осуществяется поиск элемента.
	 * @return Элемент или nullptr если не найден элемент.
	*/
	HashMapElement* Get(std::string key);

	/**
	 * @brief Возвращает элемент по оффсету и глубине, вернёт nullptr если элемента с такими индексами нету.
	 * @param offset - Номер списка по офсету.
	 * @param depth - Количество шагов вглубь по односвязному списку.
	 * @return Элемент или нулевой указатель.
	*/
	HashMapElement* GetElementByIndexes(int offset, int depth);

	int GetCapacity()
	{
		return _iternalData.GetCapacity();
	}
	int GetSize()
	{
		return _iternalData.GetSize();
	}

private:
	HashMap _iternalData;
};

