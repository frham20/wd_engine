#include "wd.h"

namespace wd
{
	namespace
	{
		constexpr const char window_class_name[] = "wd_window";
	}	

	window_platform::window_platform(window& _owner) :
		owner(_owner)
	{

	}

	window_platform::~window_platform()
	{
		destroy();
	}

	bool window_platform::init(const char* title, const recti& region)
	{
		DWORD exstyle = WS_EX_APPWINDOW | WS_EX_OVERLAPPEDWINDOW;
		DWORD style = WS_OVERLAPPEDWINDOW;

		RECT rc = { region.left, region.top, region.right, region.bottom };

		// this should be provided for the users in the API
		//if (!::AdjustWindowRectEx(&rc, style, FALSE, exstyle))
		//	return false;

		auto result = ::CreateWindowEx(exstyle, window_class_name, title, style,
			region.left, region.top, region.width(), region.height(),
			nullptr, nullptr, platform_get_hinstance(), this);
		if (result != this->hwnd)
			return false;

		return true;
	}

	bool window_platform::destroy()
	{
		if (this->hwnd != nullptr)
		{
			if (!::DestroyWindow(this->hwnd))
				return false;
		}

		return true;
	}

	void window_platform::set_region(const recti& region)
	{
		//TODO
		this->region = region;
	}

	void window_platform::set_title(const char* title)
	{
		::SetWindowText(this->hwnd, title);
		this->title = title;
	}

	void window_platform::set_visible(bool state)
	{
		const int cmd = state ? SW_SHOW : SW_HIDE;
		::ShowWindow(this->hwnd, cmd);
	}

	const char* window_platform::get_title() const
	{
		return this->title.c_str();
	}

	const recti& window_platform::get_region() const
	{
		return this->region;
	}

	bool window_platform::is_visible() const
	{
		return this->visible;
	}

	LRESULT window_platform::handle_msg(UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			{
				this->hwnd = nullptr;
				break;
			}
		case WM_CLOSE:
			{
				bool allow = true;
				this->owner.event_close(this->owner, allow);
				if (!allow)
					return 0;

				break;
			}
		}

		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	bool window_platform::init()
	{
		WNDCLASSEX wc;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_CLASSDC | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = &window_platform::window_proc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(uintptr);
		wc.hInstance = platform_get_hinstance();
		wc.hIcon = ::LoadIcon(nullptr, IDI_APPLICATION);
		wc.hCursor = ::LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = window_class_name;
		wc.hIconSm = ::LoadIcon(nullptr, IDI_APPLICATION);

		if (!::RegisterClassEx(&wc))
			return false;

		return true;
	}

	LRESULT CALLBACK window_platform::window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		auto wnd = reinterpret_cast<window_platform*>(::GetWindowLongPtr(hwnd, 0));
		if (wnd == nullptr)
		{
			if (msg == WM_NCCREATE)
			{
				auto cs = reinterpret_cast<LPCREATESTRUCT>(lparam);
				wnd = static_cast<window_platform*>(cs->lpCreateParams);
				wnd->hwnd = hwnd;
				::SetWindowLongPtr(hwnd, 0, reinterpret_cast<LONG_PTR>(wnd));
			}
			else
			{
				return ::DefWindowProc(hwnd, msg, wparam, lparam);
			}
		}

		return wnd->handle_msg(msg, wparam, lparam);
	}
}