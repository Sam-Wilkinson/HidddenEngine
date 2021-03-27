#pragma once
#include "SoundSystem.h"
#include "NullSoundSystem.h"
#include "Logger.h"

namespace Hidden
{
	class ServiceLocator final
	{
	public:
		static SoundSystem& GetSoundSystem() { return *m_SoundSystemInstance; };
		static void RegisterSoundSystem(std::shared_ptr<SoundSystem> soundSystem)
		{
			// If passed soundSystem exists, make it the service locators sound system, else make it the default(Null) soundSystem
			m_SoundSystemInstance = soundSystem ? soundSystem : m_DefaultSoundSystem;
		};

	private:
		static std::shared_ptr<SoundSystem> m_SoundSystemInstance;
		static std::shared_ptr<NullSoundSystem> m_DefaultSoundSystem;
		static std::unique_ptr<Logger> m_LoggingInstance;
	};

	std::shared_ptr<NullSoundSystem> ServiceLocator::m_DefaultSoundSystem{ std::make_shared<NullSoundSystem>() };
	std::shared_ptr<SoundSystem> ServiceLocator::m_SoundSystemInstance{ ServiceLocator::m_DefaultSoundSystem };
	std::unique_ptr<Logger> ServiceLocator::m_LoggingInstance{ std::make_unique<Logger>() };
}


