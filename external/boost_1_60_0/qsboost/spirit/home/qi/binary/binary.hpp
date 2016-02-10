/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_SPIRIT_BINARY_MAY_08_2007_0808AM)
#define QSBOOST_SPIRIT_BINARY_MAY_08_2007_0808AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/support/common_terminals.hpp>
#include <qsboost/spirit/home/support/detail/endian.hpp>
#include <qsboost/spirit/home/qi/detail/attributes.hpp>
#include <qsboost/spirit/home/qi/parser.hpp>
#include <qsboost/spirit/home/qi/meta_compiler.hpp>
#include <qsboost/spirit/home/qi/domain.hpp>
#include <qsboost/spirit/home/qi/detail/assign_to.hpp>
#include <qsboost/spirit/home/qi/skip_over.hpp>
#include <qsboost/spirit/home/support/common_terminals.hpp>
#include <qsboost/fusion/include/at.hpp>
#include <qsboost/mpl/or.hpp>
#include <qsboost/type_traits/is_integral.hpp>
#include <qsboost/type_traits/is_enum.hpp>
#include <qsboost/type_traits/is_floating_point.hpp>
#include <qsboost/config.hpp>

#define QSBOOST_SPIRIT_ENABLE_BINARY(name)                                        \
    template <>                                                                 \
    struct use_terminal<qi::domain, tag::name>                                  \
      : mpl::true_ {};                                                          \
                                                                                \
    template <typename A0>                                                      \
    struct use_terminal<qi::domain                                              \
        , terminal_ex<tag::name, fusion::vector1<A0> > >                        \
      : mpl::or_<is_integral<A0>, is_enum<A0> > {};                             \
                                                                                \
    template <>                                                                 \
    struct use_lazy_terminal<qi::domain, tag::name, 1> : mpl::true_ {};         \
                                                                                \
/***/

#define QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(name)                              \
    template<>                                                                \
    struct use_terminal<qi::domain, tag::name>: mpl::true_ {};                \
                                                                              \
    template<typename A0>                                                     \
    struct use_terminal<qi::domain, terminal_ex<tag::name,                    \
        fusion::vector1<A0> > >: is_floating_point<A0> {};                    \
                                                                              \
    template<>                                                                \
    struct use_lazy_terminal<qi::domain, tag::name, 1>: mpl::true_ {};        \
                                                                              \
/***/

namespace qsboost { namespace spirit
{
    ///////////////////////////////////////////////////////////////////////////
    // Enablers
    ///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_ENABLE_BINARY(byte_)                   // enables byte_
    QSBOOST_SPIRIT_ENABLE_BINARY(word)                    // enables word
    QSBOOST_SPIRIT_ENABLE_BINARY(big_word)                // enables big_word
    QSBOOST_SPIRIT_ENABLE_BINARY(little_word)             // enables little_word
    QSBOOST_SPIRIT_ENABLE_BINARY(dword)                   // enables dword
    QSBOOST_SPIRIT_ENABLE_BINARY(big_dword)               // enables big_dword
    QSBOOST_SPIRIT_ENABLE_BINARY(little_dword)            // enables little_dword
#ifdef QSBOOST_HAS_LONG_LONG
    QSBOOST_SPIRIT_ENABLE_BINARY(qword)                   // enables qword
    QSBOOST_SPIRIT_ENABLE_BINARY(big_qword)               // enables big_qword
    QSBOOST_SPIRIT_ENABLE_BINARY(little_qword)            // enables little_qword
#endif
    QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(bin_float)
    QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(big_bin_float)
    QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(little_bin_float)
    QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(bin_double)
    QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(big_bin_double)
    QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754(little_bin_double)
}}

#undef QSBOOST_SPIRIT_ENABLE_BINARY
#undef QSBOOST_SPIRIT_ENABLE_BINARY_IEEE754

namespace qsboost { namespace spirit { namespace qi
{
#ifndef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS
    using qsboost::spirit::byte_;
    using qsboost::spirit::word;
    using qsboost::spirit::big_word;
    using qsboost::spirit::little_word;
    using qsboost::spirit::dword;
    using qsboost::spirit::big_dword;
    using qsboost::spirit::little_dword;
#ifdef QSBOOST_HAS_LONG_LONG
    using qsboost::spirit::qword;
    using qsboost::spirit::big_qword;
    using qsboost::spirit::little_qword;
#endif
    using qsboost::spirit::bin_float;
    using qsboost::spirit::big_bin_float;
    using qsboost::spirit::little_bin_float;
    using qsboost::spirit::bin_double;
    using qsboost::spirit::big_bin_double;
    using qsboost::spirit::little_bin_double;
#endif

