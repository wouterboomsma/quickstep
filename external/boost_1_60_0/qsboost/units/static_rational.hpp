// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2003-2008 Matthias Christian Schabel
// Copyright (C) 2008 Steven Watanabe
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_UNITS_STATIC_RATIONAL_HPP 
#define QSBOOST_UNITS_STATIC_RATIONAL_HPP

#include <qsboost/integer/common_factor_ct.hpp>
#include <qsboost/mpl/less.hpp>
#include <qsboost/mpl/arithmetic.hpp>

#ifdef __BORLANDC__
#include <qsboost/mpl/eval_if.hpp>
#include <qsboost/mpl/integral_c.hpp>
#include <qsboost/mpl/identity.hpp>
#endif

#include <qsboost/units/config.hpp>
#include <qsboost/units/operators.hpp>

/// \file 
/// \brief Compile-time rational numbers and operators.

namespace qsboost {

namespace units { 

namespace detail {

struct static_rational_tag {};

}

typedef long   integer_type;

/// Compile time absolute value.
template<integer_type Value>
struct static_abs
{
    QSBOOST_STATIC_CONSTANT(integer_type,value = Value < 0 ? -Value : Value);
};

// Compile time rational number.
/** 
This is an implementation of a compile time rational number, where @c static_rational<N,D> represents
a rational number with numerator @c N and denominator @c D. Because of the potential for ambiguity arising 
from multiple equivalent values of @c static_rational (e.g. @c static_rational<6,2>==static_rational<3>), 
static rationals should always be accessed through @c static_rational<N,D>::type. Template specialization 
prevents instantiation of zero denominators (i.e. @c static_rational<N,0>). The following compile-time 
arithmetic operators are provided for static_rational variables only (no operators are defined between 
long and static_rational):
    - @c mpl::negate
    - @c mpl::plus
    - @c mpl::minus
    - @c mpl::times
    - @c mpl::divides

Neither @c static_power nor @c static_root are defined for @c static_rational. This is because template types 
may not be floating point values, while powers and roots of rational numbers can produce floating point 
values. 
*/
#ifdef __BORLANDC__

template<integer_type X>
struct make_integral_c {
    typedef qsboost::mpl::integral_c<integer_type, X> type;
};

template<integer_type N,integer_type D = 1>
class static_rational
{
    public:

        typedef static_rational this_type;

        typedef qsboost::mpl::integral_c<integer_type, N> N_type;
        typedef qsboost::mpl::integral_c<integer_type, D> D_type;

        typedef typename make_integral_c<
            (::qsboost::integer::static_gcd<
                ::qsboost::units::static_abs<N>::value,
                ::qsboost::units::static_abs<D>::value
            >::value)>::type gcd_type;
        typedef typename qsboost::mpl::eval_if<
            qsboost::mpl::less<
                D_type,
                qsboost::mpl::integral_c<integer_type, 0>
            >,
            qsboost::mpl::negate<gcd_type>,
            gcd_type
        >::type den_type;
        
    public: 
        // for mpl arithmetic support
        typedef detail::static_rational_tag tag;
        
        QSBOOST_STATIC_CONSTANT(integer_type, Numerator =
            (::qsboost::mpl::divides<N_type, den_type>::value));
        QSBOOST_STATIC_CONSTANT(integer_type, Denominator =
            (::qsboost::mpl::divides<D_type, den_type>::value));
        
        /// INTERNAL ONLY
        typedef static_rational<N,D>    this_type;
        
        /// static_rational<N,D> reduced by GCD
        typedef static_rational<
            (::qsboost::mpl::divides<N_type, den_type>::value),
            (::qsboost::mpl::divides<D_type, den_type>::value)
        >  type;
                                 
        static integer_type numerator()      { return Numerator; }
        static integer_type denominator()    { return Denominator; }
        
        // INTERNAL ONLY
        static_rational() { }
        //~static_rational() { }
};
#else
template<integer_type N,integer_type D = 1>
class static_rational
{
    private:

        static const integer_type   nabs = static_abs<N>::value,
                                    dabs = static_abs<D>::value;
        
        /// greatest common divisor of N and D
        // need cast to signed because static_gcd returns unsigned long
        static const integer_type   den = 
            static_cast<integer_type>(qsboost::integer::static_gcd<nabs,dabs>::value) * ((D < 0) ? -1 : 1);
        
