#ifndef EIGEN_QUANTITY_VECTORWISE_OP_H
#define EIGEN_QUANTITY_VECTORWISE_OP_H

namespace Eigen {

template<typename ExpressionType, int Direction, typename Unit, typename QuantityType>
class VectorwiseOpBase {
public:

    /** \returns a reference to the derived object */
    QuantityType& derived() { return *static_cast<QuantityType*>(this); }

    /** \returns a const reference to the derived object */
    const QuantityType& derived() const { return *static_cast<const QuantityType*>(this); }

    inline VectorwiseOp<ExpressionType, Direction> &nested() {
        return this->derived().nestedExpression();
    }

    inline const VectorwiseOp<ExpressionType, Direction> &nested() const {
        return this->derived().nestedExpression();
    }

    inline auto
    sum() const -> Quantity<decltype(nested().sum()), Unit>{
        return nested().sum();
    }

    inline auto
    maxCoeff() const -> Quantity<decltype(nested().maxCoeff()), Unit>{
        return nested().maxCoeff();
    }

    inline auto
    minCoeff() const -> Quantity<decltype(nested().minCoeff()), Unit>{
        return nested().minCoeff();
    }

};

template<typename ExpressionType, int Direction, typename Unit>
class VectorwiseOp<Quantity<ExpressionType, Unit>, Direction>: public VectorwiseOpBase<ExpressionType, Direction, Unit, Quantity<VectorwiseOp<ExpressionType, Direction>, Unit>> {
public:

};

template<typename ExpressionType, int Direction, typename Unit>
class VectorwiseOp<const Quantity<const ExpressionType, Unit>, Direction>: public VectorwiseOpBase<const ExpressionType, Direction, Unit, const Quantity<const VectorwiseOp<const ExpressionType, Direction>, Unit>> {
public:

};

}

#endif