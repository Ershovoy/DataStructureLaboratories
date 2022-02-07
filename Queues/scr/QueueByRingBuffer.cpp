#include "QueueByRingBuffer.h"

QueueByRingBuffer::~QueueByRingBuffer()
{
	delete _iternalElements;
}

void QueueByRingBuffer::Enqueue(int value)
{
	if (_iternalElements == nullptr)
	{
		_iternalElements = new RingBuffer{ _capacity };
	}

	if (_size == _capacity)
	{
		RingBuffer* released = _iternalElements;

		while (!released->Empty())
		{
			_iternalElements->Add(released->Pop());
		}

		delete released;
	}

	_size += 1;

	_iternalElements->Add(value);
}

int QueueByRingBuffer::Dequeue()
{
	if (_size == 0)
	{
		throw "Queue has't elements, so can't dequeue nor element.";
	}

	_size -= 1;

	return _iternalElements->Pop();
}

bool QueueByRingBuffer::Empty()
{
	if (_iternalElements != nullptr)
	{
		return _iternalElements->Empty();;
	}
	else
	{
		return true;
	}
}
