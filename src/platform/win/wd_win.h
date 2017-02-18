#pragma once

#define NOMINMAX
#include <windows.h>

//don't expose vulkan to anything outside of this lib
//not easy without losing perfs... need to hide class members in CPP files
//need to think about this some more
//#if defined(WD_ENGINE)
	#define VK_USE_PLATFORM_WIN32_KHR
	#include "vulkan\vulkan.h"
//#endif

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

//Acceptable warnings
#pragma warning(disable: 4100) //warning C4100: 'xxxxx': unreferenced formal parameter
#pragma warning(disable: 4458) //warning C4458 : declaration of 'xxxx' hides class member
#pragma warning(disable: 4180) //warning C4180 : qualifier applied to function type has no meaning; ignored

