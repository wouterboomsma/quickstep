#ifndef EIGEN_QUANTITY_GEOMETRY_H
#define EIGEN_QUANTITY_GEOMETRY_H

#include "Eigen/Geometry"

namespace Eigen {

template<typename ExpressionType, class Unit>
class QuantityGeometry: public Quantity<ExpressionType, Unit> {
public:
    typedef Quantity<ExpressionType, Unit> Base;

    using Base::Base;
};

template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit,
         typename boost::enable_if<
                 boost::mpl::and_<
                         typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                         boost::units::detail::is_non_narrowing_conversion<typename OtherExpressionType::Scalar, typename ExpressionType::Scalar>
                 >>::type* = nullptr>
inline auto
operator*(const QuantityGeometry<ExpressionType, Unit> &lhs, const Quantity<OtherExpressionType, OtherUnit> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.value()), Unit> {
    return lhs.value()*rhs.value();
}

template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit,
         typename boost::enable_if<
                 boost::mpl::and_<
                         typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                         boost::units::detail::is_non_narrowing_conversion<typename OtherExpressionType::Scalar, typename ExpressionType::Scalar>
                         >>::type* = nullptr>
inline auto
operator*(const Quantity<OtherExpressionType, OtherUnit> &lhs, const QuantityGeometry<ExpressionType, Unit> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.value()), OtherUnit> {
    return lhs.value()*rhs.value();
}

template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit,
         typename boost::enable_if<
                 boost::mpl::and_<
                         typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                         boost::units::detail::is_non_narrowing_conversion<typename OtherExpressionType::Scalar, typename ExpressionType::Scalar>
                         >>::type* = nullptr>
inline auto
operator*(const QuantityGeometry<ExpressionType, Unit> &lhs, const QuantityGeometry<OtherExpressionType, OtherUnit> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.value()), Unit> {
    return lhs.value()*rhs.value();
}



}

#endif // EIGEN_QUANTITY_GEOMETRY_H
