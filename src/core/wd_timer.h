#pragma once
namespace wd {

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
	uint64 time_us;
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

#include "wd_timer.hpp"