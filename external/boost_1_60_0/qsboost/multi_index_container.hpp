/* Multiply indexed container.
 *
 * Copyright 2003-2014 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/multi_index for library home page.
 */

#ifndef QSBOOST_MULTI_INDEX_HPP
#define QSBOOST_MULTI_INDEX_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <qsboost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <algorithm>
#include <qsboost/detail/allocator_utilities.hpp>
#include <qsboost/detail/no_exceptions_support.hpp>
#include <qsboost/detail/workaround.hpp>
#include <qsboost/move/core.hpp>
#include <qsboost/mpl/at.hpp>
#include <qsboost/mpl/contains.hpp>
#include <qsboost/mpl/find_if.hpp>
#include <qsboost/mpl/identity.hpp>
#include <qsboost/mpl/int.hpp>
#include <qsboost/mpl/size.hpp>
#include <qsboost/mpl/deref.hpp>
#include <qsboost/multi_index_container_fwd.hpp>
#include <qsboost/multi_index/detail/access_specifier.hpp>
#include <qsboost/multi_index/detail/adl_swap.hpp>
#include <qsboost/multi_index/detail/base_type.hpp>
#include <qsboost/multi_index/detail/do_not_copy_elements_tag.hpp>
#include <qsboost/multi_index/detail/converter.hpp>
#include <qsboost/multi_index/detail/header_holder.hpp>
#include <qsboost/multi_index/detail/has_tag.hpp>
#include <qsboost/multi_index/detail/no_duplicate_tags.hpp>
#include <qsboost/multi_index/detail/safe_mode.hpp>
#include <qsboost/multi_index/detail/scope_guard.hpp>
#include <qsboost/multi_index/detail/vartempl_support.hpp>
#include <qsboost/static_assert.hpp>
#include <qsboost/type_traits/is_same.hpp>
#include <qsboost/utility/base_from_member.hpp>

#if !defined(QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST)
#include <initializer_list>
#endif

#if !defined(QSBOOST_MULTI_INDEX_DISABLE_SERIALIZATION)
#include <qsboost/multi_index/detail/archive_constructed.hpp>
#include <qsboost/multi_index/detail/serialization_version.hpp>
#include <qsboost/serialization/collection_size_type.hpp>
#include <qsboost/serialization/nvp.hpp>
#include <qsboost/serialization/split_member.hpp>
#include <qsboost/serialization/version.hpp>
#include <qsboost/throw_exception.hpp> 
#endif

#if defined(QSBOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)
#include <qsboost/multi_index/detail/invariant_assert.hpp>
#define QSBOOST_MULTI_INDEX_CHECK_INVARIANT_OF(x)                              \
  detail::scope_guard QSBOOST_JOIN(check_invariant_,__LINE__)=                 \
    detail::make_obj_guard(x,&multi_index_container::check_invariant_);      \
  QSBOOST_JOIN(check_invariant_,__LINE__).touch();
#define QSBOOST_MULTI_INDEX_CHECK_INVARIANT                                    \
  QSBOOST_MULTI_INDEX_CHECK_INVARIANT_OF(*this)
#else
#define QSBOOST_MULTI_INDEX_CHECK_INVARIANT_OF(x)
#define QSBOOST_MULTI_INDEX_CHECK_INVARIANT
#endif

