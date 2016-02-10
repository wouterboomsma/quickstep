//  Boost string_algo library iter_find.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for updates, documentation, and revision history.

#ifndef QSBOOST_STRING_ITER_FIND_HPP
#define QSBOOST_STRING_ITER_FIND_HPP

#include <qsboost/algorithm/string/config.hpp>
#include <algorithm>
#include <iterator>
#include <qsboost/iterator/transform_iterator.hpp>

#include <qsboost/range/iterator_range_core.hpp>
#include <qsboost/range/begin.hpp>
#include <qsboost/range/end.hpp>
#include <qsboost/range/iterator.hpp>
#include <qsboost/range/value_type.hpp>
#include <qsboost/range/as_literal.hpp>

#include <qsboost/algorithm/string/concept.hpp>
#include <qsboost/algorithm/string/find_iterator.hpp>
#include <qsboost/algorithm/string/detail/util.hpp>

/*! \file
    Defines generic split algorithms. Split algorithms can be 
    used to divide a sequence into several part according 
    to a given criteria. Result is given as a 'container 
    of containers' where elements are copies or references 
    to extracted parts.

    There are two algorithms provided. One iterates over matching
    substrings, the other one over the gaps between these matches.
*/

namespace qsboost {
    namespace algorithm {

//  iterate find ---------------------------------------------------//

        //! Iter find algorithm
        /*!
            This algorithm executes a given finder in iteration on the input,
            until the end of input is reached, or no match is found.
            Iteration is done using built-in find_iterator, so the real 
            searching is performed only when needed.
            In each iteration new match is found and added to the result.

            \param Result A 'container container' to contain the result of search.
                Both outer and inner container must have constructor taking a pair
                of iterators as an argument.
                Typical type of the result is 
                    \c std::vector<boost::iterator_range<iterator>>
                (each element of such a vector will container a range delimiting 
                a match).
            \param Input A container which will be searched.
            \param Finder A Finder object used for searching
            \return A reference to the result

            \note Prior content of the result will be overwritten.
        */
        template< 
            typename SequenceSequenceT,
            typename RangeT,
            typename FinderT >
        inline SequenceSequenceT&
        iter_find(
            SequenceSequenceT& Result,
            RangeT& Input,
            FinderT Finder )
        {
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_iterator<RangeT>::type>
                ));

            iterator_range<QSBOOST_STRING_TYPENAME range_iterator<RangeT>::type> lit_input(::qsboost::as_literal(Input));

            typedef QSBOOST_STRING_TYPENAME 
                range_iterator<RangeT>::type input_iterator_type;
            typedef find_iterator<input_iterator_type> find_iterator_type;
            typedef detail::copy_iterator_rangeF<
                QSBOOST_STRING_TYPENAME 
                    range_value<SequenceSequenceT>::type,
                input_iterator_type> copy_range_type;
            
            input_iterator_type InputEnd=::qsboost::end(lit_input);

            typedef transform_iterator<copy_range_type, find_iterator_type>
                transform_iter_type;
    
            transform_iter_type itBegin=
                ::qsboost::make_transform_iterator( 
                    find_iterator_type( ::qsboost::begin(lit_input), InputEnd, Finder ),
                    copy_range_type());
            
            transform_iter_type itEnd=
                ::qsboost::make_transform_iterator( 
                    find_iterator_type(),
                    copy_range_type());

            SequenceSequenceT Tmp(itBegin, itEnd);
                        
            Result.swap(Tmp);
            return Result;
        }

//  iterate split ---------------------------------------------------//

        //! Split find algorithm
        /*!
            This algorithm executes a given finder in iteration on the input,
            until the end of input is reached, or no match is found.
            Iteration is done using built-in find_iterator, so the real 
            searching is performed only when needed.
            Each match is used as a separator of segments. These segments are then
            returned in the result.

            \param Result A 'container container' to contain the result of search.
                Both outer and inner container must have constructor taking a pair
                of iterators as an argument.
                Typical type of the result is 
                    \c std::vector<boost::iterator_range<iterator>>
                (each element of such a vector will container a range delimiting 
                a match).
            \param Input A container which will be searched.
            \param Finder A finder object used for searching
            \return A reference to the result

            \note Prior content of the result will be overwritten.
        */
        template< 
            typename SequenceSequenceT,
            typename RangeT,
            typename FinderT >
        inline SequenceSequenceT&
        iter_split(
            SequenceSequenceT& Result,
            RangeT& Input,
            FinderT Finder )
        {
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<FinderT,
                QSBOOST_STRING_TYPENAME range_iterator<RangeT>::type>
                ));

            iterator_range<QSBOOST_STRING_TYPENAME range_iterator<RangeT>::type> lit_input(::qsboost::as_literal(Input));

            typedef QSBOOST_STRING_TYPENAME 
                range_iterator<RangeT>::type input_iterator_type;
            typedef split_iterator<input_iterator_type> find_iterator_type;
            typedef detail::copy_iterator_rangeF<
                QSBOOST_STRING_TYPENAME 
                    range_value<SequenceSequenceT>::type,
                input_iterator_type> copy_range_type;
            
            input_iterator_type InputEnd=::qsboost::end(lit_input);

            typedef transform_iterator<copy_range_type, find_iterator_type>
                transform_iter_type;
    
            transform_iter_type itBegin=
                ::qsboost::make_transform_iterator( 
                    find_iterator_type( ::qsboost::begin(lit_input), InputEnd, Finder ),
                    copy_range_type() );

            transform_iter_type itEnd=
                ::qsboost::make_transform_iterator( 
                    find_iterator_type(),
                    copy_range_type() );
            
            SequenceSequenceT Tmp(itBegin, itEnd);

            Result.swap(Tmp);
            return Result;
        }

    } // namespace algorithm

    // pull names to the boost namespace
    using algorithm::iter_find;
    using algorithm::iter_split;

} // namespace boost


#endif  // BOOST_STRING_ITER_FIND_HPP
