#include "HiddenPCH.h"
#include "Logger.h"
#include <iostream>

Hidden::Logger::~Logger()
{
	m_LogFile.close();
}


// Not thread safe
bool Hidden::Logger::StartLogger(const std::string& filePath)
{
	m_LogFile.open(filePath);

	if (!m_LogFile.is_open())
	{
		std::cout << "ERROR: failed to open logging file" << std::endl;
		return false;
	}

	return true;
}

void Hidden::Logger::Log(Level l, const std::string& msg)
{
	std::lock_guard<std::mutex> lock(m_Mutex);
	if (m_LogFile.is_open())
	{
		m_LogFile << m_Levels[static_cast<int>(l)] + " >> "  <<  msg  << std::endl;
	}
}

void Hidden::Logger::LogInfo(const std::string& msg)
{
	Log(Level::Info, msg);
}

void Hidden::Logger::LogDebug(const std::string& msg)
{
	Log(Level::Debug, msg);
}

void Hidden::Logger::LogWarning(const std::string& msg)
{
	Log(Level::Warning, msg);
}

void Hidden::Logger::LogError(const std::string& msg)
{
	Log(Level::Error, msg);
}

void Hidden::Logger::LogFatal(const std::string& msg)
{
	Log(Level::Fatal, msg);
}
