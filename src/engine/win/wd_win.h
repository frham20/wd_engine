#pragma once

#define NOMINMAX
#include <windows.h>

#if defined(WD_TARGET_DYNAMIC)

#ifdef WD_ENGINE_EXPORTS
#define WDAPI __declspec(dllexport)
#else
#define WDAPI __declspec(dllimport)
#endif

#else

#define WD_TARGET_STATIC
#define WDAPI

#endif//defined(WD_TARGET_DYNAMIC)



#ifdef _DEBUG
#define WD_TARGET_DEBUG
#else
#define WD_TARGET_RELEASE
#endif
