#ifndef EIGEN_QUANTITY_PRODUCT_RETURN_TYPE_H
#define EIGEN_QUANTITY_PRODUCT_RETURN_TYPE_H

// Necessary to allow general matrix multiplications to work
// (this is complicated by ProductReturnType taking a default template parameter)

namespace Eigen {

namespace internal {
template<typename ExpressionType, typename Unit, typename Lhs>
struct product_type<Lhs, Quantity<ExpressionType, Unit>>: product_type<Lhs,ExpressionType> {};

template<typename ExpressionType, typename Unit, typename Rhs>
struct product_type<Quantity<ExpressionType, Unit>, Rhs>: product_type<ExpressionType, Rhs> {};
}

template<typename ExpressionType, typename Unit, typename Rhs, int ProductMode>
struct ProductReturnType<Quantity<ExpressionType, Unit>, Rhs, ProductMode> {
typedef Quantity<typename ProductReturnType<ExpressionType, Rhs, CoeffBasedProductMode>::Type, Unit> Type;
};

template<typename ExpressionType, typename Unit, typename Lhs, int ProductMode>
struct ProductReturnType<Lhs, Quantity<ExpressionType, Unit>, ProductMode> {
typedef Quantity<typename ProductReturnType<Lhs,ExpressionType, CoeffBasedProductMode>::Type, Unit> Type;
};

template<typename ExpressionType, typename Unit, typename Rhs, int ProductMode>
struct ProductReturnType<const Quantity<const ExpressionType, Unit>, Rhs, ProductMode> {
typedef Quantity<typename ProductReturnType<const ExpressionType, Rhs, CoeffBasedProductMode>::Type, Unit> Type;
};

template<typename ExpressionType, typename Unit, typename Lhs, int ProductMode>
struct ProductReturnType<Lhs, const Quantity<const ExpressionType, Unit>, ProductMode> {
typedef Quantity<typename ProductReturnType<Lhs,const ExpressionType, CoeffBasedProductMode>::Type, Unit> Type;
};


}

#endif