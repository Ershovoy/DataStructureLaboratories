#include "Stack.h"
#include "RingBuffer.h"
#include "QueueByStack.h"
#include "QueueByRingBuffer.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "Enter 1 to add element to stack.\n";
	cout << "Enter 2 to pop newest elementof stack.\n";
	cout << "Enter 3 to print all element of stack.\n";

	cout << "Enter 4 to add element to ring buffer.\n";
	cout << "Enter 5 to pop lastly added element of ring buffer.\n";
	cout << "Enter 6 to print all element of ring buffer.\n";

	cout << "Enter 7 to add element to queue.\n";
	cout << "Enter 8 to pop lastly added element of queue.\n";
	cout << "Enter 9 to print all element of queue.\n";

	cout << "Enter 0 to close program.\n";
	cout << "\n";

	Stack stack;
	RingBuffer ringBuffer;

	QueueByStack queueByStack;
	QueueByRingBuffer queueByRingBuffer;

	cout << "Enter command: ";

	int prompt;
	while (cin >> prompt)
	{
		switch (prompt)
		{
			case 1:
			{
				cout << "Enter value of element for adding to top of stack: ";
				int value;
				cin >> value;
	
				stack.Push(value);
	
				break;
			}
			case 2:
			{
				try
				{
					cout << "Newest element of stack was deleted. It was equal to: "
						<< stack.Pop() << '\n';
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
	
				break;
			}
			case 3:
			{
				Stack temporaryStack;
	
				cout << "Stack: ";
				while (!stack.Empty())
				{
					int value = stack.Pop();
					temporaryStack.Push(value);
					
					cout << value << " -> ";
				}
				cout << "nullptr\n";
	
				while (!temporaryStack.Empty())
				{
					stack.Push(temporaryStack.Pop());
				}
	
				break;
			}
			case 4:
			{
				cout << "Enter value of element for adding to ring buffer: ";
				int value;
				cin >> value;
	
				ringBuffer.Add(value);
	
				break;
			}
			case 5:
			{
				try
				{
					cout << "Older element of ring buffer was deleted. It was equal to: "
						<< ringBuffer.Pop() << '\n';
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
	
				break;
			}
			case 6:
			{
				RingBuffer temporaryRingBuffer;
	
				cout << "RingBuffer: ";
				while (!ringBuffer.Empty())
				{
					int value = ringBuffer.Pop();
					temporaryRingBuffer.Add(value);
	
					cout << value << ", ";
				}
				cout << "\n";
	
				while (!temporaryRingBuffer.Empty())
				{
					ringBuffer.Add(temporaryRingBuffer.Pop());
				}
	
				break;
			}
			case 7:
			{
				cout << "Enter value of element for adding to queue: ";
				int value;
				cin >> value;
	
				queueByStack.Enqueue(value);
				queueByRingBuffer.Enqueue(value);
	
				break;
			}
			case 8:
			{
				try
				{
					cout << "Older element of queue was deleted. It was equal to: "
						<< queueByStack.Dequeue() << " and " << queueByRingBuffer.Dequeue() << '\n';
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}
	
				break;
			}
			case 9:
			{
				QueueByRingBuffer temporaryQueueByRingBuffer;
				QueueByStack temporaryQueueByStack;
	
				cout << "Queue (byStack, byRingBuffer): ";
				while (!queueByRingBuffer.Empty())
				{
					int valueByRingBuffer = queueByRingBuffer.Dequeue();
					int valueByStack = queueByStack.Dequeue();
	
					temporaryQueueByRingBuffer.Enqueue(valueByRingBuffer);
					temporaryQueueByStack.Enqueue(valueByStack);
	
					cout << "(" << valueByStack << ", " << valueByRingBuffer << "), ";
				}
				cout << " End of queue.\n";
	
				while (!temporaryQueueByRingBuffer.Empty())
				{
					queueByStack.Enqueue(temporaryQueueByStack.Dequeue());
					queueByRingBuffer.Enqueue(temporaryQueueByRingBuffer.Dequeue());
				}
	
				break;
			}
			default:
			{
				return 0;
			}
		}

		cout << "Enter new command: ";
	}

	return 0;
}