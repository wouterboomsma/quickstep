// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_IMBUE_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_IMBUE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif

#include <qsboost/config.hpp>  // DEDUCED_TYPENAME, MSVC.
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/detail/dispatch.hpp>
#include <qsboost/iostreams/detail/streambuf.hpp>
#include <qsboost/iostreams/detail/wrap_unwrap.hpp>
#include <qsboost/iostreams/operations_fwd.hpp>
#include <qsboost/mpl/if.hpp>

// Must come last.
#include <qsboost/iostreams/detail/config/disable_warnings.hpp>

namespace qsboost { namespace iostreams { 

namespace detail {

// Implementation templates for simulated tag dispatch.
template<typename T> 
struct imbue_impl;

} // End namespace detail.

template<typename T, typename Locale>
void imbue(T& t, const Locale& loc)
{ detail::imbue_impl<T>::imbue(detail::unwrap(t), loc); }

namespace detail {

//------------------Definition of imbue_impl----------------------------------//

template<typename T>
struct imbue_impl
    : mpl::if_<
          is_custom<T>,
          operations<T>,
          imbue_impl<
              QSBOOST_DEDUCED_TYPENAME
              dispatch<
                  T, streambuf_tag, localizable_tag, any_tag
              >::type
          >
      >::type
    { };

template<>
struct imbue_impl<any_tag> {
    template<typename T, typename Locale>
    static void imbue(T&, const Locale&) { }
};

template<>
struct imbue_impl<streambuf_tag> {
    template<typename T, typename Locale>
    static void imbue(T& t, const Locale& loc) { t.pubimbue(loc); }
};

template<>
struct imbue_impl<localizable_tag> {
    template<typename T, typename Locale>
    static void imbue(T& t, const Locale& loc) { t.imbue(loc); }
};

} // End namespace detail.

} } // End namespaces iostreams, boost.

#include <qsboost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef BOOST_IOSTREAMS_IMBUE_HPP_INCLUDED
