/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2001-2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_CHAR_CLASS_NOVEMBER_10_2006_0907AM)
#define QSBOOST_SPIRIT_CHAR_CLASS_NOVEMBER_10_2006_0907AM

#if defined(_MSC_VER)
#pragma once
#endif

#include <string>

#include <qsboost/spirit/include/phoenix_limits.hpp>      // needs to be included before proto
#include <qsboost/proto/proto.hpp>
#include <qsboost/config.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/spirit/home/support/unused.hpp>
#include <qsboost/spirit/home/support/detail/is_spirit_tag.hpp>
#include <qsboost/type_traits/is_signed.hpp>
#include <qsboost/type_traits/make_unsigned.hpp>
#include <qsboost/type_traits/make_signed.hpp>

#if defined(QSBOOST_MSVC)
# pragma warning(push)
# pragma warning(disable: 4127) // conditional expression is constant
# pragma warning(disable: 4800) // 'int' : forcing value to bool 'true' or 'false' warning
#endif

namespace qsboost { namespace spirit { namespace detail
{
    // Here's the thing... typical encodings (except ASCII) deal with unsigned
    // integers > 127. ASCII uses only 127. Yet, most char and wchar_t are signed.
    // Thus, a char with value > 127 is negative (e.g. char 233 is -23). When you
    // cast this to an unsigned int with 32 bits, you get 4294967273!
    //
    // The trick is to cast to an unsigned version of the source char first
    // before casting to the target. {P.S. Don't worry about the code, the
    // optimizer will optimize the if-else branches}

    template <typename TargetChar, typename SourceChar>
    TargetChar cast_char(SourceChar ch)
    {
        if (is_signed<TargetChar>::value != is_signed<SourceChar>::value)
        {
            if (is_signed<SourceChar>::value)
            {
                 // source is signed, target is unsigned
                typedef typename make_unsigned<SourceChar>::type USourceChar;
                return TargetChar(USourceChar(ch));
            }
            else
            {
                 // source is unsigned, target is signed
                typedef typename make_signed<SourceChar>::type SSourceChar;
                return TargetChar(SSourceChar(ch));
            }
        }
        else
        {
            // source and target has same signedness
            return TargetChar(ch); // just cast
        }
    }
}}}

namespace qsboost { namespace spirit { namespace tag
{
    struct char_ { QSBOOST_SPIRIT_IS_TAG() };
    struct string { QSBOOST_SPIRIT_IS_TAG() };

    ///////////////////////////////////////////////////////////////////////////
    // classification tags
    struct alnum { QSBOOST_SPIRIT_IS_TAG() };
    struct alpha { QSBOOST_SPIRIT_IS_TAG() };
    struct digit { QSBOOST_SPIRIT_IS_TAG() };
    struct xdigit { QSBOOST_SPIRIT_IS_TAG() };
    struct cntrl { QSBOOST_SPIRIT_IS_TAG() };
    struct graph { QSBOOST_SPIRIT_IS_TAG() };
    struct print { QSBOOST_SPIRIT_IS_TAG() };
    struct punct { QSBOOST_SPIRIT_IS_TAG() };
    struct space { QSBOOST_SPIRIT_IS_TAG() };
    struct blank { QSBOOST_SPIRIT_IS_TAG() };

