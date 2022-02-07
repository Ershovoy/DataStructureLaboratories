#pragma once

// Бинарное дерево, где ключ левого узла меньше ключа родительского узла, а ключ правого больше.
struct BinaryTreeNode
{
	// Ключ текущего узла.
	int Key;
	// Указатель на левый узел.
	BinaryTreeNode* Left;
	// Указатель на правый узел.
	BinaryTreeNode* Right;
	// Указатель на родительский узел.
	BinaryTreeNode* Parent;
	// Приоритет текущего узла.
	int Priority;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	/**
	 * @brief Добавляет элемент в двоичное дерево.
	 * @param Key - ключ элемента.
	 * @param subgraph - подграф в который будет добавлен новый элемент.
	*/
	void Insert(int key, BinaryTreeNode* subgraph);

	/**
	 * @brief Удаляет элемент из двоичного дерева по ключу.
	 * @param Key - ключ удаляемого элемента.
	*/
	void Remove(int key);

	/**
	 * @brief Возвращает элемент бинарного дерева с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	 * @param Key - ключ по которому осуществяется поиск элемента.
	 * @param subgraph - подграф в котором будет осуществляться поиск.
	 * @return Элемент или nullptr если не найден элемент.
	*/
	BinaryTreeNode* Find(int key, BinaryTreeNode* subgraph);

	/**
	 * @brief Поиск минимума данного подграфа.
	 * @param subgraph - подграф в котором будет осуществляться поиск минимума.
	 * @return Минимальный элемент подграфа.
	*/
	BinaryTreeNode* FindMinimum(BinaryTreeNode* subgraph);

	/**
	 * @brief Поиск максимума данного подграфа.
	 * @param subgraph - подграф в котором будет осуществляться поиск максимума.
	 * @return Максимальный элемент подграфа.
	*/
	BinaryTreeNode* FindMaximum(BinaryTreeNode* subgraph);

	/**
	 * @brief Возвращает указатель на корень графа.
	 * @return Указатель на вершину.
	*/
	BinaryTreeNode* GetRoot()
	{
		return _root;
	}

	/**
	 * @brief Возвращает глубину графа.
	 * @return Глубина графа.
	*/
	int GetDepth();

private:
	/**
	 * @brief Рекурсивная функция, которая обновляет глубину дерева.
	 *		  Обновляет глубину только в большую сторону, поэтому перед использованием нужно обнулить текущее значение глубины.
	 * @param node - Корень дерева.
	 * @param nodeDepth - Текущая глубина узла, для корня она равна 1.
	*/
	void UpdateDepth(BinaryTreeNode* node, int nodeDepth);

	BinaryTreeNode* _root;
	int _depth;
};

