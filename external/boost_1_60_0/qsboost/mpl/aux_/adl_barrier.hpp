
#ifndef QSBOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED
#define QSBOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2002-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Id$
// $Date$
// $Revision$

#include <qsboost/mpl/aux_/config/adl.hpp>
#include <qsboost/mpl/aux_/config/gcc.hpp>
#include <qsboost/mpl/aux_/config/workaround.hpp>

#if !defined(QSBOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE)

#   define QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE qsmpl_
#   define QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace qsmpl_ {
#   define QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE }
#   define QSBOOST_MPL_AUX_ADL_BARRIER_DECL(type) \
    namespace qsboost { namespace mpl { \
    using ::QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::type; \
    } } \
/**/

#if !defined(QSBOOST_MPL_PREPROCESSING_MODE)
namespace QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE { namespace aux {} }
namespace qsboost { namespace mpl { using namespace QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE; 
namespace aux { using namespace QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE::aux; }
}}
#endif

#else // BOOST_MPL_CFG_NO_ADL_BARRIER_NAMESPACE

#   define QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE qsboost::mpl
#   define QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_OPEN namespace qsboost { namespace mpl {
#   define QSBOOST_MPL_AUX_ADL_BARRIER_NAMESPACE_CLOSE }}
#   define QSBOOST_MPL_AUX_ADL_BARRIER_DECL(type) /**/

#endif

#endif // BOOST_MPL_AUX_ADL_BARRIER_HPP_INCLUDED
