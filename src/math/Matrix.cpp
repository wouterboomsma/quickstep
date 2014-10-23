#include "Matrix.h"

#include <algorithm>
#include <assert.h>
#include <new>

extern "C" void cblas_dgemm (char Order, char TransA, char TransB, int M, int N, int K, double alpha, double *A, int lda, double *B, int ldb, double beta, double *C, int ldc);

Matrix::Matrix(int _m, int _n): data(new double[_m*_n]), m(_m), n(_n)
{
    memset(data, 0, m*n);
}

Matrix::Matrix(double* newData, int _m, int _n): data(newData), m(_m), n(_n)
{}
Matrix::Matrix(Matrix& M): data(new double[M.m*M.n]), m(M.m), n(M.n)
{
    memcpy( data, M.data, m*n*sizeof(double) );
}

Matrix::~Matrix(){
	delete[] data;
}

unsigned int Matrix::rows() const { return m; }
unsigned int Matrix::cols() const { return n; }
double Matrix::get(int i,int j) const{
    assert ( i>=0 );
    assert ( i<m );
    assert ( j>=0 );
    assert ( j<n );
    return data[j*m+i];
}

void Matrix::set(int i,int j, double v){
    assert ( i>=0 );
    assert ( i<m );
    assert ( j>=0 );
    assert ( j<n );
    data[j*m+i] = v;
}


Matrix* Matrix::getColumns(unsigned int first, unsigned int number){
	unsigned int maxCol = n<first+number?n:first+number;
    Matrix* ret = new Matrix(m, maxCol-first);
    memcpy( ret->data, data+(first*m), (ret->m*ret->n)*sizeof(double) );
    //TODO: Check
	//for(unsigned int i=0;i<data->size1; i++){
	//	for(unsigned int j=first;j<maxCol; j++){
	//		ret->set(i,j-first, get(i,j));
	//	}
	//}
	return ret;
}

void Matrix::inplaceTranspose(){
    if(m==n){
        int i,j;
        double tmp;
        for(i=0;i<m;i++){
            for(j=i+1;j<n;j++){
				tmp = data[j*m+i];
                data[j*m+i] = data[i*m+j];
                data[i*m+j] = tmp;
            }
        }
    }else{
        //Not in-place .. might be slow compared to std libraries
        double* newData = new double[m*n];
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                newData[i*n+j] = data[j*m+i];
            }
        }
		delete[] data;
        data = newData;

        int tmp = n;
        n = m;
        m = tmp;
    }
}

Matrix* Matrix::transpose(){
    Matrix* ret = new Matrix(*this);
    ret->inplaceTranspose();
    return ret;
}

Matrix* Matrix::toProjection(){
	//Matrix* ret = new Matrix(m,m);
	//char order = (char)102; //Row-major
	////TODO: Optimize by having a transpose flag in matrix that inplaceTranspose just flips and which is used here
	//char transA = (char)111; //No transpose
	//char transB = (char)112; //Transpose
	//cblas_dgemm(order, transA, transB, m, n, n, 1.0, data, m, data, m, 0.0, ret->data, m);
	//return ret;
    //TODO optimize
	Matrix* trans = transpose();
	Matrix* ret = multiply(trans);
	delete trans;
	return ret;
}

Matrix* Matrix::multiply(Matrix* A){
    if(n!=A->m){
        cerr<<"Matrix::multiply! Matrix dimensions don't support a multiplication ("<<m<<"x"<<n<<")·("<<A->m<<"x"<<A->n<<")"<<endl;
        exit(-1);
    }
    Matrix* ret = new Matrix(m,A->n);
    char order = (char)102; //Row-major
    //TODO: Optimize by having a transpose flag in matrix that inplaceTranspose just flips and which is used here
    char transA = (char)111; //No transpose
    char transB = (char)111; //No transpose
	cblas_dgemm(order, transA, transB, m, A->n, n, 1.0, data, m, A->data, n, 0.0, ret->data, m);

    return ret;
}


ostream& operator<<(ostream& os, const Matrix& m){
	for (unsigned int i=0; i<m.rows(); ++i) {
		for (unsigned int j=0; j<m.cols(); ++j){
            os << m.get(i,j);
			if(j == (m.cols()-1))
                os << endl;
			else
                os << '\t';
		}
	}
	return os;
}

ostream& operator<<(ostream& os, const Matrix* m){
	return os<<(*m);
}
