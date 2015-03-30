#ifndef EIGEN_QUANTITY_DENSE_BASE_H
#define EIGEN_QUANTITY_DENSE_BASE_H

#include <boost/units/systems/si/length.hpp>
#include "QuantityDenseCoeffsBase.h"

namespace Eigen {

template<typename ExpressionType, typename Unit>
class WithFormatQuantity;

namespace internal {
template <int N, template<class> class Functor, typename Arg, typename FuncArg>
struct ReduxTypeDeducer {
    typedef decltype(Functor<FuncArg>()(Arg{}, typename ReduxTypeDeducer<N-1, Functor, Arg, FuncArg>::type{})) type;
};

template <bool B, typename...>
struct DependentBool : std::integral_constant<bool, B> {};

template <template<class> class Functor, typename Arg, typename FuncArg>
struct ReduxTypeDeducer<Dynamic, Functor, Arg, FuncArg> {
    static_assert(DependentBool<false,Arg>::value, "Units cannot be deduced on Dynamic containers. Use m.value().redux instead.");
};

template <template<class> class Functor, typename Arg, typename FuncArg>
struct ReduxTypeDeducer<1, Functor, Arg, FuncArg> {
    typedef Arg type;
};


template <typename ExpressionType, typename UnaryOp, typename ScalarType, typename ReturnType>
struct UnaryExprReturnType {
    typedef CwiseUnaryOp<UnaryOp,const ExpressionType> type;
};

template <typename ExpressionType, typename UnaryOp, typename ScalarType, typename UnitType>
struct UnaryExprReturnType<ExpressionType, UnaryOp, ScalarType, boost::units::quantity<UnitType, ScalarType>> {
    typedef Quantity<CwiseUnaryOp<UnaryOp,const ExpressionType>, UnitType> type;
};

template <typename Lhs, typename Rhs, typename BinaryOp, typename ScalarType, typename ReturnType>
struct BinaryExprReturnType {
    typedef CwiseBinaryOp<BinaryOp,const Lhs, const Rhs> type;
};

template <typename Lhs, typename Rhs, typename BinaryOp, typename ScalarType, typename UnitType>
struct BinaryExprReturnType<Lhs, Rhs, BinaryOp, ScalarType, const boost::units::quantity<UnitType, ScalarType>> {
    typedef Quantity<CwiseBinaryOp<BinaryOp,const Lhs,const Rhs>, UnitType> type;
};

template <typename Lhs, typename Rhs, typename BinaryOp, typename ScalarType, typename UnitType>
struct BinaryExprReturnType<Lhs, Rhs, BinaryOp, ScalarType, boost::units::quantity<UnitType, ScalarType>> {
    typedef Quantity<CwiseBinaryOp<BinaryOp,const Lhs,const Rhs>, UnitType> type;
};

}




template<typename ExpressionType, typename Unit>
//class DenseBase<Quantity<ExpressionType, Unit> >: public QuantityEigenBase<ExpressionType, Unit> {
//class DenseBase<Quantity<ExpressionType, Unit> >: public DenseCoeffsBase<Quantity<ExpressionType, Unit>> {
class DenseBase<Quantity<ExpressionType, Unit> >: public QuantityDenseCoeffsBase<ExpressionType, Unit,
                                                                                 internal::accessors_level<ExpressionType>::value> {
public:
    typedef typename DenseBase<ExpressionType>::Index Index;
    typedef typename ExpressionType::Scalar Scalar;
    typedef typename ExpressionType::PacketScalar PacketScalar;
    typedef boost::units::quantity<Unit, Scalar> QuantityType;
    typedef boost::units::quantity<Unit, typename ExpressionType::CoeffReturnType> CoeffReturnType;

    // Blockmethods typedefs
    /** \internal expression type of a column */
    typedef Quantity<typename ExpressionType::ColXpr, Unit> ColXpr;
    typedef Quantity<typename ExpressionType::ConstColXpr, Unit> ConstColXpr;
    /** \internal expression type of a row */
    typedef Quantity<typename ExpressionType::RowXpr, Unit> RowXpr;
    typedef Quantity<typename ExpressionType::ConstRowXpr, Unit> ConstRowXpr;
    /** \internal expression type of a block of whole columns */
    typedef Quantity<typename ExpressionType::ColsBlockXpr, Unit> ColsBlockXpr;
    typedef Quantity<typename ExpressionType::ConstColsBlockXpr, Unit> ConstColsBlockXpr;
    /** \internal expression type of a block of whole rows */
    typedef Quantity<typename ExpressionType::RowsBlockXpr, Unit> RowsBlockXpr;
    typedef Quantity<typename ExpressionType::ConstRowsBlockXpr, Unit> ConstRowsBlockXpr;

    inline CoeffReturnType coeff(Index rowId, Index colId) const
    {
        return this->nested().coeff(rowId, colId);
    }

    inline Scalar& coeffRef(Index rowId, Index colId)
    {
        return this->nested().const_cast_derived().coeffRef(rowId, colId);
    }

    inline const Scalar& coeffRef(Index rowId, Index colId) const
    {
        return this->nested().const_cast_derived().coeffRef(rowId, colId);
    }

    inline CoeffReturnType coeff(Index index) const
    {
        return this->nested().coeff(index);
    }

    inline Scalar& coeffRef(Index index)
    {
        return this->nested().const_cast_derived().coeffRef(index);
    }

    inline const Scalar& coeffRef(Index index) const
    {
        return this->nested().const_cast_derived().coeffRef(index);
    }

    template<int LoadMode>
    inline const PacketScalar packet(Index rowId, Index colId) const
    {
        return this->nested().template packet<LoadMode>(rowId, colId);
    }

    template<int LoadMode>
    inline void writePacket(Index rowId, Index colId, const PacketScalar& val)
    {
        this->nested().const_cast_derived().template writePacket<LoadMode>(rowId, colId, val);
    }

    template<int LoadMode>
    inline const PacketScalar packet(Index index) const
    {
        return this->nested().template packet<LoadMode>(index);
    }

    template<int LoadMode>
    inline void writePacket(Index index, const PacketScalar& val)
    {
        this->nested().const_cast_derived().template writePacket<LoadMode>(index, val);
    }

    inline ExpressionType &value() {
        return this->nested();
    }

    inline const ExpressionType &value() const {
        return this->nested();
    }

    inline bool all() const {
        return this->nested().all();
    }

    inline bool allFinite() const {
        return this->nested().allFinite();
    }

    inline bool any() const {
        return this->nested().any();
    }

    inline Quantity<Block<ExpressionType>, Unit>
    block(Index startRow, Index startCol, Index blockRows, Index blockCols) {
        return this->nested().block(startRow, startCol, blockRows, blockCols);
    }

    inline const Quantity<const Block<const ExpressionType>, Unit>
    block(Index startRow, Index startCol, Index blockRows, Index blockCols) const {
        return this->nested().block(startRow, startCol, blockRows, blockCols);
    }

    template <int BlockRows, int BlockCols>
    inline Quantity<Block<ExpressionType, BlockRows, BlockCols>, Unit>
    block(Index startRow, Index startCol) {
        return this->nested().block<BlockRows, BlockCols>(startRow, startCol);
    }

    template <int BlockRows, int BlockCols>
    inline const Quantity<const Block<const ExpressionType, BlockRows, BlockCols>, Unit>
    block(Index startRow, Index startCol) const {
        return this->nested().block<BlockRows, BlockCols>(startRow, startCol);
    }

    template <int BlockRows, int BlockCols>
    inline Quantity<Block<ExpressionType, BlockRows, BlockCols>, Unit>
    block(Index startRow, Index startCol, Index blockRows, Index blockCols) {
        return this->nested().block<BlockRows, BlockCols>(startRow, startCol, blockRows, blockCols);
    }

    template <int BlockRows, int BlockCols>
    inline const Quantity<const Block<const ExpressionType, BlockRows, BlockCols>, Unit>
    block(Index startRow, Index startCol, Index blockRows, Index blockCols) const {
        return this->nested().block<BlockRows, BlockCols>(startRow, startCol, blockRows, blockCols);
    }


    inline const Quantity<Block<ExpressionType>, Unit>
    bottomLeftCorner(Index cRows, Index cCols) {
        return this->nested().bottomLeftCorner(cRows, cCols);
    }

    inline const Quantity<const Block<const ExpressionType>, Unit>
    bottomLeftCorner(Index cRows, Index cCols) const {
        return this->nested().bottomLeftCorner(cRows, cCols);
    }

    template <int CRows, int CCols>
    inline const Quantity<Block<ExpressionType, CRows, CCols>, Unit>
    bottomLeftCorner() {
        return this->nested().template bottomLeftCorner<CRows, CCols>();
    }

    template <int CRows, int CCols>
    inline const Quantity<const Block<const ExpressionType, CRows, CCols>, Unit>
    bottomLeftCorner() const {
        return this->nested().template bottomLeftCorner<CRows, CCols>();
    }

    template <int CRows, int CCols>
    inline const Quantity<Block<ExpressionType, CRows, CCols>, Unit>
    bottomLeftCorner(Index cRows, Index cCols) {
        return this->nested().bottomLeftCorner<CRows, CCols>(cRows, cCols);
    }

    template <int CRows, int CCols>
    inline const Quantity<const Block<const ExpressionType, CRows, CCols>, Unit>
    bottomLeftCorner(Index cRows, Index cCols) const {
        return this->nested().bottomLeftCorner<CRows, CCols>(cRows, cCols);
    }


    inline const Quantity<Block<ExpressionType>, Unit>
    bottomRightCorner(Index cRows, Index cCols) {
        return this->nested().bottomRightCorner(cRows, cCols);
    }

    inline const Quantity<const Block<const ExpressionType>, Unit>
    bottomRightCorner(Index cRows, Index cCols) const {
        return this->nested().bottomRightCorner(cRows, cCols);
    }

    template <int CRows, int CCols>
    inline const Quantity<Block<ExpressionType, CRows, CCols>, Unit>
    bottomRightCorner() {
        return this->nested().template bottomRightCorner<CRows, CCols>();
    }

    template <int CRows, int CCols>
    inline const Quantity<const Block<const ExpressionType, CRows, CCols>, Unit>
    bottomRightCorner() const {
        return this->nested().template bottomRightCorner<CRows, CCols>();
    }

    template <int CRows, int CCols>
    inline const Quantity<Block<ExpressionType, CRows, CCols>, Unit>
    bottomRightCorner(Index cRows, Index cCols) {
        return this->nested().bottomRightCorner<CRows, CCols>(cRows, cCols);
    }

    template <int CRows, int CCols>
    inline const Quantity<const Block<const ExpressionType, CRows, CCols>, Unit>
    bottomRightCorner(Index cRows, Index cCols) const {
        return this->nested().bottomRightCorner<CRows, CCols>(cRows, cCols);
    }


    inline const Quantity<Block<ExpressionType, Dynamic, internal::traits<ExpressionType>::ColsAtCompileTime, ExpressionType::IsRowMajor>, Unit>
    bottomRows (Index n) {
        return this->nested().bottomRows(n);
    }

    inline const Quantity<const Block<const ExpressionType, Dynamic, internal::traits<ExpressionType>::ColsAtCompileTime, ExpressionType::IsRowMajor>, Unit>
    bottomRows (Index n) const {
        return this->nested().bottomRows(n);
    }

    template <int N>
    inline const Quantity<Block<ExpressionType, N, internal::traits<ExpressionType>::ColsAtCompileTime, ExpressionType::IsRowMajor>, Unit>
    bottomRows (Index n=N) {
        return this->nested().bottomRows<N>(n);
    }

    template <int N>
    inline const Quantity<const Block<const ExpressionType, N, internal::traits<ExpressionType>::ColsAtCompileTime, ExpressionType::IsRowMajor>, Unit>
    bottomRows (Index n=N) const {
        return this->nested().bottomRows<N>(n);
    }


    template<typename NewType>
    inline auto
    cast() const -> const Quantity<decltype(this->nested().template cast<NewType>()), Unit> {
        return this->nested().template cast<NewType>();
    }


    inline auto
    col(Index i) -> Quantity<decltype(this->nested().col(i)), Unit> {
        return this->nested().col(i);
    }

    inline auto
    col(Index i) const -> const Quantity<decltype(this->nested().col(i)), Unit> {
        return this->nested().col(i);
    }

    inline auto
    colwise() -> const Quantity<decltype(this->nested().colwise()), Unit> {
        return this->nested().colwise();
    }

    inline auto
    colwise() const -> const Quantity<decltype(this->nested().colwise()), Unit> {
        return this->nested().colwise();
    }

    inline auto
    conjugate() const -> const Quantity<decltype(this->nested().conjugate()), Unit> {
        return this->nested().conjugate();
    }

    inline void
    conservativeResize (Index nbRows, Index nbCols) {
        this->nested().conservativeResize(nbRows, nbCols);
    }

    inline void
    conservativeResize (Index nbRows, NoChange_t flag) {
        this->nested().conservativeResize(nbRows, flag);
    }

    inline void
    conservativeResize(NoChange_t flag, Index nbCols) {
        this->nested().conservativeResize(flag, nbCols);
    }

    inline void
    conservativeResize(Index size) {
        this->nested().conservativeResize(size);
    }

    template <typename OtherDerived>
    inline void
    conservativeResizeLike(const DenseBase<Quantity<OtherDerived, Unit>> &other) {
        this->nested().conservativeResizeLike(other.nested());
    }

    inline Index count() const {
        return this->nested().count();
    }

    inline auto
    cwiseAbs() const -> const Quantity<decltype(this->nested().cwiseAbs()), Unit> {
        return this->nested().cwiseAbs();
    }

    inline auto
    cwiseAbs2() const -> const Quantity<decltype(this->nested().cwiseAbs2()), Unit> {
        return this->nested().cwiseAbs2();
    }

    template <typename OtherDerived>
    inline auto
    cwiseEqual(const DenseBase<Quantity<OtherDerived, Unit>> &other) const -> const Quantity<decltype(this->nested().cwiseEqual(other.nested())), Unit> {
        return this->nested().cwiseEqual(other.nested());
    }

    inline auto
    cwiseEqual(const Scalar &scalar) const -> const Quantity<decltype(this->nested().cwiseEqual(scalar)), Unit> {
        return this->nested().cwiseEqual(scalar);
    }

    inline auto
    cwiseInverse() const -> const Quantity<decltype(this->nested().cwiseInverse()), Unit> {
        return this->nested().cwiseInverse();
    }

    template <typename OtherDerived>
    inline auto
    cwiseMax(const DenseBase<Quantity<OtherDerived, Unit>> &other) const -> const Quantity<decltype(this->nested().cwiseInverse(other.nested())), Unit> {
        return this->nested().cwiseMax(other.nested());
    }

    inline auto
    cwiseMax(const Scalar &scalar) const -> const Quantity<decltype(this->nested().cwiseMax(scalar)), Unit> {
        return this->nested().cwiseMax(scalar);
    }

    template <typename OtherDerived>
    inline auto
    cwiseMin(const DenseBase<Quantity<OtherDerived, Unit>> &other) const -> const Quantity<decltype(this->nested().cwiseInverse(other.nested())), Unit> {
        return this->nested().cwiseMin(other.nested());
    }

    inline auto
    cwiseMin(const Scalar &scalar) const -> const Quantity<decltype(this->nested().cwiseMin(scalar)), Unit> {
        return this->nested().cwiseMin(scalar);
    }

    template <typename OtherDerived>
    inline auto
    cwiseNotEqual(const DenseBase<Quantity<OtherDerived, Unit>> &other) const -> const Quantity<decltype(this->nested().cwiseNotEqual(other.nested())), Unit> {
        return this->nested().cwiseNotEqual(other.nested());
    }

    template <typename OtherDerived, typename OtherUnit>
    inline auto
    cwiseProduct(const DenseBase<Quantity<OtherDerived, OtherUnit>> &other) const -> const Quantity<decltype(this->nested().cwiseProduct(other.nested())),
                                                                                                  decltype(Unit()*OtherUnit())> {
        return this->nested().cwiseProduct(other.nested());
    }

    template <typename OtherDerived, typename OtherUnit>
    inline auto
    cwiseQuotient(const DenseBase<Quantity<OtherDerived, Unit>> &other) const -> const Quantity<decltype(this->nested().cwiseQuotient(other.nested())),
                                                                                                decltype(Unit()/OtherUnit())> {
        return this->nested().cwiseQuotient(other.nested());
    }

    inline auto
    cwiseSqrt() const -> const Quantity<decltype(this->nested().cwiseSqrt()),
                                        typename decltype(boost::units::sqrt(boost::units::quantity<Unit>()))::unit_type> {
        return this->nested().cwiseQuotient();
    }

    inline Scalar*
    data() {
        return this->nested().data();
    }

    inline const Scalar*
    data() const {
        return this->nested().data();
    }

    inline auto
    eval() const -> const Quantity<decltype(this->nested().eval()), Unit> {
        return this->nested().eval();
    }

    inline void
    fill(const boost::units::quantity<Unit, Scalar> &quantity) const {
        return this->nested().fill(quantity.value());
    }

    template<unsigned int Added,unsigned int Removed>
    inline const Quantity<Flagged<ExpressionType, Added, Removed>, Unit>
    flagged() const {
        return this->nested().template flagged<Added, Removed>();
    }

    inline const WithFormatQuantity<ExpressionType, Unit> format(const IOFormat& fmt) const;

    inline bool hasNaN() const {
        return this->nested().hasNaN();
    }

    inline auto
    head(Index n) -> const Quantity<decltype(this->nested().head(n)),
                                          Unit> {
        return this->nested().head(n);
    }

    inline auto
    head(Index n) const -> const Quantity<decltype(this->nested().head(n)),
                                          Unit> {
        return this->nested().head(n);
    }

    template <int N>
    inline auto
    head(Index n) -> const Quantity<decltype(this->nested().template head<N>()),
                                          Unit> {
        return this->nested().template head<N>();
    }

    template <int N>
    inline auto
    head(Index n) const -> const Quantity<decltype(this->nested().template head<N>()),
                                          Unit> {
        return this->nested().template head<N>();
    }

    inline auto
    imag() -> const Quantity<decltype(this->nested().imag()),
                              Unit> {
        return this->nested().imag();
    }

    inline auto
    imag() const -> const Quantity<decltype(this->nested().imag()),
                                   Unit> {
        return this->nested().imag();
    }

    inline Index innerSize() const {
        return this->nested().innerSize();
    }

    template <typename OtherDerived>
    inline bool
    isApprox(const DenseBase<Quantity<OtherDerived, Unit>> &other,
             const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) const {
        return this->nested().isApprox(other.nested(), prec);
    }

    inline bool
    isApproxToConstant(const Scalar &other,
                       const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) const {
        return this->nested().isApproxToConstant(other, prec);
    }

    inline bool
    isConstant(const Scalar &other,
               const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) const {
        return this->nested().isConstant(other, prec);
    }

    template <typename OtherDerived>
    inline bool
    isMuchSmallerThan(const DenseBase<Quantity<OtherDerived, Unit>> &other,
                      const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) const {
        return this->nested().isApprox(other.nested(), prec);
    }

    inline bool
    isMuchSmallerThan(const typename NumTraits<Scalar>::Real &scalar,
                      const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) const {
        return this->nested().isMuchSmallerThan(scalar, prec);
    }

    inline bool
    isOnes(const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) {
        return this->nested().isOnes(prec);
    }

    inline bool
    isZero(const typename ExpressionType::RealScalar &prec = NumTraits<Scalar>::dummy_precision()) {
        return this->nested().isZero(prec);
    }

    template<typename OtherDerived>
    inline auto
    lazyAssign(const DenseBase<Quantity<OtherDerived, Unit>>& other) -> const Quantity<decltype(this->nested().template lazyAssign<OtherDerived>(other.nested())), Unit> {
        return this->nested().template lazyAssign<OtherDerived>(other.nested());
    }

    inline auto
    leftCols(Index n) -> const Quantity<decltype(this->nested().leftCols(n)),
                                        Unit> {
        return this->nested().leftCols(n);
    }

    inline auto
    leftCols(Index n) const -> const Quantity<decltype(this->nested().leftCols(n)),
                                              Unit> {
        return this->nested().leftCols(n);
    }

    template <int N>
    inline auto
    leftCols(Index n=N) -> const Quantity<decltype(this->nested().template leftCols<N>()),
                                          Unit> {
        return this->nested().template leftCols<N>();
    }

    template <int N>
    inline auto
    leftCols(Index n=N) const -> const Quantity<decltype(this->nested().template leftCols<N>()),
                                                Unit> {
        return this->nested().template leftCols<N>();
    }

    inline auto
    maxCoeff() const -> boost::units::quantity<Unit,Scalar> {
        return boost::units::quantity<Unit,Scalar>::from_value(this->nested().maxCoeff());
    }

    template <typename IndexType>
    inline auto
    maxCoeff(IndexType *row, IndexType *col) const -> boost::units::quantity<Unit,Scalar> {
        return boost::units::quantity<Unit,Scalar>::from_value(this->nested().template maxCoeff<IndexType>(row, col));
    }

    template <typename IndexType>
    inline auto
    maxCoeff(IndexType *index) const -> boost::units::quantity<Unit,Scalar> {
        return boost::units::quantity<Unit,Scalar>::from_value(this->nested().template maxCoeff<IndexType>(index));
    }

    inline Scalar mean() const {
        return this->nested().mean();
    }

    inline auto
    middleCols(Index startCol, Index numCols) -> const Quantity<decltype(this->nested().middleCols(startCol, numCols)),
                                                                Unit> {
        return this->nested().middleCols(startCol, numCols);
    }

    inline auto
    middleCols(Index startCol, Index numCols) const -> const Quantity<decltype(this->nested().middleCols(startCol, numCols)),
                                                                      Unit> {
        return this->nested().middleCols(startCol, numCols);
    }

    template<int N>
    inline auto
    middleCols(Index startCol, Index n=N) -> const Quantity<decltype(this->nested().template middleCols<N>(startCol, n)),
                                                            Unit> {
        return this->nested().template middleCols<N>(startCol, n);
    }

    template<int N>
    inline auto
    middleCols(Index startCol, Index n=N) const -> const Quantity<decltype(this->nested().template middleCols<N>(startCol, n)),
                                                                  Unit> {
        return this->nested().template middleCols<N>(startCol, n);
    }


    inline auto
    middleRows(Index startRow, Index numRows) -> const Quantity<decltype(this->nested().middleRows(startRow, numRows)),
                                                                Unit> {
        return this->nested().middleRows(startRow, numRows);
    }

    inline auto
    middleRows(Index startRow, Index numRows) const -> const Quantity<decltype(this->nested().middleRows(startRow, numRows)),
                                                                      Unit> {
        return this->nested().middleRows(startRow, numRows);
    }

    template<int N>
    inline auto
    middleRows(Index startRow, Index n=N) -> const Quantity<decltype(this->nested().template middleRows<N>(startRow, n)),
                                                            Unit> {
        return this->nested().template middleRows<N>(startRow, n);
    }

    template<int N>
    inline auto
    middleRows(Index startRow, Index n=N) const -> const Quantity<decltype(this->nested().template middleRows<N>(startRow, n)),
                                                                  Unit> {
        return this->nested().template middleRows<N>(startRow, n);
    }

    inline auto
    minCoeff() const -> boost::units::quantity<Unit,Scalar> {
        return boost::units::quantity<Unit,Scalar>::from_value(this->nested().minCoeff());
    }

    template <typename IndexType>
    inline auto
    minCoeff(IndexType *row, IndexType *col) const -> boost::units::quantity<Unit,Scalar> {
        return boost::units::quantity<Unit,Scalar>::from_value(this->nested().template minCoeff<IndexType>(row, col));
    }

    template <typename IndexType>
    inline auto
    minCoeff(IndexType *index) const -> boost::units::quantity<Unit,Scalar> {
        return boost::units::quantity<Unit,Scalar>::from_value(this->nested().template minCoeff<IndexType>(index));
    }

    inline auto
    nestByValue() const -> const Quantity<decltype(this->nested().nestByValue()),
                                          Unit> {
        return this->nested().nestByValue();
    }

    inline Index
    nonZeros() const {
        return this->nested().nonZeros();
    }

    inline auto
    operator<<(const boost::units::quantity<Unit> &quantity) -> Quantity<CommaInitializer< ExpressionType >, Unit> {
        return this->nested().operator<<(quantity.value());
    }

    template<typename OtherDerived>
    inline auto
    operator<<(const DenseBase<Quantity<OtherDerived, Unit>> &other) -> Quantity<CommaInitializer<ExpressionType>,Unit> {
        return this->nested().operator<<(other.nested());
    }

    template <typename OtherUnit>
    auto operator*=(const boost::units::quantity<OtherUnit> &quantity) -> Quantity<ExpressionType, decltype(Unit()*OtherUnit())> {
        return this->nested().operator*=(quantity.value());
    }

    template<class OtherUnit>
    friend inline auto
    operator*(const boost::units::quantity<OtherUnit> &lhs, const DenseBase<Quantity<ExpressionType, Unit>> &rhs) -> const Quantity<const CwiseUnaryOp<internal::scalar_multiple_op<Scalar>, const ExpressionType>, decltype(Unit()*OtherUnit())>{
        return lhs.value()*rhs.nested();
    }

    inline Index outerSize() const {
        return this->nested().outerSize();
    }

    inline auto
    prod() const -> boost::units::quantity<decltype(boost::units::pow<ExpressionType::SizeAtCompileTime>(Unit()))> {
        return boost::units::quantity<decltype(boost::units::pow<ExpressionType::SizeAtCompileTime>(Unit()))>::from_value(this->nested().prod());
    }

    inline auto
    real() -> const Quantity<decltype(this->nested().real()),
                             Unit> {
        return this->nested().real();
    }

    inline auto
    real() const -> const Quantity<decltype(this->nested().real()),
                                   Unit> {
        return this->nested().real();
    }

    template <template<class> class Func, typename FuncQuantityType=QuantityType>
    inline auto
    redux(const Func<FuncQuantityType> &func={}) const -> typename internal::ReduxTypeDeducer<ExpressionType::SizeAtCompileTime,
                                                                                              Func, QuantityType,
                                                                                              FuncQuantityType>::type {
        return internal::ReduxTypeDeducer<ExpressionType::SizeAtCompileTime,
                                          Func, QuantityType,
                                          FuncQuantityType>::type::from_value(this->nested().redux(Func<Scalar>()));
    }

    template <int RowFactor, int ColFactor>
    inline auto
    replicate() const -> const Quantity<decltype(this->nested().template replicate<RowFactor, ColFactor>()),
                                        Unit> {
        return this->nested().template replicate<RowFactor, ColFactor>();
    }

    inline auto
    replicate(Index rowFactor, Index colFactor) const -> const Quantity<decltype(this->nested().replicate(rowFactor, colFactor)),
                                        Unit> {
        return this->nested().replicate(rowFactor, colFactor);
    }

    inline void
    resize (Index nbRows, Index nbCols) {
        this->nested().resize(nbRows, nbCols);
    }

    inline void
    resize (Index size) {
        this->nested().resize(size);
    }

    inline void
    resize (NoChange_t flag, Index nbCols) {
        this->nested().resize(flag, nbCols);
    }

    inline void
    resize (Index nbRows, NoChange_t flag) {
        this->nested().resize(nbRows, flag);
    }

    template<typename OtherDerived>
    inline void
    resizeLike(const EigenBase<OtherDerived> &other) {
        this->nested().resize(other);
    }

    inline auto
    reverse() -> const Quantity<decltype(this->nested().reverse()), Unit> {
        return this->nested().reverse();
    }

    inline auto
    reverse() const -> const Quantity<decltype(this->nested().reverse()), Unit> {
        return this->nested().reverse();
    }

    inline void
    reverseInPlace() {
        this->nested().reverseInPlace();
    }

    inline auto
    rightCols(Index n) -> const Quantity<decltype(this->nested().rightCols(n)),
                                        Unit> {
        return this->nested().rightCols(n);
    }

    inline auto
    rightCols(Index n) const -> const Quantity<decltype(this->nested().rightCols(n)),
                                              Unit> {
        return this->nested().rightCols(n);
    }

    template <int N>
    inline auto
    rightCols(Index n=N) -> const Quantity<decltype(this->nested().template rightCols<N>()),
                                        Unit> {
        return this->nested().template rightCols<N>();
    }

    template <int N>
    inline auto
    rightCols(Index n=N) const -> const Quantity<decltype(this->nested().template rightCols<N>()),
                                              Unit> {
        return this->nested().template rightCols<N>();
    }

    inline auto
    row(Index i) -> Quantity<decltype(this->nested().row(i)), Unit> {
        return this->nested().row(i);
    }

    inline auto
    row(Index i) const -> const Quantity<decltype(this->nested().row(i)), Unit> {
        return this->nested().row(i);
    }

    inline auto
    rowwise() -> const Quantity<decltype(this->nested().rowwise()), Unit> {
        return this->nested().rowwise();
    }

    inline auto
    rowwise() const -> const Quantity<decltype(this->nested().rowwise()), Unit> {
        return this->nested().rowwise();
    }

    inline auto
    segment(Index start, Index n) -> const Quantity<decltype(this->nested().segment(start, n)),
                                                    Unit> {
        return this->nested().segment(start, n);
    }

    inline auto
    segment(Index start, Index n) const -> const Quantity<decltype(this->nested().segment(start, n)),
                                                          Unit> {
        return this->nested().segment(start, n);
    }

    template <int N>
    inline auto
    segment(Index start, Index n=N) -> const Quantity<decltype(this->nested().template segment<N>(start, n)),
                                                      Unit> {
        return this->nested().template segment<N>(start, n);
    }

    template <int N>
    inline auto
    segment(Index start, Index n=N) const -> const Quantity<decltype(this->nested().template segment<N>(start, n)),
                                                            Unit> {
        return this->nested().template segment<N>(start, n);
    }

    template <typename ThenDerived, typename ElseDerived>
    inline auto
    select(const DenseBase<Quantity<ThenDerived,Unit>> &thenMatrix,
           const DenseBase<Quantity<ElseDerived,Unit>> &elseMatrix) const -> const Quantity<decltype(this->nested().select(thenMatrix.nested(), elseMatrix.nested())),
                                                                                            Unit> {
        return this->nested().select(thenMatrix.nested(), elseMatrix.nested());
    }

    template <typename ThenDerived>
    inline auto
    select(const DenseBase<Quantity<ThenDerived,Unit>> &thenMatrix,
           const boost::units::quantity<Unit, typename ThenDerived::Scalar> &elseQuantity) const -> const Quantity<decltype(this->nested().select(thenMatrix.nested(), elseQuantity)),
                                                                                                                   Unit> {
        return this->nested().select(thenMatrix, elseQuantity.value());
    }

    template <typename ThenDerived>
    inline auto
    select(const boost::units::quantity<Unit, typename ThenDerived::Scalar> &thenQuantity,
           const DenseBase<Quantity<ThenDerived,Unit>> &elseMatrix) const -> const Quantity<decltype(this->nested().select(thenQuantity, elseMatrix)),
                                                                                            Unit> {
        return this->nested().select(thenQuantity.value(), elseMatrix);
    }

    inline Quantity<ExpressionType, Unit>
    setConstant(const boost::units::quantity<Unit, Scalar> &quantity) {
        return (this->nested().setConstant(quantity.value()));
    }

    inline Quantity<ExpressionType, Unit>
    setLinSpaced(Index size, const boost::units::quantity<Unit, Scalar> &low, const boost::units::quantity<Unit, Scalar> &high) {
        return (this->nested().setLinSpaced(size, low.value(), high.value()));
    }

    inline Quantity<ExpressionType, Unit>
    setLinSpaced(const boost::units::quantity<Unit, Scalar> &low, const boost::units::quantity<Unit, Scalar> &high) {
        return (this->nested().setLinSpaced(low.value(), high.value()));
    }

    inline Quantity<ExpressionType, Unit>
    setOnes() {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, initialize a matris using a standard Eigen matrix/array class, and multiply it with the desired unit.");
        return (this->nested().setOnes());
    }

    inline Quantity<ExpressionType, Unit>
    setRandom() {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, initialize a matris using a standard Eigen matrix/array class, and multiply it with the desired unit.");
        return (this->nested().setRandom());
    }

    inline Quantity<ExpressionType, Unit>
    setZero() {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, initialize a matris using a standard Eigen matrix/array class, and multiply it with the desired unit.");
        return (this->nested().setZero());
    }

    inline auto
    sum() const -> boost::units::quantity<Unit, Scalar> {
        return boost::units::quantity<Unit, Scalar>::from_value(this->nested().sum());
    }

    template<typename OtherDerived>
    inline void
    swap(const DenseBase<Quantity<OtherDerived, Unit>> &other) {
        this->nested().swap(other.nested());
    }

    inline auto
    tail(Index n) -> const Quantity<decltype(this->nested().tail(n)),
                                    Unit> {
        return this->nested().tail(n);
    }

    inline auto
    tail(Index n) const -> const Quantity<decltype(this->nested().tail(n)),
                                          Unit> {
        return this->nested().tail(n);
    }

    template <int N>
    inline auto
    tail(Index n=N) -> const Quantity<decltype(this->nested().template tail<N>(n)),
                                      Unit> {
        return this->nested().template tail<N>(n);
    }

    template <int N>
    inline auto
    tail(Index n=N) const -> const Quantity<decltype(this->nested().template tail<N>(n)),
                                          Unit> {
        return this->nested().template tail<N>(n);
    }

    inline auto
    topLeftCorner(Index cRows, Index cCols) -> const Quantity<decltype(this->nested().topLeftCorner(cRows, cCols)),
                                                              Unit> {
        return this->nested().topLeftCorner(cRows, cCols);
    }

    inline auto
    topLeftCorner(Index cRows, Index cCols) const -> const Quantity<decltype(this->nested().topLeftCorner(cRows, cCols)),
                                                                    Unit> {
        return this->nested().topLeftCorner(cRows, cCols);
    }

    template<int CRows, int CCols>
    inline auto
    topLeftCorner() -> const Quantity<decltype(this->nested().template topLeftCorner<CRows, CCols>()),
                                      Unit> {
        return this->nested().template topLeftCorner<CRows, CCols>();
    }

    template<int CRows, int CCols>
    inline auto
    topLeftCorner() const -> const Quantity<decltype(this->nested().template topLeftCorner<CRows, CCols>()),
                                            Unit> {
        return this->nested().template topLeftCorner<CRows, CCols>();
    }

    template<int CRows, int CCols>
    inline auto
    topLeftCorner(Index cRows=CRows, Index cCols=CCols) -> const Quantity<decltype(this->nested().template topLeftCorner<CRows, CCols>(cRows, cCols)),
                                                                          Unit> {
        return this->nested().template topLeftCorner<CRows, CCols>(cRows, cCols);
    }

    template<int CRows, int CCols>
    inline auto
    topLeftCorner(Index cRows=CRows, Index cCols=CCols) const -> const Quantity<decltype(this->nested().template topLeftCorner<CRows, CCols>(cRows, cCols)),
                                                                                Unit> {
        return this->nested().template topLeftCorner<CRows, CCols>(cRows, cCols);
    }

    inline auto
    topRightCorner(Index cRows, Index cCols) -> const Quantity<decltype(this->nested().topRightCorner(cRows, cCols)),
                                                              Unit> {
        return this->nested().topRightCorner(cRows, cCols);
    }

    inline auto
    topRightCorner(Index cRows, Index cCols) const -> const Quantity<decltype(this->nested().topRightCorner(cRows, cCols)),
                                                                    Unit> {
        return this->nested().topRightCorner(cRows, cCols);
    }

    template<int CRows, int CCols>
    inline auto
    topRightCorner() -> const Quantity<decltype(this->nested().template topRightCorner<CRows, CCols>()),
                                      Unit> {
        return this->nested().template topRightCorner<CRows, CCols>();
    }

    template<int CRows, int CCols>
    inline auto
    topRightCorner() const -> const Quantity<decltype(this->nested().template topRightCorner<CRows, CCols>()),
                                            Unit> {
        return this->nested().template topRightCorner<CRows, CCols>();
    }

    template<int CRows, int CCols>
    inline auto
    topRightCorner(Index cRows=CRows, Index cCols=CCols) -> const Quantity<decltype(this->nested().template topRightCorner<CRows, CCols>(cRows, cCols)),
                                                                          Unit> {
        return this->nested().template topRightCorner<CRows, CCols>(cRows, cCols);
    }

    template<int CRows, int CCols>
    inline auto
    topRightCorner(Index cRows=CRows, Index cCols=CCols) const -> const Quantity<decltype(this->nested().template topRightCorner<CRows, CCols>(cRows, cCols)),
                                                                                Unit> {
        return this->nested().template topRightCorner<CRows, CCols>(cRows, cCols);
    }

    inline auto
    topRows(Index n) -> const Quantity<decltype(this->nested().topRows(n)),
                                       Unit> {
        return this->nested().topRows(n);
    }

    inline auto
    topRows(Index n) const -> const Quantity<decltype(this->nested().topRows(n)),
                                             Unit> {
        return this->nested().topRows(n);
    }

    template<int N>
    inline auto
    topRows(Index n=N) -> const Quantity<decltype(this->nested().topRows(n)),
                                       Unit> {
        return this->nested().topRows(n);
    }

    template<int N>
    inline auto
    topRows(Index n=N) const -> const Quantity<decltype(this->nested().topRows(n)),
                                               Unit> {
        return this->nested().topRows(n);
    }

    inline auto
    transpose() -> const Quantity<decltype(this->nested().transpose()),
                                  Unit> {
        return this->nested().transpose();
    }

    inline auto
    transpose() const -> const Quantity<decltype(this->nested().transpose()),
                                        Unit> {
        return this->nested().tranpose();
    }

    inline void
    transposeInPlace() {
        this->nested().transposeInPlace();
    }

    template <typename Visitor>
    inline void
    visit(Visitor &func) const {
        static_assert(internal::DependentBool<false,Visitor>::value, "visit() is not supported for Quantity matrices and array since correct units cannot be ensured. Use m.value.visit() instead.");
    }


    inline static auto
    Constant(Index rows, Index cols, const QuantityType &quantity) -> const Quantity<decltype(ExpressionType::Constant(rows, cols, quantity.value())), Unit> {
        return ExpressionType::Constant(rows, cols, quantity.value());
    }

    inline static auto
    Constant(Index size, const QuantityType &quantity) -> const Quantity<decltype(ExpressionType::Constant(size, quantity.value())), Unit> {
        return ExpressionType::Constant(size, quantity.value());
    }

    inline static auto
    Constant(const QuantityType &quantity) -> const Quantity<decltype(ExpressionType::Constant(quantity.value())), Unit> {
        return ExpressionType::Constant(quantity.value());
    }

    inline static auto
    LinSpaced(Sequential_t flag, Index size, const QuantityType &low, const QuantityType &high)
    -> const Quantity<decltype(ExpressionType::LinSpaced(flag, size, low.value(), high.value())), Unit> {
        return ExpressionType::LinSpaced(flag, size, low.value().value(), high.value());
    }

    inline static auto
    LinSpaced(Index size, const QuantityType &low, const QuantityType &high)
    -> const Quantity<decltype(ExpressionType::LinSpaced(size, low.value(), high.value())), Unit> {
        return ExpressionType::LinSpaced(size, low.value(), high.value());
    }

    inline static auto
    LinSpaced(Sequential_t flag, const QuantityType &low, const QuantityType &high)
    -> const Quantity<decltype(ExpressionType::LinSpaced(flag, low.value(), high.value())), Unit> {
        return ExpressionType::LinSpaced(flag, low.value(), high.value());
    }

    inline static auto
    LinSpaced(const QuantityType &low, const QuantityType &high)
    -> const Quantity<decltype(ExpressionType::LinSpaced(low.value(), high.value())), Unit> {
        return ExpressionType::LinSpaced(low.value(), high.value());
    }

    template<typename CustomNullaryOp>
    inline static auto
    NullaryExpr(Index rows, Index cols, const CustomNullaryOp &func = {})
    -> const Quantity<decltype(ExpressionType::NullaryExpr(rows, cols, func)),
                      Unit> {

        static_assert(internal::DependentBool<false,CustomNullaryOp>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");

        return ExpressionType::NullaryExpr(rows, cols, func);
    }

    template<typename CustomNullaryOp>
    inline static auto
    NullaryExpr(Index size, const CustomNullaryOp &func = {})
    -> const Quantity<decltype(ExpressionType::NullaryExpr(size, func)),
                      Unit> {

        static_assert(internal::DependentBool<false,CustomNullaryOp>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");

        return ExpressionType::NullaryExpr(size, func);
    }

    inline static auto
    Ones(Index rows, Index cols) -> const Quantity<decltype(ExpressionType::Ones(rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Ones(rows, cols);
    }

    inline static auto
    Ones(Index size) -> const Quantity<decltype(ExpressionType::Ones(size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Ones(size);
    }

    inline static auto
    Ones() -> const Quantity<decltype(ExpressionType::Ones()), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Ones();
    }

    inline static auto
    Random(Index rows, Index cols) -> const Quantity<decltype(ExpressionType::Random(rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Random(rows, cols);
    }

    inline static auto
    Random(Index size) -> const Quantity<decltype(ExpressionType::Random(size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Random(size);
    }

    inline static auto
    Random() -> const Quantity<decltype(ExpressionType::Random()), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Random();
    }

    inline static auto
    Zero(Index rows, Index cols) -> const Quantity<decltype(ExpressionType::Zero(rows, cols)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Zero(rows, cols);
    }

    inline static auto
    Zero(Index size) -> const Quantity<decltype(ExpressionType::Zero(size)), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Zero(size);
    }

    inline static auto
    Zero() -> const Quantity<decltype(ExpressionType::Zero()), Unit> {
        static_assert(internal::DependentBool<false,Unit>::value, "Following the design of the boost::units library, implicit initialization of quantities is prohibited. Instead, create a raw matrix using the NullaryOps of the standard Eigen matrix/array class, and multiply with the desired unit.");
        return ExpressionType::Zero();
    }


    // The following are not originally located in DenseBase, but are identical for MatrixBase and ArrayBase, and
    // can therefore be placed here.


    // Unary functor
    // Note that only template functors are accepted - so that they can be instantiated both using
    // the quantity types (for unit derivation), and using the raw numeric type, which will be used
    // for the actual calculation
    template<template<class> class CustomUnaryOp, typename ScalarType=typename ExpressionType::Scalar>
    inline auto
    unaryExpr(const CustomUnaryOp<ScalarType> &func = {}) const
    -> typename internal::UnaryExprReturnType<
            ExpressionType,
            CustomUnaryOp<ScalarType>,
            ScalarType,
            typename std::result_of<
                    CustomUnaryOp<QuantityType>(QuantityType)>::type>::type {

        // The construction of this lambda function triggers a compile-time check of whether the
        // result type of the provided CustomBinaryOp is consistent with its operands and operator.
        // It is unclear whether this works in general - see the version below for an alternative
        // implementation, where the entire CustomBinaryOp is wrapped in a functor that forces
        // unit calculations when applying the functor. The advantage of this version is that
        // no overhead should be involved in the calculation itself.
        // TODO: find a more elegant way to implement this check
        //auto const quantity_functor = []{return CustomUnaryOp<QuantityType>()(QuantityType::from_value(Scalar{}));};

        return this->nested().unaryExpr(CustomUnaryOp<typename ExpressionType::Scalar>());
    };


    // Note that only template functors are accepted - so that they can be instantiated both using
    // the quantity types (for unit derivation), and using the raw numeric type, which will be used
    // for the actual calculation
    template<template<class> class CustomViewOp>
    inline auto
    unaryViewExpr(const CustomViewOp<typename ExpressionType::Scalar> &func = {}) const
    -> typename internal::UnaryExprReturnType<
            ExpressionType,
            CustomViewOp<typename ExpressionType::Scalar>,
            typename ExpressionType::Scalar,
            typename std::result_of<
                    CustomViewOp<QuantityType>(QuantityType)>::type>::type {

        // The construction of this lambda function triggers a compile-time check of whether the
        // result type of the provided CustomBinaryOp is consistent with its operands and operator.
        // It is unclear whether this works in general - see the version below for an alternative
        // implementation, where the entire CustomBinaryOp is wrapped in a functor that forces
        // unit calculations when applying the functor. The advantage of this version is that
        // no overhead should be involved in the calculation itself.
        // TODO: find a more elegant way to implement this check
        auto const quantity_functor = []{return CustomViewOp<QuantityType>()(QuantityType::from_value(Scalar{}));};

        return this->nested().unaryViewExpr(func);
    }

    // binary template functor with one template argument
    // Note that only template functors are accepted - so that they can be instantiated both using
    // the quantity types (for unit derivation), and using the raw numeric type, which will be used
    // for the actual calculation
    // The SpecifiedQuantityType template parameter is to allow for things like std::multiplies<void>
    template<template<class> class CustomBinaryOp, typename OtherDerived, typename SpecifiedQuantityType=QuantityType>
    inline auto
    binaryExpr(const DenseBase<Quantity<OtherDerived, Unit>> &other,
               const CustomBinaryOp<SpecifiedQuantityType> &func = {}) const
    -> typename internal::BinaryExprReturnType<
            ExpressionType,OtherDerived,
            CustomBinaryOp<typename ExpressionType::Scalar>,
            typename ExpressionType::Scalar,
            typename std::result_of<
                    CustomBinaryOp<SpecifiedQuantityType>(QuantityType,
                                                          QuantityType)>::type>::type {

        // The construction of this lambda function triggers a compile-time check of whether the
        // result type of the provided CustomBinaryOp is consistent with its operands and operator.
        // It is unclear whether this works in general - see the version below for an alternative
        // implementation, where the entire CustomBinaryOp is wrapped in a functor that forces
        // unit calculations when applying the functor. The advantage of this version is that
        // no overhead should be involved in the calculation itself.
        // TODO: find a more elegant way to implement this check
        auto const quantity_functor = [func]{return func(QuantityType::from_value(Scalar{}),
                                                         QuantityType::from_value(Scalar{}));};

        return this->nested().binaryExpr(other.nested(),
                                         CustomBinaryOp<Scalar>());
    };


    // binary template functor with two template arguments
    // Note that only template functors are accepted - so that they can be instantiated both using
    // the quantity types (for unit derivation), and using the raw numeric type, which will be used
    // for the actual calculation
    template<template<class, class> class CustomBinaryOp, typename OtherDerived, typename OtherUnit>
    inline auto
    binaryExpr(const Quantity<OtherDerived, OtherUnit> &other,
               const CustomBinaryOp<typename ExpressionType::Scalar,
                                    typename ExpressionType::Scalar> &func = {}) const
    -> typename internal::BinaryExprReturnType<
            ExpressionType,OtherDerived,
            CustomBinaryOp<typename ExpressionType::Scalar,
                           typename OtherDerived::Scalar>,
            typename ExpressionType::Scalar,
            typename std::result_of<
                    CustomBinaryOp<QuantityType,
                                   typename Quantity<OtherDerived,
                                                     OtherUnit>::QuantityType>(QuantityType,
                                                                               typename Quantity<OtherDerived,
                                                                                                 OtherUnit>::QuantityType)>::type>::type {
        typedef typename Quantity<OtherDerived, OtherUnit>::QuantityType OtherQuantityType;

        // The construction of this lambda function triggers a compile-time check of whether the
        // result type of the provided CustomBinaryOp is consistent with its operands and operator.
        // It is unclear whether this works in general - see the version below for an alternative
        // implementation, where the entire CustomBinaryOp is wrapped in a functor that forces
        // unit calculations when applying the functor. The advantage of this version is that
        // no overhead should be involved in the calculation itself.
        // TODO: find a more elegant way to implement this check
        auto const quantity_functor = []{return CustomBinaryOp<QuantityType, OtherQuantityType>()(QuantityType::from_value(Scalar{}),
                                                                                                  OtherQuantityType::from_value(Scalar{}));};

        return this->nested().binaryExpr(other.nested(),
                                         func);
    }

};

template<typename ExpressionType, typename Unit, class OtherUnit>
inline auto
operator*(const boost::units::quantity<OtherUnit> &lhs, const DenseBase<Quantity<ExpressionType, Unit>> &rhs)
-> const Quantity<decltype(lhs.value()*rhs.nested()),
                  decltype(Unit()*OtherUnit())>{
    return lhs.value()*rhs.nested();
}

}

#endif