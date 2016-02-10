// (C) Copyright Jeremy Siek 2002.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_ITERATOR_CONCEPTS_HPP
#define QSBOOST_ITERATOR_CONCEPTS_HPP

#include <qsboost/concept_check.hpp>
#include <qsboost/iterator/iterator_categories.hpp>

// Use boost::detail::iterator_traits to work around some MSVC/Dinkumware problems.
#include <qsboost/detail/iterator.hpp>

#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/type_traits/is_integral.hpp>

#include <qsboost/mpl/bool.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/mpl/and.hpp>
#include <qsboost/mpl/or.hpp>

#include <qsboost/static_assert.hpp>

// Use boost/limits to work around missing limits headers on some compilers
#include <qsboost/limits.hpp>
#include <qsboost/config.hpp>

#include <algorithm>

#include <qsboost/concept/detail/concept_def.hpp>

namespace qsboost_concepts
{
  // Used a different namespace here (instead of "boost") so that the
  // concept descriptions do not take for granted the names in
  // namespace boost.

  //===========================================================================
  // Iterator Access Concepts

  QSBOOST_concept(ReadableIterator,(Iterator))
    : qsboost::Assignable<Iterator>
    , qsboost::CopyConstructible<Iterator>

  {
      typedef QSBOOST_DEDUCED_TYPENAME qsboost::detail::iterator_traits<Iterator>::value_type value_type;
      typedef QSBOOST_DEDUCED_TYPENAME qsboost::detail::iterator_traits<Iterator>::reference reference;

      QSBOOST_CONCEPT_USAGE(ReadableIterator)
      {

          value_type v = *i;
          qsboost::ignore_unused_variable_warning(v);
      }
  private:
      Iterator i;
  };

  template <
      typename Iterator
    , typename ValueType = QSBOOST_DEDUCED_TYPENAME qsboost::detail::iterator_traits<Iterator>::value_type
  >
  struct WritableIterator
    : qsboost::CopyConstructible<Iterator>
  {
      QSBOOST_CONCEPT_USAGE(WritableIterator)
      {
          *i = v;
      }
  private:
      ValueType v;
      Iterator i;
  };

  template <
      typename Iterator
    , typename ValueType = QSBOOST_DEDUCED_TYPENAME qsboost::detail::iterator_traits<Iterator>::value_type
  >
  struct WritableIteratorConcept : WritableIterator<Iterator,ValueType> {};

  QSBOOST_concept(SwappableIterator,(Iterator))
  {
      QSBOOST_CONCEPT_USAGE(SwappableIterator)
      {
          std::iter_swap(i1, i2);
      }
  private:
      Iterator i1;
      Iterator i2;
  };

  QSBOOST_concept(LvalueIterator,(Iterator))
  {
      typedef typename qsboost::detail::iterator_traits<Iterator>::value_type value_type;

      QSBOOST_CONCEPT_USAGE(LvalueIterator)
      {
        value_type& r = const_cast<value_type&>(*i);
        qsboost::ignore_unused_variable_warning(r);
      }
  private:
      Iterator i;
  };


  //===========================================================================
  // Iterator Traversal Concepts

  QSBOOST_concept(IncrementableIterator,(Iterator))
    : qsboost::Assignable<Iterator>
    , qsboost::CopyConstructible<Iterator>
  {
      typedef typename qsboost::iterator_traversal<Iterator>::type traversal_category;

      QSBOOST_CONCEPT_ASSERT((
        qsboost::Convertible<
            traversal_category
          , qsboost::incrementable_traversal_tag
        >));

      QSBOOST_CONCEPT_USAGE(IncrementableIterator)
      {
          ++i;
          (void)i++;
      }
  private:
      Iterator i;
  };

  QSBOOST_concept(SinglePassIterator,(Iterator))
    : IncrementableIterator<Iterator>
    , qsboost::EqualityComparable<Iterator>

  {
      QSBOOST_CONCEPT_ASSERT((
          qsboost::Convertible<
             QSBOOST_DEDUCED_TYPENAME SinglePassIterator::traversal_category
           , qsboost::single_pass_traversal_tag
          > ));
  };

