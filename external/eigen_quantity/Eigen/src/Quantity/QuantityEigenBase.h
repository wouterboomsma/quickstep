#ifndef EIGEN_QUANTITY_EIGEN_BASE_H
#define EIGEN_QUANTITY_EIGEN_BASE_H

namespace Eigen {

template<typename ExpressionType, typename Unit> class Quantity;

template<typename ExpressionType, typename Unit>
class QuantityEigenBase: public EigenBase<Quantity<ExpressionType, Unit>> {
public:

    inline ExpressionType &nested() {
        return this->derived().nestedExpression();
    }

    inline const ExpressionType &nested() const {
        return this->derived().nestedExpression();
    }

};

}

#endif