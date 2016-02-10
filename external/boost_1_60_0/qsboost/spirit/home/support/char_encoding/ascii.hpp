/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_ASCII_APRIL_26_2006_1106PM)
#define QSBOOST_SPIRIT_ASCII_APRIL_26_2006_1106PM

#if defined(_MSC_VER)
#pragma once
#endif

#include <climits>
#include <qsboost/assert.hpp>
#include <qsboost/cstdint.hpp>

///////////////////////////////////////////////////////////////////////////////
// constants used to classify the single characters
///////////////////////////////////////////////////////////////////////////////
#define QSBOOST_CC_DIGIT    0x0001
#define QSBOOST_CC_XDIGIT   0x0002
#define QSBOOST_CC_ALPHA    0x0004
#define QSBOOST_CC_CTRL     0x0008
#define QSBOOST_CC_LOWER    0x0010
#define QSBOOST_CC_UPPER    0x0020
#define QSBOOST_CC_SPACE    0x0040
#define QSBOOST_CC_PUNCT    0x0080

namespace qsboost { namespace spirit { namespace char_encoding
{
    // The detection of isgraph(), isprint() and isblank() is done programmatically
    // to keep the character type table small. Additionally, these functions are
    // rather seldom used and the programmatic detection is very simple.

    ///////////////////////////////////////////////////////////////////////////
    // ASCII character classification table
    ///////////////////////////////////////////////////////////////////////////
    const unsigned char ascii_char_types[] =
    {
        /* NUL   0   0 */   QSBOOST_CC_CTRL,
        /* SOH   1   1 */   QSBOOST_CC_CTRL,
        /* STX   2   2 */   QSBOOST_CC_CTRL,
        /* ETX   3   3 */   QSBOOST_CC_CTRL,
        /* EOT   4   4 */   QSBOOST_CC_CTRL,
        /* ENQ   5   5 */   QSBOOST_CC_CTRL,
        /* ACK   6   6 */   QSBOOST_CC_CTRL,
        /* BEL   7   7 */   QSBOOST_CC_CTRL,
        /* BS    8   8 */   QSBOOST_CC_CTRL,
        /* HT    9   9 */   QSBOOST_CC_CTRL|QSBOOST_CC_SPACE,
        /* NL   10   a */   QSBOOST_CC_CTRL|QSBOOST_CC_SPACE,
        /* VT   11   b */   QSBOOST_CC_CTRL|QSBOOST_CC_SPACE,
        /* NP   12   c */   QSBOOST_CC_CTRL|QSBOOST_CC_SPACE,
        /* CR   13   d */   QSBOOST_CC_CTRL|QSBOOST_CC_SPACE,
        /* SO   14   e */   QSBOOST_CC_CTRL,
        /* SI   15   f */   QSBOOST_CC_CTRL,
        /* DLE  16  10 */   QSBOOST_CC_CTRL,
        /* DC1  17  11 */   QSBOOST_CC_CTRL,
        /* DC2  18  12 */   QSBOOST_CC_CTRL,
        /* DC3  19  13 */   QSBOOST_CC_CTRL,
        /* DC4  20  14 */   QSBOOST_CC_CTRL,
        /* NAK  21  15 */   QSBOOST_CC_CTRL,
        /* SYN  22  16 */   QSBOOST_CC_CTRL,
        /* ETB  23  17 */   QSBOOST_CC_CTRL,
        /* CAN  24  18 */   QSBOOST_CC_CTRL,
        /* EM   25  19 */   QSBOOST_CC_CTRL,
        /* SUB  26  1a */   QSBOOST_CC_CTRL,
        /* ESC  27  1b */   QSBOOST_CC_CTRL,
        /* FS   28  1c */   QSBOOST_CC_CTRL,
        /* GS   29  1d */   QSBOOST_CC_CTRL,
        /* RS   30  1e */   QSBOOST_CC_CTRL,
        /* US   31  1f */   QSBOOST_CC_CTRL,
        /* SP   32  20 */   QSBOOST_CC_SPACE,
        /*  !   33  21 */   QSBOOST_CC_PUNCT,
        /*  "   34  22 */   QSBOOST_CC_PUNCT,
        /*  #   35  23 */   QSBOOST_CC_PUNCT,
        /*  $   36  24 */   QSBOOST_CC_PUNCT,
        /*  %   37  25 */   QSBOOST_CC_PUNCT,
        /*  &   38  26 */   QSBOOST_CC_PUNCT,
        /*  '   39  27 */   QSBOOST_CC_PUNCT,
        /*  (   40  28 */   QSBOOST_CC_PUNCT,
        /*  )   41  29 */   QSBOOST_CC_PUNCT,
        /*  *   42  2a */   QSBOOST_CC_PUNCT,
        /*  +   43  2b */   QSBOOST_CC_PUNCT,
        /*  ,   44  2c */   QSBOOST_CC_PUNCT,
        /*  -   45  2d */   QSBOOST_CC_PUNCT,
        /*  .   46  2e */   QSBOOST_CC_PUNCT,
        /*  /   47  2f */   QSBOOST_CC_PUNCT,
        /*  0   48  30 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  1   49  31 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  2   50  32 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  3   51  33 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  4   52  34 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  5   53  35 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  6   54  36 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  7   55  37 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  8   56  38 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  9   57  39 */   QSBOOST_CC_DIGIT|QSBOOST_CC_XDIGIT,
        /*  :   58  3a */   QSBOOST_CC_PUNCT,
        /*  ;   59  3b */   QSBOOST_CC_PUNCT,
        /*  <   60  3c */   QSBOOST_CC_PUNCT,
        /*  =   61  3d */   QSBOOST_CC_PUNCT,
        /*  >   62  3e */   QSBOOST_CC_PUNCT,
        /*  ?   63  3f */   QSBOOST_CC_PUNCT,
        /*  @   64  40 */   QSBOOST_CC_PUNCT,
        /*  A   65  41 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_UPPER,
        /*  B   66  42 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_UPPER,
        /*  C   67  43 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_UPPER,
        /*  D   68  44 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_UPPER,
        /*  E   69  45 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_UPPER,
        /*  F   70  46 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_UPPER,
        /*  G   71  47 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  H   72  48 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  I   73  49 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  J   74  4a */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  K   75  4b */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  L   76  4c */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  M   77  4d */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  N   78  4e */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  O   79  4f */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  P   80  50 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Q   81  51 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  R   82  52 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  S   83  53 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  T   84  54 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  U   85  55 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  V   86  56 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  W   87  57 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  X   88  58 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Y   89  59 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Z   90  5a */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  [   91  5b */   QSBOOST_CC_PUNCT,
        /*  \   92  5c */   QSBOOST_CC_PUNCT,
        /*  ]   93  5d */   QSBOOST_CC_PUNCT,
        /*  ^   94  5e */   QSBOOST_CC_PUNCT,
        /*  _   95  5f */   QSBOOST_CC_PUNCT,
        /*  `   96  60 */   QSBOOST_CC_PUNCT,
        /*  a   97  61 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_LOWER,
        /*  b   98  62 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_LOWER,
        /*  c   99  63 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_LOWER,
        /*  d  100  64 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_LOWER,
        /*  e  101  65 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_LOWER,
        /*  f  102  66 */   QSBOOST_CC_ALPHA|QSBOOST_CC_XDIGIT|QSBOOST_CC_LOWER,
        /*  g  103  67 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  h  104  68 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  i  105  69 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  j  106  6a */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  k  107  6b */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  l  108  6c */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  m  109  6d */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  n  110  6e */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  o  111  6f */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  p  112  70 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  q  113  71 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  r  114  72 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  s  115  73 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  t  116  74 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  u  117  75 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  v  118  76 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  w  119  77 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  x  120  78 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  y  121  79 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  z  122  7a */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  {  123  7b */   QSBOOST_CC_PUNCT,
        /*  |  124  7c */   QSBOOST_CC_PUNCT,
        /*  }  125  7d */   QSBOOST_CC_PUNCT,
        /*  ~  126  7e */   QSBOOST_CC_PUNCT,
        /* DEL 127  7f */   QSBOOST_CC_CTRL,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    ///////////////////////////////////////////////////////////////////////////
    //  Test characters for specified conditions (using ASCII)
    ///////////////////////////////////////////////////////////////////////////
    struct ascii
    {
        typedef char char_type;

        static bool
        isascii_(int ch)
        {
            return 0 == (ch & ~0x7f);
        }

        static bool
        ischar(int ch)
        {
            return isascii_(ch);
        }

        static bool
        isalnum(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_ALPHA)
                || (ascii_char_types[ch] & QSBOOST_CC_DIGIT);
        }

        static bool
        isalpha(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_ALPHA) ? true : false;
        }

        static bool
        isdigit(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_DIGIT) ? true : false;
        }

        static bool
        isxdigit(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_XDIGIT) ? true : false;
        }

