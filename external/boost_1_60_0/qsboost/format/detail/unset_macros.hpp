// ----------------------------------------------------------------------------
// unset_macros.hpp
// ----------------------------------------------------------------------------

//  Copyright Samuel Krempp 2003. Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/format for library home page

// ----------------------------------------------------------------------------

// *** Undefine 'local' macros :
#ifdef QSBOOST_NO_OVERLOAD_FOR_NON_CONST
#undef QSBOOST_NO_OVERLOAD_FOR_NON_CONST
#endif
#ifdef QSBOOST_NO_LOCALE_ISDIGIT
#undef QSBOOST_NO_LOCALE_ISDIGIT
#endif
#ifdef QSBOOST_IO_STD
#undef QSBOOST_IO_STD
#endif
#ifdef QSBOOST_IO_NEEDS_USING_DECLARATION
#undef QSBOOST_IO_NEEDS_USING_DECLARATION
#endif
#ifdef QSBOOST_NO_TEMPLATE_STD_STREAM
#undef QSBOOST_NO_TEMPLATE_STD_STREAM
#endif
#ifdef QSBOOST_FORMAT_STREAMBUF_DEFINED
#undef QSBOOST_FORMAT_STREAMBUF_DEFINED
#endif
#ifdef QSBOOST_FORMAT_OSTREAM_DEFINED
#undef QSBOOST_FORMAT_OSTREAM_DEFINED
#endif
