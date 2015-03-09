#ifndef EIGEN_QUANTITY_ARRAY_H
#define EIGEN_QUANTITY_ARRAY_H

#include "Quantity.h"
#include "QuantityPlainObjectBase.h"

namespace Eigen {

template<typename Type, int Rows, int Cols>
class QuantityArray: public Array<Type, Rows, Cols> {
public:
    typedef Array<Type, Rows, Cols> Base;

    // Inherit base class constructors
    using Base::Base;

    // The code below is as recommended when inheriting from Matrix.
    // See: http://eigen.tuxfamily.org/dox/TopicCustomizingEigen.html

    // Default constructor
    inline QuantityArray() : Base() {
    }

    // This constructor allows you to construct Matrix from Eigen expressions
    template<typename OtherDerived>
    inline QuantityArray(const ArrayBase<OtherDerived> &other)
            : Base(other) {
    }

    template<typename OtherDerived, typename Unit>
    inline QuantityArray(const ArrayBase<Quantity<OtherDerived, Unit>> &other) {
        static_assert(internal::DependentBool<false,OtherDerived>::value, "Cannot copy a QuantityArray to a standard Array. Use .value() to extract raw array.");
    }

    // This method allows you to assign Eigen expressions to Matrix
    template<typename OtherDerived>
    inline QuantityArray &operator=(const ArrayBase<OtherDerived> &other) {
        this->Base::operator=(other);
        return *this;
    }

    template<typename OtherDerived, typename Unit>
    inline QuantityArray &operator=(const ArrayBase<Quantity<OtherDerived, Unit>> &other) {
        static_assert(internal::DependentBool<false,OtherDerived>::value, "Cannot assign a QuantityArray to a standard Array. Use .value() to extract raw array.");
        return *this;
    }

    // Overload * to add unit to array type
    template<class Dim, class System>
    friend const inline Quantity<Array<Type, Rows, Cols>, boost::units::unit<Dim, System>>
    operator*(const QuantityArray &lhs, const boost::units::unit<Dim, System> &rhs) {
        return lhs;
    }

};

template<typename Unit, int Rows, int Cols>
class QuantityArray<boost::units::quantity<Unit>, Rows, Cols>
        : public PlainObjectBase<Quantity<Array<typename boost::units::quantity<Unit>::value_type,Rows,Cols>, Unit>> {
public:

    typedef typename boost::units::quantity<Unit>::value_type ValueType;
    typedef PlainObjectBase<Quantity<Array<typename boost::units::quantity<Unit>::value_type,Rows,Cols>, Unit>> Base;
    typedef typename Base::Scalar Scalar;

    inline QuantityArray(){}

    inline QuantityArray(typename Base::Index size)
            : Base(Array<ValueType, Rows, Cols>(size)){}

    inline QuantityArray(typename Base::Index rows, typename Base::Index cols)
            : Base(Array<ValueType, Rows, Cols>(rows, cols)){}

    inline QuantityArray(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1)
            : Base(Array<ValueType, Rows, Cols>(val0.value(), val1.value())){}

    inline QuantityArray(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2)
            : Base(Array<ValueType, Rows, Cols>(val0.value(), val1.value(), val2.value())){}

    inline QuantityArray(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2,
                         const boost::units::quantity<Unit> &val3)
            : Base(Array<ValueType, Rows, Cols>(val0.value(), val1.value(),
                                                val2.value(),val3.value())){}

    template<typename OtherDerived>
    inline QuantityArray(const Quantity<OtherDerived, Unit> &quantity)
            : Base(quantity) {}

    template<typename OtherDerived>
    inline QuantityArray(const Quantity<OtherDerived, Unit> &&quantity)
            : Base(std::move(quantity)) {}

};


template<typename Dim, typename System, int Rows, int Cols>
class QuantityArray<boost::units::unit<Dim, System>, Rows, Cols>
        : public PlainObjectBase<Quantity<Array<double,Rows,Cols>, boost::units::unit<Dim, System>>> {
public:

    typedef boost::units::unit<Dim, System> Unit;
    typedef PlainObjectBase<Quantity<Array<double,Rows,Cols>, Unit>> Base;

    inline QuantityArray(){}

    inline QuantityArray(typename Base::Index size)
            : Base(Array<double, Rows, Cols>(size)){}

    inline QuantityArray(typename Base::Index rows, typename Base::Index cols)
            : Base(Array<double, Rows, Cols>(rows, cols)){}

    inline QuantityArray(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1)
            : Base(Array<double, Rows, Cols>(val0.value(), val1.value())){}

    inline QuantityArray(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2)
            : Base(Array<double, Rows, Cols>(val0.value(), val1.value(), val2.value())){}

    inline QuantityArray(const boost::units::quantity<Unit> &val0,
                         const boost::units::quantity<Unit> &val1,
                         const boost::units::quantity<Unit> &val2,
                         const boost::units::quantity<Unit> &val3)
            : Base(Array<double, Rows, Cols>(val0.value(), val1.value(),
                                             val2.value(), val3.value())){}

    template<typename OtherDerived>
    inline QuantityArray(const Quantity<OtherDerived, Unit> &quantity)
            : Base(quantity) {}

    template<typename OtherDerived>
    inline QuantityArray(const Quantity<OtherDerived, Unit> &&quantity)
            : Base(std::move(quantity)) {}

};

}

#endif
