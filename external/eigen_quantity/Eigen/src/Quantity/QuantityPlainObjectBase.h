#ifndef EIGEN_QUANTITY_PLAIN_OBJECT_BASE_H
#define EIGEN_QUANTITY_PLAIN_OBJECT_BASE_H

namespace Eigen {

template<typename ExpressionType, typename Unit>
class PlainObjectBase<Quantity<ExpressionType, Unit> >
        : public Quantity<ExpressionType, Unit> {
public:
    typedef typename DenseBase<ExpressionType>::Index Index;
    typedef Quantity<ExpressionType, Unit> Base;
    typedef typename ExpressionType::Scalar Scalar;
    using Base::Base;

    PlainObjectBase(){}

    inline static auto
    Map(const Scalar *data) -> const Quantity<decltype(ExpressionType::Map(data)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data);
    }

    inline static auto
    Map(Scalar *data) -> const Quantity<decltype(ExpressionType::Map(data)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data);
    }

    inline static auto
    Map(const Scalar *data, Index size) -> const Quantity<decltype(ExpressionType::Map(data, size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, size);
    }

    inline static auto
    Map(Scalar *data, Index size) -> const Quantity<decltype(ExpressionType::Map(data, size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, size);
    }

    inline static auto
    Map(const Scalar *data, Index rows, Index cols) -> const Quantity<decltype(ExpressionType::Map(data, rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, rows, cols);
    }

    inline static auto
    Map(Scalar *data, Index rows, Index cols) -> const Quantity<decltype(ExpressionType::Map(data, rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, rows, cols);
    }

    template<int Outer, int Inner>
    inline static auto
    Map(const Scalar *data, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::Map(data, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    Map(Scalar *data, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::Map(data, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    Map(const Scalar *data, Index size, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::Map(data, size, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, size, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    Map(Scalar *data, Index size, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::Map(data, size, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, size, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    Map(const Scalar *data, Index rows, Index cols, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::Map(data, rows, cols, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, rows, cols, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    Map(Scalar *data, Index rows, Index cols, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::Map(data, rows, cols, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::Map(data, rows, cols, stride);
    }




    inline static auto
    MapAligned(const Scalar *data) -> const Quantity<decltype(ExpressionType::MapAligned(data)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data);
    }

    inline static auto
    MapAligned(Scalar *data) -> const Quantity<decltype(ExpressionType::MapAligned(data)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data);
    }

    inline static auto
    MapAligned(const Scalar *data, Index size) -> const Quantity<decltype(ExpressionType::MapAligned(data, size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, size);
    }

    inline static auto
    MapAligned(Scalar *data, Index size) -> const Quantity<decltype(ExpressionType::MapAligned(data, size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, size);
    }

    inline static auto
    MapAligned(const Scalar *data, Index rows, Index cols) -> const Quantity<decltype(ExpressionType::MapAligned(data, rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, rows, cols);
    }

    inline static auto
    MapAligned(Scalar *data, Index rows, Index cols) -> const Quantity<decltype(ExpressionType::MapAligned(data, rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, rows, cols);
    }

    template<int Outer, int Inner>
    inline static auto
    MapAligned(const Scalar *data, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::MapAligned(data, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    MapAligned(Scalar *data, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::MapAligned(data, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    MapAligned(const Scalar *data, Index size, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::MapAligned(data, size, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, size, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    MapAligned(Scalar *data, Index size, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::MapAligned(data, size, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, size, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    MapAligned(const Scalar *data, Index rows, Index cols, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::MapAligned(data, rows, cols, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, rows, cols, stride);
    }

    template<int Outer, int Inner>
    inline static auto
    MapAligned(Scalar *data, Index rows, Index cols, const Stride<Outer,Inner> &stride) -> const Quantity<decltype(ExpressionType::MapAligned(data, rows, cols, stride)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a Map of the underlying data using the standard Eigen matrix/array class, and multiply it with the desired unit.");
        return ExpressionType::MapAligned(data, rows, cols, stride);
    }

};

}

#endif