#ifndef UTILITY_UTILS_H_
#define UTILITY_UTILS_H_

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>

namespace utility {

template<typename T>
inline void default_delete_func(T *t) {
    delete t;
}

template<typename T>
inline void delete_func_noop(T *t) {}

//template<typename T>
//class unique_ptr: public std::unique_ptr<T, void(*)(T*)> {
//public:
//    using std::unique_ptr<T, void(*)(T*)>::unique_ptr;
////    using std::unique_ptr<T, void(*)(T*)>::~unique_ptr<T, void(*)(T*)>;
//    _LIBCPP_INLINE_VISIBILITY ~unique_ptr() {this->reset();}
//};

template <class T>
using unique_ptr = std::unique_ptr<T, void(*)(T*)>;

template<typename T, typename ...Args>
unique_ptr<T> make_unique(Args &&...args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...), &default_delete_func);
}


}

#endif