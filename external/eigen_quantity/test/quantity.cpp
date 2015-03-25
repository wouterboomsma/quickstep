#include <Eigen/Quantity>
#include <boost/units/systems/si.hpp>

#undef EIGEN_DEFAULT_IO_FORMAT
#undef eigen_assert

#include "main.h"
//#undef max
//#undef min





template <class Type, int Rows, int Cols> using QMatrix = Eigen::QuantityMatrix<Type, Rows, Cols>;
template <class Type, int Rows, int Cols> using QArray = Eigen::QuantityArray<Type, Rows, Cols>;

//#define EI_PP_MAKE_STRING2(S) #S
//#define EI_PP_MAKE_STRING(S) EI_PP_MAKE_STRING2(S)
//
//// Forward declaration to avoid ICC warning
//template<typename T, typename U>
//bool test_is_equal(const T& actual, const U& expected);
//
//template<typename T, typename U>
//bool test_is_equal(const T& actual, const U& expected)
//{
//    if (actual==expected)
//        return true;
//    // false:
//    std::cerr
//    << std::endl << "    actual   = " << actual
//    << std::endl << "    expected = " << expected << std::endl << std::endl;
//    return false;
//}
//
//inline void verify_impl(bool condition, const char *file, int line, const char *condition_as_string)
//{
//    if (!condition)
//    {
//        std::cerr << "Test failed in " << file << " (" << line << ")"
//        << std::endl << "    " << condition_as_string << std::endl;
//        abort();
//    }
//}
//
//#define VERIFY(a) ::verify_impl(a, __FILE__, __LINE__, EI_PP_MAKE_STRING(a))
//#define VERIFY_IS_EQUAL(a, b) VERIFY(test_is_equal(a, b))


using namespace boost::units;
using boost::units::quantity;

template <typename Derived>
void f_eigen_base(const Eigen::EigenBase<Derived>& v) {}

template <typename Derived>
void f_dense_base(const Eigen::DenseBase<Derived>& v) {}

template <typename Derived>
void f_array_base(const Eigen::ArrayBase<Derived>& v) {}

template <typename Derived>
void f_matrix_base(const Eigen::MatrixBase<Derived>& v) {}

template <typename Derived>
void f_plain_object_base(const Eigen::PlainObjectBase<Derived>& v) {}

//template <typename Derived>
//void function(const Eigen::EigenBase<Derived>& v) {return "EigenBase";}
//
//template <typename Derived>
//void function(const Eigen::DenseBase<Derived>& v) {return "DenseBase";}
//
//template <typename Derived>
//void function(const Eigen::ArrayBase<Derived>& v) {return "ArrayBase";}
//
//template <typename Derived>
//void function(const Eigen::MatrixBase<Derived>& v) {return "MatrixBase";}
//
//template <typename Derived>
//void function(const Eigen::PlainObjectBase<Derived>& v) {return "PlainObjectBase";}


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


