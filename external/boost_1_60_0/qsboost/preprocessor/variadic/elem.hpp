# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef QSBOOST_PREPROCESSOR_VARIADIC_ELEM_HPP
# define QSBOOST_PREPROCESSOR_VARIADIC_ELEM_HPP
#
# include <qsboost/preprocessor/cat.hpp>
# include <qsboost/preprocessor/config/config.hpp>
#
# /* BOOST_PP_VARIADIC_ELEM */
#
# if QSBOOST_PP_VARIADICS
#    if QSBOOST_PP_VARIADICS_MSVC
#        define QSBOOST_PP_VARIADIC_ELEM(n, ...) QSBOOST_PP_VARIADIC_ELEM_I(n,__VA_ARGS__)
#        define QSBOOST_PP_VARIADIC_ELEM_I(n, ...) QSBOOST_PP_CAT(QSBOOST_PP_CAT(QSBOOST_PP_VARIADIC_ELEM_, n)(__VA_ARGS__,),)
#    else
#        define QSBOOST_PP_VARIADIC_ELEM(n, ...) QSBOOST_PP_CAT(QSBOOST_PP_VARIADIC_ELEM_, n)(__VA_ARGS__,)
#    endif
#    define QSBOOST_PP_VARIADIC_ELEM_0(e0, ...) e0
#    define QSBOOST_PP_VARIADIC_ELEM_1(e0, e1, ...) e1
#    define QSBOOST_PP_VARIADIC_ELEM_2(e0, e1, e2, ...) e2
#    define QSBOOST_PP_VARIADIC_ELEM_3(e0, e1, e2, e3, ...) e3
#    define QSBOOST_PP_VARIADIC_ELEM_4(e0, e1, e2, e3, e4, ...) e4
#    define QSBOOST_PP_VARIADIC_ELEM_5(e0, e1, e2, e3, e4, e5, ...) e5
#    define QSBOOST_PP_VARIADIC_ELEM_6(e0, e1, e2, e3, e4, e5, e6, ...) e6
#    define QSBOOST_PP_VARIADIC_ELEM_7(e0, e1, e2, e3, e4, e5, e6, e7, ...) e7
#    define QSBOOST_PP_VARIADIC_ELEM_8(e0, e1, e2, e3, e4, e5, e6, e7, e8, ...) e8
#    define QSBOOST_PP_VARIADIC_ELEM_9(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ...) e9
#    define QSBOOST_PP_VARIADIC_ELEM_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ...) e10
#    define QSBOOST_PP_VARIADIC_ELEM_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ...) e11
#    define QSBOOST_PP_VARIADIC_ELEM_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ...) e12
#    define QSBOOST_PP_VARIADIC_ELEM_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ...) e13
#    define QSBOOST_PP_VARIADIC_ELEM_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ...) e14
#    define QSBOOST_PP_VARIADIC_ELEM_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, ...) e15
#    define QSBOOST_PP_VARIADIC_ELEM_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, ...) e16
#    define QSBOOST_PP_VARIADIC_ELEM_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, ...) e17
#    define QSBOOST_PP_VARIADIC_ELEM_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, ...) e18
#    define QSBOOST_PP_VARIADIC_ELEM_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, ...) e19
#    define QSBOOST_PP_VARIADIC_ELEM_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, ...) e20
#    define QSBOOST_PP_VARIADIC_ELEM_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, ...) e21
#    define QSBOOST_PP_VARIADIC_ELEM_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, ...) e22
#    define QSBOOST_PP_VARIADIC_ELEM_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, ...) e23
#    define QSBOOST_PP_VARIADIC_ELEM_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, ...) e24
#    define QSBOOST_PP_VARIADIC_ELEM_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, ...) e25
#    define QSBOOST_PP_VARIADIC_ELEM_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ...) e26
#    define QSBOOST_PP_VARIADIC_ELEM_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ...) e27
#    define QSBOOST_PP_VARIADIC_ELEM_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ...) e28
#    define QSBOOST_PP_VARIADIC_ELEM_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, ...) e29
#    define QSBOOST_PP_VARIADIC_ELEM_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, ...) e30
#    define QSBOOST_PP_VARIADIC_ELEM_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, ...) e31
#    define QSBOOST_PP_VARIADIC_ELEM_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, ...) e32
#    define QSBOOST_PP_VARIADIC_ELEM_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, ...) e33
#    define QSBOOST_PP_VARIADIC_ELEM_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, ...) e34
#    define QSBOOST_PP_VARIADIC_ELEM_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, ...) e35
#    define QSBOOST_PP_VARIADIC_ELEM_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, ...) e36
#    define QSBOOST_PP_VARIADIC_ELEM_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, ...) e37
#    define QSBOOST_PP_VARIADIC_ELEM_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, ...) e38
#    define QSBOOST_PP_VARIADIC_ELEM_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, ...) e39
#    define QSBOOST_PP_VARIADIC_ELEM_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, ...) e40
#    define QSBOOST_PP_VARIADIC_ELEM_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ...) e41
#    define QSBOOST_PP_VARIADIC_ELEM_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ...) e42
#    define QSBOOST_PP_VARIADIC_ELEM_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, ...) e43
#    define QSBOOST_PP_VARIADIC_ELEM_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, ...) e44
#    define QSBOOST_PP_VARIADIC_ELEM_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, ...) e45
#    define QSBOOST_PP_VARIADIC_ELEM_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, ...) e46
#    define QSBOOST_PP_VARIADIC_ELEM_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, ...) e47
#    define QSBOOST_PP_VARIADIC_ELEM_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, ...) e48
#    define QSBOOST_PP_VARIADIC_ELEM_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, ...) e49
#    define QSBOOST_PP_VARIADIC_ELEM_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, ...) e50
#    define QSBOOST_PP_VARIADIC_ELEM_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, ...) e51
#    define QSBOOST_PP_VARIADIC_ELEM_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, ...) e52
#    define QSBOOST_PP_VARIADIC_ELEM_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, ...) e53
#    define QSBOOST_PP_VARIADIC_ELEM_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, ...) e54
#    define QSBOOST_PP_VARIADIC_ELEM_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, ...) e55
#    define QSBOOST_PP_VARIADIC_ELEM_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, ...) e56
#    define QSBOOST_PP_VARIADIC_ELEM_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, ...) e57
#    define QSBOOST_PP_VARIADIC_ELEM_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, ...) e58
#    define QSBOOST_PP_VARIADIC_ELEM_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, ...) e59
#    define QSBOOST_PP_VARIADIC_ELEM_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, ...) e60
#    define QSBOOST_PP_VARIADIC_ELEM_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, ...) e61
#    define QSBOOST_PP_VARIADIC_ELEM_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, ...) e62
#    define QSBOOST_PP_VARIADIC_ELEM_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63, ...) e63
# endif
#
# endif
