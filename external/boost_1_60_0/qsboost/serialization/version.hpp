#ifndef QSBOOST_SERIALIZATION_VERSION_HPP
#define QSBOOST_SERIALIZATION_VERSION_HPP

// MS compatible compilers support #pragma once
#if defined(_MSC_VER)
# pragma once
#endif

/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// version.hpp:

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#include <qsboost/config.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/integral_c_tag.hpp>

#include <qsboost/type_traits/is_base_and_derived.hpp>

namespace qsboost { 
namespace serialization {

struct basic_traits;

// default version number is 0. Override with higher version
// when class definition changes.
template<class T>
struct version
{
    template<class U>
    struct traits_class_version {
        typedef typename U::version type;
    };

    typedef mpl::integral_c_tag tag;
    // note: at least one compiler complained w/o the full qualification
    // on basic traits below
    typedef
        typename mpl::eval_if<
            is_base_and_derived<qsboost::serialization::basic_traits,T>,
            traits_class_version< T >,
            mpl::int_<0>
        >::type type;
    QSBOOST_STATIC_CONSTANT(int, value = version::type::value);
};

#ifndef QSBOOST_NO_INCLASS_MEMBER_INITIALIZATION
template<class T>
const int version<T>::value;
#endif

} // namespace serialization
} // namespace boost

/* note: at first it seemed that this would be a good place to trap
 * as an error an attempt to set a version # for a class which doesn't
 * save its class information (including version #) in the archive.
 * However, this imposes a requirement that the version be set after
 * the implemention level which would be pretty confusing.  If this
 * is to be done, do this check in the input or output operators when
 * ALL the serialization traits are available.  Included the implementation
 * here with this comment as a reminder not to do this!
 */
//#include <boost/serialization/level.hpp>
//#include <boost/mpl/equal_to.hpp>

#include <qsboost/mpl/less.hpp>
#include <qsboost/mpl/comparison.hpp>

// specify the current version number for the class
// version numbers limited to 8 bits !!!
#define QSBOOST_CLASS_VERSION(T, N)                                      \
namespace qsboost {                                                      \
namespace serialization {                                              \
template<>                                                             \
struct version<T >                                                     \
{                                                                      \
    typedef mpl::int_<N> type;                                         \
    typedef mpl::integral_c_tag tag;                                   \
    QSBOOST_STATIC_CONSTANT(int, value = version::type::value);          \
    QSBOOST_MPL_ASSERT((                                                 \
        qsboost::mpl::less<                                              \
            qsboost::mpl::int_<N>,                                       \
            qsboost::mpl::int_<256>                                      \
        >                                                              \
    ));                                                                \
    /*                                                                 \
    BOOST_MPL_ASSERT((                                                 \
        mpl::equal_to<                                                 \
            :implementation_level<T >,                                 \
            mpl::int_<object_class_info>                               \
        >::value                                                       \
    ));                                                                \
    */                                                                 \
};                                                                     \
}                                                                      \
}

#endif // BOOST_SERIALIZATION_VERSION_HPP
