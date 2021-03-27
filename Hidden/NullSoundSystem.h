#pragma once
#include "SoundSystem.h"

namespace Hidden
{
	class NullSoundSystem final : public SoundSystem
	{
	public:
		NullSoundSystem() = default;
		virtual ~NullSoundSystem() = default;


		NullSoundSystem(const NullSoundSystem& other) = default; // copy constructor
		NullSoundSystem(NullSoundSystem&& other) noexcept = default; // move constructor
		NullSoundSystem& operator=(const NullSoundSystem& other) = default; // copy assignment
		NullSoundSystem& operator=(NullSoundSystem&& other) noexcept = default; // move assignment

		virtual void PlaySound(const std::string&, const float) override {};
		virtual void PlayMusic(const std::string&, const float) override {};

		//virtual void PlaySound(const unsigned int soundID, const float volume) = 0;
		//virtual void PlayMusc(const unsigned int musicID, const float volume) = 0;

		virtual void PauseMusic(const unsigned int) override {};
		virtual void UnPauseMusic(const unsigned int) override {};

		virtual void StopMusic(const unsigned int) override {};

		virtual void MuteSounds() override {};
		virtual void UnMuteSounds() override {};

		virtual void ProcessSounds() override {};

	private:

	};

}

