#pragma once

#include <chrono>

class Stopwatch
{
public:
	Stopwatch();

	/// <summary>
	/// Запустить секундомер.
	/// </summary>
	void Start();

	/// <summary>
	/// Остановить секундомер.
	/// </summary>
	void Stop();

	/// <summary>
	/// Сбросить измерения до нуля и прекратить дальнейший подсчёт.
	/// </summary>
	void Reset();

	/// <summary>
	/// Получить измеренное время в наносекундах.
	/// </summary>
	/// <returns>целое число - наносекунды.</returns>
	long long GetDuration();

private:
	bool _isStopped;

	std::chrono::high_resolution_clock::time_point _timeBegin;
	std::chrono::high_resolution_clock::time_point _timeEnd;
	std::chrono::high_resolution_clock::time_point _timeDuration;
};

