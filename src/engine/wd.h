#pragma once

//platform detection
#ifdef _WIN64

#define WD_PLATFORM_WINDOWS
#define WD_PLATFORM_MS
#include "win\wd_win.h"

#else

#error Unssuported platform!

#endif


#include "core\wd_types.h"
#include "core\wd_timer.h"
