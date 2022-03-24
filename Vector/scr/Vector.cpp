#include "Vector.h"

void Reserve(Vector& vector, int capacity)
{
	int* newAlloc = new int[capacity];
	for (int i = 0; i < vector.Size; ++i)
	{
		newAlloc[i] = vector.IternalElements[i];
	}

	delete[] vector.IternalElements;

	vector.IternalElements = newAlloc;
	vector.Capacity = capacity;
}

void PushBack(Vector& vector, int value)
{
	if (vector.Size == vector.Capacity)
	{
		Reserve(vector, vector.Size * vector.GrowthFactor);
	}

	vector.IternalElements[vector.Size] = value;
	vector.Size += 1;
}

void PopBack(Vector& vector)
{
	if (vector.Size == 0)
	{
		throw "Vector hasn't element so can't delete nor element.";
	}

	vector.Size -= 1;
}

void Insert(Vector& vector, int offset, int value)
{
	if (offset < 0 || offset > vector.Size)
	{
		throw "Out of bounds of vector size. (offset must be between 0 and size of vector inclusive).";
	}

	if (vector.Size == vector.Capacity)
	{
		Reserve(vector, vector.Size * vector.GrowthFactor);
	}

	for (int i = vector.Size; i > offset; --i)
	{
		vector.IternalElements[i] = vector.IternalElements[i - 1];
	}

	vector.IternalElements[offset] = value;
	vector.Size += 1;
}

void PushFront(Vector& vector, int value)
{
	Insert(vector, 0, value);
}

void PopFront(Vector& vector)
{
	if (vector.Size == 0)
	{
		throw "Vector hasn't element so can't delete nor element.";
	}

	for (int i = 0; i < vector.Size; ++i)
	{
		vector.IternalElements[i] = vector.IternalElements[i + 1];
	}

	vector.Size -= 1;
}

void Sort(Vector& vector)
{
	for (int i = 0; i < vector.Size - 1; ++i)
	{
		int min = i;

		for (int j = i + 1; j < vector.Size; ++j)
		{
			if (vector.IternalElements[j] < vector.IternalElements[min])
			{
				min = j;
			}
		}

		double temp = vector.IternalElements[i];
		vector.IternalElements[i] = vector.IternalElements[min];
		vector.IternalElements[min] = temp;
	}
}

int FindLineary(Vector& vector, int value)
{
	for (int i = 0; i < vector.Size; ++i)
	{
		if (value == vector.IternalElements[i])
		{
			return i;
		}
	}

	return -1;
}

int FindBinary(Vector& vector, int value)
{
	int left = 0;
	int right = vector.Size - 1;
	while (left <= right)
	{
		int middle = floor((left + right) / 2);
		if (vector.IternalElements[middle] < value)
		{
			left = middle + 1;
		}
		else if (vector.IternalElements[middle] > value)
		{
			right = middle - 1;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}