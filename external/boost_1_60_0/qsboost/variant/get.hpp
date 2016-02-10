//-----------------------------------------------------------------------------
// boost variant/get.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2003 Eric Friedman, Itay Maman
// Copyright (c) 2014 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_GET_HPP
#define QSBOOST_VARIANT_GET_HPP

#include <exception>

#include "qsboost/config.hpp"
#include "qsboost/detail/workaround.hpp"
#include "qsboost/static_assert.hpp"
#include "qsboost/throw_exception.hpp"
#include "qsboost/utility/addressof.hpp"
#include "qsboost/variant/variant_fwd.hpp"
#include "qsboost/variant/detail/element_index.hpp"

#include "qsboost/type_traits/add_reference.hpp"
#include "qsboost/type_traits/add_pointer.hpp"

namespace qsboost {

//////////////////////////////////////////////////////////////////////////
// class bad_get
//
// The exception thrown in the event of a failed get of a value.
//
class QSBOOST_SYMBOL_VISIBLE bad_get
    : public std::exception
{
public: // std::exception implementation

    virtual const char * what() const QSBOOST_NOEXCEPT_OR_NOTHROW
    {
        return "boost::bad_get: "
               "failed value get using boost::get";
    }

};

//////////////////////////////////////////////////////////////////////////
// function template get<T>
//
// Retrieves content of given variant object if content is of type T.
// Otherwise: pointer ver. returns 0; reference ver. throws bad_get.
//

namespace detail { namespace variant {

// (detail) class template get_visitor
//
// Generic static visitor that: if the value is of the specified type,
// returns a pointer to the value it visits; else a null pointer.
//
template <typename T>
struct get_visitor
{
private: // private typedefs

    typedef typename add_pointer<T>::type pointer;
    typedef typename add_reference<T>::type reference;

public: // visitor typedefs

    typedef pointer result_type;

public: // visitor interfaces

    pointer operator()(reference operand) const QSBOOST_NOEXCEPT
    {
        return qsboost::addressof(operand);
    }

    template <typename U>
    pointer operator()(const U&) const QSBOOST_NOEXCEPT
    {
        return static_cast<pointer>(0);
    }
};

}} // namespace detail::variant

#ifndef QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE
#   if !QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x0551))
#       define QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(t)
#   else
#       define QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(t)  \
        , t* = 0
#   endif
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// relaxed_get<U>(variant) methods
//
template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_pointer<U>::type
relaxed_get(
      qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >* operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    ) QSBOOST_NOEXCEPT
{
    typedef typename add_pointer<U>::type U_ptr;
    if (!operand) return static_cast<U_ptr>(0);

    detail::variant::get_visitor<U> v;
    return operand->apply_visitor(v);
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_pointer<const U>::type
relaxed_get(
      const qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >* operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    ) QSBOOST_NOEXCEPT
{
    typedef typename add_pointer<const U>::type U_ptr;
    if (!operand) return static_cast<U_ptr>(0);

    detail::variant::get_visitor<const U> v;
    return operand->apply_visitor(v);
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_reference<U>::type
relaxed_get(
      qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >& operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    )
{
    typedef typename add_pointer<U>::type U_ptr;
    U_ptr result = relaxed_get<U>(&operand);

    if (!result)
        qsboost::throw_exception(bad_get());
    return *result;
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_reference<const U>::type
relaxed_get(
      const qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >& operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    )
{
    typedef typename add_pointer<const U>::type U_ptr;
    U_ptr result = relaxed_get<const U>(&operand);

    if (!result)
        qsboost::throw_exception(bad_get());
    return *result;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// strict_get<U>(variant) methods
//
template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_pointer<U>::type
strict_get(
      qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >* operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    ) QSBOOST_NOEXCEPT
{
    QSBOOST_STATIC_ASSERT_MSG(
        (qsboost::detail::variant::holds_element<qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >, U >::value),
        "boost::variant does not contain specified type U, "
        "call to boost::get<U>(boost::variant<T...>*) will always return NULL"
    );

    return relaxed_get<U>(operand);
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_pointer<const U>::type
strict_get(
      const qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >* operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    ) QSBOOST_NOEXCEPT
{
    QSBOOST_STATIC_ASSERT_MSG(
        (qsboost::detail::variant::holds_element<qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >, const U >::value),
        "boost::variant does not contain specified type U, "
        "call to boost::get<U>(const boost::variant<T...>*) will always return NULL"
    );

    return relaxed_get<U>(operand);
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_reference<U>::type
strict_get(
      qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >& operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    )
{
    QSBOOST_STATIC_ASSERT_MSG(
        (qsboost::detail::variant::holds_element<qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >, U >::value),
        "boost::variant does not contain specified type U, "
        "call to boost::get<U>(boost::variant<T...>&) will always throw boost::bad_get exception"
    );

    return relaxed_get<U>(operand);
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_reference<const U>::type
strict_get(
      const qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >& operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    )
{
    QSBOOST_STATIC_ASSERT_MSG(
        (qsboost::detail::variant::holds_element<qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >, const U >::value),
        "boost::variant does not contain specified type U, "
        "call to boost::get<U>(const boost::variant<T...>&) will always throw boost::bad_get exception"
    );

    return relaxed_get<U>(operand);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// get<U>(variant) methods
//

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_pointer<U>::type
get(
      qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >* operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    ) QSBOOST_NOEXCEPT
{
#ifdef QSBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT
    return relaxed_get<U>(operand);
#else
    return strict_get<U>(operand);
#endif

}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_pointer<const U>::type
get(
      const qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >* operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    ) QSBOOST_NOEXCEPT
{
#ifdef QSBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT
    return relaxed_get<U>(operand);
#else
    return strict_get<U>(operand);
#endif
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_reference<U>::type
get(
      qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >& operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    )
{
#ifdef QSBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT
    return relaxed_get<U>(operand);
#else
    return strict_get<U>(operand);
#endif
}

template <typename U, QSBOOST_VARIANT_ENUM_PARAMS(typename T) >
inline
    typename add_reference<const U>::type
get(
      const qsboost::variant< QSBOOST_VARIANT_ENUM_PARAMS(T) >& operand
      QSBOOST_VARIANT_AUX_GET_EXPLICIT_TEMPLATE_TYPE(U)
    )
{
#ifdef QSBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT
    return relaxed_get<U>(operand);
#else
    return strict_get<U>(operand);
#endif
}

} // namespace boost

#endif // BOOST_VARIANT_GET_HPP
