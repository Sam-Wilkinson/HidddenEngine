#pragma once
#include "SoundSystem.h"

#include <audio.h>
// ignore warning 4244, conversion from int to uint8_t possible loss of data in audio.c >> line 264 and 322
#pragma warning(push)
#pragma warning (disable:4244)
#include <audio.c>
#pragma warning(pop)

class SimpleSDL2SoundSystem final : public SoundSystem
{
public:
	SimpleSDL2SoundSystem() = default;
	virtual ~SimpleSDL2SoundSystem() = default;


	SimpleSDL2SoundSystem(const SimpleSDL2SoundSystem & other) = default; // copy constructor
	SimpleSDL2SoundSystem(SimpleSDL2SoundSystem && other) noexcept = default; // move constructor
	SimpleSDL2SoundSystem& operator=(const SimpleSDL2SoundSystem & other) = default; // copy assignment
	SimpleSDL2SoundSystem& operator=(SimpleSDL2SoundSystem && other) noexcept = default; // move assignment

	virtual void play(const unsigned int id, const float volume) = 0;
	virtual void pause(const unsigned int id) = 0;
	virtual void stop(const unsigned int id) = 0;

private:

};

