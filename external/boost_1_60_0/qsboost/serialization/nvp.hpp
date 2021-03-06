#ifndef QSBOOST_SERIALIZATION_NVP_HPP
#define QSBOOST_SERIALIZATION_NVP_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// nvp.hpp: interface for serialization system.

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <utility>

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>

#include <qsboost/mpl/integral_c.hpp>
#include <qsboost/mpl/integral_c_tag.hpp>

#include <qsboost/serialization/level.hpp>
#include <qsboost/serialization/tracking.hpp>
#include <qsboost/serialization/split_member.hpp>
#include <qsboost/serialization/base_object.hpp>
#include <qsboost/serialization/traits.hpp>
#include <qsboost/serialization/wrapper.hpp>

namespace qsboost {
namespace serialization {

template<class T>
struct nvp : 
    public std::pair<const char *, T *>,
    public wrapper_traits<const nvp< T > >
{
    explicit nvp(const char * name_, T & t) :
        // note: redundant cast works around borland issue
        // note: added _ to suppress useless gcc warning
        std::pair<const char *, T *>(name_, (T*)(& t))
    {}
    nvp(const nvp & rhs) : 
        // note: redundant cast works around borland issue
        std::pair<const char *, T *>(rhs.first, (T*)rhs.second)
    {}

    const char * name() const {
        return this->first;
    }
    T & value() const {
        return *(this->second);
    }

    const T & const_value() const {
        return *(this->second);
    }

    // True64 compiler complains with a warning about the use of
    // the name "Archive" hiding some higher level usage.  I'm sure this
    // is an error but I want to accomodated as it generates a long warning
    // listing and might be related to a lot of test failures.
    // default treatment for name-value pairs. The name is
    // just discarded and only the value is serialized. 
    template<class Archivex>
    void save(
        Archivex & ar, 
        const unsigned int /* file_version */
    ) const {
        // CodeWarrior 8.x can't seem to resolve the << op for a rhs of "const T *"
        ar.operator<<(const_value());
    }
    template<class Archivex>
    void load(
        Archivex & ar, 
        const unsigned int /* file_version */
    ){
        // CodeWarrior 8.x can't seem to resolve the >> op for a rhs of "const T *"
        ar.operator>>(value());
    }
    QSBOOST_SERIALIZATION_SPLIT_MEMBER()
};

template<class T>
inline
const nvp< T > make_nvp(const char * name, T & t){
    return nvp< T >(name, t);
}

// to maintain efficiency and portability, we want to assign
// specific serialization traits to all instances of this wrappers.
// we can't strait forward method below as it depends upon
// Partial Template Specialization and doing so would mean that wrappers
// wouldn't be treated the same on different platforms.  This would
// break archive portability. Leave this here as reminder not to use it !!!

template <class T>
struct implementation_level<nvp< T > >
{
    typedef mpl::integral_c_tag tag;
    typedef mpl::int_<object_serializable> type;
    QSBOOST_STATIC_CONSTANT(int, value = implementation_level::type::value);
};

// nvp objects are generally created on the stack and are never tracked
template<class T>
struct tracking_level<nvp< T > >
{
    typedef mpl::integral_c_tag tag;
    typedef mpl::int_<track_never> type;
    QSBOOST_STATIC_CONSTANT(int, value = tracking_level::type::value);
};


} // seralization
} // boost

#include <qsboost/preprocessor/stringize.hpp>

#define QSBOOST_SERIALIZATION_NVP(name)                              \
    qsboost::serialization::make_nvp(QSBOOST_PP_STRINGIZE(name), name)
/**/

#define QSBOOST_SERIALIZATION_BASE_OBJECT_NVP(name)                  \
    qsboost::serialization::make_nvp(                                \
        QSBOOST_PP_STRINGIZE(name),                                  \
        qsboost::serialization::base_object<name >(*this)            \
    )
/**/

#endif // BOOST_SERIALIZATION_NVP_HPP
