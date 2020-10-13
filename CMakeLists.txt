cmake_minimum_required (VERSION 3.16)


project(Asteroid)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CSS_STANDARD_REQUIRED ON)

message ("cxx Flags:" ${CMAKE_CXX_FLAGS})

set(ASTEROID_APP_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Asteroid)
add_subdirectory(AsteroidGame)