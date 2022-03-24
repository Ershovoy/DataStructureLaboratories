#include "RingBuffer.h"

RingBuffer::~RingBuffer()
{
	delete[] _iternalElements;
}

void RingBuffer::Add(int value)
{
	_iternalElements[_headIndex] = value;

	if (_isFull)
	{
		_tailIndex = (_tailIndex + 1) % _capacity;
	}

	_headIndex = (_headIndex + 1) % _capacity;

	if (_headIndex == _tailIndex)
	{
		_isFull = true;
	}
}

int RingBuffer::Pop()
{
	if (!_isFull && _headIndex == _tailIndex)
	{
		throw "Trying to get element that wasn't added.";
	}

	int result = _iternalElements[_tailIndex];

	_tailIndex = (_tailIndex + 1) % _capacity;

	_isFull = false;

	return result;
}

bool RingBuffer::Empty()
{
	return !_isFull && _headIndex == _tailIndex;
}
