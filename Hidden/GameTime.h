#pragma once

#include "Singleton.h"
#include "GameConfig.h"

class GameTime final : public Hidden::Singleton<GameTime>
{
	friend class Singleton<GameTime>;
	friend class Application;

public:

	GameTime(const GameTime& other) = delete;
	GameTime(GameTime&& other) = delete;
	GameTime& operator=(const GameTime& other) = delete;
	GameTime& operator=(GameTime&& other) = delete;

	static const float GetTime()
	{
		return deltaTime;
	}



private:
	GameTime() {};
	static float deltaTime;

	void SetTime(float _deltaTime)
	{
		deltaTime = _deltaTime;
	}
};

