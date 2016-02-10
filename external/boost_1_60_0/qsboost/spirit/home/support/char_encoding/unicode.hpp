/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_UNICODE_1_JANUARY_12_2010_0728PM)
#define QSBOOST_SPIRIT_UNICODE_1_JANUARY_12_2010_0728PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/cstdint.hpp>
#include <qsboost/spirit/home/support/char_encoding/unicode/query.hpp>

namespace qsboost { namespace spirit { namespace char_encoding
{
    ///////////////////////////////////////////////////////////////////////////
    //  Test characters for specified conditions (using iso8859-1)
    ///////////////////////////////////////////////////////////////////////////
    struct unicode
    {
        typedef ::qsboost::uint32_t char_type;

    ///////////////////////////////////////////////////////////////////////////
    //  Posix stuff
    ///////////////////////////////////////////////////////////////////////////
        static bool
        isascii_(char_type ch)
        {
            return 0 == (ch & ~0x7f);
        }

        static bool
        ischar(char_type ch)
        {
            // unicode code points in the range 0x00 to 0x10FFFF
            return ch <= 0x10FFFF;
        }

        static bool
        isalnum(char_type ch)
        {
            return ucd::is_alphanumeric(ch);
        }

        static bool
        isalpha(char_type ch)
        {
            return ucd::is_alphabetic(ch);
        }

        static bool
        isdigit(char_type ch)
        {
            return ucd::is_decimal_number(ch);
        }

        static bool
        isxdigit(char_type ch)
        {
            return ucd::is_hex_digit(ch);
        }

        static bool
        iscntrl(char_type ch)
        {
            return ucd::is_control(ch);
        }

        static bool
        isgraph(char_type ch)
        {
            return ucd::is_graph(ch);
        }

        static bool
        islower(char_type ch)
        {
            return ucd::is_lowercase(ch);
        }

        static bool
        isprint(char_type ch)
        {
            return ucd::is_print(ch);
        }

        static bool
        ispunct(char_type ch)
        {
            return ucd::is_punctuation(ch);
        }

        static bool
        isspace(char_type ch)
        {
            return ucd::is_white_space(ch);
        }

        static bool
        isblank QSBOOST_PREVENT_MACRO_SUBSTITUTION (char_type ch)
        {
            return ucd::is_blank(ch);
        }

        static bool
        isupper(char_type ch)
        {
            return ucd::is_uppercase(ch);
        }

    ///////////////////////////////////////////////////////////////////////////
    //  Simple character conversions
    ///////////////////////////////////////////////////////////////////////////

        static char_type
        tolower(char_type ch)
        {
            return ucd::to_lowercase(ch);
        }

        static char_type
        toupper(char_type ch)
        {
            return ucd::to_uppercase(ch);
        }

        static ::qsboost::uint32_t
        toucs4(char_type ch)
        {
            return ch;
        }

    ///////////////////////////////////////////////////////////////////////////
    //  Major Categories
    ///////////////////////////////////////////////////////////////////////////
#define QSBOOST_SPIRIT_MAJOR_CATEGORY(name)                                       \
        static bool                                                             \
        is_##name(char_type ch)                                                 \
        {                                                                       \
            return ucd::get_major_category(ch) == ucd::properties::name;        \
        }                                                                       \
        /***/

        QSBOOST_SPIRIT_MAJOR_CATEGORY(letter)
        QSBOOST_SPIRIT_MAJOR_CATEGORY(mark)
        QSBOOST_SPIRIT_MAJOR_CATEGORY(number)
        QSBOOST_SPIRIT_MAJOR_CATEGORY(separator)
        QSBOOST_SPIRIT_MAJOR_CATEGORY(other)
        QSBOOST_SPIRIT_MAJOR_CATEGORY(punctuation)
        QSBOOST_SPIRIT_MAJOR_CATEGORY(symbol)

    ///////////////////////////////////////////////////////////////////////////
    //  General Categories
    ///////////////////////////////////////////////////////////////////////////
#define QSBOOST_SPIRIT_CATEGORY(name)                                             \
        static bool                                                             \
        is_##name(char_type ch)                                                 \
        {                                                                       \
            return ucd::get_category(ch) == ucd::properties::name;              \
        }                                                                       \
        /***/

        QSBOOST_SPIRIT_CATEGORY(uppercase_letter)
        QSBOOST_SPIRIT_CATEGORY(lowercase_letter)
        QSBOOST_SPIRIT_CATEGORY(titlecase_letter)
        QSBOOST_SPIRIT_CATEGORY(modifier_letter)
        QSBOOST_SPIRIT_CATEGORY(other_letter)

        QSBOOST_SPIRIT_CATEGORY(nonspacing_mark)
        QSBOOST_SPIRIT_CATEGORY(enclosing_mark)
        QSBOOST_SPIRIT_CATEGORY(spacing_mark)

