#ifndef EIGEN_QUANTITY_DENSE_COEFFS_BASE_H
#define EIGEN_QUANTITY_DENSE_COEFFS_BASE_H

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

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, typename ExpressionType::Scalar>
    operator()(Index row, Index col) {
        return boost::units::quantity<Unit, typename ExpressionType::Scalar>::from_value(this->nested().operator()(row, col));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
    operator[](Index index) {
        return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().operator[](index));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
    operator()(typename ExpressionType::Index index) {
        return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().operator()(index));
    }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
    x() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().x()); }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
    y() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().y()); }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
    z() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().z()); }

    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
    w() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().w()); }








//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    operator()(Index row, Index col) {
//        return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().operator()(row, col));
//    }
//
//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    operator[](Index index) {
//        return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().operator[](index));
//    }
//
//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    operator()(typename ExpressionType::Index index) {
//        return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().operator()(index));
//    }
//
//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    x() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().x()); }
//
//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    y() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().y()); }
//
//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    z() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().z()); }
//
//    EIGEN_STRONG_INLINE boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>
//    w() { return boost::units::quantity<Unit, std::reference_wrapper<typename ExpressionType::Scalar>>::from_value(this->nested().w()); }

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