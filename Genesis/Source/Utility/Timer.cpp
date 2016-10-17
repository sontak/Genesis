#include "Utility\Timer.h"

namespace Genesis
{

	namespace Utility
	{
		Timer::Timer()
		{
			LARGE_INTEGER clockFreq;

			QueryPerformanceFrequency(&clockFreq);
			freq_ = (double)clockFreq.QuadPart / 1000.0;
		}

		void Timer::Start()
		{
			QueryPerformanceCounter(&start_);
		}

		double Timer::Stop()
		{
			QueryPerformanceCounter(&stop_);

			return (stop_.QuadPart - start_.QuadPart) / freq_;
		}
	}

}