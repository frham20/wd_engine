#include "wd.h"
#include "wd_gfx_physical_device_vk.h"

namespace wd
{
	gfx_physical_device::gfx_physical_device( VkPhysicalDevice handle )
	    : m_handle( handle )
	{
		vkGetPhysicalDeviceProperties( m_handle, &m_properties );
		vkGetPhysicalDeviceFeatures( m_handle, &m_features );

		uint32 queue_count = 0;
		vkGetPhysicalDeviceQueueFamilyProperties( m_handle, &queue_count, nullptr );
		m_queue_families.resize( queue_count );
		vkGetPhysicalDeviceQueueFamilyProperties( m_handle, &queue_count, m_queue_families.data() );
	}

	int32 gfx_physical_device::find_queue_family_index( VkQueueFlagBits flags ) const
	{
		const int32 queue_count = static_cast<int32>( m_queue_families.size() );
		for ( int32 i = 0; i < queue_count; i++ )
		{
			if ( ( m_queue_families[i].queueFlags & flags ) == VkQueueFlags( flags ) )
				return i;
		}

		return -1;
	}
}