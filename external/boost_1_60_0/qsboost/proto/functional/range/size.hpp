///////////////////////////////////////////////////////////////////////////////
/// \file size.hpp
/// Proto callables for boost::size()
//
//  Copyright 2012 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_FUNCTIONAL_RANGE_SIZE_HPP_EAN_27_08_2012
#define QSBOOST_PROTO_FUNCTIONAL_RANGE_SIZE_HPP_EAN_27_08_2012

#include <qsboost/range/size.hpp>
#include <qsboost/proto/proto_fwd.hpp>

namespace qsboost { namespace proto { namespace functional
{

    // A PolymorphicFunctionObject that wraps boost::size()
    struct size
    {
        QSBOOST_PROTO_CALLABLE()

        template<typename Sig>
        struct result;

        template<typename This, typename Rng>
        struct result<This(Rng)>
          : qsboost::range_size<Rng>
        {};

        template<typename This, typename Rng>
        struct result<This(Rng &)>
          : qsboost::range_size<Rng>
        {};

        template<typename Rng>
        typename qsboost::range_size<Rng>::type operator()(Rng const &rng) const
        {
            return qsboost::size(rng);
        }
    };

}}}

#endif
