
#if !defined(QSBOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_HPP
#define QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_HPP

#include <qsboost/phoenix/object/detail/preprocessed/new.hpp>

#endif
#else

#if !QSBOOST_PHOENIX_IS_ITERATING

#ifndef QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_HPP
#define QSBOOST_PHOENIX_OBJECT_DETAIL_NEW_HPP

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/new_" QSBOOST_PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#define QSBOOST_PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, QSBOOST_PHOENIX_COMPOSITE_LIMIT,                                            \
    <qsboost/phoenix/object/detail/new.hpp>))
#include QSBOOST_PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(QSBOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

    template <typename T, QSBOOST_PHOENIX_typename_A>
    inline
    typename expression::new_<detail::target<T>, QSBOOST_PHOENIX_A>::type const
    new_(QSBOOST_PHOENIX_A_const_ref_a)
    {
        return
            expression::
                new_<detail::target<T>, QSBOOST_PHOENIX_A>::
                    make(detail::target<T>(), QSBOOST_PHOENIX_a);
    }

#endif

#endif // BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES
