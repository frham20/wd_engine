#include "wd.h"

namespace wd
{
	gfxmanager_platform::gfxmanager_platform(gfxmanager& _owner) :
		owner(_owner)
	{

	}

	gfxmanager_platform::~gfxmanager_platform()
	{

	}

	bool gfxmanager_platform::init()
	{
		printf("=== Initializing Vulkan ===\n");

		if (!init_instance())
			return false;

		if (!select_physical_device())
			return false;

		if (!init_device())
			return false;

		printf("=== SUCCESS ===\n");

		return true;
	}

	bool gfxmanager_platform::close()
	{
		if (this->device != VK_NULL_HANDLE)
		{
			vkDestroyDevice(this->device, nullptr);
			this->device = VK_NULL_HANDLE;
		}

		if (this->instance != VK_NULL_HANDLE)
		{
			vkDestroyInstance(this->instance, nullptr);
			this->instance = VK_NULL_HANDLE;
		}

		return true;
	}

	bool gfxmanager_platform::init_instance()
	{
		//dump available extensions
		uint32 ext_count = 0;
		auto result = vkEnumerateInstanceExtensionProperties(nullptr, &ext_count, nullptr);
		if (result != VK_SUCCESS)
			return false;

		std::vector<VkExtensionProperties> extensions(ext_count);
		result = vkEnumerateInstanceExtensionProperties(nullptr, &ext_count, extensions.data());
		if (result != VK_SUCCESS)
			return false;

		printf("VkInstance extensions found (%d):\n", ext_count);
		for (const auto& ext : extensions)
			printf("\t%s\n", ext.extensionName);

		//needed extensions
		const char* vkextensions[] =
		{
			"VK_KHR_win32_surface"
		};

		VkInstanceCreateInfo info;
		info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		info.flags = 0;
		info.pNext = NULL;
		info.ppEnabledLayerNames = NULL;
		info.enabledLayerCount = 0;
		info.enabledExtensionCount = sizeof(vkextensions) / 32;
		info.ppEnabledExtensionNames = vkextensions;
		info.pApplicationInfo = nullptr;\

		result = vkCreateInstance(&info, nullptr, &this->instance);
		if (result != VK_SUCCESS)
			return false;
	
		return true;
	}

	bool gfxmanager_platform::select_physical_device()
	{
		uint32 device_count = 0;
		auto result = vkEnumeratePhysicalDevices(this->instance, &device_count, nullptr);
		if (result != VK_SUCCESS)
			return false;

		std::vector<VkPhysicalDevice> devices(device_count);
		result = vkEnumeratePhysicalDevices(this->instance, &device_count, devices.data());
		if (result != VK_SUCCESS)
			return false;

		this->physical_devices.resize(device_count);
		for (uint32 i = 0; i < device_count; i++)
			this->physical_devices[i].handle = devices[i];

		printf("VkPhysicalDevice found (%d):\n", device_count);
		for (auto& device : this->physical_devices)
		{
			vkGetPhysicalDeviceProperties(device.handle, &device.properties);
			vkGetPhysicalDeviceFeatures(device.handle, &device.features);

			uint32 queue_count = 0;
			vkGetPhysicalDeviceQueueFamilyProperties(device.handle, &queue_count, nullptr);
			device.queue_families.resize(queue_count);
			vkGetPhysicalDeviceQueueFamilyProperties(device.handle, &queue_count, device.queue_families.data());

			printf("\t%s\n", device.properties.deviceName);
		}

		if (this->physical_devices.empty())
			return false;

		//select the most appropriate device for our needs
		//TODO
		this->current_physical_device = &this->physical_devices[0];

		return true;
	}

	bool gfxmanager_platform::init_device()
	{


		return true;
	}

	gfxmanager_platform::physical_device& gfxmanager_platform::get_physical_device()
	{
		return *this->current_physical_device;
	}

	const gfxmanager_platform::physical_device& gfxmanager_platform::get_physical_device() const
	{
		return *this->current_physical_device;
	}
}

