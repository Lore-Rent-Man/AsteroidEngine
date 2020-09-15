add_executable(
	AsteroidGame
	src/sandbox.cpp
)

target_include_directories(AsteroidGame PUBLIC ${ASTEROID_APP_ROOT}/Asteroid/src)

target_compile_definitions(AsteroidGame PUBLIC AS_PLATFORM_WINDOWS)

target_link_libraries(AsteroidGame PRIVATE Asteroid)

set_target_properties(AsteroidGame
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/AsteroidGame/${CMAKE_BUILD_TYPE}
	LIBRARY_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/AsteroidGame/${CMAKE_BUILD_TYPE}
	RUNTIME_OUTPUT_DIRECTORY ${ASTEROID_APP_ROOT}/bin/AsteroidGame/${CMAKE_BUILD_TYPE}
)

add_custom_command(TARGET AsteroidGame POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${ASTEROID_APP_ROOT}/bin/Asteroid/$<CONFIGURATION>/Asteroid.dll"
	$<TARGET_FILE_DIR:AsteroidGame>)