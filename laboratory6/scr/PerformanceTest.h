#pragma once

#include "RBTree.h"
#include "AVLTree.h"
#include "Vector.h"
#include "Vector.cpp"
#include "Stopwatch.h"

#include <sstream>

using namespace std;

/// <summary>
/// Получить результаты измерений производительности для заданного дерева.
/// </summary>
/// <param name="tree">Тип дерева производительность операций которого надо замерить.</param>
/// <returns>Результаты измерений в виде строки.</returns>
template<class TreeType>
string GetTreePerformanceMeasurement(TreeType* tree);

/// <summary>
/// Измерить среднеезначение времени выполнения для заданной операции дерева.
/// </summary>
/// <param name="operationName">Название операции.</param>
/// <param name="tree">дерево производительность операции которого надо изменить</param>
/// <param name="keys">массив ключей хранящихся в момент вызова функции в дереве.</param>
/// <returns>Время затраченное на выполнение в наносекундах.</returns>
template<class TreeType>
long long GetAverageExecutionTimeOf(string operationName, TreeType* tree, Vector<int>& keys);