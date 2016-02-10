/*=============================================================================
  Copyright (c) 2001-2011 Joel de Guzman
  http://spirit.sourceforge.net/

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef QSBOOST_SPIRIT_COMMON_PLACEHOLDERS_OCTOBER_16_2008_0102PM
#define QSBOOST_SPIRIT_COMMON_PLACEHOLDERS_OCTOBER_16_2008_0102PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/spirit/home/support/terminal.hpp>
#include <qsboost/spirit/home/support/char_encoding/standard.hpp>
#include <qsboost/spirit/home/support/char_encoding/standard_wide.hpp>
#include <qsboost/spirit/home/support/char_encoding/ascii.hpp>
#include <qsboost/spirit/home/support/char_encoding/iso8859_1.hpp>
#include <qsboost/spirit/home/support/char_class.hpp>
#include <qsboost/mpl/vector.hpp>

#if defined(QSBOOST_SPIRIT_UNICODE)
# include <qsboost/spirit/home/support/char_encoding/unicode.hpp>
#endif

namespace qsboost { namespace spirit
{
    typedef mpl::vector<
            spirit::char_encoding::ascii
          , spirit::char_encoding::iso8859_1
          , spirit::char_encoding::standard
          , spirit::char_encoding::standard_wide
#if defined(QSBOOST_SPIRIT_UNICODE)
          , spirit::char_encoding::unicode
#endif
        >
    char_encodings;

    template <typename T>
    struct is_char_encoding : mpl::false_ {};

    template <>
    struct is_char_encoding<spirit::char_encoding::ascii> : mpl::true_ {};

    template <>
    struct is_char_encoding<spirit::char_encoding::iso8859_1> : mpl::true_ {};

    template <>
    struct is_char_encoding<spirit::char_encoding::standard> : mpl::true_ {};

    template <>
    struct is_char_encoding<spirit::char_encoding::standard_wide> : mpl::true_ {};

#if defined(QSBOOST_SPIRIT_UNICODE)
    template <>
    struct is_char_encoding<spirit::char_encoding::unicode> : mpl::true_ {};
#endif

    template <typename Encoding>
    struct encoding
        : proto::terminal<tag::char_code<tag::encoding, Encoding> >::type
    {};

    // Our basic terminals
    QSBOOST_SPIRIT_DEFINE_TERMINALS_NAME(
        ( verbatim, verbatim_type )
        ( no_delimit, no_delimit_type )
        ( lexeme, lexeme_type )
        ( no_skip, no_skip_type )
        ( omit, omit_type )
        ( raw, raw_type )
        ( as_string, as_string_type )
        ( as_wstring, as_wstring_type )
        ( inf, inf_type )
        ( eol, eol_type )
        ( eoi, eoi_type )
        ( buffer, buffer_type )
        ( true_, true_type )
        ( false_, false_type )
        ( matches, matches_type )
        ( hold, hold_type )
        ( strict, strict_type )
        ( relaxed, relaxed_type )
        ( duplicate, duplicate_type )
    )

    // Our extended terminals
    QSBOOST_SPIRIT_DEFINE_TERMINALS_NAME_EX(
        ( lit, lit_type )
        ( bin, bin_type )
        ( oct, oct_type )
        ( hex, hex_type )
        ( bool_, bool_type )
        ( ushort_, ushort_type )
        ( ulong_, ulong_type )
        ( uint_, uint_type )
        ( short_, short_type )
        ( long_, long_type )
        ( int_, int_type )
        ( ulong_long, ulong_long_type )
        ( long_long, long_long_type )
        ( float_, float_type )
        ( double_, double_type )
        ( long_double, long_double_type )
        ( repeat, repeat_type )
        ( eps, eps_type )
        ( pad, pad_type )
        ( byte_, byte_type )
        ( word, word_type )
        ( big_word, big_word_type )
        ( little_word, little_word_type )
        ( dword, dword_type )
        ( big_dword, big_dword_type )
        ( little_dword, little_dword_type )
        ( qword, qword_type )
        ( big_qword, big_qword_type )
        ( little_qword, little_qword_type )
        ( bin_float, bin_float_type )
        ( big_bin_float, big_bin_float_type )
        ( little_bin_float, little_bin_float_type )
        ( bin_double, bin_double_type )
        ( big_bin_double, big_bin_double_type )
        ( little_bin_double, little_bin_double_type )
        ( skip, skip_type )
        ( delimit, delimit_type )
        ( stream, stream_type )
        ( wstream, wstream_type )
        ( left_align, left_align_type )
        ( right_align, right_align_type )
        ( center, center_type )
        ( maxwidth, maxwidth_type )
        ( set_state, set_state_type )
        ( in_state, in_state_type )
        ( token, token_type )
        ( tokenid, tokenid_type )
        ( raw_token, raw_token_type )
        ( tokenid_mask, tokenid_mask_type )
        ( attr, attr_type )
        ( columns, columns_type )
        ( auto_, auto_type )
    )

    // special tags (used mainly for stateful tag types)
    namespace tag
    {
        struct attr_cast { QSBOOST_SPIRIT_IS_TAG() };
        struct as { QSBOOST_SPIRIT_IS_TAG() };
    }
}}

///////////////////////////////////////////////////////////////////////////////
// Here we place the character-set sensitive placeholders. We have one set
// each for ascii, iso8859_1, standard and standard_wide and unicode. These
// placeholders are placed in its char-set namespace. For example, there exist
// a placeholder spirit::ascii::alnum for ascii versions of alnum.

#define QSBOOST_SPIRIT_TAG_CHAR_SPEC(charset)                                     \
    typedef tag::char_code<tag::char_, charset> char_;                          \
    typedef tag::char_code<tag::string, charset> string;                        \
    /***/

