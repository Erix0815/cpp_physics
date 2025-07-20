#include "matrix.hpp"

const std::out_of_range OOB = std::out_of_range("Row or column index out of bounds.");
const std::out_of_range SUBMAT_OOB = std::out_of_range("Submatrix exceeds bounds of original matrix.");
const std::invalid_argument SHAPE_MISMATCH = std::invalid_argument("Matrix-shapes don't match.");
const std::invalid_argument INNERDIM_MISMATCH = std::invalid_argument("Inner matrix-dimensions don't align.");
const std::invalid_argument DIM_MISMATCH = std::invalid_argument("Matrix-columns or -rows don't match.");
const std::invalid_argument TOO_FEW = std::invalid_argument("Too few matrices, minimum 1");

namespace cpp_physics {

Matrix::Matrix(std::size_t rows, std::size_t cols) : rows(rows), cols(cols) { this->data = std::vector<float>(rows * cols, 0.0f); }

Matrix Matrix::Identity(std::size_t size) {
  Matrix result(size, size);
  for (std::size_t i = 0; i < size; i++) result[i, i] = 1;
  return result;
}

std::ostream& operator<<(std::ostream& flux, const Matrix& mat) {
  std::size_t rows = mat.Shape().first;
  std::size_t cols = mat.Shape().second;
  std::vector<std::size_t> maxLength(cols, 0);
  std::stringstream ss;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      ss << mat.Get(r, c);
      if (maxLength[c] < ss.str().size()) maxLength[c] = ss.str().size();
      ss.str(std::string());
    }
  }
  for (int r = 0; r < rows; r++) {
    if (r != 0) flux << "\n";
    for (int c = 0; c < cols; c++) {
      flux << mat.Get(r, c);
      ss << mat.Get(r, c);
      for (int k = 0; k < maxLength[c] - ss.str().size() + 1; k++) flux << " ";
      ss.str(std::string());
    }
  }
  return flux;
}

std::pair<std::size_t, std::size_t> Matrix::Shape() const { return {this->rows, this->cols}; }

float Matrix::Get(std::size_t row, std::size_t col) const {
  if (row >= rows || col >= cols) throw OOB;
  return data[row * cols + col];
}

void Matrix::applyFunction(std::function<float(float)> func) {
  for (float& f : data) f = func(f);
}

Matrix Matrix::Submatrix(std::size_t num_rows, std::size_t num_cols, std::size_t row_start, std::size_t col_start) const {
  if (row_start + num_rows > rows || col_start + num_cols > cols) throw SUBMAT_OOB;
  Matrix result(num_rows, num_cols);
  for (std::size_t r = 0; r < num_rows; r++) {
    for (std::size_t c = 0; c < num_cols; c++) {
      result[r, c] = Get(row_start + r, col_start + c);
    }
  }
  return result;
}

Matrix Matrix::Combine(std::vector<Matrix> matrices, bool vertical) {
  if (matrices.size() == 0) throw TOO_FEW;
  std::size_t rows = matrices[0].rows;
  std::size_t cols = matrices[0].cols;
  std::vector<std::size_t> breakpoints(matrices.size(), 0);

  for (std::size_t i = 1; i < matrices.size(); i++) {
    if (vertical && cols != matrices[i].cols || !vertical && rows != matrices[i].rows) throw DIM_MISMATCH;
    if (vertical) {
      breakpoints[i] = rows;
      rows += matrices[i].rows;
    } else {
      breakpoints[i] = cols;
      cols += matrices[i].cols;
    }
  }

  Matrix result(rows, cols);
  for (std::size_t i = 0; i < matrices.size(); i++) {
    std::size_t r_offset = 0;
    std::size_t c_offset = 0;

    if (vertical)
      r_offset = breakpoints[i];
    else
      c_offset = breakpoints[i];

    for (std::size_t r = 0; r < matrices[i].rows; r++) {
      for (std::size_t c = 0; c < matrices[i].cols; c++) {
        result[r_offset + r, c_offset + c] = matrices[i][r, c];
      }
    }
  }

  return result;
}

Matrix Matrix::memwise_Mul(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) throw SHAPE_MISMATCH;
  Matrix result(lhs.rows, lhs.cols);
  for (std::size_t i = 0; i < lhs.data.size(); i++) result.data[i] = lhs.data[i] * rhs.data[i];
  return result;
}

