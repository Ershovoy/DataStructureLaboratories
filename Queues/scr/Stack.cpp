#include "Stack.h"

Stack::~Stack()
{
	Element* iterator = _iternalElements;
	while (iterator != nullptr)
	{
		Element* released = iterator;
		iterator = iterator->next;
		delete released;
	}
}

void Stack::Push(int value)
{
	_iternalElements = new Element{ value, _iternalElements };
}

int Stack::Pop()
{
	if (_iternalElements == nullptr)
	{
		throw "No elements in the stack, so can't pop nor element.";
	}

	Element* released = _iternalElements;
	_iternalElements = _iternalElements->next;
	int result = released->data;
	delete released;

	return result;
}

void Stack::Clear()
{
	while (_iternalElements != nullptr)
	{
		Pop();
	}
}

bool Stack::Empty()
{
	return _iternalElements == nullptr;
}