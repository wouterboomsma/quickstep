# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# include <qsboost/preprocessor/config/config.hpp>
#
# if QSBOOST_PP_CONFIG_FLAGS() & QSBOOST_PP_CONFIG_DMC()
#     include <qsboost/preprocessor/detail/dmc/auto_rec.hpp>
# else
#
# ifndef QSBOOST_PREPROCESSOR_DETAIL_AUTO_REC_HPP
# define QSBOOST_PREPROCESSOR_DETAIL_AUTO_REC_HPP
#
# include <qsboost/preprocessor/control/iif.hpp>
#
# /* BOOST_PP_AUTO_REC */
#
# define QSBOOST_PP_AUTO_REC(pred, n) QSBOOST_PP_NODE_ENTRY_ ## n(pred)
#
# define QSBOOST_PP_NODE_ENTRY_256(p) QSBOOST_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define QSBOOST_PP_NODE_ENTRY_128(p) QSBOOST_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define QSBOOST_PP_NODE_ENTRY_64(p) QSBOOST_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define QSBOOST_PP_NODE_ENTRY_32(p) QSBOOST_PP_NODE_16(p)(p)(p)(p)(p)
# define QSBOOST_PP_NODE_ENTRY_16(p) QSBOOST_PP_NODE_8(p)(p)(p)(p)
# define QSBOOST_PP_NODE_ENTRY_8(p) QSBOOST_PP_NODE_4(p)(p)(p)
# define QSBOOST_PP_NODE_ENTRY_4(p) QSBOOST_PP_NODE_2(p)(p)
# define QSBOOST_PP_NODE_ENTRY_2(p) QSBOOST_PP_NODE_1(p)
#
# define QSBOOST_PP_NODE_128(p) QSBOOST_PP_IIF(p(128), QSBOOST_PP_NODE_64, QSBOOST_PP_NODE_192)
#    define QSBOOST_PP_NODE_64(p) QSBOOST_PP_IIF(p(64), QSBOOST_PP_NODE_32, QSBOOST_PP_NODE_96)
#        define QSBOOST_PP_NODE_32(p) QSBOOST_PP_IIF(p(32), QSBOOST_PP_NODE_16, QSBOOST_PP_NODE_48)
#            define QSBOOST_PP_NODE_16(p) QSBOOST_PP_IIF(p(16), QSBOOST_PP_NODE_8, QSBOOST_PP_NODE_24)
#                define QSBOOST_PP_NODE_8(p) QSBOOST_PP_IIF(p(8), QSBOOST_PP_NODE_4, QSBOOST_PP_NODE_12)
#                    define QSBOOST_PP_NODE_4(p) QSBOOST_PP_IIF(p(4), QSBOOST_PP_NODE_2, QSBOOST_PP_NODE_6)
#                        define QSBOOST_PP_NODE_2(p) QSBOOST_PP_IIF(p(2), QSBOOST_PP_NODE_1, QSBOOST_PP_NODE_3)
#                            define QSBOOST_PP_NODE_1(p) QSBOOST_PP_IIF(p(1), 1, 2)
#                            define QSBOOST_PP_NODE_3(p) QSBOOST_PP_IIF(p(3), 3, 4)
#                        define QSBOOST_PP_NODE_6(p) QSBOOST_PP_IIF(p(6), QSBOOST_PP_NODE_5, QSBOOST_PP_NODE_7)
#                            define QSBOOST_PP_NODE_5(p) QSBOOST_PP_IIF(p(5), 5, 6)
#                            define QSBOOST_PP_NODE_7(p) QSBOOST_PP_IIF(p(7), 7, 8)
#                    define QSBOOST_PP_NODE_12(p) QSBOOST_PP_IIF(p(12), QSBOOST_PP_NODE_10, QSBOOST_PP_NODE_14)
#                        define QSBOOST_PP_NODE_10(p) QSBOOST_PP_IIF(p(10), QSBOOST_PP_NODE_9, QSBOOST_PP_NODE_11)
#                            define QSBOOST_PP_NODE_9(p) QSBOOST_PP_IIF(p(9), 9, 10)
#                            define QSBOOST_PP_NODE_11(p) QSBOOST_PP_IIF(p(11), 11, 12)
#                        define QSBOOST_PP_NODE_14(p) QSBOOST_PP_IIF(p(14), QSBOOST_PP_NODE_13, QSBOOST_PP_NODE_15)
#                            define QSBOOST_PP_NODE_13(p) QSBOOST_PP_IIF(p(13), 13, 14)
#                            define QSBOOST_PP_NODE_15(p) QSBOOST_PP_IIF(p(15), 15, 16)
#                define QSBOOST_PP_NODE_24(p) QSBOOST_PP_IIF(p(24), QSBOOST_PP_NODE_20, QSBOOST_PP_NODE_28)
#                    define QSBOOST_PP_NODE_20(p) QSBOOST_PP_IIF(p(20), QSBOOST_PP_NODE_18, QSBOOST_PP_NODE_22)
#                        define QSBOOST_PP_NODE_18(p) QSBOOST_PP_IIF(p(18), QSBOOST_PP_NODE_17, QSBOOST_PP_NODE_19)
#                            define QSBOOST_PP_NODE_17(p) QSBOOST_PP_IIF(p(17), 17, 18)
#                            define QSBOOST_PP_NODE_19(p) QSBOOST_PP_IIF(p(19), 19, 20)
#                        define QSBOOST_PP_NODE_22(p) QSBOOST_PP_IIF(p(22), QSBOOST_PP_NODE_21, QSBOOST_PP_NODE_23)
#                            define QSBOOST_PP_NODE_21(p) QSBOOST_PP_IIF(p(21), 21, 22)
#                            define QSBOOST_PP_NODE_23(p) QSBOOST_PP_IIF(p(23), 23, 24)
#                    define QSBOOST_PP_NODE_28(p) QSBOOST_PP_IIF(p(28), QSBOOST_PP_NODE_26, QSBOOST_PP_NODE_30)
#                        define QSBOOST_PP_NODE_26(p) QSBOOST_PP_IIF(p(26), QSBOOST_PP_NODE_25, QSBOOST_PP_NODE_27)
#                            define QSBOOST_PP_NODE_25(p) QSBOOST_PP_IIF(p(25), 25, 26)
#                            define QSBOOST_PP_NODE_27(p) QSBOOST_PP_IIF(p(27), 27, 28)
#                        define QSBOOST_PP_NODE_30(p) QSBOOST_PP_IIF(p(30), QSBOOST_PP_NODE_29, QSBOOST_PP_NODE_31)
#                            define QSBOOST_PP_NODE_29(p) QSBOOST_PP_IIF(p(29), 29, 30)
#                            define QSBOOST_PP_NODE_31(p) QSBOOST_PP_IIF(p(31), 31, 32)
#            define QSBOOST_PP_NODE_48(p) QSBOOST_PP_IIF(p(48), QSBOOST_PP_NODE_40, QSBOOST_PP_NODE_56)
#                define QSBOOST_PP_NODE_40(p) QSBOOST_PP_IIF(p(40), QSBOOST_PP_NODE_36, QSBOOST_PP_NODE_44)
#                    define QSBOOST_PP_NODE_36(p) QSBOOST_PP_IIF(p(36), QSBOOST_PP_NODE_34, QSBOOST_PP_NODE_38)
#                        define QSBOOST_PP_NODE_34(p) QSBOOST_PP_IIF(p(34), QSBOOST_PP_NODE_33, QSBOOST_PP_NODE_35)
#                            define QSBOOST_PP_NODE_33(p) QSBOOST_PP_IIF(p(33), 33, 34)
#                            define QSBOOST_PP_NODE_35(p) QSBOOST_PP_IIF(p(35), 35, 36)
#                        define QSBOOST_PP_NODE_38(p) QSBOOST_PP_IIF(p(38), QSBOOST_PP_NODE_37, QSBOOST_PP_NODE_39)
#                            define QSBOOST_PP_NODE_37(p) QSBOOST_PP_IIF(p(37), 37, 38)
#                            define QSBOOST_PP_NODE_39(p) QSBOOST_PP_IIF(p(39), 39, 40)
#                    define QSBOOST_PP_NODE_44(p) QSBOOST_PP_IIF(p(44), QSBOOST_PP_NODE_42, QSBOOST_PP_NODE_46)
#                        define QSBOOST_PP_NODE_42(p) QSBOOST_PP_IIF(p(42), QSBOOST_PP_NODE_41, QSBOOST_PP_NODE_43)
#                            define QSBOOST_PP_NODE_41(p) QSBOOST_PP_IIF(p(41), 41, 42)
#                            define QSBOOST_PP_NODE_43(p) QSBOOST_PP_IIF(p(43), 43, 44)
#                        define QSBOOST_PP_NODE_46(p) QSBOOST_PP_IIF(p(46), QSBOOST_PP_NODE_45, QSBOOST_PP_NODE_47)
#                            define QSBOOST_PP_NODE_45(p) QSBOOST_PP_IIF(p(45), 45, 46)
#                            define QSBOOST_PP_NODE_47(p) QSBOOST_PP_IIF(p(47), 47, 48)
#                define QSBOOST_PP_NODE_56(p) QSBOOST_PP_IIF(p(56), QSBOOST_PP_NODE_52, QSBOOST_PP_NODE_60)
#                    define QSBOOST_PP_NODE_52(p) QSBOOST_PP_IIF(p(52), QSBOOST_PP_NODE_50, QSBOOST_PP_NODE_54)
#                        define QSBOOST_PP_NODE_50(p) QSBOOST_PP_IIF(p(50), QSBOOST_PP_NODE_49, QSBOOST_PP_NODE_51)
#                            define QSBOOST_PP_NODE_49(p) QSBOOST_PP_IIF(p(49), 49, 50)
#                            define QSBOOST_PP_NODE_51(p) QSBOOST_PP_IIF(p(51), 51, 52)
#                        define QSBOOST_PP_NODE_54(p) QSBOOST_PP_IIF(p(54), QSBOOST_PP_NODE_53, QSBOOST_PP_NODE_55)
#                            define QSBOOST_PP_NODE_53(p) QSBOOST_PP_IIF(p(53), 53, 54)
#                            define QSBOOST_PP_NODE_55(p) QSBOOST_PP_IIF(p(55), 55, 56)
#                    define QSBOOST_PP_NODE_60(p) QSBOOST_PP_IIF(p(60), QSBOOST_PP_NODE_58, QSBOOST_PP_NODE_62)
#                        define QSBOOST_PP_NODE_58(p) QSBOOST_PP_IIF(p(58), QSBOOST_PP_NODE_57, QSBOOST_PP_NODE_59)
#                            define QSBOOST_PP_NODE_57(p) QSBOOST_PP_IIF(p(57), 57, 58)
#                            define QSBOOST_PP_NODE_59(p) QSBOOST_PP_IIF(p(59), 59, 60)
#                        define QSBOOST_PP_NODE_62(p) QSBOOST_PP_IIF(p(62), QSBOOST_PP_NODE_61, QSBOOST_PP_NODE_63)
#                            define QSBOOST_PP_NODE_61(p) QSBOOST_PP_IIF(p(61), 61, 62)
#                            define QSBOOST_PP_NODE_63(p) QSBOOST_PP_IIF(p(63), 63, 64)
#        define QSBOOST_PP_NODE_96(p) QSBOOST_PP_IIF(p(96), QSBOOST_PP_NODE_80, QSBOOST_PP_NODE_112)
#            define QSBOOST_PP_NODE_80(p) QSBOOST_PP_IIF(p(80), QSBOOST_PP_NODE_72, QSBOOST_PP_NODE_88)
#                define QSBOOST_PP_NODE_72(p) QSBOOST_PP_IIF(p(72), QSBOOST_PP_NODE_68, QSBOOST_PP_NODE_76)
#                    define QSBOOST_PP_NODE_68(p) QSBOOST_PP_IIF(p(68), QSBOOST_PP_NODE_66, QSBOOST_PP_NODE_70)
#                        define QSBOOST_PP_NODE_66(p) QSBOOST_PP_IIF(p(66), QSBOOST_PP_NODE_65, QSBOOST_PP_NODE_67)
#                            define QSBOOST_PP_NODE_65(p) QSBOOST_PP_IIF(p(65), 65, 66)
#                            define QSBOOST_PP_NODE_67(p) QSBOOST_PP_IIF(p(67), 67, 68)
#                        define QSBOOST_PP_NODE_70(p) QSBOOST_PP_IIF(p(70), QSBOOST_PP_NODE_69, QSBOOST_PP_NODE_71)
#                            define QSBOOST_PP_NODE_69(p) QSBOOST_PP_IIF(p(69), 69, 70)
#                            define QSBOOST_PP_NODE_71(p) QSBOOST_PP_IIF(p(71), 71, 72)
#                    define QSBOOST_PP_NODE_76(p) QSBOOST_PP_IIF(p(76), QSBOOST_PP_NODE_74, QSBOOST_PP_NODE_78)
#                        define QSBOOST_PP_NODE_74(p) QSBOOST_PP_IIF(p(74), QSBOOST_PP_NODE_73, QSBOOST_PP_NODE_75)
#                            define QSBOOST_PP_NODE_73(p) QSBOOST_PP_IIF(p(73), 73, 74)
#                            define QSBOOST_PP_NODE_75(p) QSBOOST_PP_IIF(p(75), 75, 76)
#                        define QSBOOST_PP_NODE_78(p) QSBOOST_PP_IIF(p(78), QSBOOST_PP_NODE_77, QSBOOST_PP_NODE_79)
#                            define QSBOOST_PP_NODE_77(p) QSBOOST_PP_IIF(p(77), 77, 78)
#                            define QSBOOST_PP_NODE_79(p) QSBOOST_PP_IIF(p(79), 79, 80)
#                define QSBOOST_PP_NODE_88(p) QSBOOST_PP_IIF(p(88), QSBOOST_PP_NODE_84, QSBOOST_PP_NODE_92)
#                    define QSBOOST_PP_NODE_84(p) QSBOOST_PP_IIF(p(84), QSBOOST_PP_NODE_82, QSBOOST_PP_NODE_86)
#                        define QSBOOST_PP_NODE_82(p) QSBOOST_PP_IIF(p(82), QSBOOST_PP_NODE_81, QSBOOST_PP_NODE_83)
#                            define QSBOOST_PP_NODE_81(p) QSBOOST_PP_IIF(p(81), 81, 82)
#                            define QSBOOST_PP_NODE_83(p) QSBOOST_PP_IIF(p(83), 83, 84)
#                        define QSBOOST_PP_NODE_86(p) QSBOOST_PP_IIF(p(86), QSBOOST_PP_NODE_85, QSBOOST_PP_NODE_87)
#                            define QSBOOST_PP_NODE_85(p) QSBOOST_PP_IIF(p(85), 85, 86)
#                            define QSBOOST_PP_NODE_87(p) QSBOOST_PP_IIF(p(87), 87, 88)
#                    define QSBOOST_PP_NODE_92(p) QSBOOST_PP_IIF(p(92), QSBOOST_PP_NODE_90, QSBOOST_PP_NODE_94)
#                        define QSBOOST_PP_NODE_90(p) QSBOOST_PP_IIF(p(90), QSBOOST_PP_NODE_89, QSBOOST_PP_NODE_91)
#                            define QSBOOST_PP_NODE_89(p) QSBOOST_PP_IIF(p(89), 89, 90)
#                            define QSBOOST_PP_NODE_91(p) QSBOOST_PP_IIF(p(91), 91, 92)
#                        define QSBOOST_PP_NODE_94(p) QSBOOST_PP_IIF(p(94), QSBOOST_PP_NODE_93, QSBOOST_PP_NODE_95)
#                            define QSBOOST_PP_NODE_93(p) QSBOOST_PP_IIF(p(93), 93, 94)
#                            define QSBOOST_PP_NODE_95(p) QSBOOST_PP_IIF(p(95), 95, 96)
#            define QSBOOST_PP_NODE_112(p) QSBOOST_PP_IIF(p(112), QSBOOST_PP_NODE_104, QSBOOST_PP_NODE_120)
#                define QSBOOST_PP_NODE_104(p) QSBOOST_PP_IIF(p(104), QSBOOST_PP_NODE_100, QSBOOST_PP_NODE_108)
#                    define QSBOOST_PP_NODE_100(p) QSBOOST_PP_IIF(p(100), QSBOOST_PP_NODE_98, QSBOOST_PP_NODE_102)
#                        define QSBOOST_PP_NODE_98(p) QSBOOST_PP_IIF(p(98), QSBOOST_PP_NODE_97, QSBOOST_PP_NODE_99)
#                            define QSBOOST_PP_NODE_97(p) QSBOOST_PP_IIF(p(97), 97, 98)
#                            define QSBOOST_PP_NODE_99(p) QSBOOST_PP_IIF(p(99), 99, 100)
#                        define QSBOOST_PP_NODE_102(p) QSBOOST_PP_IIF(p(102), QSBOOST_PP_NODE_101, QSBOOST_PP_NODE_103)
#                            define QSBOOST_PP_NODE_101(p) QSBOOST_PP_IIF(p(101), 101, 102)
#                            define QSBOOST_PP_NODE_103(p) QSBOOST_PP_IIF(p(103), 103, 104)
#                    define QSBOOST_PP_NODE_108(p) QSBOOST_PP_IIF(p(108), QSBOOST_PP_NODE_106, QSBOOST_PP_NODE_110)
#                        define QSBOOST_PP_NODE_106(p) QSBOOST_PP_IIF(p(106), QSBOOST_PP_NODE_105, QSBOOST_PP_NODE_107)
#                            define QSBOOST_PP_NODE_105(p) QSBOOST_PP_IIF(p(105), 105, 106)
#                            define QSBOOST_PP_NODE_107(p) QSBOOST_PP_IIF(p(107), 107, 108)
#                        define QSBOOST_PP_NODE_110(p) QSBOOST_PP_IIF(p(110), QSBOOST_PP_NODE_109, QSBOOST_PP_NODE_111)
#                            define QSBOOST_PP_NODE_109(p) QSBOOST_PP_IIF(p(109), 109, 110)
#                            define QSBOOST_PP_NODE_111(p) QSBOOST_PP_IIF(p(111), 111, 112)
#                define QSBOOST_PP_NODE_120(p) QSBOOST_PP_IIF(p(120), QSBOOST_PP_NODE_116, QSBOOST_PP_NODE_124)
#                    define QSBOOST_PP_NODE_116(p) QSBOOST_PP_IIF(p(116), QSBOOST_PP_NODE_114, QSBOOST_PP_NODE_118)
#                        define QSBOOST_PP_NODE_114(p) QSBOOST_PP_IIF(p(114), QSBOOST_PP_NODE_113, QSBOOST_PP_NODE_115)
#                            define QSBOOST_PP_NODE_113(p) QSBOOST_PP_IIF(p(113), 113, 114)
#                            define QSBOOST_PP_NODE_115(p) QSBOOST_PP_IIF(p(115), 115, 116)
#                        define QSBOOST_PP_NODE_118(p) QSBOOST_PP_IIF(p(118), QSBOOST_PP_NODE_117, QSBOOST_PP_NODE_119)
#                            define QSBOOST_PP_NODE_117(p) QSBOOST_PP_IIF(p(117), 117, 118)
#                            define QSBOOST_PP_NODE_119(p) QSBOOST_PP_IIF(p(119), 119, 120)
#                    define QSBOOST_PP_NODE_124(p) QSBOOST_PP_IIF(p(124), QSBOOST_PP_NODE_122, QSBOOST_PP_NODE_126)
#                        define QSBOOST_PP_NODE_122(p) QSBOOST_PP_IIF(p(122), QSBOOST_PP_NODE_121, QSBOOST_PP_NODE_123)
#                            define QSBOOST_PP_NODE_121(p) QSBOOST_PP_IIF(p(121), 121, 122)
#                            define QSBOOST_PP_NODE_123(p) QSBOOST_PP_IIF(p(123), 123, 124)
#                        define QSBOOST_PP_NODE_126(p) QSBOOST_PP_IIF(p(126), QSBOOST_PP_NODE_125, QSBOOST_PP_NODE_127)
#                            define QSBOOST_PP_NODE_125(p) QSBOOST_PP_IIF(p(125), 125, 126)
#                            define QSBOOST_PP_NODE_127(p) QSBOOST_PP_IIF(p(127), 127, 128)
#    define QSBOOST_PP_NODE_192(p) QSBOOST_PP_IIF(p(192), QSBOOST_PP_NODE_160, QSBOOST_PP_NODE_224)
#        define QSBOOST_PP_NODE_160(p) QSBOOST_PP_IIF(p(160), QSBOOST_PP_NODE_144, QSBOOST_PP_NODE_176)
#            define QSBOOST_PP_NODE_144(p) QSBOOST_PP_IIF(p(144), QSBOOST_PP_NODE_136, QSBOOST_PP_NODE_152)
#                define QSBOOST_PP_NODE_136(p) QSBOOST_PP_IIF(p(136), QSBOOST_PP_NODE_132, QSBOOST_PP_NODE_140)
#                    define QSBOOST_PP_NODE_132(p) QSBOOST_PP_IIF(p(132), QSBOOST_PP_NODE_130, QSBOOST_PP_NODE_134)
#                        define QSBOOST_PP_NODE_130(p) QSBOOST_PP_IIF(p(130), QSBOOST_PP_NODE_129, QSBOOST_PP_NODE_131)
#                            define QSBOOST_PP_NODE_129(p) QSBOOST_PP_IIF(p(129), 129, 130)
#                            define QSBOOST_PP_NODE_131(p) QSBOOST_PP_IIF(p(131), 131, 132)
#                        define QSBOOST_PP_NODE_134(p) QSBOOST_PP_IIF(p(134), QSBOOST_PP_NODE_133, QSBOOST_PP_NODE_135)
#                            define QSBOOST_PP_NODE_133(p) QSBOOST_PP_IIF(p(133), 133, 134)
#                            define QSBOOST_PP_NODE_135(p) QSBOOST_PP_IIF(p(135), 135, 136)
#                    define QSBOOST_PP_NODE_140(p) QSBOOST_PP_IIF(p(140), QSBOOST_PP_NODE_138, QSBOOST_PP_NODE_142)
#                        define QSBOOST_PP_NODE_138(p) QSBOOST_PP_IIF(p(138), QSBOOST_PP_NODE_137, QSBOOST_PP_NODE_139)
#                            define QSBOOST_PP_NODE_137(p) QSBOOST_PP_IIF(p(137), 137, 138)
#                            define QSBOOST_PP_NODE_139(p) QSBOOST_PP_IIF(p(139), 139, 140)
#                        define QSBOOST_PP_NODE_142(p) QSBOOST_PP_IIF(p(142), QSBOOST_PP_NODE_141, QSBOOST_PP_NODE_143)
#                            define QSBOOST_PP_NODE_141(p) QSBOOST_PP_IIF(p(141), 141, 142)
#                            define QSBOOST_PP_NODE_143(p) QSBOOST_PP_IIF(p(143), 143, 144)
#                define QSBOOST_PP_NODE_152(p) QSBOOST_PP_IIF(p(152), QSBOOST_PP_NODE_148, QSBOOST_PP_NODE_156)
#                    define QSBOOST_PP_NODE_148(p) QSBOOST_PP_IIF(p(148), QSBOOST_PP_NODE_146, QSBOOST_PP_NODE_150)
#                        define QSBOOST_PP_NODE_146(p) QSBOOST_PP_IIF(p(146), QSBOOST_PP_NODE_145, QSBOOST_PP_NODE_147)
#                            define QSBOOST_PP_NODE_145(p) QSBOOST_PP_IIF(p(145), 145, 146)
#                            define QSBOOST_PP_NODE_147(p) QSBOOST_PP_IIF(p(147), 147, 148)
#                        define QSBOOST_PP_NODE_150(p) QSBOOST_PP_IIF(p(150), QSBOOST_PP_NODE_149, QSBOOST_PP_NODE_151)
#                            define QSBOOST_PP_NODE_149(p) QSBOOST_PP_IIF(p(149), 149, 150)
#                            define QSBOOST_PP_NODE_151(p) QSBOOST_PP_IIF(p(151), 151, 152)
#                    define QSBOOST_PP_NODE_156(p) QSBOOST_PP_IIF(p(156), QSBOOST_PP_NODE_154, QSBOOST_PP_NODE_158)
#                        define QSBOOST_PP_NODE_154(p) QSBOOST_PP_IIF(p(154), QSBOOST_PP_NODE_153, QSBOOST_PP_NODE_155)
#                            define QSBOOST_PP_NODE_153(p) QSBOOST_PP_IIF(p(153), 153, 154)
#                            define QSBOOST_PP_NODE_155(p) QSBOOST_PP_IIF(p(155), 155, 156)
#                        define QSBOOST_PP_NODE_158(p) QSBOOST_PP_IIF(p(158), QSBOOST_PP_NODE_157, QSBOOST_PP_NODE_159)
#                            define QSBOOST_PP_NODE_157(p) QSBOOST_PP_IIF(p(157), 157, 158)
#                            define QSBOOST_PP_NODE_159(p) QSBOOST_PP_IIF(p(159), 159, 160)
#            define QSBOOST_PP_NODE_176(p) QSBOOST_PP_IIF(p(176), QSBOOST_PP_NODE_168, QSBOOST_PP_NODE_184)
#                define QSBOOST_PP_NODE_168(p) QSBOOST_PP_IIF(p(168), QSBOOST_PP_NODE_164, QSBOOST_PP_NODE_172)
#                    define QSBOOST_PP_NODE_164(p) QSBOOST_PP_IIF(p(164), QSBOOST_PP_NODE_162, QSBOOST_PP_NODE_166)
#                        define QSBOOST_PP_NODE_162(p) QSBOOST_PP_IIF(p(162), QSBOOST_PP_NODE_161, QSBOOST_PP_NODE_163)
#                            define QSBOOST_PP_NODE_161(p) QSBOOST_PP_IIF(p(161), 161, 162)
#                            define QSBOOST_PP_NODE_163(p) QSBOOST_PP_IIF(p(163), 163, 164)
#                        define QSBOOST_PP_NODE_166(p) QSBOOST_PP_IIF(p(166), QSBOOST_PP_NODE_165, QSBOOST_PP_NODE_167)
#                            define QSBOOST_PP_NODE_165(p) QSBOOST_PP_IIF(p(165), 165, 166)
#                            define QSBOOST_PP_NODE_167(p) QSBOOST_PP_IIF(p(167), 167, 168)
#                    define QSBOOST_PP_NODE_172(p) QSBOOST_PP_IIF(p(172), QSBOOST_PP_NODE_170, QSBOOST_PP_NODE_174)
#                        define QSBOOST_PP_NODE_170(p) QSBOOST_PP_IIF(p(170), QSBOOST_PP_NODE_169, QSBOOST_PP_NODE_171)
#                            define QSBOOST_PP_NODE_169(p) QSBOOST_PP_IIF(p(169), 169, 170)
#                            define QSBOOST_PP_NODE_171(p) QSBOOST_PP_IIF(p(171), 171, 172)
#                        define QSBOOST_PP_NODE_174(p) QSBOOST_PP_IIF(p(174), QSBOOST_PP_NODE_173, QSBOOST_PP_NODE_175)
#                            define QSBOOST_PP_NODE_173(p) QSBOOST_PP_IIF(p(173), 173, 174)
#                            define QSBOOST_PP_NODE_175(p) QSBOOST_PP_IIF(p(175), 175, 176)
#                define QSBOOST_PP_NODE_184(p) QSBOOST_PP_IIF(p(184), QSBOOST_PP_NODE_180, QSBOOST_PP_NODE_188)
#                    define QSBOOST_PP_NODE_180(p) QSBOOST_PP_IIF(p(180), QSBOOST_PP_NODE_178, QSBOOST_PP_NODE_182)
#                        define QSBOOST_PP_NODE_178(p) QSBOOST_PP_IIF(p(178), QSBOOST_PP_NODE_177, QSBOOST_PP_NODE_179)
#                            define QSBOOST_PP_NODE_177(p) QSBOOST_PP_IIF(p(177), 177, 178)
#                            define QSBOOST_PP_NODE_179(p) QSBOOST_PP_IIF(p(179), 179, 180)
#                        define QSBOOST_PP_NODE_182(p) QSBOOST_PP_IIF(p(182), QSBOOST_PP_NODE_181, QSBOOST_PP_NODE_183)
#                            define QSBOOST_PP_NODE_181(p) QSBOOST_PP_IIF(p(181), 181, 182)
#                            define QSBOOST_PP_NODE_183(p) QSBOOST_PP_IIF(p(183), 183, 184)
#                    define QSBOOST_PP_NODE_188(p) QSBOOST_PP_IIF(p(188), QSBOOST_PP_NODE_186, QSBOOST_PP_NODE_190)
#                        define QSBOOST_PP_NODE_186(p) QSBOOST_PP_IIF(p(186), QSBOOST_PP_NODE_185, QSBOOST_PP_NODE_187)
#                            define QSBOOST_PP_NODE_185(p) QSBOOST_PP_IIF(p(185), 185, 186)
#                            define QSBOOST_PP_NODE_187(p) QSBOOST_PP_IIF(p(187), 187, 188)
#                        define QSBOOST_PP_NODE_190(p) QSBOOST_PP_IIF(p(190), QSBOOST_PP_NODE_189, QSBOOST_PP_NODE_191)
#                            define QSBOOST_PP_NODE_189(p) QSBOOST_PP_IIF(p(189), 189, 190)
#                            define QSBOOST_PP_NODE_191(p) QSBOOST_PP_IIF(p(191), 191, 192)
#        define QSBOOST_PP_NODE_224(p) QSBOOST_PP_IIF(p(224), QSBOOST_PP_NODE_208, QSBOOST_PP_NODE_240)
#            define QSBOOST_PP_NODE_208(p) QSBOOST_PP_IIF(p(208), QSBOOST_PP_NODE_200, QSBOOST_PP_NODE_216)
#                define QSBOOST_PP_NODE_200(p) QSBOOST_PP_IIF(p(200), QSBOOST_PP_NODE_196, QSBOOST_PP_NODE_204)
#                    define QSBOOST_PP_NODE_196(p) QSBOOST_PP_IIF(p(196), QSBOOST_PP_NODE_194, QSBOOST_PP_NODE_198)
#                        define QSBOOST_PP_NODE_194(p) QSBOOST_PP_IIF(p(194), QSBOOST_PP_NODE_193, QSBOOST_PP_NODE_195)
#                            define QSBOOST_PP_NODE_193(p) QSBOOST_PP_IIF(p(193), 193, 194)
#                            define QSBOOST_PP_NODE_195(p) QSBOOST_PP_IIF(p(195), 195, 196)
#                        define QSBOOST_PP_NODE_198(p) QSBOOST_PP_IIF(p(198), QSBOOST_PP_NODE_197, QSBOOST_PP_NODE_199)
#                            define QSBOOST_PP_NODE_197(p) QSBOOST_PP_IIF(p(197), 197, 198)
#                            define QSBOOST_PP_NODE_199(p) QSBOOST_PP_IIF(p(199), 199, 200)
#                    define QSBOOST_PP_NODE_204(p) QSBOOST_PP_IIF(p(204), QSBOOST_PP_NODE_202, QSBOOST_PP_NODE_206)
#                        define QSBOOST_PP_NODE_202(p) QSBOOST_PP_IIF(p(202), QSBOOST_PP_NODE_201, QSBOOST_PP_NODE_203)
#                            define QSBOOST_PP_NODE_201(p) QSBOOST_PP_IIF(p(201), 201, 202)
#                            define QSBOOST_PP_NODE_203(p) QSBOOST_PP_IIF(p(203), 203, 204)
#                        define QSBOOST_PP_NODE_206(p) QSBOOST_PP_IIF(p(206), QSBOOST_PP_NODE_205, QSBOOST_PP_NODE_207)
#                            define QSBOOST_PP_NODE_205(p) QSBOOST_PP_IIF(p(205), 205, 206)
#                            define QSBOOST_PP_NODE_207(p) QSBOOST_PP_IIF(p(207), 207, 208)
#                define QSBOOST_PP_NODE_216(p) QSBOOST_PP_IIF(p(216), QSBOOST_PP_NODE_212, QSBOOST_PP_NODE_220)
#                    define QSBOOST_PP_NODE_212(p) QSBOOST_PP_IIF(p(212), QSBOOST_PP_NODE_210, QSBOOST_PP_NODE_214)
#                        define QSBOOST_PP_NODE_210(p) QSBOOST_PP_IIF(p(210), QSBOOST_PP_NODE_209, QSBOOST_PP_NODE_211)
#                            define QSBOOST_PP_NODE_209(p) QSBOOST_PP_IIF(p(209), 209, 210)
#                            define QSBOOST_PP_NODE_211(p) QSBOOST_PP_IIF(p(211), 211, 212)
#                        define QSBOOST_PP_NODE_214(p) QSBOOST_PP_IIF(p(214), QSBOOST_PP_NODE_213, QSBOOST_PP_NODE_215)
#                            define QSBOOST_PP_NODE_213(p) QSBOOST_PP_IIF(p(213), 213, 214)
#                            define QSBOOST_PP_NODE_215(p) QSBOOST_PP_IIF(p(215), 215, 216)
#                    define QSBOOST_PP_NODE_220(p) QSBOOST_PP_IIF(p(220), QSBOOST_PP_NODE_218, QSBOOST_PP_NODE_222)
#                        define QSBOOST_PP_NODE_218(p) QSBOOST_PP_IIF(p(218), QSBOOST_PP_NODE_217, QSBOOST_PP_NODE_219)
#                            define QSBOOST_PP_NODE_217(p) QSBOOST_PP_IIF(p(217), 217, 218)
#                            define QSBOOST_PP_NODE_219(p) QSBOOST_PP_IIF(p(219), 219, 220)
#                        define QSBOOST_PP_NODE_222(p) QSBOOST_PP_IIF(p(222), QSBOOST_PP_NODE_221, QSBOOST_PP_NODE_223)
#                            define QSBOOST_PP_NODE_221(p) QSBOOST_PP_IIF(p(221), 221, 222)
#                            define QSBOOST_PP_NODE_223(p) QSBOOST_PP_IIF(p(223), 223, 224)
#            define QSBOOST_PP_NODE_240(p) QSBOOST_PP_IIF(p(240), QSBOOST_PP_NODE_232, QSBOOST_PP_NODE_248)
#                define QSBOOST_PP_NODE_232(p) QSBOOST_PP_IIF(p(232), QSBOOST_PP_NODE_228, QSBOOST_PP_NODE_236)
#                    define QSBOOST_PP_NODE_228(p) QSBOOST_PP_IIF(p(228), QSBOOST_PP_NODE_226, QSBOOST_PP_NODE_230)
#                        define QSBOOST_PP_NODE_226(p) QSBOOST_PP_IIF(p(226), QSBOOST_PP_NODE_225, QSBOOST_PP_NODE_227)
#                            define QSBOOST_PP_NODE_225(p) QSBOOST_PP_IIF(p(225), 225, 226)
#                            define QSBOOST_PP_NODE_227(p) QSBOOST_PP_IIF(p(227), 227, 228)
#                        define QSBOOST_PP_NODE_230(p) QSBOOST_PP_IIF(p(230), QSBOOST_PP_NODE_229, QSBOOST_PP_NODE_231)
#                            define QSBOOST_PP_NODE_229(p) QSBOOST_PP_IIF(p(229), 229, 230)
#                            define QSBOOST_PP_NODE_231(p) QSBOOST_PP_IIF(p(231), 231, 232)
#                    define QSBOOST_PP_NODE_236(p) QSBOOST_PP_IIF(p(236), QSBOOST_PP_NODE_234, QSBOOST_PP_NODE_238)
#                        define QSBOOST_PP_NODE_234(p) QSBOOST_PP_IIF(p(234), QSBOOST_PP_NODE_233, QSBOOST_PP_NODE_235)
#                            define QSBOOST_PP_NODE_233(p) QSBOOST_PP_IIF(p(233), 233, 234)
#                            define QSBOOST_PP_NODE_235(p) QSBOOST_PP_IIF(p(235), 235, 236)
#                        define QSBOOST_PP_NODE_238(p) QSBOOST_PP_IIF(p(238), QSBOOST_PP_NODE_237, QSBOOST_PP_NODE_239)
#                            define QSBOOST_PP_NODE_237(p) QSBOOST_PP_IIF(p(237), 237, 238)
#                            define QSBOOST_PP_NODE_239(p) QSBOOST_PP_IIF(p(239), 239, 240)
#                define QSBOOST_PP_NODE_248(p) QSBOOST_PP_IIF(p(248), QSBOOST_PP_NODE_244, QSBOOST_PP_NODE_252)
#                    define QSBOOST_PP_NODE_244(p) QSBOOST_PP_IIF(p(244), QSBOOST_PP_NODE_242, QSBOOST_PP_NODE_246)
#                        define QSBOOST_PP_NODE_242(p) QSBOOST_PP_IIF(p(242), QSBOOST_PP_NODE_241, QSBOOST_PP_NODE_243)
#                            define QSBOOST_PP_NODE_241(p) QSBOOST_PP_IIF(p(241), 241, 242)
#                            define QSBOOST_PP_NODE_243(p) QSBOOST_PP_IIF(p(243), 243, 244)
#                        define QSBOOST_PP_NODE_246(p) QSBOOST_PP_IIF(p(246), QSBOOST_PP_NODE_245, QSBOOST_PP_NODE_247)
#                            define QSBOOST_PP_NODE_245(p) QSBOOST_PP_IIF(p(245), 245, 246)
#                            define QSBOOST_PP_NODE_247(p) QSBOOST_PP_IIF(p(247), 247, 248)
#                    define QSBOOST_PP_NODE_252(p) QSBOOST_PP_IIF(p(252), QSBOOST_PP_NODE_250, QSBOOST_PP_NODE_254)
#                        define QSBOOST_PP_NODE_250(p) QSBOOST_PP_IIF(p(250), QSBOOST_PP_NODE_249, QSBOOST_PP_NODE_251)
#                            define QSBOOST_PP_NODE_249(p) QSBOOST_PP_IIF(p(249), 249, 250)
#                            define QSBOOST_PP_NODE_251(p) QSBOOST_PP_IIF(p(251), 251, 252)
#                        define QSBOOST_PP_NODE_254(p) QSBOOST_PP_IIF(p(254), QSBOOST_PP_NODE_253, QSBOOST_PP_NODE_255)
#                            define QSBOOST_PP_NODE_253(p) QSBOOST_PP_IIF(p(253), 253, 254)
#                            define QSBOOST_PP_NODE_255(p) QSBOOST_PP_IIF(p(255), 255, 256)
#
# endif
# endif
