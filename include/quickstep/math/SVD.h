#ifndef SVD_H
#define SVD_H

#include "Matrix.h"

/**
 * @brief Computation and representation of a singular value decomposition of a matrix.
 * The pseudo-inverse and null-space projection matrices can both be extracted using this class.
 */
class SVD
{
public:

	/** Decomposes \f$M$ into \f$U*S*V^t$. */
	SVD(Matrix& M);
    ~SVD();

	/** Returns the pseudo-inverse of \f$M$, \f$M^\dagger = V*S^\dagger*U^t$ */
	Matrix* pseudoInverse();

	/** Returns the pseudo-inverse of \f$M$, \f$M^\dagger = V*S^\dagger*U^t$ using lambda
 		as a damping factor. */
	Matrix* pseudoInverse(double lambda);

	/** Returns a matrix that projects on the null-space of M. */
	Matrix* nullSpaceProjectionMatrix();

	void print();

private:
	Matrix *U, *S, *V;
};

#endif // SVD_H
