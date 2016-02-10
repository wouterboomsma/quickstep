///////////////////////////////////////////////////////////////////////////////
/// \file at.hpp
/// Proto callables Fusion at
//
//  Copyright 2010 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_FUNCTIONAL_FUSION_AT_HPP_EAN_11_27_2010
#define QSBOOST_PROTO_FUNCTIONAL_FUSION_AT_HPP_EAN_11_27_2010

#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/remove_const.hpp>
#include <qsboost/type_traits/remove_reference.hpp>
#include <qsboost/fusion/include/at.hpp>
#include <qsboost/proto/proto_fwd.hpp>

namespace qsboost { namespace proto { namespace functional
{
    /// \brief A PolymorphicFunctionObject type that invokes the
    /// \c fusion::at() accessor on its argument.
    ///
    /// A PolymorphicFunctionObject type that invokes the
    /// \c fusion::at() accessor on its argument.
    struct at
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename Seq, typename N>
        struct result<This(Seq, N)>
          : fusion::result_of::at<
                typename qsboost::remove_reference<Seq>::type
              , typename qsboost::remove_const<typename qsboost::remove_reference<N>::type>::type
            >
        {};

        template<typename Seq, typename N>
        typename fusion::result_of::at<Seq, N>::type
        operator ()(Seq &seq, N const & QSBOOST_PROTO_DISABLE_IF_IS_CONST(Seq)) const
        {
            return fusion::at<N>(seq);
        }

        template<typename Seq, typename N>
        typename fusion::result_of::at<Seq const, N>::type
        operator ()(Seq const &seq, N const &) const
        {
            return fusion::at<N>(seq);
        }
    };
}}}

#endif