namespace qsboost{

namespace multi_index{

#if QSBOOST_WORKAROUND(QSBOOST_MSVC,QSBOOST_TESTED_AT(1500))
#pragma warning(push)
#pragma warning(disable:4522) /* spurious warning on multiple operator=()'s */
#endif

template<typename Value,typename IndexSpecifierList,typename Allocator>
class multi_index_container:
  private ::qsboost::base_from_member<
    typename qsboost::detail::allocator::rebind_to<
      Allocator,
      typename detail::multi_index_node_type<
        Value,IndexSpecifierList,Allocator>::type
    >::type>,
  QSBOOST_MULTI_INDEX_PRIVATE_IF_MEMBER_TEMPLATE_FRIENDS detail::header_holder<
    typename qsboost::detail::allocator::rebind_to<
      Allocator,
      typename detail::multi_index_node_type<
        Value,IndexSpecifierList,Allocator>::type
    >::type::pointer,
    multi_index_container<Value,IndexSpecifierList,Allocator> >,
  public detail::multi_index_base_type<
    Value,IndexSpecifierList,Allocator>::type
{
#if defined(QSBOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)&&\
    QSBOOST_WORKAROUND(__MWERKS__,<=0x3003)
/* The "ISO C++ Template Parser" option in CW8.3 has a problem with the
 * lifetime of const references bound to temporaries --precisely what
 * scopeguards are.
 */

#pragma parse_mfunc_templ off
#endif

private:
  QSBOOST_COPYABLE_AND_MOVABLE(multi_index_container)

#if !defined(QSBOOST_NO_MEMBER_TEMPLATE_FRIENDS)
  template <typename,typename,typename> friend class  detail::index_base;
  template <typename,typename>          friend struct detail::header_holder;
  template <typename,typename>          friend struct detail::converter;
#endif

  typedef typename detail::multi_index_base_type<
      Value,IndexSpecifierList,Allocator>::type   super;
  typedef typename
  qsboost::detail::allocator::rebind_to<
    Allocator,
    typename super::node_type
  >::type                                         node_allocator;
  typedef ::qsboost::base_from_member<
    node_allocator>                               bfm_allocator;
  typedef detail::header_holder<
    typename node_allocator::pointer,
    multi_index_container>                        bfm_header;


public:
  /* All types are inherited from super, a few are explicitly
   * brought forward here to save us some typename's.
   */

  typedef typename super::ctor_args_list           ctor_args_list;
  typedef IndexSpecifierList                       index_specifier_type_list;
 
  typedef typename super::index_type_list          index_type_list;

  typedef typename super::iterator_type_list       iterator_type_list;
  typedef typename super::const_iterator_type_list const_iterator_type_list;
  typedef typename super::value_type               value_type;
  typedef typename super::final_allocator_type     allocator_type;
  typedef typename super::iterator                 iterator;
  typedef typename super::const_iterator           const_iterator;

  QSBOOST_STATIC_ASSERT(
    detail::no_duplicate_tags_in_index_list<index_type_list>::value);

  /* global project() needs to see this publicly */

  typedef typename super::node_type node_type;

  /* construct/copy/destroy */

  explicit multi_index_container(

#if QSBOOST_WORKAROUND(__IBMCPP__,<=600)
    /* VisualAge seems to have an ETI issue with the default values
     * for arguments args_list and al.
     */

    const ctor_args_list& args_list=
      typename mpl::identity<multi_index_container>::type::
        ctor_args_list(),
    const allocator_type& al=
      typename mpl::identity<multi_index_container>::type::
        allocator_type()):
#else
    const ctor_args_list& args_list=ctor_args_list(),
    const allocator_type& al=allocator_type()):
#endif

    bfm_allocator(al),
    super(args_list,bfm_allocator::member),
    node_count(0)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
  }

  explicit multi_index_container(const allocator_type& al):
    bfm_allocator(al),
    super(ctor_args_list(),bfm_allocator::member),
    node_count(0)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
  }
  
  template<typename InputIterator>
  multi_index_container(
    InputIterator first,InputIterator last,

#if QSBOOST_WORKAROUND(__IBMCPP__,<=600)
    /* VisualAge seems to have an ETI issue with the default values
     * for arguments args_list and al.
     */

    const ctor_args_list& args_list=
      typename mpl::identity<multi_index_container>::type::
        ctor_args_list(),
    const allocator_type& al=
      typename mpl::identity<multi_index_container>::type::
        allocator_type()):
#else
    const ctor_args_list& args_list=ctor_args_list(),
    const allocator_type& al=allocator_type()):
#endif

    bfm_allocator(al),
    super(args_list,bfm_allocator::member),
    node_count(0)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
    QSBOOST_TRY{
      iterator hint=super::end();
      for(;first!=last;++first){
        hint=super::make_iterator(
          insert_ref_(*first,hint.get_node()).first);
        ++hint;
      }
    }
    QSBOOST_CATCH(...){
      clear_();
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

#if !defined(QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST)
  multi_index_container(
    std::initializer_list<Value> list,
    const ctor_args_list& args_list=ctor_args_list(),
    const allocator_type& al=allocator_type()):
    bfm_allocator(al),
    super(args_list,bfm_allocator::member),
    node_count(0)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
    QSBOOST_TRY{
      typedef const Value* init_iterator;

      iterator hint=super::end();
      for(init_iterator first=list.begin(),last=list.end();
          first!=last;++first){
        hint=super::make_iterator(insert_(*first,hint.get_node()).first);
        ++hint;
      }
    }
    QSBOOST_CATCH(...){
      clear_();
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }
#endif

  multi_index_container(
    const multi_index_container<Value,IndexSpecifierList,Allocator>& x):
    bfm_allocator(x.bfm_allocator::member),
    bfm_header(),
    super(x),
    node_count(0)
  {
    copy_map_type map(bfm_allocator::member,x.size(),x.header(),header());
    for(const_iterator it=x.begin(),it_end=x.end();it!=it_end;++it){
      map.clone(it.get_node());
    }
    super::copy_(x,map);
    map.release();
    node_count=x.size();

    /* Not until this point are the indices required to be consistent,
     * hence the position of the invariant checker.
     */

    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
  }

  multi_index_container(QSBOOST_RV_REF(multi_index_container) x):
    bfm_allocator(x.bfm_allocator::member),
    bfm_header(),
    super(x,detail::do_not_copy_elements_tag()),
    node_count(0)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT_OF(x);
    swap_elements_(x);
  }

  ~multi_index_container()
  {
    delete_all_nodes_();
  }

