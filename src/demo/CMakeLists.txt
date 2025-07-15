add_executable(cpp-physics_demo main.cpp)
target_link_libraries(cpp-physics_demo PUBLIC cpp-physics_lib)
target_include_directories(cpp-physics_demo PUBLIC ../lib/)
