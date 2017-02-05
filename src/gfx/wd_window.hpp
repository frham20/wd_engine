namespace wd 
{
	inline window::window() :
		platform(*this)
	{
	}

	inline bool window::init(const char* title, const recti& region)
	{
		return this->platform.init(title, region);
	}

	inline const char* window::get_title() const
	{
		return this->platform.get_title();
	}

	inline const recti& window::get_region() const
	{
		return this->platform.get_region();
	}

	inline void window::set_region(const recti& region)
	{
		this->platform.set_region(region);
	}

	inline void window::set_title(const char* title)
	{
		this->platform.set_title(title);
	}

	inline bool window::is_visible() const
	{
		return this->platform.is_visible();
	}

	inline void window::set_visible(bool state)
	{
		this->platform.set_visible(state);
	}

	inline window_platform& window::get_platform()
	{
		return this->platform;
	}

	inline const window_platform& window::get_platform() const
	{
		return this->platform;
	}

}