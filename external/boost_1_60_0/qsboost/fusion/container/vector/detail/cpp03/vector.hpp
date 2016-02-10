/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_VECTOR_07072005_1244)
#define FUSION_VECTOR_07072005_1244

#include <qsboost/preprocessor/iterate.hpp>
#include <qsboost/preprocessor/repetition/enum_params.hpp>
#include <qsboost/preprocessor/repetition/enum_binary_params.hpp>
#include <qsboost/fusion/support/config.hpp>
#include <qsboost/fusion/support/is_sequence.hpp>
#include <qsboost/fusion/container/vector/vector_fwd.hpp>
#include <qsboost/fusion/container/vector/detail/cpp03/vector_n_chooser.hpp>
#include <qsboost/fusion/sequence/intrinsic/begin.hpp>
#include <qsboost/mpl/at.hpp>
#include <qsboost/mpl/bool.hpp>
#include <qsboost/type_traits/add_reference.hpp>
#include <qsboost/type_traits/add_const.hpp>
#include <qsboost/type_traits/is_base_of.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/core/enable_if.hpp>

#define FUSION_HASH #

#if QSBOOST_WORKAROUND(QSBOOST_MSVC, <= 1600)

#define QSBOOST_FUSION_VECTOR_COPY_INIT()                                       \
    ctor_helper(rhs, is_base_of<vector, Sequence>())                          \

#define QSBOOST_FUSION_VECTOR_CTOR_HELPER()                                     \
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED                                  \
    static vector_n const&                                                    \
    ctor_helper(vector const& rhs, mpl::true_)                                \
    {                                                                         \
        return rhs.vec;                                                       \
    }                                                                         \
                                                                              \
    template <typename T>                                                     \
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED                                  \
    static T const&                                                           \
    ctor_helper(T const& rhs, mpl::false_)                                    \
    {                                                                         \
        return rhs;                                                           \
    }

#else

#define QSBOOST_FUSION_VECTOR_COPY_INIT()                                       \
    rhs                                                                       \

#define QSBOOST_FUSION_VECTOR_CTOR_HELPER()

#endif

#if !defined(QSBOOST_FUSION_DONT_USE_PREPROCESSED_FILES)
#include <qsboost/fusion/container/vector/detail/cpp03/preprocessed/vector.hpp>
#else
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/vvector" FUSION_MAX_VECTOR_SIZE_STR ".hpp")
#endif

/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

    This is an auto-generated file. Do not edit!
==============================================================================*/

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace qsboost { namespace fusion
{
    struct void_;
    struct fusion_sequence_tag;

    template <QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, typename T)>
    struct vector
        : sequence_base<vector<QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, T)> >
    {
    private:

        typedef typename detail::vector_n_chooser<
            QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, T)>::type
        vector_n;

        template <QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, typename U)>
        friend struct vector;

    public:

        typedef typename vector_n::types types;
        typedef typename vector_n::fusion_tag fusion_tag;
        typedef typename vector_n::tag tag;
        typedef typename vector_n::size size;
        typedef typename vector_n::category category;
        typedef typename vector_n::is_view is_view;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector()
            : vec() {}

        template <QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, typename U)>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector(vector<QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, U)> const& rhs)
            : vec(rhs.vec) {}

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector(vector const& rhs)
            : vec(rhs.vec) {}

        template <typename Sequence>
        QSBOOST_FUSION_GPU_ENABLED
        vector(Sequence const& rhs,
            typename qsboost::enable_if<traits::is_sequence<Sequence> >::type* = 0)
            : vec(QSBOOST_FUSION_VECTOR_COPY_INIT()) {}

        //  Expand a couple of forwarding constructors for arguments
        //  of type (T0), (T0, T1), (T0, T1, T2) etc. Example:
        //
        //  vector(
        //      typename detail::call_param<T0>::type arg0
        //    , typename detail::call_param<T1>::type arg1)
        //    : vec(arg0, arg1) {}
        #include <qsboost/fusion/container/vector/detail/cpp03/vector_forward_ctor.hpp>

        template <QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, typename U)>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector<QSBOOST_PP_ENUM_PARAMS(FUSION_MAX_VECTOR_SIZE, U)> const& rhs)
        {
            vec = rhs.vec;
            return *this;
        }

        template <typename T>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector&
        operator=(T const& rhs)
        {
            vec = rhs;
            return *this;
        }

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector const& rhs)
        {
            vec = rhs.vec;
            return *this;
        }

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES)
#endif
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector(vector&& rhs)
            : vec(std::forward<vector_n>(rhs.vec)) {}

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector&
        operator=(vector&& rhs)
        {
            vec = std::forward<vector_n>(rhs.vec);
            return *this;
        }

        template <typename T>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        vector&
        operator=(T&& rhs)
        {
            vec = QSBOOST_FUSION_FWD_ELEM(T, rhs);
            return *this;
        }
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif

        template <int N>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename add_reference<
            typename mpl::at_c<types, N>::type
        >::type
        at_impl(mpl::int_<N> index)
        {
            return vec.at_impl(index);
        }

        template <int N>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename add_reference<
            typename add_const<
                typename mpl::at_c<types, N>::type
            >::type
        >::type
        at_impl(mpl::int_<N> index) const
        {
            return vec.at_impl(index);
        }

        template <typename I>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename add_reference<
            typename mpl::at<types, I>::type
        >::type
        at_impl(I /*index*/)
        {
            return vec.at_impl(mpl::int_<I::value>());
        }

        template<typename I>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename add_reference<
            typename add_const<
                typename mpl::at<types, I>::type
            >::type
        >::type
        at_impl(I /*index*/) const
        {
            return vec.at_impl(mpl::int_<I::value>());
        }

    private:

        QSBOOST_FUSION_VECTOR_CTOR_HELPER()
        vector_n vec;
    };
}}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif // BOOST_FUSION_DONT_USE_PREPROCESSED_FILES

#undef FUSION_HASH
#endif
