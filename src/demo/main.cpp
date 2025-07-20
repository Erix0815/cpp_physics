#include "cpp-physics.hpp"
#include <iostream>

using namespace cpp_physics;

int main() {
  Matrix a = Matrix::Identity(2);
  Matrix b = Matrix::Combine({a, 2 * a});
  Matrix c = Matrix::Combine({b, 4 * b}, true);
  Matrix d = c.Submatrix(2, 4, 1, 0);
  std::cout << d << std::endl;
  return 0;
}
