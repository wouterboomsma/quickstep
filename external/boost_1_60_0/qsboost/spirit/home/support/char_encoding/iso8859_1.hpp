/*=============================================================================
    Copyright (c) 2001-2011 Hartmut Kaiser
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#if !defined(QSBOOST_SPIRIT_ISO8859_1_APRIL_26_2006_1106PM)
#define QSBOOST_SPIRIT_ISO8859_1_APRIL_26_2006_1106PM

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
    // ISO 8859-1 character classification table
    //
    // the comments intentionally contain non-ascii characters
    // boostinspect:noascii
    ///////////////////////////////////////////////////////////////////////////
    const unsigned char iso8859_1_char_types[] =
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
        /* --  128  80 */   QSBOOST_CC_CTRL,
        /* --  129  81 */   QSBOOST_CC_CTRL,
        /* --  130  82 */   QSBOOST_CC_CTRL,
        /* --  131  83 */   QSBOOST_CC_CTRL,
        /* --  132  84 */   QSBOOST_CC_CTRL,
        /* --  133  85 */   QSBOOST_CC_CTRL,
        /* --  134  86 */   QSBOOST_CC_CTRL,
        /* --  135  87 */   QSBOOST_CC_CTRL,
        /* --  136  88 */   QSBOOST_CC_CTRL,
        /* --  137  89 */   QSBOOST_CC_CTRL,
        /* --  138  8a */   QSBOOST_CC_CTRL,
        /* --  139  8b */   QSBOOST_CC_CTRL,
        /* --  140  8c */   QSBOOST_CC_CTRL,
        /* --  141  8d */   QSBOOST_CC_CTRL,
        /* --  142  8e */   QSBOOST_CC_CTRL,
        /* --  143  8f */   QSBOOST_CC_CTRL,
        /* --  144  90 */   QSBOOST_CC_CTRL,
        /* --  145  91 */   QSBOOST_CC_CTRL,
        /* --  146  92 */   QSBOOST_CC_CTRL,
        /* --  147  93 */   QSBOOST_CC_CTRL,
        /* --  148  94 */   QSBOOST_CC_CTRL,
        /* --  149  95 */   QSBOOST_CC_CTRL,
        /* --  150  96 */   QSBOOST_CC_CTRL,
        /* --  151  97 */   QSBOOST_CC_CTRL,
        /* --  152  98 */   QSBOOST_CC_CTRL,
        /* --  153  99 */   QSBOOST_CC_CTRL,
        /* --  154  9a */   QSBOOST_CC_CTRL,
        /* --  155  9b */   QSBOOST_CC_CTRL,
        /* --  156  9c */   QSBOOST_CC_CTRL,
        /* --  157  9d */   QSBOOST_CC_CTRL,
        /* --  158  9e */   QSBOOST_CC_CTRL,
        /* --  159  9f */   QSBOOST_CC_CTRL,
        /*     160  a0 */   QSBOOST_CC_SPACE,
        /*  ¡  161  a1 */   QSBOOST_CC_PUNCT,
        /*  ¢  162  a2 */   QSBOOST_CC_PUNCT,
        /*  £  163  a3 */   QSBOOST_CC_PUNCT,
        /*  ¤  164  a4 */   QSBOOST_CC_PUNCT,
        /*  ¥  165  a5 */   QSBOOST_CC_PUNCT,
        /*  ¦  166  a6 */   QSBOOST_CC_PUNCT,
        /*  §  167  a7 */   QSBOOST_CC_PUNCT,
        /*  ¨  168  a8 */   QSBOOST_CC_PUNCT,
        /*  ©  169  a9 */   QSBOOST_CC_PUNCT,
        /*  ª  170  aa */   QSBOOST_CC_PUNCT,
        /*  «  171  ab */   QSBOOST_CC_PUNCT,
        /*  ¬  172  ac */   QSBOOST_CC_PUNCT,
        /*  ­  173  ad */   QSBOOST_CC_PUNCT,
        /*  ®  174  ae */   QSBOOST_CC_PUNCT,
        /*  ¯  175  af */   QSBOOST_CC_PUNCT,
        /*  °  176  b0 */   QSBOOST_CC_PUNCT,
        /*  ±  177  b1 */   QSBOOST_CC_PUNCT,
        /*  ²  178  b2 */   QSBOOST_CC_DIGIT|QSBOOST_CC_PUNCT,
        /*  ³  179  b3 */   QSBOOST_CC_DIGIT|QSBOOST_CC_PUNCT,
        /*  ´  180  b4 */   QSBOOST_CC_PUNCT,
        /*  µ  181  b5 */   QSBOOST_CC_PUNCT,
        /*  ¶  182  b6 */   QSBOOST_CC_PUNCT,
        /*  ·  183  b7 */   QSBOOST_CC_PUNCT,
        /*  ¸  184  b8 */   QSBOOST_CC_PUNCT,
        /*  ¹  185  b9 */   QSBOOST_CC_DIGIT|QSBOOST_CC_PUNCT,
        /*  º  186  ba */   QSBOOST_CC_PUNCT,
        /*  »  187  bb */   QSBOOST_CC_PUNCT,
        /*  ¼  188  bc */   QSBOOST_CC_PUNCT,
        /*  ½  189  bd */   QSBOOST_CC_PUNCT,
        /*  ¾  190  be */   QSBOOST_CC_PUNCT,
        /*  ¿  191  bf */   QSBOOST_CC_PUNCT,
        /*  À  192  c0 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Á  193  c1 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Â  194  c2 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ã  195  c3 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ä  196  c4 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Å  197  c5 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Æ  198  c6 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ç  199  c7 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  È  200  c8 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  É  201  c9 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ê  202  ca */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ë  203  cb */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ì  204  cc */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Í  205  cd */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Î  206  ce */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ï  207  cf */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ð  208  d0 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ñ  209  d1 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ò  210  d2 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ó  211  d3 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ô  212  d4 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Õ  213  d5 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ö  214  d6 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  ×  215  d7 */   QSBOOST_CC_PUNCT,
        /*  Ø  216  d8 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ù  217  d9 */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ú  218  da */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Û  219  db */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ü  220  dc */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Ý  221  dd */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  Þ  222  de */   QSBOOST_CC_ALPHA|QSBOOST_CC_UPPER,
        /*  ß  223  df */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  à  224  e0 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  á  225  e1 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  â  226  e2 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ã  227  e3 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ä  228  e4 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  å  229  e5 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  æ  230  e6 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ç  231  e7 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  è  232  e8 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  é  233  e9 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ê  234  ea */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ë  235  eb */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ì  236  ec */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  í  237  ed */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  î  238  ee */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ï  239  ef */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ð  240  f0 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ñ  241  f1 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ò  242  f2 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ó  243  f3 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ô  244  f4 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  õ  245  f5 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ö  246  f6 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ÷  247  f7 */   QSBOOST_CC_PUNCT,
        /*  ø  248  f8 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ù  249  f9 */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ú  250  fa */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  û  251  fb */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ü  252  fc */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ý  253  fd */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  þ  254  fe */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
        /*  ÿ  255  ff */   QSBOOST_CC_ALPHA|QSBOOST_CC_LOWER,
    };

    ///////////////////////////////////////////////////////////////////////////
    // ISO 8859-1 character conversion table
    ///////////////////////////////////////////////////////////////////////////
    const unsigned char iso8859_1_char_conversion[] =
    {
        /* NUL   0   0 */   '\0',
        /* SOH   1   1 */   '\0',
        /* STX   2   2 */   '\0',
        /* ETX   3   3 */   '\0',
        /* EOT   4   4 */   '\0',
        /* ENQ   5   5 */   '\0',
        /* ACK   6   6 */   '\0',
        /* BEL   7   7 */   '\0',
        /* BS    8   8 */   '\0',
        /* HT    9   9 */   '\0',
        /* NL   10   a */   '\0',
        /* VT   11   b */   '\0',
        /* NP   12   c */   '\0',
        /* CR   13   d */   '\0',
        /* SO   14   e */   '\0',
        /* SI   15   f */   '\0',
        /* DLE  16  10 */   '\0',
        /* DC1  17  11 */   '\0',
        /* DC2  18  12 */   '\0',
        /* DC3  19  13 */   '\0',
        /* DC4  20  14 */   '\0',
        /* NAK  21  15 */   '\0',
        /* SYN  22  16 */   '\0',
        /* ETB  23  17 */   '\0',
        /* CAN  24  18 */   '\0',
        /* EM   25  19 */   '\0',
        /* SUB  26  1a */   '\0',
        /* ESC  27  1b */   '\0',
        /* FS   28  1c */   '\0',
        /* GS   29  1d */   '\0',
        /* RS   30  1e */   '\0',
        /* US   31  1f */   '\0',
        /* SP   32  20 */   '\0',
        /*  !   33  21 */   '\0',
        /*  "   34  22 */   '\0',
        /*  #   35  23 */   '\0',
        /*  $   36  24 */   '\0',
        /*  %   37  25 */   '\0',
        /*  &   38  26 */   '\0',
        /*  '   39  27 */   '\0',
        /*  (   40  28 */   '\0',
        /*  )   41  29 */   '\0',
        /*  *   42  2a */   '\0',
        /*  +   43  2b */   '\0',
        /*  ,   44  2c */   '\0',
        /*  -   45  2d */   '\0',
        /*  .   46  2e */   '\0',
        /*  /   47  2f */   '\0',
        /*  0   48  30 */   '\0',
        /*  1   49  31 */   '\0',
        /*  2   50  32 */   '\0',
        /*  3   51  33 */   '\0',
        /*  4   52  34 */   '\0',
        /*  5   53  35 */   '\0',
        /*  6   54  36 */   '\0',
        /*  7   55  37 */   '\0',
        /*  8   56  38 */   '\0',
        /*  9   57  39 */   '\0',
        /*  :   58  3a */   '\0',
        /*  ;   59  3b */   '\0',
        /*  <   60  3c */   '\0',
        /*  =   61  3d */   '\0',
        /*  >   62  3e */   '\0',
        /*  ?   63  3f */   '\0',
        /*  @   64  40 */   '\0',
        /*  A   65  41 */   'a',
        /*  B   66  42 */   'b',
        /*  C   67  43 */   'c',
        /*  D   68  44 */   'd',
        /*  E   69  45 */   'e',
        /*  F   70  46 */   'f',
        /*  G   71  47 */   'g',
        /*  H   72  48 */   'h',
        /*  I   73  49 */   'i',
        /*  J   74  4a */   'j',
        /*  K   75  4b */   'k',
        /*  L   76  4c */   'l',
        /*  M   77  4d */   'm',
        /*  N   78  4e */   'n',
        /*  O   79  4f */   'o',
        /*  P   80  50 */   'p',
        /*  Q   81  51 */   'q',
        /*  R   82  52 */   'r',
        /*  S   83  53 */   's',
        /*  T   84  54 */   't',
        /*  U   85  55 */   'u',
        /*  V   86  56 */   'v',
        /*  W   87  57 */   'w',
        /*  X   88  58 */   'x',
        /*  Y   89  59 */   'y',
        /*  Z   90  5a */   'z',
        /*  [   91  5b */   '\0',
        /*  \   92  5c */   '\0',
        /*  ]   93  5d */   '\0',
        /*  ^   94  5e */   '\0',
        /*  _   95  5f */   '\0',
        /*  `   96  60 */   '\0',
        /*  a   97  61 */   'A',
        /*  b   98  62 */   'B',
        /*  c   99  63 */   'C',
        /*  d  100  64 */   'D',
        /*  e  101  65 */   'E',
        /*  f  102  66 */   'F',
        /*  g  103  67 */   'G',
        /*  h  104  68 */   'H',
        /*  i  105  69 */   'I',
        /*  j  106  6a */   'J',
        /*  k  107  6b */   'K',
        /*  l  108  6c */   'L',
        /*  m  109  6d */   'M',
        /*  n  110  6e */   'N',
        /*  o  111  6f */   'O',
        /*  p  112  70 */   'P',
        /*  q  113  71 */   'Q',
        /*  r  114  72 */   'R',
        /*  s  115  73 */   'S',
        /*  t  116  74 */   'T',
        /*  u  117  75 */   'U',
        /*  v  118  76 */   'V',
        /*  w  119  77 */   'W',
        /*  x  120  78 */   'X',
        /*  y  121  79 */   'Y',
        /*  z  122  7a */   'Z',
        /*  {  123  7b */   '\0',
        /*  |  124  7c */   '\0',
        /*  }  125  7d */   '\0',
        /*  ~  126  7e */   '\0',
        /* DEL 127  7f */   '\0',
        /* --  128  80 */   '\0',
        /* --  129  81 */   '\0',
        /* --  130  82 */   '\0',
        /* --  131  83 */   '\0',
        /* --  132  84 */   '\0',
        /* --  133  85 */   '\0',
        /* --  134  86 */   '\0',
        /* --  135  87 */   '\0',
        /* --  136  88 */   '\0',
        /* --  137  89 */   '\0',
        /* --  138  8a */   '\0',
        /* --  139  8b */   '\0',
        /* --  140  8c */   '\0',
        /* --  141  8d */   '\0',
        /* --  142  8e */   '\0',
        /* --  143  8f */   '\0',
        /* --  144  90 */   '\0',
        /* --  145  91 */   '\0',
        /* --  146  92 */   '\0',
        /* --  147  93 */   '\0',
        /* --  148  94 */   '\0',
        /* --  149  95 */   '\0',
        /* --  150  96 */   '\0',
        /* --  151  97 */   '\0',
        /* --  152  98 */   '\0',
        /* --  153  99 */   '\0',
        /* --  154  9a */   '\0',
        /* --  155  9b */   '\0',
        /* --  156  9c */   '\0',
        /* --  157  9d */   '\0',
        /* --  158  9e */   '\0',
        /* --  159  9f */   '\0',
        /*     160  a0 */   '\0',
        /*  ¡  161  a1 */   '\0',
        /*  ¢  162  a2 */   '\0',
        /*  £  163  a3 */   '\0',
        /*  ¤  164  a4 */   '\0',
        /*  ¥  165  a5 */   '\0',
        /*  ¦  166  a6 */   '\0',
        /*  §  167  a7 */   '\0',
        /*  ¨  168  a8 */   '\0',
        /*  ©  169  a9 */   '\0',
        /*  ª  170  aa */   '\0',
        /*  «  171  ab */   '\0',
        /*  ¬  172  ac */   '\0',
        /*  ­  173  ad */   '\0',
        /*  ®  174  ae */   '\0',
        /*  ¯  175  af */   '\0',
        /*  °  176  b0 */   '\0',
        /*  ±  177  b1 */   '\0',
        /*  ²  178  b2 */   '\0',
        /*  ³  179  b3 */   '\0',
        /*  ´  180  b4 */   '\0',
        /*  µ  181  b5 */   '\0',
        /*  ¶  182  b6 */   '\0',
        /*  ·  183  b7 */   '\0',
        /*  ¸  184  b8 */   '\0',
        /*  ¹  185  b9 */   '\0',
        /*  º  186  ba */   '\0',
        /*  »  187  bb */   '\0',
        /*  ¼  188  bc */   '\0',
        /*  ½  189  bd */   '\0',
        /*  ¾  190  be */   '\0',
        /*  ¿  191  bf */   '\0',
        /*  à  192  c0 */   0xe0,
        /*  á  193  c1 */   0xe1,
        /*  â  194  c2 */   0xe2,
        /*  ã  195  c3 */   0xe3,
        /*  ä  196  c4 */   0xe4,
        /*  å  197  c5 */   0xe5,
        /*  æ  198  c6 */   0xe6,
        /*  ç  199  c7 */   0xe7,
        /*  è  200  c8 */   0xe8,
        /*  é  201  c9 */   0xe9,
        /*  ê  202  ca */   0xea,
        /*  ë  203  cb */   0xeb,
        /*  ì  204  cc */   0xec,
        /*  í  205  cd */   0xed,
        /*  î  206  ce */   0xee,
        /*  ï  207  cf */   0xef,
        /*  ð  208  d0 */   0xf0,
        /*  ñ  209  d1 */   0xf1,
        /*  ò  210  d2 */   0xf2,
        /*  ó  211  d3 */   0xf3,
        /*  ô  212  d4 */   0xf4,
        /*  õ  213  d5 */   0xf5,
        /*  ö  214  d6 */   0xf6,
        /*  ×  215  d7 */   '\0',
        /*  ø  216  d8 */   0xf8,
        /*  ù  217  d9 */   0xf9,
        /*  ú  218  da */   0xfa,
        /*  û  219  db */   0xfb,
        /*  ü  220  dc */   0xfc,
        /*  ý  221  dd */   0xfd,
        /*  þ  222  de */   0xfe,
        /*  ß  223  df */   '\0',
        /*  À  224  e0 */   0xc0,
        /*  Á  225  e1 */   0xc1,
        /*  Â  226  e2 */   0xc2,
        /*  Ã  227  e3 */   0xc3,
        /*  Ä  228  e4 */   0xc4,
        /*  Å  229  e5 */   0xc5,
        /*  Æ  230  e6 */   0xc6,
        /*  Ç  231  e7 */   0xc7,
        /*  È  232  e8 */   0xc8,
        /*  É  233  e9 */   0xc9,
        /*  Ê  234  ea */   0xca,
        /*  Ë  235  eb */   0xcb,
        /*  Ì  236  ec */   0xcc,
        /*  Í  237  ed */   0xcd,
        /*  Î  238  ee */   0xce,
        /*  Ï  239  ef */   0xcf,
        /*  Ð  240  f0 */   0xd0,
        /*  Ñ  241  f1 */   0xd1,
        /*  Ò  242  f2 */   0xd2,
        /*  Ó  243  f3 */   0xd3,
        /*  Ô  244  f4 */   0xd4,
        /*  Õ  245  f5 */   0xd5,
        /*  Ö  246  f6 */   0xd6,
        /*  ÷  247  f7 */   '\0',
        /*  Ø  248  f8 */   0xd8,
        /*  Ù  249  f9 */   0xd9,
        /*  Ú  250  fa */   0xda,
        /*  Û  251  fb */   0xdb,
        /*  Ü  252  fc */   0xdc,
        /*  Ý  253  fd */   0xdd,
        /*  Þ  254  fe */   0xde,
        /*  ÿ  255  ff */   '\0',
    };

    ///////////////////////////////////////////////////////////////////////////
    //  Test characters for specified conditions (using iso8859-1)
    ///////////////////////////////////////////////////////////////////////////
    struct iso8859_1
    {
        typedef unsigned char char_type;

        static bool
        isascii_(int ch)
        {
            return 0 == (ch & ~0x7f);
        }

        static bool
        ischar(int ch)
        {
            // iso8859.1 uses all 8 bits
            // we have to watch out for sign extensions
            return (0 == (ch & ~0xff) || ~0 == (ch | 0xff)) ? true : false;
        }

        static bool
        isalnum(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_ALPHA)
                || (iso8859_1_char_types[ch] & QSBOOST_CC_DIGIT);
        }

        static bool
        isalpha(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_ALPHA) ? true : false;
        }

        static bool
        isdigit(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_DIGIT) ? true : false;
        }

        static bool
        isxdigit(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_XDIGIT) ? true : false;
        }

        static bool
        iscntrl(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_CTRL) ? true : false;
        }

        static bool
        isgraph(int ch)
        {
            return ('\x21' <= ch && ch <= '\x7e') || ('\xa1' <= ch && ch <= '\xff');
        }

        static bool
        islower(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_LOWER) ? true : false;
        }

        static bool
        isprint(int ch)
        {
            return ('\x20' <= ch && ch <= '\x7e') || ('\xa0' <= ch && ch <= '\xff');
        }

        static bool
        ispunct(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_PUNCT) ? true : false;
        }

        static bool
        isspace(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_SPACE) ? true : false;
        }

        static bool
        isblank QSBOOST_PREVENT_MACRO_SUBSTITUTION (int ch)
        {
            return ('\x09' == ch || '\x20' == ch || '\xa0' == ch);
        }

        static bool
        isupper(int ch)
        {
            QSBOOST_ASSERT(0 == (ch & ~UCHAR_MAX));
            return (iso8859_1_char_types[ch] & QSBOOST_CC_UPPER) ? true : false;
        }

    ///////////////////////////////////////////////////////////////////////////
    //  Simple character conversions
    ///////////////////////////////////////////////////////////////////////////

        static int
        tolower(int ch)
        {
            return isupper(ch) && '\0' != iso8859_1_char_conversion[ch] ?
                iso8859_1_char_conversion[ch] : ch;
        }

        static int
        toupper(int ch)
        {
            return islower(ch) && '\0' != iso8859_1_char_conversion[ch] ?
                iso8859_1_char_conversion[ch] : ch;
        }

        static ::qsboost::uint32_t
        toucs4(int ch)
        {
            // The first 256 characters in Unicode and the UCS are
            // identical to those in ISO/IEC-8859-1.
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

