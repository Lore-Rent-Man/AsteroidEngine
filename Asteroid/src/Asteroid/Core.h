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

#define BIT(x) (1 << x)