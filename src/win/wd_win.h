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

//Acceptable warnings
#pragma warning(disable: 4100) //warning C4100: 'xxxxx': unreferenced formal parameter
#pragma warning(disable: 4458) //warning C4458 : declaration of 'xxxx' hides class member
#pragma warning(disable: 4180) //warning C4180 : qualifier applied to function type has no meaning; ignored
