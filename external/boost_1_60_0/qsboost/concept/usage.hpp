// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef QSBOOST_CONCEPT_USAGE_DWA2006919_HPP
# define QSBOOST_CONCEPT_USAGE_DWA2006919_HPP

# include <qsboost/concept/assert.hpp>
# include <qsboost/detail/workaround.hpp>
# include <qsboost/concept/detail/backward_compatibility.hpp>

namespace qsboost { namespace concepts { 

template <class Model>
struct usage_requirements
{
    ~usage_requirements() { ((Model*)0)->~Model(); }
};

#  if QSBOOST_WORKAROUND(__GNUC__, <= 3)

#   define QSBOOST_CONCEPT_USAGE(model)                                    \
      model(); /* at least 2.96 and 3.4.3 both need this :( */           \
      QSBOOST_CONCEPT_ASSERT((qsboost::concepts::usage_requirements<model>)); \
      ~model()

#  else

#   define QSBOOST_CONCEPT_USAGE(model)                                    \
      QSBOOST_CONCEPT_ASSERT((qsboost::concepts::usage_requirements<model>)); \
      ~model()

#  endif

}} // namespace boost::concepts

#endif // BOOST_CONCEPT_USAGE_DWA2006919_HPP
