#pragma once

namespace Hidden
{
	class SoundSystem
	{
	public:
		SoundSystem() = default;
		virtual ~SoundSystem() = default;


		SoundSystem(const SoundSystem& other) = default; // copy constructor
		SoundSystem(SoundSystem&& other) noexcept = default; // move constructor
		SoundSystem& operator=(const SoundSystem& other) = default; // copy assignment
		SoundSystem& operator=(SoundSystem&& other) noexcept = default; // move assignment

		virtual void PlaySound(const std::string& filePath, const float volume) = 0;
		virtual void PlayMusic(const std::string& filePath, const float volume) = 0;

		//virtual void PlaySound(const unsigned int soundID, const float volume) = 0;
		//virtual void PlayMusc(const unsigned int musicID, const float volume) = 0;

		virtual void PauseMusic(const unsigned int id) = 0;
		virtual void UnPauseMusic(const unsigned int id) = 0;

		virtual void StopMusic(const unsigned int id) = 0;

		virtual void MuteSounds() = 0;
		virtual void UnMuteSounds() = 0;

		virtual void ProcessSounds() = 0;



	protected:

	private:


	};
}



