#pragma once
#if defined(WD_PLATFORM_WINDOWS)
#include "platform\win\wd_engine_win.h"
#else
#error Unsupported platform
#endif

namespace wd 
{
	class engine : private noncopyable
	{
	public:
		WDAPI engine();
		WDAPI ~engine();
		WDAPI bool init();
		WDAPI bool close();

		WDAPI void run();
		WDAPI void do_frame(float delta_t);

		engine_platform& get_platform();
		const engine_platform& get_platform() const;

	private:
		engine_platform platform;
		gfxmanager gfx;
		bool initialized = false;
	};
}
