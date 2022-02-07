#pragma once

#include "RBTree.h"
#include "AVLTree.h"
#include "PerformanceTest.h"
#include "PerformanceTest.cpp"

#include <iostream>
#include <fstream>

/// <summary>
/// ������� ���� ��� ������ ���� ������, ��� ������� ����� ����������� ���������������� ��������. 
/// </summary>
/// <param name="avlTree">- ��� ������ ��� ������� ����� ����������� ��������.</param>
/// <param name="rbTree">- ������-������ ������ ��� ������� ����� ����������� ��������.</param>
void TreesMenu(AVLTree* avlTree, RBTree* rbTree);

/// <summary>
/// ���� ��� ���������� �������� ��� ��� �������.
/// </summary>
/// <param name="avlTree">- ��� ������ ��� ������� ����� ����������� ��������.</param>
void AVLTreeMenu(AVLTree* avlTree);

/// <summary>
/// ���� ��� ���������� �������� ��� ������-������ �������.
/// </summary>
/// <param name="rbTree">- ������-������ ������ ��� ������� ����� ����������� ��������.</param>
void RBTreeMenu(RBTree* rbTree);

/// <summary>
/// ����� ������ ���� ��� ������ ���� ������.
/// </summary>
void PrintMenuOptions();

/// <summary>
/// ���������� ������� ��� ������ � �������.
/// </summary>
/// <param name="node">- ������ ��������� � �������� ���������� ����� ������ ������.</param>
/// <param name="height"> ������ ��������� �����.</param>
/// <param name="spaceCount">- ������������ � ��������, ��� ������ ��������� ���� ��� ������� ����� �������� ���� �������.</param>
void PrintAVLTree(AVLTreeNode* node, int height, int spaceCount = 0);

/// <summary>
/// ���������� ������� ������-������ ������ � �������.
/// </summary>
/// <param name="node">- ������ ��������� � �������� ���������� ����� ������ ������.</param>
/// <param name="height">- ������ ��������� �����.</param>
/// <param name="spaceCount">- ������������ � ��������, ��� ������ ��������� ���� ��� ������� ����� �������� ���� �������.</param>
void PrintRBTree(RBTreeNode* node, int height, int spaceCount = 0);

/// <summary>
/// ��� ����� ����� �� ������������, ��������� ����� ������ �������� ������. 
/// </summary>
/// <param name="value">- ���������� ���� ����� ������� ����.</param>
/// <returns>
/// ����� true ���� ������������ ��� �����.
/// </returns>
bool GetInteger(int& value);