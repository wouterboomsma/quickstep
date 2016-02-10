
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

#ifndef QSBOOST_FT_CONFIG_COMPILER_HPP_INCLUDED
#define QSBOOST_FT_CONFIG_COMPILER_HPP_INCLUDED

#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>

#if defined(QSBOOST_MSVC)

#   if QSBOOST_MSVC < 1310
#     error "unsupported compiler version"
#   endif

#   ifdef QSBOOST_FT_AUTODETECT_CALLING_CONVENTIONS

      // enable clrcall calling covention (call to .NET managed code) when
      // compiling with /clr 
#     if QSBOOST_MSVC >= 1400 && defined(__cplusplus_cli)
#       ifndef QSBOOST_FT_CC_CLRCALL
#       define QSBOOST_FT_CC_CLRCALL callable_builtin
#       endif
#     endif

      // Intel x86 architecture specific calling conventions
#     ifdef _M_IX86
#       define QSBOOST_FT_COMMON_X86_CCs callable_builtin
#       if QSBOOST_MSVC < 1400
          // version 7.1 is missing a keyword to specify the thiscall cc ...
#         ifndef QSBOOST_FT_CC_IMPLICIT_THISCALL
#         define QSBOOST_FT_CC_IMPLICIT_THISCALL non_variadic|member|callable_builtin
#         ifndef QSBOOST_FT_CONFIG_OK
#           pragma message("INFO| /Gd /Gr /Gz will compiler options will cause")
#           pragma message("INFO| a compile error.")
#           pragma message("INFO| Reconfigure Boost.FunctionTypes in this case.")
#           pragma message("INFO| This message can be suppressed by defining")
#           pragma message("INFO| BOOST_FT_CONFIG_OK.")
#         endif
#         endif
#       else 
          // ...introduced in version 8
#         ifndef QSBOOST_FT_CC_THISCALL
#         define QSBOOST_FT_CC_THISCALL non_variadic|member|callable_builtin
#         endif
#       endif
#     endif
#   endif

#elif defined(__GNUC__) && !defined(QSBOOST_INTEL_LINUX)

#   if __GNUC__ < 3
#     error "unsupported compiler version"
#   endif

#   ifdef QSBOOST_FT_AUTODETECT_CALLING_CONVENTIONS

#     if defined(__i386__)
#       // see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=20439
#       // see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=29328
#       if QSBOOST_WORKAROUND(__GNUC__,QSBOOST_TESTED_AT(4))
#         ifndef QSBOOST_FT_CC_IMPLICIT 
#         define QSBOOST_FT_CC_IMPLICIT member|callable_builtin
#         endif
#         define QSBOOST_FT_COMMON_X86_CCs non_member|callable_builtin
#       else
#         define QSBOOST_FT_COMMON_X86_CCs callable_builtin
#       endif
#     else
#       ifndef QSBOOST_FT_CC_IMPLICIT
#       define QSBOOST_FT_CC_IMPLICIT callable_builtin
#       endif
#     endif
#   endif

#   if (defined(QSBOOST_FT_CC_CDECL) || defined(QSBOOST_FT_COMMON_X86_CCs)) \
        && !defined(__cdecl)
#     define __cdecl __attribute__((__cdecl__))
#   endif
#   if (defined(QSBOOST_FT_CC_STDCALL) || defined(QSBOOST_FT_COMMON_X86_CCs)) \
        && !defined(__stdcall)
#     define __stdcall __attribute__((__stdcall__))
#   endif
#   if (defined(QSBOOST_FT_CC_FASTCALL) || defined(QSBOOST_FT_COMMON_X86_CCs)) \
        && !defined(__fastcall)
#     define __fastcall __attribute__((__fastcall__))
#   endif

#elif defined(__BORLANDC__)

#   if __BORLANDC__ < 0x550
#     error "unsupported compiler version"
#   elif __BORLANDC__ > 0x565
#     pragma message("WARNING: library untested with this compiler version")
#   endif

#   ifdef QSBOOST_FT_AUTODETECT_CALLING_CONVENTIONS
#     define QSBOOST_FT_COMMON_X86_CCs callable_builtin
#   endif

    // syntactic specialities of cc specifier
#   define QSBOOST_FT_SYNTAX(result,lparen,cc_spec,type_mod,name,rparen) \
                        result() cc_spec() lparen() type_mod() name() rparen()
#else
    // only enable default calling convention
#   define QSBOOST_FT_CC_IMPLICIT callable_builtin
#endif


#endif

