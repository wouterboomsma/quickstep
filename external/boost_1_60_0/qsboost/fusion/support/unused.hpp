/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(QSBOOST_FUSION_SUPPORT_UNUSED_20070305_1038)
#define QSBOOST_FUSION_SUPPORT_UNUSED_20070305_1038

#include <qsboost/fusion/support/config.hpp>
#include <iosfwd>

#include <qsboost/config.hpp>
#if defined(QSBOOST_MSVC)
# pragma warning(push)
# pragma warning(disable: 4522) // multiple assignment operators specified warning
#endif

#define QSBOOST_FUSION_UNUSED_HAS_IO

namespace qsboost { namespace fusion
{
    struct unused_type
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        unused_type() QSBOOST_NOEXCEPT
        {
        }

        template <typename T>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        unused_type(T const&) QSBOOST_NOEXCEPT
        {
        }

        template <typename T>
        QSBOOST_FUSION_CONSTEXPR_THIS QSBOOST_FUSION_GPU_ENABLED
        unused_type const&
        operator=(T const&) const QSBOOST_NOEXCEPT
        {
            return *this;
        }

        template <typename T>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        unused_type&
        operator=(T const&) QSBOOST_NOEXCEPT
        {
            return *this;
        }

        QSBOOST_FUSION_CONSTEXPR_THIS QSBOOST_FUSION_GPU_ENABLED
        unused_type const&
        operator=(unused_type const&) const QSBOOST_NOEXCEPT
        {
            return *this;
        }

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        unused_type&
        operator=(unused_type const&) QSBOOST_NOEXCEPT
        {
            return *this;
        }
    };

    QSBOOST_CONSTEXPR_OR_CONST unused_type unused = unused_type();

    namespace detail
    {
        struct unused_only
        {
            QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
            unused_only(unused_type const&) QSBOOST_NOEXCEPT {}
        };
    }

    QSBOOST_CONSTEXPR
    inline std::ostream& operator<<(std::ostream& out, detail::unused_only const&) QSBOOST_NOEXCEPT
    {
        return out;
    }

    QSBOOST_CONSTEXPR
    inline std::istream& operator>>(std::istream& in, unused_type&) QSBOOST_NOEXCEPT
    {
        return in;
    }
}}

#if defined(QSBOOST_MSVC)
# pragma warning(pop)
#endif

#endif
