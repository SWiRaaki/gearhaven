cmake_minimum_required(VERSION 3.10)
project(Gearhaven)
add_executable(
	Gearhaven
	main.c
)
target_link_libraries(
	Gearhaven
	raylib
	m
)
set_property(TARGET Gearhaven PROPERTY C_STANDARD 99)