    using qsboost::spirit::byte_type;
    using qsboost::spirit::word_type;
    using qsboost::spirit::big_word_type;
    using qsboost::spirit::little_word_type;
    using qsboost::spirit::dword_type;
    using qsboost::spirit::big_dword_type;
    using qsboost::spirit::little_dword_type;
#ifdef QSBOOST_HAS_LONG_LONG
    using qsboost::spirit::qword_type;
    using qsboost::spirit::big_qword_type;
    using qsboost::spirit::little_qword_type;
#endif
    using qsboost::spirit::bin_float_type;
    using qsboost::spirit::big_bin_float_type;
    using qsboost::spirit::little_bin_float_type;
    using qsboost::spirit::bin_double_type;
    using qsboost::spirit::big_bin_double_type;
    using qsboost::spirit::little_bin_double_type;

    namespace detail
    {
        template <int bits>
        struct integer
        {
#ifdef QSBOOST_HAS_LONG_LONG
            QSBOOST_SPIRIT_ASSERT_MSG(
                bits == 8 || bits == 16 || bits == 32 || bits == 64,
                not_supported_binary_size, ());
#else
            QSBOOST_SPIRIT_ASSERT_MSG(
                bits == 8 || bits == 16 || bits == 32,
                not_supported_binary_size, ());
#endif
        };

        template <>
        struct integer<8>
        {
            enum { size = 1 };
            typedef uint_least8_t type;
        };

        template <>
        struct integer<16>
        {
            enum { size = 2 };
            typedef uint_least16_t type;
        };

        template <>
        struct integer<32>
        {
            enum { size = 4 };
            typedef uint_least32_t type;
        };

#ifdef QSBOOST_HAS_LONG_LONG
        template <>
        struct integer<64>
        {
            enum { size = 8 };
            typedef uint_least64_t type;
        };
#endif

        template <int bits>
        struct floating_point
        {
            QSBOOST_SPIRIT_ASSERT_MSG(
                bits == 32 || bits == 64,
                not_supported_binary_size, ());
        };

        template <>
        struct floating_point<32>
        {
            enum { size = 4 };
            typedef float type;
        };

        template <>
        struct floating_point<64>
        {
            enum { size = 8 };
            typedef double type;
        };

        ///////////////////////////////////////////////////////////////////////
        template <QSBOOST_SCOPED_ENUM(qsboost::endian::endianness) bits>
        struct what;

        template <>
        struct what<qsboost::endian::endianness::native>
        {
            static std::string is()
            {
                return "native-endian binary";
            }
        };

        template <>
        struct what<qsboost::endian::endianness::little>
        {
            static char const* is()
            {
                return "little-endian binary";
            }
        };

        template <>
        struct what<qsboost::endian::endianness::big>
        {
            static char const* is()
            {
                return "big-endian binary";
            }
        };
    }