void test_quantity_init() {

    // Initialization
    QMatrix<double, 1, 3> vector(1., 2., 3.);     // QuantityMatrix derived from Eigen::Matrix for all standard types
    QArray<double, 1, 3> array(1., 2., 3.);     // QuantityMatrix derived from Eigen::Matrix for all standard types

    // Following the design of boost::units, only explicit initialization is allowed
    QMatrix<si::length, 1, 3> length_vector(vector * si::meter);
    QArray<si::length, 1, 3> length_array(array * si::meter);
    //Matrix<si::length, 1, 3> length_vec2(vec);   // This fails (see failtest)

    // Inline initialization
    QMatrix<si::length, 1, 3> length_vector3 = QMatrix<double, 1, 3>(1., 2., 3.) * si::meter;
    auto length_vector4 = QMatrix<double, 1, 3>(1., 2., 3.) * si::meter;

    // From comma list
    QMatrix<si::length, 2, 2> length_matrix = (QMatrix<double, 2, 2>() << 1.,2.,3.,4.).finished() * si::meter;

    // From constant
    auto length_matrix2 = QMatrix<si::length, 2, 2>::Constant(10.*si::meter);

    // Ones and Zero are not available directly (which would be implicit initialization), but
    // accessible by multiplication with unit
    auto length_matrix3 = QMatrix<double, 2, 2>::Ones() * si::meter;
    auto length_matrix4 = QMatrix<double, 2, 2>::Zero() * si::meter;

    // Initialize using comma initializer - single quantity values
    QMatrix<si::length, 1, 3> length_vector5;
    length_vector << 1.*si::meter, 2.*si::meter, 3.*si::meter;
    length_vector5 = (QMatrix<si::length, 1, 3>() << 1.*si::meter, 2.*si::meter, 3.*si::meter).finished();


    // Initialize using comma initializer - matrix expression values
    // No units
    QMatrix<double, 3, 3> matrix;
    matrix << array, array, array;

    // With units
    QMatrix<si::length, 3, 3> length_matrix5;
    length_matrix5 << length_array, length_array, length_array;
    VERIFY_IS_APPROX((length_matrix5.value)(),matrix);

    // With units - initialization of temporary
    auto length_matrix6 = (QMatrix<si::length, 3, 3>() << length_array, length_array, length_array).finished();
    VERIFY_IS_APPROX((length_matrix6.value)(),matrix);

    // Output
    // cout << "length_vector: " << length_vector << endl;
    // cout << "length_array: " << length_array << endl;
    // cout << "length_matrix:\n" << length_matrix << endl;
    // cout << "length_matrix2:\n" << length_matrix2 << endl;
    // cout << "length_matrix3:\n" << length_matrix3 << endl;
    // cout << "length_matrix4:\n" << length_matrix3 << endl;
    // cout << endl << endl;
};

template <typename T>
void bla(T t) {
    static_assert(Eigen::internal::DependentBool<false, T>(), "hello");
}

