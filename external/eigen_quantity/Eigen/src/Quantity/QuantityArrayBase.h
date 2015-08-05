#ifndef EIGEN_QUANTITY_ARRAY_BASE_H
#define EIGEN_QUANTITY_ARRAY_BASE_H

#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include "QuantityDenseBase.h"

namespace Eigen {

template<typename ExpressionType, typename Unit>
//class QuantityArrayBaseBase: public QuantityDenseBase<ExpressionType, Unit> {
class ArrayBase<Quantity<ExpressionType, Unit>>: public DenseBase<Quantity<ExpressionType, Unit>> {
public:
    typedef DenseBase<Quantity<ExpressionType, Unit>> Base;
    typedef typename ExpressionType::Scalar Scalar;
    typedef boost::units::quantity<Unit, Scalar> QuantityType;
    typedef typename DenseBase<ExpressionType>::Index Index;


    inline const Quantity<
            CwiseUnaryOp<
                    internal::scalar_abs_op<
                            typename ExpressionType::Scalar>,
                    const ExpressionType>,
            Unit>
    abs() const {
        return this->nested().abs();
    }

    inline const Quantity<
            CwiseUnaryOp<
                    internal::scalar_abs2_op<
                            typename ExpressionType::Scalar>,
                    const ExpressionType>,
            decltype(Unit() * Unit())>
    abs2() const {
        return this->nested().abs2();
    }

    inline auto
    cube() const -> const Quantity<decltype(this->nested().cube()),
                                   decltype(Unit()*Unit()*Unit())> {
        return this->nested().cube();
    }

    inline auto
    cwiseInverse() const -> const Quantity<decltype(this->nested().cwiseInverse()),
                                           decltype(boost::units::pow<-1>(Unit()))> {
        return this->nested().cwiseInverse();
    }

    inline auto
    inverse() -> const Quantity<decltype(this->nested().inverse()),
                                decltype(boost::units::pow<-1>(Unit()))> {
        return this->nested().inverse();
    }

    inline Quantity<MatrixWrapper<ExpressionType>, Unit> matrix() {
        return this->nested().matrix();
    }

    inline const Quantity<const MatrixWrapper<const ExpressionType>, Unit> matrix() const {
        return this->nested().matrix();
    }

    template <typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    max(const ArrayBase<Quantity<OtherDerived, OtherUnit>> &other) const -> const Quantity<decltype(this->nested().max(other.nested())),
                                                                                           Unit> {
        return this->nested().max(other.nested());
    }

    inline auto
    max(const Scalar &other) const -> const Quantity<decltype(this->nested().max(other)),
                                                     Unit> {
        return this->nested().max(other.nested());
    }

    template <typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    min(const ArrayBase<Quantity<OtherDerived, OtherUnit>> &other) const -> const Quantity<decltype(this->nested().min(other.nested())),
                                                                                           Unit> {
        return this->nested().min(other.nested());
    }