    ///////////////////////////////////////////////////////////////////////////
    // classification/conversion tags
    struct no_case { QSBOOST_SPIRIT_IS_TAG() };
    struct lower { QSBOOST_SPIRIT_IS_TAG() };
    struct upper { QSBOOST_SPIRIT_IS_TAG() };
    struct lowernum { QSBOOST_SPIRIT_IS_TAG() };
    struct uppernum { QSBOOST_SPIRIT_IS_TAG() };
    struct ucs4 { QSBOOST_SPIRIT_IS_TAG() };
    struct encoding { QSBOOST_SPIRIT_IS_TAG() };

#if defined(QSBOOST_SPIRIT_UNICODE)
///////////////////////////////////////////////////////////////////////////
//  Unicode Major Categories
///////////////////////////////////////////////////////////////////////////
    struct letter { QSBOOST_SPIRIT_IS_TAG() };
    struct mark { QSBOOST_SPIRIT_IS_TAG() };
    struct number { QSBOOST_SPIRIT_IS_TAG() };
    struct separator { QSBOOST_SPIRIT_IS_TAG() };
    struct other { QSBOOST_SPIRIT_IS_TAG() };
    struct punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct symbol { QSBOOST_SPIRIT_IS_TAG() };

///////////////////////////////////////////////////////////////////////////
//  Unicode General Categories
///////////////////////////////////////////////////////////////////////////
    struct uppercase_letter { QSBOOST_SPIRIT_IS_TAG() };
    struct lowercase_letter { QSBOOST_SPIRIT_IS_TAG() };
    struct titlecase_letter { QSBOOST_SPIRIT_IS_TAG() };
    struct modifier_letter { QSBOOST_SPIRIT_IS_TAG() };
    struct other_letter { QSBOOST_SPIRIT_IS_TAG() };

    struct nonspacing_mark { QSBOOST_SPIRIT_IS_TAG() };
    struct enclosing_mark { QSBOOST_SPIRIT_IS_TAG() };
    struct spacing_mark { QSBOOST_SPIRIT_IS_TAG() };

    struct decimal_number { QSBOOST_SPIRIT_IS_TAG() };
    struct letter_number { QSBOOST_SPIRIT_IS_TAG() };
    struct other_number { QSBOOST_SPIRIT_IS_TAG() };

    struct space_separator { QSBOOST_SPIRIT_IS_TAG() };
    struct line_separator { QSBOOST_SPIRIT_IS_TAG() };
    struct paragraph_separator { QSBOOST_SPIRIT_IS_TAG() };

    struct control { QSBOOST_SPIRIT_IS_TAG() };
    struct format { QSBOOST_SPIRIT_IS_TAG() };
    struct private_use { QSBOOST_SPIRIT_IS_TAG() };
    struct surrogate { QSBOOST_SPIRIT_IS_TAG() };
    struct unassigned { QSBOOST_SPIRIT_IS_TAG() };

    struct dash_punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct open_punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct close_punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct connector_punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct other_punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct initial_punctuation { QSBOOST_SPIRIT_IS_TAG() };
    struct final_punctuation { QSBOOST_SPIRIT_IS_TAG() };

