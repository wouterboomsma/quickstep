// Copyright (C) 2005 Arkadiy Vertleyb
// Copyright (C) 2005 Peder Holt
//
// Copyright (C) 2006 Tobias Schwinger
//
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_TYPEOF_VECTOR_HPP_INCLUDED

#include <qsboost/mpl/int.hpp>
#include <qsboost/preprocessor/iteration/self.hpp>

#ifndef QSBOOST_TYPEOF_LIMIT_SIZE
#   define QSBOOST_TYPEOF_LIMIT_SIZE 50
#endif

//
// To recreate the preprocessed versions of this file preprocess and run
//
//   $(BOOST_ROOT)/libs/typeof/tools/preprocess.pl
//

#if defined(QSBOOST_TYPEOF_PP_INCLUDE_EXTERNAL)

#   undef QSBOOST_TYPEOF_PP_INCLUDE_EXTERNAL

#elif !defined(QSBOOST_TYPEOF_PREPROCESSING_MODE) && !QSBOOST_PP_IS_SELFISH

#   define QSBOOST_PP_INDIRECT_SELF <qsboost/typeof/vector.hpp>
#   if   QSBOOST_TYPEOF_LIMIT_SIZE < 50
#     include QSBOOST_PP_INCLUDE_SELF()
#   elif QSBOOST_TYPEOF_LIMIT_SIZE < 100
#     include <qsboost/typeof/vector50.hpp>
#     define  QSBOOST_TYPEOF_PP_START_SIZE 51
#     include QSBOOST_PP_INCLUDE_SELF()
#   elif QSBOOST_TYPEOF_LIMIT_SIZE < 150
#     include <qsboost/typeof/vector100.hpp>
#     define  QSBOOST_TYPEOF_PP_START_SIZE 101
#     include QSBOOST_PP_INCLUDE_SELF()
#   elif QSBOOST_TYPEOF_LIMIT_SIZE < 200
#     include <qsboost/typeof/vector150.hpp>
#     define  QSBOOST_TYPEOF_PP_START_SIZE 151
#     include QSBOOST_PP_INCLUDE_SELF()
#   elif QSBOOST_TYPEOF_LIMIT_SIZE <= 250
#     include <qsboost/typeof/vector200.hpp>
#     define  QSBOOST_TYPEOF_PP_START_SIZE 201
#     include QSBOOST_PP_INCLUDE_SELF()
#   else
#     error "BOOST_TYPEOF_LIMIT_SIZE too high"
#   endif

#else// defined(BOOST_TYPEOF_PREPROCESSING_MODE) || BOOST_PP_IS_SELFISH

#   ifndef QSBOOST_TYPEOF_PP_NEXT_SIZE
#     define QSBOOST_TYPEOF_PP_NEXT_SIZE QSBOOST_TYPEOF_LIMIT_SIZE
#   endif
#   ifndef QSBOOST_TYPEOF_PP_START_SIZE
#     define QSBOOST_TYPEOF_PP_START_SIZE 0
#   endif

#   if QSBOOST_TYPEOF_PP_START_SIZE <= QSBOOST_TYPEOF_LIMIT_SIZE

#     include <qsboost/preprocessor/enum_params.hpp>
#     include <qsboost/preprocessor/repeat.hpp>
#     include <qsboost/preprocessor/repeat_from_to.hpp>
#     include <qsboost/preprocessor/cat.hpp>
#     include <qsboost/preprocessor/inc.hpp>
#     include <qsboost/preprocessor/dec.hpp>
#     include <qsboost/preprocessor/comma_if.hpp>
#     include <qsboost/preprocessor/iteration/local.hpp>
#     include <qsboost/preprocessor/control/expr_iif.hpp>
#     include <qsboost/preprocessor/logical/not.hpp>

// iterator

#     define QSBOOST_TYPEOF_spec_iter(n)\
        template<class V>\
        struct v_iter<V, mpl::int_<n> >\
        {\
            typedef typename V::item ## n type;\
            typedef v_iter<V, mpl::int_<n + 1> > next;\
        };

namespace qsboost { namespace type_of {

