
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#if   QSBOOST_FT_ARITY_LOOP_PREFIX

#   ifndef QSBOOST_FT_DETAIL_COMPONENTS_IMPL_MASTER_HPP_INCLUDED
#   define QSBOOST_FT_DETAIL_COMPONENTS_IMPL_MASTER_HPP_INCLUDED
#     include <qsboost/preprocessor/cat.hpp>
#     include <qsboost/preprocessor/facilities/empty.hpp>
#     include <qsboost/preprocessor/facilities/identity.hpp>
#     include <qsboost/preprocessor/arithmetic/dec.hpp>
#     include <qsboost/preprocessor/punctuation/comma_if.hpp>
#   endif

#   define QSBOOST_FT_type_name

#   if !QSBOOST_FT_mfp

#     define QSBOOST_FT_types \
          R QSBOOST_PP_COMMA_IF(QSBOOST_FT_arity) QSBOOST_FT_params(QSBOOST_PP_EMPTY)
#   else

#     define QSBOOST_FT_types \
          R, typename class_transform<T0 QSBOOST_FT_cv, L>::type \
          QSBOOST_PP_COMMA_IF(QSBOOST_PP_DEC(QSBOOST_FT_arity)) \
          QSBOOST_FT_params(QSBOOST_PP_EMPTY)

#   endif

#elif QSBOOST_FT_ARITY_LOOP_IS_ITERATING

template< QSBOOST_FT_tplargs(QSBOOST_PP_IDENTITY(typename)), typename L>
struct components_impl<QSBOOST_FT_type, L>
{
  typedef encode_bits<QSBOOST_FT_flags,QSBOOST_FT_cc_id> bits;
  typedef constant<QSBOOST_FT_full_mask> mask;

  typedef function_types::components<QSBOOST_FT_type, L> type;
  typedef components_mpl_sequence_tag tag;

  typedef mpl::integral_c<std::size_t,QSBOOST_FT_arity> function_arity;

  typedef QSBOOST_PP_CAT(mpl::vector,QSBOOST_FT_n)< QSBOOST_FT_types > types;
};

#elif QSBOOST_FT_ARITY_LOOP_SUFFIX

#   undef QSBOOST_FT_types
#   undef QSBOOST_FT_type_name

#else
#   error "attempt to use arity loop master file without loop"
#endif

