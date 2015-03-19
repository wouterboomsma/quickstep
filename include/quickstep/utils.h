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

}

#endif