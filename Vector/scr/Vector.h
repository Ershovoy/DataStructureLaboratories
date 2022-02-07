#pragma once

#include <iostream>

/// <summary>
/// ��������� ������ ������������ ������, ��������� ������������ ������� ����������� ����� ���������.
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
	/// ����������� ������������� �������.
	/// </summary>
	int Capacity;

	/// <summary>
	/// ������� ���������� ��������� � ������������ �������.
	/// </summary>
	int Size;

	/// <summary>
	/// ��������� �� �������� ������������� �������.
	/// </summary>
	int* IternalElements;

	/// <summary>
	/// �� ������� ��� �� ����������� ����������� �������, ����� �� �������������.
	/// </summary>
	const int GrowthFactor = 2;
};

/// <summary>
/// ��������� ������ ������������ ����������� �������.
/// </summary>
/// <param name="vector">- ������� ������</param>
/// <param name="capacity">- ����� ����������� �������</param>
void Reserve(Vector& vector, int capacity);

/// <summary>
/// ������� �������� � ����� �������.
/// </summary>
/// <param name="vector">- ������� ������.</param>
/// <param name="value">- �������� ��� �������.</param>
void PushBack(Vector& vector, int value);

/// <summary>
/// �������� �������� �� ����� �������
/// </summary>
/// <param name="vector">- ������� ������.</param>
void PopBack(Vector& vector);

/// <summary>
/// ������� �������� ������.
/// </summary>
/// <param name="vector">- ������� ������.</param>
/// <param name="offset">- �������� ������������ ������ �������, ������� ��� ������� �������.</param>
/// <param name="value">- �������� ��� �������.</param>
void Insert(Vector& vector, int offset, int value);

/// <summary>
/// ������� �������� � ������ �������.
/// </summary>
/// <param name="vector">- ������� ������.</param>
/// <param name="value">- �������� ��� �������.</param>
void PushFront(Vector& vector, int value);

/// <summary>
/// �������� �������� �� ������ �������
/// </summary>
/// <param name="vector">- ������� ������.</param>
void PopFront(Vector& vector);

/// <summary>
/// ��������� �������� ������� �� �����������. (���������� �������)
/// </summary>
/// <param name="vector">- ������� ������.</param>
void Sort(Vector& vector);

/// <summary>
/// ����� ������ �������� �� ��������, ����� �������������� �������.
/// </summary>
/// <param name="vector">- ������� ������.</param>
/// <param name="value">- �������� ������ �������� ���� �����.</param>
/// <returns>������ �������� � �������� ���������.</returns>
int FindLineary(Vector& vector, int value);

/// <summary>
/// ����� ������ �������� �� ��������, ����� �������������� �������.
/// </summary>
/// <param name="vector">- ������� ������.</param>
/// <param name="value">- ��������, ������ �������� ���� �����.</param>
/// <returns>������ �������� � �������� ���������.</returns>
int FindBinary(Vector& vector, int value);
