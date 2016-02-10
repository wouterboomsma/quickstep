///////////////////////////////////////////////////////////////////////////////
/// \file push_back.hpp
/// Proto callables Fusion push_back
//
//  Copyright 2010 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_FUNCTIONAL_FUSION_PUSH_BACK_HPP_EAN_11_27_2010
#define QSBOOST_PROTO_FUNCTIONAL_FUSION_PUSH_BACK_HPP_EAN_11_27_2010

#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/remove_const.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/fusion/include/push_back.hpp>
#include <qsboost/proto/proto_fwd.hpp>

namespace qsboost { namespace proto { namespace functional
{
    /// \brief A PolymorphicFunctionObject type that invokes the
    /// \c fusion::push_back() algorithm on its argument.
    ///
    /// A PolymorphicFunctionObject type that invokes the
    /// \c fusion::push_back() algorithm on its argument.
    struct push_back
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename Seq, typename T>
        struct result<This(Seq, T)>
          : fusion::result_of::push_back<
                typename qsboost::add_const<typename qsboost::remove_reference<Seq>::type>::type
              , typename qsboost::remove_const<typename qsboost::remove_reference<T>::type>::type
            >
        {};

        template<typename Seq, typename T>
        typename fusion::result_of::push_back<Seq const, T>::type
        operator ()(Seq const &seq, T const &t) const
        {
            return fusion::push_back(seq, t);
        }
    };
}}}

#endif
