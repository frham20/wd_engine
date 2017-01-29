namespace wd {


inline window::window() :
	region(0,0,0,0),
	title("WD Window")
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

}