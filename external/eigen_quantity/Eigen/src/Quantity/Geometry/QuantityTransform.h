#ifndef EIGEN_QUANTITY_TRANSFORM_H
#define EIGEN_QUANTITY_TRANSFORM_H

#include "QuantityGeometryTransformBase.h"

namespace Eigen {

template<typename ExpressionType, typename Unit>
class QuantityTransform: public QuantityGeometryTransformBase<ExpressionType, Unit> {
public:


    inline static const Quantity<ExpressionType, Unit> Identity() {
        return ExpressionType::Identity();
    }

    void
    setIdentity() {
        this->nested().setIdentity();
    }


};

template<typename QDim, typename QSystem, int Dim, int Mode>
class Transform<boost::units::unit<QDim, QSystem>, Dim, Mode>: public Quantity<Transform<double, Dim, Mode, AutoAlign>, boost::units::unit<QDim, QSystem>> {
public:
    typedef Quantity<Transform<double, Dim, Mode, AutoAlign>, boost::units::unit<QDim, QSystem>> Base;

    using Base::Base;
};

template<typename QDim, typename QSystem, typename QScalar, int Dim, int Mode>
class Transform<boost::units::quantity<boost::units::unit<QDim, QSystem>, QScalar>, Dim, Mode>: public Quantity<Transform<QScalar, Dim, Mode, AutoAlign>, boost::units::unit<QDim, QSystem>> {
    typedef Quantity<Transform<QScalar, Dim, Mode, AutoAlign>, boost::units::unit<QDim, QSystem>> Base;

    using Base::Base;
};

//template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit>
//inline auto
//operator*(const Quantity<Transform<, Unit> &lhs, const Quantity<OtherExpressionType, OtherUnit> &rhs)
//-> Quantity<decltype(lhs.nested()*rhs.nested()),
//            decltype(Unit()*OtherUnit())>{
//    return lhs.nested()*rhs.nested();
//}


namespace internal {

template<typename Scalar, int Dim, int Mode, typename Unit>
struct QuantityBase<Transform < Scalar, Dim, Mode>, Unit> {
    typedef QuantityTransform<Transform<Scalar, Dim, Mode>, Unit> type;
};

template<typename Scalar, int Dim, int Mode, typename Unit>
struct QuantityBase<const Transform <Scalar, Dim, Mode>, Unit> {
    typedef QuantityTransform<const Transform<Scalar, Dim, Mode>, Unit> type;
};

}



}

#endif // EIGEN_QUANTITY_TRANSFORM_H
