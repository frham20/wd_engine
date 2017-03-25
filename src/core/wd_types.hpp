#pragma once
namespace wd
{
#if defined( WD_PLATFORM_WINDOWS )

	typedef char      int8;
	typedef short     int16;
	typedef int       int32;
	typedef long long int64;

	typedef unsigned char      uint8;
	typedef unsigned short     uint16;
	typedef unsigned int       uint32;
	typedef unsigned long long uint64;

	typedef uint64 uintptr;

#else

#error Unsupported platform!

#endif

} // namespace wd
