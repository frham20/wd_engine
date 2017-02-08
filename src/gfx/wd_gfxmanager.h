#pragma once
#if defined(WD_PLATFORM_WINDOWS)
#include "platform\win\wd_gfxmanager_win.h"
#else
#error Unsupported platform
#endif

namespace wd
{
	class gfxmanager
	{
	public:
		gfxmanager();
		~gfxmanager();

		bool init();
		bool close();

		gfxmanager_platform& get_platform();
		const gfxmanager_platform& get_platform() const;

	private:
		gfxmanager_platform platform;
	};
}
