#include "SVD.h"

#include <algorithm> // min
#include <iostream>
//#include <lapacke.h>

/* DGESVD prototype */
extern "C" void dgesvd( char* jobu, char* jobvt, int* m, int* n, double* a,
                int* lda, double* s, double* u, int* ldu, double* vt, int* ldvt,
                double* work, int* lwork, int* info );

using namespace std;

//Decompose A into USV^t and store U, S and V
SVD::SVD(Matrix& A){
	int m = A.rows();
	int n = A.cols();
	int o = min(m,n);

    double* a = new double[m*n];
    memcpy(a,A.data, m*n*sizeof(double));
	double* u = new double[m*m];
	double* s = new double[o];
	double* vt = new double[n*n];

    char jobu = 'A';
    char jobvt = 'A';
	int info = 0;
	double wkopt;
	int lwrk = -1;
	dgesvd( &jobu,&jobvt, &m, &n, a, &m, s, u, &m, vt, &n, &wkopt, &lwrk, &info);
	lwrk = (int)wkopt;
	double *wrk = new double[lwrk];
	dgesvd( &jobu, &jobvt, &m, &n, a, &m, s, u, &m, vt, &n, wrk, &lwrk, &info);

    if(info<0){
        cerr<<"SVD failed to converge"<<endl;
        exit(-1);
    }

    this->U = new Matrix(u,m,m);
    this->V = new Matrix(vt,n,n);
    this->V->inplaceTranspose();
    this->S = new Matrix(m,n);
    for(int i=0;i<o;i++){
        S->set(i,i,s[i]);
    }
    delete[] s;
    delete[] wrk;

}

SVD::~SVD(){
	delete U;
	delete S;
	delete V;
}



Matrix* SVD::nullSpaceProjectionMatrix(){
	int sz = min(S->rows(), S->cols());

	int nullSpaceSize = 0;
	double maxSVal = S->get(0,0);
	if(maxSVal<0.0001)
		nullSpaceSize = sz;
	else{
		for(int i=sz-1; i>=0; --i){
			if(  (S->get(i,i)/maxSVal)>0.000001  )	break;
			nullSpaceSize++;
		}
	}

    //cout<<nullSpaceSize<<endl;
	Matrix* N = V->getColumns(V->cols()-nullSpaceSize, nullSpaceSize);
    //cout<<"N"<<endl<<N<<endl;
	//Matrix* nullSpaceBasis_t = nullSpaceBasis->transpose();
	//Matrix* ret = nullSpaceBasis->multiply(nullSpaceBasis_t);
	Matrix* ret = N->toProjection();
	delete N;
	//delete nullSpaceBasis_t;
	return ret;
}

Matrix* SVD::pseudoInverse(){
	//Matrix* S_dag = new Matrix(S->cols(), S->rows());
	//int Sz = min(S->rows(), S->cols());
	//for(int i=0;i<Sz;i++){
	//	double val = S->get(i,i);
	//	if(val>0.0001) S_dag->set(i,i, 1/val);
	//}
	//Matrix* U_t = U->transpose();
	//Matrix* prod1 = V->multiply(S_dag);
	//Matrix* prod2 = prod1->multiply(U_t);

	//delete S_dag;
	//delete U_t;
	//delete prod1;

	//return prod2;
    return NULL;
}

Matrix* SVD::pseudoInverse(double lambda){
	//Matrix* S_dag = new Matrix(S->cols(), S->rows());
	//int Sz = min(S->rows(), S->cols());
	//for(int i=0;i<Sz;i++){
	//	double val = S->get(i,i);
	//	if(val>0.0001) S_dag->set(i,i, val/(val*val+lambda*lambda));
	//}
	//Matrix* U_t = U->transpose();
	//Matrix* prod1 = V->multiply(S_dag);
	//Matrix* prod2 = prod1->multiply(U_t);

	//delete S_dag;
	//delete U_t;
	//delete prod1;

	//return prod2;
    return NULL;
}

void SVD::print(){
	cout<<"U:"<<endl;
	cout<<U<<endl;
	cout<<"S:"<<endl;
	cout<<S<<endl;
	cout<<"V:"<<endl;
	cout<<V<<endl;
}
