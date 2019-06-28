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

#ifdef ROOB_ENABLE_ASSERTS
	#define ROOB_ASSERT(x, ...) {if(!(x)) { ROOB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ROOB_CORE_ASSERT(x, ...) {if(!(x)) { ROOB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ROOB_ASSERT(x, ...)
	#define ROOB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)