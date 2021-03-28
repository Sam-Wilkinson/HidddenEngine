#pragma once
#include "SoundSystem.h"
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace Hidden
{
	class SimpleSDL2SoundSystem final : public SoundSystem
	{
	public:
		SimpleSDL2SoundSystem();
		virtual ~SimpleSDL2SoundSystem();


		SimpleSDL2SoundSystem(const SimpleSDL2SoundSystem& other) = default; // copy constructor
		SimpleSDL2SoundSystem(SimpleSDL2SoundSystem&& other) noexcept = default; // move constructor
		SimpleSDL2SoundSystem& operator=(const SimpleSDL2SoundSystem& other) = default; // copy assignment
		SimpleSDL2SoundSystem& operator=(SimpleSDL2SoundSystem&& other) noexcept = default; // move assignment

		virtual void PlaySound(const std::string& filePath, const float volume) override;
		virtual void PlayMusic(const std::string& filePath, const float volume) override;

		//virtual void PlaySound(const unsigned int soundID, const float volume) override;
		//virtual void PlayMusc(const unsigned int musicID, const float volume) override ;

		virtual void PauseMusic(const unsigned int id) override;
		virtual void UnPauseMusic(const unsigned int id) override;

		virtual void StopMusic(const unsigned int id) override;

		virtual void MuteSounds() override;
		virtual void UnMuteSounds() override;

		virtual void ProcessSounds() override;

	private:

		std::queue < std::pair<std::string, float>> m_SoundQueue;

		std::thread m_Thread;
		std::mutex m_Mutex;
		std::condition_variable m_WorkAvailable;

		bool m_IsMuted;

	};
}



