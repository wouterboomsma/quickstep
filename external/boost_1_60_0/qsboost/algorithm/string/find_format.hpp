//  Boost string_algo library find_format.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/ for updates, documentation, and revision history.

#ifndef QSBOOST_STRING_FIND_FORMAT_HPP
#define QSBOOST_STRING_FIND_FORMAT_HPP

#include <deque>
#include <qsboost/detail/iterator.hpp>
#include <qsboost/range/iterator_range_core.hpp>
#include <qsboost/range/begin.hpp>
#include <qsboost/range/end.hpp>
#include <qsboost/range/const_iterator.hpp>
#include <qsboost/range/as_literal.hpp>

#include <qsboost/algorithm/string/concept.hpp>
#include <qsboost/algorithm/string/detail/find_format.hpp>
#include <qsboost/algorithm/string/detail/find_format_all.hpp>

/*! \file
    Defines generic replace algorithms. Each algorithm replaces
    part(s) of the input. The part to be replaced is looked up using a Finder object.
    Result of finding is then used by a Formatter object to generate the replacement.
*/

namespace qsboost {
    namespace algorithm {

// generic replace  -----------------------------------------------------------------//

        //! Generic replace algorithm
        /*!
            Use the Finder to search for a substring. Use the Formatter to format
            this substring and replace it in the input.
            The result is a modified copy of the input. It is returned as a sequence 
            or copied to the output iterator.
    
            \param Output An output iterator to which the result will be copied
            \param Input An input sequence
            \param Finder A Finder object used to search for a match to be replaced
            \param Formatter A Formatter object used to format a match
            \return An output iterator pointing just after the last inserted character or
                a modified copy of the input

            \note The second variant of this function provides the strong exception-safety guarantee
        */
        template< 
            typename OutputIteratorT,
            typename RangeT,
            typename FinderT,
            typename FormatterT>
        inline OutputIteratorT find_format_copy(
            OutputIteratorT Output,
            const RangeT& Input,
            FinderT Finder,
            FormatterT Formatter )
        {
            // Concept check
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type>
                ));
            QSBOOST_CONCEPT_ASSERT((
                FormatterConcept<
                    FormatterT,
                    FinderT,QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type>
                ));

            iterator_range<QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> lit_input(::qsboost::as_literal(Input));

            return detail::find_format_copy_impl(
                Output,
                lit_input,
                Formatter,
                Finder( ::qsboost::begin(lit_input), ::qsboost::end(lit_input) ) );
        }

        //! Generic replace algorithm
        /*!
            \overload
        */
        template< 
            typename SequenceT, 
            typename FinderT,
            typename FormatterT>
        inline SequenceT find_format_copy(
            const SequenceT& Input,
            FinderT Finder,
            FormatterT Formatter )
        {
            // Concept check
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));
            QSBOOST_CONCEPT_ASSERT((
                FormatterConcept<
                    FormatterT,
                    FinderT,QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));

            return detail::find_format_copy_impl(
                Input,
                Formatter,
                Finder(::qsboost::begin(Input), ::qsboost::end(Input)));
        }

        //! Generic replace algorithm
        /*!
            Use the Finder to search for a substring. Use the Formatter to format
            this substring and replace it in the input. The input is modified in-place.

            \param Input An input sequence
            \param Finder A Finder object used to search for a match to be replaced
            \param Formatter A Formatter object used to format a match
        */
        template<
            typename SequenceT,
            typename FinderT,
            typename FormatterT>
        inline void find_format( 
            SequenceT& Input,
            FinderT Finder,
            FormatterT Formatter)
        {
            // Concept check
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));
            QSBOOST_CONCEPT_ASSERT(( 
                FormatterConcept<
                    FormatterT,
                    FinderT,QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));

            detail::find_format_impl(
                Input,
                Formatter,
                Finder(::qsboost::begin(Input), ::qsboost::end(Input)));
        }


//  find_format_all generic ----------------------------------------------------------------//

        //! Generic replace all algorithm
        /*!
            Use the Finder to search for a substring. Use the Formatter to format
            this substring and replace it in the input. Repeat this for all matching
            substrings.
            The result is a modified copy of the input. It is returned as a sequence 
            or copied to the output iterator.

            \param Output An output iterator to which the result will be copied
            \param Input An input sequence
            \param Finder A Finder object used to search for a match to be replaced
            \param Formatter A Formatter object used to format a match
            \return An output iterator pointing just after the last inserted character or
                a modified copy of the input

             \note The second variant of this function provides the strong exception-safety guarantee
        */
        template< 
            typename OutputIteratorT,
            typename RangeT,
            typename FinderT,
            typename FormatterT>
        inline OutputIteratorT find_format_all_copy(
            OutputIteratorT Output,
            const RangeT& Input,
            FinderT Finder,
            FormatterT Formatter)
        {
            // Concept check
            QSBOOST_CONCEPT_ASSERT(( 
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type>
                ));
            QSBOOST_CONCEPT_ASSERT(( 
                FormatterConcept<
                    FormatterT,
                    FinderT,QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type>
                ));

            iterator_range<QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type> lit_input(::qsboost::as_literal(Input));

            return detail::find_format_all_copy_impl(
                Output,
                lit_input,
                Finder,
                Formatter,
                Finder(::qsboost::begin(lit_input), ::qsboost::end(lit_input)));
        }

        //! Generic replace all algorithm
        /*!
            \overload
        */
        template< 
            typename SequenceT, 
            typename FinderT,
            typename FormatterT >
        inline SequenceT find_format_all_copy(
            const SequenceT& Input,
            FinderT Finder,
            FormatterT Formatter )
        {
            // Concept check
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));
            QSBOOST_CONCEPT_ASSERT((
                FormatterConcept<
                    FormatterT,
                    FinderT,QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));

            return detail::find_format_all_copy_impl(
                Input,
                Finder,
                Formatter,
                Finder( ::qsboost::begin(Input), ::qsboost::end(Input) ) );
        }

        //! Generic replace all algorithm
        /*!
            Use the Finder to search for a substring. Use the Formatter to format
            this substring and replace it in the input. Repeat this for all matching
            substrings.The input is modified in-place.

            \param Input An input sequence
            \param Finder A Finder object used to search for a match to be replaced
            \param Formatter A Formatter object used to format a match
        */
        template<
            typename SequenceT,
            typename FinderT,
            typename FormatterT >
        inline void find_format_all( 
            SequenceT& Input,
            FinderT Finder,
            FormatterT Formatter )
        {
            // Concept check
            QSBOOST_CONCEPT_ASSERT((
                FinderConcept<
                    FinderT,
                    QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));
            QSBOOST_CONCEPT_ASSERT((
                FormatterConcept<
                    FormatterT,
                    FinderT,QSBOOST_STRING_TYPENAME range_const_iterator<SequenceT>::type>
                ));

            detail::find_format_all_impl(
                Input,
                Finder,
                Formatter,
                Finder(::qsboost::begin(Input), ::qsboost::end(Input)));

        }

    } // namespace algorithm

    // pull the names to the boost namespace
    using algorithm::find_format_copy;
    using algorithm::find_format;
    using algorithm::find_format_all_copy;
    using algorithm::find_format_all;

} // namespace boost


#endif  // BOOST_STRING_FIND_FORMAT_HPP
