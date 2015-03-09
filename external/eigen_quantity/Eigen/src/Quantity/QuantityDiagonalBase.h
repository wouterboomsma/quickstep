#ifndef EIGEN_QUANTITY_DIAGONAL_BASE_H
#define EIGEN_QUANTITY_DIAGONAL_BASE_H

namespace Eigen {

template<typename ExpressionType, typename Unit>
class DiagonalBase<Quantity<ExpressionType, Unit>>: public QuantityEigenBase<ExpressionType, Unit> {
public:
    typedef QuantityEigenBase<ExpressionType, Unit> Base;

    int RowsAtCompileTime = internal::traits<ExpressionType>::DiagonalVectorType::RowsAtCompileTime;
    int ColsAtCompileTime = internal::traits<ExpressionType>::DiagonalVectorType::ColsAtCompileTime;

};

}

#endif