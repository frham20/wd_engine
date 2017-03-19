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
		std::vector<VkDeviceQueueCreateInfo> select_queues();

		physical_device& get_physical_device();
		const physical_device& get_physical_device() const;

	private:
		gfxmanager& m_owner;
		VkInstance m_instance   = VK_NULL_HANDLE;
		VkDevice m_device       = VK_NULL_HANDLE;
		std::vector<std::unique_ptr<physical_device>> m_physical_devices;

		physical_device* m_current_physical_device = {};
		VkQueue m_transfer_queue= VK_NULL_HANDLE; //used to transfer data to the GPU
		VkQueue m_compute_queue = VK_NULL_HANDLE; //used by compute shader operations
		VkQueue m_graphic_queue = VK_NULL_HANDLE; //render queue
		
	};
}