Matrix Matrix::memwise_iMul(const Matrix& other) {
  if (rows != other.rows || cols != other.cols) throw SHAPE_MISMATCH;
  for (std::size_t i = 0; i < data.size(); i++) data[i] *= other.data[i];
  return *this;
}

Matrix Matrix::memwise_Div(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) throw SHAPE_MISMATCH;
  Matrix result(lhs.rows, lhs.cols);
  for (std::size_t i = 0; i < lhs.data.size(); i++) result.data[i] = lhs.data[i] / rhs.data[i];
  return result;
}

Matrix Matrix::memwise_iDiv(const Matrix& other) {
  if (rows != other.rows || cols != other.cols) throw SHAPE_MISMATCH;
  for (std::size_t i = 0; i < data.size(); i++) data[i] /= other.data[i];
  return *this;
}

Matrix Matrix::operator+=(const Matrix& other) {
  if (rows != other.rows || cols != other.cols) throw SHAPE_MISMATCH;
  for (std::size_t i = 0; i < data.size(); i++) data[i] += other.data[i];
  return *this;
}
Matrix Matrix::operator+(const Matrix& other) const {
  if (rows != other.rows || cols != other.cols) throw SHAPE_MISMATCH;
  Matrix result(rows, cols);
  for (std::size_t i = 0; i < data.size(); i++) result.data[i] = data[i] + other.data[i];
  return result;
}

Matrix Matrix::operator-=(const Matrix& other) {
  if (rows != other.rows || cols != other.cols) throw SHAPE_MISMATCH;
  for (std::size_t i = 0; i < data.size(); i++) data[i] -= other.data[i];
  return *this;
}
Matrix Matrix::operator-(const Matrix& other) const {
  if (rows != other.rows || cols != other.cols) throw SHAPE_MISMATCH;
  Matrix result(rows, cols);
  for (std::size_t i = 0; i < data.size(); i++) result.data[i] = data[i] - other.data[i];
  return result;
}

Matrix Matrix::operator*=(const Matrix& other) {
  if (cols != other.rows) throw INNERDIM_MISMATCH;
  return *this * other;
}

Matrix Matrix::operator*(const Matrix& other) const {
  if (cols != other.rows) throw INNERDIM_MISMATCH;
  Matrix result(rows, other.cols);
  for (std::size_t r = 0; r < rows; r++) {
    for (std::size_t c = 0; c < other.cols; c++) {
      float sum = 0;
      for (std::size_t k = 0; k < cols; k++) {
        sum += Get(r, k) * other.Get(k, c);
      }
      result[r, c] = sum;
    }
  }
  return result;
}

Matrix Matrix::operator*=(float scalar) {
  applyFunction([scalar](float x) { return x * scalar; });
  return *this;
}

Matrix Matrix::operator*(float scalar) const {
  Matrix result(rows, cols);
  for (std::size_t i = 0; i < data.size(); i++) result.data[i] = data[i] * scalar;
  return result;
}

Matrix Matrix::operator/=(float scalar) {
  applyFunction([scalar](float x) { return x / scalar; });
  return *this;
}

Matrix Matrix::operator/(float scalar) const {
  Matrix result(rows, cols);
  for (std::size_t i = 0; i < data.size(); i++) result.data[i] = data[i] / scalar;
  return result;
}

Matrix Matrix::operator=(const Matrix& other) {
  Matrix result(other.rows, other.cols);
  result.data = other.data;
  return result;
}

Matrix Matrix::operator-() const {
  Matrix result(rows, cols);
  for (std::size_t i = 0; i < result.data.size(); i++) result.data[i] = -data[i];
  return result;
}

Matrix Matrix::operator!() const {
  Matrix result(cols, rows);
  for (std::size_t r = 0; r < rows; r++) {
    for (std::size_t c = 0; c < cols; c++) {
      result[c, r] = Get(r, c);
    }
  }
  return result;
}

float& Matrix::operator[](std::size_t row, std::size_t col) {
  if (row >= this->rows || col >= this->cols) throw OOB;
  return this->data[row * this->cols + col];
}

bool Matrix::operator==(const Matrix& other) {
  if (rows != other.rows || cols != other.cols) return false;
  return data == other.data;
}

bool Matrix::operator!=(const Matrix& other) {
  if (rows != other.rows || cols != other.cols) return true;
  return data != other.data;
}

} // namespace cpp_physics
