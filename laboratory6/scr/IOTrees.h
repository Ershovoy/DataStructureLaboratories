#pragma once

#include "RBTree.h"
#include "AVLTree.h"
#include "PerformanceTest.h"
#include "PerformanceTest.cpp"

#include <iostream>
#include <fstream>

/// <summary>
/// Вывести меню для выбора вида дерева, над которым будут выполняться пользовательские операции. 
/// </summary>
/// <param name="avlTree">- АВЛ дерево над которым будут выполняться операции.</param>
/// <param name="rbTree">- красно-чёрное дерево над которым будут выполняться операции.</param>
void TreesMenu(AVLTree* avlTree, RBTree* rbTree);

/// <summary>
/// Меню для выполнения операций над АВЛ деревом.
/// </summary>
/// <param name="avlTree">- АВЛ дерево над которым будут выполняться операции.</param>
void AVLTreeMenu(AVLTree* avlTree);

/// <summary>
/// Меню для выполнения операций над красно-чёрным деревом.
/// </summary>
/// <param name="rbTree">- красно-чёрное дерево над которым будут выполняться операции.</param>
void RBTreeMenu(RBTree* rbTree);

/// <summary>
/// Вывод команд меню для выбора вида дерева.
/// </summary>
void PrintMenuOptions();

/// <summary>
/// Рекурсивно выводит АВЛ дерево в консоль.
/// </summary>
/// <param name="node">- корень поддерева с которого начинается обход справа налево.</param>
/// <param name="height"> высота введённого корня.</param>
/// <param name="spaceCount">- используется в рекурсии, чем глубже находится узел тем большее число пробелов надо вывести.</param>
void PrintAVLTree(AVLTreeNode* node, int height, int spaceCount = 0);

/// <summary>
/// Рекурсивно выводит красно-чёрное дерево в консоль.
/// </summary>
/// <param name="node">- корень поддерева с которого начинается обход справа налево.</param>
/// <param name="height">- высота введённого корня.</param>
/// <param name="spaceCount">- используется в рекурсии, чем глубже находится узел тем большее число пробелов надо вывести.</param>
void PrintRBTree(RBTreeNode* node, int height, int spaceCount = 0);

/// <summary>
/// Ждёт ввода числа от пользователя, игнорируя любой другой введённый символ. 
/// </summary>
/// <param name="value">- переменная куда будет записан ввод.</param>
/// <returns>
/// Вернёт true если пользователь ввёл число.
/// </returns>
bool GetInteger(int& value);