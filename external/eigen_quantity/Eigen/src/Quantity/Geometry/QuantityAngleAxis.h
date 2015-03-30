#ifndef EIGEN_QUANTITY_ANGLEAXIS_H
#define EIGEN_QUANTITY_ANGLEAXIS_H

#include "QuantityGeometryTransformBase.h"

namespace Eigen {

template<typename ExpressionType, typename Unit>
class QuantityAngleAxis: public QuantityGeometryTransformBase<ExpressionType, Unit> {
public:

};

template<typename QDim, typename QSystem>
class AngleAxis<boost::units::unit<QDim, QSystem>>: public Quantity<AngleAxis<double>, boost::units::unit<QDim, QSystem>> {
public:
    typedef boost::units::unit<QDim, QSystem> Unit;
    typedef Quantity<AngleAxis<double>, Unit> Base;

    using Base::Base;

    template <typename System, typename ExpressionType>
    AngleAxis(const boost::units::quantity<boost::units::unit<boost::units::plane_angle_dimension, System>> &angle, const MatrixBase<Quantity<ExpressionType, Unit>> &axis)
        : Base(AngleAxis<double>(angle.value(), axis.value())) {
    }

};

template<typename QDim, typename QSystem, typename QScalar>
class AngleAxis<boost::units::quantity<boost::units::unit<QDim, QSystem>, QScalar>>: public Quantity<AngleAxis<QScalar>, boost::units::unit<QDim, QSystem>> {
public:
    typedef boost::units::unit<QDim, QSystem> Unit;
    typedef Quantity<AngleAxis<QScalar>, Unit> Base;

    using Base::Base;

    template <typename System, typename ExpressionType>
    AngleAxis(const boost::units::quantity<boost::units::unit<boost::units::plane_angle_dimension, System>> &angle, const MatrixBase<Quantity<ExpressionType, Unit>> &axis)
        : Base(AngleAxis<double>(angle.value(), axis.value())) {
    }
};


namespace internal {

template<typename Scalar, typename Unit>
struct QuantityBase<AngleAxis<Scalar>, Unit> {
    typedef QuantityAngleAxis<AngleAxis<Scalar>, Unit> type;
};

template<typename Scalar, typename Unit>
struct QuantityBase<const AngleAxis<Scalar>, Unit> {
    typedef QuantityAngleAxis<const AngleAxis<Scalar>, Unit> type;
};

}

}

#endif // EIGEN_QUANTITY_ANGLEAXIS_H
