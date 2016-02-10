// Boost.Range library
//
//  Copyright Neil Groves 2009.
//  Copyright Thorsten Ottosen 2003-2004. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//

#ifndef QSBOOST_RANGE_SUB_RANGE_HPP
#define QSBOOST_RANGE_SUB_RANGE_HPP

#include <qsboost/detail/workaround.hpp>

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1500)) 
    #pragma warning( push )
    #pragma warning( disable : 4996 )
#endif

#include <qsboost/range/config.hpp>
#include <qsboost/range/iterator_range.hpp>
#include <qsboost/range/value_type.hpp>
#include <qsboost/range/size_type.hpp>
#include <qsboost/range/difference_type.hpp>
#include <qsboost/range/reference.hpp>
#include <qsboost/range/algorithm/equal.hpp>
#include <qsboost/assert.hpp>
#include <qsboost/type_traits/is_reference.hpp>
#include <qsboost/type_traits/remove_reference.hpp>

namespace qsboost
{
    namespace range_detail
    {

template<class ForwardRange, class TraversalTag>
class sub_range_base
        : public iterator_range<
            QSBOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type
        >
{
    typedef iterator_range<
        QSBOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type
    > base;

protected:
    typedef QSBOOST_DEDUCED_TYPENAME base::iterator_range_ iterator_range_;

public:
    typedef QSBOOST_DEDUCED_TYPENAME range_value<ForwardRange>::type value_type;
    typedef QSBOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type iterator;
    typedef QSBOOST_DEDUCED_TYPENAME range_iterator<const ForwardRange>::type const_iterator;
    typedef QSBOOST_DEDUCED_TYPENAME range_difference<ForwardRange>::type difference_type;
    typedef QSBOOST_DEDUCED_TYPENAME range_size<ForwardRange>::type size_type;
    typedef QSBOOST_DEDUCED_TYPENAME range_reference<ForwardRange>::type reference;
    typedef QSBOOST_DEDUCED_TYPENAME range_reference<const ForwardRange>::type const_reference;

    sub_range_base()
    {
    }

    template<class Iterator>
    sub_range_base(Iterator first, Iterator last)
        : base(first, last)
    {
    }

    reference front()
    {
        return base::front();
    }

    const_reference front() const
    {
        return base::front();
    }
};

template<class ForwardRange>
class sub_range_base<ForwardRange, bidirectional_traversal_tag>
        : public sub_range_base<ForwardRange, forward_traversal_tag>
{
    typedef sub_range_base<ForwardRange, forward_traversal_tag> base;
public:
    sub_range_base()
    {
    }

    template<class Iterator>
    sub_range_base(Iterator first, Iterator last)
        : base(first, last)
    {
    }

    QSBOOST_DEDUCED_TYPENAME base::reference back()
    {
        return base::back();
    }

    QSBOOST_DEDUCED_TYPENAME base::const_reference back() const
    {
        return base::back();
    }
};

template<class ForwardRange>
class sub_range_base<ForwardRange, random_access_traversal_tag>
        : public sub_range_base<ForwardRange, bidirectional_traversal_tag>
{
    typedef sub_range_base<ForwardRange, bidirectional_traversal_tag> base;

public:
    sub_range_base()
    {
    }

    template<class Iterator>
    sub_range_base(Iterator first, Iterator last)
        : base(first, last)
    {
    }

    QSBOOST_DEDUCED_TYPENAME base::reference
    operator[](QSBOOST_DEDUCED_TYPENAME base::difference_type n)
    {
        return this->begin()[n];
    }

    QSBOOST_DEDUCED_TYPENAME base::const_reference
    operator[](QSBOOST_DEDUCED_TYPENAME base::difference_type n) const
    {
        return this->begin()[n];
    }
};

    } // namespace range_detail

    template<class ForwardRange>
    class sub_range
        : public range_detail::sub_range_base<
                ForwardRange,
                QSBOOST_DEDUCED_TYPENAME iterator_traversal<
                    QSBOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type
                >::type
            >
    {
        typedef QSBOOST_DEDUCED_TYPENAME range_iterator<
            ForwardRange
        >::type iterator_t;

        typedef range_detail::sub_range_base<
            ForwardRange,
            QSBOOST_DEDUCED_TYPENAME iterator_traversal<
                QSBOOST_DEDUCED_TYPENAME range_iterator<ForwardRange>::type
            >::type
        > base;

        typedef QSBOOST_DEDUCED_TYPENAME base::impl impl;

    protected:
        typedef QSBOOST_DEDUCED_TYPENAME base::iterator_range_ iterator_range_;

    private:
        template<class Source>
        struct is_compatible_range
            : is_convertible<
                QSBOOST_DEDUCED_TYPENAME mpl::eval_if<
                    has_range_iterator<Source>,
                    range_iterator<Source>,
                    mpl::identity<void>
                >::type,
                QSBOOST_DEDUCED_TYPENAME base::iterator
            >
        {
        };

    public:
        sub_range()
        { }

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1500) ) 
        sub_range(const sub_range& r)
            : base(impl::adl_begin(const_cast<base&>(static_cast<const base&>(r))),
                   impl::adl_end(const_cast<base&>(static_cast<const base&>(r))))
        { }  
#endif

        template< class ForwardRange2 >
        sub_range(
            ForwardRange2& r,
            QSBOOST_DEDUCED_TYPENAME ::qsboost::enable_if<
                is_compatible_range<ForwardRange2>
            >::type* = 0
        )
        : base(impl::adl_begin(r), impl::adl_end(r))
        {
        }

        template< class ForwardRange2 >
        sub_range(
            const ForwardRange2& r,
            QSBOOST_DEDUCED_TYPENAME ::qsboost::enable_if<
                is_compatible_range<const ForwardRange2>
            >::type* = 0
        )
        : base(impl::adl_begin(r), impl::adl_end(r))
        {
        }

        QSBOOST_DEDUCED_TYPENAME base::const_iterator begin() const
        {
            return base::begin();
        }

        QSBOOST_DEDUCED_TYPENAME base::iterator begin()
        {
            return base::begin();
        }

        QSBOOST_DEDUCED_TYPENAME base::const_iterator end() const
        {
            return base::end();
        }

        QSBOOST_DEDUCED_TYPENAME base::iterator end()
        {
            return base::end();
        }

        template< class Iter >
        sub_range( Iter first, Iter last ) :
            base( first, last )
        { }

        template<class ForwardRange2>
        QSBOOST_DEDUCED_TYPENAME ::qsboost::enable_if<
            is_compatible_range<ForwardRange2>,
            sub_range&
        >::type
        operator=(ForwardRange2& r)
        {
            iterator_range_::operator=( r );
            return *this;
        }

        template<class ForwardRange2>
        QSBOOST_DEDUCED_TYPENAME ::qsboost::enable_if<
            is_compatible_range<const ForwardRange2>,
            sub_range&
        >::type
        operator=( const ForwardRange2& r )
        {
            iterator_range_::operator=( r );
            return *this;
        }   

        sub_range& operator=( const sub_range& r )
        {
            iterator_range_::operator=( static_cast<const iterator_range_&>(r) );
            return *this;            
        }
        
        sub_range& advance_begin(
            QSBOOST_DEDUCED_TYPENAME base::difference_type n)
        {
            std::advance(this->m_Begin, n);
            return *this;
        }
        
        sub_range& advance_end(
            QSBOOST_DEDUCED_TYPENAME base::difference_type n)
        {
            std::advance(this->m_End, n);
            return *this;
        }
    };

} // namespace 'boost'

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, QSBOOST_TESTED_AT(1500)) 
    #pragma warning( pop )
#endif

#endif

