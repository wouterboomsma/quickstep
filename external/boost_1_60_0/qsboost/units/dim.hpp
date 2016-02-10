// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2007-2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_DIM_HPP
#define QSBOOST_UNITS_DIM_HPP

#include <qsboost/static_assert.hpp>

#include <qsboost/type_traits/is_same.hpp>

#include <qsboost/mpl/arithmetic.hpp>

#include <qsboost/units/config.hpp>
#include <qsboost/units/static_rational.hpp>
#include <qsboost/units/detail/dim_impl.hpp>

/// \file dim.hpp
/// \brief Handling of fundamental dimension/exponent pairs.

namespace qsboost {

namespace units {

namespace detail {

struct dim_tag { };

}

/// \brief Dimension tag/exponent pair for a single fundamental dimension.
///
/// \details 
/// The dim class represents a single dimension tag/dimension exponent pair.
/// That is, @c dim<tag_type,value_type> is a pair where @c tag_type represents the
/// fundamental dimension being represented and @c value_type represents the 
/// exponent of that fundamental dimension as a @c static_rational. @c tag_type must 
/// be a derived from a specialization of @c base_dimension.
/// Specialization of the following Boost.MPL metafunctions are provided
///
///     - @c mpl::plus for two @c dims
///     - @c mpl::minus for two @c dims
///     - @c mpl::negate for a @c dim
///
/// These metafunctions all operate on the exponent, and require
/// that the @c dim operands have the same base dimension tag.
/// In addition, multiplication and division by @c static_rational
/// is supported.
///
///     - @c mpl::times for a @c static_rational and a @c dim in either order
///     - @c mpl::divides for a @c static_rational and a @c dim in either order
///
/// These metafunctions likewise operate on the exponent only.
template<typename T,typename V> 
struct dim
{
    typedef dim             type;
    typedef detail::dim_tag tag;
    typedef T               tag_type;
    typedef V               value_type;
};

} // namespace units

} // namespace boost

#if QSBOOST_UNITS_HAS_QSBOOST_TYPEOF

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TEMPLATE(qsboost::units::dim, 2)

#endif

#ifndef QSBOOST_UNITS_DOXYGEN

namespace qsboost {

namespace mpl {

// define MPL operators acting on dim<T,V>

template<>
struct plus_impl<qsboost::units::detail::dim_tag,qsboost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        QSBOOST_STATIC_ASSERT((qsboost::is_same<typename T0::tag_type,typename T1::tag_type>::value == true));
        typedef qsboost::units::dim<typename T0::tag_type, typename mpl::plus<typename T0::value_type, typename T1::value_type>::type> type;
    };
};

template<>
struct minus_impl<qsboost::units::detail::dim_tag,qsboost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        QSBOOST_STATIC_ASSERT((qsboost::is_same<typename T0::tag_type,typename T1::tag_type>::value == true));
        typedef qsboost::units::dim<typename T0::tag_type, typename mpl::minus<typename T0::value_type, typename T1::value_type>::type> type;
    };
};

template<>
struct times_impl<qsboost::units::detail::dim_tag,qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef qsboost::units::dim<typename T0::tag_type, typename mpl::times<typename T0::value_type, T1>::type> type;
    };
};

template<>
struct times_impl<qsboost::units::detail::static_rational_tag,qsboost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef qsboost::units::dim<typename T1::tag_type, typename mpl::times<T0, typename T1::value_type>::type> type;
    };
};

template<>
struct divides_impl<qsboost::units::detail::dim_tag,qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef qsboost::units::dim<typename T0::tag_type, typename mpl::divides<typename T0::value_type, T1>::type> type;
    };
};

template<>
struct divides_impl<qsboost::units::detail::static_rational_tag,qsboost::units::detail::dim_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef qsboost::units::dim<typename T1::tag_type, typename mpl::divides<T0, typename T1::value_type>::type> type;
    };
};

template<>
struct negate_impl<qsboost::units::detail::dim_tag>
{
    template<class T0>
    struct apply
    {
        typedef qsboost::units::dim<typename T0::tag_type,typename mpl::negate<typename T0::value_type>::type> type;
    };
};

} // namespace mpl

} // namespace boost

#endif

#endif // BOOST_UNITS_DIM_HPP
