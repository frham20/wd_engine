#include "wd.h"

namespace wd
{
	gfxmanager_win::gfxmanager_win(gfxmanager& _owner) :
		owner(_owner)
	{

	}

	gfxmanager_win::~gfxmanager_win()
	{

	}

	bool gfxmanager_win::init()
	{
		if (!init_instance())
			return false;

		if (!init_device())
			return false;

		return true;
	}

	bool gfxmanager_win::close()
	{
		return true;
	}

	bool gfxmanager_win::init_instance()
	{
		printf("Initializing Vulkan Instance...");

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

		auto result = vkCreateInstance(&info, nullptr, &this->vkinstance);
		if (result != VK_SUCCESS)
		{
			printf("ERROR\n");
			return false;
		}

		printf("SUCCESS\n");
		
		return true;
	}

	bool gfxmanager_win::init_device()
	{
		return true;
	}
}