    struct math_symbol { QSBOOST_SPIRIT_IS_TAG() };
    struct currency_symbol { QSBOOST_SPIRIT_IS_TAG() };
    struct modifier_symbol { QSBOOST_SPIRIT_IS_TAG() };
    struct other_symbol { QSBOOST_SPIRIT_IS_TAG() };

///////////////////////////////////////////////////////////////////////////
//  Unicode Derived Categories
///////////////////////////////////////////////////////////////////////////
    struct alphabetic { QSBOOST_SPIRIT_IS_TAG() };
    struct uppercase { QSBOOST_SPIRIT_IS_TAG() };
    struct lowercase { QSBOOST_SPIRIT_IS_TAG() };
    struct white_space { QSBOOST_SPIRIT_IS_TAG() };
    struct hex_digit { QSBOOST_SPIRIT_IS_TAG() };
    struct noncharacter_code_point { QSBOOST_SPIRIT_IS_TAG() };
    struct default_ignorable_code_point { QSBOOST_SPIRIT_IS_TAG() };

///////////////////////////////////////////////////////////////////////////
//  Unicode Scripts
///////////////////////////////////////////////////////////////////////////
    struct arabic { QSBOOST_SPIRIT_IS_TAG() };
    struct imperial_aramaic { QSBOOST_SPIRIT_IS_TAG() };
    struct armenian { QSBOOST_SPIRIT_IS_TAG() };
    struct avestan { QSBOOST_SPIRIT_IS_TAG() };
    struct balinese { QSBOOST_SPIRIT_IS_TAG() };
    struct bamum { QSBOOST_SPIRIT_IS_TAG() };
    struct bengali { QSBOOST_SPIRIT_IS_TAG() };
    struct bopomofo { QSBOOST_SPIRIT_IS_TAG() };
    struct braille { QSBOOST_SPIRIT_IS_TAG() };
    struct buginese { QSBOOST_SPIRIT_IS_TAG() };
    struct buhid { QSBOOST_SPIRIT_IS_TAG() };
    struct canadian_aboriginal { QSBOOST_SPIRIT_IS_TAG() };
    struct carian { QSBOOST_SPIRIT_IS_TAG() };
    struct cham { QSBOOST_SPIRIT_IS_TAG() };
    struct cherokee { QSBOOST_SPIRIT_IS_TAG() };
    struct coptic { QSBOOST_SPIRIT_IS_TAG() };
    struct cypriot { QSBOOST_SPIRIT_IS_TAG() };
    struct cyrillic { QSBOOST_SPIRIT_IS_TAG() };
    struct devanagari { QSBOOST_SPIRIT_IS_TAG() };
    struct deseret { QSBOOST_SPIRIT_IS_TAG() };
    struct egyptian_hieroglyphs { QSBOOST_SPIRIT_IS_TAG() };
    struct ethiopic { QSBOOST_SPIRIT_IS_TAG() };
    struct georgian { QSBOOST_SPIRIT_IS_TAG() };
    struct glagolitic { QSBOOST_SPIRIT_IS_TAG() };
    struct gothic { QSBOOST_SPIRIT_IS_TAG() };
    struct greek { QSBOOST_SPIRIT_IS_TAG() };
    struct gujarati { QSBOOST_SPIRIT_IS_TAG() };
    struct gurmukhi { QSBOOST_SPIRIT_IS_TAG() };
    struct hangul { QSBOOST_SPIRIT_IS_TAG() };
    struct han { QSBOOST_SPIRIT_IS_TAG() };
    struct hanunoo { QSBOOST_SPIRIT_IS_TAG() };
    struct hebrew { QSBOOST_SPIRIT_IS_TAG() };
    struct hiragana { QSBOOST_SPIRIT_IS_TAG() };
    struct katakana_or_hiragana { QSBOOST_SPIRIT_IS_TAG() };
    struct old_italic { QSBOOST_SPIRIT_IS_TAG() };
    struct javanese { QSBOOST_SPIRIT_IS_TAG() };
    struct kayah_li { QSBOOST_SPIRIT_IS_TAG() };
    struct katakana { QSBOOST_SPIRIT_IS_TAG() };
    struct kharoshthi { QSBOOST_SPIRIT_IS_TAG() };
    struct khmer { QSBOOST_SPIRIT_IS_TAG() };
    struct kannada { QSBOOST_SPIRIT_IS_TAG() };
    struct kaithi { QSBOOST_SPIRIT_IS_TAG() };
    struct tai_tham { QSBOOST_SPIRIT_IS_TAG() };
    struct lao { QSBOOST_SPIRIT_IS_TAG() };
    struct latin { QSBOOST_SPIRIT_IS_TAG() };
    struct lepcha { QSBOOST_SPIRIT_IS_TAG() };
    struct limbu { QSBOOST_SPIRIT_IS_TAG() };
    struct linear_b { QSBOOST_SPIRIT_IS_TAG() };
    struct lisu { QSBOOST_SPIRIT_IS_TAG() };
    struct lycian { QSBOOST_SPIRIT_IS_TAG() };
    struct lydian { QSBOOST_SPIRIT_IS_TAG() };
    struct malayalam { QSBOOST_SPIRIT_IS_TAG() };
    struct mongolian { QSBOOST_SPIRIT_IS_TAG() };
    struct meetei_mayek { QSBOOST_SPIRIT_IS_TAG() };
    struct myanmar { QSBOOST_SPIRIT_IS_TAG() };
    struct nko { QSBOOST_SPIRIT_IS_TAG() };
    struct ogham { QSBOOST_SPIRIT_IS_TAG() };
    struct ol_chiki { QSBOOST_SPIRIT_IS_TAG() };
    struct old_turkic { QSBOOST_SPIRIT_IS_TAG() };
    struct oriya { QSBOOST_SPIRIT_IS_TAG() };
    struct osmanya { QSBOOST_SPIRIT_IS_TAG() };
    struct phags_pa { QSBOOST_SPIRIT_IS_TAG() };
    struct inscriptional_pahlavi { QSBOOST_SPIRIT_IS_TAG() };
    struct phoenician { QSBOOST_SPIRIT_IS_TAG() };
    struct inscriptional_parthian { QSBOOST_SPIRIT_IS_TAG() };
    struct rejang { QSBOOST_SPIRIT_IS_TAG() };
    struct runic { QSBOOST_SPIRIT_IS_TAG() };
    struct samaritan { QSBOOST_SPIRIT_IS_TAG() };
    struct old_south_arabian { QSBOOST_SPIRIT_IS_TAG() };
    struct saurashtra { QSBOOST_SPIRIT_IS_TAG() };
    struct shavian { QSBOOST_SPIRIT_IS_TAG() };
    struct sinhala { QSBOOST_SPIRIT_IS_TAG() };
    struct sundanese { QSBOOST_SPIRIT_IS_TAG() };
    struct syloti_nagri { QSBOOST_SPIRIT_IS_TAG() };
    struct syriac { QSBOOST_SPIRIT_IS_TAG() };
    struct tagbanwa { QSBOOST_SPIRIT_IS_TAG() };
    struct tai_le { QSBOOST_SPIRIT_IS_TAG() };
    struct new_tai_lue { QSBOOST_SPIRIT_IS_TAG() };
    struct tamil { QSBOOST_SPIRIT_IS_TAG() };
    struct tai_viet { QSBOOST_SPIRIT_IS_TAG() };
    struct telugu { QSBOOST_SPIRIT_IS_TAG() };
    struct tifinagh { QSBOOST_SPIRIT_IS_TAG() };
    struct tagalog { QSBOOST_SPIRIT_IS_TAG() };
    struct thaana { QSBOOST_SPIRIT_IS_TAG() };
    struct thai { QSBOOST_SPIRIT_IS_TAG() };
    struct tibetan { QSBOOST_SPIRIT_IS_TAG() };
    struct ugaritic { QSBOOST_SPIRIT_IS_TAG() };
    struct vai { QSBOOST_SPIRIT_IS_TAG() };
    struct old_persian { QSBOOST_SPIRIT_IS_TAG() };
    struct cuneiform { QSBOOST_SPIRIT_IS_TAG() };
    struct yi { QSBOOST_SPIRIT_IS_TAG() };
    struct inherited { QSBOOST_SPIRIT_IS_TAG() };
    struct common { QSBOOST_SPIRIT_IS_TAG() };
    struct unknown { QSBOOST_SPIRIT_IS_TAG() };
#endif

