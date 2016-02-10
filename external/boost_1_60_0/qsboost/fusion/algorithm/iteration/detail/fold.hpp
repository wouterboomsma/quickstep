/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman
    Copyright (c) 2006 Dan Marsden
    Copyright (c) 2009-2010 Christopher Schmidt
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <qsboost/preprocessor/cat.hpp>

#define FUSION_HASH #

#ifdef QSBOOST_FUSION_REVERSE_FOLD
#   ifdef QSBOOST_FUSION_ITER_FOLD
#       define QSBOOST_FUSION_FOLD_NAME reverse_iter_fold
#   else
#       define QSBOOST_FUSION_FOLD_NAME reverse_fold
#   endif

#   define QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION end
#   define QSBOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION prior
#   define QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(IT)                   \
        typename fusion::result_of::prior<IT>::type
#   define QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM(IT) fusion::prior(IT)
#else
#   ifdef QSBOOST_FUSION_ITER_FOLD
#       define QSBOOST_FUSION_FOLD_NAME iter_fold
#   else
#       define QSBOOST_FUSION_FOLD_NAME fold
#   endif

#   define QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION begin
#   define QSBOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION next
#   define QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(IT) IT
#   define QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM(IT) IT
#endif
#ifdef QSBOOST_FUSION_ITER_FOLD
#   define QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(IT) IT&
#   define QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM(IT) IT
#else
#   define QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(IT)                  \
        typename fusion::result_of::deref<IT>::type
#   define QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM(IT) fusion::deref(IT)
#endif

#if (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
FUSION_HASH if QSBOOST_WORKAROUND QSBOOST_PREVENT_MACRO_SUBSTITUTION (QSBOOST_MSVC, < 1500)
FUSION_HASH     define QSBOOST_FUSION_FOLD_IMPL_ENABLER(T) void
FUSION_HASH else
FUSION_HASH     define QSBOOST_FUSION_FOLD_IMPL_ENABLER(T) typename T::type
FUSION_HASH endif
#else
#   if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1500)
#       define QSBOOST_FUSION_FOLD_IMPL_ENABLER(T) void
#   else
#       define QSBOOST_FUSION_FOLD_IMPL_ENABLER(T) typename T::type
#   endif
#endif

namespace qsboost { namespace fusion
{
    namespace detail
    {
        template<int SeqSize, typename It, typename State, typename F, typename = void
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if QSBOOST_WORKAROUND QSBOOST_PREVENT_MACRO_SUBSTITUTION (QSBOOST_MSVC, < 1500)
#endif
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1500) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
          // Dirty hack: those compilers cannot choose exactly one partial specialization.
          , bool = SeqSize == 0
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif
        >
        struct QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)
        {};

        template<typename It, typename State, typename F>
        struct QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)<0,It,State,F
          , typename qsboost::enable_if_has_type<QSBOOST_FUSION_FOLD_IMPL_ENABLER(State)>::type
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if QSBOOST_WORKAROUND QSBOOST_PREVENT_MACRO_SUBSTITUTION (QSBOOST_MSVC, < 1500)
#endif
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1500) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
          , true
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif
          >
        {
            typedef typename State::type type;
        };

        template<int SeqSize, typename It, typename State, typename F>
        struct QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)<SeqSize,It,State,F
          , typename qsboost::enable_if_has_type<
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if QSBOOST_WORKAROUND QSBOOST_PREVENT_MACRO_SUBSTITUTION (QSBOOST_MSVC, >= 1500)
#endif
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, >= 1500) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
                // Following SFINAE enables to avoid MSVC 9's partial specialization
                // ambiguous bug but MSVC 8 don't compile, and moreover MSVC 8 style
                // workaround won't work with MSVC 9.
                typename qsboost::disable_if_c<SeqSize == 0, State>::type::type
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH else
                QSBOOST_FUSION_FOLD_IMPL_ENABLER(State)
#endif
#else
                QSBOOST_FUSION_FOLD_IMPL_ENABLER(State)
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif
            >::type
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH if QSBOOST_WORKAROUND QSBOOST_PREVENT_MACRO_SUBSTITUTION (QSBOOST_MSVC, < 1500)
#endif
#if QSBOOST_WORKAROUND(QSBOOST_MSVC, < 1500) || \
    (defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES))
          , false
