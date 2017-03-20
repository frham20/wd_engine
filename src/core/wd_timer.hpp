#pragma once

//////////////////////////////////////////////////////////////////////////
// timer
//////////////////////////////////////////////////////////////////////////
namespace wd 
{
	class timer
	{
	public:
		uint64 start();
		uint64 stop();

		uint64 get_us() const;
		double get_ms() const;
		double get_s() const;

	public:
		static timer create();

	private:
		uint64 m_time_us;
	};

	uint64 get_time_us();
	double get_time_ms();
	double get_time_s();

	template<typename FN> uint64 time_us(FN fn);
	template<typename FN> double time_ms(FN fn);
	template<typename FN> double time_s(FN fn);

	template<typename FN, typename FNC> void time_us(FN fn, FNC then);
	template<typename FN, typename FNC> void time_ms(FN fn, FNC then);
	template<typename FN, typename FNC> void time_s(FN fn, FNC then);

}//namespace wd

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
namespace wd {

	namespace _timer_internal
	{
		constexpr double US_TO_MS_FACTOR = 1.0 / 1'000.0;
		constexpr double US_TO_S_FACTOR = 1.0 / 1'000'000.0;
	}//namespace _timer_internal

	uint64 platform_get_time_us();

	inline uint64 get_time_us()
	{
		return platform_get_time_us();
	}

	inline double get_time_ms()
	{
		return static_cast<double>(get_time_us()) * _timer_internal::US_TO_MS_FACTOR;
	}

	inline double get_time_s()
	{
		return static_cast<double>(get_time_us()) * _timer_internal::US_TO_S_FACTOR;
	}

	inline uint64 timer::start()
	{
		m_time_us = get_time_us();
		return m_time_us;
	}

	inline uint64 timer::stop()
	{
		m_time_us = get_time_us() - m_time_us;
		return m_time_us;
	}

	inline uint64 timer::get_us() const
	{
		return m_time_us;
	}

	inline double timer::get_ms() const
	{
		return static_cast<double>(m_time_us) * _timer_internal::US_TO_MS_FACTOR;
	}

	inline double timer::get_s() const
	{
		return static_cast<double>(m_time_us) *_timer_internal::US_TO_S_FACTOR;
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

#if defined(WD_PLATFORM_WINDOWS)
#include "platform\win\wd_timer_win.hpp"
#endif
