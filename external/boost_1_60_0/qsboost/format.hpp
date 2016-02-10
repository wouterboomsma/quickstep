// ----------------------------------------------------------------------------
// format.hpp :  primary header
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/format for library home page


// ----------------------------------------------------------------------------

#ifndef QSBOOST_FORMAT_HPP
#define QSBOOST_FORMAT_HPP

#include <vector>
#include <string>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/config.hpp>

#ifndef QSBOOST_NO_STD_LOCALE
#include <locale>
#endif

// ***   Compatibility framework
#include <qsboost/format/detail/compat_workarounds.hpp>

#ifdef QSBOOST_NO_LOCALE_ISIDIGIT
#include <cctype>  // we'll use the non-locale  <cctype>'s std::isdigit(int)
#endif

// ****  Forward declarations ----------------------------------
#include <qsboost/format/format_fwd.hpp>     // basic_format<Ch,Tr>, and other frontends
#include <qsboost/format/internals_fwd.hpp>  // misc forward declarations for internal use

// ****  Auxiliary structs (stream_format_state<Ch,Tr> , and format_item<Ch,Tr> )
#include <qsboost/format/internals.hpp>    

// ****  Format  class  interface --------------------------------
#include <qsboost/format/format_class.hpp>

// **** Exceptions -----------------------------------------------
#include <qsboost/format/exceptions.hpp>

// **** Implementation -------------------------------------------
#include <qsboost/format/format_implementation.hpp>   // member functions
#include <qsboost/format/group.hpp>                   // class for grouping arguments
#include <qsboost/format/feed_args.hpp>               // argument-feeding functions
#include <qsboost/format/parsing.hpp>                 // format-string parsing (member-)functions

// **** Implementation of the free functions ----------------------
#include <qsboost/format/free_funcs.hpp>


// *** Undefine 'local' macros :
#include <qsboost/format/detail/unset_macros.hpp>

#endif // BOOST_FORMAT_HPP
