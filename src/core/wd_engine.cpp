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

	timer::init();

	this->initialized = true;

	return true;
}

bool engine::close()
{
	this->initialized = false;
	return true;
}


}