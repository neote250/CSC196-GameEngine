
#include "EngineTime.h"

void Time::Tick()
{
	clock::duration duration = clock::now() - _startTime;
	_time = duration.count() / (float)clock::duration::period::den;

	duration = clock::now() - _frameTime;
	_deltaTime = duration.count() / (float)clock::duration::period::den;

	_frameTime = clock::now();
}
