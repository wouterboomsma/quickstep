// Copyright David Abrahams 2006. Distributed under the Boost
// Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#ifndef QSBOOST_CONCEPT_DETAIL_CONCEPT_DEF_DWA200651_HPP
# define QSBOOST_CONCEPT_DETAIL_CONCEPT_DEF_DWA200651_HPP
# include <qsboost/preprocessor/seq/for_each_i.hpp>
# include <qsboost/preprocessor/seq/enum.hpp>
# include <qsboost/preprocessor/comma_if.hpp>
# include <qsboost/preprocessor/cat.hpp>
#endif // BOOST_CONCEPT_DETAIL_CONCEPT_DEF_DWA200651_HPP

// BOOST_concept(SomeName, (p1)(p2)...(pN))
//
// Expands to "template <class p1, class p2, ...class pN> struct SomeName"
//
// Also defines an equivalent SomeNameConcept for backward compatibility.
// Maybe in the next release we can kill off the "Concept" suffix for good.
# define QSBOOST_concept(name, params)                                            \
    template < QSBOOST_PP_SEQ_FOR_EACH_I(QSBOOST_CONCEPT_typename,~,params) >       \
    struct name; /* forward declaration */                                      \
                                                                                \
    template < QSBOOST_PP_SEQ_FOR_EACH_I(QSBOOST_CONCEPT_typename,~,params) >       \
    struct QSBOOST_PP_CAT(name,Concept)                                           \
      : name< QSBOOST_PP_SEQ_ENUM(params) >                                       \
    {                                                                           \
    };                                                                          \
                                                                                \
    template < QSBOOST_PP_SEQ_FOR_EACH_I(QSBOOST_CONCEPT_typename,~,params) >       \
    struct name                                                                
    
// Helper for BOOST_concept, above.
# define QSBOOST_CONCEPT_typename(r, ignored, index, t) \
    QSBOOST_PP_COMMA_IF(index) typename t

