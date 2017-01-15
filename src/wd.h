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


#if !defined(WD_NO_TYPEALIASES)
using int8 = wd::int8;
using int16 = wd::int16;
using int32 = wd::int32;
using int64 = wd::int64;
using uint8 = wd::uint8;
using uint16 = wd::uint16;
using uint32 = wd::uint32;
using uint64 = wd::uint64;
using uintptr = wd::uintptr;
#endif