        static bool
        iscntrl(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_CTRL) ? true : false;
        }

        static bool
        isgraph(int ch)
        {
            return ('\x21' <= ch && ch <= '\x7e');
        }

        static bool
        islower(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_LOWER) ? true : false;
        }

        static bool
        isprint(int ch)
        {
            return ('\x20' <= ch && ch <= '\x7e');
        }

        static bool
        ispunct(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_PUNCT) ? true : false;
        }

        static bool
        isspace(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_SPACE) ? true : false;
        }

        static bool
        isblank QSBOOST_PREVENT_MACRO_SUBSTITUTION (int ch)
        {
            return ('\x09' == ch || '\x20' == ch);
        }

        static bool
        isupper(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (ascii_char_types[ch] & QSBOOST_CC_UPPER) ? true : false;
        }

        ///////////////////////////////////////////////////////////////////////
        //  Simple character conversions
        ///////////////////////////////////////////////////////////////////////

        static int
        tolower(int ch)
        {
            return isupper(ch) ? (ch - 'A' + 'a') : ch;
        }

        static int
        toupper(int ch)
        {
            return islower(ch) ? (ch - 'a' + 'A') : ch;
        }

        static ::qsboost::uint32_t
        toucs4(int ch)
        {
            return ch;
        }
    };

}}}

///////////////////////////////////////////////////////////////////////////////
// undefine macros
///////////////////////////////////////////////////////////////////////////////
#undef QSBOOST_CC_DIGIT
#undef QSBOOST_CC_XDIGIT
#undef QSBOOST_CC_ALPHA
#undef QSBOOST_CC_CTRL
#undef QSBOOST_CC_LOWER
#undef QSBOOST_CC_UPPER
#undef QSBOOST_CC_PUNCT
#undef QSBOOST_CC_SPACE

#endif
