#include "wd.h"

namespace wd
{
	//////////////////////////////////////////////////////////////////////////
	// gfxmanager_platform::physical_device
	//////////////////////////////////////////////////////////////////////////
	struct gfxmanager_platform::physical_device
	{
		explicit physical_device(VkPhysicalDevice handle);

		VkPhysicalDevice handle = VK_NULL_HANDLE;
		VkPhysicalDeviceFeatures features = {};
		VkPhysicalDeviceProperties properties = {};
		std::vector<VkQueueFamilyProperties> queue_families;
	};

	gfxmanager_platform::physical_device::physical_device(VkPhysicalDevice _handle) :
		handle(_handle)
	{
		vkGetPhysicalDeviceProperties(this->handle, &this->properties);
		vkGetPhysicalDeviceFeatures(this->handle, &this->features);

		uint32 queue_count = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(this->handle, &queue_count, nullptr);
		this->queue_families.resize(queue_count);
		vkGetPhysicalDeviceQueueFamilyProperties(this->handle, &queue_count, this->queue_families.data());
	}

	//////////////////////////////////////////////////////////////////////////
	// gfxmanager_platform
	//////////////////////////////////////////////////////////////////////////
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

		if (!select_queues())
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

		this->physical_devices.reserve(device_count);
		for (uint32 i = 0; i < device_count; i++)
		{
			auto phys_device = std::make_unique<physical_device>(devices[i]);
			this->physical_devices.push_back(std::move(phys_device));
		}

		printf("Physical devices found (%d):\n", device_count);
		for (auto& device : this->physical_devices)
			printf("\t%s\n", device->properties.deviceName);

		if (this->physical_devices.empty())
			return false;

		//select the most appropriate device for our needs
		//TODO
		this->current_physical_device = this->physical_devices[0].get();
		printf("Selected physical device: %s\n", this->current_physical_device->properties.deviceName);

		return true;
	}

	bool gfxmanager_platform::select_queues()
	{
		//select the queues we need
		uint32 transfer_queue_index = std::numeric_limits<uint32>::max();
		uint32 compute_queue_index  = std::numeric_limits<uint32>::max();
		uint32 graphics_queue_index = std::numeric_limits<uint32>::max();

		const auto& queues = this->current_physical_device->queue_families;
		const size_t queue_count = queues.size();
		printf("Available queue families (%d):\n", static_cast<uint32>(queue_count));

		for (uint32 i = 0; i < queue_count; i++)
		{
			const auto& queue = queues[i];
			printf("\t%d: flags( 0x%08x ) count( %d )\n", i, queue.queueFlags, queue.queueCount);
			
			if (queue.queueFlags & VK_QUEUE_TRANSFER_BIT)
				transfer_queue_index = i;

			if (queue.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				graphics_queue_index = i;

			if (queue.queueFlags & VK_QUEUE_COMPUTE_BIT)
				compute_queue_index = i;
		}


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

