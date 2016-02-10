/*=============================================================================
    Copyright (c) 2001-2009 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden
    Copyright (c) 2009-2011 Christopher Schmidt
    Copyright (c) 2013-2014 Damien Buhl

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef QSBOOST_FUSION_ADAPTED_STRUCT_DETAIL_ADAPT_BASE_HPP
#define QSBOOST_FUSION_ADAPTED_STRUCT_DETAIL_ADAPT_BASE_HPP

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/config.hpp>
#include <qsboost/fusion/support/tag_of_fwd.hpp>
#include <qsboost/fusion/adapted/struct/detail/adapt_auto.hpp>
#include <qsboost/fusion/adapted/struct/detail/adapt_is_tpl.hpp>

#include <qsboost/preprocessor/empty.hpp>
#include <qsboost/preprocessor/stringize.hpp>
#include <qsboost/preprocessor/control/if.hpp>
#include <qsboost/preprocessor/seq/size.hpp>
#include <qsboost/preprocessor/seq/for_each.hpp>
#include <qsboost/preprocessor/seq/for_each_i.hpp>
#include <qsboost/preprocessor/seq/enum.hpp>
#include <qsboost/preprocessor/seq/seq.hpp>
#include <qsboost/preprocessor/tuple/eat.hpp>
#include <qsboost/preprocessor/tuple/elem.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/comparison/less.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/tag.hpp>
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/type_traits/add_const.hpp>

#include <qsboost/typeof/typeof.hpp>


#define QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME_TEMPLATE_PARAMS(SEQ)              \
    QSBOOST_PP_SEQ_HEAD(SEQ)<QSBOOST_PP_SEQ_ENUM(QSBOOST_PP_SEQ_TAIL(SEQ))>           \
    QSBOOST_PP_EMPTY()

#define QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(SEQ)                              \
    QSBOOST_PP_IF(                                                                \
        QSBOOST_PP_SEQ_HEAD(SEQ),                                                 \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME_TEMPLATE_PARAMS,                  \
        QSBOOST_PP_SEQ_HEAD)(QSBOOST_PP_SEQ_TAIL(SEQ))

#define QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS_IMPL_C(R, _, ELEM)     \
    (typename ELEM)
#define QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS_IMPL(SEQ)              \
    QSBOOST_PP_SEQ_ENUM(                                                          \
        QSBOOST_PP_SEQ_FOR_EACH(                                                  \
            QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS_IMPL_C,            \
            _,                                                                  \
            QSBOOST_PP_SEQ_TAIL(SEQ)))
#define QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(SEQ)                   \
    QSBOOST_PP_IF(                                                                \
        QSBOOST_PP_SEQ_HEAD(SEQ),                                                 \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS_IMPL,                  \
        QSBOOST_PP_TUPLE_EAT(1))(SEQ)

#ifdef QSBOOST_MSVC
#   define QSBOOST_FUSION_ATTRIBUTE_TYPEOF(                                       \
        NAME_SEQ, ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, PREFIX, TEMPLATE_PARAMS_SEQ) \
                                                                                \
    QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS(                    \
        TEMPLATE_PARAMS_SEQ)                                                    \
                                                                                \
    struct deduced_attr_type {                                                  \
      static const QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)& obj;        \
      typedef                                                                   \
      QSBOOST_PP_IF(QSBOOST_FUSION_ADAPT_IS_TPL(TEMPLATE_PARAMS_SEQ), typename, )   \
      QSBOOST_TYPEOF( PREFIX() obj.QSBOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE,      \
            0, ATTRIBUTE))                                                      \
      type;                                                                     \
    };                                                                          \
                                                                                \
    typedef                                                                     \
        QSBOOST_PP_IF(QSBOOST_FUSION_ADAPT_IS_TPL(TEMPLATE_PARAMS_SEQ), typename, ) \
        deduced_attr_type::type attribute_type;

#else 
#   define QSBOOST_FUSION_ATTRIBUTE_TYPEOF(                                       \
        NAME_SEQ, ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, PREFIX, TEMPLATE_PARAMS_SEQ) \
                                                                                \
    struct deduced_attr_type {                                                  \
      static const QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)& obj;        \
      typedef QSBOOST_TYPEOF(                                                     \
          PREFIX() obj.QSBOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE, 0, ATTRIBUTE)) \
      type;                                                                     \
    };                                                                          \
                                                                                \
    typedef                                                                     \
        QSBOOST_PP_IF(QSBOOST_FUSION_ADAPT_IS_TPL(TEMPLATE_PARAMS_SEQ), typename, ) \
        deduced_attr_type::type attribute_type;

#endif

#define QSBOOST_FUSION_ATTRIBUTE_GIVENTYPE(                                       \
    NAME_SEQ, ATTRIBUTE, ATTRIBUTE_TUPEL_SIZE, PREFIX, TEMPLATE_PARAMS_SEQ)     \
    typedef                                                                     \
        QSBOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE, 0, ATTRIBUTE) attribute_type;
   

#ifdef QSBOOST_NO_PARTIAL_SPECIALIZATION_IMPLICIT_DEFAULT_ARGS
#   define QSBOOST_FUSION_ADAPT_STRUCT_TAG_OF_SPECIALIZATION(                     \
        MODIFIER, TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)                           \
                                                                                \
    template<                                                                   \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct tag_of<                                                              \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ) MODIFIER                \
      , void                                                                    \
    >                                                                           \
    {                                                                           \
        typedef TAG type;                                                       \
    };
#else
#   define QSBOOST_FUSION_ADAPT_STRUCT_TAG_OF_SPECIALIZATION(                     \
        MODIFIER, TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)                           \
                                                                                \
    template<                                                                   \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct tag_of<QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ) MODIFIER>     \
    {                                                                           \
        typedef TAG type;                                                       \
    };
#endif

#define QSBOOST_FUSION_ADAPT_STRUCT_BASE_UNPACK_AND_CALL(R,DATA,I,ATTRIBUTE)      \
    QSBOOST_PP_TUPLE_ELEM(4,0,DATA)(                                              \
        QSBOOST_PP_TUPLE_ELEM(4,1,DATA),                                          \
        QSBOOST_PP_TUPLE_ELEM(4,2,DATA),                                          \
        QSBOOST_PP_TUPLE_ELEM(4,3,DATA),                                          \
        I,                                                                      \
        ATTRIBUTE)

#ifdef QSBOOST_MSVC
#   define QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAM(R,_,ELEM)     \
        typedef ELEM ELEM;
#   define QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS_IMPL(SEQ)    \
        QSBOOST_PP_SEQ_FOR_EACH(                                                  \
            QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAM,             \
            _,                                                                  \
            QSBOOST_PP_SEQ_TAIL(SEQ))
#   define QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS(SEQ)         \
        QSBOOST_PP_IF(                                                            \
            QSBOOST_PP_SEQ_HEAD(SEQ),                                             \
            QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS_IMPL,       \
            QSBOOST_PP_TUPLE_EAT(1))(SEQ)
#else
#   define QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS(SEQ)
#endif

#define QSBOOST_FUSION_ADAPT_STRUCT_C_BASE(                                       \
    TEMPLATE_PARAMS_SEQ,NAME_SEQ,IS_VIEW,                                       \
    I,PREFIX,ATTRIBUTE,ATTRIBUTE_TUPEL_SIZE,                                    \
    DEDUCE_TYPE)                                                                \
                                                                                \
    template<                                                                   \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct access::struct_member<                                               \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                         \
      , I                                                                       \
    >                                                                           \
    {                                                                           \
        QSBOOST_PP_IF(DEDUCE_TYPE,                                                \
            QSBOOST_FUSION_ATTRIBUTE_TYPEOF, QSBOOST_FUSION_ATTRIBUTE_GIVENTYPE)(   \
                NAME_SEQ,                                                       \
                ATTRIBUTE,                                                      \
                ATTRIBUTE_TUPEL_SIZE,                                           \
                PREFIX,                                                         \
                TEMPLATE_PARAMS_SEQ)                                            \
                                                                                \
        QSBOOST_FUSION_ADAPT_STRUCT_MSVC_REDEFINE_TEMPLATE_PARAMS(                \
            TEMPLATE_PARAMS_SEQ)                                                \
                                                                                \
        typedef attribute_type type;                                            \
                                                                                \
        template<typename Seq>                                                  \
        struct apply                                                            \
        {                                                                       \
            typedef typename                                                    \
                add_reference<                                                  \
                    typename mpl::eval_if<                                      \
                        is_const<Seq>                                           \
                      , add_const<attribute_type>                               \
                      , mpl::identity<attribute_type>                           \
                    >::type                                                     \
                >::type                                                         \
            type;                                                               \
                                                                                \
            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED                            \
            static type                                                         \
            call(Seq& seq)                                                      \
            {                                                                   \
                return seq.PREFIX()                                             \
                    QSBOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE,                   \
                        QSBOOST_PP_IF(DEDUCE_TYPE, 0, 1), ATTRIBUTE);             \
            }                                                                   \
        };                                                                      \
    };                                                                          \
                                                                                \
    template<                                                                   \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(TEMPLATE_PARAMS_SEQ)   \
    >                                                                           \
    struct struct_member_name<                                                  \
        QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                         \
      , I                                                                       \
    >                                                                           \
    {                                                                           \
        typedef char const* type;                                               \
                                                                                \
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED                                \
        static type                                                             \
        call()                                                                  \
        {                                                                       \
            return QSBOOST_PP_STRINGIZE(                                          \
               QSBOOST_PP_TUPLE_ELEM(ATTRIBUTE_TUPEL_SIZE,                        \
                        QSBOOST_PP_IF(DEDUCE_TYPE, 0, 1),                         \
                          ATTRIBUTE));                                          \
        }                                                                       \
    };

#define QSBOOST_FUSION_ADAPT_STRUCT_BASE(                                         \
    TEMPLATE_PARAMS_SEQ,                                                        \
    NAME_SEQ,                                                                   \
    TAG,                                                                        \
    IS_VIEW,                                                                    \
    ATTRIBUTES_SEQ,                                                             \
    ATTRIBUTES_CALLBACK)                                                        \
                                                                                \
namespace qsboost                                                                 \
{                                                                               \
    namespace fusion                                                            \
    {                                                                           \
        namespace traits                                                        \
        {                                                                       \
            QSBOOST_FUSION_ADAPT_STRUCT_TAG_OF_SPECIALIZATION(                    \
                QSBOOST_PP_EMPTY(), TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)           \
            QSBOOST_FUSION_ADAPT_STRUCT_TAG_OF_SPECIALIZATION(                    \
                const, TEMPLATE_PARAMS_SEQ, NAME_SEQ, TAG)                      \
        }                                                                       \
                                                                                \
        namespace extension                                                     \
        {                                                                       \
            QSBOOST_PP_IF(                                                        \
                QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ATTRIBUTES_SEQ)),                \
                QSBOOST_PP_SEQ_FOR_EACH_I_R,                                      \
                QSBOOST_PP_TUPLE_EAT(4))(                                         \
                    1,                                                          \
                    QSBOOST_FUSION_ADAPT_STRUCT_BASE_UNPACK_AND_CALL,             \
                    (ATTRIBUTES_CALLBACK,TEMPLATE_PARAMS_SEQ,NAME_SEQ, IS_VIEW),\
                    QSBOOST_PP_SEQ_TAIL(ATTRIBUTES_SEQ))                          \
                                                                                \
            template<                                                           \
                QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(               \
                    TEMPLATE_PARAMS_SEQ)                                        \
            >                                                                   \
            struct struct_size<QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)> \
              : mpl::int_<QSBOOST_PP_DEC(QSBOOST_PP_SEQ_SIZE(ATTRIBUTES_SEQ))>      \
            {};                                                                 \
                                                                                \
            template<                                                           \
                QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(               \
                    TEMPLATE_PARAMS_SEQ)                                        \
            >                                                                   \
            struct struct_is_view<                                              \
                QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)                 \
            >                                                                   \
              : mpl::QSBOOST_PP_IF(IS_VIEW,true_,false_)                          \
            {};                                                                 \
        }                                                                       \
    }                                                                           \
                                                                                \
    namespace mpl                                                               \
    {                                                                           \
        template<typename>                                                      \
        struct sequence_tag;                                                    \
                                                                                \
        template<                                                               \
            QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(                   \
                TEMPLATE_PARAMS_SEQ)                                            \
        >                                                                       \
        struct sequence_tag<QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ)>    \
        {                                                                       \
            typedef fusion::fusion_sequence_tag type;                           \
        };                                                                      \
                                                                                \
        template<                                                               \
            QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_TEMPLATE_PARAMS(                   \
                TEMPLATE_PARAMS_SEQ)                                            \
        >                                                                       \
        struct sequence_tag<                                                    \
            QSBOOST_FUSION_ADAPT_STRUCT_UNPACK_NAME(NAME_SEQ) const               \
        >                                                                       \
        {                                                                       \
            typedef fusion::fusion_sequence_tag type;                           \
        };                                                                      \
    }                                                                           \
}

#endif
