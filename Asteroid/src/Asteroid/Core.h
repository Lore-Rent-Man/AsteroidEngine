#pragma once

//Using macros to ensure windows support and check whether file is 
//client or engine to import or export respectively.

#ifdef AS_PLATFORM_WINDOWS
	#ifdef AS_BUILD_DLL
		#define ASTEROID_API __declspec(dllexport)
	#else
		#define ASTEROID_API __declspec(dllimport)
	#endif
#else
	#error Asteroid only support Windows!
#endif

#ifndef NDEBUG
	#define AS_ENABLE_ASSERTS
#endif

#ifdef AS_ENABLE_ASSERTS
	#define AS_ASSERT(x, ...) {if(!x){AS_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define AS_CORE_ASSERT(x, ...) {if(!x){AS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define AS_ASSERT(x, ...)
	#define AS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define AS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
