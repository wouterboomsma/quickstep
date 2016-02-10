// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_RESOLVE_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_RESOLVE_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <qsboost/config.hpp> // partial spec, put size_t in std.
#include <cstddef>          // std::size_t.
#include <qsboost/detail/is_incrementable.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/detail/adapter/mode_adapter.hpp>
#include <qsboost/iostreams/detail/adapter/output_iterator_adapter.hpp>
#include <qsboost/iostreams/detail/adapter/range_adapter.hpp>
#include <qsboost/iostreams/detail/config/gcc.hpp>
#include <qsboost/iostreams/detail/config/overload_resolution.hpp>
#include <qsboost/iostreams/detail/config/wide_streams.hpp>
#include <qsboost/iostreams/detail/enable_if_stream.hpp>
#include <qsboost/iostreams/detail/is_dereferenceable.hpp>
#include <qsboost/iostreams/detail/is_iterator_range.hpp>
#include <qsboost/iostreams/detail/select.hpp>
#include <qsboost/iostreams/detail/wrap_unwrap.hpp>
#include <qsboost/iostreams/device/array.hpp>
#include <qsboost/iostreams/traits.hpp>
#include <qsboost/mpl/and.hpp>
#include <qsboost/mpl/bool.hpp> // true_.
#include <qsboost/mpl/if.hpp>
#if !QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300)
# include <qsboost/range/iterator_range.hpp>
#endif // #if BOOST_WORKAROUND(BOOST_MSVC, <= 1300)
#include <qsboost/type_traits/is_array.hpp>

// Must come last.
#include <qsboost/iostreams/detail/config/disable_warnings.hpp> // VC7.1 C4224.

namespace qsboost { namespace iostreams { namespace detail {

//------------------Definition of resolve-------------------------------------//

#ifndef QSBOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION //-------------------------//

template<typename Mode, typename Ch, typename T>
struct resolve_traits {
    typedef typename 
            mpl::if_<
                qsboost::detail::is_incrementable<T>,
                output_iterator_adapter<Mode, Ch, T>,
                const T&
            >::type type;
};

# ifndef QSBOOST_IOSTREAMS_NO_STREAM_TEMPLATES //-------------------------------//

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type
resolve( const T& t 
         QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T)

