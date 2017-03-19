#pragma once

namespace wd
{
	class gfxmanager_platform;

	class gfxmanager
	{
	public:
		gfxmanager();
		~gfxmanager();

		bool init();
		bool close();

		gfxmanager_platform& get_platform();
		const gfxmanager_platform& get_platform() const;

	private:
		struct imp;
		std::unique_ptr<imp> m_pimpl;
	};
}
