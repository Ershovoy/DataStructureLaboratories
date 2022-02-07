#pragma once

#include "HashMap.h"

class Map
{
public:
	/**
	 * @brief ��������� ������� � ������.
	 * @param key - ���� �� �������� �������������� ������ � �������� ��������.
	 * @param value - �������� ��������.
	*/
	void Insert(std::string key, std::string value);

	/**
	 * @brief ������� ������� �� ���-������� �� �����.
	 * @param key - ���� ��������, ������� �������� ���� �������.
	*/
	void Erase(std::string key);

	/**
	 * @brief ���������� ������� ������� � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	 * @param key - ���� �� �������� ������������� ����� ��������.
	 * @return ������� ��� nullptr ���� �� ������ �������.
	*/
	HashMapElement* Get(std::string key);

	/**
	 * @brief ���������� ������� �� ������� � �������, ����� nullptr ���� �������� � ������ ��������� ����.
	 * @param offset - ����� ������ �� ������.
	 * @param depth - ���������� ����� ������ �� ������������ ������.
	 * @return ������� ��� ������� ���������.
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

