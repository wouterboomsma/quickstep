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
struct QuantityBaseBase;

template<typename ExpressionType, class Unit>
struct QuantityBaseBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, MatrixXpr>::value>::type> {
    typedef MatrixBaseSpecialization<ExpressionType, Unit> type;
};

template<typename ExpressionType, class Unit>
struct QuantityBaseBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, ArrayXpr>::value>::type> {
    typedef ArrayBaseSpecialization<ExpressionType, Unit> type;
};


template<typename ExpressionType, class Unit, class Enable=void>
struct QuantityBase {
    typedef typename QuantityBaseBase<ExpressionType, Unit>::type type;
};

//template<typename ExpressionType, class Unit>
//struct QuantityBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, MatrixXpr>::value>::type> {
//    typedef MatrixBaseSpecialization<ExpressionType, Unit> type;
//};
//
//template<typename ExpressionType, class Unit>
//struct QuantityBase<ExpressionType, Unit, typename std::enable_if<std::is_same<typename internal::traits<ExpressionType>::XprKind, ArrayXpr>::value>::type> {
//    typedef ArrayBaseSpecialization<ExpressionType, Unit> type;
//};

template<typename ExpressionType, int Direction, class Unit>
struct QuantityBase<VectorwiseOp<ExpressionType, Direction>, Unit> {
    typedef VectorwiseOp<Quantity<ExpressionType, Unit>, Direction> type;
};

template<typename ExpressionType, int Direction, class Unit>
struct QuantityBase<const VectorwiseOp<const ExpressionType, Direction>, Unit> {
    typedef VectorwiseOp<const Quantity<const ExpressionType, Unit>, Direction> type;
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
//    typedef typename std::remove_reference<ExpressionType>::type::Index Index;

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

    template<typename OtherDerived, typename OtherUnit,
             typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                             >>::type* = nullptr>
    inline Quantity(const Quantity<OtherDerived, OtherUnit> &other)
            : expression(other.nested()) {
    }

    template<typename OtherDerived, typename OtherUnit,
             typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                             >>::type* = nullptr>
    inline Quantity(Quantity<OtherDerived, Unit> &&other)
            : expression(std::move(other.nested())) {
    }

    template<typename OtherDerived, typename OtherUnit,
             typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                             >>::type* = nullptr>
    inline Quantity &operator=(const Quantity<OtherDerived, OtherUnit> &other) {
        expression = other.nested();
        return *this;
    }

    template<typename OtherDerived, typename OtherUnit,
             typename boost::enable_if<
                     boost::mpl::and_<
                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
                             >>::type* = nullptr>
    inline Quantity &operator=(Quantity<OtherDerived, Unit> &&other)  {
        expression = other.nested();
        return *this;
    }

    template<typename OtherDerived>
    inline Quantity &operator=(const Quantity<OtherDerived, Unit> &other) {
        expression = other.nested();
        return *this;
    }

    inline Quantity &operator=(const boost::units::quantity<Unit> &other) {
        expression = other;
        return *this;
    }


//    inline typename std::remove_reference<ExpressionType>::type::Index rows() const { return expression.rows(); }
//    inline typename std::remove_reference<ExpressionType>::type::Index cols() const { return expression.cols(); }
//    inline Index outerStride() const { expression.outerStride(); }
//    inline Index innerStride() const { expression.innerStride(); }

    // Only allow evalTo another quantity with the same unit
    template<typename Dest>
    inline void evalTo(Quantity<Dest, Unit>& dst) const { dst.expression = expression; }

    /** \returns the this->nested this->nested() */
    inline const ExpressionType &
    nestedExpression() const { return expression; }

    /** \returns the this->nested this->nested() */
    inline ExpressionType &
    nestedExpression() { return expression.const_cast_derived(); }

    inline ExpressionType &value() {
        return this->nested();
    }

