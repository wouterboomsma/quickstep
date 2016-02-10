///////////////////////////////////////////////////////////////////////////////
/// \file debug.hpp
/// Utilities for debugging Proto expression trees
//
//  Copyright 2008 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_PROTO_DEBUG_HPP_EAN_12_31_2006
#define QSBOOST_PROTO_DEBUG_HPP_EAN_12_31_2006

#include <iostream>
#include <qsboost/preprocessor/stringize.hpp>
#include <qsboost/ref.hpp>
#include <qsboost/mpl/assert.hpp>
#include <qsboost/proto/proto_fwd.hpp>
#include <qsboost/proto/traits.hpp>
#include <qsboost/proto/matches.hpp>
#include <qsboost/proto/fusion.hpp>
#include <qsboost/fusion/algorithm/iteration/for_each.hpp>
#include <qsboost/detail/sp_typeinfo.hpp>

namespace qsboost { namespace proto
{
    namespace tagns_ { namespace tag
    {
    #define QSBOOST_PROTO_DEFINE_TAG_INSERTION(Tag)                               \
        /** \brief INTERNAL ONLY */                                             \
        inline std::ostream &operator <<(std::ostream &sout, Tag const &)       \
        {                                                                       \
            return sout << QSBOOST_PP_STRINGIZE(Tag);                             \
        }                                                                       \
        /**/

