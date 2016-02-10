#ifndef QUICKSTEP_UTILS_H_
#define QUICKSTEP_UTILS_H_

#include <qsboost/exception/exception.hpp>
#include <qsboost/exception/info.hpp>
#include <Eigen/Dense>

namespace quickstep {

//// replacement for std::make_unique, which is not available in C++11
//template<typename T, typename ...Args>
//inline std::unique_ptr <T> make_unique(Args &&...args) {
//    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
//}


// Convenience aliases for matrices and vectors
using Eigen::Dynamic;
template <class Type, int Rows, int Cols> using Matrix = Eigen::Matrix<Type, Rows, Cols>;
template <class Type, int Rows, int Cols> using Array = Eigen::Array<Type, Rows, Cols>;
template <class Type, int Cols> using Vector = Eigen::Matrix<Type, 1, Cols>;
template <class Type> using Vector3 = Eigen::Matrix<Type, 3, 1>;
template <class Type> using Array3 = Eigen::Array<Type, 3, 1>;

typedef Eigen::Array<double, 3, 1> Coordinate;
typedef Eigen::Array<double, 3, Eigen::Dynamic> Coordinates;

typedef Eigen::Map<Coordinates> CoordinatesWrapper;
typedef Eigen::Map<const Coordinates> ConstCoordinatesWrapper;

typedef Eigen::Array<double, 3, 1> Array3d;
typedef Eigen::Matrix<double, 3, 1> Vector3d;


//// TODO: Remove
//template <typename T>
//void print_template(const T &t) {
//    static_assert(Eigen::internal::DependentBool<false, T>(), "printing template");
//}

}

#endif