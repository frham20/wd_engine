#include "wd.h"

namespace wd 
{
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
			if (!platform_process_messages())
				break;

			double delta_t = get_time_s() - starttime;

			//spin until we hit min_delta_t
			while (delta_t < min_delta_t)
				delta_t = get_time_s() - starttime;

			starttime = get_time_s();
			do_frame(static_cast<float>(delta_t));
		}
	}

}//namespace wd