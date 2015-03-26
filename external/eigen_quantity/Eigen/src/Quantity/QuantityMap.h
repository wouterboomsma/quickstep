#ifndef EIGEN_QUANTITY_MAP_H
#define EIGEN_QUANTITY_MAP_H

namespace Eigen {

namespace internal {
template <typename TYPE>
class MapBaseUnitSelector;

template<typename Dim, typename System>
class MapBaseUnitSelector<boost::units::unit<Dim, System>>{
public:
    typedef boost::units::unit<Dim, System> type;
};

template<typename Dim, typename System>
class MapBaseUnitSelector<boost::units::quantity<boost::units::unit<Dim, System>>> {
public:
    typedef boost::units::unit<Dim, System> type;
};

//template <typename TYPE1, typename TYPE2>
//class MapUnitAligner {
//public:
//    typedef TYPE2 type;
//};
//
//template<typename Dim1, typename System1, typename Dim2, typename System2>
//class MapUnitAligner<boost::units::unit<Dim1, System1>, boost::units::quantity<boost::units::unit<Dim2, System2>>>{
//public:
//    typedef boost::units::unit<Dim2, System2> type;
//};
//
//template<typename Dim1, typename System1, typename Dim2, typename System2>
//class MapUnitAligner<boost::units::quantity<boost::units::unit<Dim1, System1>>, boost::units::unit<Dim2, System2>> {
//public:
//    typedef boost::units::quantity<boost::units::unit<Dim2, System2>> type;
//};

}

template <int Rows, int Cols, typename Unit>
class Map<QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<Array<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type> {
//class Map<QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<Array<double, Rows, Cols>>, Unit> {
public:

    typedef Quantity<Map<Array<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type> Base;
//    typedef Quantity<Map<Array<double, Rows, Cols>>, Unit> Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(const Quantity<Map<OtherDerived>, OtherUnit> &other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(other) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(Quantity<Map<OtherDerived>, OtherUnit> &&other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<OtherUnit,Unit>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename QuantityArray<OtherUnit, Rows, Cols>::ValueType, typename Base::Scalar>
                               >>::type* = 0)
            : Base(std::move(other)) {}
};

template<typename T1, typename T2>
void bla(T1 t1, T2 t2) {
    static_assert(Eigen::internal::DependentBool<false, T1>::value, "hello");
}

template <int Rows, int Cols, typename Unit>
class Map<const QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<const Array<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type > {
//class Map<const QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<const Array<double, Rows, Cols>>, Unit > {
public:

    typedef Quantity<Map<const Array<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type> Base;
//    typedef Quantity<Map<const Array<double, Rows, Cols>>, Unit> Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(const Quantity<Map<OtherDerived>, OtherUnit> &other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(other) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(const Quantity<Map<OtherDerived>, OtherUnit> &&other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(std::move(other)) {
    }
};


template <int Rows, int Cols, typename Unit>
class Map<QuantityMatrix<Unit, Rows, Cols>>: public Quantity<Map<Matrix<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type > {
public:

    typedef Quantity<Map<Matrix<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type > Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(const Quantity<Map<OtherDerived>, OtherUnit> &other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(other) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(Quantity<Map<OtherDerived>, OtherUnit> &&other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(std::move(other)) {}
};

template <int Rows, int Cols, typename Unit>
class Map<const QuantityMatrix<Unit, Rows, Cols>>: public Quantity<Map<const Matrix<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type > {
public:

    typedef Quantity<Map<const Matrix<double, Rows, Cols>>, typename internal::MapBaseUnitSelector<Unit>::type > Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(const Quantity<Map<OtherDerived>, OtherUnit> &other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(other) {}

    template<typename OtherDerived, typename OtherUnit>
    inline Map(const Quantity<Map<OtherDerived>, OtherUnit> &&other,
               typename boost::enable_if<
                       boost::mpl::and_<
                               typename boost::units::is_implicitly_convertible<typename internal::MapBaseUnitSelector<Unit>::type, typename internal::MapBaseUnitSelector<OtherUnit>::type>::type,
                               boost::units::detail::is_non_narrowing_conversion<typename Quantity<Map<OtherDerived>, OtherUnit>::Scalar, typename Base::Scalar>
                       >>::type* = 0)
            : Base(std::move(other)) {}
};


}

#endif // EIGEN_QUANTITY_MAP_H
