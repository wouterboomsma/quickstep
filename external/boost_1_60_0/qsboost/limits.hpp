
//  (C) Copyright John maddock 1999. 
//  (C) David Abrahams 2002.  Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// use this header as a workaround for missing <limits>

//  See http://www.boost.org/libs/compatibility/index.html for documentation.

#ifndef QSBOOST_LIMITS
#define QSBOOST_LIMITS

#include <qsboost/config.hpp>

#ifdef QSBOOST_NO_LIMITS
#  error "There is no std::numeric_limits suppport available."
#else
# include <limits>
#endif

#if (defined(QSBOOST_HAS_LONG_LONG) && defined(QSBOOST_NO_LONG_LONG_NUMERIC_LIMITS)) \
      || (defined(QSBOOST_HAS_MS_INT64) && defined(QSBOOST_NO_MS_INT64_NUMERIC_LIMITS))
// Add missing specializations for numeric_limits:
#ifdef QSBOOST_HAS_MS_INT64
#  define QSBOOST_LLT __int64
#  define QSBOOST_ULLT unsigned __int64
#else
#  define QSBOOST_LLT  ::qsboost::long_long_type
#  define QSBOOST_ULLT  ::qsboost::ulong_long_type
#endif

#include <climits>  // for CHAR_BIT

namespace std
{
  template<>
  class numeric_limits<QSBOOST_LLT> 
  {
   public:

      QSBOOST_STATIC_CONSTANT(bool, is_specialized = true);
#ifdef QSBOOST_HAS_MS_INT64
      static QSBOOST_LLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0x8000000000000000i64; }
      static QSBOOST_LLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0x7FFFFFFFFFFFFFFFi64; }
#elif defined(LLONG_MAX)
      static QSBOOST_LLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return LLONG_MIN; }
      static QSBOOST_LLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return LLONG_MAX; }
#elif defined(LONGLONG_MAX)
      static QSBOOST_LLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return LONGLONG_MIN; }
      static QSBOOST_LLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return LONGLONG_MAX; }
#else
      static QSBOOST_LLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return 1LL << (sizeof(QSBOOST_LLT) * CHAR_BIT - 1); }
      static QSBOOST_LLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return ~(min)(); }
#endif
      QSBOOST_STATIC_CONSTANT(int, digits = sizeof(QSBOOST_LLT) * CHAR_BIT -1);
      QSBOOST_STATIC_CONSTANT(int, digits10 = (CHAR_BIT * sizeof (QSBOOST_LLT) - 1) * 301L / 1000);
      QSBOOST_STATIC_CONSTANT(bool, is_signed = true);
      QSBOOST_STATIC_CONSTANT(bool, is_integer = true);
      QSBOOST_STATIC_CONSTANT(bool, is_exact = true);
      QSBOOST_STATIC_CONSTANT(int, radix = 2);
      static QSBOOST_LLT epsilon() throw() { return 0; };
      static QSBOOST_LLT round_error() throw() { return 0; };

      QSBOOST_STATIC_CONSTANT(int, min_exponent = 0);
      QSBOOST_STATIC_CONSTANT(int, min_exponent10 = 0);
      QSBOOST_STATIC_CONSTANT(int, max_exponent = 0);
      QSBOOST_STATIC_CONSTANT(int, max_exponent10 = 0);

      QSBOOST_STATIC_CONSTANT(bool, has_infinity = false);
      QSBOOST_STATIC_CONSTANT(bool, has_quiet_NaN = false);
      QSBOOST_STATIC_CONSTANT(bool, has_signaling_NaN = false);
      QSBOOST_STATIC_CONSTANT(bool, has_denorm = false);
      QSBOOST_STATIC_CONSTANT(bool, has_denorm_loss = false);
      static QSBOOST_LLT infinity() throw() { return 0; };
      static QSBOOST_LLT quiet_NaN() throw() { return 0; };
      static QSBOOST_LLT signaling_NaN() throw() { return 0; };
      static QSBOOST_LLT denorm_min() throw() { return 0; };

      QSBOOST_STATIC_CONSTANT(bool, is_iec559 = false);
      QSBOOST_STATIC_CONSTANT(bool, is_bounded = true);
      QSBOOST_STATIC_CONSTANT(bool, is_modulo = true);

      QSBOOST_STATIC_CONSTANT(bool, traps = false);
      QSBOOST_STATIC_CONSTANT(bool, tinyness_before = false);
      QSBOOST_STATIC_CONSTANT(float_round_style, round_style = round_toward_zero);
      
  };

  template<>
  class numeric_limits<QSBOOST_ULLT> 
  {
   public:

      QSBOOST_STATIC_CONSTANT(bool, is_specialized = true);
#ifdef QSBOOST_HAS_MS_INT64
      static QSBOOST_ULLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0ui64; }
      static QSBOOST_ULLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0xFFFFFFFFFFFFFFFFui64; }
