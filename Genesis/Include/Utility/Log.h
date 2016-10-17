#pragma once
#ifndef _LOG_H_
#define _LOG_H_

#include <fstream>
#include <vector>
#include <string>

#define Logf(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::Fatal)
#define Loge(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::Error)
#define Logw(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::Warn)
#define Logi(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::Info)
#define Logd(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::Debug)
#define Logv(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::Verbose)
#define Loga(tag, message) Genesis::Utility::Log::Get().Write(tag, message, Genesis::Utility::Log::All)

namespace Genesis
{

	namespace Utility
	{

		class Log
		{
		public:
			// The default filename of the log file
			// TODO: Make this changeable
			const char * kDefaultFilename = "application.log";

			enum LogLevel
			{
				Fatal,
				Error,
				Warn,
				Info,
				Debug,
				Verbose,
				All
			};

			// Singleton access
			static Log & Get()
			{
				static Log * this_;

				if(this_ == 0)
					this_ = new Log();

				return (*this_);
			}

			void Write(const std::string & tag, const std::string & message, LogLevel logLevel = Info)
			{
				// Don't write anything if the current log level is lower than the log level for this
				// log message
				if(logLevel > logLevel_ && logLevel != LogLevel::All)
				{
					return;
				}

				// Make sure the log file is open
				if(!logStream_.is_open())
				{
					return;
				}

				// Write the message to the log
				logStream_ << "[" << kLogLevelStrings[logLevel].c_str() << "][" << tag.c_str() << "]: " << message.c_str() << std::endl << std::flush;
			}

			// Sets the log level for future log messages
			void SetLogLevel(LogLevel level)
			{
				logLevel_ = level;
			}

			// Returns the currently specified log level
			LogLevel GetLogLevel()
			{
				return logLevel_;
			}

		private:
			// Vector of strings which correspond to each log level
			std::vector<std::string> kLogLevelStrings;

			Log()
			{
				// Open a new log file and clear its contents (trunc)
				logStream_.open(kDefaultFilename, std::ios::out | std::ios::trunc);

				kLogLevelStrings = {
					"F",
					"E",
					"W",
					"I",
					"D",
					"V",
					"A"
				};

				// Default log level is Info
				logLevel_ = LogLevel::Info;
			}

			~Log()
			{
				logStream_.close();
			}

			// Singleton object
			static Log * this_;

			// Log file stream
			std::ofstream logStream_;

			// The currently specified log level
			LogLevel logLevel_;
		};

	}

}

#endif