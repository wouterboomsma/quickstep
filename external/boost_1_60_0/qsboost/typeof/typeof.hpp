// Copyright (C) 2004 Arkadiy Vertleyb
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_TYPEOF_HPP_INCLUDED
#define QSBOOST_TYPEOF_TYPEOF_HPP_INCLUDED

#if defined(QSBOOST_TYPEOF_COMPLIANT)
#   define QSBOOST_TYPEOF_EMULATION
#endif

#if defined(QSBOOST_TYPEOF_EMULATION) && defined(QSBOOST_TYPEOF_NATIVE)
#   error both typeof emulation and native mode requested
#endif

#if defined(__COMO__)
#   ifdef __GNUG__
#       ifndef QSBOOST_TYPEOF_EMULATION
#           ifndef QSBOOST_TYPEOF_NATIVE
#               define QSBOOST_TYPEOF_NATIVE
#           endif
#           define QSBOOST_TYPEOF_KEYWORD typeof
#       endif
#   else
#       ifndef QSBOOST_TYPEOF_NATIVE
#           ifndef QSBOOST_TYPEOF_EMULATION
#               define QSBOOST_TYPEOF_EMULATION
#           endif
#       else
#           error native typeof is not supported
#       endif
#   endif

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
#   ifdef __GNUC__
#       ifndef QSBOOST_TYPEOF_EMULATION
#           ifndef QSBOOST_TYPEOF_NATIVE
#               define QSBOOST_TYPEOF_NATIVE
#           endif
#           define QSBOOST_TYPEOF_KEYWORD __typeof__
#       endif
#   else
#       ifndef QSBOOST_TYPEOF_NATIVE
#           ifndef QSBOOST_TYPEOF_EMULATION
#               define QSBOOST_TYPEOF_EMULATION
#           endif
#       else
#           error native typeof is not supported
#       endif
#   endif

#elif defined(__GNUC__)
#   ifndef QSBOOST_TYPEOF_EMULATION
#       ifndef QSBOOST_TYPEOF_NATIVE
#           define QSBOOST_TYPEOF_NATIVE
#       endif
#       define QSBOOST_TYPEOF_KEYWORD __typeof__
#   endif

#elif defined(__MWERKS__)
#   if(__MWERKS__ <= 0x3003)  // 8.x
#       ifndef QSBOOST_TYPEOF_EMULATION
#           ifndef QSBOOST_TYPEOF_NATIVE
#               define QSBOOST_TYPEOF_NATIVE
#           endif
#           define QSBOOST_TYPEOF_KEYWORD __typeof__
#       else
#           define QSBOOST_TYPEOF_EMULATION_UNSUPPORTED
#       endif
#   else // 9.x
#       ifndef QSBOOST_TYPEOF_EMULATION
#           ifndef QSBOOST_TYPEOF_NATIVE
#               define QSBOOST_TYPEOF_NATIVE
#           endif
#           define QSBOOST_TYPEOF_KEYWORD __typeof__
#       endif
#   endif
#elif defined __CODEGEARC__
#   ifndef QSBOOST_TYPEOF_EMULATION
#       ifndef QSBOOST_TYPEOF_NATIVE
#           define QSBOOST_TYPEOF_EMULATION_UNSUPPORTED
#       endif
#   else
#       define QSBOOST_TYPEOF_EMULATION_UNSUPPORTED
#   endif
#elif defined __BORLANDC__
#   ifndef QSBOOST_TYPEOF_EMULATION
#       ifndef QSBOOST_TYPEOF_NATIVE
#           define QSBOOST_TYPEOF_EMULATION_UNSUPPORTED
#       endif
#   else
#       define QSBOOST_TYPEOF_EMULATION_UNSUPPORTED
#   endif
#elif defined __DMC__
#   ifndef QSBOOST_TYPEOF_EMULATION
#       ifndef QSBOOST_TYPEOF_NATIVE
#           define QSBOOST_TYPEOF_NATIVE
#       endif
#       include <qsboost/typeof/dmc/typeof_impl.hpp>
#       define MSVC_TYPEOF_HACK
#   endif
#elif defined(_MSC_VER)
#   if (_MSC_VER <= 1300)  // 6.5, 7.0
#       ifndef QSBOOST_TYPEOF_EMULATION
#           ifndef QSBOOST_TYPEOF_NATIVE
#               define QSBOOST_TYPEOF_NATIVE
#           endif
#           include <qsboost/typeof/msvc/typeof_impl.hpp>
#           define MSVC_TYPEOF_HACK
#       else
#           error typeof emulation is not supported
#       endif
#   elif (_MSC_VER >= 1310)  // 7.1 ->
#       ifndef QSBOOST_TYPEOF_EMULATION
#           ifndef QSBOOST_TYPEOF_NATIVE
#               ifndef _MSC_EXTENSIONS
#                   define QSBOOST_TYPEOF_EMULATION
#               else
#                   define QSBOOST_TYPEOF_NATIVE
#               endif
#           endif
#       endif
#       ifdef QSBOOST_TYPEOF_NATIVE
#           include <qsboost/typeof/msvc/typeof_impl.hpp>
#           define MSVC_TYPEOF_HACK
#       endif
#   endif
#elif defined(__HP_aCC)
#   ifndef QSBOOST_TYPEOF_NATIVE
#       ifndef QSBOOST_TYPEOF_EMULATION
#           define QSBOOST_TYPEOF_EMULATION
#       endif
#   else
#       error native typeof is not supported
#   endif

