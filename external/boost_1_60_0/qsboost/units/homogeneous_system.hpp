// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_HOMOGENEOUS_SYSTEM_HPP_INCLUDED
#define QSBOOST_UNITS_HOMOGENEOUS_SYSTEM_HPP_INCLUDED

#include <qsboost/mpl/bool.hpp>

#include <qsboost/units/config.hpp>
#include <qsboost/units/static_rational.hpp>

#ifdef QSBOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/mpl/not.hpp>

#include <qsboost/units/detail/linear_algebra.hpp>

#endif

namespace qsboost {

namespace units {

/// A system that can uniquely represent any unit
/// which can be composed from a linearly independent set
/// of base units.  It is safe to rebind a unit with
/// such a system to different dimensions.
///
/// Do not construct this template directly.  Use
/// make_system instead.
template<class L>
struct homogeneous_system {
    /// INTERNAL ONLY
    typedef L type;
};

template<class T, class E>
struct static_power;

template<class T, class R>
struct static_root;

/// INTERNAL ONLY
template<class L, long N, long D>
struct static_power<homogeneous_system<L>, static_rational<N,D> >
{
    typedef homogeneous_system<L> type;
};

/// INTERNAL ONLY
template<class L, long N, long D>
struct static_root<homogeneous_system<L>, static_rational<N,D> >
{
    typedef homogeneous_system<L> type;
};

namespace detail {

template<class System, class Dimensions>
struct check_system;

#ifdef QSBOOST_UNITS_CHECK_HOMOGENEOUS_UNITS

template<class L, class Dimensions>
struct check_system<homogeneous_system<L>, Dimensions> :
    qsboost::mpl::not_<
        qsboost::is_same<
            typename calculate_base_unit_exponents<
                L,
                Dimensions
            >::type,
            inconsistent
        >
    > {};

#else

template<class L, class Dimensions>
struct check_system<homogeneous_system<L>, Dimensions> : mpl::true_ {};

#endif

} // namespace detail

} // namespace units

} // namespace boost

#if QSBOOST_UNITS_HAS_QSBOOST_TYPEOF

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TEMPLATE(qsboost::units::homogeneous_system, (class))

#endif

#endif
