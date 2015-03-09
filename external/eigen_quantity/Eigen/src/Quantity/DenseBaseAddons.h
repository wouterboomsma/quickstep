template<class Dim, class System>
friend const inline Quantity<Derived, boost::units::unit<Dim, System>>
operator*(const Derived &lhs, const boost::units::unit<Dim, System> &rhs) {
    return lhs;
}




