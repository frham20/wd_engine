#include "wd.hpp"

#if defined( WD_TARGET_DYNAMIC )
BOOL WINAPI DllMain( _In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved )
{
	return TRUE;
}
#endif