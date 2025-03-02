cmake_minimum_required( VERSION 3.10 )
project( Gearhaven )
if( NOT CMAKE_BUILD_TYPE )
	set( CMAKE_BUILD_TYPE Release )
endif()
set( CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wreturn-type -pedantic" )
set( CMAKE_CXX_FLAGS_DEBUG "-g2 -DDEBUG" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )
add_executable(
	gearhaven
	main.c
	src/gearhaven.c
	src/controls.c
	src/camera.c
)
add_subdirectory(
	external/raylib
)
if( WIN32 )
	message( STATUS "Build for Windows starts.." )
	add_definitions( -DPLATFORM_WINDOWS )
	set( OS_LIBS "" )
elseif( UNIX )
	message( STATUS "Build for Linux starts.." )
	add_definitions( -DPLATFORM_LINUX )
	set( OS_LIBS m )
else()
	set( OS_LIBS "" )
endif()
target_link_libraries(
	gearhaven
	raylib
	${OS_LIBS}
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