#elif defined(ULLONG_MAX) && defined(ULLONG_MIN)
      static QSBOOST_ULLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULLONG_MIN; }
      static QSBOOST_ULLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULLONG_MAX; }
#elif defined(ULONGLONG_MAX) && defined(ULONGLONG_MIN)
      static QSBOOST_ULLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULONGLONG_MIN; }
      static QSBOOST_ULLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return ULONGLONG_MAX; }
#else
      static QSBOOST_ULLT min QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return 0uLL; }
      static QSBOOST_ULLT max QSBOOST_PREVENT_MACRO_SUBSTITUTION (){ return ~0uLL; }
#endif
      QSBOOST_STATIC_CONSTANT(int, digits = sizeof(QSBOOST_LLT) * CHAR_BIT);
      QSBOOST_STATIC_CONSTANT(int, digits10 = (CHAR_BIT * sizeof (QSBOOST_LLT)) * 301L / 1000);
      QSBOOST_STATIC_CONSTANT(bool, is_signed = false);
      QSBOOST_STATIC_CONSTANT(bool, is_integer = true);
      QSBOOST_STATIC_CONSTANT(bool, is_exact = true);
      QSBOOST_STATIC_CONSTANT(int, radix = 2);
      static QSBOOST_ULLT epsilon() throw() { return 0; };
      static QSBOOST_ULLT round_error() throw() { return 0; };

      QSBOOST_STATIC_CONSTANT(int, min_exponent = 0);
      QSBOOST_STATIC_CONSTANT(int, min_exponent10 = 0);
      QSBOOST_STATIC_CONSTANT(int, max_exponent = 0);
      QSBOOST_STATIC_CONSTANT(int, max_exponent10 = 0);

      QSBOOST_STATIC_CONSTANT(bool, has_infinity = false);
      QSBOOST_STATIC_CONSTANT(bool, has_quiet_NaN = false);
      QSBOOST_STATIC_CONSTANT(bool, has_signaling_NaN = false);
      QSBOOST_STATIC_CONSTANT(bool, has_denorm = false);
      QSBOOST_STATIC_CONSTANT(bool, has_denorm_loss = false);
      static QSBOOST_ULLT infinity() throw() { return 0; };
      static QSBOOST_ULLT quiet_NaN() throw() { return 0; };
      static QSBOOST_ULLT signaling_NaN() throw() { return 0; };
      static QSBOOST_ULLT denorm_min() throw() { return 0; };

      QSBOOST_STATIC_CONSTANT(bool, is_iec559 = false);
      QSBOOST_STATIC_CONSTANT(bool, is_bounded = true);
      QSBOOST_STATIC_CONSTANT(bool, is_modulo = true);

      QSBOOST_STATIC_CONSTANT(bool, traps = false);
      QSBOOST_STATIC_CONSTANT(bool, tinyness_before = false);
      QSBOOST_STATIC_CONSTANT(float_round_style, round_style = round_toward_zero);
      
  };
}
#endif 

#endif