        QSBOOST_SPIRIT_CATEGORY(decimal_number)
        QSBOOST_SPIRIT_CATEGORY(letter_number)
        QSBOOST_SPIRIT_CATEGORY(other_number)

        QSBOOST_SPIRIT_CATEGORY(space_separator)
        QSBOOST_SPIRIT_CATEGORY(line_separator)
        QSBOOST_SPIRIT_CATEGORY(paragraph_separator)

        QSBOOST_SPIRIT_CATEGORY(control)
        QSBOOST_SPIRIT_CATEGORY(format)
        QSBOOST_SPIRIT_CATEGORY(private_use)
        QSBOOST_SPIRIT_CATEGORY(surrogate)
        QSBOOST_SPIRIT_CATEGORY(unassigned)

        QSBOOST_SPIRIT_CATEGORY(dash_punctuation)
        QSBOOST_SPIRIT_CATEGORY(open_punctuation)
        QSBOOST_SPIRIT_CATEGORY(close_punctuation)
        QSBOOST_SPIRIT_CATEGORY(connector_punctuation)
        QSBOOST_SPIRIT_CATEGORY(other_punctuation)
        QSBOOST_SPIRIT_CATEGORY(initial_punctuation)
        QSBOOST_SPIRIT_CATEGORY(final_punctuation)

        QSBOOST_SPIRIT_CATEGORY(math_symbol)
        QSBOOST_SPIRIT_CATEGORY(currency_symbol)
        QSBOOST_SPIRIT_CATEGORY(modifier_symbol)
        QSBOOST_SPIRIT_CATEGORY(other_symbol)

    ///////////////////////////////////////////////////////////////////////////
    //  Derived Categories
    ///////////////////////////////////////////////////////////////////////////
#define QSBOOST_SPIRIT_DERIVED_CATEGORY(name)                                     \
        static bool                                                             \
        is_##name(char_type ch)                                                 \
        {                                                                       \
            return ucd::is_##name(ch);                                          \
        }                                                                       \
        /***/

        QSBOOST_SPIRIT_DERIVED_CATEGORY(alphabetic)
        QSBOOST_SPIRIT_DERIVED_CATEGORY(uppercase)
        QSBOOST_SPIRIT_DERIVED_CATEGORY(lowercase)
        QSBOOST_SPIRIT_DERIVED_CATEGORY(white_space)
        QSBOOST_SPIRIT_DERIVED_CATEGORY(hex_digit)
        QSBOOST_SPIRIT_DERIVED_CATEGORY(noncharacter_code_point)
        QSBOOST_SPIRIT_DERIVED_CATEGORY(default_ignorable_code_point)

    ///////////////////////////////////////////////////////////////////////////
    //  Scripts
    ///////////////////////////////////////////////////////////////////////////
#define QSBOOST_SPIRIT_SCRIPT(name)                                               \
        static bool                                                             \
        is_##name(char_type ch)                                                 \
        {                                                                       \
            return ucd::get_script(ch) == ucd::properties::name;                \
        }                                                                       \
        /***/

