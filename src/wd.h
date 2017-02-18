#pragma once

//platform detection
#ifdef _WIN64

#define WD_PLATFORM_WINDOWS
#define WD_PLATFORM_MS
#include "platform\win\wd_win.h"

#else

#error Unssuported platform!

#endif

//std
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <type_traits>


//core
#include "core\wd_types.h"
#include "core\wd_noncopyable.h"
#include "core\wd_timer.h"
#include "core\wd_event.h"

//math
#include "math\wd_point2.h"
#include "math\wd_vec2.h"
#include "math\wd_rect.h"

//io

//res

//gfx
#include "gfx\wd_window.h"
#include "gfx\wd_gfxmanager.h"


#include "core\wd_engine.h"


//platform specific implementations
//only used when compiling the engine itself
#if defined(WD_ENGINE)
#if defined(WD_PLATFORM_WINDOWS)
#include "platform\win\wd_win_imp.h"
#endif
#endif


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


