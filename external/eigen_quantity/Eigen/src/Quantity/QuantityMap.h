#ifndef EIGEN_QUANTITY_MAP_H
#define EIGEN_QUANTITY_MAP_H

namespace Eigen {

namespace internal {
template <typename TYPE>
class MapBaseSelector;

template<typename Dim, typename System>
class MapBaseSelector<boost::units::unit<Dim, System>>{
public:
    typedef boost::units::unit<Dim, System> type;
};

template<typename Dim, typename System>
class MapBaseSelector<boost::units::quantity<boost::units::unit<Dim, System>>> {
public:
    typedef boost::units::unit<Dim, System> type;
};

}

template <int Rows, int Cols, typename Unit>
class Map<QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<Array<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type> {
//class Map<QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<Array<double, Rows, Cols>>, Unit> {
public:

    typedef Quantity<Map<Array<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type> Base;
//    typedef Quantity<Map<Array<double, Rows, Cols>>, Unit> Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}
};

template <int Rows, int Cols, typename Unit>
class Map<const QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<const Array<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type > {
//class Map<const QuantityArray<Unit, Rows, Cols>>: public Quantity<Map<const Array<double, Rows, Cols>>, Unit > {
public:

    typedef Quantity<Map<const Array<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type> Base;
//    typedef Quantity<Map<const Array<double, Rows, Cols>>, Unit> Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}
};


template <int Rows, int Cols, typename Unit>
class Map<QuantityMatrix<Unit, Rows, Cols>>: public Quantity<Map<Matrix<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type > {
public:

    typedef Quantity<Map<Matrix<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type > Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}
};

template <int Rows, int Cols, typename Unit>
class Map<const QuantityMatrix<Unit, Rows, Cols>>: public Quantity<Map<const Matrix<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type > {
public:

    typedef Quantity<Map<const Matrix<double, Rows, Cols>>, typename internal::MapBaseSelector<Unit>::type > Base;

    Map(const Base &other)
            : Base(other) {}

    Map(Base &&other)
            : Base(std::move(other)) {}
};


}

#endif // EIGEN_QUANTITY_MAP_H
