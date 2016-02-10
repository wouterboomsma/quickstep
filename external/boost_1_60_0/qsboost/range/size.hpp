// Boost.Range library
//
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef QSBOOST_RANGE_SIZE_HPP
#define QSBOOST_RANGE_SIZE_HPP

#if defined(_MSC_VER)
# pragma once
#endif

#include <qsboost/range/config.hpp>
#include <qsboost/range/begin.hpp>
#include <qsboost/range/end.hpp>
#include <qsboost/range/size_type.hpp>
#include <qsboost/range/detail/has_member_size.hpp>
#include <qsboost/assert.hpp>
#include <qsboost/cstdint.hpp>
#include <qsboost/utility.hpp>

namespace qsboost
{
    namespace range_detail
    {

        template<class SinglePassRange>
        inline typename ::qsboost::enable_if<
            has_member_size<SinglePassRange>,
            typename range_size<const SinglePassRange>::type
        >::type
        range_calculate_size(const SinglePassRange& rng)
        {
            return rng.size();
        }

        template<class SinglePassRange>
        inline typename disable_if<
            has_member_size<SinglePassRange>,
            typename range_size<const SinglePassRange>::type
        >::type
        range_calculate_size(const SinglePassRange& rng)
        {
            return std::distance(qsboost::begin(rng), qsboost::end(rng));
        }
    }

    template<class SinglePassRange>
    inline typename range_size<const SinglePassRange>::type
    size(const SinglePassRange& rng)
    {
// Very strange things happen on some compilers that have the range concept
// asserts disabled. This preprocessor condition is clearly redundant on a
// working compiler but is vital for at least some compilers such as clang 4.2
// but only on the Mac!
#if QSBOOST_RANGE_ENABLE_CONCEPT_ASSERT == 1
        QSBOOST_RANGE_CONCEPT_ASSERT((qsboost::SinglePassRangeConcept<SinglePassRange>));
#endif

#if !QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x564)) && \
    !QSBOOST_WORKAROUND(__GNUC__, < 3) \
    /**/
        using namespace range_detail;
#endif

        return range_calculate_size(rng);
    }

} // namespace 'boost'

#endif
