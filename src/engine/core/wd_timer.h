#pragma once
namespace wd {

class timer
{
public:
	void start();
	uint64 stop();

	uint64 get_us() const;
	double get_ms() const;
	double get_s() const;

public:
	static void init();

private:
	uint64 time_us;
};

}//namespace wd

#include "wd_timer.hpp"