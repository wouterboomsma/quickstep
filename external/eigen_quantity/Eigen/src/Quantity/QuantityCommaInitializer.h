#ifndef EIGEN_QUANTITY_COMMA_INITIALIZER_H
#define EIGEN_QUANTITY_COMMA_INITIALIZER_H

namespace Eigen {

template<typename ExpressionType, typename Unit>
class CommaInitializer<Quantity<ExpressionType, Unit>> {
public:
    typedef typename ExpressionType::Scalar Scalar;
    typedef Quantity<CommaInitializer<ExpressionType>, Unit> QuantityType;

    /** \returns a reference to the derived object */
    inline QuantityType& derived() { return *static_cast<QuantityType*>(this); }

    /** \returns a const reference to the derived object */
    inline const QuantityType& derived() const { return *static_cast<const QuantityType*>(this); }

    inline CommaInitializer<ExpressionType> &nested() {
        return const_cast<CommaInitializer<ExpressionType>&>(static_cast<const QuantityType&>(this->derived()).nestedExpression());
    }

    inline const CommaInitializer<ExpressionType> &nested() const {
        return this->derived().nestedExpression();
    }

    CommaInitializer& operator,(const boost::units::quantity<Unit> &s) {
        this->nested().operator,(s.value());
        return *this;
    }

    template <typename OtherDerived>
    CommaInitializer& operator,(const DenseBase<Quantity<OtherDerived, Unit>> &other) {
        this->nested().operator,(other.nested());
        return *this;
    }

    inline Quantity<ExpressionType, Unit> finished() {
        return this->nested().finished();
    }
};

}

#endif

