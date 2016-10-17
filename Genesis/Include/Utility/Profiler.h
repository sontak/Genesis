#pragma once
#ifndef _PROFILER_H_
#define _PROFILER_H_

#include "Timer.h"
#include "Log.h"

#define PROFILE_START(module) Genesis::Utility::Profiler _profiler(module)
#define PROFILE_STOP _profiler.Stop()

namespace Genesis
{

	namespace Utility
	{

		class Profiler
		{
		public:
			Profiler(const std::string & module)
				: module_(module)
			{
				Logv(kLogTag, "*** Profile begin for [" + module_ + "]");
				timer_.Start();
			}

			void Stop()
			{
				double time = timer_.Stop();

				Logv(kLogTag, "*** Profile end for [" + module_ + "]");
				Logv(kLogTag, "***      Elapsed: " + std::to_string(time) + " ms");
			}

		private:
			const char * kLogTag = "Profiler";
			std::string module_;
			Timer timer_;
		};

	}

}

#endif