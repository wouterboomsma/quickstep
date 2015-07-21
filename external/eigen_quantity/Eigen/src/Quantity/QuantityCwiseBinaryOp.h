#ifndef EIGEN_QUANTITY_CWISE_BINARY_OP_H
#define EIGEN_QUANTITY_CWISE_BINARY_OP_H

namespace Eigen {

template<typename BinaryOp, typename Lhs, typename ExpressionType, typename Unit>
class CwiseBinaryOp<BinaryOp, Lhs, const Quantity<ExpressionType, Unit>>: public Quantity<const CwiseBinaryOp<BinaryOp, Lhs, const ExpressionType>, Unit> {
public:
CwiseBinaryOp(const Lhs &lhs, const Quantity<ExpressionType, Unit> &rhs):
        Quantity<const CwiseBinaryOp<BinaryOp, Lhs, const ExpressionType>, Unit>(CwiseBinaryOp<BinaryOp, Lhs, const ExpressionType>(lhs,rhs.nested())){}
};

}

#endif