        QSBOOST_PROTO_DEFINE_TAG_INSERTION(terminal)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(unary_plus)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(negate)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(dereference)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(complement)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(address_of)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(logical_not)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(pre_inc)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(pre_dec)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(post_inc)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(post_dec)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(shift_left)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(shift_right)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(multiplies)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(divides)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(modulus)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(plus)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(minus)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(less)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(greater)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(less_equal)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(greater_equal)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(equal_to)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(not_equal_to)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(logical_or)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(logical_and)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(bitwise_and)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(bitwise_or)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(bitwise_xor)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(comma)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(mem_ptr)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(shift_left_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(shift_right_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(multiplies_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(divides_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(modulus_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(plus_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(minus_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(bitwise_and_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(bitwise_or_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(bitwise_xor_assign)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(subscript)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(member)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(if_else_)
        QSBOOST_PROTO_DEFINE_TAG_INSERTION(function)

    #undef QSBOOST_PROTO_DEFINE_TAG_INSERTION
    }}

    namespace hidden_detail_
    {
        struct ostream_wrapper
        {
            ostream_wrapper(std::ostream &sout)
              : sout_(sout)
            {}

            std::ostream &sout_;

        private:
            ostream_wrapper &operator =(ostream_wrapper const &);
        };

        struct named_any
        {
            template<typename T>
            named_any(T const &)
              : name_(QSBOOST_SP_TYPEID(T).name())
            {}

            char const *name_;
        };

        inline std::ostream &operator <<(ostream_wrapper sout_wrap, named_any t)
        {
            return sout_wrap.sout_ << t.name_;
        }
    }

    namespace detail
    {
        struct display_expr_impl
        {
            explicit display_expr_impl(std::ostream &sout, int depth = 0)
              : depth_(depth)
              , first_(true)
              , sout_(sout)
            {}

            template<typename Expr>
            void operator()(Expr const &expr) const
            {
                this->impl(expr, mpl::long_<arity_of<Expr>::value>());
            }

        private:
            display_expr_impl(display_expr_impl const &);
            display_expr_impl &operator =(display_expr_impl const &);

            template<typename Expr>
            void impl(Expr const &expr, mpl::long_<0>) const
            {
                using namespace hidden_detail_;
                typedef typename tag_of<Expr>::type tag;
                this->sout_.width(this->depth_);
                this->sout_ << (this->first_? "" : ", ");
                this->sout_ << tag() << "(" << proto::value(expr) << ")\n";
                this->first_ = false;
            }

            template<typename Expr, typename Arity>
            void impl(Expr const &expr, Arity) const
            {
                using namespace hidden_detail_;
                typedef typename tag_of<Expr>::type tag;
                this->sout_.width(this->depth_);
                this->sout_ << (this->first_? "" : ", ");
                this->sout_ << tag() << "(\n";
                display_expr_impl display(this->sout_, this->depth_ + 4);
                fusion::for_each(expr, display);
                this->sout_.width(this->depth_);
                this->sout_ << "" << ")\n";
                this->first_ = false;
            }

            int depth_;
            mutable bool first_;
            std::ostream &sout_;
        };
    }

    namespace functional
    {
        /// \brief Pretty-print a Proto expression tree.
        ///
        /// A PolymorphicFunctionObject which accepts a Proto expression
        /// tree and pretty-prints it to an \c ostream for debugging
        /// purposes.
        struct display_expr
        {
            QSBOOST_PROTO_CALLABLE()

            typedef void result_type;

            /// \param sout  The \c ostream to which the expression tree
            ///              will be written.
            /// \param depth The starting indentation depth for this node.
            ///              Children nodes will be displayed at a starting
            ///              depth of <tt>depth+4</tt>.
            explicit display_expr(std::ostream &sout = std::cout, int depth = 0)
              : depth_(depth)
              , sout_(sout)
            {}

            /// \brief Pretty-print the current node in a Proto expression
            /// tree.
            template<typename Expr>
            void operator()(Expr const &expr) const
            {
                detail::display_expr_impl(this->sout_, this->depth_)(expr);
            }

        private:
            int depth_;
            reference_wrapper<std::ostream> sout_;
        };
    }

    /// \brief Pretty-print a Proto expression tree.
    ///
    /// \note Equivalent to <tt>functional::display_expr(0, sout)(expr)</tt>
    /// \param expr The Proto expression tree to pretty-print
    /// \param sout The \c ostream to which the output should be
    ///             written. If not specified, defaults to
    ///             <tt>std::cout</tt>.
    template<typename Expr>
    void display_expr(Expr const &expr, std::ostream &sout)
    {
        functional::display_expr(sout, 0)(expr);
    }

    /// \overload
    ///
    template<typename Expr>
    void display_expr(Expr const &expr)
    {
        functional::display_expr()(expr);
    }

    /// \brief Assert at compile time that a particular expression
    ///        matches the specified grammar.
    ///
    /// \note Equivalent to <tt>BOOST_MPL_ASSERT((proto::matches\<Expr, Grammar\>))</tt>
    /// \param expr The Proto expression to check againts <tt>Grammar</tt>
    template<typename Grammar, typename Expr>
    void assert_matches(Expr const & /*expr*/)
    {
        QSBOOST_MPL_ASSERT((proto::matches<Expr, Grammar>));
    }

    /// \brief Assert at compile time that a particular expression
    ///        does not match the specified grammar.
    ///
    /// \note Equivalent to <tt>BOOST_MPL_ASSERT_NOT((proto::matches\<Expr, Grammar\>))</tt>
    /// \param expr The Proto expression to check againts <tt>Grammar</tt>
    template<typename Grammar, typename Expr>
    void assert_matches_not(Expr const & /*expr*/)
    {
        QSBOOST_MPL_ASSERT_NOT((proto::matches<Expr, Grammar>));
    }

    /// \brief Assert at compile time that a particular expression
    ///        matches the specified grammar.
    ///
    /// \note Equivalent to <tt>proto::assert_matches\<Grammar\>(Expr)</tt>
    /// \param Expr The Proto expression to check againts <tt>Grammar</tt>
    /// \param Grammar The grammar used to validate Expr.
    #define QSBOOST_PROTO_ASSERT_MATCHES(Expr, Grammar)                                               \
        (true ? (void)0 : qsboost::proto::assert_matches<Grammar>(Expr))

    /// \brief Assert at compile time that a particular expression
    ///        does not match the specified grammar.
    ///
    /// \note Equivalent to <tt>proto::assert_matches_not\<Grammar\>(Expr)</tt>
    /// \param Expr The Proto expression to check againts <tt>Grammar</tt>
    /// \param Grammar The grammar used to validate Expr.
    #define QSBOOST_PROTO_ASSERT_MATCHES_NOT(Expr, Grammar)                                           \
        (true ? (void)0 : qsboost::proto::assert_matches_not<Grammar>(Expr))

}}

#endif
