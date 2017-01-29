#include "wd.h"

namespace wd {

namespace _timer_internal {
	uint64 ticks_per_second = 0;
}

bool engine::platform_init()
{
	//get perf timer frequency
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_timer_internal::ticks_per_second));

	return true;
}

bool engine::platform_close()
{
	return true;
}

}