#include "Eigen/Quantity"
#include <boost/units/systems/si.hpp>
template <class Type, int Rows, int Cols> using Matrix = Eigen::QuantityMatrix<Type, Rows, Cols>;
template <class Type, int Size> using Vector = Eigen::QuantityMatrix<Type, Size, 1>;

int main() {

    using namespace boost::units;

    Vector<quantity<si::length>, 2> meter_vector(Vector<double, 2>(1., 2.)*si::meter);

#ifdef EIGEN_SHOULD_FAIL_TO_BUILD
    // Assignment to length vector fails
    Vector<quantity<si::length>, 2> area_vector(meter_vector.array().square());
#else
    Vector<quantity<si::area>, 2> area_vector(meter_vector.array().square());
#endif
}