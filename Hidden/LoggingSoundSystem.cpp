#include "HiddenPCH.h"
#include "LoggingSoundSystem.h"

void Hidden::LoggingSoundSystem::PlaySound(const std::string& filePath, const float volume)
{
	// TODO Log Play sound
	m_SoundSystem->PlaySound(filePath, volume);
}

void Hidden::LoggingSoundSystem::PlayMusic(const std::string& filePath, const float volume)
{
	// TODO Log Play Music
	m_SoundSystem->PlayMusic(filePath, volume);
}

void Hidden::LoggingSoundSystem::PauseMusic(const unsigned int id)
{
	// TODO Log Pause Music
	m_SoundSystem->PauseMusic(id);
}

void Hidden::LoggingSoundSystem::UnPauseMusic(const unsigned int id)
{
	// TODO Log Unpause Music
	m_SoundSystem->UnPauseMusic(id);
}

void Hidden::LoggingSoundSystem::StopMusic(const unsigned int id)
{
	// TODO Log Stop Music
	m_SoundSystem->StopMusic(id);
}

void Hidden::LoggingSoundSystem::MuteSounds()
{
	// TODO Log Mute Sounds;
	m_SoundSystem->MuteSounds();
}

void Hidden::LoggingSoundSystem::UnMuteSounds()
{
	// TODO Log UnMute Sounds
	m_SoundSystem->UnMuteSounds();
}

void Hidden::LoggingSoundSystem::ProcessSounds()
{
	// TODO Log processSounds

	m_SoundSystem->ProcessSounds();

}
