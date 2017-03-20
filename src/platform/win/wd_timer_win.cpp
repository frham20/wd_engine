#include "wd.hpp"

namespace wd
{
	namespace _timer_internal
	{
		uint64 ticks_per_second = 0;
	}

	bool platform_timer_init()
	{
		//get perf timer frequency
		return ::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_timer_internal::ticks_per_second)) != 0;
	}

}