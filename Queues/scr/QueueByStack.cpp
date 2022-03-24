#include "QueueByStack.h"

void QueueByStack::Enqueue(int value)
{
	while (!_queueBegin.Empty())
	{
		_queueEnd.Push(_queueBegin.Pop());
	}

	_queueBegin.Push(value);

	while (!_queueEnd.Empty())
	{
		_queueBegin.Push(_queueEnd.Pop());
	}
}

int QueueByStack::Dequeue()
{
	if (_queueBegin.Empty())
	{
		throw "Queue has't elements, so can't dequeue nor element.";
	}

	return _queueBegin.Pop();
}
