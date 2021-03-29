#include "HiddenPCH.h"
#include "ServiceLocator.h"


using namespace Hidden;

std::shared_ptr<NullSoundSystem> ServiceLocator::m_DefaultSoundSystem{ std::make_shared<NullSoundSystem>() };
std::shared_ptr<SoundSystem> ServiceLocator::m_SoundSystemInstance{ ServiceLocator::m_DefaultSoundSystem };
std::unique_ptr<Logger> ServiceLocator::m_LoggingInstance{ std::make_unique<Logger>() };
