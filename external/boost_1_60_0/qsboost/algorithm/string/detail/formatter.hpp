//  Boost string_algo library formatter.hpp header file  ---------------------------//

//  Copyright Pavol Droba 2002-2003.
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#ifndef QSBOOST_STRING_FORMATTER_DETAIL_HPP
#define QSBOOST_STRING_FORMATTER_DETAIL_HPP


#include <qsboost/range/iterator_range_core.hpp>
#include <qsboost/range/begin.hpp>
#include <qsboost/range/end.hpp>
#include <qsboost/range/const_iterator.hpp>

#include <qsboost/algorithm/string/detail/util.hpp>

//  generic replace functors -----------------------------------------------//

namespace qsboost {
    namespace algorithm {
        namespace detail {

//  const format functor ----------------------------------------------------//

            // constant format functor
            template<typename RangeT>
            struct const_formatF
            {
            private:
                typedef QSBOOST_STRING_TYPENAME
                    range_const_iterator<RangeT>::type format_iterator;
                typedef iterator_range<format_iterator> result_type;
            
            public:
                // Construction
                const_formatF(const RangeT& Format) :
                    m_Format(::qsboost::begin(Format), ::qsboost::end(Format)) {}

                // Operation
#if QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x564))
                template<typename Range2T>
                result_type& operator()(const Range2T&)
                {
                    return m_Format;
                }
#endif

                template<typename Range2T>
                const result_type& operator()(const Range2T&) const
                {
                    return m_Format;
                }

            private:
                result_type m_Format;
            };

//  identity format functor ----------------------------------------------------//

            // identity format functor
            template<typename RangeT>
            struct identity_formatF
            {
                // Operation
                template< typename Range2T >
                const RangeT& operator()(const Range2T& Replace) const
                {
                    return RangeT(::qsboost::begin(Replace), ::qsboost::end(Replace));
                }
            };

//  empty format functor ( used by erase ) ------------------------------------//
        
            // empty format functor
            template< typename CharT >
            struct empty_formatF
            {
                template< typename ReplaceT >
                empty_container<CharT> operator()(const ReplaceT&) const
                {
                    return empty_container<CharT>();
                }
            };

//  dissect format functor ----------------------------------------------------//

            // dissect format functor
            template<typename FinderT>
            struct dissect_formatF
            {
            public:
                // Construction
                dissect_formatF(FinderT Finder) :
                  m_Finder(Finder) {}

                  // Operation
                  template<typename RangeT>
                  inline iterator_range< 
                      QSBOOST_STRING_TYPENAME range_const_iterator<RangeT>::type>
                  operator()(const RangeT& Replace) const
                  {
                      return m_Finder(::qsboost::begin(Replace), ::qsboost::end(Replace));
                  }

            private:
                FinderT m_Finder;
            };


        } // namespace detail
    } // namespace algorithm
} // namespace boost

#endif  // BOOST_STRING_FORMATTER_DETAIL_HPP
