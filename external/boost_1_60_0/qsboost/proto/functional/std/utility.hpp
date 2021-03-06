///////////////////////////////////////////////////////////////////////////////
/// \file utility.hpp
/// Proto callables for things found in the std \<utility\> header
//
//  Copyright 2010 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_FUNCTIONAL_STD_UTILITY_HPP_EAN_11_27_2010
#define QSBOOST_PROTO_FUNCTIONAL_STD_UTILITY_HPP_EAN_11_27_2010

#include <utility>
#include <qsboost/type_traits/remove_const.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/proto/proto_fwd.hpp>

namespace qsboost { namespace proto { namespace functional
{
    /// \brief A PolymorphicFunctionObject type that invokes the
    /// \c std::make_pair() algorithm on its arguments.
    ///
    /// A PolymorphicFunctionObject type that invokes the
    /// \c std::make_pair() algorithm on its arguments.
    struct make_pair
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename First, typename Second>
        struct result<This(First, Second)>
        {
            typedef
                std::pair<
                    typename remove_const<typename remove_reference<First>::type>::type
                  , typename remove_const<typename remove_reference<Second>::type>::type
                >
            type;
        };

        template<typename First, typename Second>
        std::pair<First, Second> operator()(First const &first, Second const &second) const
        {
            return std::make_pair(first, second);
        }
    };

    /// \brief A PolymorphicFunctionObject type that returns
    /// the first element of a std::pair.
    ///
    /// A PolymorphicFunctionObject type that returns
    /// the first element of a std::pair..
    struct first
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename Pair>
        struct result<This(Pair)>
        {
            typedef typename Pair::first_type type;
        };

        template<typename This, typename Pair>
        struct result<This(Pair &)>
        {
            typedef typename Pair::first_type &type;
        };

        template<typename This, typename Pair>
        struct result<This(Pair const &)>
        {
            typedef typename Pair::first_type const &type;
        };

        template<typename Pair>
        typename Pair::first_type &operator()(Pair &pair) const
        {
            return pair.first;
        }

        template<typename Pair>
        typename Pair::first_type const &operator()(Pair const &pair) const
        {
            return pair.first;
        }
    };

    /// \brief A PolymorphicFunctionObject type that returns
    /// the second element of a std::pair.
    ///
    /// A PolymorphicFunctionObject type that returns
    /// the second element of a std::pair..
    struct second
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename Pair>
        struct result<This(Pair)>
        {
            typedef typename Pair::second_type type;
        };

        template<typename This, typename Pair>
        struct result<This(Pair &)>
        {
            typedef typename Pair::second_type &type;
        };

        template<typename This, typename Pair>
        struct result<This(Pair const &)>
        {
            typedef typename Pair::second_type const &type;
        };

        template<typename Pair>
        typename Pair::second_type &operator()(Pair &pair) const
        {
            return pair.second;
        }

        template<typename Pair>
        typename Pair::second_type const &operator()(Pair const &pair) const
        {
            return pair.second;
        }
    };

}}}

#endif
