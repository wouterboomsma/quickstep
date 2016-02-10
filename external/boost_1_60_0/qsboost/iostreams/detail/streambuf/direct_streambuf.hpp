// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_DIRECT_STREAMBUF_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_DIRECT_STREAMBUF_HPP_INCLUDED

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif              

#include <qsboost/assert.hpp>
#include <cstddef>
#include <typeinfo>
#include <utility>                                 // pair.
#include <qsboost/config.hpp>                        // BOOST_DEDUCED_TYPENAME, 
#include <qsboost/iostreams/detail/char_traits.hpp>  // member template friends.
#include <qsboost/iostreams/detail/config/wide_streams.hpp>
#include <qsboost/iostreams/detail/error.hpp>
#include <qsboost/iostreams/detail/execute.hpp>
#include <qsboost/iostreams/detail/functional.hpp>
#include <qsboost/iostreams/detail/ios.hpp>
#include <qsboost/iostreams/detail/optional.hpp>
#include <qsboost/iostreams/detail/streambuf.hpp>
#include <qsboost/iostreams/detail/streambuf/linked_streambuf.hpp>
#include <qsboost/iostreams/operations.hpp>
#include <qsboost/iostreams/positioning.hpp>
#include <qsboost/iostreams/traits.hpp>
#include <qsboost/throw_exception.hpp>

// Must come last.
#include <qsboost/iostreams/detail/config/disable_warnings.hpp> // MSVC.

