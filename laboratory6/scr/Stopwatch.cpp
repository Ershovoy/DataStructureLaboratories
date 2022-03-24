#include "Stopwatch.h"

Stopwatch::Stopwatch() : _isStopped{ true }, _timeBegin{}, _timeEnd{}, _timeDuration{}
{
}

void Stopwatch::Start()
{
	_timeBegin = std::chrono::high_resolution_clock::now();

	_isStopped = false;
}

void Stopwatch::Stop()
{
	_timeEnd = std::chrono::high_resolution_clock::now();
	_timeDuration += _timeEnd - _timeBegin;

	_isStopped = true;
}

void Stopwatch::Reset()
{
	_isStopped = true;
	_timeDuration = {};
}

long long Stopwatch::GetDuration()
{
	if (!_isStopped)
	{
		Stop();
		Start();
	}

	return std::chrono::time_point_cast<std::chrono::nanoseconds>(_timeDuration).time_since_epoch().count();
}
