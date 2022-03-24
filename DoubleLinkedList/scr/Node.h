#pragma once

class Node
{
public:
	Node(int data) : _iternalData{ data }, _previousNode{ nullptr }, _nextNode{ nullptr } {};

	/// <summary>
	/// Создаёт узел, правый указатель которого указывает на текущий, а левый указатель текущий на новый.
	/// </summary>
	/// <param name="value">- значение нового узела.</param>
	/// <returns>Возвращает указатель на только что созданный узел.</returns>
	Node* InsertLeft(int value);

	/// <summary>
	/// Создаёт узел, левый указатель которого указывает на текущий, а правый указатель текущий на новый.
	/// </summary>
	/// <param name="value">- значение нового узела.</param>
	/// <returns>Возвращает указатель на только что созданный узел.</returns>
	Node* InsertRight(int value);

	/// <summary>
	/// Удаляет текущий узел.
	/// </summary>
	void Erase();

	/// <summary>
	/// Движение по левому указателю на новый узел, N количество раз.
	/// </summary>
	/// <param name="moveCount">- количество переходов по левому указателю.</param>
	/// <returns>Возвращает указатель на узел, на котором остановились.</returns>
	Node* MoveLeft(int moveCount = 1);

	/// <summary>
	/// Движение по правому указателю на новый узел, N количество раз.
	/// </summary>
	/// <param name="moveCount">- количество переходов по правому указателю.</param>
	/// <returns>Возвращает указатель на узел, на котором остановились.</returns>
	Node* MoveRight(int moveCount = 1);

	/// <summary>
	/// Задаёт новые данные для текущего узла.
	/// </summary>
	/// <param name="value">- значение данных.</param>
	void SetData(int value)
	{
		_iternalData = value;
	}

	/// <summary>
	/// Получить данные, хранящиеся в текущей узле.
	/// </summary>
	/// <returns>Возвращает значение, хранящиеся в текущем узле.</returns>
	int GetData()
	{
		return _iternalData;
	}

private:
	int _iternalData;
	Node* _nextNode;
	Node* _previousNode;
};