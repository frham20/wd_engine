#pragma once
namespace wd
{
#if defined(WD_PLATFORM_WINDOWS)
	
	typedef char	int8;
	typedef short	int16;
	typedef int		int32;
	typedef __int64	int64;

	typedef unsigned char    uint8;
	typedef unsigned short   uint16;
	typedef unsigned int     uint32;	
	typedef unsigned __int64 uint64;

	typedef uint64 uint_ptr;

#else

	#error Unsupported platform!

#endif
}
