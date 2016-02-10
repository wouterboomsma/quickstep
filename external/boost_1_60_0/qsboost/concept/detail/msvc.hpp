// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef QSBOOST_CONCEPT_CHECK_MSVC_DWA2006429_HPP
# define QSBOOST_CONCEPT_CHECK_MSVC_DWA2006429_HPP

# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/concept/detail/backward_compatibility.hpp>
# include <qsboost/config.hpp>

# ifdef QSBOOST_OLD_CONCEPT_SUPPORT
#  include <qsboost/concept/detail/has_constraints.hpp>
#  include <qsboost/mpl/if.hpp>
# endif

# ifdef QSBOOST_MSVC
#  pragma warning(push)
#  pragma warning(disable:4100)
# endif

namespace qsboost { namespace concepts {


template <class Model>
struct check
{
    virtual void failed(Model* x)
    {
        x->~Model();
    }
};

# ifndef QSBOOST_NO_PARTIAL_SPECIALIZATION
struct failed {};
template <class Model>
struct check<failed ************ Model::************>
{
    virtual void failed(Model* x)
    {
        x->~Model();
    }
};
# endif

# ifdef QSBOOST_OLD_CONCEPT_SUPPORT
  
namespace detail
{
  // No need for a virtual function here, since evaluating
  // not_satisfied below will have already instantiated the
  // constraints() member.
  struct constraint {};
}

template <class Model>
struct require
  : mpl::if_c<
        not_satisfied<Model>::value
      , detail::constraint
# ifndef QSBOOST_NO_PARTIAL_SPECIALIZATION
      , check<Model>
# else
      , check<failed ************ Model::************>
# endif 
        >::type
{};
      
# else
  
template <class Model>
struct require
# ifndef QSBOOST_NO_PARTIAL_SPECIALIZATION
    : check<Model>
# else
    : check<failed ************ Model::************>
# endif 
{};
  
# endif
    
# if QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1310)

//
// The iterator library sees some really strange errors unless we
// do things this way.
//
template <class Model>
struct require<void(*)(Model)>
{
    virtual void failed(Model*)
    {
        require<Model>();
    }
};

# define QSBOOST_CONCEPT_ASSERT_FN( ModelFnPtr )      \
enum                                                \
{                                                   \
    QSBOOST_PP_CAT(qsboost_concept_check,__LINE__) =    \
    sizeof(::qsboost::concepts::require<ModelFnPtr>)    \
}
  
# else // Not vc-7.1
  
template <class Model>
require<Model>
require_(void(*)(Model));
  
# define QSBOOST_CONCEPT_ASSERT_FN( ModelFnPtr )          \
enum                                                    \
{                                                       \
    QSBOOST_PP_CAT(qsboost_concept_check,__LINE__) =        \
      sizeof(::qsboost::concepts::require_((ModelFnPtr)0)) \
}
  
# endif
}}

# ifdef QSBOOST_MSVC
#  pragma warning(pop)
# endif

#endif // BOOST_CONCEPT_CHECK_MSVC_DWA2006429_HPP