#ifdef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS

#define QSBOOST_SPIRIT_CHAR_SPEC(charset)                                         \
    typedef spirit::terminal<tag::charset::char_> char_type;                    \
    typedef spirit::terminal<tag::charset::string> string_type;                 \
    /***/

#else

#define QSBOOST_SPIRIT_CHAR_SPEC(charset)                                         \
    typedef spirit::terminal<tag::charset::char_> char_type;                    \
    char_type const char_ = char_type();                                        \
                                                                                \
    inline void silence_unused_warnings_##char_() { (void) char_; }             \
                                                                                \
    typedef spirit::terminal<tag::charset::string> string_type;                 \
    string_type const string = string_type();                                   \
                                                                                \
    inline void silence_unused_warnings_##string() { (void) string; }           \
    /***/

#endif

#ifdef QSBOOST_SPIRIT_NO_PREDEFINED_TERMINALS

#define QSBOOST_SPIRIT_CHAR_CODE(name, charset)                                   \
    typedef proto::terminal<tag::char_code<tag::name, charset> >::type          \
        name##_type;                                                            \
    /***/

#else

#define QSBOOST_SPIRIT_CHAR_CODE(name, charset)                                   \
    typedef proto::terminal<tag::char_code<tag::name, charset> >::type          \
        name##_type;                                                            \
    name##_type const name = name##_type();                                     \
                                                                                \
    inline void silence_unused_warnings_##name() { (void) name; }               \
    /***/


#endif