    inline auto
    min(const Scalar &other) const -> const Quantity<decltype(this->nested().min(other)),
                                                     Unit> {
        return this->nested().min(other.nested());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator!=(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator!=(other.nested())) {
        return this->nested().operator!=(other.nested());
    }

    inline auto
    operator!=(const boost::units::quantity<Unit, Scalar> &other) const -> decltype(this->nested().operator!=(other.value())) {
        return this->nested().operator!=(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator&&(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator&&(other.nested())) {
        return this->nested().operator&&(other.nested());
    }

    template<typename OtherDerived, typename OtherUnit>
    inline auto
    operator*(const Quantity<OtherDerived, OtherUnit> &other) const -> const Quantity<decltype(this->nested().operator*(other.nested())),
                                                                                      decltype(Unit() * OtherUnit())> {
        return this->nested().operator*(other.nested());
    }

    template<typename OtherExpressionType>
    inline auto
    operator*(const ArrayBase<OtherExpressionType> &other) const -> const Quantity<decltype(this->nested().operator*(other)),
                                                                                   Unit> {
        return this->nested().operator*(other);
    }

    inline auto
    operator*(const Scalar &other) const -> const Quantity<decltype(this->nested().operator*(other)),
                                                           Unit> {
        return this->nested().operator*(other);
    }

    template<typename OtherUnit>
    inline auto
    operator*(const boost::units::quantity<OtherUnit, Scalar> &other) const -> const Quantity<decltype(this->nested().operator*(other.value())),
                                                                                              decltype(Unit() * OtherUnit())> {
        return this->nested().operator*(other.value());
    }

    inline auto
    operator*(const std::complex<Scalar> &other) const -> const Quantity<decltype(this->nested().operator*(other)),
                                                                         Unit> {
        return this->nested().operator*(other);
    }

    template<typename OtherDerived, typename OtherUnit>
    inline auto
    operator/(const ArrayBase<Quantity<OtherDerived, OtherUnit>> &other) const -> const Quantity<decltype(this->nested().operator/(other.nested())),
                                                                                                 decltype(Unit() / OtherUnit())> {
        return this->nested().operator/(other.nested());
    }

    inline auto
    operator/(const Scalar &other) const -> const Quantity<decltype(this->nested().operator/(other)),
                                                           Unit> {
        return this->nested().operator/(other);
    }

    template<typename OtherUnit>
    inline auto
    operator/(const boost::units::quantity<OtherUnit, Scalar> &other) const -> const Quantity<decltype(this->nested().operator/(other.value())),
                                                                                              decltype(Unit() / OtherUnit())> {
        return this->nested().operator/(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator+(const Quantity<OtherDerived, OtherUnit> &other) const -> const Quantity<decltype(this->nested().operator+(other.nested())),
                                                                                      Unit> {
        return this->nested().operator+(other.nested());
    }

    inline auto
    operator+(const boost::units::quantity<Unit> &other) const -> const Quantity<decltype(this->nested().operator+(other.value())),
                                                                                 Unit> {
        return this->nested().operator+(other.value());
    }

    inline auto
    operator-(const boost::units::quantity<Unit> &other) const -> const Quantity<decltype(this->nested().operator-(other.value())),
                                                                                 Unit> {
        return this->nested().operator-(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
             typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                             >>::type* = nullptr>
    inline auto
    operator-(const Quantity<OtherDerived, OtherUnit> &other) const -> const Quantity<decltype(this->nested().operator-(other.nested())),
                                                                                      OtherUnit> {
        return this->nested().operator-(other.nested());
    }

    inline auto
    operator-() const -> const Quantity<decltype(this->nested().operator-()),
                                        Unit> {
        return this->nested().operator-();
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator<(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator<(other.nested())) {
        return this->nested().operator<(other.nested());
    }

    inline auto
    operator<(const boost::units::quantity<Unit, Scalar> &other) const -> decltype(this->nested().operator<(other.value())) {
        return this->nested().operator<(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator<=(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator<=(other.nested())) {
        return this->nested().operator<=(other.nested());
    }

    inline auto
    operator<=(const boost::units::quantity<Unit, Scalar> &other) const -> decltype(this->nested().operator<=(other.value())) {
        return this->nested().operator<=(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator=(const Quantity<EigenBase<OtherDerived>, OtherUnit> &other) const -> const Quantity<decltype(this->nested().operator=(other.nested())),
                                                                                                 Unit> {
        return this->nested().operator=(other.nested());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator=(const Quantity<ArrayBase<OtherDerived>, OtherUnit> &other) const -> const Quantity<decltype(this->nested().operator=(other.nested())),
                                                                                                 Unit> {
        return this->nested().operator=(other.nested());
    }

    template<int _Rows, int _Cols, int _Options, int _MaxRows, int _MaxCols>
    inline auto
    operator=(const Quantity<Array<Scalar, _Rows, _Cols, _Options, _MaxRows, _MaxCols>, Unit> &other) const -> const Quantity<decltype(this->nested().operator=(other.nested())),
                                                                                                                              Unit> {
        return this->nested().operator=(other.nested());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator==(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator==(other.nested())) {
        return this->nested().operator==(other.nested());
    }

    inline auto
    operator==(const boost::units::quantity<Unit, Scalar> &other) const -> decltype(this->nested().operator==(other.value())) {
        return this->nested().operator==(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator>(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator>(other.nested())) {
        return this->nested().operator>(other.nested());
    }

    inline auto
    operator>(const boost::units::quantity<Unit, Scalar> &other) const -> decltype(this->nested().operator>(other.value())) {
        return this->nested().operator>(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator>=(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator>=(other.nested())) {
        return this->nested().operator>=(other.nested());
    }

    inline auto
    operator>=(const boost::units::quantity<Unit, Scalar> &other) const -> decltype(this->nested().operator>=(other.value())) {
        return this->nested().operator>=(other.value());
    }

    template<typename OtherDerived, typename OtherUnit,
                 typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                     >>::type* = nullptr>
    inline auto
    operator||(const Quantity<OtherDerived, OtherUnit> &other) const -> decltype(this->nested().operator||(other.nested())) {
        return this->nested().operator||(other.nested());
    }

    template<int N>
    inline auto
    pow() const -> const Quantity<decltype(this->nested().pow(N)),
                                  decltype(boost::units::pow<N>(Unit()))> {
        return this->nested().pow(N);
    }

    inline auto
    sqrt() -> const Quantity<decltype(this->nested().sqrt()),
                             typename decltype(boost::units::sqrt(boost::units::quantity<Unit>()))::unit_type> {
        return this->nested().sqrt();
    }

    inline auto
    square() -> Quantity<decltype(this->nested().square()),
                         decltype(Unit()*Unit())> {
        return this->nested().square();
    }
};


template<typename ExpressionType, typename Unit>
class ArrayBaseSpecialization: public ArrayBase<Quantity<ExpressionType, Unit>> {
};

template<typename ExpressionType, typename System>
class ArrayBaseSpecialization<ExpressionType,
                              boost::units::unit<boost::units::dimensionless_type,
                                                 boost::units::homogeneous_system<System> > >
        : public ArrayBase<Quantity<ExpressionType,
                                    boost::units::unit<boost::units::dimensionless_type,
                                                       boost::units::homogeneous_system<System> > > >{
public:
    typedef boost::units::unit<boost::units::dimensionless_type, boost::units::homogeneous_system<System> > Unit;

    inline auto
    acos() const -> const Quantity<decltype(this->nested().acos()),
                                   typename decltype(boost::units::acos(boost::units::quantity<Unit>()))::unit_type> {
        return this->nested().acos();
    }

    inline auto
    asin() const -> const Quantity<decltype(this->nested().asin()),
                                   typename decltype(boost::units::asin(boost::units::quantity<Unit>()))::unit_type> {
        return this->nested().asin();
    }

    inline auto
    log() const -> const Quantity<decltype(this->nested().log()), Unit> {
        this->nested().log();
    }
};

template<typename ExpressionType, typename System>
class ArrayBaseSpecialization<ExpressionType,
                              boost::units::unit<boost::units::plane_angle_dimension, boost::units::homogeneous_system<System> > >
        : public ArrayBase<Quantity<ExpressionType,
                                    boost::units::unit<boost::units::plane_angle_dimension,
                                                       boost::units::homogeneous_system<System> > > > {
public:
    inline auto
    cos() -> const Quantity<decltype(this->nested().cos()),
                            typename decltype(boost::units::cos(boost::units::quantity<boost::units::unit<boost::units::plane_angle_dimension, boost::units::homogeneous_system<System> > >()))::unit_type> {
        return this->nested().cos();
    }

    inline auto
    sin() -> const Quantity<decltype(this->nested().sin()),
                            typename decltype(boost::units::sin(boost::units::quantity<boost::units::unit<boost::units::plane_angle_dimension, boost::units::homogeneous_system<System> > >()))::unit_type> {
        return this->nested().sin();
    }

    inline auto
    tan() -> const Quantity<decltype(this->nested().tan()),
                            typename decltype(boost::units::tan(boost::units::quantity<boost::units::unit<boost::units::plane_angle_dimension, boost::units::homogeneous_system<System> > >()))::unit_type> {
        return this->nested().tan();
    }
};


}

#endif