    template<class V, class Increase_QSBOOST_TYPEOF_LIMIT_SIZE> struct v_iter; // not defined
#     define  QSBOOST_PP_LOCAL_MACRO  QSBOOST_TYPEOF_spec_iter
#     define  QSBOOST_PP_LOCAL_LIMITS \
        (QSBOOST_PP_DEC(QSBOOST_TYPEOF_PP_START_SIZE), \
         QSBOOST_PP_DEC(QSBOOST_TYPEOF_LIMIT_SIZE))
#     include QSBOOST_PP_LOCAL_ITERATE()

}}

#     undef QSBOOST_TYPEOF_spec_iter

// vector

#     define QSBOOST_TYPEOF_typedef_item(z, n, _)\
        typedef P ## n item ## n;

#     define QSBOOST_TYPEOF_typedef_fake_item(z, n, _)\
        typedef mpl::int_<1> item ## n;

#     define QSBOOST_TYPEOF_define_vector(n)\
        template<QSBOOST_PP_ENUM_PARAMS(n, class P) QSBOOST_PP_EXPR_IIF(QSBOOST_PP_NOT(n), class T = void)>\
        struct vector ## n\
        {\
            typedef v_iter<vector ## n<QSBOOST_PP_ENUM_PARAMS(n,P)>, qsboost::mpl::int_<0> > begin;\
            QSBOOST_PP_REPEAT(n, QSBOOST_TYPEOF_typedef_item, ~)\
            QSBOOST_PP_REPEAT_FROM_TO(n, QSBOOST_TYPEOF_PP_NEXT_SIZE, QSBOOST_TYPEOF_typedef_fake_item, ~)\
        };

namespace qsboost { namespace type_of {

#     define  QSBOOST_PP_LOCAL_MACRO  QSBOOST_TYPEOF_define_vector
#     define  QSBOOST_PP_LOCAL_LIMITS \
        (QSBOOST_TYPEOF_PP_START_SIZE,QSBOOST_TYPEOF_LIMIT_SIZE)
#     include QSBOOST_PP_LOCAL_ITERATE()

}}

#     undef QSBOOST_TYPEOF_typedef_item
#     undef QSBOOST_TYPEOF_typedef_fake_item
#     undef QSBOOST_TYPEOF_define_vector

// push_back

#     define QSBOOST_TYPEOF_spec_push_back(n)\
        template<QSBOOST_PP_ENUM_PARAMS(n, class P) QSBOOST_PP_COMMA_IF(n) class T>\
        struct push_back<QSBOOST_PP_CAT(qsboost::type_of::vector, n)<QSBOOST_PP_ENUM_PARAMS(n, P)>, T>\
        {\
            typedef QSBOOST_PP_CAT(qsboost::type_of::vector, QSBOOST_PP_INC(n))<\
                QSBOOST_PP_ENUM_PARAMS(n, P) QSBOOST_PP_COMMA_IF(n) T\
            > type;\
        };

namespace qsboost { namespace type_of {

#   if   QSBOOST_TYPEOF_LIMIT_SIZE < 50
    template<class V, class T> struct push_back {
        typedef V type;
    };
#   endif
    //default behaviour is to let push_back ignore T, and return the input vector.
    //This is to let BOOST_TYPEOF_NESTED_TYPEDEF work properly with the default vector.
#     define  QSBOOST_PP_LOCAL_MACRO  QSBOOST_TYPEOF_spec_push_back
#     define  QSBOOST_PP_LOCAL_LIMITS \
        (QSBOOST_PP_DEC(QSBOOST_TYPEOF_PP_START_SIZE), \
         QSBOOST_PP_DEC(QSBOOST_TYPEOF_LIMIT_SIZE))
#     include QSBOOST_PP_LOCAL_ITERATE()

}}

#     undef QSBOOST_TYPEOF_spec_push_back

#   endif//BOOST_TYPEOF_PP_START_SIZE<=BOOST_TYPEOF_LIMIT_SIZE
#   undef  QSBOOST_TYPEOF_PP_START_SIZE
#   undef  QSBOOST_TYPEOF_PP_NEXT_SIZE

#endif//BOOST_TYPEOF_PREPROCESSING_MODE || BOOST_PP_IS_SELFISH

#define QSBOOST_TYPEOF_VECTOR_HPP_INCLUDED
#endif//BOOST_TYPEOF_VECTOR_HPP_INCLUDED

