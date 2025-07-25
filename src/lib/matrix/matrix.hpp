#ifndef matrix_hpp
#define matrix_hpp

#include <functional>
#include <sstream>

namespace cpp_physics {

const std::out_of_range OOB = std::out_of_range("Row or column index out of bounds.");
const std::out_of_range SUBMAT_OOB = std::out_of_range("Submatrix exceeds bounds of original matrix.");
const std::invalid_argument SHAPE_MISMATCH = std::invalid_argument("Matrix-shapes don't match.");
const std::invalid_argument INNERDIM_MISMATCH = std::invalid_argument("Inner matrix-dimensions don't align.");
const std::invalid_argument DIM_MISMATCH = std::invalid_argument("Matrix-columns or -rows don't match.");
const std::invalid_argument TOO_FEW = std::invalid_argument("Too few matrices, minimum 1.");
const std::invalid_argument DIV_ZERO = std::invalid_argument("Division by 0.");

class Matrix {
private:
  std::vector<float> data;
  std::size_t rows;
  std::size_t cols;

public:
  /**
   * @brief Constructs a Matrix with the specified number of rows and columns.
   * @param rows The number of rows in the matrix.
   * @param cols The number of columns in the matrix. Defaults to 1.
   */
  Matrix(std::size_t rows, std::size_t cols = 1);

  /**
   * @brief Creates a new identity-matrix
   * @param size Amount o frows and columns in the Matrix
   * @return The new identity-matrix
   */
  static Matrix Identity(std::size_t size);

  /**
   * @brief return the shape of the matrix as a tuple of (rows, cols).
   * @return A tuple containing the number of rows and columns in the matrix.
   */
  std::pair<std::size_t, std::size_t> Shape() const;

  /**
   * @brief Retrieves a value from the matrix at the specified row and column.
   * @param row The row index from which to retrieve the value.
   * @param col The column index from which to retrieve the value.
   * @return The value at the specified row and column.
   */
  float Get(std::size_t row, std::size_t col) const;

  /**
   * @brief Apply a function to all elements of the matrix.
   * @param func A function that takes a float as Argument and return a float.
   */
  void applyFunction(std::function<float(float)> func);

  /**
   * @brief Extract a submatrix from the matrix.
   * @param rows Amount of rows in the submatrix.
   * @param cols Amount of columns in the submatrix.
   * @param row_start The starting row index for the submatrix.
   * @param col_start The starting column index for the submatrix.
   * @return A new submatrix.
   */
  Matrix Submatrix(std::size_t rows, std::size_t cols, std::size_t row_start, std::size_t col_start) const;

  /**
   * @brief Combine multiple matrices into a new matrix.
   * @param matrices A vector containing the matrices to combine.
   * @param vertical Align the matrices horizontally or vertically. Defaults to false, for horizontal.
   * @return A new Matrix containing copies of all the other matrices.
   */
  static Matrix Combine(std::vector<Matrix> matrices, bool vertical = false);

  /**
   * @brief Sum all elements in the matrix.
   * @return The sum of all elements.
   */
  float Sum() const;

  /**
   * @brief Memberwise-multiply two matrices.
   * @param lhs The multiplicand.
   * @param rhs The multiplier.
   * @return A new matrix containing the result.
   */
  static Matrix memwise_Mul(const Matrix& lhs, const Matrix& rhs);

  /**
   * @brief Memberwise-multiply a matrix to this one.
   * @param other The multiplier.
   */
  Matrix memwise_iMul(const Matrix& other);

  /**
   * @brief Memberwise-divide two matrices.
   * @param lhs The dividend.
   * @param rhs The divisor.
   * @return A new matrix containing the result.
   */
  static Matrix memwise_Div(const Matrix& lhs, const Matrix& rhs);

  /**
   * @brief Memberwise-divide this matrix by anoter one.
   * @param other The divisor.
   */
  Matrix memwise_iDiv(const Matrix& other);

  /**
   * @brief Add another matrix to this one.
   * @param other The matrix to add.
   */
  Matrix operator+=(const Matrix& other);
  /**
   * @brief Add two matrices.
   * @param other The addend.
   * @return A new matrix containing the result.
   */
  Matrix operator+(const Matrix& other) const;
  /**
   * @brief Subtract another matrix from this one.
   * @param other The matrix to subtract.
   */
  Matrix operator-=(const Matrix& other);
  /**
   * @brief Subtract two matrices.
   * @param other The subtrahend.
   * @return A new matrix containing the result.
   */
  Matrix operator-(const Matrix& other) const;
  /**
   * @brief Multiply another matrix to this one.
   * @param other The matrix to multiply with.
   */
  Matrix operator*=(const Matrix& other);
  /**
   * @brief Multiply two matrices.
   * @param other The multiplier.
   * @return A new matrix containing the result.
   */
  Matrix operator*(const Matrix& other) const;
  /**
   * @brief Scale this matrix.
   * @param scalar The factor to scale the matrix by.
   */
  Matrix operator*=(float scalar);
  /**
   * @brief Scale a matrix.
   * @param scalar The scalar to scale by.
   * @return A new matrix containing the result.
   */
  Matrix operator*(float scalar) const;
  /**
   * @brief Divide this matrix by a scalar.
   * @param scalar The factor to divide the matrix by.
   */
  Matrix operator/=(float scalar);
  /**
   * @brief Divide a matrix by a scalar.
   * @param scalar The scalar to divide by.
   * @return A new matrix containing the result.
   */
  Matrix operator/(float scalar) const;

  /**
   * @brief Copy this matrix.
   * @param other The matrix to copy.
   * @return A copy of the other matrix.
   */
  Matrix operator=(const Matrix& other);

  /**
   * @brief Negate this matrix.
   * @return A new negated matrix.
   */
  Matrix operator-() const;
  /**
   * @brief Transpose this matrix.
   * @return A new transposed matrix.
   */
  Matrix operator!() const;

  /**
   * @brief Access values inside the matrix.
   * @param row The row of the value to access.
   * @param col The row of the value to access.
   * @return A reference to the specified value.
   */
  float& operator[](std::size_t row, std::size_t col);

  /**
   * @brief Check if this matrices is equal to another matrix.
   * @param other The matrix to compare to.
   * @return true, if the matrices are equal.
   */
  bool operator==(const Matrix& other);
  /**
   * @brief Check if this matrices is different from another matrix.
   * @param other The matrix to compare to.
   * @return true, if the matrices are different.
   */
  bool operator!=(const Matrix& other);
};

/**
 * @brief Scale a matrix.
 * @param scalar The scalar to scale by.
 * @param mat The matrix to scale.
 * @return A new matrix containing the result.
 */
Matrix operator*(float scalar, const Matrix& mat);

/**
 * @brief Print a matrix.
 * @param flux cout-voodoo
 * @param mat The matrix to print.
 * @return cout-voodoo
 */
std::ostream& operator<<(std::ostream& flux, const Matrix& mat);

} // namespace cpp_physics

#endif