#elif defined(__DECCXX)
#   ifndef QSBOOST_TYPEOF_NATIVE
#       ifndef QSBOOST_TYPEOF_EMULATION
#           define QSBOOST_TYPEOF_EMULATION
#       endif
#   else
#       error native typeof is not supported
#   endif

#elif defined(__BORLANDC__)
#   if (__BORLANDC__ < 0x590)
#       define QSBOOST_TYPEOF_NO_FUNCTION_TYPES
#       define QSBOOST_TYPEOF_NO_MEMBER_FUNCTION_TYPES
#   endif
#   ifndef QSBOOST_TYPEOF_NATIVE
#       ifndef QSBOOST_TYPEOF_EMULATION
#           define QSBOOST_TYPEOF_EMULATION
#       endif
#   else
#       error native typeof is not supported
#   endif
#elif defined(__SUNPRO_CC)
#   if (__SUNPRO_CC < 0x590 )
#     ifdef QSBOOST_TYPEOF_NATIVE
#         error native typeof is not supported
#     endif
#     ifndef QSBOOST_TYPEOF_EMULATION
#         define QSBOOST_TYPEOF_EMULATION
#     endif
#   else
#     ifndef QSBOOST_TYPEOF_EMULATION
#         ifndef QSBOOST_TYPEOF_NATIVE
#             define QSBOOST_TYPEOF_NATIVE
#         endif
#         define QSBOOST_TYPEOF_KEYWORD __typeof__
#     endif
#   endif
#else //unknown compiler
#   ifndef QSBOOST_TYPEOF_NATIVE
#       ifndef QSBOOST_TYPEOF_EMULATION
#           define QSBOOST_TYPEOF_EMULATION
#       endif
#   else
#       ifndef QSBOOST_TYPEOF_KEYWORD
#           define QSBOOST_TYPEOF_KEYWORD typeof
#       endif
#   endif

#endif

#define QSBOOST_TYPEOF_UNIQUE_ID()\
     QSBOOST_TYPEOF_REGISTRATION_GROUP * 0x10000 + __LINE__

#define QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()\
     <qsboost/typeof/incr_registration_group.hpp>

#ifdef QSBOOST_TYPEOF_EMULATION_UNSUPPORTED
#   include <qsboost/typeof/unsupported.hpp>
#elif defined QSBOOST_TYPEOF_EMULATION
#   define QSBOOST_TYPEOF_TEXT "using typeof emulation"
#   include <qsboost/typeof/message.hpp>
#   include <qsboost/typeof/typeof_impl.hpp>
#   include <qsboost/typeof/type_encoding.hpp>
#   include <qsboost/typeof/template_encoding.hpp>
#   include <qsboost/typeof/modifiers.hpp>
#   include <qsboost/typeof/pointers_data_members.hpp>
#   include <qsboost/typeof/register_functions.hpp>
#   include <qsboost/typeof/register_fundamental.hpp>

#elif defined(QSBOOST_TYPEOF_NATIVE)
#   define QSBOOST_TYPEOF_TEXT "using native typeof"
#   include <qsboost/typeof/message.hpp>
#   include <qsboost/typeof/native.hpp>
#else
#   error typeof configuration error
#endif

// auto
#define QSBOOST_AUTO(Var, Expr) QSBOOST_TYPEOF(Expr) Var = Expr
#define QSBOOST_AUTO_TPL(Var, Expr) QSBOOST_TYPEOF_TPL(Expr) Var = Expr

#endif//BOOST_TYPEOF_TYPEOF_HPP_INCLUDED
