#include "wd.h"
#include "wd_timer.h"

namespace wd {

namespace _timer_internal {

#if defined(WD_PLATFORM_WINDOWS)
uint64 ticks_per_second = 0;
#endif

}//namespace _platform_internal

void timer::init()
{
	#if defined(WD_PLATFORM_WINDOWS)
	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&_timer_internal::ticks_per_second));
	#endif
}

}//namespace wd