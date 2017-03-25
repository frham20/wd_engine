#pragma once

//////////////////////////////////////////////////////////////////////////
// gfx_physical_device
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	class gfx_physical_device
	{
	  public:
		explicit gfx_physical_device( VkPhysicalDevice handle );

		int32 find_queue_family_index( VkQueueFlagBits flags ) const;

		VkPhysicalDevice                            get_handle() const;
		const VkPhysicalDeviceFeatures&             get_features() const;
		const VkPhysicalDeviceProperties&           get_properties() const;
		const std::vector<VkQueueFamilyProperties>& get_queue_families() const;

	  private:
		VkPhysicalDevice                     m_handle     = VK_NULL_HANDLE;
		VkPhysicalDeviceFeatures             m_features   = {};
		VkPhysicalDeviceProperties           m_properties = {};
		std::vector<VkQueueFamilyProperties> m_queue_families;
	};
}

//////////////////////////////////////////////////////////////////////////
// imp
//////////////////////////////////////////////////////////////////////////
namespace wd
{
	inline VkPhysicalDevice gfx_physical_device::get_handle() const
	{
		return m_handle;
	}

	inline const VkPhysicalDeviceFeatures& gfx_physical_device::get_features() const
	{
		return m_features;
	}

	inline const VkPhysicalDeviceProperties& gfx_physical_device::get_properties() const
	{
		return m_properties;
	}

	inline const std::vector<VkQueueFamilyProperties>& gfx_physical_device::get_queue_families() const
	{
		return m_queue_families;
	}
}