  QSBOOST_concept(ForwardTraversal,(Iterator))
    : SinglePassIterator<Iterator>
    , qsboost::DefaultConstructible<Iterator>
  {
      typedef typename qsboost::detail::iterator_traits<Iterator>::difference_type difference_type;

      QSBOOST_MPL_ASSERT((qsboost::is_integral<difference_type>));
      QSBOOST_MPL_ASSERT_RELATION(std::numeric_limits<difference_type>::is_signed, ==, true);

      QSBOOST_CONCEPT_ASSERT((
          qsboost::Convertible<
             QSBOOST_DEDUCED_TYPENAME ForwardTraversal::traversal_category
           , qsboost::forward_traversal_tag
          > ));
  };

  QSBOOST_concept(BidirectionalTraversal,(Iterator))
    : ForwardTraversal<Iterator>
  {
      QSBOOST_CONCEPT_ASSERT((
          qsboost::Convertible<
             QSBOOST_DEDUCED_TYPENAME BidirectionalTraversal::traversal_category
           , qsboost::bidirectional_traversal_tag
          > ));

      QSBOOST_CONCEPT_USAGE(BidirectionalTraversal)
      {
          --i;
          (void)i--;
      }
   private:
      Iterator i;
  };

  QSBOOST_concept(RandomAccessTraversal,(Iterator))
    : BidirectionalTraversal<Iterator>
  {
      QSBOOST_CONCEPT_ASSERT((
          qsboost::Convertible<
             QSBOOST_DEDUCED_TYPENAME RandomAccessTraversal::traversal_category
           , qsboost::random_access_traversal_tag
          > ));

      QSBOOST_CONCEPT_USAGE(RandomAccessTraversal)
      {
          i += n;
          i = i + n;
          i = n + i;
          i -= n;
          i = i - n;
          n = i - j;
      }

   private:
      typename BidirectionalTraversal<Iterator>::difference_type n;
      Iterator i, j;
  };

  //===========================================================================
  // Iterator Interoperability

  namespace detail
  {
    template <typename Iterator1, typename Iterator2>
    void interop_single_pass_constraints(Iterator1 const& i1, Iterator2 const& i2)
    {
        bool b;
        b = i1 == i2;
        b = i1 != i2;

        b = i2 == i1;
        b = i2 != i1;
        qsboost::ignore_unused_variable_warning(b);
    }

    template <typename Iterator1, typename Iterator2>
    void interop_rand_access_constraints(
        Iterator1 const& i1, Iterator2 const& i2,
        qsboost::random_access_traversal_tag, qsboost::random_access_traversal_tag)
    {
        bool b;
        typename qsboost::detail::iterator_traits<Iterator2>::difference_type n;
        b = i1 <  i2;
        b = i1 <= i2;
        b = i1 >  i2;
        b = i1 >= i2;
        n = i1 -  i2;

        b = i2 <  i1;
        b = i2 <= i1;
        b = i2 >  i1;
        b = i2 >= i1;
        n = i2 -  i1;
        qsboost::ignore_unused_variable_warning(b);
        qsboost::ignore_unused_variable_warning(n);
    }

    template <typename Iterator1, typename Iterator2>
    void interop_rand_access_constraints(
        Iterator1 const&, Iterator2 const&,
        qsboost::single_pass_traversal_tag, qsboost::single_pass_traversal_tag)
    { }

  } // namespace detail

  QSBOOST_concept(InteroperableIterator,(Iterator)(ConstIterator))
  {
   private:
      typedef typename qsboost::iterators::pure_iterator_traversal<Iterator>::type traversal_category;
      typedef typename qsboost::iterators::pure_iterator_traversal<ConstIterator>::type const_traversal_category;

   public:
      QSBOOST_CONCEPT_ASSERT((SinglePassIterator<Iterator>));
      QSBOOST_CONCEPT_ASSERT((SinglePassIterator<ConstIterator>));

      QSBOOST_CONCEPT_USAGE(InteroperableIterator)
      {
          detail::interop_single_pass_constraints(i, ci);
          detail::interop_rand_access_constraints(i, ci, traversal_category(), const_traversal_category());

          ci = i;
      }

   private:
      Iterator      i;
      ConstIterator ci;
  };

} // namespace boost_concepts

#include <qsboost/concept/detail/concept_undef.hpp>

#endif // BOOST_ITERATOR_CONCEPTS_HPP
