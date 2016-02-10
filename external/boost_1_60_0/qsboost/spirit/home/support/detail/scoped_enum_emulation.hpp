//  Copyright (c) 2001-2011 Hartmut Kaiser
//  http://spirit.sourceforge.net/
// 
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef QSBOOST_SPIRIT_SCOPED_ENUM_EMULATION_HPP
#define QSBOOST_SPIRIT_SCOPED_ENUM_EMULATION_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/version.hpp>
#include <qsboost/config.hpp>

#if QSBOOST_VERSION >= 104000
# include <qsboost/detail/scoped_enum_emulation.hpp>
#else
# if !defined(QSBOOST_NO_CXX11_SCOPED_ENUMS)
#  define QSBOOST_NO_CXX11_SCOPED_ENUMS
# endif 
# define QSBOOST_SCOPED_ENUM_START(name) struct name { enum enum_type
# define QSBOOST_SCOPED_ENUM_END };
# define QSBOOST_SCOPED_ENUM(name) name::enum_type
#endif

#endif
