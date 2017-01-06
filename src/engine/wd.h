#pragma once

#if defined(WD_PLATFORM_WINDOWS)
	#include "wd_windows.h"
#else
	#error Unsupported platform!
#endif

//Acceptable warnings
#pragma warning(disable: 4100) //warning C4100: 'xxxxx': unreferenced formal parameter


#include "core\types.h"
#include "core\timer.h"
