#include "Node.h"

Node* Node::InsertLeft(int value)
{
	Node* newLink = new Node{ value };

	if (this != nullptr)
	{
		newLink->_nextNode = this;
		if (_previousNode != nullptr)
		{
			_previousNode->_nextNode = newLink;
			newLink->_previousNode = _previousNode;
		}
		_previousNode = newLink;
	}

	return newLink;
}

Node* Node::InsertRight(int value)
{
	Node* newLink = new Node{ value };

	if (this != nullptr)
	{
		newLink->_previousNode = this;
		if (_nextNode != nullptr)
		{
			_nextNode->_previousNode = newLink;
			newLink->_nextNode = _nextNode;
		}
		_nextNode = newLink;
	}

	return newLink;
}

void Node::Erase()
{
	if (this == nullptr)
	{
		return;
	}

	if (this->_nextNode)
	{
		this->_nextNode->_previousNode = this->_previousNode;
	}

	if (this->_previousNode)
	{
		this->_previousNode->_nextNode = this->_nextNode;
	}

	delete this;
}

Node* Node::MoveLeft(int moveCount)
{
	Node* result = this;

	for (int i = 0; i < moveCount; ++i)
	{
		if (result->_previousNode == nullptr)
		{
			throw "Can't move to object that wasn't created.";
		}
		result = result->_previousNode;
	}

	return result;
}

Node* Node::MoveRight(int moveCount)
{
	Node* result = this;

	if (result == nullptr)
	{
		throw "Can't move to object that wasn't created.";
	}

	for (int i = 0; i < moveCount; ++i)
	{
		if (result->_nextNode == nullptr)
		{
			throw "Can't move to object that wasn't created.";
		}
		result = result->_nextNode;
	}

	return result;
}
