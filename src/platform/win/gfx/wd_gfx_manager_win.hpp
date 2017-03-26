#pragma once

namespace wd
{
	class gfx_physical_device;

	class gfx_manager_platform : private noncopyable
	{
	  public:
		explicit gfx_manager_platform( gfx_manager& owner );
		~gfx_manager_platform();

		bool init();
		bool close();

	  private:
		bool init_instance();
		bool init_device();

		bool                       select_physical_device();
		gfx_physical_device&       get_physical_device();
		const gfx_physical_device& get_physical_device() const;

		std::vector<VkDeviceQueueCreateInfo> select_queues();

	  private:
		gfx_manager& m_owner;
		VkInstance   m_instance = VK_NULL_HANDLE;
		VkDevice     m_device   = VK_NULL_HANDLE;

		std::vector<std::unique_ptr<gfx_physical_device>> m_physical_devices;
		gfx_physical_device*                              m_current_physical_device = {};

		VkQueue m_transfer_queue = VK_NULL_HANDLE; // used to transfer data to the GPU
		VkQueue m_compute_queue  = VK_NULL_HANDLE; // used by compute shader operations
		VkQueue m_graphic_queue  = VK_NULL_HANDLE; // render queue
	};
}