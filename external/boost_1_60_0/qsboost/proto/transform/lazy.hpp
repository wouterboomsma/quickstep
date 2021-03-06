///////////////////////////////////////////////////////////////////////////////
/// \file lazy.hpp
/// Contains definition of the lazy<> transform.
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_TRANSFORM_LAZY_HPP_EAN_12_02_2007
#define QSBOOST_PROTO_TRANSFORM_LAZY_HPP_EAN_12_02_2007

#include <qsboost/preprocessor/iteration/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_trailing_params.hpp>
#include <qsboost/proto/proto_fwd.hpp>
#include <qsboost/proto/transform/make.hpp>
#include <qsboost/proto/transform/call.hpp>
#include <qsboost/proto/transform/impl.hpp>
#include <qsboost/proto/transform/detail/pack.hpp>

namespace qsboost { namespace proto
{
    /// \brief A PrimitiveTransform that uses <tt>make\<\></tt> to build
    /// a CallableTransform, and then uses <tt>call\<\></tt> to apply it.
    ///
    /// <tt>lazy\<\></tt> is useful as a higher-order transform, when the
    /// transform to be applied depends on the current state of the
    /// transformation. The invocation of the <tt>make\<\></tt> transform
    /// evaluates any nested transforms, and the resulting type is treated
    /// as a CallableTransform, which is evaluated with <tt>call\<\></tt>.
    template<typename Object>
    struct lazy : transform<lazy<Object> >
    {
        template<typename Expr, typename State, typename Data>
        struct impl
          : call<
                typename make<Object>::template impl<Expr, State, Data>::result_type
            >::template impl<Expr, State, Data>
        {};
    };

    /// INTERNAL ONLY
    template<typename Fun>
    struct lazy<detail::msvc_fun_workaround<Fun> >
      : lazy<Fun>
    {};

    #include <qsboost/proto/transform/detail/lazy.hpp>

    /// INTERNAL ONLY
    ///
    template<typename Object>
    struct is_callable<lazy<Object> >
      : mpl::true_
    {};

}}

#endif
