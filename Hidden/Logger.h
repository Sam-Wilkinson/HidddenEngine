#pragma once

#include <fstream>
#include <string>
#include <mutex>

namespace Hidden
{
	class Logger final
	{
	public:
		enum class Level
		{
			Info = 0,
			Debug = 1,
			Warning = 2,
			Error = 3,
			Fatal = 4
		};

		Logger() = default;
		virtual ~Logger();

		bool StartLogger(const std::string& filePath);

		Logger(const Logger & other) = default; // copy constructor
		Logger(Logger && other) noexcept = default; // move constructor
		Logger& operator=(const Logger & other) = default; // copy assignment
		Logger& operator=(Logger && other) noexcept = default; // move assignment


		void Log(Level l, const std::string& msg);

		void LogInfo(const std::string& msg);
		void LogDebug(const std::string& msg);
		void LogWarning(const std::string& msg);
		void LogError(const std::string& msg);
		void LogFatal(const std::string& msg);

	private:
		std::string m_Levels[5] = { "Info", "Debug", "Warning", "Error", "Fatal" };
		std::mutex m_Mutex;
		std::ofstream m_LogFile;

	};
}


