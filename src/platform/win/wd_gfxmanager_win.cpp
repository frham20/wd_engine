#include "wd.hpp"

namespace wd
{
	//////////////////////////////////////////////////////////////////////////
	// gfxmanager_platform::physical_device
	//////////////////////////////////////////////////////////////////////////
	struct gfxmanager_platform::physical_device
	{
		explicit physical_device(VkPhysicalDevice handle);

		int32 find_dedicated_queue_family_index(VkQueueFlagBits flag) const;
		int32 find_queue_family_index(VkQueueFlagBits flags) const;

		VkPhysicalDevice m_handle = VK_NULL_HANDLE;
		VkPhysicalDeviceFeatures m_features = {};
		VkPhysicalDeviceProperties m_properties = {};
		std::vector<VkQueueFamilyProperties> m_queue_families;
	};

	gfxmanager_platform::physical_device::physical_device(VkPhysicalDevice handle) :
		m_handle(handle)
	{
		vkGetPhysicalDeviceProperties(m_handle, &m_properties);
		vkGetPhysicalDeviceFeatures(m_handle, &m_features);

		uint32 queue_count = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(m_handle, &queue_count, nullptr);
		m_queue_families.resize(queue_count);
		vkGetPhysicalDeviceQueueFamilyProperties(m_handle, &queue_count, m_queue_families.data());
	}

	int32 gfxmanager_platform::physical_device::find_queue_family_index(VkQueueFlagBits flags) const
	{
		const int32 queue_count = static_cast<int32>(m_queue_families.size());
		for (int32 i = 0; i < queue_count; i++)
		{
			if ((m_queue_families[i].queueFlags & flags) == VkQueueFlags(flags))
				return i;
		}

		return -1;
	}

	//////////////////////////////////////////////////////////////////////////
	// gfxmanager_platform
	//////////////////////////////////////////////////////////////////////////
	gfxmanager_platform::gfxmanager_platform(gfxmanager& owner) :
		m_owner(owner)
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

		if (!init_device())
			return false;

		printf("=== SUCCESS ===\n");

		return true;
	}

	bool gfxmanager_platform::close()
	{
		if (m_device != VK_NULL_HANDLE)
		{
			vkDestroyDevice(m_device, nullptr);
			m_device = VK_NULL_HANDLE;
		}

		if (m_instance != VK_NULL_HANDLE)
		{
			vkDestroyInstance(m_instance, nullptr);
			m_instance = VK_NULL_HANDLE;
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

		result = vkCreateInstance(&info, nullptr, &m_instance);
		if (result != VK_SUCCESS)
			return false;
	
		return true;
	}

	bool gfxmanager_platform::select_physical_device()
	{
		uint32 device_count = 0;
		auto result = vkEnumeratePhysicalDevices(m_instance, &device_count, nullptr);
		if (result != VK_SUCCESS)
			return false;

		std::vector<VkPhysicalDevice> devices(device_count);
		result = vkEnumeratePhysicalDevices(m_instance, &device_count, devices.data());
		if (result != VK_SUCCESS)
			return false;

		m_physical_devices.reserve(device_count);
		for (uint32 i = 0; i < device_count; i++)
		{
			auto phys_device = std::make_unique<physical_device>(devices[i]);
			m_physical_devices.push_back(std::move(phys_device));
		}

		printf("Physical devices found (%d):\n", device_count);
		for (auto& device : m_physical_devices)
			printf("\t%s\n", device->m_properties.deviceName);

		if (m_physical_devices.empty())
			return false;

		//select the most appropriate device for our needs
		//TODO
		m_current_physical_device = m_physical_devices[0].get();
		printf("Selected physical device: %s\n", m_current_physical_device->m_properties.deviceName);

		return true;
	}

	std::vector<VkDeviceQueueCreateInfo> gfxmanager_platform::select_queues()
	{
		const auto& queues = m_current_physical_device->m_queue_families;
		const int32 queue_count = static_cast<int32>(queues.size());
		printf("Available queue families (%d):\n", queue_count);
		for (int32 i = 0; i < queue_count; i++)
		{
			const auto& queue = queues[i];
			printf("\t%d: flags( 0x%08x ) count( %d )\n", i, queue.queueFlags, queue.queueCount);
		}

		//select the queue families we need
//		int32 transfer_queue_index = m_current_physical_device->find_queue_family_index(VK_QUEUE_TRANSFER_BIT);
// 		if (transfer_queue_index == -1)
// 		{
// 
// 		}

//		int32 compute_queue_index  = m_current_physical_device->find_queue_family_index(VK_QUEUE_COMPUTE_BIT);
//		int32 graphics_queue_index = m_current_physical_device->find_queue_family_index(VK_QUEUE_GRAPHICS_BIT);
		

		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
		queueCreateInfos.reserve(3);


		VkDeviceQueueCreateInfo qi = {};
		qi.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;

		return queueCreateInfos;
	}

	bool gfxmanager_platform::init_device()
	{
		if (!select_physical_device())
			return false;

		auto queueCreateInfos = select_queues();
		if (queueCreateInfos.empty())
			return false;

		VkDeviceCreateInfo info = {};
		info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		info.pQueueCreateInfos = queueCreateInfos.data();
		info.pNext = nullptr;
//		vkCreateDevice()


		return true;
	}

	gfxmanager_platform::physical_device& gfxmanager_platform::get_physical_device()
	{
		return *m_current_physical_device;
	}

	const gfxmanager_platform::physical_device& gfxmanager_platform::get_physical_device() const
	{
		return *m_current_physical_device;
	}
}

