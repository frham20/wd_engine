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
		struct physical_device;

	private:
		bool init_instance();
		bool init_device();
		bool select_physical_device();
		bool select_queues();

		physical_device& get_physical_device();
		const physical_device& get_physical_device() const;

	private:
		gfxmanager& owner;
		VkInstance instance	= VK_NULL_HANDLE;
		VkDevice   device	= VK_NULL_HANDLE;
		std::vector<std::unique_ptr<physical_device>> physical_devices;
		physical_device* current_physical_device = {};

		VkQueue transfer_queue; //used for transfering data to the GPU
		VkQueue compute_queue;  //used by compute shader operations
		VkQueue graphic_queue;  //main render queue
		
	};
}