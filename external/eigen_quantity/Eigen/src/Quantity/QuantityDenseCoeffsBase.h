#ifndef EIGEN_QUANTITY_DENSE_COEFFS_BASE_H
#define EIGEN_QUANTITY_DENSE_COEFFS_BASE_H

#include "Quantity.h"

namespace Eigen {

template<typename ExpressionType, typename Unit, int Level>
class QuantityDenseCoeffsBase;


template<typename ExpressionType, typename Unit>
class QuantityDenseCoeffsBase<ExpressionType, Unit, ReadOnlyAccessors>: public DenseCoeffsBase<Quantity<ExpressionType, Unit>, internal::accessors_level<ExpressionType>::value> {
public:

    typedef DenseCoeffsBase<Quantity<ExpressionType, Unit>, internal::accessors_level<ExpressionType>::value> Base;
    typedef typename Base::Scalar Scalar;
    typedef typename Base::CoeffReturnType CoeffReturnType;
    typedef typename Base::Index Index;

    inline ExpressionType &nested() {
        return this->derived().nestedExpression();
    }

    inline const ExpressionType &nested() const {
        return this->derived().nestedExpression();
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    operator()(Index row, Index col) const {
        return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().operator()(row, col));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    operator[](Index index) const {
        return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().operator[](index));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    operator()(Index index) const {
        return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().operator()(index));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    x() const { return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().x());}

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    y() const { return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().y());}

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    z() const { return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().z());}

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, CoeffReturnType>
    w() const { return boost::units::quantity<Unit, CoeffReturnType>::from_value(this->nested().w());}

};

// Wrapper around a boost::units::quantity value containing a reference.
// This is in order to make sure that assignments to elements or blocks
// in an array/matrix work as expected
template <typename Unit, typename ValueType>
class QuantityReferenceValue: public boost::units::quantity<Unit, ValueType&> {
public:
    inline QuantityReferenceValue &operator=(boost::units::quantity<Unit, ValueType> &&other) {
        this->value() = other.value();
        return *this;
    }

    inline QuantityReferenceValue &operator=(const boost::units::quantity<Unit, ValueType> &other) {
        this->value() = other.value();
        return *this;
    }

    static QuantityReferenceValue from_value(ValueType &val)  { return QuantityReferenceValue(val, 0); }

    friend boost::units::quantity<Unit, ValueType> operator/(const QuantityReferenceValue &numerator, const ValueType &denominator) {
        return boost::units::quantity<Unit, ValueType>::from_value(numerator.value())/denominator;
    }

    friend boost::units::quantity<decltype(boost::units::pow<-1>(Unit())), ValueType> operator/(const ValueType &numerator, const QuantityReferenceValue &denominator) {
        return numerator/boost::units::quantity<Unit, ValueType>::from_value(denominator.value());
    }

    friend boost::units::quantity<Unit, ValueType> operator*(const QuantityReferenceValue &value1, const ValueType &value2) {
        return boost::units::quantity<Unit, ValueType>::from_value(value1.value()) * value2;
    }

    friend boost::units::quantity<Unit, ValueType> operator*(const ValueType &value1, const QuantityReferenceValue &value2) {
        return value1 * boost::units::quantity<Unit, ValueType>::from_value(value2.value());
    }

private:
    explicit QuantityReferenceValue(ValueType& val, int flag)
            : boost::units::quantity<Unit, ValueType&>(val, flag) { }
};

template<typename ExpressionType, typename Unit>
class QuantityDenseCoeffsBase<ExpressionType, Unit, WriteAccessors>: public QuantityDenseCoeffsBase<ExpressionType, Unit, ReadOnlyAccessors> {
public:

    typedef QuantityDenseCoeffsBase<ExpressionType, Unit, ReadOnlyAccessors> Base;
    typedef typename Base::Scalar Scalar;
    typedef typename Base::Index Index;

    using Base::operator();
    using Base::operator[];
    using Base::x;
    using Base::y;
    using Base::z;
    using Base::w;

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    operator()(Index row, Index col) {
        return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().operator()(row, col));
    }

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    operator[](Index index) {
        return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().operator[](index));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, typename ExpressionType::Scalar>
    operator[](Index index) const {
        return boost::units::quantity<Unit, typename ExpressionType::Scalar>::from_value(this->nested().operator[](index));
    }

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    operator()(typename ExpressionType::Index index) {
        return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().operator()(index));
    }

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    x() { return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().x()); }

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    y() { return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().y()); }

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    z() { return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().z()); }

    EIGEN_STRONG_INLINE QuantityReferenceValue<Unit, typename ExpressionType::Scalar>
    w() { return QuantityReferenceValue<Unit, typename ExpressionType::Scalar>::from_value(this->nested().w()); }

};

template<typename ExpressionType, typename Unit>
class QuantityDenseCoeffsBase<ExpressionType, Unit, DirectAccessors>: public QuantityDenseCoeffsBase<ExpressionType, Unit, ReadOnlyAccessors> {
public:
};

template<typename ExpressionType, typename Unit>
class QuantityDenseCoeffsBase<ExpressionType, Unit, DirectWriteAccessors>: public QuantityDenseCoeffsBase<ExpressionType, Unit, WriteAccessors> {
public:
};

}

#endif