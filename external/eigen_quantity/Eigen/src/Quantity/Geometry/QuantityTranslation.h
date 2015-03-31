#ifndef EIGEN_QUANTITY_TRANSLATION_H
#define EIGEN_QUANTITY_TRANSLATION_H

#include "QuantityGeometryTransformBase.h"

namespace Eigen {

template<typename ExpressionType, typename Unit>
class QuantityTranslation: public QuantityGeometryTransformBase<ExpressionType, Unit> {
public:

};

template<typename QDim, typename QSystem, int Dim>
class Translation<boost::units::unit<QDim, QSystem>, Dim>: public Quantity<Translation<double, Dim>, boost::units::unit<QDim, QSystem>> {
public:

    typedef boost::units::unit<QDim, QSystem> Unit;
    typedef Quantity<Translation<double, Dim>, Unit> Base;

    using Base::Base;

    template <typename ExpressionType>
    Translation(const MatrixBase<Quantity<ExpressionType, Unit>> &vector) {
        this->nested()(vector.value());
    }

    Translation(const boost::units::quantity<Unit> &vx, const boost::units::quantity<Unit> &vy, const boost::units::quantity<Unit> &vz) {
    	this->nested().x() = vx.value();
    	this->nested().y() = vy.value();
    	this->nested().z() = vz.value();
    }
};

template<typename QDim, typename QSystem, typename QScalar, int Dim>
class Translation<boost::units::quantity<boost::units::unit<QDim, QSystem>, QScalar>, Dim>: public Quantity<Translation<QScalar, Dim>, boost::units::unit<QDim, QSystem>> {
public:
    typedef boost::units::unit<QDim, QSystem> Unit;
    typedef Quantity<Translation<QScalar, Dim>, Unit> Base;

    using Base::Base;

    template <typename ExpressionType>
    Translation(const MatrixBase<Quantity<ExpressionType, Unit>> &vector) {
        this->nested()(vector.value());
    }

    Translation(const boost::units::quantity<Unit> &vx, const boost::units::quantity<Unit> &vy, const boost::units::quantity<Unit> &vz){
    	this->nested().x() = vx.value();
    	this->nested().y() = vy.value();
    	this->nested().z() = vz.value();
    }
};


namespace internal {

template<typename Scalar, int Dim, typename Unit>
struct QuantityBase<Translation<Scalar, Dim>, Unit> {
    typedef QuantityTranslation<Translation<Scalar, Dim>, Unit> type;
};

template<typename Scalar, int Dim, typename Unit>
struct QuantityBase<const Translation<Scalar, Dim>, Unit> {
    typedef QuantityTranslation<const Translation<Scalar, Dim>, Unit> type;
};

}

}

#endif // EIGEN_QUANTITY_TRANSLATION_H
