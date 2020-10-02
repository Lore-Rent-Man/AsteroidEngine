add_library(
	Asteroid SHARED
	src/Asteroid.h
	src/Asteroid/Application.cpp
	src/Asteroid/Application.h
	src/Asteroid/Core.h
	src/Asteroid/EntryPoint.h
	src/Asteroid/Log.cpp
	src/Asteroid/Log.h
	src/Asteroid/Layer.h
	src/Asteroid/Layer.cpp
	src/Asteroid/LayerStack.h
	src/Asteroid/LayerStack.cpp
	src/Asteroid/Window.h
	src/Asteroid/Events/Event.h
	src/Asteroid/Events/KeyEvent.h
	src/Asteroid/Events/ApplicationEvent.h
	src/Asteroid/Events/MouseEvent.h
	src/Asteroid/Window/WindowsWindow.h
	src/Asteroid/Window/WindowsWindow.cpp
)

target_include_directories(Asteroid PUBLIC 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/include
	${ASTEROID_APP_ROOT}/Asteroid/src
)

target_compile_definitions(Asteroid PUBLIC AS_BUILD_DLL AS_ENABLE_ASSERTS)
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

add_library(glad 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/lib/glad.c
)

target_include_directories(glad PUBLIC 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/include
)

set_target_properties(glad
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
)

target_link_libraries(Asteroid PUBLIC
	${ASTEROID_APP_ROOT}/Asteroid/vendor/lib/glfw3.lib
	glad
)
	