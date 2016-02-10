/*=============================================================================
    BOOST_PP_VARIADICS version of BOOST_PP_IS_SEQ inspired from 
    boost/mpl/aux_/preprocessor/is_seq.hpp, original copyrights goes to :

    Copyright Paul Mensonides 2003
    Copyright Aleksey Gurtovoy 2003-2004

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

==============================================================================*/

#ifndef QSBOOST_FUSION_ADAPTED_STRUCT_DETAIL_PREPROCESSOR_IS_SEQ_HPP
#define QSBOOST_FUSION_ADAPTED_STRUCT_DETAIL_PREPROCESSOR_IS_SEQ_HPP

#include <qsboost/preprocessor/seq/size.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/punctuation/paren.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/config/config.hpp>

#if QSBOOST_PP_VARIADICS

#define QSBOOST_FUSION_PP_IS_SEQ(seq) QSBOOST_PP_CAT(QSBOOST_FUSION_PP_IS_SEQ_,       \
    QSBOOST_FUSION_PP_IS_SEQ_0 seq QSBOOST_PP_RPAREN())

#define QSBOOST_FUSION_PP_IS_SEQ_0(...)                                           \
    QSBOOST_FUSION_PP_IS_SEQ_1(__VA_ARGS__

#define QSBOOST_FUSION_PP_IS_SEQ_ALWAYS_0(...)                                    \
    0

#define QSBOOST_FUSION_PP_IS_SEQ_QSBOOST_FUSION_PP_IS_SEQ_0                         \
    QSBOOST_FUSION_PP_IS_SEQ_ALWAYS_0(

#define QSBOOST_FUSION_PP_IS_SEQ_QSBOOST_FUSION_PP_IS_SEQ_1(...)                    \
    1

#endif // BOOST_PP_VARIADICS

#endif
