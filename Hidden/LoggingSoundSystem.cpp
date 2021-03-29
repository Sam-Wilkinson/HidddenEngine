#include "HiddenPCH.h"
#include "LoggingSoundSystem.h"
#include "ServiceLocator.h"


Hidden::LoggingSoundSystem::LoggingSoundSystem(std::unique_ptr<SoundSystem> ss)
	:m_SoundSystem{std::move(ss)}
{
}

void Hidden::LoggingSoundSystem::PlaySound(const std::string& filePath, const float volume)
{
	//Log Play sound
	std::string msg{"Play sound:" + filePath + " at volume: " + std::to_string(volume) };

	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->PlaySound(filePath, volume);
}

void Hidden::LoggingSoundSystem::PlayMusic(const std::string& filePath, const float volume)
{
	// Log Play Music
	std::string msg{ "Play Music:" + filePath + " at volume: " + std::to_string(volume) };

	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->PlayMusic(filePath, volume);
}

void Hidden::LoggingSoundSystem::PauseMusic(const unsigned int id)
{
	// Log Pause Music

	std::string msg{ "Pausing Music" };

	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->PauseMusic(id);
}

void Hidden::LoggingSoundSystem::UnPauseMusic(const unsigned int id)
{
	// Log Unpause Music
	std::string msg{ "UnPausing Music" };

	ServiceLocator::GetLoggerSystem().LogInfo(msg);
	m_SoundSystem->UnPauseMusic(id);
}

void Hidden::LoggingSoundSystem::StopMusic(const unsigned int id)
{
	//  Log Stop Music

	std::string msg{ "Stopping Music" };
	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->StopMusic(id);
}

void Hidden::LoggingSoundSystem::MuteSounds()
{
	//  Log Mute Sounds;
	std::string msg{ "Muting Sounds" };
	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->MuteSounds();
}

void Hidden::LoggingSoundSystem::UnMuteSounds()
{
	// TODO Log UnMute Sounds

	std::string msg{ "Muting Sounds" };
	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->UnMuteSounds();
}

void Hidden::LoggingSoundSystem::ProcessSounds()
{
	//  Log processSounds
	std::string msg{ "Processing Sounds" };
	ServiceLocator::GetLoggerSystem().LogInfo(msg);

	m_SoundSystem->ProcessSounds();

}
