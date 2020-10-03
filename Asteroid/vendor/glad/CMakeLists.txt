add_library(glad STATIC
	glad.c
)

target_include_directories(glad PUBLIC 
	${ASTEROID_APP_ROOT}/Asteroid/vendor/glad
	${ASTEROID_APP_ROOT}/Asteroid/vendor
)

set_target_properties(glad
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/Asteroid/${CMAKE_BUILD_TYPE}
)