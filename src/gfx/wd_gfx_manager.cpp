#include "wd.h"

namespace wd
{
	struct gfx_manager::imp
	{
		imp( gfx_manager& owner )
		    : platform( owner )
		{
		}

		gfx_manager_platform platform;
	};

	gfx_manager::gfx_manager()
	    : m_pimpl( new imp( *this ) )
	{
	}

	gfx_manager::~gfx_manager()
	{
		close();
	}

	bool gfx_manager::init()
	{
		if ( !get_platform().init() )
			return false;

		return true;
	}

	bool gfx_manager::close()
	{
		if ( !get_platform().close() )
			return false;

		return true;
	}

	gfx_manager_platform& gfx_manager::get_platform()
	{
		return m_pimpl->platform;
	}

	const gfx_manager_platform& gfx_manager::get_platform() const
	{
		return m_pimpl->platform;
	}
}
