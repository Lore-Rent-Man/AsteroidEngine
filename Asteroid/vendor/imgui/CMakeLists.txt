add_library(ImGui STATIC
	imconfig.h
	imgui.h
	imgui.cpp
	imgui_draw.cpp
	imgui_internal.h
	imgui_widgets.cpp
	imstb_rectpack.h
	imstb_textedit.h
	imstb_truetype.h
	imgui_demo.cpp
)

target_include_directories(ImGui PUBLIC 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/imgui
)

set_target_properties(ImGui
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
)
