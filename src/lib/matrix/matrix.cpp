#include "matrix.hpp"
#include <iostream>

using namespace cpp_physics;

Matrix::Matrix(int rows, int cols) {
  std::cout << "Matrix created with " << rows << " rows and " << cols
            << " columns." << std::endl;
}
Matrix::~Matrix() { std::cout << "Matrix destroyed." << std::endl; }
