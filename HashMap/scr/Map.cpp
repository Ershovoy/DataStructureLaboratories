#include "Map.h"

void Map::Insert(std::string key, std::string value)
{
	if (_iternalData.Get(key) == nullptr)
	{
		_iternalData.Insert(key, value);
	}
	else
	{
		throw "Map can't store two element with the same key.";
	}
}

void Map::Erase(std::string key)
{
	_iternalData.Erase(key);
}

HashMapElement* Map::Get(std::string key)
{
	return _iternalData.Get(key);
}

HashMapElement* Map::GetElementByIndexes(int offset, int depth)
{
	return _iternalData.GetElementByIndexes(offset, depth);
}
