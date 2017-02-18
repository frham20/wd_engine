#include "wd.h"
#include "wd_window.h"

#include "..\platform\win\wd_window_win.h"


namespace wd 
{
	struct window::imp
	{
		imp(window& owner) : platform(owner) {}
		window_platform platform;
	};

	window::window() :
		pimpl(new imp(*this))
	{
	}

	window::~window()
	{

	}

	bool window::init(const char* title, const recti& region)
	{
		return get_platform().init(title, region);
	}

	const char* window::get_title() const
	{
		return get_platform().get_title();
	}

	const recti& window::get_region() const
	{
		return get_platform().get_region();
	}

	void window::set_region(const recti& region)
	{
		get_platform().set_region(region);
	}

	void window::set_title(const char* title)
	{
		get_platform().set_title(title);
	}

	bool window::is_visible() const
	{
		return get_platform().is_visible();
	}

	void window::set_visible(bool state)
	{
		get_platform().set_visible(state);
	}

	window_platform& window::get_platform()
	{
		return this->pimpl->platform;
	}

	const window_platform& window::get_platform() const
	{
		return this->pimpl->platform;
	}
}