#ifndef EIGEN_QUANTITY_MAP_H
#define EIGEN_QUANTITY_MAP_H

namespace Eigen {


template <typename ExpressionType, typename Unit>
class QuantityMap: public Quantity<Map<ExpressionType>, Unit> {
public:
    typedef Quantity<Map<ExpressionType>, Unit> Base;
    typedef typename Map<ExpressionType>::PointerArgType PointerArgType;

    QuantityMap(const Base &other)
            : Base(other) {}

    QuantityMap(Base &&other)
            : Base(std::move(other)) {}

    template<typename OtherDerived, typename OtherUnit>
    inline QuantityMap(const Quantity<Map<OtherDerived>, OtherUnit> &other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<Unit, OtherUnit>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename OtherDerived::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(other) {}

    template<typename OtherDerived, typename OtherUnit>
    inline QuantityMap(Quantity<Map<OtherDerived>, OtherUnit> &&other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<Unit,OtherUnit>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename OtherDerived::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(std::move(other)) {}

};

template <typename Scalar, int Rows, int Cols>
class Map<QuantityArray<Scalar, Rows, Cols>>: public Map<Array<Scalar, Rows, Cols>> {
public:
    typedef Map<Array<Scalar, Rows, Cols>> Base;
    using Base::PointerArgType;
    using Base::Base;

    template<class Dim, class System>
    friend const inline Quantity<Map<Array<Scalar, Rows, Cols>>, boost::units::unit<Dim, System>>
    operator*(const Map &lhs, const boost::units::unit<Dim, System> &rhs) {
        return lhs;
    }
};

template <typename Scalar, int Rows, int Cols>
class Map<QuantityMatrix<Scalar, Rows, Cols>>: public Map<Matrix<Scalar, Rows, Cols>> {
public:
    typedef Map<Matrix<Scalar, Rows, Cols>> Base;
    using Base::PointerArgType;
    using Base::Base;

    template<class Dim, class System>
    friend const inline Quantity<Map<Matrix<Scalar, Rows, Cols>>, boost::units::unit<Dim, System>>
    operator*(const Map &lhs, const boost::units::unit<Dim, System> &rhs) {
        return lhs;
    }
};



template <typename Unit, typename Scalar, int Rows, int Cols>
class Map<QuantityArray<boost::units::quantity<Unit, Scalar>, Rows, Cols>>: public QuantityMap<Array<Scalar, Rows, Cols>, Unit> {
public:
    typedef QuantityMap<Array<Scalar, Rows, Cols>, Unit> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};

template <typename Dim, typename System, int Rows, int Cols>
class Map<QuantityArray<boost::units::unit<Dim, System>, Rows, Cols>>: public QuantityMap<Array<double, Rows, Cols>, boost::units::unit<Dim, System>> {
public:
    typedef QuantityMap<Array<double, Rows, Cols>, boost::units::unit<Dim, System>> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};

template <typename Unit, typename Scalar, int Rows, int Cols>
class Map<const QuantityArray<boost::units::quantity<Unit, Scalar>, Rows, Cols>>: public QuantityMap<const Array<Scalar, Rows, Cols>, Unit> {
public:
    typedef QuantityMap<const Array<Scalar, Rows, Cols>, Unit> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};

template <typename Dim, typename System, int Rows, int Cols>
class Map<const QuantityArray<boost::units::unit<Dim, System>, Rows, Cols>>: public QuantityMap<const Array<double, Rows, Cols>, boost::units::unit<Dim, System>> {
public:
    typedef QuantityMap<const Array<double, Rows, Cols>, boost::units::unit<Dim, System>> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};



template <typename Unit, typename Scalar, int Rows, int Cols>
class Map<QuantityMatrix<boost::units::quantity<Unit,Scalar>, Rows, Cols>>: public QuantityMap<Matrix<Scalar, Rows, Cols>, Unit> {
public:
    typedef QuantityMap<Matrix<Scalar, Rows, Cols>, Unit> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};

template <typename Dim, typename System, int Rows, int Cols>
class Map<QuantityMatrix<boost::units::unit<Dim, System>, Rows, Cols>>: public QuantityMap<Matrix<double, Rows, Cols>, boost::units::unit<Dim, System>> {
public:
    typedef QuantityMap<Matrix<double, Rows, Cols>, boost::units::unit<Dim, System>> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};

template <typename Unit, typename Scalar, int Rows, int Cols>
class Map<const QuantityMatrix<boost::units::quantity<Unit, Scalar>, Rows, Cols>>: public QuantityMap<const Matrix<Scalar, Rows, Cols>, Unit> {
public:
    typedef QuantityMap<const Matrix<Scalar, Rows, Cols>, Unit> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};

template <typename Dim, typename System, int Rows, int Cols>
class Map<const QuantityMatrix<boost::units::unit<Dim, System>, Rows, Cols>>: public QuantityMap<const Matrix<double, Rows, Cols>, boost::units::unit<Dim, System>> {
public:
    typedef QuantityMap<const Matrix<double, Rows, Cols>, boost::units::unit<Dim, System>> Base;
    using typename Base::PointerArgType;
    using Base::Base;
};



}

#endif // EIGEN_QUANTITY_MAP_H
