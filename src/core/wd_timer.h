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
	WDAPI static void init();
	static timer create();

private:
	uint64 time_us;
};

template<typename FN> uint64 time_us(FN fn);
template<typename FN> double time_ms(FN fn);
template<typename FN> double time_s(FN fn);

}//namespace wd

#include "wd_timer.hpp"