#define QSBOOST_SPIRIT_DEFINE_CHAR_CODES(charset)                                 \
    namespace qsboost { namespace spirit { namespace tag { namespace charset      \
    {                                                                           \
        QSBOOST_SPIRIT_TAG_CHAR_SPEC(spirit::char_encoding::charset)              \
    }}}}                                                                        \
    namespace qsboost { namespace spirit { namespace charset                      \
    {                                                                           \
        QSBOOST_SPIRIT_CHAR_SPEC(charset)                                         \
                                                                                \
        QSBOOST_SPIRIT_CHAR_CODE(alnum, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(alpha, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(blank, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(cntrl, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(digit, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(graph, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(print, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(punct, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(space, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(xdigit, spirit::char_encoding::charset)          \
                                                                                \
        QSBOOST_SPIRIT_CHAR_CODE(no_case, spirit::char_encoding::charset)         \
        QSBOOST_SPIRIT_CHAR_CODE(lower, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(upper, spirit::char_encoding::charset)           \
        QSBOOST_SPIRIT_CHAR_CODE(lowernum, spirit::char_encoding::charset)        \
        QSBOOST_SPIRIT_CHAR_CODE(uppernum, spirit::char_encoding::charset)        \
    }}}                                                                         \
    /***/

QSBOOST_SPIRIT_DEFINE_CHAR_CODES(ascii)
QSBOOST_SPIRIT_DEFINE_CHAR_CODES(iso8859_1)
QSBOOST_SPIRIT_DEFINE_CHAR_CODES(standard)
QSBOOST_SPIRIT_DEFINE_CHAR_CODES(standard_wide)

namespace qsboost { namespace spirit { namespace traits
{
    template <typename Char>
    struct char_encoding_from_char;

    template <>
    struct char_encoding_from_char<char>
      : mpl::identity<spirit::char_encoding::standard>
    {};

    template <>
    struct char_encoding_from_char<wchar_t>
      : mpl::identity<spirit::char_encoding::standard_wide>
    {};

    template <typename T>
    struct char_encoding_from_char<T const>
      : char_encoding_from_char<T>
    {};
}}}

#if defined(QSBOOST_SPIRIT_UNICODE)
QSBOOST_SPIRIT_DEFINE_CHAR_CODES(unicode)

    namespace qsboost { namespace spirit { namespace tag { namespace unicode
    {
        QSBOOST_SPIRIT_TAG_CHAR_SPEC(spirit::char_encoding::unicode)
    }}}}

    namespace qsboost { namespace spirit { namespace unicode
    {
#define QSBOOST_SPIRIT_UNICODE_CHAR_CODE(name)                                    \
    QSBOOST_SPIRIT_CHAR_CODE(name, spirit::char_encoding::unicode)                \

    ///////////////////////////////////////////////////////////////////////////
    //  Unicode Major Categories
    ///////////////////////////////////////////////////////////////////////////
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(letter)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(mark)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(number)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(separator)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(other)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(symbol)

    ///////////////////////////////////////////////////////////////////////////
    //  Unicode General Categories
    ///////////////////////////////////////////////////////////////////////////
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(uppercase_letter)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lowercase_letter)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(titlecase_letter)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(modifier_letter)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(other_letter)

        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(nonspacing_mark)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(enclosing_mark)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(spacing_mark)

        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(decimal_number)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(letter_number)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(other_number)

        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(space_separator)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(line_separator)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(paragraph_separator)

        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(control)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(format)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(private_use)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(surrogate)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(unassigned)

        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(dash_punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(open_punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(close_punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(connector_punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(other_punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(initial_punctuation)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(final_punctuation)

        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(math_symbol)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(currency_symbol)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(modifier_symbol)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(other_symbol)

    ///////////////////////////////////////////////////////////////////////////
    //  Unicode Derived Categories
    ///////////////////////////////////////////////////////////////////////////
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(alphabetic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(uppercase)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lowercase)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(white_space)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(hex_digit)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(noncharacter_code_point)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(default_ignorable_code_point)

    ///////////////////////////////////////////////////////////////////////////
    //  Unicode Scripts
    ///////////////////////////////////////////////////////////////////////////
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(arabic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(imperial_aramaic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(armenian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(avestan)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(balinese)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(bamum)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(bengali)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(bopomofo)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(braille)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(buginese)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(buhid)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(canadian_aboriginal)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(carian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(cham)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(cherokee)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(coptic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(cypriot)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(cyrillic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(devanagari)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(deseret)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(egyptian_hieroglyphs)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(ethiopic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(georgian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(glagolitic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(gothic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(greek)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(gujarati)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(gurmukhi)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(hangul)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(han)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(hanunoo)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(hebrew)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(hiragana)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(katakana_or_hiragana)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(old_italic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(javanese)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(kayah_li)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(katakana)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(kharoshthi)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(khmer)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(kannada)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(kaithi)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tai_tham)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lao)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(latin)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lepcha)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(limbu)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(linear_b)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lisu)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lycian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(lydian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(malayalam)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(mongolian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(meetei_mayek)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(myanmar)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(nko)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(ogham)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(ol_chiki)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(old_turkic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(oriya)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(osmanya)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(phags_pa)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(inscriptional_pahlavi)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(phoenician)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(inscriptional_parthian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(rejang)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(runic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(samaritan)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(old_south_arabian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(saurashtra)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(shavian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(sinhala)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(sundanese)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(syloti_nagri)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(syriac)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tagbanwa)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tai_le)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(new_tai_lue)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tamil)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tai_viet)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(telugu)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tifinagh)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tagalog)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(thaana)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(thai)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(tibetan)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(ugaritic)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(vai)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(old_persian)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(cuneiform)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(yi)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(inherited)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(common)
        QSBOOST_SPIRIT_UNICODE_CHAR_CODE(unknown)

#undef QSBOOST_SPIRIT_UNICODE_CHAR_CODE
    }}}
#endif

#endif
