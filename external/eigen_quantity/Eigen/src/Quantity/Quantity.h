#ifndef EIGEN_QUANTITY_H
#define EIGEN_QUANTITY_H

#include <boost/units/quantity.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/is_dimensionless.hpp>
#include <iostream>

namespace Eigen {
template<typename ExpressionType, typename Unit> class Quantity;
template<typename Type, int Rows, int Cols> class QuantityMatrix;
template<typename Type, int Rows, int Cols> class QuantityArray;
}
#define EIGEN_DENSEBASE_PLUGIN "Eigen/src/Quantity/DenseBaseAddons.h"

#include <Eigen/Dense>
#include "QuantityDenseBase.h"
#include "QuantityArrayBase.h"
#include "QuantityMatrixBase.h"
#include "QuantityEigenBase.h"
#include "QuantityVectorwiseOp.h"
#include "QuantityDiagonalBase.h"
#include "QuantityCommaInitializer.h"

namespace Eigen {

namespace internal {

// Inherit traits from Expression type
template<typename ExpressionType, typename Unit>
struct traits<Quantity<ExpressionType, Unit> > : traits<ExpressionType> {
    //typedef typename boost::units::quantity<Unit, const typename ExpressionType::Scalar&> Scalar;
};

template<typename ExpressionType, class Unit, class Enable=void>
struct QuantityBase;

template<typename ExpressionType, class Unit>
struct QuantityBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, MatrixXpr>::value>::type> {
    typedef MatrixBaseSpecialization<ExpressionType, Unit> type;
};

template<typename ExpressionType, class Unit>
struct QuantityBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, ArrayXpr>::value>::type> {
    typedef ArrayBaseSpecialization<ExpressionType, Unit> type;
};

template<typename ExpressionType, int Direction, class Unit>
struct QuantityBase<VectorwiseOp<ExpressionType, Direction>, Unit> {
    typedef VectorwiseOp<Quantity<ExpressionType, Unit>, Direction> type;
};

template<typename ExpressionType, class Unit>
struct QuantityBase<DiagonalWrapper<ExpressionType>, Unit> {
    typedef DiagonalBase<Quantity<DiagonalWrapper<ExpressionType>, Unit>> type;
};

template<typename ExpressionType, class Unit>
struct QuantityBase<const DiagonalWrapper<const ExpressionType>, Unit> {
    typedef DiagonalBase<Quantity<const DiagonalWrapper<const ExpressionType>, Unit>> type;
};

template<typename ExpressionType, class Unit>
struct QuantityBase<CommaInitializer<ExpressionType>, Unit> {
    typedef CommaInitializer<Quantity<ExpressionType, Unit>> type;
};

template<typename ExpressionType, class Unit>
struct QuantityBase<const CommaInitializer<const ExpressionType>, Unit> {
    typedef CommaInitializer<Quantity<const ExpressionType, Unit>> type;
};


//template<typename ExpressionType, class Unit>
//struct QuantityBase<ExpressionType, Unit> {
//    typedef MatrixBaseSpecialization<ExpressionType, Unit> type;
//};
//
//template<typename ExpressionType, class Unit>
//struct QuantityBase<ExpressionType, Unit, ArrayXpr> {
//    typedef ArrayBaseSpecialization<ExpressionType, Unit> type;
//};

//template<typename ExpressionType, class Unit>
//struct QuantityBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, MatrixXpr> {
//    typedef ArrayBaseSpecialization<ExpressionType, Unit> type;
//};

}


template<typename ExpressionType, class Unit>
class Quantity
//        : public internal::QuantityBase<ExpressionType, Unit, typename internal::traits<ExpressionType>::XprKind>::type {
        : public internal::QuantityBase<typename std::remove_reference<ExpressionType>::type, Unit>::type {
public:

    typedef typename internal::QuantityBase<typename std::remove_reference<ExpressionType>::type, Unit>::type Base;

    typedef typename std::remove_reference<ExpressionType>::type::Scalar Scalar;
    typedef boost::units::quantity<Unit, Scalar> QuantityType;
    typedef const Quantity& Nested;
    typedef typename std::remove_reference<ExpressionType>::type::Index Index;

    inline Quantity(){}

    inline Quantity(const ExpressionType &a_matrix)
            //: Base(a_matrix),
            : expression(a_matrix) {
    }

    inline Quantity(typename std::remove_reference<ExpressionType>::type &&a_matrix)
            //: Base(std::move(a_matrix)),
            : expression(std::move(a_matrix)) {
    }

    template<typename OtherDerived>
    inline Quantity(const Quantity<OtherDerived, Unit> &other)
            // : Base(other.nested()),
              : expression(other.nested()) {
    }

    template<typename OtherDerived>
    inline Quantity(Quantity<OtherDerived, Unit> &&other)
            // : Base(other.nested()),
            : expression(std::move(other.nested())) {
    }

    template<typename OtherDerived>
    inline Quantity &operator=(const Quantity<OtherDerived, Unit> &other) {
        expression = other.nested();
        return *this;
    }



    inline typename std::remove_reference<ExpressionType>::type::Index rows() const { return expression.rows(); }
    inline typename std::remove_reference<ExpressionType>::type::Index cols() const { return expression.cols(); }
    inline Index outerStride() const { expression.outerStride(); }
    inline Index innerStride() const { expression.innerStride(); }

    // Only allow evalTo another quantity with the same unit
    template<typename Dest>
    inline void evalTo(Quantity<Dest, Unit>& dst) const { dst.expression = expression; }

    /** \returns the this->nested this->nested() */
    inline const ExpressionType &
    nestedExpression() const { return expression; }

    /** \returns the this->nested this->nested() */
    inline ExpressionType &
    nestedExpression() { return expression.const_cast_derived(); }


    // Overload * to add unit to Quantity type
    template<class Dim, class System>
    friend const inline Quantity<ExpressionType, decltype(Unit()*boost::units::unit<Dim, System>())>
    operator*(const Quantity<ExpressionType, Unit> &lhs, const boost::units::unit<Dim, System> &rhs) {
        return lhs.nested();
    }

    // Overload / to remove unit from Quantity type
    template<class Dim, class System>
    friend const inline Quantity<ExpressionType, decltype(Unit()/boost::units::unit<Dim, System>())>
    operator/(const Quantity<ExpressionType, Unit> &lhs, const boost::units::unit<Dim, System> &rhs) {
        return lhs.nested();
    }

private:

    ExpressionType expression;

};

}

#endif