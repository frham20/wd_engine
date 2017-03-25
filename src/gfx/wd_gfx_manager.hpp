#pragma once

namespace wd
{
	class gfx_manager_platform;

	class gfx_manager
	{
	  public:
		gfx_manager();
		~gfx_manager();

		bool init();
		bool close();

		gfx_manager_platform&       get_platform();
		const gfx_manager_platform& get_platform() const;

	  private:
		struct imp;
		std::unique_ptr<imp> m_pimpl;
	};
}
