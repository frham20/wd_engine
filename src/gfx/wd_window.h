#pragma once

#if defined(WD_PLATFORM_WINDOWS)
#include "platform\win\wd_window_win.h"
#else
#error Unsupported platform
#endif

namespace wd
{
	class window : private noncopyable
	{
	public:
		window();

		bool init(const char* title, const recti& region);

		const char* get_title() const;
		const recti& get_region() const;

		void set_region(const recti& region);
		void set_title(const char* title);

		bool is_visible() const;
		void set_visible(bool state);

		window_platform& get_platform();
		const window_platform& get_platform() const;

		event<window&, bool&> event_close;
		event<window&, recti&> event_resize;
		event<window&, recti&> event_resizing;

	private:
		window_platform platform;
	};
}

#include "wd_window.hpp"
