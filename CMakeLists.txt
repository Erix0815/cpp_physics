cmake_minimum_required(VERSION 3.12)
project(cpp-physics
	VERSION 0.0.0.1
	DESCRIPTION "A C++ library for physics simulations"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_PDB_OUTPUT_DIRECTORY ./pdb/)

include(CTest)

add_subdirectory(./src/lib/)
add_subdirectory(./src/test/)
add_subdirectory(./src/demo/)
