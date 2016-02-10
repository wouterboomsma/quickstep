//-----------------------------------------------------------------------------
// boost variant/detail/variant_io.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2002-2003
// Eric Friedman, Itay Maman
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_VARIANT_DETAIL_VARIANT_IO_HPP
#define QSBOOST_VARIANT_DETAIL_VARIANT_IO_HPP

#include <iosfwd> // for std::basic_ostream forward declare

#include "qsboost/variant/variant_fwd.hpp"

#include "qsboost/detail/templated_streams.hpp"
#include "qsboost/variant/static_visitor.hpp"

namespace qsboost {

///////////////////////////////////////////////////////////////////////////////
// function template operator<<
//
// Outputs the content of the given variant to the given ostream.
//

// forward declare (allows output of embedded variant< variant< ... >, ... >)
template <
      QSBOOST_TEMPLATED_STREAM_ARGS(E,T)
    QSBOOST_TEMPLATED_STREAM_COMMA
      QSBOOST_VARIANT_ENUM_PARAMS(typename U)
    >
inline QSBOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      QSBOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const variant< QSBOOST_VARIANT_ENUM_PARAMS(U) >& rhs
    );

namespace detail { namespace variant {

template <typename OStream>
class printer
    : public qsboost::static_visitor<>
{
private: // representation

    OStream& out_;

public: // structors

    explicit printer(OStream& out)
        : out_( out )
    {
    }

public: // visitor interface

    template <typename T>
    void operator()(const T& operand) const
    {
        out_ << operand;
    }

private:
    printer& operator=(const printer&);

};

}} // namespace detail::variant

template <
      QSBOOST_TEMPLATED_STREAM_ARGS(E,T)
    QSBOOST_TEMPLATED_STREAM_COMMA
      QSBOOST_VARIANT_ENUM_PARAMS(typename U)
    >
inline QSBOOST_TEMPLATED_STREAM(ostream, E,T)& operator<<(
      QSBOOST_TEMPLATED_STREAM(ostream, E,T)& out
    , const variant< QSBOOST_VARIANT_ENUM_PARAMS(U) >& rhs
    )
{
    detail::variant::printer<
          QSBOOST_TEMPLATED_STREAM(ostream, E,T)
        > visitor(out);

    rhs.apply_visitor(visitor);

    return out;
}

} // namespace boost

#endif // BOOST_VARIANT_DETAIL_VARIANT_IO_HPP
