
#ifndef QSBOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED
#define QSBOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2008
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#if !defined(QSBOOST_MPL_CFG_COMPILER_DIR)

#   include <qsboost/mpl/aux_/config/dtp.hpp>
#   include <qsboost/mpl/aux_/config/ttp.hpp>
#   include <qsboost/mpl/aux_/config/ctps.hpp>
#   include <qsboost/mpl/aux_/config/msvc.hpp>
#   include <qsboost/mpl/aux_/config/gcc.hpp>
#   include <qsboost/mpl/aux_/config/workaround.hpp>

#   if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1300)
#       define QSBOOST_MPL_CFG_COMPILER_DIR msvc60

#   elif QSBOOST_WORKAROUND(QSBOOST_MSVC, == 1300)
#       define QSBOOST_MPL_CFG_COMPILER_DIR msvc70

#   elif QSBOOST_WORKAROUND(QSBOOST_MPL_CFG_GCC, QSBOOST_TESTED_AT(0x0304))
#       define QSBOOST_MPL_CFG_COMPILER_DIR gcc

#   elif QSBOOST_WORKAROUND(__BORLANDC__, QSBOOST_TESTED_AT(0x610))
#       if !defined(QSBOOST_MPL_CFG_NO_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#           define QSBOOST_MPL_CFG_COMPILER_DIR bcc551
#       elif QSBOOST_WORKAROUND(__BORLANDC__, >= 0x590)
#           define QSBOOST_MPL_CFG_COMPILER_DIR bcc
#       else
#           define QSBOOST_MPL_CFG_COMPILER_DIR bcc_pre590
#       endif

#   elif QSBOOST_WORKAROUND(__DMC__, QSBOOST_TESTED_AT(0x840))
#       define QSBOOST_MPL_CFG_COMPILER_DIR dmc

#   elif defined(__MWERKS__)
#       if defined(QSBOOST_MPL_CFG_BROKEN_DEFAULT_PARAMETERS_IN_NESTED_TEMPLATES)
#           define QSBOOST_MPL_CFG_COMPILER_DIR mwcw
#       else
#           define QSBOOST_MPL_CFG_COMPILER_DIR plain
#       endif

#   elif defined(QSBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
#       define QSBOOST_MPL_CFG_COMPILER_DIR no_ctps

#   elif defined(QSBOOST_MPL_CFG_NO_TEMPLATE_TEMPLATE_PARAMETERS)
#       define QSBOOST_MPL_CFG_COMPILER_DIR no_ttp

#   else
#       define QSBOOST_MPL_CFG_COMPILER_DIR plain
#   endif

#endif // BOOST_MPL_CFG_COMPILER_DIR

#endif // BOOST_MPL_AUX_CONFIG_COMPILER_HPP_INCLUDED