    ///////////////////////////////////////////////////////////////////////////
    // This composite tag type encodes both the character
    // set and the specific char tag (used for classification
    // or conversion). char_code_base and char_encoding_base
    // can be used to test for modifier membership (see modifier.hpp)
    template <typename CharClass>
    struct char_code_base {};

    template <typename CharEncoding>
    struct char_encoding_base {};

    template <typename CharClass, typename CharEncoding>
    struct char_code
        : char_code_base<CharClass>, char_encoding_base<CharEncoding>
    {
        QSBOOST_SPIRIT_IS_TAG()
        typedef CharEncoding char_encoding; // e.g. ascii
        typedef CharClass char_class;       // e.g. tag::alnum
    };
}}}

namespace qsboost { namespace spirit { namespace char_class
{
    ///////////////////////////////////////////////////////////////////////////
    // Test characters for classification
    template <typename CharEncoding>
    struct classify
    {
        typedef typename CharEncoding::char_type char_type;

#define QSBOOST_SPIRIT_CLASSIFY(name, isname)                                     \
        template <typename Char>                                                \
        static bool                                                             \
        is(tag::name, Char ch)                                                  \
        {                                                                       \
            return CharEncoding::isname                                         \
                QSBOOST_PREVENT_MACRO_SUBSTITUTION                                \
                    (detail::cast_char<char_type>(ch));                         \
        }                                                                       \
        /***/

