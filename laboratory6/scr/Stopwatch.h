#pragma once

#include <chrono>

class Stopwatch
{
public:
	Stopwatch();

	/// <summary>
	/// ��������� ����������.
	/// </summary>
	void Start();

	/// <summary>
	/// ���������� ����������.
	/// </summary>
	void Stop();

	/// <summary>
	/// �������� ��������� �� ���� � ���������� ���������� �������.
	/// </summary>
	void Reset();

	/// <summary>
	/// �������� ���������� ����� � ������������.
	/// </summary>
	/// <returns>����� ����� - �����������.</returns>
	long long GetDuration();

private:
	bool _isStopped;

	std::chrono::high_resolution_clock::time_point _timeBegin;
	std::chrono::high_resolution_clock::time_point _timeEnd;
	std::chrono::high_resolution_clock::time_point _timeDuration;
};