        QSBOOST_SPIRIT_SCRIPT(arabic)
        QSBOOST_SPIRIT_SCRIPT(imperial_aramaic)
        QSBOOST_SPIRIT_SCRIPT(armenian)
        QSBOOST_SPIRIT_SCRIPT(avestan)
        QSBOOST_SPIRIT_SCRIPT(balinese)
        QSBOOST_SPIRIT_SCRIPT(bamum)
        QSBOOST_SPIRIT_SCRIPT(bengali)
        QSBOOST_SPIRIT_SCRIPT(bopomofo)
        QSBOOST_SPIRIT_SCRIPT(braille)
        QSBOOST_SPIRIT_SCRIPT(buginese)
        QSBOOST_SPIRIT_SCRIPT(buhid)
        QSBOOST_SPIRIT_SCRIPT(canadian_aboriginal)
        QSBOOST_SPIRIT_SCRIPT(carian)
        QSBOOST_SPIRIT_SCRIPT(cham)
        QSBOOST_SPIRIT_SCRIPT(cherokee)
        QSBOOST_SPIRIT_SCRIPT(coptic)
        QSBOOST_SPIRIT_SCRIPT(cypriot)
        QSBOOST_SPIRIT_SCRIPT(cyrillic)
        QSBOOST_SPIRIT_SCRIPT(devanagari)
        QSBOOST_SPIRIT_SCRIPT(deseret)
        QSBOOST_SPIRIT_SCRIPT(egyptian_hieroglyphs)
        QSBOOST_SPIRIT_SCRIPT(ethiopic)
        QSBOOST_SPIRIT_SCRIPT(georgian)
        QSBOOST_SPIRIT_SCRIPT(glagolitic)
        QSBOOST_SPIRIT_SCRIPT(gothic)
        QSBOOST_SPIRIT_SCRIPT(greek)
        QSBOOST_SPIRIT_SCRIPT(gujarati)
        QSBOOST_SPIRIT_SCRIPT(gurmukhi)
        QSBOOST_SPIRIT_SCRIPT(hangul)
        QSBOOST_SPIRIT_SCRIPT(han)
        QSBOOST_SPIRIT_SCRIPT(hanunoo)
        QSBOOST_SPIRIT_SCRIPT(hebrew)
        QSBOOST_SPIRIT_SCRIPT(hiragana)
        QSBOOST_SPIRIT_SCRIPT(katakana_or_hiragana)
        QSBOOST_SPIRIT_SCRIPT(old_italic)
        QSBOOST_SPIRIT_SCRIPT(javanese)
        QSBOOST_SPIRIT_SCRIPT(kayah_li)
        QSBOOST_SPIRIT_SCRIPT(katakana)
        QSBOOST_SPIRIT_SCRIPT(kharoshthi)
        QSBOOST_SPIRIT_SCRIPT(khmer)
        QSBOOST_SPIRIT_SCRIPT(kannada)
        QSBOOST_SPIRIT_SCRIPT(kaithi)
        QSBOOST_SPIRIT_SCRIPT(tai_tham)
        QSBOOST_SPIRIT_SCRIPT(lao)
        QSBOOST_SPIRIT_SCRIPT(latin)
        QSBOOST_SPIRIT_SCRIPT(lepcha)
        QSBOOST_SPIRIT_SCRIPT(limbu)
        QSBOOST_SPIRIT_SCRIPT(linear_b)
        QSBOOST_SPIRIT_SCRIPT(lisu)
        QSBOOST_SPIRIT_SCRIPT(lycian)
        QSBOOST_SPIRIT_SCRIPT(lydian)
        QSBOOST_SPIRIT_SCRIPT(malayalam)
        QSBOOST_SPIRIT_SCRIPT(mongolian)
        QSBOOST_SPIRIT_SCRIPT(meetei_mayek)
        QSBOOST_SPIRIT_SCRIPT(myanmar)
        QSBOOST_SPIRIT_SCRIPT(nko)
        QSBOOST_SPIRIT_SCRIPT(ogham)
        QSBOOST_SPIRIT_SCRIPT(ol_chiki)
        QSBOOST_SPIRIT_SCRIPT(old_turkic)
        QSBOOST_SPIRIT_SCRIPT(oriya)
        QSBOOST_SPIRIT_SCRIPT(osmanya)
        QSBOOST_SPIRIT_SCRIPT(phags_pa)
        QSBOOST_SPIRIT_SCRIPT(inscriptional_pahlavi)
        QSBOOST_SPIRIT_SCRIPT(phoenician)
        QSBOOST_SPIRIT_SCRIPT(inscriptional_parthian)
        QSBOOST_SPIRIT_SCRIPT(rejang)
        QSBOOST_SPIRIT_SCRIPT(runic)
        QSBOOST_SPIRIT_SCRIPT(samaritan)
        QSBOOST_SPIRIT_SCRIPT(old_south_arabian)
        QSBOOST_SPIRIT_SCRIPT(saurashtra)
        QSBOOST_SPIRIT_SCRIPT(shavian)
        QSBOOST_SPIRIT_SCRIPT(sinhala)
        QSBOOST_SPIRIT_SCRIPT(sundanese)
        QSBOOST_SPIRIT_SCRIPT(syloti_nagri)
        QSBOOST_SPIRIT_SCRIPT(syriac)
        QSBOOST_SPIRIT_SCRIPT(tagbanwa)
        QSBOOST_SPIRIT_SCRIPT(tai_le)
        QSBOOST_SPIRIT_SCRIPT(new_tai_lue)
        QSBOOST_SPIRIT_SCRIPT(tamil)
        QSBOOST_SPIRIT_SCRIPT(tai_viet)
        QSBOOST_SPIRIT_SCRIPT(telugu)
        QSBOOST_SPIRIT_SCRIPT(tifinagh)
        QSBOOST_SPIRIT_SCRIPT(tagalog)
        QSBOOST_SPIRIT_SCRIPT(thaana)
        QSBOOST_SPIRIT_SCRIPT(thai)
        QSBOOST_SPIRIT_SCRIPT(tibetan)
        QSBOOST_SPIRIT_SCRIPT(ugaritic)
        QSBOOST_SPIRIT_SCRIPT(vai)
        QSBOOST_SPIRIT_SCRIPT(old_persian)
        QSBOOST_SPIRIT_SCRIPT(cuneiform)
        QSBOOST_SPIRIT_SCRIPT(yi)
        QSBOOST_SPIRIT_SCRIPT(inherited)
        QSBOOST_SPIRIT_SCRIPT(common)
        QSBOOST_SPIRIT_SCRIPT(unknown)

#undef QSBOOST_SPIRIT_MAJOR_CATEGORY
#undef QSBOOST_SPIRIT_CATEGORY
#undef QSBOOST_SPIRIT_DERIVED_CATEGORY
#undef QSBOOST_SPIRIT_SCRIPT

    };

}}}

#endif