    ///////////////////////////////////////////////////////////////////////////
    template <typename T, QSBOOST_SCOPED_ENUM(qsboost::endian::endianness) endian, int bits>
    struct any_binary_parser : primitive_parser<any_binary_parser<T, endian, bits> >
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef qsboost::endian::endian<endian, typename T::type,
                bits> type;
        };

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& attr_param) const
        {
            qi::skip_over(first, last, skipper);

            typename attribute<Context, Iterator>::type attr_;
            unsigned char* bytes = reinterpret_cast<unsigned char*>(&attr_);

            Iterator it = first;
            for (unsigned int i = 0; i < sizeof(attr_); ++i)
            {
                if (it == last)
                    return false;
                *bytes++ = *it++;
            }

            first = it;
            spirit::traits::assign_to(attr_, attr_param);
            return true;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info(qi::detail::what<endian>::is());
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    template <typename V, typename T
      , QSBOOST_SCOPED_ENUM(qsboost::endian::endianness) endian, int bits>
    struct binary_lit_parser
      : primitive_parser<binary_lit_parser<V, T, endian, bits> >
    {
        template <typename Context, typename Iterator>
        struct attribute
        {
            typedef unused_type type;
        };

        binary_lit_parser(V n_)
          : n(n_) {}

        template <typename Iterator, typename Context
          , typename Skipper, typename Attribute>
        bool parse(Iterator& first, Iterator const& last
          , Context& /*context*/, Skipper const& skipper
          , Attribute& attr_param) const
        {
            qi::skip_over(first, last, skipper);

            // Even if the endian types are not pod's (at least not in the
            // definition of C++03) it seems to be safe to assume they are
            // (but in C++0x the endian types _are_ PODs).
            // This allows us to treat them as a sequence of consecutive bytes.
            qsboost::endian::endian<endian, typename T::type, bits> attr_;

#if defined(QSBOOST_MSVC)
// warning C4244: 'argument' : conversion from 'const int' to 'foo', possible loss of data
#pragma warning(push)
#pragma warning(disable: 4244)
#endif
            attr_ = n;
#if defined(QSBOOST_MSVC)
#pragma warning(pop)
#endif

            unsigned char* bytes = reinterpret_cast<unsigned char*>(&attr_);

            Iterator it = first;
            for (unsigned int i = 0; i < sizeof(attr_); ++i)
            {
                if (it == last || *bytes++ != static_cast<unsigned char>(*it++))
                    return false;
            }

            first = it;
            spirit::traits::assign_to(attr_, attr_param);
            return true;
        }

        template <typename Context>
        info what(Context& /*context*/) const
        {
            return info(qi::detail::what<endian>::is());
        }

        V n;
    };

    ///////////////////////////////////////////////////////////////////////////
    // Parser generators: make_xxx function (objects)
    ///////////////////////////////////////////////////////////////////////////
    template <typename T, QSBOOST_SCOPED_ENUM(qsboost::endian::endianness) endian, int bits>
    struct make_binary_parser
    {
        typedef any_binary_parser<T, endian, bits> result_type;
        result_type operator()(unused_type, unused_type) const
        {
            return result_type();
        }
    };

    template <typename V, typename T
      , QSBOOST_SCOPED_ENUM(qsboost::endian::endianness) endian, int bits>
    struct make_binary_lit_parser
    {
        typedef binary_lit_parser<V, T, endian, bits> result_type;
        template <typename Terminal>
        result_type operator()(Terminal const& term, unused_type) const
        {
            return result_type(fusion::at_c<0>(term.args));
        }
    };

#define QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(name, endiantype, bits)            \
    template <typename Modifiers>                                             \
    struct make_primitive<tag::name, Modifiers>                               \
      : make_binary_parser<detail::integer<bits>,                             \
        qsboost::endian::endianness::endiantype, bits> {};                      \
                                                                              \
    template <typename Modifiers, typename A0>                                \
    struct make_primitive<                                                    \
        terminal_ex<tag::name, fusion::vector1<A0> > , Modifiers>             \
      : make_binary_lit_parser<A0, detail::integer<bits>,                     \
        qsboost::endian::endianness::endiantype, bits> {};                      \
                                                                              \
    /***/

    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(byte_, native, 8)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(word, native, 16)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(big_word, big, 16)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(little_word, little, 16)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(dword, native, 32)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(big_dword, big, 32)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(little_dword, little, 32)
#ifdef QSBOOST_HAS_LONG_LONG
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(qword, native, 64)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(big_qword, big, 64)
    QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE(little_qword, little, 64)
#endif

#undef QSBOOST_SPIRIT_MAKE_BINARY_PRIMITIVE

#define QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(name, endiantype, bits)    \
    template<typename Modifiers>                                              \
    struct make_primitive<tag::name, Modifiers>                               \
      : make_binary_parser<detail::floating_point<bits>,                      \
        qsboost::endian::endianness::endiantype, bits> {};                      \
                                                                              \
    template<typename Modifiers, typename A0>                                 \
    struct make_primitive<                                                    \
        terminal_ex<tag::name, fusion::vector1<A0> >, Modifiers>              \
      : make_binary_lit_parser<A0, detail::floating_point<bits>,              \
        qsboost::endian::endianness::endiantype,                                \
        bits> {};                                                             \
                                                                              \
    /***/

    QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(bin_float, native, 32)
    QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(big_bin_float, big, 32)
    QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(little_bin_float, little, 32)
    QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(bin_double, native, 64)
    QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(big_bin_double, big, 64)
    QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE(little_bin_double, little, 64)

#undef QSBOOST_SPIRIT_MAKE_BINARY_IEEE754_PRIMITIVE

}}}

#endif
