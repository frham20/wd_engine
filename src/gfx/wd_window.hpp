namespace wd 
{
	inline window::window() :
		region(0, 0, 0, 0),
		title("WD Window"),
		visible(false)
	{

	}

	inline window::~window()
	{
		platform_destroy();
	}

	inline const char* window::get_title() const
	{
		return this->title.c_str();
	}

	inline const recti& window::get_region() const
	{
		return this->region;
	}

	inline void window::set_region(const recti& region)
	{
		platform_set_region(region);
		this->region = region;
	}

	inline void window::set_title(const char* title)
	{
		platform_set_title(title);
		this->title = title;
	}

	inline bool window::is_visible() const
	{
		return this->visible;
	}

	inline void window::set_visible(bool state)
	{
		if (this->visible == state)
			return;

		platform_set_visible(state);
		this->visible = state;
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