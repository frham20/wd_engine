#pragma once
namespace wd {

namespace _timer_internal {

constexpr double US_TO_MS_FACTOR = 1.0 / 1'000.0;
constexpr double US_TO_S_FACTOR = 1.0 / 1'000'000.0;

#if defined(WD_PLATFORM_WINDOWS)
extern uint64 ticks_per_second;
#endif

inline uint64 get_time_us()
{
	#if defined(WD_PLATFORM_WINDOWS)
	uint64 ticks;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&ticks));
	return (ticks * 1'000'000) / ticks_per_second;
	#endif
}

}//namespace _timer_internal


inline uint64 timer::start()
{
	this->time_us = _timer_internal::get_time_us();
	return this->time_us;
}

inline uint64 timer::stop()
{
	this->time_us = _timer_internal::get_time_us() - this->time_us;
	return this->time_us;
}

inline uint64 timer::get_us() const
{
	return this->time_us;
}

inline double timer::get_ms() const
{
	return static_cast<double>(this->time_us) * _timer_internal::US_TO_MS_FACTOR;
}

inline double timer::get_s() const
{
	return static_cast<double>(this->time_us) *_timer_internal::US_TO_S_FACTOR;
}

inline timer timer::create()
{
	timer tm;
	tm.start();
	return tm;
}

template<typename FN>
inline uint64 time_us(FN fn)
{
	timer tm;
	tm.start();
	fn();
	return tm.stop();
}

template<typename FN>
double time_ms(FN fn)
{
	timer tm;
	tm.start();
	fn();
	tm.stop();
	return tm.get_ms();
}

template<typename FN>
double time_s(FN fn)
{
	timer tm;
	tm.start();
	fn();
	tm.stop();
	return tm.get_s();
}

template<typename FN, typename FNC>
inline void time_us(FN fn, FNC then)
{
	then(time_us(fn));
}

template<typename FN, typename FNC>
inline void time_ms(FN fn, FNC then)
{
	then(time_ms(fn));
}

template<typename FN, typename FNC> 
inline void time_s(FN fn, FNC then)
{
	then(time_s(fn));
}

}//namespace wd
