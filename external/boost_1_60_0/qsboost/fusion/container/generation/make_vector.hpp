/*=============================================================================
    Copyright (c) 2014-2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef QSBOOSTFUSION_MAKE_VECTOR_11112014_2252
#define QSBOOSTFUSION_MAKE_VECTOR_11112014_2252

#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/container/vector/vector.hpp>

#if !defined(QSBOOST_FUSION_HAS_VARIADIC_VECTOR)
# include <qsboost/fusion/container/generation/detail/pp_make_vector.hpp>
#else

///////////////////////////////////////////////////////////////////////////////
// C++11 variadic interface
///////////////////////////////////////////////////////////////////////////////

#include <qsboost/fusion/support/detail/as_fusion_element.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/type_traits/remove_const.hpp>
#include <utility>

namespace qsboost { namespace fusion
{
    namespace result_of
    {
        template <typename ...T>
        struct make_vector
        {
            // make `make_vector<T..., void_...>' into `make_vector<T...>'
            template <typename, typename...> struct trim_void;

            template <typename... U>
            struct trim_void<vector<U...> >
            {
                typedef vector<U...> type;
            };

            template <typename... U, typename... Tail>
            struct trim_void<vector<U...>, void_, Tail...>
                : trim_void<vector<U...> > { };

            template <typename... U, typename Head, typename... Tail>
            struct trim_void<vector<U...>, Head, Tail...>
                : trim_void<vector<U..., Head>, Tail...> { };

            typedef
                typename trim_void<
                    vector<>
                  , typename detail::as_fusion_element<
                        typename remove_const<
                            typename remove_reference<T>::type
                        >::type
                    >::type...
                >::type
            type;
        };
    }

    template <typename ...T>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::make_vector<T...>::type
    make_vector(T&&... arg)
    {
        return typename result_of::make_vector<T...>::type(std::forward<T>(arg)...);
    }
 }}


#endif
#endif