#endif
#if defined(__WAVE__) && defined(QSBOOST_FUSION_CREATE_PREPROCESSED_FILES)
FUSION_HASH endif
#endif
          >
          : QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)<
                SeqSize-1
              , typename result_of::QSBOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION<It>::type
              , qsboost::result_of<
                    F(
                        typename add_reference<typename State::type>::type,
                        QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(It const)
                    )
                >
              , F
            >
        {};

        template<typename It, typename State, typename F>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        inline typename QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)<
            0
          , It
          , State
          , F
        >::type
        QSBOOST_PP_CAT(it_,QSBOOST_FUSION_FOLD_NAME)(mpl::int_<0>, It const&, typename State::type state, F&)
        {
            return state;
        }

        template<typename It, typename State, typename F, int SeqSize>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        inline typename lazy_enable_if_c<
            SeqSize != 0
          , QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)<
                SeqSize
              , It
              , State
              , F
            >
        >::type
        QSBOOST_PP_CAT(it_,QSBOOST_FUSION_FOLD_NAME)(mpl::int_<SeqSize>, It const& it, typename State::type state, F& f)
        {
            return QSBOOST_PP_CAT(it_,QSBOOST_FUSION_FOLD_NAME)<
                typename result_of::QSBOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION<It>::type
              , qsboost::result_of<
                    F(
                        typename add_reference<typename State::type>::type,
                        QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM(It const)
                    )
                >
              , F
            >(
                mpl::int_<SeqSize-1>()
              , fusion::QSBOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION(it)
              , f(state, QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM(it))
              , f
            );
        }

        template<typename Seq, typename State, typename F
          , bool = traits::is_sequence<Seq>::value
          , bool = traits::is_segmented<Seq>::value>
        struct QSBOOST_PP_CAT(result_of_,QSBOOST_FUSION_FOLD_NAME)
        {};

        template<typename Seq, typename State, typename F>
        struct QSBOOST_PP_CAT(result_of_,QSBOOST_FUSION_FOLD_NAME)<Seq, State, F, true, false>
          : QSBOOST_PP_CAT(result_of_it_,QSBOOST_FUSION_FOLD_NAME)<
                result_of::size<Seq>::value
              , QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(
                    typename result_of::QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION<Seq>::type
                )
              , add_reference<State>
              , F
            >
        {};

        template<typename Seq, typename State, typename F>
        QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
        inline typename QSBOOST_PP_CAT(result_of_,QSBOOST_FUSION_FOLD_NAME)<Seq, State, F>::type
        QSBOOST_FUSION_FOLD_NAME(Seq& seq, State& state, F& f)
        {
            return QSBOOST_PP_CAT(it_,QSBOOST_FUSION_FOLD_NAME)<
                QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM(
                    typename result_of::QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION<Seq>::type
                )
              , add_reference<State>
              , F
            >(
                typename result_of::size<Seq>::type()
              , QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM(
                    fusion::QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION(seq)
                )
              , state
              , f
            );
        }
    }

    namespace result_of
    {
        template<typename Seq, typename State, typename F>
        struct QSBOOST_FUSION_FOLD_NAME
          : detail::QSBOOST_PP_CAT(result_of_,QSBOOST_FUSION_FOLD_NAME)<Seq, State, F>
        {};
    }

    template<typename Seq, typename State, typename F>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::QSBOOST_FUSION_FOLD_NAME<
        Seq
      , State const
      , F
    >::type
    QSBOOST_FUSION_FOLD_NAME(Seq& seq, State const& state, F f)
    {
        return detail::QSBOOST_FUSION_FOLD_NAME<Seq, State const, F>(seq, state, f);
    }

    template<typename Seq, typename State, typename F>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::QSBOOST_FUSION_FOLD_NAME<
        Seq const
      , State const
      , F
    >::type
    QSBOOST_FUSION_FOLD_NAME(Seq const& seq, State const& state, F f)
    {
        return detail::QSBOOST_FUSION_FOLD_NAME<Seq const, State const, F>(seq, state, f);
    }

    template<typename Seq, typename State, typename F>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::QSBOOST_FUSION_FOLD_NAME<
        Seq
      , State
      , F
    >::type
    QSBOOST_FUSION_FOLD_NAME(Seq& seq, State& state, F f)
    {
        return detail::QSBOOST_FUSION_FOLD_NAME<Seq, State, F>(seq, state, f);
    }

    template<typename Seq, typename State, typename F>
    QSBOOST_CONSTEXPR QSBOOST_FUSION_GPU_ENABLED
    inline typename result_of::QSBOOST_FUSION_FOLD_NAME<
        Seq const
      , State
      , F
    >::type
    QSBOOST_FUSION_FOLD_NAME(Seq const& seq, State& state, F f)
    {
        return detail::QSBOOST_FUSION_FOLD_NAME<Seq const, State, F>(seq, state, f);
    }
}}

#undef QSBOOST_FUSION_FOLD_NAME
#undef QSBOOST_FUSION_FOLD_IMPL_ENABLER
#undef QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_FUNCTION
#undef QSBOOST_FUSION_FOLD_IMPL_NEXT_IT_FUNCTION
#undef QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_META_TRANSFORM
#undef QSBOOST_FUSION_FOLD_IMPL_FIRST_IT_TRANSFORM
#undef QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_META_TRANSFORM
#undef QSBOOST_FUSION_FOLD_IMPL_INVOKE_IT_TRANSFORM
#undef FUSION_HASH
