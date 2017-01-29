#include "wd.h"

namespace wd {

namespace {

	bool window_class_registered = false;
	const char window_class_name[] = "wd_window";

	LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
}

bool window::platform_init(const char* title, const recti& region)
{
	/*
	if (!window_class_registered)
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = &window_proc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(uintptr);
		wc.hInstance = NULL; //TODO
		wc.hIcon = ::LoadIcon(;

			HICON       hIcon;
		HCURSOR     hCursor;
		HBRUSH      hbrBackground;
		LPCSTR      lpszMenuName;
		LPCSTR      lpszClassName;
		HICON       hIconSm;
		}


		::RegisterClassEx()
	}

	this->platform.hwnd = 
	*/
	return true;
}

bool window::platform_destroy()
{
	return true;
}

void window::platform_set_region(const recti& region)
{

}

void window::platform_set_title(const char* title)
{

}


}