    inline const ExpressionType &value() const {
        return this->nested();
    }


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

//// Specialization for Transform, which doesn't follow the same layout as in Core
//template<typename Scalar, int Dim, int Mode, typename Unit>
//class Quantity<Transform<Scalar, Dim, Mode>, Unit>: public QuantityTransform<Transform<Scalar, Dim, Mode>, Unit> {
//public:
//
//    typedef Transform<Scalar, Dim, Mode> ExpressionType;
//
//    inline Quantity(const ExpressionType &a_matrix)
//    //: Base(a_matrix),
//            : expression(a_matrix) {
//    }
//
//    inline Quantity(typename std::remove_reference<ExpressionType>::type &&a_matrix)
//    //: Base(std::move(a_matrix)),
//            : expression(std::move(a_matrix)) {
//    }
//
//    template<typename OtherDerived>
//    inline Quantity(const Quantity<OtherDerived, Unit> &other)
//    // : Base(other.nested()),
//            : expression(other.nested()) {
//    }
//
//    template<typename OtherDerived>
//    inline Quantity(Quantity<OtherDerived, Unit> &&other)
//    // : Base(other.nested()),
//            : expression(std::move(other.nested())) {
//    }
//
//    template<typename OtherDerived, typename OtherUnit>
//    inline Quantity(const Quantity<OtherDerived, OtherUnit> &other,
//                    typename boost::enable_if<
//                            boost::mpl::and_<
//                                    typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
//                                    boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
//                                    >>::type* = 0)
//            : expression(other.nested()) {
//    }
//
//    template<typename OtherDerived, typename OtherUnit>
//    inline Quantity(Quantity<OtherDerived, Unit> &&other,
//                    typename boost::enable_if<
//                            boost::mpl::and_<
//                                    typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
//                                    boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
//                                    >>::type* = 0)
//            : expression(std::move(other.nested())) {
//    }
//
//    template<typename OtherDerived, typename OtherUnit,
//             typename boost::enable_if<
//                     boost::mpl::and_<
//                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
//                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
//                             >>::type* = nullptr>
//    inline Quantity &operator=(const Quantity<OtherDerived, OtherUnit> &other) {
//        expression = other.nested();
//        return *this;
//    }
//
//    template<typename OtherDerived, typename OtherUnit,
//             typename boost::enable_if<
//                     boost::mpl::and_<
//                             typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
//                             boost::units::detail::is_non_narrowing_conversion<typename Quantity<OtherDerived, OtherUnit>::Scalar, Scalar>
//                             >>::type* = nullptr>
//    inline Quantity &operator=(Quantity<OtherDerived, Unit> &&other)  {
//        expression = other.nested();
//        return *this;
//    }
//
//    template<typename OtherDerived>
//    inline Quantity &operator=(const Quantity<OtherDerived, Unit> &other) {
//        expression = other.nested();
//        return *this;
//    }
//
//    inline Quantity &operator=(const boost::units::quantity<Unit> &other) {
//        expression = other;
//        return *this;
//    }
//
//private:
//
//    ExpressionType expression;
//
//};
//



//// Operators ////

// CwiseNullaryOp
template<typename ExpressionType, typename Unit, typename NullaryOp, typename PlainObjectType>
inline auto
operator*(const CwiseNullaryOp<NullaryOp, PlainObjectType> &lhs, const Quantity<ExpressionType, Unit> &rhs)
-> Quantity<decltype(lhs*rhs.nested()),
            Unit>{
    return lhs*rhs.nested();
}
//
//
// VectorwiseOp
template<typename ExpressionType, typename Unit, typename OtherExpressionType, int Direction>
inline auto
operator*(const VectorwiseOp<OtherExpressionType, Direction> &lhs, const Quantity<ExpressionType, Unit> &rhs)
-> Quantity<decltype(lhs*rhs.nested()),
            Unit>{
    return lhs*rhs.nested();
}

//template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit>
//inline auto
//operator*(const Quantity<ExpressionType, Unit> &lhs, const Quantity<OtherExpressionType, OtherUnit> &rhs)
//-> Quantity<decltype(lhs.nested()*rhs.nested()),
//            decltype(Unit()*OtherUnit())>{
//    return lhs.nested()*rhs.nested();
//}

template<typename ExpressionType, typename Unit>
inline auto
operator*(const double &lhs, const Quantity<ExpressionType, Unit> &rhs)
-> Quantity<decltype(lhs*rhs.nested()),
            Unit>{
    return lhs*rhs.nested();
}

template<typename ExpressionType, typename Unit, typename OtherUnit>
inline auto
operator*(const boost::units::quantity<OtherUnit> &lhs, const Quantity<ExpressionType, Unit> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.value()), decltype(Unit()*OtherUnit())>{
    return lhs.value()*rhs.value();
}

template<typename ExpressionType, typename Unit, typename OtherDerived, typename OtherUnit>
inline auto
operator*(const DenseBase<Quantity<ExpressionType, Unit>> &lhs, const Quantity<OtherDerived, OtherUnit> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.value()), decltype(Unit() * OtherUnit())> {
    return lhs.value()*rhs.value();
}

template<typename ExpressionType, typename Unit, typename OtherExpressionType>
inline auto
operator*(const DenseBase<Quantity<ExpressionType, Unit>> &lhs, const DenseBase<OtherExpressionType> &rhs)
-> const Quantity<decltype(lhs.value()*rhs), Unit> {
    return lhs.value()*rhs;
}

template<typename ExpressionType, typename Unit, typename OtherExpressionType>
inline auto
operator*(const DenseBase<ExpressionType> &lhs, const DenseBase<Quantity<OtherExpressionType, Unit>> &rhs)
-> const Quantity<decltype(lhs*rhs.value()), Unit> {
    return lhs*rhs.value();
}

template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit>
inline auto
operator*(const Quantity<ExpressionType, Unit> &lhs, const Quantity<OtherExpressionType, OtherUnit> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.value()), decltype(Unit()*OtherUnit())> {
    return lhs.value()*rhs.value();
}


//template<typename ExpressionType, typename Unit, typename OtherExpressionType, typename OtherUnit>
//inline auto
//operator*(const Quantity<Transform<ExpressionType, Unit> &lhs, const Quantity<OtherExpressionType, OtherUnit> &rhs)
//-> const Quantity<decltype(lhs.value()*rhs.value()), decltype(Unit()*OtherUnit())> {
//    return lhs.value()*rhs.value();
//}




}

#endif
