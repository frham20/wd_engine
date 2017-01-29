#pragma once

#if defined(WD_PLATFORM_WINDOWS)
#include "win\wd_window_win.h"
#else
#error Unsupported platform
#endif

namespace wd {

class window : private noncopyable
{
public:
	window();
	~window();
	
	WDAPI bool init(const char* title, const recti& region);

	const char* get_title() const;
	const recti& get_region() const;

	void set_region(const recti& region);
	void set_title(const char* title);

private:
	bool platform_init(const char* title, const recti& region);
	bool platform_destroy();
	void platform_set_region(const recti& region);
	void platform_set_title(const char* title);

private:
	window_platform platform;
	std::string title;
	recti region;
};

}

#include "wd_window.hpp"
