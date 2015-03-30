#ifndef EIGEN_QUANTITY_GEOMETRY_BASE_H
#define EIGEN_QUANTITY_GEOMETRY_BASE_H

#include "Eigen/Geometry"

namespace Eigen {

template<typename ExpressionType, typename Unit>
class QuantityGeometryTransformBase {
public:

    typedef typename ExpressionType::Scalar Scalar;
    typedef Quantity<ExpressionType, Unit> QuantityType;

    /** \returns a reference to the derived object */
    inline QuantityType& derived() { return *static_cast<QuantityType*>(this); }

    /** \returns a const reference to the derived object */
    inline const QuantityType& derived() const { return *static_cast<const QuantityType*>(this); }

    inline ExpressionType &nested() {
        return const_cast<ExpressionType&>(static_cast<const QuantityType&>(this->derived()).nestedExpression());
    }

    inline const ExpressionType &nested() const {
        return this->derived().nestedExpression();
    }

//    static_assert(internal::DependentBool<false, ExpressionType>(), "hello");
};

template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit,
         typename boost::enable_if<
                 boost::mpl::and_<
                         typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                         boost::units::detail::is_non_narrowing_conversion<typename Quantity<ExpressionType, Unit>::Scalar, typename Quantity<OtherExpressionType, OtherUnit>::Scalar>
                         >>::type* = nullptr>
inline auto
operator*(const QuantityGeometryTransformBase<ExpressionType, Unit> &lhs, const QuantityGeometryTransformBase<OtherExpressionType, OtherUnit> &rhs)
-> Quantity<decltype(lhs.nested()*rhs.nested()),
            Unit>{     // Note: no unit multiplication here (transforms maintain their unit)
    return lhs.nested()*rhs.nested();
}

template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit,
         typename boost::enable_if<
                 boost::mpl::and_<
                         typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                         boost::units::detail::is_non_narrowing_conversion<typename Quantity<ExpressionType, Unit>::Scalar, typename Quantity<OtherExpressionType, OtherUnit>::Scalar>
                         >>::type* = nullptr>
inline auto
operator*(const QuantityGeometryTransformBase<ExpressionType, Unit> &lhs, const Quantity<OtherExpressionType, OtherUnit> &rhs)
-> Quantity<decltype(lhs.nested()*rhs.nested()),
            Unit>{     // Note: no unit multiplication here (transforms maintain their unit)
    return lhs.nested()*rhs.nested();
}

}

#endif // EIGEN_QUANTITY_GEOMETRY_BASE
