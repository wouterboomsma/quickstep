// -*- C++ -*-
// ----------------------------------------------------------------------------
// config_macros.hpp : configuration macros for the format library
// only BOOST_IO_STD is absolutely needed (it should be 'std::' in general)
// others are compiler-specific workaround macros used in #ifdef switches
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// see http://www.boost.org/libs/format for library home page


// ----------------------------------------------------------------------------

#ifndef QSBOOST_FORMAT_CONFIG_MACROS_HPP
#define QSBOOST_FORMAT_CONFIG_MACROS_HPP

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>

// make sure our local macros wont override something :
#if defined(QSBOOST_NO_LOCALE_ISDIGIT) || defined(QSBOOST_OVERLOAD_FOR_NON_CONST) \
  || defined(QSBOOST_IO_STD) || defined( QSBOOST_IO_NEEDS_USING_DECLARATION ) \
    || defined(QSBOOST_NO_TEMPLATE_STD_STREAM) \
    || defined(QSBOOST_FORMAT_STREAMBUF_DEFINED) || defined(QSBOOST_FORMAT_OSTREAM_DEFINED)
#error "boost::format uses a local macro that is already defined."
#endif

// specific workarounds. each header can define BOOS_IO_STD if it 
// needs. (e.g. because of IO_NEEDS_USING_DECLARATION)
#include <qsboost/format/detail/workarounds_gcc-2_95.hpp>
#include <qsboost/format/detail/workarounds_stlport.hpp>

#ifndef QSBOOST_IO_STD
#  define QSBOOST_IO_STD ::std::
#endif

#if defined(QSBOOST_NO_STD_LOCALE) || \
 ( QSBOOST_WORKAROUND(__BORLANDC__, <= 0x564) \
   || QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT( 0x570 ) )  )
// some future __BORLANDC__ >0x564  versions might not need this
// 0x570 is Borland's kylix branch
#define QSBOOST_NO_LOCALE_ISDIGIT
#endif

#if  QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x570) ) || QSBOOST_WORKAROUND( QSBOOST_MSVC, QSBOOST_TESTED_AT(1300))
#define QSBOOST_NO_OVERLOAD_FOR_NON_CONST
#endif

// **** Workaround for io streams, stlport and msvc.
#ifdef QSBOOST_IO_NEEDS_USING_DECLARATION
namespace qsboost {
  using std::char_traits;
  using std::basic_ostream;
  namespace io {
    using std::basic_ostream;
    namespace detail {
      using std::basic_ios;
      using std::basic_ostream;
    }
  }
#if ! defined(QSBOOST_NO_STD_LOCALE)
    using std::locale;
    namespace io {
        using std::locale;
        namespace detail {
            using std::locale;
        }
    }
#endif // locale
}
  // -end N.S. boost
#endif // needs_using_declaration

#if ! defined(QSBOOST_NO_STD_LOCALE)
#include <locale>
#endif


// ***  hide std::locale if it doesnt exist. 
// this typedef is either std::locale or int, avoids placing ifdefs everywhere
namespace qsboost { namespace io { namespace detail {
#if ! defined(QSBOOST_NO_STD_LOCALE)
    typedef QSBOOST_IO_STD locale locale_t;
#else 
    typedef int          locale_t;
#endif
} } }


// ----------------------------------------------------------------------------

#endif // BOOST_FORMAT_MACROS_DEFAULT_HPP
