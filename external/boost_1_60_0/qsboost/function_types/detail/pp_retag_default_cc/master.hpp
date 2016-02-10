
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

#if !defined(QSBOOST_PP_VALUE)
#   include <qsboost/preprocessor/slot/slot.hpp>
#   include <qsboost/preprocessor/iteration/self.hpp>

#   include <qsboost/function_types/detail/encoding/def.hpp>
#   include <qsboost/function_types/detail/encoding/aliases_def.hpp>

namespace qsboost { namespace function_types {

namespace detail
{
  template<class Tag, class RefTag> struct selector_bits
  {
#   define  QSBOOST_PP_VALUE non_member|member|non_variadic|variadic
#   include QSBOOST_PP_ASSIGN_SLOT(1)

    QSBOOST_STATIC_CONSTANT(bits_t, value = (
        (::qsboost::function_types::detail::bits<Tag>::value & QSBOOST_FT_default_cc) 
      | (::qsboost::function_types::detail::bits<RefTag>::value & QSBOOST_PP_SLOT(1))
    ));
  };

  template<bits_t SelectorBits> struct default_cc_tag; 
  
  template<class Tag, class RefTag> struct retag_default_cc
    : detail::compound_tag
      < Tag, detail::default_cc_tag< 
          ::qsboost::function_types::detail::selector_bits<Tag,RefTag>::value > >
  { };

  template<bits_t SelectorBits> struct default_cc_tag
  {
    typedef null_tag::bits bits;
    typedef null_tag::mask mask;
  };

  class test_class;
  typedef constant<QSBOOST_FT_cc_mask> cc_mask_constant;

#   define QSBOOST_FT_self \
      <qsboost/function_types/detail/pp_retag_default_cc/master.hpp>

#   define  default_cc_ QSBOOST_FT_default_cc

#   define  QSBOOST_PP_VALUE default_cc_|non_member|non_variadic
#   define  QSBOOST_FT_tester void (*tester)()
#   define  QSBOOST_PP_INDIRECT_SELF QSBOOST_FT_self
#   include QSBOOST_PP_INCLUDE_SELF()

#   define  QSBOOST_PP_VALUE default_cc_|non_member|variadic
#   define  QSBOOST_FT_tester void (*tester)(...)
#   define  QSBOOST_PP_INDIRECT_SELF QSBOOST_FT_self
#   include QSBOOST_PP_INCLUDE_SELF()

#   define  QSBOOST_PP_VALUE default_cc_|member|non_variadic
#   define  QSBOOST_FT_tester void (test_class::*tester)()
#   define  QSBOOST_PP_INDIRECT_SELF QSBOOST_FT_self
#   include QSBOOST_PP_INCLUDE_SELF()

#   define  QSBOOST_PP_VALUE default_cc_|member|variadic
#   define  QSBOOST_FT_tester void (test_class::*tester)(...)
#   define  QSBOOST_PP_INDIRECT_SELF QSBOOST_FT_self
#   include QSBOOST_PP_INCLUDE_SELF()

#   undef   default_cc_

#   undef QSBOOST_FT_self

} } } // namespace ::boost::function_types::detail

#   include <qsboost/function_types/detail/encoding/aliases_undef.hpp>
#   include <qsboost/function_types/detail/encoding/undef.hpp>

#else // if defined(BOOST_PP_VALUE)

#   include QSBOOST_PP_ASSIGN_SLOT(1)

  template<> struct default_cc_tag<QSBOOST_PP_SLOT(1)> 
  {
    typedef QSBOOST_FT_tester;
    typedef mpl::bitand_<components<tester>::bits,cc_mask_constant> bits;
    typedef cc_mask_constant mask;
  };

#   undef QSBOOST_FT_tester

#endif