#if defined(QSBOOST_NO_CXX11_RVALUE_REFERENCES)
  /* As per http://www.boost.org/doc/html/move/emulation_limitations.html
   * #move.emulation_limitations.assignment_operator
   */

  multi_index_container<Value,IndexSpecifierList,Allocator>& operator=(
    const multi_index_container<Value,IndexSpecifierList,Allocator>& x)
  {
    multi_index_container y(x);
    this->swap(y);
    return *this;
  }
#endif

  multi_index_container<Value,IndexSpecifierList,Allocator>& operator=(
    QSBOOST_COPY_ASSIGN_REF(multi_index_container) x)
  {
    multi_index_container y(x);
    this->swap(y);
    return *this;
  }

  multi_index_container<Value,IndexSpecifierList,Allocator>& operator=(
    QSBOOST_RV_REF(multi_index_container) x)
  {
    this->swap(x);
    return *this;
  }

#if !defined(QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST)
  multi_index_container<Value,IndexSpecifierList,Allocator>& operator=(
    std::initializer_list<Value> list)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
    typedef const Value* init_iterator;

    multi_index_container x(*this,detail::do_not_copy_elements_tag());    
    iterator hint=x.end();
    for(init_iterator first=list.begin(),last=list.end();
        first!=last;++first){
      hint=x.make_iterator(x.insert_(*first,hint.get_node()).first);
      ++hint;
    }
    x.swap_elements_(*this);
    return*this;
  }
#endif

  allocator_type get_allocator()const QSBOOST_NOEXCEPT
  {
    return allocator_type(bfm_allocator::member);
  }

  /* retrieval of indices by number */

#if !defined(QSBOOST_NO_MEMBER_TEMPLATES)
  template<int N>
  struct nth_index
  {
    QSBOOST_STATIC_ASSERT(N>=0&&N<mpl::size<index_type_list>::type::value);
    typedef typename mpl::at_c<index_type_list,N>::type type;
  };

  template<int N>
  typename nth_index<N>::type& get()QSBOOST_NOEXCEPT
  {
    QSBOOST_STATIC_ASSERT(N>=0&&N<mpl::size<index_type_list>::type::value);
    return *this;
  }

  template<int N>
  const typename nth_index<N>::type& get()const QSBOOST_NOEXCEPT
  {
    QSBOOST_STATIC_ASSERT(N>=0&&N<mpl::size<index_type_list>::type::value);
    return *this;
  }
#endif

  /* retrieval of indices by tag */

#if !defined(QSBOOST_NO_MEMBER_TEMPLATES)
  template<typename Tag>
  struct index
  {
    typedef typename mpl::find_if<
      index_type_list,
      detail::has_tag<Tag>
    >::type                                    iter;

    QSBOOST_STATIC_CONSTANT(
      bool,index_found=!(is_same<iter,typename mpl::end<index_type_list>::type >::value));
    QSBOOST_STATIC_ASSERT(index_found);

    typedef typename mpl::deref<iter>::type    type;
  };

  template<typename Tag>
  typename index<Tag>::type& get()QSBOOST_NOEXCEPT
  {
    return *this;
  }

  template<typename Tag>
  const typename index<Tag>::type& get()const QSBOOST_NOEXCEPT
  {
    return *this;
  }
#endif

  /* projection of iterators by number */

