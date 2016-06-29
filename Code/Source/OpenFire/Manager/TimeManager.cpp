#include "OpenFire.h"
#include "TimeManager.h"

const float updateSeconds = 0.3f;

float TimeManager::GetRemainingSeconds()
{
	return updateSeconds - this->accumulatedSeconds;
}

void TimeManager::AddSeconds(float deltaSeconds)
{
	this->accumulatedSeconds += deltaSeconds;
}

void TimeManager::RewindSeconds()
{
	this->accumulatedSeconds -= updateSeconds;
}
