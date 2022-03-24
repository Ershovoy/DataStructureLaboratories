#pragma once

#include "TreeNodes.h"

class RBTree
{
public:
	RBTree();
	~RBTree();

	/// <summary>
	/// Создаёт узел в красно-чёрном дереве с заданным ключём.
	/// </summary>
	/// <param name="key">
	/// ключ, созданного узла.
	/// </param>
	void Insert(int key);

	/// <summary>
	/// Удаляет любой красный узел или черный узел с одним ребёнком из красно-чёрного дерева.
	/// </summary>
	/// <param name="key">
	/// ключ удаляемого узла.
	/// </param>
	void Delete(int key);

	/// <summary>
	/// Возвращает элемент красно-чёрного дерева с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	/// </summary>
	/// <param name="key">ключ по которому осуществяется поиск элемента.</param>
	/// <returns>
	/// Элемент или nullptr если элемент не найден.
	/// </returns>
	RBTreeNode* Find(int key);

	/// <summary>
	/// Возвращает корень красно-чёрного дерева или nullptr.
	/// </summary>
	/// <returns>
	/// Узел, являющийся корнем или nil (фиктивный узел).
	/// </returns>
	RBTreeNode* GetRoot()
	{
		return _root;
	}

	/// <summary>
	/// Возвращает количество выполненых поворотов над узлами за время существаоания дерева.
	/// </summary>
	int GetNodeRotateCount()
	{
		return _nodeRotateCount;
	}

	/// <summary>
	/// Сбрасывает количество выполненых поворот над узлам до нуля.
	/// </summary>
	void ResetNodeRotateCount()
	{
		_nodeRotateCount = 0;
	}

private:
	/// <summary>
	/// Проверяет красный ли заданный узел.
	/// </summary>
	/// <returns>true если узел красный и не равен nullptr, иначе false</returns>
	bool IsRed(RBTreeNode* node);

	/// <summary>
	/// Рекурсивно создаёт узел с заданным ключём в заданном поддереве, возвращаясь назад вызывает
	/// InsertFixLeft() для выхода из левого узла и InsertFixRight() для правого, для корретировки цвета.
	/// </summary>
	/// <param name="node">корень поддерева от куда будет осуществляться вставка.</param>
	/// <param name="key">ключ, созданного узла.</param>
	/// <returns>
	/// корень, сбалансированного поддерева.
	/// </returns>
	RBTreeNode* Insert(RBTreeNode* node, int key);

	/// <summary>
	/// Рекурсивно удаляет любой красный узел или черный узел с одним ребёнком в заданном поддереве
	/// </summary>
	/// <param name="node">корень поддерева с которого будет осуществляется поиск узла с заданным ключём.</param>
	/// <param name="key">ключ, удаляемого узла.</param>
	/// <param name="isBalanced">если дерево будет сбалансированно установит этот флаг.</param>
	/// <returns>
	/// корень, сбалансированного поддерева или нулевой указатель.
	/// </returns>
	RBTreeNode* Delete(RBTreeNode* node, int key, bool& isBalanced);

	/// <summary>
	/// Вызывается во время выхода из рекурсии для каждого узла в обратном порядке.
	/// Исправляет случаи когда удаляемый узел черный, вызывается только когда баланс уже нарушен.
	/// </summary>
	/// <param name="node">текущий узел рекурсии в удалении</param>
	/// <param name="isBalanced">установит флаг если после её вызова баланс удалось исправить</param>
	/// <returns>Новый корень слабансированного или нет поддерева.</returns>
	RBTreeNode* DeleteFix(RBTreeNode* node, bool direction, bool& isBalanced);

	/// <summary>
	/// Рекурсивно ищет узел с заданным ключём в заданном корне поддерева.
	/// </summary>
	/// <param name="node">корень поддерева.</param>
	/// <param name="key">ключ по которому осуществяется поиск элемента.</param>
	/// <returns>
	/// Элемент или nullptr если не найден элемент.
	/// </returns>
	RBTreeNode* Find(RBTreeNode* node, int key);

	/// <summary>
	/// Вызывается во время выхода из рекурсии для каждого узла в обратном порядке
	/// Исправляет два красных узла идущих подряд.
	/// </summary>
	/// <param name="node">текущий узел рекурсии в добавлении</param>
	/// <returns>Новый корень сбалансированного поддерева левого ребёнка.</returns>
	RBTreeNode* InsertFix(RBTreeNode* node, bool direction);

	/// <summary>
	/// Инвентирует цвет кореня заданного узла и его детей.
	/// </summary>
	void FlipColor(RBTreeNode* node);

	/// <summary>
	/// левый/правой поворот вокруг заданного узла в заданном направлении. Его левое/правое поддерево поднимается вверх, заменяя свой левый/правый дочерний узел
	/// на заданный, а правый/левый дочерний узел заданного узла на раннее заменённый.
	/// </summary>
	/// <param name="node">узел, вокруг которого нужно выполнил поворот.</param>
	/// <param name="direction">направление поворота: 0 - влево, 1 - вправо.</param>
	/// <returns>
	/// Новый корень полученного поддерева.
	/// </returns>
	RBTreeNode* Rotate(RBTreeNode* node, bool direction);

	/// <summary>
	/// Корень красно-чёрного дерева.
	/// </summary>
	RBTreeNode* _root;

	/// <summary>
	/// Количество выполненых поворотов за время существования дерева.
	/// </summary>
	int _nodeRotateCount;
};