    public: 
        // for mpl arithmetic support
        typedef detail::static_rational_tag tag;
        
        static const integer_type   Numerator = N/den,
            Denominator = D/den;
        
        /// INTERNAL ONLY
        typedef static_rational<N,D>    this_type;
        
        /// static_rational<N,D> reduced by GCD
        typedef static_rational<Numerator,Denominator>  type;
                                 
        static integer_type numerator()      { return Numerator; }
        static integer_type denominator()    { return Denominator; }
        
        // INTERNAL ONLY
        static_rational() { }
        //~static_rational() { }   
};
#endif

}

}

#if QSBOOST_UNITS_HAS_QSBOOST_TYPEOF

#include QSBOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

QSBOOST_TYPEOF_REGISTER_TEMPLATE(qsboost::units::static_rational, (long)(long))

#endif

namespace qsboost {

namespace units {

// prohibit zero denominator
template<integer_type N> class static_rational<N,0>;

/// get decimal value of @c static_rational
template<class T,integer_type N,integer_type D>
inline typename divide_typeof_helper<T,T>::type 
value(const static_rational<N,D>&)
{
    return T(N)/T(D);
}

} // namespace units

#ifndef QSBOOST_UNITS_DOXYGEN

namespace mpl {

#ifdef __BORLANDC__

template<>
struct plus_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            ::qsboost::mpl::plus<
                qsboost::mpl::times<typename T0::N_type, typename T1::D_type>,
                qsboost::mpl::times<typename T1::N_type, typename T0::D_type>
            >::value,
            ::qsboost::mpl::times<typename T0::D_type, typename T1::D_type>::value
        >::type type;
    };
};

template<>
struct minus_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            ::qsboost::mpl::minus<
                qsboost::mpl::times<typename T0::N_type, typename T1::D_type>,
                qsboost::mpl::times<typename T1::N_type, typename T0::D_type>
            >::value,
            ::qsboost::mpl::times<typename T0::D_type, typename T1::D_type>::value
        >::type type;
    };
};

template<>
struct times_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            ::qsboost::mpl::times<typename T0::N_type, typename T1::N_type>::value,
            ::qsboost::mpl::times<typename T0::D_type, typename T1::D_type>::value
        >::type type;
    };
};

template<>
struct divides_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            ::qsboost::mpl::times<typename T0::N_type, typename T1::D_type>::value,
            ::qsboost::mpl::times<typename T0::D_type, typename T1::N_type>::value
        >::type type;
    };
};

template<>
struct negate_impl<qsboost::units::detail::static_rational_tag>
{
    template<class T0>
    struct apply {
        typedef typename qsboost::units::static_rational<
            ::qsboost::mpl::negate<typename T0::N_type>::value,
            ::qsboost::mpl::identity<T0>::type::Denominator
        >::type type;
    };
};

template<>
struct less_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef mpl::bool_<((mpl::minus<T0, T1>::type::Numerator) < 0)> type;
    };
};

#else

template<>
struct plus_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            T0::Numerator*T1::Denominator+T1::Numerator*T0::Denominator,
            T0::Denominator*T1::Denominator
        >::type type;
    };
};

template<>
struct minus_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            T0::Numerator*T1::Denominator-T1::Numerator*T0::Denominator,
            T0::Denominator*T1::Denominator
        >::type type;
    };
};

template<>
struct times_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            T0::Numerator*T1::Numerator,
            T0::Denominator*T1::Denominator
        >::type type;
    };
};

template<>
struct divides_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply {
        typedef typename qsboost::units::static_rational<
            T0::Numerator*T1::Denominator,
            T0::Denominator*T1::Numerator
        >::type type;
    };
};

template<>
struct negate_impl<qsboost::units::detail::static_rational_tag>
{
    template<class T0>
    struct apply {
        typedef typename qsboost::units::static_rational<-T0::Numerator,T0::Denominator>::type type;
    };
};

template<>
struct less_impl<qsboost::units::detail::static_rational_tag, qsboost::units::detail::static_rational_tag>
{
    template<class T0, class T1>
    struct apply
    {
        typedef mpl::bool_<((mpl::minus<T0, T1>::type::Numerator) < 0)> type;
    };
};

#endif


}

#endif

} // namespace boost

#endif // BOOST_UNITS_STATIC_RATIONAL_HPP
