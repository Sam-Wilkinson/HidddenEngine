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

		static Logger& GetLoggerSystem() { return *m_LoggingInstance; };

	private:
		static std::shared_ptr<SoundSystem> m_SoundSystemInstance;
		static std::shared_ptr<NullSoundSystem> m_DefaultSoundSystem;
		static std::unique_ptr<Logger> m_LoggingInstance;
	};

}


