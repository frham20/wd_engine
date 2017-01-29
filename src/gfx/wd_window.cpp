#include "wd.h"
#include "wd_window.h"

namespace wd {


bool window::init(const char* title, const recti& region)
{
	if (!platform_init(title, region))
		return false;

	this->title = title;
	this->region = region;

	return true;
}

}