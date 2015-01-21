#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/**
 * @brief Convenient wrapper for matrix data used by SVD and for multiplication.
 * The matrix data is stored in an array of doubles using column-major format which
 * is convenient for the SVD routine.
 */
class Matrix
{
public:
    /**
     * @brief Construct an mxn matrix with all 0-entries.
     * @param m The number of rows
     * @param n The number of columns
     */
    Matrix(int m, int n);

    /**
     * @brief Construct a "deep" copy of m
     * All values are copied using memcpy.
     * @param m The matrix to copy
     */
	Matrix(Matrix& m);

	~Matrix();

    /**
     * @brief Transpose the matrix in-place
     * A fast constant space method is used if the matrix is square, otherwise the straightforward m*n storage
     * approach is used.
     */
	void inplaceTranspose();

    /**
     * @brief Return the transposed of this matrix.
     * @return A new matrix corresponding to the transposed
     */
	Matrix* transpose();

    /**
     * @brief Generates a projection-matrix that projects vectors onto the subspace spanned by this matrix columns.
     */
	Matrix* toProjection();

    /**
     * @brief Matrix multiplication of this with m.
     * Uses blas dgemm and should be relatively efficient.
     */
	Matrix* multiply(Matrix* m);
	double operator () (int i, int j) { return get(i,j); }

    /**
     * @brief Get the value of the (i,j)th entry
     * @param i The row index
     * @param j The column index
     * @return A double value
     */
	double get(int i,int j) const;

    /**
     * @brief Set the value of the (i,j)th entry
     * @param i The row index
     * @param j The column index
     * @param v A double value
     */
	void set(int i,int j, double v);

    /** @brief The number of rows in this matrix. */
	unsigned int rows() const;

    /** @brief The number of columns in this matrix. */
	unsigned int cols() const;

    /**
     * @brief Get 'number' columns starting at the 'first'.
     * If 'first+number > cols()' only 'cols()-first' columns will be returned. 'first' and 'number' are assumed
     * to be positive numbers.
     * @param first The index of the first column to be chosen
     * @param number The number of columns to chose
     * @return A new matrix containing copies of the values in the specified columns
     */
	Matrix* getColumns(unsigned int first, unsigned int number);

private:
	Matrix(double*, int m, int n);
	double *data;
    int n, m;

	friend class SVD;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);
std::ostream& operator<<(std::ostream& os, const Matrix* m);


#endif // MATRIX_H
