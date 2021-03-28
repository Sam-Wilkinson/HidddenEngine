#include "HiddenPCH.h"
#include "SimpleSDL2SoundSystem.h"

#include <audio.h>

// ignore warning 4244, conversion from int to uint8_t possible loss of data in audio.c >> line 264 and 322
#pragma warning(push)
#pragma warning (disable:4244)
#include "audio.cpp"
#pragma warning(pop)


Hidden::SimpleSDL2SoundSystem::SimpleSDL2SoundSystem()
	:m_Thread{ std::thread([this]() {this->ProcessSounds(); }) }, m_IsMuted{false}
{

	if(SDL_Init(SDL_INIT_AUDIO) < 0)
	{ 
		// TODO log error that audio was unable to intialise
		return;
	}

	initAudio();
}

Hidden::SimpleSDL2SoundSystem::~SimpleSDL2SoundSystem()
{
	//TODO Make sure queue is empty before notify, if not, clear it and then notify

	m_WorkAvailable.notify_one();

	m_Thread.join();

	endAudio();

	SDL_Quit();
}

void Hidden::SimpleSDL2SoundSystem::PlaySound(const std::string& filePath, const float volume)
{
	const std::pair<std::string, float> sound{filePath, volume};
	std::lock_guard<std::mutex> lock{ m_Mutex };
	m_SoundQueue.push(sound);
	m_WorkAvailable.notify_one();
}

void Hidden::SimpleSDL2SoundSystem::PlayMusic(const std::string& filePath, const float volume)
{
	playMusic(filePath.c_str(), static_cast<int>(SDL_MIX_MAXVOLUME * volume));
}

void Hidden::SimpleSDL2SoundSystem::PauseMusic(const unsigned int)
{
	pauseAudio();
}

void Hidden::SimpleSDL2SoundSystem::UnPauseMusic(const unsigned int )
{
	unpauseAudio();
}

void Hidden::SimpleSDL2SoundSystem::StopMusic(const unsigned int )
{
	endAudio();
}

void Hidden::SimpleSDL2SoundSystem::MuteSounds()
{
	m_IsMuted = true;
}

void Hidden::SimpleSDL2SoundSystem::UnMuteSounds()
{
	m_IsMuted = false;
}

void Hidden::SimpleSDL2SoundSystem::ProcessSounds()
{
	do
	{
		std::unique_lock<std::mutex> lock(m_Mutex);

		if (!m_SoundQueue.empty())
		{
			auto sound = m_SoundQueue.front();
			m_SoundQueue.pop();

			if (!m_IsMuted)
			{
				playSound(sound.first.c_str(), static_cast<int>(SDL_MIX_MAXVOLUME * sound.second));
			}

		}

		if (m_SoundQueue.empty())
		{
			m_WorkAvailable.wait(lock);
		}

	} while (!m_SoundQueue.empty());
}
