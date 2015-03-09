#include "Eigen/Quantity"
#include <boost/units/systems/si.hpp>
template <class Type, int Rows, int Cols> using QMatrix = Eigen::QuantityMatrix<Type, Rows, Cols>;
template <class Type, int Rows, int Cols> using QArray = Eigen::QuantityArray<Type, Rows, Cols>;

// In c++14, std::multiplies has a void specialization, which
// deduces its return type. Here, we define it ourselves to
// demonstrate its effect.
template<typename T>
struct multiplies: public std::multiplies<T> {};

template<>
struct multiplies<void> {

    template<class T, class U>
    constexpr auto operator()(T &&lhs, U &&rhs) const
    -> decltype(std::forward<T>(lhs) * std::forward<U>(rhs)) {
        return std::forward<T>(lhs) * std::forward<U>(rhs);
    }
};

int main() {

    using namespace boost::units;

    QMatrix<si::length, Eigen::Dynamic, Eigen::Dynamic> length_vector_dynamic = QMatrix<double, 3, 1>(1., 2., 3.) * si::meter;

#ifdef EIGEN_SHOULD_FAIL_TO_BUILD
    // Result unit cannot be deduced on dynamic size matrix
    length_vector_dynamic.redux(multiplies<void>());
#else
    // Instead, use raw matrix value, and manually assign unit
    boost::units::quantity<si::volume> volume = length_vector_dynamic.value().redux(multiplies<void>()) * boost::units::pow<3>(si::meter);
#endif
}