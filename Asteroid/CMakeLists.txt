add_library(
	Asteroid SHARED
	src/Asteroid.h
	src/Asteroid/Application.h
	src/Asteroid/Application.cpp
	src/Asteroid/Core.h
	src/Asteroid/EntryPoint.h
	src/Asteroid/Layer.h
	src/Asteroid/Layer.cpp
	src/Asteroid/LayerStack.h
	src/Asteroid/LayerStack.cpp
	src/Asteroid/Log.cpp
	src/Asteroid/Log.h
	src/Asteroid/Window.h
	src/Asteroid/Events/Event.h
	src/Asteroid/Events/KeyEvent.h
	src/Asteroid/Events/ApplicationEvent.h
	src/Asteroid/Events/MouseEvent.h
	src/Asteroid/ImGui/ImGuiLayer.h
	src/Asteroid/ImGui/ImGuiLayer.cpp
	src/Asteroid/Platform/OpenGL/ImGuiOpenGLRenderer.h
	src/Asteroid/Platform/OpenGL/ImGuiOpenGLRenderer.cpp
	src/Asteroid/Platform/Window/WindowsWindow.h
	src/Asteroid/Platform/Window/WindowsWindow.cpp
)

target_include_directories(Asteroid PUBLIC 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/include/
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

add_subdirectory(vendor)

target_link_libraries(Asteroid PUBLIC
	${ASTEROID_APP_ROOT}/Asteroid/vendor/lib/glfw3.lib
	glad
	ImGui
)
	