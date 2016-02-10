///////////////////////////////////////////////////////////////////////////////
/// \file pack.hpp
/// Contains helpers for pseudo-pack expansion.
//
//  Copyright 2012 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_TRANSFORM_DETAIL_PACK_HPP_EAN_2012_07_11
#define QSBOOST_PROTO_TRANSFORM_DETAIL_PACK_HPP_EAN_2012_07_11

#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/arithmetic/inc.hpp>
#include <qsboost/preprocessor/arithmetic/dec.hpp>
#include <qsboost/preprocessor/arithmetic/sub.hpp>
#include <qsboost/preprocessor/punctuation/comma_if.hpp>
#include <qsboost/preprocessor/repetition/enum.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>
#include <qsboost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <qsboost/preprocessor/repetition/repeat.hpp>
#include <qsboost/preprocessor/iteration/local.hpp>
#include <qsboost/preprocessor/iteration/iterate.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/proto/proto_fwd.hpp>

#if defined(_MSC_VER)
# pragma warning(push)
# pragma warning(disable: 4348) // redefinition of default parameter
#endif

namespace qsboost { namespace proto
{
    namespace detail
    {
        template<typename Fun>
        struct msvc_fun_workaround;

        template<typename Tfx, typename T>
        struct expand_pattern_helper
        {
            typedef T type;
            typedef mpl::false_ applied;
        };

        template<typename Tfx, typename Fun>
        struct expand_pattern_helper<Tfx, Fun *>
          : expand_pattern_helper<Tfx, Fun>
        {};

        template<typename Tfx, typename T>
        struct expand_pattern_helper<Tfx, pack(T)>
        {
            // BUGBUG fix me. See comment in transform/detail/call.hpp
            QSBOOST_MPL_ASSERT_MSG(
                (is_same<T, _>::value)
              , PACK_EXPANSIONS_OF_EXPRESSIONS_OTHER_THAN_THE_CURRENT_NOT_YET_SUPPORTED
              , (T)
            );
            typedef Tfx type(T);
            typedef mpl::true_ applied;
        };

        template<typename Tfx>
        struct expand_pattern_helper<Tfx, pack(_)>
        {
            typedef Tfx type;
            typedef mpl::true_ applied;
        };

        #include <qsboost/proto/transform/detail/expand_pack.hpp>

        template<long Arity, typename Fun, typename Cont>
        struct expand_pattern;

        template<typename Fun, typename Cont>
        struct expand_pattern<0, Fun, Cont>
          : Cont::template cat<typename expand_pattern_helper<proto::_value, Fun>::type>
        {
            QSBOOST_MPL_ASSERT_MSG(
                (expand_pattern_helper<proto::_value, Fun>::applied::value)
              , NO_PACK_EXPRESSION_FOUND_IN_PACK_EXPANSION
              , (Fun)
            );
        };

        #include <qsboost/proto/transform/detail/pack_impl.hpp>
    }
}}

#if defined(_MSC_VER)
# pragma warning(pop)
#endif

#endif