void test_quantity() {

    // Mostly compile-time tests
    test_quantity_init();

    auto array = (QArray<double, 2, 2>() << 1., 2., 3., 4.).finished();
    auto vector = QMatrix<double, 1, 3>(1., 2., 3.);
    QArray<si::length, 2, 2> length_array{array * si::meter};
    auto length_vector = vector * si::meter;

    // component-wise multiplication
    QArray<si::area, 2, 2> area_array = length_array*length_array;
    VERIFY_IS_APPROX((area_array.value)(),array*array);

    // multiplication with quantity scalar
    QArray<si::area, 2, 2> area_array2 = length_array*2*si::meter;
    VERIFY_IS_APPROX((area_array2.value)(),array*2.);

    // multiplication with scalar
    QArray<si::length, 2, 2> length_array2 = length_array*2.;
    VERIFY_IS_APPROX((length_array2.value)(),array*2.);

    // component-wise division
    QArray<si::velocity, 2, 2> velocity_array = length_array / QArray<si::time, 2, 2>::Constant(1. * si::second);
    VERIFY_IS_APPROX((velocity_array.value)(),array);

    // division with quantity scalar
    QArray<si::velocity, 2, 2> velocity_array2 = length_array / (1.*si::second);
    VERIFY_IS_APPROX((velocity_array2.value)(),array);

    // division with scalar
    QArray<si::length, 2, 2> length_array3 = length_array/2.;
    VERIFY_IS_APPROX((length_array3.value)(),array/2.);

    // dot product with itself (squared norm)
    boost::units::quantity<si::area> dot_product = length_vector.dot(length_vector);
    VERIFY_IS_APPROX((dot_product.value)(),vector.dot(vector));

    // Boolean results
    QArray<bool, 2, 2> bool_result1 = length_array > 0.5 * si::meter;
    VERIFY_IS_APPROX(bool_result1,array > 0.5);
    QArray<bool, 2, 2> bool_result2 = length_array == 0.5 * si::meter;
    VERIFY_IS_APPROX(bool_result2,array == 0.5);
    QArray<bool, 2, 2> bool_result3 = length_array > QArray<si::length, 2, 2>::Constant(0.5 * si::meter);
    VERIFY_IS_APPROX(bool_result3,(array > Array<double, 2, 2>::Constant(0.5)));

    // Inverse(Inverse) = original
    auto inverse_length_array = length_array.inverse();
    VERIFY_IS_APPROX(inverse_length_array.inverse(), length_array);

    // Explicit specification to check type
    QArray<boost::units::quantity<decltype(boost::units::pow<-1>(si::length())), double>, 2, 2> inverse_length_array2 = inverse_length_array;

    // Sum
    quantity<si::length> sum_value = length_array.sum();
    VERIFY_IS_EQUAL(sum_value.value(), array.sum());

    // Accessing coefficients through [], () and x(), y(), z(), w() returns boost::quantity values
    quantity<si::length> coeff = length_array(0);
    VERIFY_IS_APPROX(coeff.value(), length_array.value()(0));
    quantity<si::length> coeff2 = length_array(0,0);
    VERIFY_IS_APPROX(coeff2.value(), length_array.value()(0,0));
    quantity<si::length> coeff3 = length_vector[0];
    VERIFY_IS_APPROX(coeff3.value(), length_vector.value()[0]);

    // Const references are wrapped in quantities as expected
    quantity<si::length, const double&> coeff_const_ref = length_array(0);

    // Non-const references work as well - and are assignable as expected
    auto coeff_ref = length_array(0);
    double &coeff_ref_raw = length_array.value()(0);
    VERIFY_IS_EQUAL(&(coeff_ref.value()), &coeff_ref_raw); // test memory address

    // Assign to non-const ref
    coeff_ref.value() = 5.;
    VERIFY_IS_APPROX(length_array(0).value(), 5.);

    coeff_ref = 6.*si::meter;  // this doesn't work
    length_array.block(0, 0, 1, 1).setConstant(6.*si::meter);
    VERIFY_IS_APPROX(length_array(0).value(), 6.);

    // Undo changes
    length_array = array * si::meter;

    // Extracting row vector
    auto length_row_vector = length_array.row(0);
    VERIFY_IS_APPROX(length_row_vector.value(), array.row(0));


    // Functors

    // note difference in calling interface - Quantity matrix takes template template so that it can
    // be instantiated with both original type and quantity type (for unit evaluation)
    auto neg_length_array = length_array.unaryExpr<std::negate>();
    VERIFY_IS_APPROX(neg_length_array.value(),array.unaryExpr<std::negate<double>>());

    // Addition using std::plus binary operator
    QArray<si::length, 2, 2> plus_length_array = length_array.binaryExpr<std::plus>(length_array);
    VERIFY_IS_APPROX(plus_length_array.value(),array.binaryExpr<std::plus<double>>(array));

    // Multiplication using std::multiply
    // Note that functor is given as argument rather than template argument to allow easy specification
    // of functor type.
    QArray<si::area, 2, 2> mult_area_array = length_array.binaryExpr(length_array, multiplies<void>());
    VERIFY_IS_APPROX(mult_area_array.value(),array.binaryExpr<std::multiplies<double>>(array));

    // This fails because scalar_product_op does not deduce the correct unit return type. See failtest example functor_wrong_return_type
    //length_array.binaryExpr<Eigen::internal::scalar_product_op>(length_array);

    // Boolean operators just return a standard boolean result
    Array<bool, 2, 2> eq_array = length_array.binaryExpr<std::equal_to>(length_array);
    VERIFY_IS_EQUAL(eq_array.all(), true);

    // Redux operations work for containers with dimensions known at compile time:
    boost::units::quantity<si::volume> volume = length_vector.redux(multiplies<void>());
    VERIFY_IS_APPROX(volume.value(), vector.redux<>(std::multiplies<double>()));

    // Redux fails on dynamic containers. See failtest example redux_dynamic_matrix
    QMatrix<si::length, Dynamic, Dynamic> length_vector_dynamic{length_vector};
    // boost::units::quantity<si::volume> volume2 = length_vector_dynamic.redux(multiplies<void>()); // <- fails
    boost::units::quantity<si::volume> volume2 = length_vector_dynamic.value().redux(multiplies<void>()) * boost::units::pow<3>(si::meter);


    // Using standard Eigen functions on QuantityMatrix and QuantityArray
    // Compile-time tests
    f_eigen_base(length_array);
    f_dense_base(length_array);
    f_array_base(length_array);
    // f_matrix_base(length_array); Fails - not a matrix
    f_matrix_base(length_vector);
    f_plain_object_base(length_array);


    // Extract diagonal
    QMatrix<si::length, 3, 3> diagonal((QMatrix<double, 3, 1>(2,5,6)*si::meter).asDiagonal());
    VERIFY_IS_EQUAL(diagonal(1,1).value(), 5.);

    // By design, assigning to a standard matrix of doubles does not work
    // QMatrix<double, 3, 3> diagonal2((QMatrix<double, 3, 1>(2,5,6)*si::meter).asDiagonal());


    // Column-wise operations
    // sum
    auto col_sum = length_array.colwise().sum();
    VERIFY_IS_APPROX(col_sum.value(), array.colwise().sum());


    // Block operations
    QMatrix<si::length, 3, 3> length_matrix_33 = QMatrix<si::length, 3, 3>::Constant(1. * si::meter);
    length_matrix_33.row(0) = length_vector;
    VERIFY_IS_APPROX(length_matrix_33.row(0).value(), length_vector.value());

    auto row = length_matrix_33.row(1);
    row << 1.*si::meter, 2.*si::meter, 3.*si::meter;
    VERIFY_IS_APPROX(length_matrix_33.row(1).value(), length_vector.value());



    // Maps
    std::vector<double> raw_vec(3, 0.0);
    auto mapped = Array<double, 1, 3>::Map(raw_vec.data(), 3);

    auto mapped_quantity = Array<double, 1, 3>::Map(raw_vec.data(), 3) * si::meter;
    mapped_quantity(0,1) = 2. * si::meter;
    std::cout << mapped_quantity << "\n";
    std::cout << raw_vec[0] << " " << raw_vec[1] << " " << raw_vec[2] << "\n";

    auto mapped_quantity2 = QArray<double, 1, 3>::Map(raw_vec.data(), 3) * si::meter;
    mapped_quantity2(0,1) = 2. * si::meter;
    std::cout << mapped_quantity2 << "\n";
    std::cout << raw_vec[0] << " " << raw_vec[1] << " " << raw_vec[2] << "\n";

    Map<QArray<si::length, 1, 3>> mapped_quantity3 = QArray<double, 1, 3>::Map(raw_vec.data(), 3) * si::meter;
    mapped_quantity3(0,1) = 2. * si::meter;
    std::cout << mapped_quantity3 << "\n";
    std::cout << raw_vec[0] << " " << raw_vec[1] << " " << raw_vec[2] << "\n";

    const std::vector<double> raw_vec_const(3, 0.0);
    Map<const QArray<si::length, 1, 3>> mapped_quantity4 = QArray<double, 1, 3>::Map(raw_vec_const.data(), 3) * si::meter;

    // Output
//    cout << "length_array: " << length_array << endl;
//    cout << "area_array:\n " << area_array << endl;
//    cout << "velocity_array: " << velocity_array << endl;
//    cout << "velocity_array2: " << velocity_array2 << endl;
//    cout << "length_vector: " << length_vector << endl;
//    cout << "length_array2: " << length_array2 << endl;
//    cout << "length_array3: " << length_array3 << endl;
//    cout << "dot_product: " << dot_product << endl;
//    cout << endl << endl;
};

//int main(int argc, char *argv[]) {
//
//    test_quantity_init();
//
//    test_quantity_ops();
//}