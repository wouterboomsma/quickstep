/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
// No include guard. This file is meant to be included many times

#if !defined(FUSION_MACRO_05042005)
#define FUSION_MACRO_05042005

#define FUSION_VECTOR_CTOR_DEFAULT_INIT(z, n, _)                                \
    m##n()

#define FUSION_VECTOR_CTOR_INIT(z, n, _)                                        \
    m##n(_##n)

#define FUSION_VECTOR_MEMBER_CTOR_INIT(z, n, _)                                 \
    m##n(other.m##n)

#define FUSION_VECTOR_CTOR_FORWARD(z, n, _)                                     \
   m##n(QSBOOST_FUSION_FWD_ELEM(T##n, other.m##n))

#define FUSION_VECTOR_CTOR_ARG_FWD(z, n, _)                                     \
   m##n(QSBOOST_FUSION_FWD_ELEM(U##n, _##n))

#define FUSION_VECTOR_MEMBER_DECL(z, n, _)                                      \
    T##n m##n;

#define FUSION_VECTOR_MEMBER_FORWARD(z, n, _)                                   \
   QSBOOST_FUSION_FWD_ELEM(U##n, _##n)

#define FUSION_VECTOR_MEMBER_ASSIGN(z, n, _)                                    \
    this->QSBOOST_PP_CAT(m, n) = vec.QSBOOST_PP_CAT(m, n);

#define FUSION_VECTOR_MEMBER_DEREF_ASSIGN(z, n, _)                              \
    this->QSBOOST_PP_CAT(m, n) = *QSBOOST_PP_CAT(i, n);

#define FUSION_VECTOR_MEMBER_MOVE(z, n, _)                                      \
    this->QSBOOST_PP_CAT(m, n) = std::forward<                                    \
        QSBOOST_PP_CAT(T, n)>(vec.QSBOOST_PP_CAT(m, n));

#define FUSION_VECTOR_MEMBER_AT_IMPL(z, n, _)                                   \
    QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED                              \
        typename add_reference<T##n>::type                                      \
        at_impl(mpl::int_<n>) { return this->m##n; }                            \
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED                                    \
        typename add_reference<typename add_const<T##n>::type>::type            \
        at_impl(mpl::int_<n>) const { return this->m##n; }

#define FUSION_VECTOR_MEMBER_ITER_DECL_VAR(z, n, _)                             \
    typedef typename result_of::next<                                           \
        QSBOOST_PP_CAT(I, QSBOOST_PP_DEC(n))>::type QSBOOST_PP_CAT(I, n);             \
    QSBOOST_PP_CAT(I, n) QSBOOST_PP_CAT(i, n)                                       \
        = fusion::next(QSBOOST_PP_CAT(i, QSBOOST_PP_DEC(n)));

#endif

#define N QSBOOST_PP_ITERATION()

    template <QSBOOST_PP_ENUM_PARAMS(N, typename T)>
    struct QSBOOST_PP_CAT(vector_data, N)
    {
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector_data, N)()
            : QSBOOST_PP_ENUM(N, FUSION_VECTOR_CTOR_DEFAULT_INIT, _) {}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES)
#endif
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
        template <QSBOOST_PP_ENUM_PARAMS(N, typename U)>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector_data, N)(QSBOOST_PP_ENUM_BINARY_PARAMS(N, U, && arg)
          , typename qsboost::enable_if<is_convertible<U0, T0> >::type* /*dummy*/ = 0
        )
            : QSBOOST_PP_ENUM(N, FUSION_VECTOR_CTOR_ARG_FWD, arg) {}

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector_data, N)(
            QSBOOST_PP_CAT(vector_data, N)&& other)
            : QSBOOST_PP_ENUM(N, FUSION_VECTOR_CTOR_FORWARD, arg) {}
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
    QSBOOST_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
    QSBOOST_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector_data, N)(
            QSBOOST_PP_ENUM_BINARY_PARAMS(
                N, typename detail::call_param<T, >::type arg))
            : QSBOOST_PP_ENUM(N, FUSION_VECTOR_CTOR_INIT, arg) {}

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector_data, N)(
            QSBOOST_PP_CAT(vector_data, N) const& other)
            : QSBOOST_PP_ENUM(N, FUSION_VECTOR_MEMBER_CTOR_INIT, _) {}

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector_data, N)&
        operator=(QSBOOST_PP_CAT(vector_data, N) const& vec)
        {
            QSBOOST_PP_REPEAT(N, FUSION_VECTOR_MEMBER_ASSIGN, _)
            return *this;
        }

        template <typename Sequence>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
    QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
    QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        static QSBOOST_PP_CAT(vector_data, N)
        init_from_sequence(Sequence const& seq)
        {
            typedef typename result_of::begin<Sequence const>::type I0;
            I0 i0 = fusion::begin(seq);
            QSBOOST_PP_REPEAT_FROM_TO(1, N, FUSION_VECTOR_MEMBER_ITER_DECL_VAR, _)
            return QSBOOST_PP_CAT(vector_data, N)(QSBOOST_PP_ENUM_PARAMS(N, *i));
        }

        template <typename Sequence>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
    QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
    QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        static QSBOOST_PP_CAT(vector_data, N)
        init_from_sequence(Sequence& seq)
        {
            typedef typename result_of::begin<Sequence>::type I0;
            I0 i0 = fusion::begin(seq);
            QSBOOST_PP_REPEAT_FROM_TO(1, N, FUSION_VECTOR_MEMBER_ITER_DECL_VAR, _)
            return QSBOOST_PP_CAT(vector_data, N)(QSBOOST_PP_ENUM_PARAMS(N, *i));
        }

        QSBOOST_PP_REPEAT(N, FUSION_VECTOR_MEMBER_DECL, _)
    };

    template <QSBOOST_PP_ENUM_PARAMS(N, typename T)>
    struct QSBOOST_PP_CAT(vector, N)
      : QSBOOST_PP_CAT(vector_data, N)<QSBOOST_PP_ENUM_PARAMS(N, T)>
      , sequence_base<QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, T)> >
    {
        typedef QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, T)> this_type;
        typedef QSBOOST_PP_CAT(vector_data, N)<QSBOOST_PP_ENUM_PARAMS(N, T)> base_type;
        typedef mpl::QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, T)> types;
        typedef vector_tag fusion_tag;
        typedef fusion_sequence_tag tag; // this gets picked up by MPL
        typedef mpl::false_ is_view;
        typedef random_access_traversal_tag category;
        typedef mpl::int_<N> size;

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)() {}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
    QSBOOST_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
    QSBOOST_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
