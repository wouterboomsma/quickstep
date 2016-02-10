
// (C) Copyright Tobias Schwinger
//
// Use modification and distribution are subject to the boost Software License,
// Version 1.0. (See http://www.boost.org/LICENSE_1_0.txt).

//------------------------------------------------------------------------------

// no include guards, this file is intended for multiple inclusion

#if   QSBOOST_FT_ARITY_LOOP_PREFIX

#   ifndef QSBOOST_FT_DETAIL_SYNTHESIZE_IMPL_MASTER_HPP_INCLUDED
#   define QSBOOST_FT_DETAIL_SYNTHESIZE_IMPL_MASTER_HPP_INCLUDED
#     include <qsboost/preprocessor/cat.hpp>
#     include <qsboost/preprocessor/arithmetic/dec.hpp>
#     include <qsboost/preprocessor/iteration/local.hpp>
#     include <qsboost/preprocessor/facilities/empty.hpp>
#     include <qsboost/preprocessor/facilities/identity.hpp>
#   endif

#   define QSBOOST_FT_type_name type

#   ifdef QSBOOST_FT_flags
#     define QSBOOST_FT_make_type(flags,cc,arity) QSBOOST_FT_make_type_impl(flags,cc,arity)
#     define QSBOOST_FT_make_type_impl(flags,cc,arity) make_type_ ## flags ## _ ## cc ## _ ## arity
#   else
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_make_type(flags,cc,arity) QSBOOST_FT_make_type_impl(flags,cc,arity)
QSBOOST_PP_EXPAND(#) define QSBOOST_FT_make_type_impl(flags,cc,arity) make_type_ ## flags ## _ ## cc ## _ ## arity
#   endif

#   define QSBOOST_FT_iter(i) QSBOOST_PP_CAT(iter_,i)

#elif QSBOOST_FT_ARITY_LOOP_IS_ITERATING

template< QSBOOST_FT_tplargs(QSBOOST_PP_IDENTITY(typename)) >
struct QSBOOST_FT_make_type(QSBOOST_FT_flags,QSBOOST_FT_cc_id,QSBOOST_FT_arity)
{
  typedef QSBOOST_FT_type ;
};

template<> 
struct synthesize_impl_o< QSBOOST_FT_flags, QSBOOST_FT_cc_id, QSBOOST_FT_n > 
{ 
  template<typename S> struct synthesize_impl_i
  {
  private:
    typedef typename mpl::begin<S>::type QSBOOST_FT_iter(0);
#   if QSBOOST_FT_n > 1
#     define QSBOOST_PP_LOCAL_MACRO(i) typedef typename mpl::next< \
          QSBOOST_FT_iter(QSBOOST_PP_DEC(i)) >::type QSBOOST_FT_iter(i);
#     define QSBOOST_PP_LOCAL_LIMITS (1,QSBOOST_FT_n-1)
#     include QSBOOST_PP_LOCAL_ITERATE()
#   endif
  public:
    typedef typename detail::QSBOOST_FT_make_type(QSBOOST_FT_flags,QSBOOST_FT_cc_id,QSBOOST_FT_arity) 
    < typename mpl::deref< QSBOOST_FT_iter(0) >::type 
#   if QSBOOST_FT_mfp
    , typename detail::cv_traits< 
          typename mpl::deref< QSBOOST_FT_iter(1) >::type >::type
#   endif
#   if QSBOOST_FT_n > (QSBOOST_FT_mfp+1)
#     define QSBOOST_PP_LOCAL_LIMITS (QSBOOST_FT_mfp+1,QSBOOST_FT_n-1)
#     define QSBOOST_PP_LOCAL_MACRO(i) \
        , typename mpl::deref< QSBOOST_FT_iter(i) >::type
#     include QSBOOST_PP_LOCAL_ITERATE()
#   endif
    >::type type;
  };
};

#elif QSBOOST_FT_ARITY_LOOP_SUFFIX

#   ifdef QSBOOST_FT_flags
#     undef QSBOOST_FT_make_type
#     undef QSBOOST_FT_make_type_impl
#   else
QSBOOST_PP_EXPAND(#) undef QSBOOST_FT_make_type
QSBOOST_PP_EXPAND(#) undef QSBOOST_FT_make_type_impl
#   endif
#   undef QSBOOST_FT_iter
#   undef QSBOOST_FT_type_name

#else
#   error "attempt to use arity loop master file without loop"
#endif

