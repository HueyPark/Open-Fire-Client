#pragma once

#include "Framework/Singleton.h"

class OPENFIRE_API TimeManager : public Singleton<TimeManager>
{
private:
	float accumulatedSeconds = 0.0f;

public:
	float GetRemainingSeconds();

	void AddSeconds(float deltaSeconds);

	void RewindSeconds();
};
