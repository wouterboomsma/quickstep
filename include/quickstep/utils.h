#ifndef QUICKSTEP_UTILS_H_
#define QUICKSTEP_UTILS_H_

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>

namespace quickstep {

// replacement for std::make_unique, which is not available in C++11
template<typename T, typename ...Args>
inline std::unique_ptr <T> make_unique(Args &&...args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


// Convenience aliases for matrices and vectors
template <class Type, int Rows, int Cols> using Matrix = Eigen::QuantityMatrix<Type, Rows, Cols>;
template <class Type, int Rows, int Cols> using Array = Eigen::QuantityArray<Type, Rows, Cols>;
template <class Type, int Cols> using Vector = Eigen::QuantityMatrix<Type, 1, Cols>;
template <class Type> using Vector3 = Eigen::QuantityMatrix<Type, 3, 1>;


// TODO: Remove
template <typename T>
void print_template(const T &t) {
    static_assert(Eigen::internal::DependentBool<false, T>(), "printing template");
}

}

#endif