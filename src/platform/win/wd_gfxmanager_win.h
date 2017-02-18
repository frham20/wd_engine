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
		struct physical_device
		{
			VkPhysicalDevice device = VK_NULL_HANDLE;
			VkPhysicalDeviceFeatures features = {};
			VkPhysicalDeviceProperties properties = {};
		};

	private:
		bool init_instance();
		bool init_device();
		bool select_physical_device();

		physical_device& get_physical_device();
		const physical_device& get_physical_device() const;

	private:
		gfxmanager& owner;
		VkInstance instance	= VK_NULL_HANDLE;
		VkDevice   device	= VK_NULL_HANDLE;
		std::vector<physical_device> physical_devices;
	};
}