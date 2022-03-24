#pragma once

#include "TreeNodes.h"

class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	/// <summary>
	/// Создаёт узел в АВЛ дереве с заданным ключём.
	/// </summary>
	/// <param name="key">
	/// ключ, созданного узла.
	/// </param>
	void Insert(int key);

	/// <summary>
	/// Удаляет элемент из АВЛ дерева с заданным ключём.
	/// </summary>
	/// <param name="key">
	/// значения ключа
	/// </param>
	void Delete(int key);

	/// <summary>
	/// Возвращает элемент АВЛ дерева с заданным ключём, если элемент с заданным ключём не найден, то nullptr.
	/// </summary>
	/// <param name="key">ключ по которому осуществяется поиск элемента.</param>
	/// <returns>
	/// Элемент или nullptr если элемент не найден.
	/// </returns>
	AVLTreeNode* Find(int key);

	/// <summary>
	/// Возвращает корень АВЛ дерева или nullptr.
	/// </summary>
	/// <returns>
	/// Узел, являющийся корнем или nullptr.
	/// </returns>
	AVLTreeNode* GetRoot();

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
	/// Рекурсивно создаёт узел с заданным ключём в заданном поддереве, возвращаясь назад вызывает
	/// BalanceNode() для каждого узла, что не допускает возникновения дизбаланса в заданном поддереве.
	/// </summary>
	/// <param name="node">корень поддерева от куда будет осуществляться вставка.</param>
	/// <param name="key">ключ, созданного узла.</param>
	/// <returns>
	/// корень, сбалансированного поддерева.
	/// </returns>
	AVLTreeNode* Insert(AVLTreeNode* node, int key);

	/// <summary>
	/// Рекурсивно удаляет узел с заданным ключём в заданном поддереве, возвращаясь назад вызывает
	/// BalanceNode() для каждого узла, что не допускает возникновения дизбаланса в заданном поддереве.
	/// </summary>
	/// <param name="node">корень поддерева с которого будет осуществляется поиск кзла с заданным ключём.</param>
	/// <param name="key">ключ, удаляемого узла</param>
	/// <returns>
	/// корень, сбалансированного поддерева или нулевой указатель.
	/// </returns>
	AVLTreeNode* Delete(AVLTreeNode* node, int key);

	/// <summary>
	/// Рекурсивно ищет узел с заданным ключём в заданном корне поддерева.
	/// </summary>
	/// <param name="node">корень поддерева.</param>
	/// <param name="key">ключ по которому осуществяется поиск элемента.</param>
	/// <returns>
	/// Элемент или nullptr если не найден элемент.
	/// </returns>
	AVLTreeNode* Find(AVLTreeNode* node, int key);

	/// <summary>
	/// Рекурсивный поиск минимального узла в заданном поддереве.
	/// </summary>
	/// <param name="node">узел, в котором осуществляется поиск.</param>
	/// <returns>
	/// Минимальный узел в заданном поддереве.
	/// </returns>
	AVLTreeNode* FindMin(AVLTreeNode* node);

	/// <summary>
	/// Рекурсивно удаляет минимальный узел из заданного поддерева, возвращаясь назад вызывает
	/// BalanceNode() для каждого узла, что не допускает возникновения дизбаланса в заданном поддереве.
	/// </summary>
	/// <param name="node">узел, с которого осуществляется поиск и дальнейшее удаление.</param>
	/// <returns>
	/// Новый корень полученного поддерева, может быть nullptr.
	/// </returns>
	AVLTreeNode* DeleteMin(AVLTreeNode* node);

	/// <summary>
	/// левый/правой поворот вокруг заданного узла в заданном направлении. 
	/// Его левое/правое поддерево поднимается вверх, заменяя свой левый/правый дочерний узел
	/// на заданный, а правый/левый дочерний узел заданного узла на раннее заменённый.
	/// </summary>
	/// <param name="node">узел, вокруг которого нужно выполнил поворот.</param>
	/// <param name="direction">направление поворота: 0 - влево, 1 - вправо.</param>
	/// <returns>
	/// Новый корень полученного поддерева.
	/// </returns>
	AVLTreeNode* Rotate(AVLTreeNode* node, bool direction);

	/// <summary>
	/// Исправляет дизбаланс заданного узла, выполняя двойной или одинарный поворот.
	/// </summary>
	/// <param name="node">узел, дизбаланс которого надо испарвить.</param>
	/// <returns>
	/// Новый корень исправленного узла.
	/// </returns>
	AVLTreeNode* BalanceNode(AVLTreeNode* node);

	/// <summary>
	/// Вычисляет высоту заданного узла.
	/// </summary>
	/// <param name="node">узел, высоту которого надо найти.</param>
	/// <returns>
	/// Высота узла или -1 если node == nullptr.
	/// </returns>
	short int GetHeight(AVLTreeNode* node);

	/// <summary>
	/// Вычисляет разницу высот правого и левого поддерева заданного узла.
	/// </summary>
	/// <param name="node">узел, разницу высоты поддеревьев которого надо вычислить.</param>
	/// <returns>
	/// Вернёт положительное число, если высота правого поддерева больше левого.	
	/// Верёт 0, если высоты поддеревьев равны. Иначе отрицательное.
	/// </returns>
	short int GetBalanceFactor(AVLTreeNode* node);

	/// <summary>
	/// Корректирует высоту заданного узла (при условии, что высоты его поддеревьев верны).
	/// </summary>
	/// <param name="node">
	/// узел, высоту которого надо скоректировать.
	/// </param>
	void UpdateHeight(AVLTreeNode* node);

	/// <summary>
	/// Корень АВЛ дерева.
	/// </summary>
	AVLTreeNode* _root;

	/// <summary>
	/// Количество выполненых поворотов за время существования дерева.
	/// </summary>
	int _nodeRotateCount;
};