#if !defined(QSBOOST_NO_MEMBER_TEMPLATES)
  template<int N>
  struct nth_index_iterator
  {
    typedef typename nth_index<N>::type::iterator type;
  };

  template<int N>
  struct nth_index_const_iterator
  {
    typedef typename nth_index<N>::type::const_iterator type;
  };

  template<int N,typename IteratorType>
  typename nth_index_iterator<N>::type project(IteratorType it)
  {
    typedef typename nth_index<N>::type index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    QSBOOST_STATIC_ASSERT(
      (mpl::contains<iterator_type_list,IteratorType>::value));
#endif

    QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<typename IteratorType::container_type&>(*this));

    return index_type::make_iterator(static_cast<node_type*>(it.get_node()));
  }

  template<int N,typename IteratorType>
  typename nth_index_const_iterator<N>::type project(IteratorType it)const
  {
    typedef typename nth_index<N>::type index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    QSBOOST_STATIC_ASSERT((
      mpl::contains<iterator_type_list,IteratorType>::value||
      mpl::contains<const_iterator_type_list,IteratorType>::value));
#endif

    QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<const typename IteratorType::container_type&>(*this));
    return index_type::make_iterator(static_cast<node_type*>(it.get_node()));
  }
#endif

  /* projection of iterators by tag */

#if !defined(QSBOOST_NO_MEMBER_TEMPLATES)
  template<typename Tag>
  struct index_iterator
  {
    typedef typename index<Tag>::type::iterator type;
  };

  template<typename Tag>
  struct index_const_iterator
  {
    typedef typename index<Tag>::type::const_iterator type;
  };

  template<typename Tag,typename IteratorType>
  typename index_iterator<Tag>::type project(IteratorType it)
  {
    typedef typename index<Tag>::type index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    QSBOOST_STATIC_ASSERT(
      (mpl::contains<iterator_type_list,IteratorType>::value));
#endif

    QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<typename IteratorType::container_type&>(*this));
    return index_type::make_iterator(static_cast<node_type*>(it.get_node()));
  }

  template<typename Tag,typename IteratorType>
  typename index_const_iterator<Tag>::type project(IteratorType it)const
  {
    typedef typename index<Tag>::type index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* fails in Sun C++ 5.7 */
    QSBOOST_STATIC_ASSERT((
      mpl::contains<iterator_type_list,IteratorType>::value||
      mpl::contains<const_iterator_type_list,IteratorType>::value));
#endif

    QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);
    QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(
      it,static_cast<const typename IteratorType::container_type&>(*this));
    return index_type::make_iterator(static_cast<node_type*>(it.get_node()));
  }
#endif

QSBOOST_MULTI_INDEX_PROTECTED_IF_MEMBER_TEMPLATE_FRIENDS:
  typedef typename super::copy_map_type copy_map_type;

#if !defined(QSBOOST_NO_CXX11_HDR_INITIALIZER_LIST)
  multi_index_container(
    const multi_index_container<Value,IndexSpecifierList,Allocator>& x,
    detail::do_not_copy_elements_tag):
    bfm_allocator(x.bfm_allocator::member),
    bfm_header(),
    super(x,detail::do_not_copy_elements_tag()),
    node_count(0)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;
  }
