// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_ERROR_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_ERROR_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              
                 
#include <qsboost/iostreams/detail/ios.hpp>  // failure.

namespace qsboost { namespace iostreams { namespace detail {

inline QSBOOST_IOSTREAMS_FAILURE cant_read() 
{ return QSBOOST_IOSTREAMS_FAILURE("no read access"); }

inline QSBOOST_IOSTREAMS_FAILURE cant_write() 
{ return QSBOOST_IOSTREAMS_FAILURE("no write access"); }

inline QSBOOST_IOSTREAMS_FAILURE cant_seek() 
{ return QSBOOST_IOSTREAMS_FAILURE("no random access"); }

inline QSBOOST_IOSTREAMS_FAILURE bad_read() 
{ return QSBOOST_IOSTREAMS_FAILURE("bad read"); }

inline QSBOOST_IOSTREAMS_FAILURE bad_putback() 
{ return QSBOOST_IOSTREAMS_FAILURE("putback buffer full"); }

inline QSBOOST_IOSTREAMS_FAILURE bad_write() 
{ return QSBOOST_IOSTREAMS_FAILURE("bad write"); }

inline QSBOOST_IOSTREAMS_FAILURE write_area_exhausted() 
{ return QSBOOST_IOSTREAMS_FAILURE("write area exhausted"); }

inline QSBOOST_IOSTREAMS_FAILURE bad_seek() 
{ return QSBOOST_IOSTREAMS_FAILURE("bad seek"); }

} } } // End namespaces detail, iostreams, boost.

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_ERROR_HPP_INCLUDED
