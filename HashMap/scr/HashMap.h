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
	/// ��������� ������� � ���-�������.
	/// </summary>
	/// <param name="key">- ���� �� �������� �������������� ������ � �������� ��������.</param>
	/// <param name="value">- �������� ��������.</param>
	void Insert(std::string key, std::string value);

	/// <summary>
	/// ������� ������� �� ���-������� �� �����.
	/// </summary>
	/// <param name="key">- ���� ��������, ������� �������� ���� �������.</param>
	void Erase(std::string key);

	/// <summary>
	/// ���������� ������� ���-������� � �������� ������, ���� ������� � �������� ������ �� ������, �� nullptr.
	/// </summary>
	/// <param name="key">- ���� �� �������� ������������� ����� ��������.</param>
	/// <returns>������� ��� nullptr ���� �� ������ �������.</returns>
	HashMapElement* Get(std::string key);

	/// <summary>
	/// ���������� ������� �� ������� � �������, ����� nullptr ���� �������� � ������ ��������� ����.
	/// </summary>
	/// <param name="offset">- ����� ������������ ������ �� ������.</param>
	/// <param name="depth">- ���������� ����� ������ �� ������������ ������.</param>
	/// <returns>������� ��� ������� ���������.</returns>
	HashMapElement* GetElementByIndexes(int offset, int depth);
	
	/// <summary>
	/// ���������� ����������� ���-�������.
	/// </summary>
	/// <returns>������������� ��������.</returns>
	int GetCapacity()
	{
		return _capacity;
	}

	/// <summary>
	/// ���������� ������� ������ ���-�������.
	/// </summary>
	/// <returns>������������� ��������.</returns>
	int GetSize()
	{
		return _size;
	}

private:
	/// <summary>
	/// �������� ������, ��������� � ���.
	/// </summary>
	/// <param name="string">- ������� ������ - ����.</param>
	/// <returns>������������� ��������� ����������� ��� � �������� [0, _size).</returns>
	int PearsonHashing(std::string string);

	/// <summary>
	/// ��������� ������������ ��� �������� ���-������� � ����������� �������������� ����� ��� �����. 
	/// </summary>
	void Rehashing();

	HashMapElement** _iternalData;
	int _capacity;
	int _size;

	const double _growthFactor = 1.5;
	const double _fillFactor = 0.75;
};

