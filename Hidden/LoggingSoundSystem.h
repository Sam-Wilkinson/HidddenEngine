#pragma once
#include "SoundSystem.h"

namespace Hidden
{
	class LoggingSoundSystem : public SoundSystem
	{
	public:
		LoggingSoundSystem(std::unique_ptr<SoundSystem> ss);
		virtual ~LoggingSoundSystem() = default;


		LoggingSoundSystem(const LoggingSoundSystem& other) = default; // copy constructor
		LoggingSoundSystem(LoggingSoundSystem&& other) noexcept = default; // move constructor
		LoggingSoundSystem& operator=(const LoggingSoundSystem& other) = default; // copy assignment
		LoggingSoundSystem& operator=(LoggingSoundSystem&& other) noexcept = default; // move assignment

		virtual void PlaySound(const std::string& filePath, const float volume) override;
		virtual void PlayMusic(const std::string& filePath, const float volume) override;

		//virtual void PlaySound(const unsigned int soundID, const float volume) = 0;
		//virtual void PlayMusc(const unsigned int musicID, const float volume) = 0;

		virtual void PauseMusic(const unsigned int id) override;
		virtual void UnPauseMusic(const unsigned int id) override;

		virtual void StopMusic(const unsigned int id) override;

		virtual void MuteSounds() override;
		virtual void UnMuteSounds() override;

		virtual void ProcessSounds() override;

	private:
		std::unique_ptr<SoundSystem> m_SoundSystem;

	};

}


