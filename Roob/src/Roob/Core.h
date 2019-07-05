#pragma once

#ifdef ROOB_PLATFORM_WINDOWS
	#if ROOB_DYNAMIC_LINK
		#ifdef ROOB_BUILD_DLL
			#define ROOB_API __declspec(dllexport)
		#else
			#define ROOB_API __declspec(dllimport)
		#endif
	#else
		#define ROOB_API
	#endif
#else
	#error Roob only supports Windows!
#endif

#ifdef ROOB_DEBUG
	#define ROOB_ENABLE_ASSERTS
#endif

#ifdef ROOB_ENABLE_ASSERTS
	#define ROOB_ASSERT(x, ...) {if(!(x)) { ROOB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ROOB_CORE_ASSERT(x, ...) {if(!(x)) { ROOB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ROOB_ASSERT(x, ...)
	#define ROOB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ROOB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)