#include "Eigen/Quantity"
#include <boost/units/systems/si.hpp>
template <class Type, int Rows, int Cols> using QMatrix = Eigen::QuantityMatrix<Type, Rows, Cols>;
template <class Type, int Rows, int Cols> using QArray = Eigen::QuantityArray<Type, Rows, Cols>;

namespace Eigen {
namespace internal {
template<typename LhsScalar, typename RhsScalar>
struct scalar_product_op_deduced_return_type {
    enum {
        // TODO vectorize mixed product
                Vectorizable = is_same<LhsScalar, RhsScalar>::value && packet_traits<LhsScalar>::HasMul && packet_traits<RhsScalar>::HasMul
    };
    typedef decltype(LhsScalar() * RhsScalar()) result_type;
    EIGEN_EMPTY_STRUCT_CTOR(scalar_product_op_deduced_return_type)
    EIGEN_STRONG_INLINE const result_type

    operator()(const LhsScalar &a, const RhsScalar &b) const {
        return a * b;
    }

    template<typename Packet>
    EIGEN_STRONG_INLINE const Packet

    packetOp(const Packet &a, const Packet &b) const {
        return internal::pmul(a, b);
    }

    template<typename Packet>
    EIGEN_STRONG_INLINE const result_type

    predux(const Packet &a) const {
        return internal::predux_mul(a);
    }
};

template<typename LhsScalar, typename RhsScalar>
struct functor_traits<scalar_product_op_deduced_return_type<LhsScalar, RhsScalar> > {
    enum {
        Cost = (NumTraits<LhsScalar>::MulCost + NumTraits<RhsScalar>::MulCost) / 2, // rough estimate!
        PacketAccess = scalar_product_op_deduced_return_type< LhsScalar, RhsScalar>::Vectorizable
    };
};
}
}

int main() {

    using namespace boost::units;

    auto array = (QArray<double, 2, 2>() << 1., 2., 3., 4.).finished();
    QArray<si::length, 2, 2> length_array{array * si::meter};

#ifdef EIGEN_SHOULD_FAIL_TO_BUILD
    // Functor detects error in units return type
    length_array.binaryExpr<Eigen::internal::scalar_product_op>(length_array);
#else
    // Functor detects error in units return type
    length_array.binaryExpr<Eigen::internal::scalar_product_op_deduced_return_type>(length_array);
#endif
}