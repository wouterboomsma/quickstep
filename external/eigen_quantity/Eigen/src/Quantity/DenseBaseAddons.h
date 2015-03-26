template<class Dim, class System>
friend const inline Quantity<Derived, boost::units::unit<Dim, System>>
operator*(const Derived &lhs, const boost::units::unit<Dim, System> &rhs) {
    return lhs;
}

template<class Unit>
friend inline auto
operator*(const Derived &lhs, const boost::units::quantity<Unit> &rhs) -> const Quantity<decltype(lhs*rhs.value()), Unit> {
    return lhs*rhs.value();
}

template<class Dim, class System>
friend const inline Quantity<Derived, boost::units::unit<Dim, System>>
operator*(const boost::units::unit<Dim, System> &lhs, const Derived &rhs) {
    return rhs;
}

template<class Unit>
friend inline auto
operator*(const boost::units::quantity<Unit> &lhs, const Derived &rhs) -> const Quantity<decltype(lhs.value()*rhs), Unit> {
    return lhs.value()*rhs;
}




