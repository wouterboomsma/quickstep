#ifndef EIGEN_QUANTITY_MATRIX_BASE_H
#define EIGEN_QUANTITY_MATRIX_BASE_H

#include "QuantityDenseBase.h"

namespace Eigen {

template<typename ExpressionType, typename Unit>
class MatrixBase<Quantity<ExpressionType, Unit>> : public DenseBase<Quantity<ExpressionType, Unit>> {
public:
    typedef DenseBase<Quantity<ExpressionType, Unit>> Base;
    typedef typename DenseBase<ExpressionType>::Index Index;
    typedef typename ExpressionType::Scalar Scalar;

    inline auto
    adjoint() const -> const Quantity<decltype(this->nested().adjoint()), Unit> {
        return this->nested().adjoint();
    }

    inline void
    adjointInPlace() const {
        this->nested().adjointInPlace();
    }

    template<typename EssentialPart>
    inline void
    applyHouseholderOnTheLeft(const EssentialPart &essential, const Scalar &tau, Scalar *workspace) {
        this->nested().applyHouseHolderOnTheLeft();
    }

    template<typename EssentialPart>
    inline void
    applyHouseholderOnTheRight(const EssentialPart &essential, const Scalar &tau, Scalar *workspace) {
        this->nested().applyHouseHolderOnTheRight();
    }

    template<typename OtherDerived>
    inline void
    applyOnTheLeft(const EigenBase<Quantity<OtherDerived, Unit>> &other) {
        this->nested().applyOnTheLeft(other);
    }

    template<typename OtherScalar>
    inline void
    applyOnTheLeft(Index p, Index q, const JacobiRotation<OtherScalar> &j) {
        this->nested().applyOnTheLeft(p, q, j);
    }

    template<typename OtherDerived>
    inline void
    applyOnTheRight(const EigenBase<Quantity<OtherDerived, Unit>> &other) {
        this->nested().applyOnTheRight(other);
    }

    template<typename OtherScalar>
    inline void
    applyOnTheRight(Index p, Index q, const JacobiRotation<OtherScalar> &j) {
        this->nested().applyOnTheRight(p, q, j);
    }

    inline Quantity<ArrayWrapper<ExpressionType>, Unit>
    array() const {
        return this->nested().array();
    }

    inline Quantity<const DiagonalWrapper<const ExpressionType>, Unit>
    asDiagonal() const {
        return this->nested().asDiagonal();
    }

    inline boost::units::quantity<Unit,
                           typename NumTraits<typename internal::traits<ExpressionType>::Scalar>::Real>
    blueNorm() {
        return boost::units::quantity<Unit,
                                      typename NumTraits<typename internal::traits<ExpressionType>::Scalar>::Real>::from_value(this->nested().blueNorm());
    }

    template<typename OtherDerived>
    inline auto
    cross(const MatrixBase<Quantity<OtherDerived, Unit>> &other) const
    -> Quantity<decltype(this->nested().cross(other)), Unit> {
        return this->nested().cross(other.nested());
    }

    inline boost::units::quantity<decltype(boost::units::pow<ExpressionType::SizeAtCompileTime>(Unit()))>
    determinant() const {
        return boost::units::quantity<decltype(boost::units::pow<ExpressionType::SizeAtCompileTime>(Unit()))>::from_value(this->nested().determinant());
    };

    inline Quantity<Diagonal<ExpressionType>, Unit> diagonal() {
        return this->nested().diagonal();
    }

    inline const Quantity<const Diagonal<const ExpressionType>, Unit> diagonal() const {
        return this->nested().diagonal();
    }

    inline Quantity<Diagonal<ExpressionType,DynamicIndex>, Unit>
    diagonal(Index index) {
        return this->nested().diagonal(index);
    }

    inline const Quantity<const Diagonal<const ExpressionType,DynamicIndex>, Unit> diagonal(Index index) const {
        return this->nested().diagonal(index);
    }

    inline Index
    diagonalSize() const {
        return this->nested().diagonalSize();
    }

    template<typename OtherDerived, typename OtherUnit>
    inline auto
    dot(const MatrixBase<Quantity<OtherDerived, OtherUnit>> &other) const
    -> boost::units::quantity<decltype(Unit()*OtherUnit())> {
        return boost::units::quantity<decltype(Unit()*OtherUnit())>::from_value(this->nested().dot(other.nested()));
    }

