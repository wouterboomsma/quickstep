//  Boost string_algo library slist_traits.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003. 
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for updates, documentation, and revision history.

#ifndef QSBOOST_STRING_STD_SLIST_TRAITS_HPP
#define QSBOOST_STRING_STD_SLIST_TRAITS_HPP

#include <qsboost/algorithm/string/config.hpp>
#include <qsboost/algorithm/string/yes_no_type.hpp>
#include QSBOOST_SLIST_HEADER 
#include <qsboost/algorithm/string/sequence_traits.hpp>

namespace qsboost {
    namespace algorithm {

//  SGI's std::slist<> traits  -----------------------------------------------//


    // stable iterators trait
        template<typename T, typename AllocT>
        class has_stable_iterators< QSBOOST_STD_EXTENSION_NAMESPACE::slist<T,AllocT> >
        {
        public:
#if QSBOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = true };
#else
            QSBOOST_STATIC_CONSTANT(bool, value=true);
#endif // BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            typedef mpl::bool_<has_stable_iterators<T>::value> type;
        };

    // const time insert trait
        template<typename T, typename AllocT>
        class has_const_time_insert< QSBOOST_STD_EXTENSION_NAMESPACE::slist<T,AllocT> >
        {
        public:
#if QSBOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = true };
#else
            QSBOOST_STATIC_CONSTANT(bool, value=true);
#endif // BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            typedef mpl::bool_<has_const_time_insert<T>::value> type;
        };

    // const time erase trait
        template<typename T, typename AllocT>
        class has_const_time_erase< QSBOOST_STD_EXTENSION_NAMESPACE::slist<T,AllocT> >
        {
        public:
#if QSBOOST_WORKAROUND( __IBMCPP__, <= 600 )
            enum { value = true };
#else
            QSBOOST_STATIC_CONSTANT(bool, value=true);
#endif // BOOST_WORKAROUND( __IBMCPP__, <= 600 )
            typedef mpl::bool_<has_const_time_erase<T>::value> type;
        };


    } // namespace algorithm
} // namespace boost


#endif  // BOOST_STRING_STD_LIST_TRAITS_HPP
