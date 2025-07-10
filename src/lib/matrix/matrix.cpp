#include "matrix.hpp"
#include <cstring>
#include <iostream>
#include <utility>

namespace cpp_physics {

Matrix::Matrix(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  this->data = new float[rows * cols];
}
Matrix::Matrix(Matrix* copy) {
  this->rows = copy->rows;
  this->cols = copy->cols;
  this->data = new float[rows * cols];
  memcpy(this->data, copy->data, rows * cols * sizeof(float));
}
Matrix::~Matrix() { delete[] data; }

float* Matrix::Element(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    std::cerr << "Index (" << row << ", " << col << ")out of bounds: (" << rows
              << ", " << cols << ")" << std::endl;
    return nullptr;
  }
  return &data[row * cols + col];
}

std::pair<int, int> Matrix::Shape() { return {rows, cols}; }

Matrix* Matrix::operator+=(Matrix* other) {
  if (this->rows != other->rows || this->cols != other->cols) {
    std::cerr << "Matrix dimensions do not match for addition." << std::endl;
    return nullptr;
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      *Element(r, c) += *other->Element(r, c);
    }
  }
  return this;
}

Matrix* Matrix::operator-=(Matrix* other) {
  if (this->rows != other->rows || this->cols != other->cols) {
    std::cerr << "Matrix dimensions do not match for subtraction." << std::endl;
    return nullptr;
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      *Element(r, c) -= *other->Element(r, c);
    }
  }
  return this;
}

Matrix* Matrix::operator*=(float scalar) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      *Element(r, c) *= scalar;
    }
  }
  return this;
}

Matrix* Matrix::operator/=(float scalar) {
  if (scalar == 0) {
    std::cerr << "Division by zero is not allowed." << std::endl;
    return nullptr;
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      *Element(r, c) /= scalar;
    }
  }
  return this;
}
} // namespace cpp_physics