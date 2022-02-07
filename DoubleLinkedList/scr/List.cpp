#include "List.h"

List::~List()
{
	while (_head != _tail)
	{
		Node* list = _head;
		_head = _head->MoveRight();
		list->Erase();
	}
	_head->Erase();
}

void List::AddHead(int value)
{
	_head = _head->InsertLeft(value);

	if (_length == 0)
	{
		_tail = _head;
	}

	_length += 1;
}

void List::AddTail(int value)
{
	_tail = _tail->InsertRight(value);

	if (_length == 0)
	{
		_head = _tail;
	}

	_length += 1;
}

void List::InsertBefore(int index, int value)
{
	if (index >= _length || index < 0)
	{
		throw "Index can't be negative number or be greater than length of list.";
	}

	if (_length == 0)
	{
		AddHead(value);
	}
	else
	{
		_head->MoveRight(index)->InsertLeft(value);

		if (index == 0)
		{
			_head = _head->MoveLeft();
		}

		_length += 1;
	}
}

void List::InsertAfter(int index, int value)
{
	if (index >= _length || index < 0)
	{
		throw "Index can't be negative number or be greater than length of list.";
	}

	if (_length == 0)
	{
		AddTail(value);
	}
	else
	{
		_head->MoveRight(index)->InsertRight(value);

		if (index == _length - 1 && _length != 0)
		{
			_tail = _tail->MoveRight();
		}

		_length += 1;
	}
}

void List::Erase(int index)
{
	Node* link = _head;

	if (_length == 1)
	{
		link->Erase();
		_head = nullptr;
		_tail = nullptr;
		_length = 0;
		return;
	}

	if (index == _length - 1)
	{
		_tail = _tail->MoveLeft();
	}
	else if (index == 0)
	{
		_head = _head->MoveRight();
	}

	link->MoveRight(index)->Erase();

	_length -= 1;
}

void List::Clear()
{
	while (_head != _tail)
	{
		Node* list = _head;
		_head = _head->MoveRight();
		list->Erase();
	}
	_head->Erase();

	_head = nullptr;
	_tail = nullptr;
	_length = 0;
}

void List::SelectionSort()
{
	for (int i = 0; i < _length - 1; ++i)
	{
		int min = i;

		for (int j = i + 1; j < _length; ++j)
		{
			if (_head->MoveRight(j)->GetData() < _head->MoveRight(min)->GetData())
				min = j;
		}

		int temp = _head->MoveRight(i)->GetData();
		_head->MoveRight(i)->SetData(_head->MoveRight(min)->GetData());
		_head->MoveRight(min)->SetData(temp);
	}
}

int List::Find(int value)
{
	Node* iterator = _head;

	if (iterator->GetData() == value)
	{
		return 0;
	}

	for (int i = 1; i < _length; ++i)
	{
		iterator = iterator->MoveRight();

		if (iterator->GetData() == value)
		{
			return i;
		}
	}

	return -1;
}
