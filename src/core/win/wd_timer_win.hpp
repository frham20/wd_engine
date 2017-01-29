#pragma once

namespace wd {

namespace _timer_internal {
	extern uint64 ticks_per_second;
}

inline uint64 platform_get_time_us()
{
	uint64 ticks;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&ticks));
	return (ticks * 1'000'000) / _timer_internal::ticks_per_second;
}

}
