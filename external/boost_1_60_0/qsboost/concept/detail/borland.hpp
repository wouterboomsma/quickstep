// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef QSBOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_HPP
# define QSBOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_HPP

# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/concept/detail/backward_compatibility.hpp>

namespace qsboost { namespace concepts {

template <class ModelFnPtr>
struct require;

template <class Model>
struct require<void(*)(Model)>
{
    enum { instantiate = sizeof((((Model*)0)->~Model()), 3) };
};

#  define QSBOOST_CONCEPT_ASSERT_FN( ModelFnPtr )         \
  enum                                                  \
  {                                                     \
      QSBOOST_PP_CAT(qsboost_concept_check,__LINE__) =      \
      qsboost::concepts::require<ModelFnPtr>::instantiate  \
  }

}} // namespace boost::concept

#endif // BOOST_CONCEPT_DETAIL_BORLAND_DWA2006429_HPP
