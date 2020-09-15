add_library(
	Asteroid SHARED
	src/Asteroid.h
	src/Asteroid/Application.cpp
	src/Asteroid/Application.h
	src/Asteroid/Core.h
	src/Asteroid/EntryPoint.h
	src/Asteroid/Log.cpp
	src/Asteroid/Log.h
)

target_include_directories(Asteroid PUBLIC ${ASTEROID_APP_ROOT}/Asteroid/vendor/spdlog/include)

target_compile_definitions(Asteroid PUBLIC AS_PLATFORM_WINDOWS AS_BUILD_DLL)

set_target_properties(Asteroid
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
)
	