#pragma once

#include "RBTree.h"
#include "AVLTree.h"
#include "Vector.h"
#include "Vector.cpp"
#include "Stopwatch.h"

#include <sstream>

using namespace std;

/// <summary>
/// �������� ���������� ��������� ������������������ ��� ��������� ������.
/// </summary>
/// <param name="tree">��� ������ ������������������ �������� �������� ���� ��������.</param>
/// <returns>���������� ��������� � ���� ������.</returns>
template<class TreeType>
string GetTreePerformanceMeasurement(TreeType* tree);

/// <summary>
/// �������� ��������������� ������� ���������� ��� �������� �������� ������.
/// </summary>
/// <param name="operationName">�������� ��������.</param>
/// <param name="tree">������ ������������������ �������� �������� ���� ��������</param>
/// <param name="keys">������ ������ ���������� � ������ ������ ������� � ������.</param>
/// <returns>����� ����������� �� ���������� � ������������.</returns>
template<class TreeType>
long long GetAverageExecutionTimeOf(string operationName, TreeType* tree, Vector<int>& keys);