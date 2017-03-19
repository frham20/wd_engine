#include "wd.h"

namespace wd 
{
	struct engine::imp
	{
		imp(engine& owner) : platform(owner) {}

		engine_platform platform;
		gfxmanager gfx;
		bool initialized = false;
	};

	engine::engine() :
		m_pimpl(new imp(*this))
	{

	}

	engine::~engine()
	{
		close();
	}

	bool engine::init()
	{
		if (m_pimpl->initialized)
			return true;

		if (!get_platform().init())
			return false;

		if (!m_pimpl->gfx.init())
			return false;

		m_pimpl->initialized = true;

		return true;
	}

	bool engine::close()
	{
		if (!get_platform().close())
			return false;

		if (!m_pimpl->gfx.close())
			return false;

		m_pimpl->initialized = false;
		return true;
	}

	void engine::do_frame(float delta_t)
	{
		//TODO! :)
	}

	void engine::run()
	{
		const double min_delta_t = 1.0 / 240.0;
		double starttime = get_time_s();
		while (true)
		{
			if (!get_platform().process_messages())
				break;

			double delta_t = get_time_s() - starttime;

			//spin until we hit min_delta_t
			while (delta_t < min_delta_t)
				delta_t = get_time_s() - starttime;

			starttime = get_time_s();
			do_frame(static_cast<float>(delta_t));
		}
	}

	engine_platform& engine::get_platform()
	{
		return m_pimpl->platform;
	}

	const engine_platform& engine::get_platform() const
	{
		return m_pimpl->platform;
	}

}//namespace wd