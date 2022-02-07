#pragma once

#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>

//TODO: rsdn
// Декартово дерево, где ключ левого узела меньше ключа родительского узла, а ключ правого больше.
struct TreapNode
{
	// Ключ текущего узла.
	int Key;
	// Приоритет текущего узла.
	short Priority;
	// Указатель на левый узел.
	TreapNode* Left;
	// Указатель на правый узел.
	TreapNode* Right;
};

class Treap
{
public:
	Treap();
	~Treap();

	/**
	 * @brief Добавляет элемент в декартово дерево не оптимизированным алгоритмом, использующим 2 merge() и 1 split().
	 * @param Key - ключ элемента.
	*/
	void InsertNotOptimized(int key);

	/**
	 * @brief Добавляет элемент в декартово дерево оптимизированным алгоритмом, использующим 1 split().
	 * @param Key - ключ элемента.
	*/
	void InsertOptimized(int key);

	/**
	 * @brief Удаляет элемент из декартово дерева по ключу (используется 1 merge(), 2 split()).
	 * @param Key - ключ удаляемого элемента.
	*/
	void RemoveNotOptimized(int key);

	/**
	 * @brief Удаляет элемент из декартово дерева по ключу (используется 1 merge()).
	 * @param Key - ключ удаляемого элемента.
	*/
	void RemoveOptimized(int key);

	/**
	 * @brief Возвращает элемент декартова дерева с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	 * @param Key - ключ по которому осуществяется поиск элемента.
	 * @param subgraph - подграф в котором будет осуществляться поиск.
	 * @return Элемент или nullptr если не найден элемент.
	*/
	TreapNode* Find(int key, TreapNode* node);

	//TODO: rsdn
	
	/**
	 * @brief Получить глубину дерева.
	 * @return Значение глубины.
	*/
	int GetDepth();

	/**
	 * @brief Получить корень дерева.
	 * @return Указатель на узел корня.
	*/
	TreapNode* GetRoot()
	{
		return _root;
	}

private:
	//TODO: rsdn 
	
	/**
	 * @brief Возвращает указатель на элемент декартова дерева с заданным ключём, 
	 * если элемент с заданным ключём не найден, то nullptr. Используется чтобы изменить указатель родительского узела.
	 * @param key - ключ по которому осуществяется поиск элемента.
	 * @param node - подграф в котором будет осуществляться поиск.
	 * @return Указатель на элемент или nullptr если не найден элемент.
	*/
	TreapNode** FindPointerToNode(int key, TreapNode** node);

	/**
	 * @brief Возвращает указатель на первый элемент декартова дерева с приоритет которого меньше заданного, 
	 * @param node - узел с которого будет осуществляться поиск.
	 * @param priority - заданный приоритет.
	 * @return Указатель на узел приоритет которого меньше заданного.
	*/
	TreapNode** FindPointerToLessPriorityNode(TreapNode** node, int priority);

	/**
	 * @brief Сливает два декартовых дерева в одно. 
	 *        Условие: все ключи в левом дереве должны быть меньше, чем ключи в правом.
	 * @param left - Левое дерево (его узлы < узлов правого дерева).
	 * @param right - Правое дерево (его узлы > узлов левого дерева).
	 * @return Результат дерево содержащие все узлы из левого и правого дерева.
	*/
	TreapNode* Merge(TreapNode* left, TreapNode* right);

	/**
	 * @brief Разрезает декартов дерево по ключу, чтобы получить дерево где все ключи меньше, заданного
	 * и дерево где ключи больше заданного.
	 * @param node - Корень дерева
	 * @param key - Ключ по которому будет разрезано дерево
	 * @param left - Первый результат это дерево, где все ключи меньше.
	 * @param right - Второй результат это дерево, где все ключи больше.
	*/
	void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

	TreapNode* _root;
};

