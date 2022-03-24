#include "HashMap.h"

HashMap::HashMap() : _capacity{ 8 }, _size{ 0 }
{
	_iternalData = new HashMapElement * [_capacity]();
}

HashMap::~HashMap()
{
	for (int i = 0; i < _capacity; ++i)
	{
		HashMapElement* iterator = _iternalData[i];
		while (iterator != nullptr)
		{
			HashMapElement* next = iterator->next;

			delete iterator;

			iterator = next;
		}
	}
	delete[] _iternalData;
}

void HashMap::Insert(std::string key, std::string value)
{
	if (_size / double(_capacity) > _fillFactor)
	{
		Rehashing();
	}

	int index = PearsonHashing(key);

	if (_iternalData[index] == nullptr)
	{
		_iternalData[index] = new HashMapElement{ key, value, nullptr };
	}
	else
	{
		_iternalData[index] = new HashMapElement{ key, value, _iternalData[index] };
	}

	_size += 1;
}

void HashMap::Erase(std::string key)
{
	int index = PearsonHashing(key);

	HashMapElement** previous = &_iternalData[index];
	HashMapElement* iterator = _iternalData[index];

	while (iterator != nullptr)
	{
		if (iterator->key == key)
		{
			*previous = iterator->next;
			delete iterator;
			_size -= 1;
			return;
		}

		previous = &(*previous)->next;
		iterator = iterator->next;
	}

	throw "Can't delete nor element with that key.";
}

HashMapElement* HashMap::Get(std::string key)
{
	int index = PearsonHashing(key);

	HashMapElement* iterator = _iternalData[index];
	while (iterator != nullptr)
	{
		if (iterator->key == key)
		{
			return iterator;
		}

		iterator = iterator->next;
	}

	return nullptr;
}

int HashMap::PearsonHashing(std::string string)
{
	// Каждое простое число может быть представлено в виде (6 * x - 1) и (6 * X + 1) кроме (2 и 3).
	// Находим простое число ближайшее к значению capacity, и меньшее него. Оно и будет взаимно простым.
	int primeNumberToCapacity = int((_capacity - 1) / 6) * 6 - 1;

	int hashResult = 0;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		hashResult = (hashResult * primeNumberToCapacity + string[i]) % _capacity;
	}

	return hashResult;
}

void HashMap::Rehashing()
{
	int previousCapacity = _capacity;
	_capacity = int(_capacity * _growthFactor);
	HashMapElement** newAllocation = new HashMapElement * [_capacity]();

	for (int i = 0; i < previousCapacity; ++i)
	{
		HashMapElement* iterator = _iternalData[i];
		while (iterator != nullptr)
		{
			int index = PearsonHashing(iterator->key);

			HashMapElement* next = iterator->next;

			if (newAllocation[index] == nullptr)
			{
				newAllocation[index] = iterator;
				newAllocation[index]->next = nullptr;
			}
			else
			{
				iterator->next = newAllocation[index];
				newAllocation[index] = iterator;
			}

			iterator = next;
		}
	}

	delete[] _iternalData;
	_iternalData = newAllocation;
}

HashMapElement* HashMap::GetElementByIndexes(int offset, int depth)
{
	HashMapElement* iterator = _iternalData[offset];
	for (int i = 0; i < depth; ++i)
	{
		if (iterator != nullptr)
		{
			iterator = iterator->next;
		}
	}
	return iterator;
}