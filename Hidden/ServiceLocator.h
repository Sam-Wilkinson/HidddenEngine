#pragma once
#include "SoundSystem.h"

class ServiceLocator final
{
public:
	static SoundSystem& GetSoundSystem() { return *m_SoundSystemInstance; };
	static void RegisterSoundSystem(std::unique_ptr<SoundSystem> soundSystem) { m_SoundSystemInstance = std::move(soundSystem); };

private:
	static std::unique_ptr<SoundSystem> m_SoundSystemInstance;

};

std::unique_ptr<SoundSystem> ServiceLocator::m_SoundSystemInstance{};