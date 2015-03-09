#ifndef EIGEN_QUANTITY_MATRIX_H
#define EIGEN_QUANTITY_MATRIX_H

#include "Quantity.h"
#include "QuantityPlainObjectBase.h"

namespace Eigen {

template<typename Type, int Rows, int Cols>
class QuantityMatrix : public Matrix<Type, Rows, Cols> {
public:
    typedef Matrix<Type, Rows, Cols> Base;

    // Inherit base class constructors
    using Base::Base;

    // The code below is as recommended when inheriting from Eigen::Matrix.
    // See: http://eigen.tuxfamily.org/dox/TopicCustomizingEigen.html

    // Default constructor
    inline QuantityMatrix() : Base() {
    }

    // This constructor allows you to construct Matrix from Eigen expressions
    template<typename OtherDerived>
    inline QuantityMatrix(const MatrixBase<OtherDerived> &other)
            : Base(other) {
    }

    template<typename OtherDerived, typename Unit>
    inline QuantityMatrix(const MatrixBase<Quantity<OtherDerived, Unit>> &other) {
        static_assert(internal::DependentBool<false,OtherDerived>::value, "Cannot copy a QuantityMatrix to a standard Matrix. Use .value() to extract raw matrix");
    }

    // This method allows you to assign Eigen expressions to Matrix
    template<typename OtherDerived>
    inline QuantityMatrix &operator=(const MatrixBase<OtherDerived> &other) {
        this->Base::operator=(other);
        return *this;
    }

    template<typename OtherDerived, typename Unit>
    inline QuantityMatrix &operator=(const MatrixBase<Quantity<OtherDerived, Unit>> &other) {
        static_assert(internal::DependentBool<false,OtherDerived>::value, "Cannot assign a QuantityMatrix to a standard Matrix. Use .value() to extract raw matrix");
        return *this;
    }

    // Overload * to add unit to matrix type
    template<class Dim, class System>
    friend const inline Quantity<Matrix<Type, Rows, Cols>, boost::units::unit<Dim, System>>
    operator*(const QuantityMatrix &lhs, const boost::units::unit<Dim, System> &rhs) {
        return lhs;
    }

};

template<typename Unit, int Rows, int Cols>
class QuantityMatrix<boost::units::quantity<Unit>, Rows, Cols>
    : public PlainObjectBase<Quantity<Matrix<typename boost::units::quantity<Unit>::value_type,Rows,Cols>, Unit>> {
public:

    typedef typename boost::units::quantity<Unit>::value_type ValueType;
    typedef PlainObjectBase<Quantity<Matrix<typename boost::units::quantity<Unit>::value_type,Rows,Cols>, Unit>> Base;

    inline QuantityMatrix(){}

    inline QuantityMatrix(typename Base::Index size)
            : Base(Matrix<ValueType, Rows, Cols>(size)){}

    inline QuantityMatrix(typename Base::Index rows, typename Base::Index cols)
            : Base(Matrix<ValueType, Rows, Cols>(rows, cols)){}

    inline QuantityMatrix(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1)
            : Base(Matrix<ValueType, Rows, Cols>(val0.value(), val1.value())){}

    inline QuantityMatrix(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2)
            : Base(Matrix<ValueType, Rows, Cols>(val0.value(), val1.value(), val2.value())){}

    inline QuantityMatrix(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2,
                         const boost::units::quantity<Unit> &val3)
            : Base(Matrix<ValueType, Rows, Cols>(val0.value(), val1.value(),
                                                 val2.value(),val3.value())){}

    template<typename OtherDerived>
    inline QuantityMatrix(const Quantity<OtherDerived, Unit> &quantity)
            : Base(quantity) {}

    template<typename OtherDerived>
    inline QuantityMatrix(const Quantity<OtherDerived, Unit> &&quantity)
            : Base(std::move(quantity)) {}

};

template<typename Dim, typename System, int Rows, int Cols>
class QuantityMatrix<boost::units::unit<Dim, System>, Rows, Cols>
        : public PlainObjectBase<Quantity<Matrix<double,Rows,Cols>, boost::units::unit<Dim, System>>> {
public:
    typedef boost::units::unit<Dim, System> Unit;
    typedef typename boost::units::quantity<Unit>::value_type ValueType;
    typedef PlainObjectBase<Quantity<Matrix<double,Rows,Cols>, Unit>> Base;

    inline QuantityMatrix(){}

    inline QuantityMatrix(typename Base::Index size)
            : Base(Matrix<ValueType, Rows, Cols>(size)){}

    inline QuantityMatrix(typename Base::Index rows, typename Base::Index cols)
            : Base(Matrix<ValueType, Rows, Cols>(rows, cols)){}

    inline QuantityMatrix(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1)
            : Base(Matrix<double, Rows, Cols>(val0.value(), val1.value())){}

    inline QuantityMatrix(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2)
            : Base(Matrix<double, Rows, Cols>(val0.value(), val1.value(), val2.value())){}

    inline QuantityMatrix(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2,
                         const boost::units::quantity<Unit> &val3)
            : Base(Matrix<double, Rows, Cols>(val0.value(), val1.value(),
                                              val2.value(), val3.value())){}

    template<typename OtherDerived>
    inline QuantityMatrix(const Quantity<OtherDerived, Unit> &quantity)
            : Base(quantity) {}

    template<typename OtherDerived>
    inline QuantityMatrix(const Quantity<OtherDerived, Unit> &&quantity)
            : Base(std::move(quantity)) {}

};

}

#endif