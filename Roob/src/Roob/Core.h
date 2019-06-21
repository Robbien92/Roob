#pragma once

#ifdef ROOB_PLATFORM_WINDOWS
	#ifdef ROOB_BUILD_DLL
		#define ROOB_API __declspec(dllexport)
	#else
		#define ROOB_API __declspec(dllimport)
	#endif
#else
	#error Roob only supports Windows!
#endif