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
		if (!init_instance())
			return false;

		if (!init_device())
			return false;

		return true;
	}

	bool gfxmanager_platform::close()
	{
		return true;
	}

	bool gfxmanager_platform::init_instance()
	{
		printf("=== Initializing Vulkan Instance ===\n");

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
		for (auto& ext : extensions)
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
		info.pApplicationInfo = nullptr;

		result = vkCreateInstance(&info, nullptr, &this->vkinstance);
		if (result != VK_SUCCESS)
			return false;

		printf("=== SUCCESS ===\n");
		
		return true;
	}

	bool gfxmanager_platform::init_device()
	{
		return true;
	}
}

