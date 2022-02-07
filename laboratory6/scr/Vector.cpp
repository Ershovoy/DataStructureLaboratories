#include "Vector.h"

template<typename Type>
Vector<Type>::Vector() : _capacity{ 8 }, _size{ 0 }, _growthFactor{ 1.5 }
{
	_iternalElements = new Type[8];
}

template<typename Type>
Vector<Type>::~Vector()
{
	delete[] _iternalElements;
}

template<typename Type>
void Vector<Type>::InsertElement(Type value, unsigned int index)
{
	if (!IsIndexCorrect(index))
	{
		throw "Out of bounds of vector size. (index must be between 0 and size of vector inclusive).";
	}

	if (_size == _capacity)
	{
		Reserve(_size * _growthFactor);
	}

	for (int i = _size; i > index; --i)
	{
		_iternalElements[i] = _iternalElements[i - 1];
	}

	_iternalElements[index] = value;
	_size += 1;
}

template<typename Type>
void Vector<Type>::DeleteElement(unsigned int index)
{
	if (!IsIndexCorrect(index))
	{
		throw "Out of bounds of vector size. (index must be between 0 and size of vector inclusive).";
	}

	for (int i = index; i < _size - 1; ++i)
	{
		_iternalElements[i] = _iternalElements[i + 1];
	}

	_size -= 1;
}

template<typename Type>
void Vector<Type>::PushFront(Type value)
{
	InsertElement(value, 0);
}

template<typename Type>
void Vector<Type>::PushBack(Type value)
{
	if (_size == _capacity)
	{
		Reserve(_size * _growthFactor);
	}

	_iternalElements[_size] = value;
	_size += 1;
}

template<typename Type>
void Vector<Type>::PopFront()
{
	if (_size == 0)
	{
		throw "Vector hasn't element so can't delete nor element.";
	}

	for (int i = 0; i < _size - 1; ++i)
	{
		_iternalElements[i] = _iternalElements[i + 1];
	}

	_size -= 1;
}

template<typename Type>
void Vector<Type>::PopBack()
{
	if (_size == 0)
	{
		throw "Vector hasn't element so can't delete nor element.";
	}

	_size -= 1;
}

template<typename Type>
void Vector<Type>::Sort()
{
	for (int i = 0; i < _size - 1; ++i)
	{
		int min = i;

		for (int j = i + 1; j < _size; ++j)
		{
			if (_iternalElements[j] < _iternalElements[min])
			{
				min = j;
			}
		}

		double temporary = _iternalElements[i];
		_iternalElements[i] = _iternalElements[min];
		_iternalElements[min] = temporary;
	}
}

template<typename Type>
int Vector<Type>::FindLinary(Type value)
{
	for (int i = 0; i < _size; ++i)
	{
		if (value == _iternalElements[i])
		{
			return i;
		}
	}

	return -1;
}

template<typename Type>
int Vector<Type>::FindBinary(Type value)
{
	int leftBorder = 0;
	int rightBorder = _size - 1;
	while (leftBorder <= rightBorder)
	{
		int middle = (leftBorder + rightBorder) / 2;

		if (_iternalElements[middle] < value)
		{
			leftBorder = middle + 1;
		}
		else if (_iternalElements[middle] > value)
		{
			rightBorder = middle - 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}

template<typename Type>
Type Vector<Type>::GetElement(unsigned int index)
{
	if (!IsIndexCorrect(index))
	{
		throw "Out of bounds of vector size. (index must be between 0 and size of vector inclusive).";
	}
	else
	{
		return _iternalElements[index];
	}
}

template<typename Type>
Type Vector<Type>::operator[](unsigned int index)
{
	return GetElement(index);
}

template<typename Type>
unsigned int Vector<Type>::GetSize() const
{
	return _size;
}

template<typename Type>
unsigned int Vector<Type>::GetCapacity() const
{
	return _capacity;
}

template<typename Type>
bool Vector<Type>::IsIndexCorrect(int index)
{
	if (index < 0 || index > _size)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename Type>
void Vector<Type>::Reserve(unsigned int capacity)
{
	Type* newAllocation = new Type[capacity];
	for (int i = 0; i < _size; ++i)
	{
		newAllocation[i] = _iternalElements[i];
	}

	delete[] _iternalElements;

	_iternalElements = newAllocation;
	_capacity = capacity;
}