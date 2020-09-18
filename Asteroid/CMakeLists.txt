add_library(
	Asteroid SHARED
	src/Asteroid.h
	src/Asteroid/Application.cpp
	src/Asteroid/Application.h
	src/Asteroid/Core.h
	src/Asteroid/EntryPoint.h
	src/Asteroid/Log.cpp
	src/Asteroid/Log.h
	src/Asteroid/Events/Event.h
	src/Asteroid/Events/KeyEvent.h
	src/Asteroid/Events/ApplicationEvent.h
	src/Asteroid/Events/MouseEvent.h
)

target_include_directories(Asteroid PUBLIC 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/spdlog/include
	${ASTEROID_APP_ROOT}/Asteroid/src
)

target_compile_definitions(Asteroid PUBLIC AS_BUILD_DLL)
if (WIN32)
	target_compile_definitions(Asteroid PUBLIC AS_PLATFORM_WINDOWS)
endif(WIN32)

set_target_properties(Asteroid
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
)

target_precompile_headers(Asteroid PUBLIC
	src/aspch.h
)
	