namespace qsboost { namespace iostreams { 
    
namespace detail {

template< typename T,
          typename Tr = 
              QSBOOST_IOSTREAMS_CHAR_TRAITS(
                 QSBOOST_DEDUCED_TYPENAME char_type_of<T>::type 
              ) >
class direct_streambuf 
    : public linked_streambuf<QSBOOST_DEDUCED_TYPENAME char_type_of<T>::type, Tr>
{
public:
    typedef typename char_type_of<T>::type                char_type;
    QSBOOST_IOSTREAMS_STREAMBUF_TYPEDEFS(Tr)
private:
    typedef linked_streambuf<char_type, traits_type>      base_type;
    typedef typename category_of<T>::type                 category;
    typedef QSBOOST_IOSTREAMS_BASIC_STREAMBUF(
                char_type, traits_type
            )                                             streambuf_type;
public: // stream needs access.
    void open(const T& t, std::streamsize buffer_size, 
              std::streamsize pback_size);
    bool is_open() const;
    void close();
    bool auto_close() const { return auto_close_; }
    void set_auto_close(bool close) { auto_close_ = close; }
    bool strict_sync() { return true; }

    // Declared in linked_streambuf.
    T* component() { return storage_.get(); }
protected:
#if !QSBOOST_WORKAROUND(__GNUC__, == 2)
    QSBOOST_IOSTREAMS_USING_PROTECTED_STREAMBUF_MEMBERS(base_type)
#endif
    direct_streambuf();

    //--------------Virtual functions-----------------------------------------//

    // Declared in linked_streambuf.
    void close_impl(QSBOOST_IOS::openmode m);
    const std::type_info& component_type() const { return typeid(T); }
    void* component_impl() { return component(); } 
#ifdef QSBOOST_IOSTREAMS_NO_STREAM_TEMPLATES
    public:
#endif

    // Declared in basic_streambuf.
    int_type underflow();
    int_type pbackfail(int_type c);
    int_type overflow(int_type c);
    pos_type seekoff( off_type off, QSBOOST_IOS::seekdir way,
                      QSBOOST_IOS::openmode which );
    pos_type seekpos(pos_type sp, QSBOOST_IOS::openmode which);
private:
    pos_type seek_impl( stream_offset off, QSBOOST_IOS::seekdir way,
                        QSBOOST_IOS::openmode which );
    void init_input(any_tag) { }
    void init_input(input);
    void init_output(any_tag) { }
    void init_output(output);
    void init_get_area();
    void init_put_area();
    bool one_head() const;
    bool two_head() const;
    optional<T>  storage_;
    char_type   *ibeg_, *iend_, *obeg_, *oend_;
    bool         auto_close_;
};
                    
//------------------Implementation of direct_streambuf------------------------//

template<typename T, typename Tr>
direct_streambuf<T, Tr>::direct_streambuf() 
    : ibeg_(0), iend_(0), obeg_(0), oend_(0), auto_close_(true) 
{ this->set_true_eof(true); }

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::open
    (const T& t, std::streamsize, std::streamsize)
{
    storage_.reset(t);
    init_input(category());
    init_output(category());
    setg(0, 0, 0);
    setp(0, 0);
    this->set_needs_close();
}

template<typename T, typename Tr>
bool direct_streambuf<T, Tr>::is_open() const 
{ return ibeg_ != 0 || obeg_ != 0; }

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::close() 
{ 
    base_type* self = this;
    detail::execute_all( detail::call_member_close(*self, QSBOOST_IOS::in),
                         detail::call_member_close(*self, QSBOOST_IOS::out),
                         detail::call_reset(storage_) );
}

template<typename T, typename Tr>
typename direct_streambuf<T, Tr>::int_type 
direct_streambuf<T, Tr>::underflow()
{
    if (!ibeg_) 
        qsboost::throw_exception(cant_read());
    if (!gptr()) 
        init_get_area();
    return gptr() != iend_ ? 
        traits_type::to_int_type(*gptr()) : 
        traits_type::eof();
}

template<typename T, typename Tr>
typename direct_streambuf<T, Tr>::int_type 
direct_streambuf<T, Tr>::pbackfail(int_type c)
{
    using namespace std;
    if (!ibeg_) 
        qsboost::throw_exception(cant_read());
    if (gptr() != 0 && gptr() != ibeg_) {
        gbump(-1);
        if (!traits_type::eq_int_type(c, traits_type::eof()))
            *gptr() = traits_type::to_char_type(c);
        return traits_type::not_eof(c);
    }
    qsboost::throw_exception(bad_putback());
}

template<typename T, typename Tr>
typename direct_streambuf<T, Tr>::int_type 
direct_streambuf<T, Tr>::overflow(int_type c)
{
    using namespace std;
    if (!obeg_)
        qsboost::throw_exception(QSBOOST_IOSTREAMS_FAILURE("no write access"));
    if (!pptr()) init_put_area();
    if (!traits_type::eq_int_type(c, traits_type::eof())) {
        if (pptr() == oend_)
            qsboost::throw_exception(
                QSBOOST_IOSTREAMS_FAILURE("write area exhausted")
            );
        *pptr() = traits_type::to_char_type(c);
        pbump(1);
        return c;
    }
    return traits_type::not_eof(c);
}

template<typename T, typename Tr>
inline typename direct_streambuf<T, Tr>::pos_type
direct_streambuf<T, Tr>::seekoff
    (off_type off, QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which)
{ return seek_impl(off, way, which); }

template<typename T, typename Tr>
inline typename direct_streambuf<T, Tr>::pos_type
direct_streambuf<T, Tr>::seekpos
    (pos_type sp, QSBOOST_IOS::openmode which)
{ 
    return seek_impl(position_to_offset(sp), QSBOOST_IOS::beg, which);
}

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::close_impl(QSBOOST_IOS::openmode which)
{
    if (which == QSBOOST_IOS::in && ibeg_ != 0) {
        setg(0, 0, 0);
        ibeg_ = iend_ = 0;
    }
    if (which == QSBOOST_IOS::out && obeg_ != 0) {
        sync();
        setp(0, 0);
        obeg_ = oend_ = 0;
    }
    qsboost::iostreams::close(*storage_, which);
}

template<typename T, typename Tr>
typename direct_streambuf<T, Tr>::pos_type direct_streambuf<T, Tr>::seek_impl
    (stream_offset off, QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which)
{
    using namespace std;
    QSBOOST_IOS::openmode both = QSBOOST_IOS::in | QSBOOST_IOS::out;
    if (two_head() && (which & both) == both)
        qsboost::throw_exception(bad_seek());
    stream_offset result = -1;
    bool one = one_head();
    if (one && (pptr() != 0 || gptr()== 0))
        init_get_area(); // Switch to input mode, for code reuse.
    if (one || ((which & QSBOOST_IOS::in) != 0 && ibeg_ != 0)) {
        if (!gptr()) setg(ibeg_, ibeg_, iend_);
        ptrdiff_t next = 0;
        switch (way) {
        case QSBOOST_IOS::beg: next = off; break;
        case QSBOOST_IOS::cur: next = (gptr() - ibeg_) + off; break;
        case QSBOOST_IOS::end: next = (iend_ - ibeg_) + off; break;
        default: QSBOOST_ASSERT(0);
        }
        if (next < 0 || next > (iend_ - ibeg_))
            qsboost::throw_exception(bad_seek());
        setg(ibeg_, ibeg_ + next, iend_);
        result = next;
    }
    if (!one && (which & QSBOOST_IOS::out) != 0 && obeg_ != 0) {
        if (!pptr()) setp(obeg_, oend_);
        ptrdiff_t next = 0;
        switch (way) {
        case QSBOOST_IOS::beg: next = off; break;
        case QSBOOST_IOS::cur: next = (pptr() - obeg_) + off; break;
        case QSBOOST_IOS::end: next = (oend_ - obeg_) + off; break;
        default: QSBOOST_ASSERT(0);
        }
        if (next < 0 || next > (oend_ - obeg_))
            qsboost::throw_exception(bad_seek());
        pbump(static_cast<int>(next - (pptr() - obeg_)));
        result = next;
    }
    return offset_to_position(result);
}

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::init_input(input)
{
    std::pair<char_type*, char_type*> p = input_sequence(*storage_);
    ibeg_ = p.first;
    iend_ = p.second;
}

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::init_output(output)
{
    std::pair<char_type*, char_type*> p = output_sequence(*storage_);
    obeg_ = p.first;
    oend_ = p.second;
}

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::init_get_area()
{
    setg(ibeg_, ibeg_, iend_);
    if (one_head() && pptr()) {
        gbump(static_cast<int>(pptr() - obeg_));
        setp(0, 0);
    }
}

template<typename T, typename Tr>
void direct_streambuf<T, Tr>::init_put_area()
{
    setp(obeg_, oend_);
    if (one_head() && gptr()) {
        pbump(static_cast<int>(gptr() - ibeg_));
        setg(0, 0, 0);
    }
}

template<typename T, typename Tr>
inline bool direct_streambuf<T, Tr>::one_head() const
{ return ibeg_ && obeg_ && ibeg_ == obeg_; }

template<typename T, typename Tr>
inline bool direct_streambuf<T, Tr>::two_head() const
{ return ibeg_ && obeg_ && ibeg_ != obeg_; }

//----------------------------------------------------------------------------//

} // End namespace detail.

} } // End namespaces iostreams, boost.

#include <qsboost/iostreams/detail/config/enable_warnings.hpp> // MSVC

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_DIRECT_STREAMBUF_HPP_INCLUDED
