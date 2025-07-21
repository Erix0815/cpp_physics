# src/lib/matrix
add_executable(matrix_unittest matrix_test.cpp)
target_link_libraries(matrix_unittest PUBLIC cpp-physics)
add_test(NAME MatrixAlgebra COMMAND matrix_unittest)
