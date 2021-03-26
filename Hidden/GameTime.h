#pragma once

#include "Singleton.h"
#include "GameConfig.h"

class GameTime final : public Hidden::Singleton<GameTime>
{
	friend class Singleton<GameTime>;


public:

	GameTime(const GameTime& other) = delete;
	GameTime(GameTime&& other) = delete;
	GameTime& operator=(const GameTime& other) = delete;
	GameTime& operator=(GameTime&& other) = delete;

	const float GetTime()
	{
		return deltaTime;
	}

	void SetTime(float _deltaTime)
	{
		deltaTime = _deltaTime;
	}

private:
	GameTime()
		: deltaTime{}
	{}
	float deltaTime;
};

