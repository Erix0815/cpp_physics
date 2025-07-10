#ifndef matrix_hpp
#define matrix_hpp

#include <utility>

namespace cpp_physics {

	class Matrix {
	private:
		int rows;
		int cols;
		float* data;

	public:
		/**
		 * @brief Constructs a Matrix with the specified number of rows and columns.
		 * @param rows The number of rows in the matrix.
		 * @param cols The number of columns in the matrix. Defaults to 1 (column-vector).
		 */
		Matrix(int rows, int cols = 1);
		/**
		 * @brief Constructs a Matrix by copying another Matrix.
		 * @param copy A pointer to the Matrix to copy from.
		 */
		Matrix(Matrix* copy);
		/**
		 * @brief Destroys the Matrix and releases allocated memory.
		 */
		~Matrix();
		/**
		 * @brief Reference an element in the matrix.
		 * @param row The row index of the element.
		 * @param col The column index of the element.
		 * @return A pointer to the element at the specified row and column.
		*/
		float* Element(int row, int col);

		/**
		 * @brief Returns the shape of the matrix as a tuple of (rows, cols).
		 * @return A tuple containing the number of rows and columns in the matrix.
		 */
		std::pair<int, int> Shape();

		/**
		 * @brief Add another Matrix to this one.
		 * @param other The Matrix to add.
		 */
		Matrix* operator+=(Matrix* other);

		/**
		 * @brief Subtract another Matrix from this one.
		 * @param other The Matrix to subtract.
		 */
		Matrix* operator-=(Matrix* other);

		/**
		 * @brief Multiply this Matrix by a scalar value.
		 * @param scalar The scalar value to multiply by.
		 */
		Matrix* operator*=(float scalar);

		/**
		 * @brief Divide this Matrix by a scalar value.
		 * @param scalar The scalar value to divide by.
		 */
		Matrix* operator/=(float scalar);
	};
}

#endif
