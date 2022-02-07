#include "IOVector.h"

using namespace std;

void PrintVectorMenu(Vector& vector)
{
	enum VectorOperation
	{
		Print = 1,
		InsertEnd,
		InsertBegin,
		RemoveEnd,
		RemoveBegin,
		InsertElement,
		RemoveElement,
		FindElementLinearly,
		FindElementBinary
	};

	cout << "Enter 1 to print all vector elements.\n";
	cout << "Enter 2 to add element to end of vector.\n";
	cout << "Enter 3 to add element to beginning of vector.\n";
	cout << "Enter 4 to remove last element of vector.\n";
	cout << "Enter 5 to remove first element of vector.\n";
	cout << "Enter 6 to insert element into vector.\n";
	cout << "Enter 7 to sort elements of vector.\n";
	cout << "Enter 8 to find vector element linearly.\n";
	cout << "Enter 9 to find vector element binary.\n";
	cout << "Enter 0 to close program.\n";
	cout << "\n";

	cout << "Enter command: ";

	int prompt;
	while (cin >> prompt)
	{
		switch (prompt)
		{
			case Print:
			{
				for (int i = 0; i < vector.Size; ++i)
				{
					cout << vector.IternalElements[i] << ", ";
				}
				cout << '\n';
				break;
			}
			case InsertEnd:
			{
				cout << "Enter value of element for adding to end of vector: ";
				double value;
				cin >> value;
				PushBack(vector, value);
				break;
			}

			case InsertBegin:
			{
				cout << "Enter value of element for adding to beginning of vector: ";
				double value;
				cin >> value;
				PushFront(vector, value);
				break;
			}
			case RemoveEnd:
			{
				try
				{
					PopBack(vector);
					cout << "Last element was deleted.\n";
				}
				catch (char const* ch)
				{
					std::cerr << ch << '\n';
				}

				break;
			}
			case RemoveBegin:
			{
				try
				{
					PopFront(vector);
					cout << "First element was deleted.\n";
				}
				catch (char const* ch)
				{
					std::cerr << ch << '\n';
				}

				break;
			}
			case InsertElement:
			{
				cout << "Enter position of element: ";
				int position;
				cin >> position;

				cout << "Enter value of element for inserting: ";
				double value;
				cin >> value;

				try
				{
					Insert(vector, position, value);
				}
				catch (char const* ch)
				{
					std::cerr << ch << '\n';
				}

				break;
			}
			case RemoveElement:
			{
				cout << "Elements of vector was sorted.\n";
				Sort(vector);
				break;
			}
			case FindElementLinearly:
			{
				cout << "Enter value to find lineary: ";
				double value;
				cin >> value;

				cout << "Position of " << value << " in vector is " << FindLineary(vector, value) << '\n';
				break;
			}
			case FindElementBinary:
			{
				cout << "Enter value to find binary: ";
				double value;
				cin >> value;

				cout << "Position of " << value << " in vector is " << FindBinary(vector, value) << '\n';
				break;
			}
			default:
			{
				return;
			}
		}

		cout << "Enter new command: ";
	}
}
