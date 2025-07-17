#include "cpp-physics.hpp"
#include <random>
#include <vector>

using namespace cpp_physics;
using std::size_t;

std::mt19937 gen(12345678);

int test_add_sub() {
  const size_t tests = 30;
  const size_t rows = 20;
  const size_t cols = 10;
  std::uniform_real_distribution<float> dis(-10, 50);

  Matrix m1(rows, cols);
  Matrix m2(rows, cols);
  Matrix m3(rows, cols);
  Matrix sum(rows, cols);
  Matrix dif(rows, cols);

  for (size_t t = 0; t < tests; t++) {
    for (size_t r = 0; r < rows; r++) {
      for (size_t c = 0; c < cols; c++) {
        float num1 = dis(gen);
        float num2 = dis(gen);
        m1[r, c] = num1;
        m2[r, c] = num2;
        m3[r, c] = num1;
        sum[r, c] = num1 + num2;
        dif[r, c] = num1 - num2;
      }
    }
    if (m1 + m2 != sum || m2 + m1 != sum || m1 - m2 != dif || m1 + -m2 != dif) return 1;
    m1 += m2;
    m3 -= m2;
    if (m1 != sum || m3 != dif) return 1;
  }
  return 0;
}

int test_scale() {
  const size_t tests = 20;
  const size_t rows = 10;
  const size_t cols = 5;
  std::uniform_real_distribution<float> dis1(-1, 3);
  std::uniform_real_distribution<float> dis2(-10, 50);

  Matrix m1(rows, cols);
  Matrix m2(rows, cols);
  Matrix m3(rows, cols);
  Matrix m4(rows, cols);
  Matrix m5(rows, cols);
  Matrix s(rows, cols);
  Matrix c1(rows, cols);
  Matrix c2(rows, cols);

  for (size_t t = 0; t < tests; t++) {
    float scalar = dis1(gen);
    for (size_t r = 0; r < rows; r++) {
      for (size_t c = 0; c < cols; c++) {
        float num = dis2(gen);
        m1[r, c] = num;
        m2[r, c] = num;
        m3[r, c] = num;
        m4[r, c] = num;
        m5[r, c] = num;
        s[r, c] = scalar;
        c1[r, c] = num * scalar;
        c2[r, c] = num / scalar;
      }
    }
    if (Matrix::memwise_Mul(s, m1) != c1 || scalar * m1 != c1) return 1;
    if (Matrix::memwise_Mul(m1, s) != c1 || m1 * scalar != c1) return 1;
    if (Matrix::memwise_Div(m1, s) != c2 || m1 / scalar != c2) return 1;
    m1 *= scalar;
    m2 /= scalar;
    m3.memwise_iDiv(s);
    m4.memwise_iMul(s);
    s.memwise_iMul(m5);
    if (m1 != c1 || m2 != c2 || m3 != c2 || m4 != c1 || s != c1) return 1;
  }
  return 0;
}

int test_mul() {
  // TODO
  return 0;
}

int main() { return test_add_sub() || test_scale() || test_mul(); }