        QSBOOST_SPIRIT_CLASSIFY(char_, ischar)
        QSBOOST_SPIRIT_CLASSIFY(alnum, isalnum)
        QSBOOST_SPIRIT_CLASSIFY(alpha, isalpha)
        QSBOOST_SPIRIT_CLASSIFY(digit, isdigit)
        QSBOOST_SPIRIT_CLASSIFY(xdigit, isxdigit)
        QSBOOST_SPIRIT_CLASSIFY(cntrl, iscntrl)
        QSBOOST_SPIRIT_CLASSIFY(graph, isgraph)
        QSBOOST_SPIRIT_CLASSIFY(lower, islower)
        QSBOOST_SPIRIT_CLASSIFY(print, isprint)
        QSBOOST_SPIRIT_CLASSIFY(punct, ispunct)
        QSBOOST_SPIRIT_CLASSIFY(space, isspace)
        QSBOOST_SPIRIT_CLASSIFY(blank, isblank)
        QSBOOST_SPIRIT_CLASSIFY(upper, isupper)

#undef QSBOOST_SPIRIT_CLASSIFY

        template <typename Char>
        static bool
        is(tag::lowernum, Char ch)
        {
            return CharEncoding::islower(detail::cast_char<char_type>(ch)) ||
                   CharEncoding::isdigit(detail::cast_char<char_type>(ch));
        }

