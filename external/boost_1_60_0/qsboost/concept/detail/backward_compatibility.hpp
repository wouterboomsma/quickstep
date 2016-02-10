// Copyright David Abrahams 2009. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef QSBOOST_CONCEPT_BACKWARD_COMPATIBILITY_DWA200968_HPP
# define QSBOOST_CONCEPT_BACKWARD_COMPATIBILITY_DWA200968_HPP

namespace qsboost
{
  namespace concepts {}

# if defined(QSBOOST_HAS_CONCEPTS) && !defined(QSBOOST_CONCEPT_NO_BACKWARD_KEYWORD)
  namespace concept = concepts;
# endif 
} // namespace boost::concept

#endif // BOOST_CONCEPT_BACKWARD_COMPATIBILITY_DWA200968_HPP
