#include "wd.h"
#include "wd_window_win.h"

namespace wd {

	extern bool platform_timer_init();

	namespace 
	{
		HINSTANCE hinstance;
	}

	HINSTANCE engine_platform::get_hinstance()
	{
		return hinstance;
	}

	engine_platform::engine_platform(engine& _owner) :
		owner(_owner)
	{

	}

	bool engine_platform::init()
	{
		//find hinstance of the module the engine is currently in
		HMODULE module_handle;
		if (!::GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, reinterpret_cast<LPCTSTR>(&hinstance), &module_handle))
			return false;

		hinstance = reinterpret_cast<HINSTANCE>(module_handle);

		if (!platform_timer_init())
			return false;

		if (!window_platform::init())
			return false;

		return true;
	}

	bool engine_platform::close()
	{
		return true;
	}

	bool engine_platform::process_messages()
	{
		bool quit = false;

		MSG msg;
		while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				quit = true;

			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}

		return !quit;
	}

}//namespace wd