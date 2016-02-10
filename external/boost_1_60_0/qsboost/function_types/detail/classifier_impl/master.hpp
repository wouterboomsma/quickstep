
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#if QSBOOST_FT_ARITY_LOOP_PREFIX

#   ifndef QSBOOST_FT_DETAIL_CLASSIFIER_IMPL_MASTER_HPP_INCLUDED
#   define QSBOOST_FT_DETAIL_CLASSIFIER_IMPL_MASTER_HPP_INCLUDED
#     include <qsboost/preprocessor/facilities/identity.hpp>
#   endif

#   define QSBOOST_FT_type_name

#elif QSBOOST_FT_ARITY_LOOP_IS_ITERATING

template< QSBOOST_FT_tplargs(QSBOOST_PP_IDENTITY(typename)) >
typename encode_charr<QSBOOST_FT_flags,QSBOOST_FT_cc_id,QSBOOST_FT_arity>::type
classifier_impl(QSBOOST_FT_type);

#elif QSBOOST_FT_ARITY_LOOP_SUFFIX

#   undef QSBOOST_FT_type_name

#else
#   error "attempt to use arity loop master file without loop"
#endif

