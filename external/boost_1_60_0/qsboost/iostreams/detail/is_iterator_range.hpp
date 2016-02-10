// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED       
 
#include <qsboost/config.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/iostreams/detail/bool_trait_def.hpp>

// Must come last.
#include <qsboost/iostreams/detail/config/disable_warnings.hpp>

namespace qsboost { 

# if !QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1300) //---------------------------------//

// We avoid dependence on Boost.Range by using a forward declaration.
template<typename Iterator>
class iterator_range;
    
namespace iostreams {

QSBOOST_IOSTREAMS_BOOL_TRAIT_DEF(is_iterator_range, qsboost::iterator_range, 1)

} // End namespace iostreams.

# else // # if !BOOST_WORKAROUND(BOOST_MSVC, <= 1300) //-----------------------//

namespace iostreams {    

    template<typename T>
    struct is_iterator_range {
        QSBOOST_STATIC_CONSTANT(bool, value = false);
    };

} // End namespace iostreams.

# endif // # if !BOOST_WORKAROUND(BOOST_MSVC, < 1300) //----------------------//

} // End namespace boost.

#include <qsboost/iostreams/detail/config/enable_warnings.hpp>

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_IS_ITERATOR_RANGE_HPP_INCLUDED
