
// Support for multiplcations of standard matrix (e.g. rotation matrix) with quantity vector
template<typename OtherDerived, typename Unit>
const typename ProductReturnType<Derived,OtherDerived>::Type
        operator*(const MatrixBase<Quantity<OtherDerived, Unit>> &other) const {
    return this->operator*(other.value());
};




