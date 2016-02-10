//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef QSBOOST_TT_HAS_MINUS_HPP_INCLUDED
#define QSBOOST_TT_HAS_MINUS_HPP_INCLUDED

#define QSBOOST_TT_TRAIT_NAME has_minus
#define QSBOOST_TT_TRAIT_OP -
#define QSBOOST_TT_FORBIDDEN_IF\
   (\
      /* Lhs==pointer and Rhs==fundamental and Rhs!=integral */\
      (\
         ::qsboost::is_pointer< Lhs_noref >::value && \
         ::qsboost::is_fundamental< Rhs_nocv >::value && \
         (!  ::qsboost::is_integral< Rhs_noref >::value )\
      ) || \
      /* Lhs==void* and (Rhs==fundamental or Rhs==pointer) */\
      (\
         ::qsboost::is_pointer< Lhs_noref >::value && \
         ::qsboost::is_void< Lhs_noptr >::value && \
         ( \
            ::qsboost::is_fundamental< Rhs_nocv >::value || \
            ::qsboost::is_pointer< Rhs_noref >::value\
          )\
      ) || \
      /* Rhs==void* and (Lhs==fundamental or Lhs==pointer) */\
      (\
         ::qsboost::is_pointer< Rhs_noref >::value && \
         ::qsboost::is_void< Rhs_noptr >::value && \
         (\
            ::qsboost::is_fundamental< Lhs_nocv >::value || \
            ::qsboost::is_pointer< Lhs_noref >::value\
          )\
      ) ||\
      /* Lhs=fundamental and Rhs=pointer */\
      (\
         ::qsboost::is_fundamental< Lhs_nocv >::value && \
         ::qsboost::is_pointer< Rhs_noref >::value\
      ) ||\
      /* two different pointers */\
      (\
         ::qsboost::is_pointer< Lhs_noref >::value && \
         ::qsboost::is_pointer< Rhs_noref >::value && \
         (!  ::qsboost::is_same< Lhs_nocv, Rhs_nocv >::value )\
      )\
      )


#include <qsboost/type_traits/detail/has_binary_operator.hpp>

#undef QSBOOST_TT_TRAIT_NAME
#undef QSBOOST_TT_TRAIT_OP
#undef QSBOOST_TT_FORBIDDEN_IF

#endif
