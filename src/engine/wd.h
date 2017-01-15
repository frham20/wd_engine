#pragma once

//platform detection
#ifdef _WIN32
#define WD_PLATFORM_WINDOWS
#define WD_PLATFORM_MS
#else
#error Unssuported platform!
#endif


#if defined(WD_PLATFORM_WINDOWS)
#include "win\wd_win.h"
#else
#error Unsupported platform!
#endif

//Acceptable warnings
#pragma warning(disable: 4100) //warning C4100: 'xxxxx': unreferenced formal parameter


#include "core\wd_types.h"
#include "core\wd_timer.h"
