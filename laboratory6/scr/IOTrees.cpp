#include "IOTrees.h"

void AVLTreeMenu(AVLTree* avlTree)
{
	enum AVLTreeOperation
	{
		Insert = 1,
		Delete,
		Find,
		Print,
		RunTests
	};

	std::cout << "Enter 1 to insert element to AVLTree.\n";
	std::cout << "Enter 2 to delete element from AVLTree.\n";
	std::cout << "Enter 3 to find AVLTree Node by key value.\n";
	std::cout << "Enter 4 to print all element of AVLTree.\n";
	std::cout << "Enter 5 to run performance tests and write it to file.\n";
	std::cout << "Enter 0 to return to the main menu.\n\n";

	std::cout << "Enter command: ";

	int prompt;
	while (GetInteger(prompt))
	{
		switch (prompt)
		{
			case Insert:
			{
				std::cout << "Enter key of element or several separated by space and ended by any character: ";
				int key;
				GetInteger(key);
				try
				{
					avlTree->Insert(key);
				}
				catch (char const* error)
				{
					std::cerr << error << '\n';
				}
				break;
			}
			case Delete:
			{
				std::cout << "Enter key of element: ";
				int key;
				GetInteger(key);
				try
				{
					avlTree->Delete(key);
					std::cout << "Element of AVL Tree was deleted.\n";
				}
				catch (char const* error)
				{
					std::cerr << error << '\n';
				}
				break;
			}
			case Find:
			{
				std::cout << "Enter key of element: ";
				int key;
				GetInteger(key);
					AVLTreeNode* result = avlTree->Find(key);
				if(result != nullptr)
				{
					std::cout << "Index of node with key " << key << " is equal to: ";
					std::cout << "(" << result->Key << "; " << result->Height << ")\n";
				}
				else
				{
					std::cout << "Element with than key didn't exist.\n";
				}
				break;
			}
			case Print:
			{
				AVLTreeNode* root = avlTree->GetRoot();
				PrintAVLTree(root, (root) ? root->Height : 0);
				break;
			}
			case RunTests:
			{
				std::cout << "Performance tests are executing. Please wait...\n";
				std::ofstream file{ "AVLTreePerformanceTest.txt" };
				file << GetTreePerformanceMeasurement(avlTree);
				file.close();
				std::cout << "Performance tests are finished. Result are saved in file.\n";
				break;
			}
			default:
			{
				PrintMenuOptions();
				return;
			}
		}
		std::cout << "Enter new command: ";
	}
}

void RBTreeMenu(RBTree* rbTree)
{
	enum RBTreeOperation
	{
		Insert = 1,
		Delete,
		Find,
		Print,
		RunTests
	};

	std::cout << "Enter 1 to insert element to Red Black Tree.\n";
	std::cout << "Enter 2 to delete element from Red Black Tree.\n";
	std::cout << "Enter 3 to find Red Black Tree Node by key value.\n";
	std::cout << "Enter 4 to print all element of Red Black Tree.\n";
	std::cout << "Enter 5 to run performance tests and write it to file.\n";
	std::cout << "Enter 0 to return to the main menu.\n\n";

	std::cout << "Enter command: ";

	int prompt;
	while (GetInteger(prompt))
	{
		switch (prompt)
		{
			case Insert:
			{
				std::cout << "Enter key of element: ";
				int key;
				GetInteger(key);
				try
				{
					rbTree->Insert(key);
				}
				catch (char const* error)
				{
					std::cerr << error << '\n';
				}
				break;
			}
			case Delete:
			{
				std::cout << "Enter key of element: ";
				int key;
				GetInteger(key);
				try
				{
					rbTree->Delete(key);
					std::cout << "Element of Red Black Tree was deleted.\n";
				}
				catch (char const* error)
				{
					std::cerr << error << '\n';
				}
				break;
			}
			case Find:
			{
				std::cout << "Enter key of element: ";
				int key;
				GetInteger(key);

				RBTreeNode* result = rbTree->Find(key);
				if (result != nullptr)
				{
					std::cout << "Index of node with key " << key << " is equal to: ";
					std::cout << "(" << result->Key << "; "
						<< (result->IsBlack ? "Black" : "Red") << ")\n";
				}
				else
				{
					std::cout << "Element with than key didn't exist.";
				}
				break;
			}
			case Print:
			{
				RBTreeNode* root = rbTree->GetRoot();
				PrintRBTree(root, 4);
				break;
			}
			case RunTests:
			{
				std::cout << "Performance tests are executing. Please wait...\n";
				std::ofstream file{ "RBTreePerformanceTest.txt" };
				file << GetTreePerformanceMeasurement(rbTree);
				file.close();
				std::cout << "Performance tests are finished. Result are saved in file.\n";
				break;
			}
			default:
			{
				PrintMenuOptions();
				return;
			}
		}
		std::cout << "Enter new command: ";
	}
}

void TreesMenu(AVLTree* avlTree, RBTree* rbTree)
{
	enum TreeType
	{
		AVL = 1,
		RedBlack
	};

	PrintMenuOptions();

	int prompt;
	while (GetInteger(prompt))
	{
		switch (prompt)
		{
			case AVL:
			{
				AVLTreeMenu(avlTree);
				break;
			}
			case RedBlack:
			{
				RBTreeMenu(rbTree);
				break;
			}
			default:
			{
				return;
			}
		}
	}
}

void PrintAVLTree(AVLTreeNode* node, int height, int spaceCount)
{
	if (height == -1)
	{
		return;
	}

	spaceCount += 6;
	if (node != nullptr)
	{
		PrintAVLTree(node->Child[Right], height - 1, spaceCount);
		std::cout << std::string(spaceCount - 6, ' ') << "(" << node->Key << "; " << node->Height << ")\n";
		PrintAVLTree(node->Child[Left], height - 1, spaceCount);
	}
	else
	{
		PrintAVLTree(nullptr, height - 1, spaceCount);
		std::cout << std::string(spaceCount - 6, ' ') << "(_; _)\n";
		PrintAVLTree(nullptr, height - 1, spaceCount);
	}
}

void PrintMenuOptions()
{
	std::cout << "Enter 1 to work with AVLTree.\n";
	std::cout << "Enter 2 to work with RedBlackTree\n";
	std::cout << "Enter 0 to close program.\n\n";

	std::cout << "Enter command: ";
}

void PrintRBTree(RBTreeNode* node, int height, int spaceCount)
{
	if (height == -1)
	{
		return;
	}

	spaceCount += 6;
	if (node != nullptr)
	{
		PrintRBTree(node->Child[Right], height - 1, spaceCount);
		std::cout << std::string(spaceCount - 6, ' ') << "(" << node->Key << "; "
			<< ((node->IsBlack) ? "Black" : "Red") << ")\n";
		PrintRBTree(node->Child[Left], height - 1, spaceCount);
	}
	else
	{
		PrintRBTree(nullptr, height - 1, spaceCount);
		std::cout << std::string(spaceCount - 6, ' ') << "(_; _)\n";
		PrintRBTree(nullptr, height - 1, spaceCount);
	}
}


bool GetInteger(int& value)
{
	char input;
	while (std::cin >> input)
	{
		if (isdigit(input) || input == '-')
		{
			std::cin.unget();
			std::cin >> value;
			return true;
		}
		else
		{
			std::cout << "Incorrect input.\n";
		}
	}
}