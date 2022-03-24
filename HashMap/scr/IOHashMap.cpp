#include "IOHashMap.h"

void printHashMapMenu(HashMap& hashMap, Map& map)
{
	cout << "Enter 1 to insert element to HashMap.\n";
	cout << "Enter 2 to erase element of HashMap.\n";
	cout << "Enter 3 to get element of HashMap by key.\n";
	cout << "Enter 4 to print all element of HashMap.\n";

	cout << "Enter 5 to insert element to Map.\n";
	cout << "Enter 6 to erase element of Map.\n";
	cout << "Enter 7 to get element of Map by key.\n";
	cout << "Enter 8 to print all element of Map.\n";

	cout << "Enter 0 to close program.\n";
	cout << "\n";

	cout << "Enter command: ";

	int prompt;
	while (cin >> prompt)
	{
		switch (prompt)
		{
			case 1:
			{
				cout << "Enter element key and element data: ";

				string key, value;
				cin >> key >> value;

				hashMap.Insert(key, value);

				break;
			}
			case 2:
			{
				cout << "Enter key of element: ";

				string key;
				cin >> key;

				try
				{
					hashMap.Erase(key);
					cout << "Element of HashMap was deleted.\n";
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}

				break;
			}
			case 3:
			{
				cout << "Enter key to find element: ";

				string key;
				cin >> key;

				HashMapElement* element = hashMap.Get(key);

				cout << "Element equal to: (" << element->key << ", " << element->value << ")" << " -> " << element->next << ";\n";

				break;
			}
			case 4:
			{
				std::cout << "[\n";
				for (int i = 0; i < hashMap.GetCapacity(); ++i)
				{
					std::cout << "\t{ " << i << ": ";

					HashMapElement* iterator = hashMap.GetElementByIndexes(i, 0);
					while (iterator != nullptr)
					{
						std::cout << "(" << iterator->key << " - " << iterator->value << ") -> ";

						iterator = iterator->next;
					}

					std::cout << "() }" << '\n';
				}
				std::cout << "]\n";
				break;
			}
			case 5:
			{
				cout << "Enter element key and element data: ";

				string key, value;
				cin >> key >> value;

				try
				{
					map.Insert(key, value);
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}

				break;
			}
			case 6:
			{
				cout << "Enter key of element: ";

				string key;
				cin >> key;

				try
				{
					map.Erase(key);
					cout << "Element of HashMap was deleted.\n";
				}
				catch (char const* error)
				{
					cerr << error << '\n';
				}

				break;
			}
			case 7:
			{
				cout << "Enter key to find element: ";

				string key;
				cin >> key;

				HashMapElement* element = map.Get(key);

				cout << "Element equal to: (" << element->key << ", " << element->value << ")" << " -> " << element->next << ";\n";

				break;
			}
			case 8:
			{
				std::cout << "[\n";
				for (int i = 0; i < map.GetCapacity(); ++i)
				{
					std::cout << "\t{ " << i << ": ";

					HashMapElement* iterator = map.GetElementByIndexes(i, 0);
					while (iterator != nullptr)
					{
						std::cout << "(" << iterator->key << " - " << iterator->value << ") -> ";

						iterator = iterator->next;
					}

					std::cout << "() }" << '\n';
				}
				std::cout << "]\n";
				break;
			}
			default:
			{
				return;
			}
		}

		cout << "Enter new command: ";
	}
	return;
}