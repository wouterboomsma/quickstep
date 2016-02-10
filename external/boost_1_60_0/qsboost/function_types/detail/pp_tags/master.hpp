
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is guarded externally

#ifdef __WAVE__
// this file has been generated from the master.hpp file in the same directory
#   pragma wave option(preserve: 0)
#endif

#if !defined(QSBOOST_FT_PREPROCESSING_MODE) || defined(QSBOOST_FT_CONFIG_HPP_INCLUDED)
#   error "this file used with two-pass preprocessing, only"
#endif

#include <qsboost/preprocessor/slot/slot.hpp>
#include <qsboost/function_types/detail/encoding/def.hpp>

namespace qsboost { namespace function_types {

typedef detail::property_tag<QSBOOST_FT_non_variadic,QSBOOST_FT_variadic_mask> non_variadic;
typedef detail::property_tag<QSBOOST_FT_variadic,QSBOOST_FT_variadic_mask>     variadic;
                                                                       
typedef detail::property_tag<0,QSBOOST_FT_const>                     non_const;
typedef detail::property_tag<QSBOOST_FT_const,QSBOOST_FT_const>        const_qualified;
                                                                       
typedef detail::property_tag<0,QSBOOST_FT_volatile>                  non_volatile;
typedef detail::property_tag<QSBOOST_FT_volatile,QSBOOST_FT_volatile>  volatile_qualified; 

typedef detail::property_tag<QSBOOST_FT_default_cc,QSBOOST_FT_cc_mask> default_cc;

#define QSBOOST_PP_VALUE QSBOOST_FT_const|QSBOOST_FT_volatile 
#include QSBOOST_PP_ASSIGN_SLOT(1)

typedef detail::property_tag<0                , QSBOOST_PP_SLOT(1)> non_cv;
typedef detail::property_tag<QSBOOST_FT_const   , QSBOOST_PP_SLOT(1)> const_non_volatile;
typedef detail::property_tag<QSBOOST_FT_volatile, QSBOOST_PP_SLOT(1)> volatile_non_const;
typedef detail::property_tag<QSBOOST_PP_SLOT(1) , QSBOOST_PP_SLOT(1)> cv_qualified;

namespace detail {

  typedef constant<QSBOOST_FT_full_mask> full_mask;

  template <bits_t Flags, bits_t CCID> struct encode_bits_impl
  {
    QSBOOST_STATIC_CONSTANT( bits_t, value = 
      Flags | (QSBOOST_FT_default_cc * CCID) << 1 );
  };

  template <bits_t Flags, bits_t CCID, std::size_t Arity> 
  struct encode_charr_impl
  {
    QSBOOST_STATIC_CONSTANT(std::size_t, value = (std::size_t)(1+
      Flags | (QSBOOST_FT_default_cc * CCID) << 1 | Arity << QSBOOST_FT_arity_shift
    ));
  };

  template <bits_t Bits> struct decode_bits
  {
    QSBOOST_STATIC_CONSTANT(bits_t, flags = Bits & QSBOOST_FT_flags_mask);

    QSBOOST_STATIC_CONSTANT(bits_t, cc_id = 
      ( (Bits & QSBOOST_FT_full_mask) / QSBOOST_FT_default_cc) >> 1 
    );

    QSBOOST_STATIC_CONSTANT(bits_t, tag_bits = (Bits & QSBOOST_FT_full_mask));

    QSBOOST_STATIC_CONSTANT(std::size_t, arity = (std::size_t)
      (Bits >> QSBOOST_FT_arity_shift) 
    );
  };

  template <bits_t LHS_bits, bits_t LHS_mask, bits_t RHS_bits, bits_t RHS_mask>
  struct tag_ice
  {
    QSBOOST_STATIC_CONSTANT(bool, match =
      RHS_bits == (LHS_bits & RHS_mask & (RHS_bits |~QSBOOST_FT_type_mask))
    );

    QSBOOST_STATIC_CONSTANT(bits_t, combined_bits = 
      (LHS_bits & ~RHS_mask) | RHS_bits
    );

    QSBOOST_STATIC_CONSTANT(bits_t, combined_mask =
      LHS_mask | RHS_mask
    );

    QSBOOST_STATIC_CONSTANT(bits_t, extracted_bits =
      LHS_bits & RHS_mask
    );

  };

#define QSBOOST_FT_mask QSBOOST_FT_type_mask
  typedef property_tag<QSBOOST_FT_callable_builtin,QSBOOST_FT_mask>            callable_builtin_tag;
  typedef property_tag<QSBOOST_FT_non_member_callable_builtin,QSBOOST_FT_mask> nonmember_callable_builtin_tag;
  typedef property_tag<QSBOOST_FT_function,QSBOOST_FT_mask>       function_tag;
  typedef property_tag<QSBOOST_FT_reference,QSBOOST_FT_mask>      reference_tag;
  typedef property_tag<QSBOOST_FT_pointer,QSBOOST_FT_mask>        pointer_tag;
  typedef property_tag<QSBOOST_FT_member_function_pointer,QSBOOST_FT_mask> member_function_pointer_tag;
  typedef property_tag<QSBOOST_FT_member_object_pointer,QSBOOST_FT_mask> member_object_pointer_tag;
  typedef property_tag<QSBOOST_FT_member_object_pointer_flags,QSBOOST_FT_full_mask> member_object_pointer_base;
  typedef property_tag<QSBOOST_FT_member_pointer,QSBOOST_FT_mask> member_pointer_tag;
#undef  QSBOOST_FT_mask 

#define QSBOOST_PP_VALUE QSBOOST_FT_function|QSBOOST_FT_non_variadic|QSBOOST_FT_default_cc
#include QSBOOST_PP_ASSIGN_SLOT(1)
#define QSBOOST_PP_VALUE QSBOOST_FT_type_mask|QSBOOST_FT_variadic_mask|QSBOOST_FT_cc_mask
#include QSBOOST_PP_ASSIGN_SLOT(2)

  typedef property_tag< QSBOOST_PP_SLOT(1) , QSBOOST_PP_SLOT(2) > nv_dcc_func;

#define QSBOOST_PP_VALUE \
    QSBOOST_FT_member_function_pointer|QSBOOST_FT_non_variadic|QSBOOST_FT_default_cc
#include QSBOOST_PP_ASSIGN_SLOT(1)

  typedef property_tag< QSBOOST_PP_SLOT(1) , QSBOOST_PP_SLOT(2) > nv_dcc_mfp;

} // namespace detail

} } // namespace ::boost::function_types

