#include "wd.h"

namespace wd
{
	gfxmanager::gfxmanager() :
		platform(*this)
	{

	}

	gfxmanager::~gfxmanager()
	{
		close();
	}

	bool gfxmanager::init()
	{
		if (!this->platform.init())
			return false;

		return true;
	}

	bool gfxmanager::close()
	{
		if (!this->platform.close())
			return false;

		return true;
	}

	gfxmanager_platform& gfxmanager::get_platform()
	{
		return this->platform;
	}

	const gfxmanager_platform& gfxmanager::get_platform() const
	{
		return this->platform;
	}
}
