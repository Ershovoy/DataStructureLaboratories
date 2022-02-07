#include "List.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

void MeasureExecutionTimeOf(string methodName, List& list);

int main()
{
	cout << "Enter 1 to print all vector list.\n";
	cout << "Enter 2 to add element to head of list.\n";
	cout << "Enter 3 to add element to tail of list.\n";
	cout << "Enter 4 to remove head element of list.\n";
	cout << "Enter 5 to remove tail element of list.\n";
	cout << "Enter 6 to insert element before certain index into list.\n";
	cout << "Enter 7 to insert element after certain index into list.\n";
	cout << "Enter 8 to sort elements of list.\n";
	cout << "Enter 9 to find element index of list linearly.\n";
	cout << "Enter 10 to run program execution tests.\n";
	cout << "Enter 0 to clsoe program.\n";

	List list;

	cout << "\nEnter command: ";
	int prompt;
	while (std::cin >> prompt)
	{
		switch (prompt)
		{
			case 1:
			{
				for (int i = 0; i < list.GetLength(); ++i)
				{
					cout << list.GetData(i) << ", ";
				}
				cout << '\n';
				break;
			}
			case 2:
			{
				cout << "Enter value for inserting to head: ";
				int value;
				cin >> value;

				list.AddHead(value);
				break;
			}
			case 3:
			{
				cout << "Enter value for inserting to tail: ";
				int value;
				cin >> value;

				list.AddTail(value);
				break;
			}
			case 4:
			{
				cout << "Fisrt element of list was deleted.";

				try
				{
					list.Erase(0);
				}
				catch (const char* error)
				{
					std::cerr << error << '\n';
				}
				break;
			}
			case 5:
			{
				cout << "Last element of list was deleted.";

				try
				{
					list.Erase(list.GetLength() - 1);
				}
				catch (const char* error)
				{
					std::cerr << error << '\n';
				}

				break;
			}
			case 6:
			{
				cout << "Enter value for inserting: ";
				int value;
				cin >> value;

				cout << "Enter before what index perform inserting: ";
				int index;
				cin >> index;

				try
				{
					list.InsertBefore(index, value);
				}
				catch (const char* error)
				{
					std::cerr << error << '\n';
				}

				break;
			}
			case 7:
			{
				cout << "Enter value for inserting: ";
				int value;
				cin >> value;

				cout << "Enter after what index perform inserting: ";
				int index;
				cin >> index;

				try
				{
					list.InsertAfter(index, value);
				}
				catch (const char* error)
				{
					std::cerr << error << '\n';
				}

				break;
			}
			case 8:
			{
				cout << "Element of list was sorted.";

				list.SelectionSort();
				break;
			}
			case 9:
			{
				cout << "Enter value to find its position linary: ";
				int value;
				cin >> value;

				cout << "Position of " << value << " in list is " << list.Find(value);
				break;
			}
			case 10:
			{
				high_resolution_clock::time_point timeBegin, timeEnd;

				cout << "Enter a count of element for measuring time operation: ";
				int elementCount;
				cin >> elementCount;

				for (int i = 0; i < elementCount; ++i)
				{
					list.AddHead(rand());
				}

				try
				{
					MeasureExecutionTimeOf("AddHead()", list);
					MeasureExecutionTimeOf("AddTail()", list);
					/*MeasureExecutionTimeOf("InsertAfter()", list);
					MeasureExecutionTimeOf("InsertBefore()", list);
					MeasureExecutionTimeOf("Find()", list);
					if (elementCount < 100'000)
					{
						MeasureExecutionTimeOf("Sort()", list);
					}
					MeasureExecutionTimeOf("Erase()", list);*/
				}
				catch (const char* error)
				{
					cerr << error << '\n';
				}

				break;
			}
			default:
			{
				return 0;
			}
		}
		cout << "\nEnter new command: ";
	}
	return 0;
}

void MeasureExecutionTimeOf(string methodName, List& list)
{
	high_resolution_clock::time_point timeBegin, timeEnd;

	timeBegin = high_resolution_clock::now();

	if (methodName == "AddHead()")
	{
		list.AddHead(rand());
	}
	else if (methodName == "AddTail()")
	{
		list.AddTail(rand());
	}
	else if (methodName == "InsertAfter()")
	{
		list.InsertAfter(list.GetLength() - 1, rand());
	}
	else if (methodName == "InsertBefore()")
	{
		list.InsertBefore(list.GetLength() - 1, rand());
	}
	else if (methodName == "Find()")
	{
		list.Find(list.GetData(list.GetLength() - 1));
	}
	else if (methodName == "Sort()")
	{
		list.SelectionSort();
	}
	else if (methodName == "Erase()")
	{
		list.Erase(list.GetLength() - 1);
	}
	else
	{
		throw "Error: methodName parament is incorrect.";
	}

	timeEnd = high_resolution_clock::now();

	cout << "Execution time of \"" << methodName << "\" operation on list with " << list.GetLength()
		<< " elements: " << duration_cast<nanoseconds>(timeEnd - timeBegin).count() << " in seconds.\n";
}