        template <typename Char>
        static bool
        is(tag::uppernum, Char ch)
        {
            return CharEncoding::isupper(detail::cast_char<char_type>(ch)) ||
                   CharEncoding::isdigit(detail::cast_char<char_type>(ch));
        }

#if defined(QSBOOST_SPIRIT_UNICODE)

#define QSBOOST_SPIRIT_UNICODE_CLASSIFY(name)                                     \
        template <typename Char>                                                \
        static bool                                                             \
        is(tag::name, Char ch)                                                  \
        {                                                                       \
            return CharEncoding::is_##name(detail::cast_char<char_type>(ch));   \
        }                                                                       \
        /***/

///////////////////////////////////////////////////////////////////////////
//  Unicode Major Categories
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(mark)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(number)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(separator)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(other)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(symbol)

///////////////////////////////////////////////////////////////////////////
//  Unicode General Categories
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(uppercase_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lowercase_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(titlecase_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(modifier_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(other_letter)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY(nonspacing_mark)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(enclosing_mark)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(spacing_mark)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY(decimal_number)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(letter_number)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(other_number)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY(space_separator)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(line_separator)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(paragraph_separator)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY(control)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(format)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(private_use)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(surrogate)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(unassigned)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY(dash_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(open_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(close_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(connector_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(other_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(initial_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(final_punctuation)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY(math_symbol)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(currency_symbol)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(modifier_symbol)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(other_symbol)

///////////////////////////////////////////////////////////////////////////
//  Unicode Derived Categories
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(alphabetic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(uppercase)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lowercase)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(white_space)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(hex_digit)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(noncharacter_code_point)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(default_ignorable_code_point)

///////////////////////////////////////////////////////////////////////////
//  Unicode Scripts
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(arabic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(imperial_aramaic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(armenian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(avestan)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(balinese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(bamum)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(bengali)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(bopomofo)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(braille)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(buginese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(buhid)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(canadian_aboriginal)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(carian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(cham)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(cherokee)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(coptic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(cypriot)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(cyrillic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(devanagari)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(deseret)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(egyptian_hieroglyphs)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(ethiopic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(georgian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(glagolitic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(gothic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(greek)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(gujarati)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(gurmukhi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(hangul)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(han)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(hanunoo)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(hebrew)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(hiragana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(katakana_or_hiragana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(old_italic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(javanese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(kayah_li)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(katakana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(kharoshthi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(khmer)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(kannada)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(kaithi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tai_tham)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lao)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(latin)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lepcha)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(limbu)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(linear_b)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lisu)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lycian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(lydian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(malayalam)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(mongolian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(meetei_mayek)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(myanmar)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(nko)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(ogham)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(ol_chiki)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(old_turkic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(oriya)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(osmanya)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(phags_pa)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(inscriptional_pahlavi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(phoenician)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(inscriptional_parthian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(rejang)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(runic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(samaritan)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(old_south_arabian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(saurashtra)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(shavian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(sinhala)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(sundanese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(syloti_nagri)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(syriac)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tagbanwa)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tai_le)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(new_tai_lue)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tamil)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tai_viet)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(telugu)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tifinagh)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tagalog)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(thaana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(thai)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(tibetan)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(ugaritic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(vai)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(old_persian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(cuneiform)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(yi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(inherited)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(common)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY(unknown)

#undef QSBOOST_SPIRIT_UNICODE_CLASSIFY
#endif

    };

    ///////////////////////////////////////////////////////////////////////////
    // Convert characters
    template <typename CharEncoding>
    struct convert
    {
        typedef typename CharEncoding::char_type char_type;

        template <typename Char>
        static Char
        to(tag::lower, Char ch)
        {
            return static_cast<Char>(
                CharEncoding::tolower(detail::cast_char<char_type>(ch)));
        }

        template <typename Char>
        static Char
        to(tag::upper, Char ch)
        {
            return static_cast<Char>(
                CharEncoding::toupper(detail::cast_char<char_type>(ch)));
        }

        template <typename Char>
        static Char
        to(tag::ucs4, Char ch)
        {
            return static_cast<Char>(
                CharEncoding::toucs4(detail::cast_char<char_type>(ch)));
        }

        template <typename Char>
        static Char
        to(unused_type, Char ch)
        {
            return ch;
        }
    };

    ///////////////////////////////////////////////////////////////////////////
    // Info on character classification
    template <typename CharEncoding>
    struct what
    {
#define QSBOOST_SPIRIT_CLASSIFY_WHAT(name, isname)                                \
        static char const* is(tag::name)                                        \
        {                                                                       \
            return isname;                                                      \
        }                                                                       \
        /***/

        QSBOOST_SPIRIT_CLASSIFY_WHAT(char_, "char")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(alnum, "alnum")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(alpha, "alpha")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(digit, "digit")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(xdigit, "xdigit")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(cntrl, "cntrl")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(graph, "graph")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(lower, "lower")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(lowernum, "lowernum")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(print, "print")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(punct, "punct")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(space, "space")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(blank, "blank")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(upper, "upper")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(uppernum, "uppernum")
        QSBOOST_SPIRIT_CLASSIFY_WHAT(ucs4, "ucs4")

#undef QSBOOST_SPIRIT_CLASSIFY_WHAT

#if defined(QSBOOST_SPIRIT_UNICODE)

#define QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(name)                                \
        static char const* is(tag::name)                                        \
        {                                                                       \
            return QSBOOST_PP_STRINGIZE(name);                                    \
        }                                                                       \
        /***/

///////////////////////////////////////////////////////////////////////////
//  Unicode Major Categories
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(mark)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(number)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(separator)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(other)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(symbol)

///////////////////////////////////////////////////////////////////////////
//  Unicode General Categories
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(uppercase_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lowercase_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(titlecase_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(modifier_letter)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(other_letter)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(nonspacing_mark)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(enclosing_mark)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(spacing_mark)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(decimal_number)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(letter_number)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(other_number)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(space_separator)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(line_separator)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(paragraph_separator)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(control)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(format)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(private_use)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(surrogate)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(unassigned)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(dash_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(open_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(close_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(connector_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(other_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(initial_punctuation)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(final_punctuation)

    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(math_symbol)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(currency_symbol)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(modifier_symbol)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(other_symbol)

///////////////////////////////////////////////////////////////////////////
//  Unicode Derived Categories
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(alphabetic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(uppercase)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lowercase)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(white_space)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(hex_digit)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(noncharacter_code_point)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(default_ignorable_code_point)

///////////////////////////////////////////////////////////////////////////
//  Unicode Scripts
///////////////////////////////////////////////////////////////////////////
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(arabic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(imperial_aramaic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(armenian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(avestan)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(balinese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(bamum)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(bengali)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(bopomofo)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(braille)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(buginese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(buhid)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(canadian_aboriginal)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(carian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(cham)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(cherokee)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(coptic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(cypriot)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(cyrillic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(devanagari)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(deseret)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(egyptian_hieroglyphs)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(ethiopic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(georgian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(glagolitic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(gothic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(greek)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(gujarati)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(gurmukhi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(hangul)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(han)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(hanunoo)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(hebrew)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(hiragana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(katakana_or_hiragana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(old_italic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(javanese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(kayah_li)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(katakana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(kharoshthi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(khmer)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(kannada)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(kaithi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tai_tham)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lao)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(latin)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lepcha)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(limbu)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(linear_b)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lisu)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lycian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(lydian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(malayalam)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(mongolian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(meetei_mayek)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(myanmar)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(nko)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(ogham)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(ol_chiki)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(old_turkic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(oriya)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(osmanya)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(phags_pa)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(inscriptional_pahlavi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(phoenician)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(inscriptional_parthian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(rejang)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(runic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(samaritan)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(old_south_arabian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(saurashtra)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(shavian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(sinhala)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(sundanese)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(syloti_nagri)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(syriac)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tagbanwa)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tai_le)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(new_tai_lue)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tamil)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tai_viet)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(telugu)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tifinagh)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tagalog)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(thaana)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(thai)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(tibetan)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(ugaritic)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(vai)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(old_persian)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(cuneiform)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(yi)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(inherited)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(common)
    QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT(unknown)

#undef QSBOOST_SPIRIT_UNICODE_CLASSIFY_WHAT
#endif

    };
}}}

namespace qsboost { namespace spirit { namespace traits
{
    ///////////////////////////////////////////////////////////////////////////
    // This meta-function evaluates to mpl::true_ if the function
    // char_encoding::ischar() needs to be called to ensure correct matching.
    // This happens mainly if the character type returned from the underlying
    // iterator is larger than the character type of the used character
    // encoding. Additionally, this meta-function provides a customization
    // point for the lexer library to enforce this behavior while parsing
    // a token stream.
    template <typename Char, typename BaseChar>
    struct mustcheck_ischar
      : mpl::bool_<(sizeof(Char) > sizeof(BaseChar)) ? true : false> {};

    ///////////////////////////////////////////////////////////////////////////
    // The following template calls char_encoding::ischar, if necessary
    template <typename CharParam, typename CharEncoding
      , bool MustCheck = mustcheck_ischar<
            CharParam, typename CharEncoding::char_type>::value>
    struct ischar
    {
        static bool call(CharParam)
        {
            return true;
        }
    };

    template <typename CharParam, typename CharEncoding>
    struct ischar<CharParam, CharEncoding, true>
    {
        static bool call(CharParam const& ch)
        {
            return CharEncoding::ischar(int(ch));
        }
    };

}}}

#if defined(QSBOOST_MSVC)
# pragma warning(pop)
#endif

#endif


