#pragma once

namespace wd
{
	class gfxmanager_platform : private noncopyable
	{
	public:
		explicit gfxmanager_platform(gfxmanager& owner);
		~gfxmanager_platform();

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
}