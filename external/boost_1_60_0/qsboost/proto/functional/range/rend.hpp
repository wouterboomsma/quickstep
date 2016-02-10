///////////////////////////////////////////////////////////////////////////////
/// \file rend.hpp
/// Proto callables for boost::rend()
//
//  Copyright 2012 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_FUNCTIONAL_RANGE_REND_HPP_EAN_27_08_2012
#define QSBOOST_PROTO_FUNCTIONAL_RANGE_REND_HPP_EAN_27_08_2012

#include <qsboost/range/rend.hpp>
#include <qsboost/proto/proto_fwd.hpp>

namespace qsboost { namespace proto { namespace functional
{

    // A PolymorphicFunctionObject that wraps boost::rend()
    struct rend
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename Rng>
        struct result<This(Rng)>
          : qsboost::range_reverse_iterator<Rng const>
        {};

        template<typename This, typename Rng>
        struct result<This(Rng &)>
          : qsboost::range_reverse_iterator<Rng>
        {};

        template<typename Rng>
        typename qsboost::range_reverse_iterator<Rng>::type operator()(Rng &rng) const
        {
            return qsboost::rend(rng);
        }

        template<typename Rng>
        typename qsboost::range_reverse_iterator<Rng const>::type operator()(Rng const &rng) const
        {
            return qsboost::rend(rng);
        }
    };

}}}

#endif
