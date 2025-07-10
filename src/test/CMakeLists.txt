add_executable(cpp-physics_test
	main.cpp
)
target_link_libraries(cpp-physics_test PUBLIC
	cpp-physics_lib
)
target_include_directories(cpp-physics_test PUBLIC
	../lib/
)
