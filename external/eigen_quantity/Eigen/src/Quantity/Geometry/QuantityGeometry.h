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

// Transformations multiplied with each other maintain the same unit
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

// Transformations multiplied with each other maintain the same unit
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

// Transformations multiplied with each other maintain the same unit
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

// Multiplying with a unit changes the unit
template<typename ExpressionType, typename Unit, class Dim, class System,
         typename boost::enable_if<typename boost::units::is_implicitly_convertible<boost::units::unit<Dim, System>,Unit>>::type* = nullptr>
inline auto
operator*(const QuantityGeometry<ExpressionType, Unit> &lhs, const boost::units::unit<Dim, System> &rhs)
-> const Quantity<decltype(lhs.value()), decltype(Unit()*boost::units::unit<Dim, System>())> {
    return lhs.value();
}

// Scaling does not change the unit
template<typename ExpressionType, typename Unit, typename OtherScalarType>
inline auto
operator*(const QuantityGeometry<ExpressionType, Unit> &lhs, UniformScaling<OtherScalarType> rhs)
-> const Quantity<decltype(lhs.value()*rhs), Unit> {
    return lhs.value()*rhs;
}



}

#endif // EIGEN_QUANTITY_GEOMETRY_H