         // I suspect that the compilers which require this workaround may
         // be correct, but I'm not sure why :(
         #if QSBOOST_WORKAROUND(QSBOOST_INTEL_CXX_VERSION, QSBOOST_TESTED_AT(810)) ||\
             QSBOOST_WORKAROUND(__MWERKS__, QSBOOST_TESTED_AT(0x3205)) || \
             QSBOOST_WORKAROUND(QSBOOST_IOSTREAMS_GCC, QSBOOST_TESTED_AT(400)) ||\
             QSBOOST_WORKAROUND(__IBMCPP__, QSBOOST_TESTED_AT(1110))
             /**/
         , typename disable_if< is_iterator_range<T> >::type* = 0
         #endif
         )
{
    typedef typename resolve_traits<Mode, Ch, T>::type return_type;
    return return_type(t);
}

template<typename Mode, typename Ch, typename Tr>
mode_adapter< Mode, std::basic_streambuf<Ch, Tr> > 
resolve(std::basic_streambuf<Ch, Tr>& sb)
{ return mode_adapter< Mode, std::basic_streambuf<Ch, Tr> >(wrap(sb)); }

template<typename Mode, typename Ch, typename Tr>
mode_adapter< Mode, std::basic_istream<Ch, Tr> > 
resolve(std::basic_istream<Ch, Tr>& is)
{ return mode_adapter< Mode, std::basic_istream<Ch, Tr> >(wrap(is)); }

template<typename Mode, typename Ch, typename Tr>
mode_adapter< Mode, std::basic_ostream<Ch, Tr> > 
resolve(std::basic_ostream<Ch, Tr>& os)
{ return mode_adapter< Mode, std::basic_ostream<Ch, Tr> >(wrap(os)); }

template<typename Mode, typename Ch, typename Tr>
mode_adapter< Mode, std::basic_iostream<Ch, Tr> > 
resolve(std::basic_iostream<Ch, Tr>& io)
{ return mode_adapter< Mode, std::basic_iostream<Ch, Tr> >(wrap(io)); }

template<typename Mode, typename Ch, std::size_t N>
array_adapter<Mode, Ch> resolve(Ch (&array)[N])
{ return array_adapter<Mode, Ch>(array); }

#  if !QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300)
    template<typename Mode, typename Ch, typename Iter>
    range_adapter< Mode, qsboost::iterator_range<Iter> > 
    resolve(const qsboost::iterator_range<Iter>& rng)
    { return range_adapter< Mode, qsboost::iterator_range<Iter> >(rng); }
#  endif // #if BOOST_WORKAROUND(BOOST_MSVC, <= 1300)

# else // # ifndef BOOST_IOSTREAMS_NO_STREAM_TEMPLATES //---------------------//

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type
resolve( const T& t 
         QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T)
         #if defined(__GNUC__)
         , typename disable_if< is_iterator_range<T> >::type* = 0
         #endif
         )
{
    typedef typename resolve_traits<Mode, Ch, T>::type return_type;
    return return_type(t);
}

template<typename Mode, typename Ch>
mode_adapter<Mode, std::streambuf> 
resolve(std::streambuf& sb) 
{ return mode_adapter<Mode, std::streambuf>(wrap(sb)); }

template<typename Mode, typename Ch>
mode_adapter<Mode, std::istream> 
resolve(std::istream& is)
{ return mode_adapter<Mode, std::istream>(wrap(is)); }

template<typename Mode, typename Ch>
mode_adapter<Mode, std::ostream> 
resolve(std::ostream& os)
{ return mode_adapter<Mode, std::ostream>(wrap(os)); }

template<typename Mode, typename Ch>
mode_adapter<Mode, std::iostream> 
resolve(std::iostream& io)
{ return mode_adapter<Mode, std::iostream>(wrap(io)); }

template<typename Mode, typename Ch, std::size_t N>
array_adapter<Mode, Ch> resolve(Ch (&array)[N])
{ return array_adapter<Mode, Ch>(array); }

template<typename Mode, typename Ch, typename Iter>
range_adapter< Mode, qsboost::iterator_range<Iter> > 
resolve(const qsboost::iterator_range<Iter>& rng)
{ return range_adapter< Mode, qsboost::iterator_range<Iter> >(rng); }

# endif // # ifndef BOOST_IOSTREAMS_NO_STREAM_TEMPLATES //--------------------//
#else // #ifndef BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION //----------------//

template<typename Mode, typename Ch, typename T>
struct resolve_traits {
    // Note: test for is_iterator_range must come before test for output
    // iterator.
    typedef typename 
            iostreams::select<  // Disambiguation for Tru64.
                is_std_io<T>,
                mode_adapter<Mode, T>,
                is_iterator_range<T>,
                range_adapter<Mode, T>,
                is_dereferenceable<T>,
                output_iterator_adapter<Mode, Ch, T>,
                is_array<T>,
                array_adapter<Mode, T>,
                else_,
                #if !QSBOOST_WORKAROUND(__BORLANDC__, < 0x600)
                    const T&
                #else
                    T
                #endif
            >::type type;
};

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type 
resolve(const T& t, mpl::true_)
{   // Bad overload resolution.
    typedef typename resolve_traits<Mode, Ch, T>::type return_type;
    return return_type(wrap(const_cast<T&>(t)));
}

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type 
resolve(const T& t, mpl::false_)
{ 
    typedef typename resolve_traits<Mode, Ch, T>::type return_type;
    return return_type(t);
}

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type 
resolve(const T& t QSBOOST_IOSTREAMS_DISABLE_IF_STREAM(T))
{ return resolve<Mode, Ch>(t, is_std_io<T>()); }

# if !QSBOOST_WORKAROUND(__BORLANDC__, < 0x600) && \
     !QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) && \
     !defined(__GNUC__) // ---------------------------------------------------//

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type 
resolve(T& t, mpl::true_)
{ 
    typedef typename resolve_traits<Mode, Ch, T>::type return_type;
    return return_type(wrap(t));
}

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type 
resolve(T& t, mpl::false_)
{ 
    typedef typename resolve_traits<Mode, Ch, T>::type return_type;
    return return_type(t);
}

template<typename Mode, typename Ch, typename T>
typename resolve_traits<Mode, Ch, T>::type 
resolve(T& t QSBOOST_IOSTREAMS_ENABLE_IF_STREAM(T))
{ return resolve<Mode, Ch>(t, is_std_io<T>()); }

# endif // Borland 5.x, VC6-7.0 or GCC 2.9x //--------------------------------//
#endif // #ifndef BOOST_IOSTREAMS_BROKEN_OVERLOAD_RESOLUTION //---------------//

} } } // End namespaces detail, iostreams, boost.

#include <qsboost/iostreams/detail/config/enable_warnings.hpp> // VC7.1 4224.

#endif // BOOST_IOSTREAMS_DETAIL_RESOLVE_HPP_INCLUDED
