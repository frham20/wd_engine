#include "wd.h"

namespace wd {

engine::engine() :
	initialized(false)
{
}

engine::~engine()
{
	close();
}

bool engine::init()
{
	if (this->initialized)
		return true;

	platform_init();

	this->initialized = true;

	return true;
}

bool engine::close()
{
	platform_close();

	this->initialized = false;
	return true;
}


}