cmake_minimum_required( VERSION 3.10 )
project( Gearhaven )
add_executable(
	gearhaven
	main.c
	src/gearhaven.c
	src/controls.c
	src/camera.c
)
target_link_libraries(
	gearhaven
	raylib
	m
)
target_include_directories(
	gearhaven
	PRIVATE inc/
)
set_property(
	TARGET gearhaven
	PROPERTY C_STANDARD 99
)
include_directories(
	inc/
)
if( NOT CMAKE_BUILD_TYPE )
	set( CMAKE_BUILD_TYPE Release )
endif()
set( CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wreturn-type -pedantic" )
set( CMAKE_CXX_FLAGS_DEBUG "-g2 -DDEBUG" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )
