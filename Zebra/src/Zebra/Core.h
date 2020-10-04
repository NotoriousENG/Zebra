#pragma once

#ifdef ZB_PLATFORM_WINDOWS
	#ifdef ZB_BUILD_DLL
		#define ZEBRA_API __declspec(dllexport)
	#else
		#define ZEBRA_API __declspec(dllimport)
	#endif
#else
	#error Zebra only supports Windows!
#endif
