# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002-2011.                             *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_CONFIG_CONFIG_HPP
# define QSBOOST_PREPROCESSOR_CONFIG_CONFIG_HPP
#
# /* BOOST_PP_CONFIG_FLAGS */
#
# define QSBOOST_PP_CONFIG_STRICT() 0x0001
# define QSBOOST_PP_CONFIG_IDEAL() 0x0002
#
# define QSBOOST_PP_CONFIG_MSVC() 0x0004
# define QSBOOST_PP_CONFIG_MWCC() 0x0008
# define QSBOOST_PP_CONFIG_BCC() 0x0010
# define QSBOOST_PP_CONFIG_EDG() 0x0020
# define QSBOOST_PP_CONFIG_DMC() 0x0040
#
# ifndef QSBOOST_PP_CONFIG_FLAGS
#    if defined(__GCCXML__)
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_STRICT())
#    elif defined(__WAVE__)
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_STRICT())
#    elif defined(__MWERKS__) && __MWERKS__ >= 0x3200
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_STRICT())
#    elif defined(__EDG__) || defined(__EDG_VERSION__)
#        if defined(_MSC_VER) && (defined(__INTELLISENSE__) || __EDG_VERSION__ >= 308)
#            define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_MSVC())
#        else
#            define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_EDG() | QSBOOST_PP_CONFIG_STRICT())
#        endif
#    elif defined(__MWERKS__)
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_MWCC())
#    elif defined(__DMC__)
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_DMC())
#    elif defined(__BORLANDC__) && __BORLANDC__ >= 0x581
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_STRICT())
#    elif defined(__BORLANDC__) || defined(__IBMC__) || defined(__IBMCPP__) || defined(__SUNPRO_CC)
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_BCC())
#    elif defined(_MSC_VER) && !defined(__clang__)
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_MSVC())
#    else
#        define QSBOOST_PP_CONFIG_FLAGS() (QSBOOST_PP_CONFIG_STRICT())
#    endif
# endif
#
# /* BOOST_PP_CONFIG_EXTENDED_LINE_INFO */
#
# ifndef QSBOOST_PP_CONFIG_EXTENDED_LINE_INFO
#    define QSBOOST_PP_CONFIG_EXTENDED_LINE_INFO 0
# endif
#
# /* BOOST_PP_CONFIG_ERRORS */
#
# ifndef QSBOOST_PP_CONFIG_ERRORS
#    ifdef NDEBUG
#        define QSBOOST_PP_CONFIG_ERRORS 0
#    else
#        define QSBOOST_PP_CONFIG_ERRORS 1
#    endif
# endif
#
# /* BOOST_PP_VARIADICS */
#
# define QSBOOST_PP_VARIADICS_MSVC 0
# if !defined QSBOOST_PP_VARIADICS
#    /* variadic support explicitly disabled for all untested compilers */
#    if defined __GCCXML__ || defined __CUDACC__ || defined __PATHSCALE__ || defined __DMC__ || defined __CODEGEARC__ || defined __BORLANDC__ || defined __MWERKS__ || ( defined __SUNPRO_CC && __SUNPRO_CC < 0x5130 ) || defined __HP_aCC && !defined __EDG__ || defined __MRC__ || defined __SC__ || defined __IBMCPP__ || defined __PGI
#        define QSBOOST_PP_VARIADICS 0
#    /* VC++ (C/C++) */
#    elif defined _MSC_VER && _MSC_VER >= 1400 && (!defined __EDG__ || defined(__INTELLISENSE__)) && !defined __clang__
#        define QSBOOST_PP_VARIADICS 1
#        undef QSBOOST_PP_VARIADICS_MSVC
#        define QSBOOST_PP_VARIADICS_MSVC 1
#    /* Wave (C/C++), GCC (C++) */
#    elif defined __WAVE__ && __WAVE_HAS_VARIADICS__ || defined __GNUC__ && defined __GXX_EXPERIMENTAL_CXX0X__ && __GXX_EXPERIMENTAL_CXX0X__
#        define QSBOOST_PP_VARIADICS 1
#    /* EDG-based (C/C++), GCC (C), and unknown (C/C++) */
#    elif !defined __cplusplus && __STDC_VERSION__ >= 199901L || __cplusplus >= 201103L
#        define QSBOOST_PP_VARIADICS 1
#    else
#        define QSBOOST_PP_VARIADICS 0
#    endif
# elif !QSBOOST_PP_VARIADICS + 1 < 2
#    undef QSBOOST_PP_VARIADICS
#    define QSBOOST_PP_VARIADICS 1
#    if defined _MSC_VER && _MSC_VER >= 1400 && (defined(__INTELLISENSE__) || !(defined __EDG__ || defined __GCCXML__ || defined __CUDACC__ || defined __PATHSCALE__ || defined __clang__ || defined __DMC__ || defined __CODEGEARC__ || defined __BORLANDC__ || defined __MWERKS__ || defined __SUNPRO_CC || defined __HP_aCC || defined __MRC__ || defined __SC__ || defined __IBMCPP__ || defined __PGI))
#        undef QSBOOST_PP_VARIADICS_MSVC
#        define QSBOOST_PP_VARIADICS_MSVC 1
#    endif
# else
#    undef QSBOOST_PP_VARIADICS
#    define QSBOOST_PP_VARIADICS 0
# endif
#
# endif
