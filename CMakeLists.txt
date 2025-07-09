cmake_minimum_required(VERSION 3.12)
project(cpp-physics
	VERSION 0.0.0.1
	DESCRIPTION "A C++ library for physics simulations"
	LANGUAGES CXX
)
add_executable(cpp-physics_test
	src/test/main.cpp
)
