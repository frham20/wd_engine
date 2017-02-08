#pragma once

namespace wd
{
	class gfxmanager;

	class gfxmanager_win : private noncopyable
	{
	public:
		explicit gfxmanager_win(gfxmanager& owner);
		~gfxmanager_win();

		bool init();
		bool close();

	private:
		bool init_instance();
		bool init_device();

	private:
		gfxmanager& owner;
		VkInstance vkinstance;
		VkDevice   vkdevice;

	};


	typedef gfxmanager_win gfxmanager_platform;
}