#include "wd.h"

namespace wd {

namespace {

	bool window_class_registered = false;
	const char window_class_name[] = "wd_window";

	LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_NCCREATE:
			{
				auto cs = reinterpret_cast<LPCREATESTRUCT>(lparam);
				auto wnd = static_cast<window*>(cs->lpCreateParams);
				wnd->get_platform().hwnd = hwnd;
				::SetWindowLongPtr(hwnd, 0, reinterpret_cast<LONG_PTR>(wnd));
				return TRUE;
			}
		}


		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
}

bool platform_window_init()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = &window_proc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(uintptr);
	wc.hInstance = platform_get_hinstance();
	wc.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = window_class_name;
	wc.hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);

	if (!::RegisterClassEx(&wc))
		return false;

	return true;
}

bool window::platform_init(const char* title, const recti& region)
{
	DWORD exstyle = WS_EX_APPWINDOW | WS_EX_OVERLAPPEDWINDOW;
	DWORD style = WS_OVERLAPPEDWINDOW;

	RECT rc = { region.left, region.top, region.right, region.bottom };

	// this should be provided for the users in the API
	//if (!::AdjustWindowRectEx(&rc, style, FALSE, exstyle))
	//	return false;

	auto result = ::CreateWindowEx(exstyle, window_class_name, title, style,
								   region.left, region.top, region.width(), region.height(),
								   NULL, NULL, platform_get_hinstance(), this);
	if (result != this->platform.hwnd)
		return false;

	return true;
}

bool window::platform_destroy()
{
	if (this->platform.hwnd != NULL)
	{
		if (!::DestroyWindow(this->platform.hwnd))
			return false;

		this->platform.hwnd = NULL;
	}

	return true;
}

void window::platform_set_region(const recti& region)
{

}

void window::platform_set_title(const char* title)
{
	::SetWindowText(this->platform.hwnd, title);
}

void window::platform_set_visible(bool state)
{
	const int cmd = state ? SW_SHOW : SW_HIDE;
	::ShowWindow(this->platform.hwnd, cmd);
}


}