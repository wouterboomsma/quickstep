///////////////////////////////////////////////////////////////////////////////
/// \file empty.hpp
/// Proto callables for boost::empty()
//
//  Copyright 2012 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_FUNCTIONAL_RANGE_EMPTY_HPP_EAN_27_08_2012
#define QSBOOST_PROTO_FUNCTIONAL_RANGE_EMPTY_HPP_EAN_27_08_2012

#include <qsboost/range/empty.hpp>
#include <qsboost/proto/proto_fwd.hpp>

namespace qsboost { namespace proto { namespace functional
{

    // A PolymorphicFunctionObject that wraps boost::empty()
    struct empty
    {
        QSBOOST_PROTO_CALLABLE()

        typedef bool result_type;

        template<typename Rng>
        bool operator()(Rng const &rng) const
        {
            return qsboost::empty(rng);
        }
    };

}}}

#endif
