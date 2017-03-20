#include "wd.hpp"

namespace wd
{
	struct gfxmanager::imp
	{
		imp(gfxmanager& owner) : platform(owner) {}

		gfxmanager_platform platform;
	};

	gfxmanager::gfxmanager() :
		m_pimpl(new imp(*this))
	{

	}

	gfxmanager::~gfxmanager()
	{
		close();
	}

	bool gfxmanager::init()
	{
		if (!get_platform().init())
			return false;

		return true;
	}

	bool gfxmanager::close()
	{
		if (!get_platform().close())
			return false;

		return true;
	}

	gfxmanager_platform& gfxmanager::get_platform()
	{
		return m_pimpl->platform;
	}

	const gfxmanager_platform& gfxmanager::get_platform() const
	{
		return m_pimpl->platform;
	}
}