#endif

  node_type* header()const
  {
    return &*bfm_header::member;
  }

  node_type* allocate_node()
  {
    return &*bfm_allocator::member.allocate(1);
  }

  void deallocate_node(node_type* x)
  {
    typedef typename node_allocator::pointer node_pointer;
    bfm_allocator::member.deallocate(static_cast<node_pointer>(x),1);
  }

  bool empty_()const
  {
    return node_count==0;
  }

  std::size_t size_()const
  {
    return node_count;
  }

  std::size_t max_size_()const
  {
    return static_cast<std::size_t >(-1);
  }

  template<typename Variant>
  std::pair<node_type*,bool> insert_(const Value& v,Variant variant)
  {
    node_type* x=0;
    node_type* res=super::insert_(v,x,variant);
    if(res==x){
      ++node_count;
      return std::pair<node_type*,bool>(res,true);
    }
    else{
      return std::pair<node_type*,bool>(res,false);
    }
  }

  std::pair<node_type*,bool> insert_(const Value& v)
  {
    return insert_(v,detail::lvalue_tag());
  }

  std::pair<node_type*,bool> insert_rv_(const Value& v)
  {
    return insert_(v,detail::rvalue_tag());
  }

  template<typename T>
  std::pair<node_type*,bool> insert_ref_(T& t)
  {
    node_type* x=allocate_node();
    QSBOOST_TRY{
      new(&x->value()) value_type(t);
      QSBOOST_TRY{
        node_type* res=super::insert_(x->value(),x,detail::emplaced_tag());
        if(res==x){
          ++node_count;
          return std::pair<node_type*,bool>(res,true);
        }
        else{
          qsboost::detail::allocator::destroy(&x->value());
          deallocate_node(x);
          return std::pair<node_type*,bool>(res,false);
        }
      }
      QSBOOST_CATCH(...){
        qsboost::detail::allocator::destroy(&x->value());
        QSBOOST_RETHROW;
      }
      QSBOOST_CATCH_END
    }
    QSBOOST_CATCH(...){
      deallocate_node(x);
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

  std::pair<node_type*,bool> insert_ref_(const value_type& x)
  {
    return insert_(x);
  }

  std::pair<node_type*,bool> insert_ref_(value_type& x)
  {
    return insert_(x);
  }

  template<QSBOOST_MULTI_INDEX_TEMPLATE_PARAM_PACK>
  std::pair<node_type*,bool> emplace_(
    QSBOOST_MULTI_INDEX_FUNCTION_PARAM_PACK)
  {
    node_type* x=allocate_node();
    QSBOOST_TRY{
      detail::vartempl_placement_new(
        &x->value(),QSBOOST_MULTI_INDEX_FORWARD_PARAM_PACK);
      QSBOOST_TRY{
        node_type* res=super::insert_(x->value(),x,detail::emplaced_tag());
        if(res==x){
          ++node_count;
          return std::pair<node_type*,bool>(res,true);
        }
        else{
          qsboost::detail::allocator::destroy(&x->value());
          deallocate_node(x);
          return std::pair<node_type*,bool>(res,false);
        }
      }
      QSBOOST_CATCH(...){
        qsboost::detail::allocator::destroy(&x->value());
        QSBOOST_RETHROW;
      }
      QSBOOST_CATCH_END
    }
    QSBOOST_CATCH(...){
      deallocate_node(x);
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

  template<typename Variant>
  std::pair<node_type*,bool> insert_(
    const Value& v,node_type* position,Variant variant)
  {
    node_type* x=0;
    node_type* res=super::insert_(v,position,x,variant);
    if(res==x){
      ++node_count;
      return std::pair<node_type*,bool>(res,true);
    }
    else{
      return std::pair<node_type*,bool>(res,false);
    }
  }

  std::pair<node_type*,bool> insert_(const Value& v,node_type* position)
  {
    return insert_(v,position,detail::lvalue_tag());
  }

  std::pair<node_type*,bool> insert_rv_(const Value& v,node_type* position)
  {
    return insert_(v,position,detail::rvalue_tag());
  }

  template<typename T>
  std::pair<node_type*,bool> insert_ref_(
    T& t,node_type* position)
  {
    node_type* x=allocate_node();
    QSBOOST_TRY{
      new(&x->value()) value_type(t);
      QSBOOST_TRY{
        node_type* res=super::insert_(
          x->value(),position,x,detail::emplaced_tag());
        if(res==x){
          ++node_count;
          return std::pair<node_type*,bool>(res,true);
        }
        else{
          qsboost::detail::allocator::destroy(&x->value());
          deallocate_node(x);
          return std::pair<node_type*,bool>(res,false);
        }
      }
      QSBOOST_CATCH(...){
        qsboost::detail::allocator::destroy(&x->value());
        QSBOOST_RETHROW;
      }
      QSBOOST_CATCH_END
    }
    QSBOOST_CATCH(...){
      deallocate_node(x);
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

  std::pair<node_type*,bool> insert_ref_(
    const value_type& x,node_type* position)
  {
    return insert_(x,position);
  }

  std::pair<node_type*,bool> insert_ref_(
    value_type& x,node_type* position)
  {
    return insert_(x,position);
  }

  template<QSBOOST_MULTI_INDEX_TEMPLATE_PARAM_PACK>
  std::pair<node_type*,bool> emplace_hint_(
    node_type* position,
    QSBOOST_MULTI_INDEX_FUNCTION_PARAM_PACK)
  {
    node_type* x=allocate_node();
    QSBOOST_TRY{
      detail::vartempl_placement_new(
        &x->value(),QSBOOST_MULTI_INDEX_FORWARD_PARAM_PACK);
      QSBOOST_TRY{
        node_type* res=super::insert_(
          x->value(),position,x,detail::emplaced_tag());
        if(res==x){
          ++node_count;
          return std::pair<node_type*,bool>(res,true);
        }
        else{
          qsboost::detail::allocator::destroy(&x->value());
          deallocate_node(x);
          return std::pair<node_type*,bool>(res,false);
        }
      }
      QSBOOST_CATCH(...){
        qsboost::detail::allocator::destroy(&x->value());
        QSBOOST_RETHROW;
      }
      QSBOOST_CATCH_END
    }
    QSBOOST_CATCH(...){
      deallocate_node(x);
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

  void erase_(node_type* x)
  {
    --node_count;
    super::erase_(x);
    deallocate_node(x);
  }

  void delete_node_(node_type* x)
  {
    super::delete_node_(x);
    deallocate_node(x);
  }

  void delete_all_nodes_()
  {
    super::delete_all_nodes_();
  }

  void clear_()
  {
    delete_all_nodes_();
    super::clear_();
    node_count=0;
  }

  void swap_(multi_index_container<Value,IndexSpecifierList,Allocator>& x)
  {
    if(bfm_allocator::member!=x.bfm_allocator::member){
      detail::adl_swap(bfm_allocator::member,x.bfm_allocator::member);
    }
    std::swap(bfm_header::member,x.bfm_header::member);
    super::swap_(x);
    std::swap(node_count,x.node_count);
  }

  void swap_elements_(
    multi_index_container<Value,IndexSpecifierList,Allocator>& x)
  {
    std::swap(bfm_header::member,x.bfm_header::member);
    super::swap_elements_(x);
    std::swap(node_count,x.node_count);
  }

  bool replace_(const Value& k,node_type* x)
  {
    return super::replace_(k,x,detail::lvalue_tag());
  }

  bool replace_rv_(const Value& k,node_type* x)
  {
    return super::replace_(k,x,detail::rvalue_tag());
  }

  template<typename Modifier>
  bool modify_(Modifier& mod,node_type* x)
  {
    mod(const_cast<value_type&>(x->value()));

    QSBOOST_TRY{
      if(!super::modify_(x)){
        deallocate_node(x);
        --node_count;
        return false;
      }
      else return true;
    }
    QSBOOST_CATCH(...){
      deallocate_node(x);
      --node_count;
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

  template<typename Modifier,typename Rollback>
  bool modify_(Modifier& mod,Rollback& back_,node_type* x)
  {
    mod(const_cast<value_type&>(x->value()));

    bool b;
    QSBOOST_TRY{
      b=super::modify_rollback_(x);
    }
    QSBOOST_CATCH(...){
      QSBOOST_TRY{
        back_(const_cast<value_type&>(x->value()));
        QSBOOST_RETHROW;
      }
      QSBOOST_CATCH(...){
        this->erase_(x);
        QSBOOST_RETHROW;
      }
      QSBOOST_CATCH_END
    }
    QSBOOST_CATCH_END

    QSBOOST_TRY{
      if(!b){
        back_(const_cast<value_type&>(x->value()));
        return false;
      }
      else return true;
    }
    QSBOOST_CATCH(...){
      this->erase_(x);
      QSBOOST_RETHROW;
    }
    QSBOOST_CATCH_END
  }

#if !defined(QSBOOST_MULTI_INDEX_DISABLE_SERIALIZATION)
  /* serialization */

  friend class qsboost::serialization::access;

  QSBOOST_SERIALIZATION_SPLIT_MEMBER()

  typedef typename super::index_saver_type        index_saver_type;
  typedef typename super::index_loader_type       index_loader_type;

  template<class Archive>
  void save(Archive& ar,const unsigned int version)const
  {
    const serialization::collection_size_type       s(size_());
    const detail::serialization_version<value_type> value_version;
    ar<<serialization::make_nvp("count",s);
    ar<<serialization::make_nvp("value_version",value_version);

    index_saver_type sm(bfm_allocator::member,s);

    for(iterator it=super::begin(),it_end=super::end();it!=it_end;++it){
      serialization::save_construct_data_adl(ar,&*it,value_version);
      ar<<serialization::make_nvp("item",*it);
      sm.add(it.get_node(),ar,version);
    }
    sm.add_track(header(),ar,version);

    super::save_(ar,version,sm);
  }

  template<class Archive>
  void load(Archive& ar,const unsigned int version)
  {
    QSBOOST_MULTI_INDEX_CHECK_INVARIANT;

    clear_(); 
    serialization::collection_size_type       s;
    detail::serialization_version<value_type> value_version;
    if(version<1){
      std::size_t sz;
      ar>>serialization::make_nvp("count",sz);
      s=static_cast<serialization::collection_size_type>(sz);
    }
    else{
      ar>>serialization::make_nvp("count",s);
    }
    if(version<2){
      value_version=0;
    }
    else{
      ar>>serialization::make_nvp("value_version",value_version);
    }

    index_loader_type lm(bfm_allocator::member,s);

    for(std::size_t n=0;n<s;++n){
      detail::archive_constructed<Value> value("item",ar,value_version);
      std::pair<node_type*,bool> p=insert_(
        value.get(),super::end().get_node());
      if(!p.second)throw_exception(
        archive::archive_exception(
          archive::archive_exception::other_exception));
      ar.reset_object_address(&p.first->value(),&value.get());
      lm.add(p.first,ar,version);
    }
    lm.add_track(header(),ar,version);

    super::load_(ar,version,lm);
  }
#endif

#if defined(QSBOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)
  /* invariant stuff */

  bool invariant_()const
  {
    return super::invariant_();
  }

  void check_invariant_()const
  {
    QSBOOST_MULTI_INDEX_INVARIANT_ASSERT(invariant_());
  }
#endif

private:
  std::size_t node_count;

#if defined(QSBOOST_MULTI_INDEX_ENABLE_INVARIANT_CHECKING)&&\
    QSBOOST_WORKAROUND(__MWERKS__,<=0x3003)
#pragma parse_mfunc_templ reset
#endif
};

#if QSBOOST_WORKAROUND(QSBOOST_MSVC,QSBOOST_TESTED_AT(1500))
#pragma warning(pop) /* C4522 */
#endif

/* retrieval of indices by number */

template<typename MultiIndexContainer,int N>
struct nth_index
{
  QSBOOST_STATIC_CONSTANT(
    int,
    M=mpl::size<typename MultiIndexContainer::index_type_list>::type::value);
  QSBOOST_STATIC_ASSERT(N>=0&&N<M);
  typedef typename mpl::at_c<
    typename MultiIndexContainer::index_type_list,N>::type type;
};

template<int N,typename Value,typename IndexSpecifierList,typename Allocator>
typename nth_index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type&
get(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m)QSBOOST_NOEXCEPT
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>    multi_index_type;
  typedef typename nth_index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    N
  >::type                                  index_type;

  QSBOOST_STATIC_ASSERT(N>=0&&
    N<
    mpl::size<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::index_type_list
    >::type::value);

  return detail::converter<multi_index_type,index_type>::index(m);
}

template<int N,typename Value,typename IndexSpecifierList,typename Allocator>
const typename nth_index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type&
get(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m
)QSBOOST_NOEXCEPT
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>    multi_index_type;
  typedef typename nth_index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    N
  >::type                                  index_type;

  QSBOOST_STATIC_ASSERT(N>=0&&
    N<
    mpl::size<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::index_type_list
    >::type::value);

  return detail::converter<multi_index_type,index_type>::index(m);
}

/* retrieval of indices by tag */

template<typename MultiIndexContainer,typename Tag>
struct index
{
  typedef typename MultiIndexContainer::index_type_list index_type_list;

  typedef typename mpl::find_if<
    index_type_list,
    detail::has_tag<Tag>
  >::type                                      iter;

  QSBOOST_STATIC_CONSTANT(
    bool,index_found=!(is_same<iter,typename mpl::end<index_type_list>::type >::value));
  QSBOOST_STATIC_ASSERT(index_found);

  typedef typename mpl::deref<iter>::type       type;
};

template<
  typename Tag,typename Value,typename IndexSpecifierList,typename Allocator
>
typename ::qsboost::multi_index::index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&
get(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m)QSBOOST_NOEXCEPT
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::qsboost::multi_index::index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    Tag
  >::type                                       index_type;

  return detail::converter<multi_index_type,index_type>::index(m);
}

template<
  typename Tag,typename Value,typename IndexSpecifierList,typename Allocator
>
const typename ::qsboost::multi_index::index<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type&
get(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m
)QSBOOST_NOEXCEPT
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::qsboost::multi_index::index<
    multi_index_container<
      Value,IndexSpecifierList,Allocator>,
    Tag
  >::type                                       index_type;

  return detail::converter<multi_index_type,index_type>::index(m);
}

/* projection of iterators by number */

template<typename MultiIndexContainer,int N>
struct nth_index_iterator
{
  typedef typename nth_index<MultiIndexContainer,N>::type::iterator type;
};

template<typename MultiIndexContainer,int N>
struct nth_index_const_iterator
{
  typedef typename nth_index<MultiIndexContainer,N>::type::const_iterator type;
};

template<
  int N,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename nth_index_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type
project(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it)
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>                multi_index_type;
  typedef typename nth_index<multi_index_type,N>::type index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* Sun C++ 5.7 fails */
  QSBOOST_STATIC_ASSERT((
    mpl::contains<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value));
#endif

  QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(QSBOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    QSBOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index_type>::iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

template<
  int N,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename nth_index_const_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,N>::type
project(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it)
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>                multi_index_type;
  typedef typename nth_index<multi_index_type,N>::type index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* Sun C++ 5.7 fails */
  QSBOOST_STATIC_ASSERT((
    mpl::contains<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value||
    mpl::contains<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::const_iterator_type_list,
      IteratorType>::value));
#endif

  QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(QSBOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    QSBOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index_type>::const_iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

/* projection of iterators by tag */

template<typename MultiIndexContainer,typename Tag>
struct index_iterator
{
  typedef typename ::qsboost::multi_index::index<
    MultiIndexContainer,Tag>::type::iterator    type;
};

template<typename MultiIndexContainer,typename Tag>
struct index_const_iterator
{
  typedef typename ::qsboost::multi_index::index<
    MultiIndexContainer,Tag>::type::const_iterator type;
};

template<
  typename Tag,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename index_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type
project(
  multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it)
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::qsboost::multi_index::index<
    multi_index_type,Tag>::type                 index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* Sun C++ 5.7 fails */
  QSBOOST_STATIC_ASSERT((
    mpl::contains<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value));
#endif

  QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(QSBOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    QSBOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index_type>::iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

template<
  typename Tag,typename IteratorType,
  typename Value,typename IndexSpecifierList,typename Allocator>
typename index_const_iterator<
  multi_index_container<Value,IndexSpecifierList,Allocator>,Tag>::type
project(
  const multi_index_container<Value,IndexSpecifierList,Allocator>& m,
  IteratorType it)
{
  typedef multi_index_container<
    Value,IndexSpecifierList,Allocator>         multi_index_type;
  typedef typename ::qsboost::multi_index::index<
    multi_index_type,Tag>::type                 index_type;

#if !defined(__SUNPRO_CC)||!(__SUNPRO_CC<0x580) /* Sun C++ 5.7 fails */
  QSBOOST_STATIC_ASSERT((
    mpl::contains<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::iterator_type_list,
      IteratorType>::value||
    mpl::contains<
      QSBOOST_DEDUCED_TYPENAME multi_index_type::const_iterator_type_list,
      IteratorType>::value));
#endif

  QSBOOST_MULTI_INDEX_CHECK_VALID_ITERATOR(it);

#if defined(QSBOOST_MULTI_INDEX_ENABLE_SAFE_MODE)
  typedef detail::converter<
    multi_index_type,
    QSBOOST_DEDUCED_TYPENAME IteratorType::container_type> converter;
  QSBOOST_MULTI_INDEX_CHECK_IS_OWNER(it,converter::index(m));
#endif

  return detail::converter<multi_index_type,index_type>::const_iterator(
    m,static_cast<typename multi_index_type::node_type*>(it.get_node()));
}

/* Comparison. Simple forward to first index. */

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator==(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)==get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator<(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)<get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator!=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)!=get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator>(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)>get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator>=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)>=get<0>(y);
}

template<
  typename Value1,typename IndexSpecifierList1,typename Allocator1,
  typename Value2,typename IndexSpecifierList2,typename Allocator2
>
bool operator<=(
  const multi_index_container<Value1,IndexSpecifierList1,Allocator1>& x,
  const multi_index_container<Value2,IndexSpecifierList2,Allocator2>& y)
{
  return get<0>(x)<=get<0>(y);
}

/*  specialized algorithms */

template<typename Value,typename IndexSpecifierList,typename Allocator>
void swap(
  multi_index_container<Value,IndexSpecifierList,Allocator>& x,
  multi_index_container<Value,IndexSpecifierList,Allocator>& y)
{
  x.swap(y);
}

} /* namespace multi_index */

#if !defined(QSBOOST_MULTI_INDEX_DISABLE_SERIALIZATION)
/* class version = 1 : we now serialize the size through
 * boost::serialization::collection_size_type.
 * class version = 2 : proper use of {save|load}_construct_data.
 */

namespace serialization {
template<typename Value,typename IndexSpecifierList,typename Allocator>
struct version<
  qsboost::multi_index_container<Value,IndexSpecifierList,Allocator>
>
{
  QSBOOST_STATIC_CONSTANT(int,value=2);
};
} /* namespace serialization */
#endif

/* Associated global functions are promoted to namespace boost, except
 * comparison operators and swap, which are meant to be Koenig looked-up.
 */

using multi_index::get;
using multi_index::project;

} /* namespace boost */

#undef QSBOOST_MULTI_INDEX_CHECK_INVARIANT
#undef QSBOOST_MULTI_INDEX_CHECK_INVARIANT_OF

#endif
