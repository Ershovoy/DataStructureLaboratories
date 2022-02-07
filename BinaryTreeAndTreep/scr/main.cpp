#include "BinaryTree.h"
#include "Treap.h"

#include <iostream>
#include <string>
#include <queue>

using namespace std;

template<class T>
void printTree(T* node, int treeDepth);

int main()
{
	cout << "Enter 1 to insert element to Binary Tree.\n";
	cout << "Enter 2 to erase element from Binary Tree.\n";
	cout << "Enter 3 to print all element of Binary Tree.\n";

	cout << "Enter 4 to insert element to Treap by one split and two merge operation.\n";
	cout << "Enter 5 to insert element to Treap by one split operation.\n";
	cout << "Enter 6 to erase element of Treap by two split and one merge operation.\n";
	cout << "Enter 7 to erase element of Treap by one merge operation.\n";
	cout << "Enter 8 to print all element of Treap.\n";

	cout << "Enter 0 to close program.\n";
	cout << "\n";

	BinaryTree binaryTree;
	Treap treap;

	cout << "Enter command: ";

	int prompt;
	while (cin >> prompt)
	{
		switch (prompt)
		{
		case 1:
		{
			cout << "Enter element key: ";

			int key;
			cin >> key;

			try
			{
				binaryTree.Insert(key, binaryTree.GetRoot());
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			break;
		}
		case 2:
		{
			cout << "Enter key of element: ";

			int key;
			cin >> key;

			try
			{
				binaryTree.Remove(key);
				cout << "Element of Binary Tree was deleted.\n";
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			break;
		}
		case 3:
		{
			printTree(binaryTree.GetRoot(), binaryTree.GetDepth());
			break;
		}
		case 4:
		{
			cout << "Enter element key: ";

			int key;
			cin >> key;

			try
			{
				treap.InsertNotOptimized(key);
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			break;
		}
		case 5:
		{
			cout << "Enter element key: ";

			int key;
			cin >> key;

			try
			{
				treap.InsertNotOptimized(key);
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

			int key;
			cin >> key;

			try
			{
				treap.RemoveNotOptimized(key);
				cout << "Element of Treep was deleted.\n";
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			break;
		}
		case 7:
		{
			cout << "Enter key of element: ";

			int key;
			cin >> key;

			try
			{
				treap.RemoveOptimized(key);
				cout << "Element of Treep was deleted.\n";
			}
			catch (char const* error)
			{
				cerr << error << '\n';
			}
			break;
		}
		case 8:
		{
			printTree(treap.GetRoot(), treap.GetDepth());
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

template<class T>
void printTree(T* node, int treeDepth)
{
	queue<T*> queue;
	queue.push(node);

	int maxTreeDepth = treeDepth;
	for (int i = 0; i < maxTreeDepth; ++i)
	{
		int queueSize = queue.size();
		for (int j = 0; j < queueSize; ++j)
		{
			T* node = queue.front();
			queue.pop();

			int spaceCount = int(pow(2, treeDepth + 1)) - 1;
			if (node != nullptr)
			{
				if (node->Key < 0)
				{
					spaceCount -= 1;
				}
				if (node->Priority != 0)
				{
					spaceCount -= 1;
				}
			}
			cout << string(spaceCount, '.');
			if (node != nullptr)
			{
				cout << node->Key;
				if (node->Priority != 0)
				{
					if (node->Key < 0)
					{
						spaceCount += 1;
					}
					spaceCount += 1;
					int digit = node->Priority;
					int digitsNumber = 0;
					while (digit > 0)
					{
						digit /= 10;
						digitsNumber += 1;
					}
					spaceCount -= digitsNumber;
					cout << ";" << node->Priority;
				}
			}
			else
			{
				cout << "_";
			}
			if (spaceCount < 0) spaceCount = 0;
			cout << string(spaceCount, '.');
			cout << "|";

			if (node != nullptr)
			{
				queue.push(node->Left);
				queue.push(node->Right);
			}
			else
			{
				queue.push(nullptr);
				queue.push(nullptr);
			}
		}
		treeDepth -= 1;
		cout << '\n';
	}
	cout << '\n';
}