#if (N == 1)
        explicit
#endif
        QSBOOST_PP_CAT(vector, N)(
            QSBOOST_PP_ENUM_BINARY_PARAMS(
                N, typename detail::call_param<T, >::type arg))
            : base_type(QSBOOST_PP_ENUM_PARAMS(N, arg)) {}

#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES)
#endif
#if !defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
        template <QSBOOST_PP_ENUM_PARAMS(N, typename U)>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
#if (N == 1)
        explicit
        QSBOOST_PP_CAT(vector, N)(U0&& _0
          , typename qsboost::enable_if<is_convertible<U0, T0> >::type* /*dummy*/ = 0
          )
         : base_type(QSBOOST_FUSION_FWD_ELEM(U0, _0)) {}
#else
        QSBOOST_PP_CAT(vector, N)(QSBOOST_PP_ENUM_BINARY_PARAMS(N, U, && arg))
            : base_type(QSBOOST_PP_ENUM(N, FUSION_VECTOR_MEMBER_FORWARD, arg)) {}
#endif

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)(QSBOOST_PP_CAT(vector, N)&& rhs)
            : base_type(std::forward<base_type>(rhs)) {}

        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)(QSBOOST_PP_CAT(vector, N) const& rhs)
            : base_type(static_cast<base_type const&>(rhs)) {}

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)&
        operator=(QSBOOST_PP_CAT(vector, N) const& vec)
        {
            base_type::operator=(vec);
            return *this;
        }

        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)&
        operator=(QSBOOST_PP_CAT(vector, N)&& vec)
        {
            QSBOOST_PP_REPEAT(N, FUSION_VECTOR_MEMBER_MOVE, _)
            return *this;
        }
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif

        template <QSBOOST_PP_ENUM_PARAMS(N, typename U)>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
    QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
    QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)(
            QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, U)> const& vec)
            : base_type(QSBOOST_PP_ENUM_PARAMS(N, vec.m)) {}

        template <typename Sequence>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)(
            Sequence const& seq
          , typename qsboost::enable_if<traits::is_sequence<Sequence> >::type* = 0
#if (N == 1)
          , typename qsboost::disable_if<is_convertible<Sequence, T0> >::type* /*dummy*/ = 0
#endif
            )
            : base_type(base_type::init_from_sequence(seq)) {}

        template <typename Sequence>
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
FUSION_HASH endif
#else
#if !defined(QSBOOST_CLANG)
        QSBOOST_CXX14_CONSTEXPR
#endif
#endif
        QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)(
            Sequence& seq
          , typename qsboost::enable_if<traits::is_sequence<Sequence> >::type* = 0
#if (N == 1)
          , typename qsboost::disable_if<is_convertible<Sequence, T0> >::type* /*dummy*/ = 0
#endif
            )
            : base_type(base_type::init_from_sequence(seq)) {}

        template <QSBOOST_PP_ENUM_PARAMS(N, typename U)>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        QSBOOST_PP_CAT(vector, N)&
        operator=(QSBOOST_PP_CAT(vector, N)<QSBOOST_PP_ENUM_PARAMS(N, U)> const& vec)
        {
            QSBOOST_PP_REPEAT(N, FUSION_VECTOR_MEMBER_ASSIGN, _)
            return *this;
        }

        template <typename Sequence>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename qsboost::disable_if<is_convertible<Sequence, T0>, this_type&>::type
        operator=(Sequence const& seq)
        {
            typedef typename result_of::begin<Sequence const>::type I0;
            I0 i0 = fusion::begin(seq);
            QSBOOST_PP_REPEAT_FROM_TO(1, N, FUSION_VECTOR_MEMBER_ITER_DECL_VAR, _)
            QSBOOST_PP_REPEAT(N, FUSION_VECTOR_MEMBER_DEREF_ASSIGN, _)
            return *this;
        }

        QSBOOST_PP_REPEAT(N, FUSION_VECTOR_MEMBER_AT_IMPL, _)

        template<typename I>
        QSBOOST_CXX14_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename add_reference<typename mpl::at<types, I>::type>::type
        at_impl(I)
        {
            return this->at_impl(mpl::int_<I::value>());
        }

        template<typename I>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        typename add_reference<typename add_const<typename mpl::at<types, I>::type>::type>::type
        at_impl(I) const
        {
            return this->at_impl(mpl::int_<I::value>());
        }
    };

#undef N
