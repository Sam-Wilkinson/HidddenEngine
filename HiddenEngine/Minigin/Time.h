#pragma once

#include "Singleton.h"
#include "GameConfig.h"

class Time final : public Hidden::Singleton<Time>
{
	friend class Singleton<Time>;


public:

	Time(const Time& other) = delete;
	Time(Time&& other) = delete;
	Time& operator=(const Time& other) = delete;
	Time& operator=(Time&& other) = delete;

	const float GetTime()
	{
		return deltaTime;
	}

	void SetTime(float _deltaTime)
	{
		deltaTime = _deltaTime;
	}

private:
	Time()
		: deltaTime{}
	{}
	float deltaTime;
};