    inline auto
    eigenvalues() const -> Quantity<decltype(this->nested().eigenvalues()), Unit> {
        return this->nested().eigenvalues();
    }

    inline auto
    forceAlignedAccess() const -> const Quantity<decltype(this->nested().forceAlignedAccess()), Unit> {
        return this->nested().forcedAlignedAccess();
    }

    inline auto
    forceAlignedAccess() -> Quantity<decltype(this->nested().forceAlignedAccess()), Unit> {
        return this->nested().forcedAlignedAccess();
    }

    template<bool Enable>
    inline auto
    forceAlignedAccessIf() -> Quantity<decltype(this->nested().template forceAlignedAccessIf<Enable>()), Unit> {
        return this->nested().template forcedAlignedAccessIf<Enable>();
    }

    template<bool Enable>
    inline auto
    forceAlignedAccessIf() const -> const Quantity<decltype(this->nested().template forceAlignedAccessIf<Enable>()), Unit> {
        return this->nested().template forcedAlignedAccessIf<Enable>();
    }



    inline auto
    norm() const
    -> boost::units::quantity<Unit> {
        return boost::units::quantity<Unit>::from_value(this->nested().norm());
    }

    // Removed because normalizing renders the matrix unit-less, which
    // cannot be represented with an in-place operation. Use matrix.value().normalize()
    // void
    // normalize() {
    //     this->nested().normalize();
    // }

    inline auto
//    normalized() const -> Quantity<decltype(this->nested().normalized()), Unit> {
    normalized() const -> decltype(this->nested().normalized()) {
        return this->nested().normalized();
    }

    inline auto
    squaredNorm() const
    -> boost::units::quantity<decltype(Unit()*Unit())> {
        return boost::units::quantity<decltype(Unit()*Unit())>::from_value(this->nested().squaredNorm());
    }


    inline auto
    operator*(const Scalar &other) const -> const Quantity<decltype(this->nested().operator*(other)),
                                                           Unit> {
        return this->nested().operator*(other);
    }

    inline auto
    operator*(const std::complex<Scalar> &other) const -> const Quantity<decltype(this->nested().operator*(other)),
                                                                         Unit> {
        return this->nested().operator*(other);
    }

    inline auto
    operator/(const Scalar &other) const -> const Quantity<decltype(this->nested().operator/(other)),
                                                           Unit> {
        return this->nested().operator/(other);
    }

    template<typename OtherDerived>
    inline auto
    operator+(const Quantity<OtherDerived, Unit> &other) const -> const Quantity<decltype(this->nested().operator+(other.nested())),
                                                                                 decltype(Unit())> {
        return this->nested().operator+(other.nested());
    }

    template<typename OtherDerived>
    inline auto
    operator-(const Quantity<OtherDerived, Unit> &other) const -> const Quantity<decltype(this->nested().operator-(other.nested())),
                                                                                 decltype(Unit())> {
        return this->nested().operator-(other.nested());
    }

    inline auto
    operator-() const -> const Quantity<decltype(this->nested().operator-()),
                                        Unit> {
        return this->nested().operator-();
    }

    template<typename OtherDerived>
    inline bool
    operator!=(const MatrixBase<Quantity<OtherDerived, Unit>> &other) const {
        return this->nested().operator!=(other.nested());
    }

    template<typename OtherDerived>
    inline bool
    operator==(const MatrixBase<Quantity<OtherDerived, Unit>> &other) const {
        return this->nested().operator==(other.nested());
    }


    // QR module
    inline auto
    colPivHouseholderQr() const -> Quantity<decltype(this->nested().colPivHouseholderQr()), Unit> {
        return this->nested().colPivHouseholderQr();
    }


    // LU module
//    template <typename ResultType>
//    void computeInverseAndDetWithCheck(Quantity<ResultType, Unit> &inverse,
//                                       typename ResultType::Scalar& determinant,
//                                       bool& invertible,
//                                       const RealScalar& absDeterminantThreshold = NumTraits<Scalar>::dummy_precision())
    // computerInverseWithCheck

    // Geometry
    template<typename OtherDerived>
    inline auto
    cross3(const MatrixBase<Quantity<OtherDerived, Unit>> &other) const
    -> Quantity<decltype(this->nested().cross3(other)), Unit> {
        return this->nested().cross3(other);
    }

    // eulerAngles

};


template<typename ExpressionType, typename Unit>
class MatrixBaseSpecialization: public MatrixBase<Quantity<ExpressionType, Unit>> {
public:


};

}

#endif