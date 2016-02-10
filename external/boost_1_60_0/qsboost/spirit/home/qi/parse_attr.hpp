//  Copyright (c) 2001-2011 Hartmut Kaiser
//  Copyright (c) 2001-2011 Joel de Guzman
//  Copyright (c) 2009 Carl Barron
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying 
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(QSBOOST_PP_IS_ITERATING)

#if !defined(QSBOOST_SPIRIT_PARSE_ATTR_APRIL_24_2009_1043AM)
#define QSBOOST_SPIRIT_PARSE_ATTR_APRIL_24_2009_1043AM

#include <qsboost/spirit/home/qi/parse.hpp>

#include <qsboost/fusion/include/vector.hpp>
#include <qsboost/preprocessor/cat.hpp>
#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>

#define QSBOOST_PP_FILENAME_1 <qsboost/spirit/home/qi/parse_attr.hpp>
#define QSBOOST_PP_ITERATION_LIMITS (2, SPIRIT_ARGUMENTS_LIMIT)
#include QSBOOST_PP_ITERATE()

#endif

///////////////////////////////////////////////////////////////////////////////
//
//  Preprocessor vertical repetition code
//
///////////////////////////////////////////////////////////////////////////////
#else // defined(BOOST_PP_IS_ITERATING)

#define N QSBOOST_PP_ITERATION()
#define QSBOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE(z, n, A) QSBOOST_PP_CAT(A, n)&

namespace qsboost { namespace spirit { namespace qi
{
    ///////////////////////////////////////////////////////////////////////////
    template <typename Iterator, typename Expr
      , QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    parse(
        Iterator& first
      , Iterator last
      , Expr const& expr
      , QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        // Make sure the iterator is at least a forward_iterator. If you got an 
        // compilation error here, then you are using an input_iterator while
        // calling this function, you need to supply at least a 
        // forward_iterator instead.
        QSBOOST_CONCEPT_ASSERT((ForwardIterator<Iterator>));

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then the expression (expr) is not a valid spirit qi expression.
        QSBOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);

        typedef fusion::vector<
            QSBOOST_PP_ENUM(N, QSBOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type lattr (QSBOOST_PP_ENUM_PARAMS(N, attr));
        return compile<qi::domain>(expr).parse(first, last, unused, unused, lattr);
    }

    template <typename Iterator, typename Expr
      , QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    parse(
        Iterator const& first_
      , Iterator last
      , Expr const& expr
      , QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        Iterator first = first_;
        return qi::parse(first, last, expr, QSBOOST_PP_ENUM_PARAMS(N, attr));
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Iterator, typename Expr, typename Skipper
      , QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    phrase_parse(
        Iterator& first
      , Iterator last
      , Expr const& expr
      , Skipper const& skipper
      , QSBOOST_SCOPED_ENUM(skip_flag) post_skip
      , QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        // Make sure the iterator is at least a forward_iterator. If you got an 
        // compilation error here, then you are using an input_iterator while
        // calling this function, you need to supply at least a 
        // forward_iterator instead.
        QSBOOST_CONCEPT_ASSERT((ForwardIterator<Iterator>));

        // Report invalid expression error as early as possible.
        // If you got an error_invalid_expression error message here,
        // then either the expression (expr) or skipper is not a valid
        // spirit qi expression.
        QSBOOST_SPIRIT_ASSERT_MATCH(qi::domain, Expr);
        QSBOOST_SPIRIT_ASSERT_MATCH(qi::domain, Skipper);

        typedef
            typename result_of::compile<qi::domain, Skipper>::type
        skipper_type;
        skipper_type const skipper_ = compile<qi::domain>(skipper);

        typedef fusion::vector<
            QSBOOST_PP_ENUM(N, QSBOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE, A)
        > vector_type;

        vector_type lattr (QSBOOST_PP_ENUM_PARAMS(N, attr));
        if (!compile<qi::domain>(expr).parse(
                first, last, unused, skipper_, lattr))
            return false;

        if (post_skip == skip_flag::postskip)
            qi::skip_over(first, last, skipper_);
        return true;
    }

    template <typename Iterator, typename Expr, typename Skipper
      , QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    phrase_parse(
        Iterator const& first_
      , Iterator last
      , Expr const& expr
      , Skipper const& skipper
      , QSBOOST_SCOPED_ENUM(skip_flag) post_skip
      , QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        Iterator first = first_;
        return qi::phrase_parse(first, last, expr, skipper, post_skip
          , QSBOOST_PP_ENUM_PARAMS(N, attr));
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename Iterator, typename Expr, typename Skipper
      , QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    phrase_parse(
        Iterator& first
      , Iterator last
      , Expr const& expr
      , Skipper const& skipper
      , QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        return qi::phrase_parse(first, last, expr, skipper, skip_flag::postskip
          , QSBOOST_PP_ENUM_PARAMS(N, attr));
    }

    template <typename Iterator, typename Expr, typename Skipper
      , QSBOOST_PP_ENUM_PARAMS(N, typename A)>
    inline bool
    phrase_parse(
        Iterator const& first_
      , Iterator last
      , Expr const& expr
      , Skipper const& skipper
      , QSBOOST_PP_ENUM_BINARY_PARAMS(N, A, & attr))
    {
        Iterator first = first_;
        return qi::phrase_parse(first, last, expr, skipper, skip_flag::postskip
          , QSBOOST_PP_ENUM_PARAMS(N, attr));
    }
}}}

#undef QSBOOST_SPIRIT_QI_ATTRIBUTE_REFERENCE
#undef N

#endif

