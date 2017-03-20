#pragma once

//////////////////////////////////////////////////////////////////////////
// engine
//////////////////////////////////////////////////////////////////////////
namespace wd 
{
	class engine_platform;

	class engine : private noncopyable
	{
	public:
		WDAPI engine();
		WDAPI ~engine();
		WDAPI bool init();
		WDAPI bool close();

		WDAPI void run();
		WDAPI void do_frame(float delta_t);

		engine_platform& get_platform();
		const engine_platform& get_platform() const;

	private:
		struct imp;
		std::unique_ptr<imp> m_pimpl;
	};
}
