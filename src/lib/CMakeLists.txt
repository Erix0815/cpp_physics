add_library(cpp-physics_lib SHARED
	matrix/matrix.cpp
	matrix/matrix.hpp
)
target_include_directories(cpp-physics_lib PUBLIC
	matrix/
)
