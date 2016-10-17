#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

#include <Windows.h>

namespace Genesis
{

	namespace Utility
	{

		class Timer
		{
		public:
			Timer();
			~Timer() { }

			void Start();
			double Stop();

		private:
			double freq_;
			LARGE_INTEGER start_;
			LARGE_INTEGER stop_;
		};

	}

}

#endif