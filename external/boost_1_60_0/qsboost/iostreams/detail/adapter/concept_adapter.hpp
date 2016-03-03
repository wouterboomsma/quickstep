// (C) Copyright 2008 CodeRage, LLC (turkanis at coderage dot com)
// (C) Copyright 2003-2007 Jonathan Turkanis
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt.)

// See http://www.boost.org/libs/iostreams for documentation.

#ifndef QSBOOST_IOSTREAMS_DETAIL_CONCEPT_ADAPTER_HPP_INCLUDED
#define QSBOOST_IOSTREAMS_DETAIL_CONCEPT_ADAPTER_HPP_INCLUDED

#include <qsboost/config.hpp>                             // SFINAE.
#include <qsboost/iostreams/concepts.hpp>
#include <qsboost/iostreams/categories.hpp>
#include <qsboost/iostreams/detail/adapter/non_blocking_adapter.hpp>
#include <qsboost/iostreams/detail/call_traits.hpp>
#include <qsboost/iostreams/detail/char_traits.hpp>
#include <qsboost/iostreams/detail/dispatch.hpp>
#include <qsboost/iostreams/detail/error.hpp>
#include <qsboost/iostreams/detail/streambuf.hpp>        // pubsync.
#include <qsboost/iostreams/detail/config/unreachable_return.hpp>
#include <qsboost/iostreams/device/null.hpp>
#include <qsboost/iostreams/traits.hpp>
#include <qsboost/iostreams/operations.hpp>
#include <qsboost/mpl/if.hpp>
#include <qsboost/static_assert.hpp>
#include <qsboost/throw_exception.hpp>

// Must come last.
#include <qsboost/iostreams/detail/config/disable_warnings.hpp>  // MSVC.


namespace qsboost { namespace iostreams { namespace detail {

template<typename Category> struct device_wrapper_impl;
template<typename Category> struct flt_wrapper_impl;

template<typename T>
class concept_adapter {
private:
    typedef typename detail::value_type<T>::type       value_type;
    typedef typename dispatch<T, input, output>::type  input_tag;
    typedef typename dispatch<T, output, input>::type  output_tag;
    typedef typename
            mpl::if_<
                is_device<T>,
                device_wrapper_impl<input_tag>,
                flt_wrapper_impl<input_tag>
            >::type                                    input_impl;
    typedef typename
            mpl::if_<
                is_device<T>,
                device_wrapper_impl<output_tag>,
                flt_wrapper_impl<output_tag>
            >::type                                    output_impl;
    typedef typename
            mpl::if_<
                is_device<T>,
                device_wrapper_impl<any_tag>,
                flt_wrapper_impl<any_tag>
            >::type                                    any_impl;
public:
    typedef typename char_type_of<T>::type             char_type;
    typedef typename category_of<T>::type              category;

    explicit concept_adapter(const reference_wrapper<T>& ref) : t_(ref.get())
    { QSBOOST_STATIC_ASSERT(is_std_io<T>::value); }
    explicit concept_adapter(const T& t) : t_(t)
    { QSBOOST_STATIC_ASSERT(!is_std_io<T>::value); }

    T& operator*() { return t_; }
    T* operator->() { return &t_; }

    std::streamsize read(char_type* s, std::streamsize n)
    { return this->read(s, n, (basic_null_source<char_type>*) 0); }

    template<typename Source>
    std::streamsize read(char_type* s, std::streamsize n, Source* src)
    { return input_impl::read(t_, src, s, n); }

    std::streamsize write(const char_type* s, std::streamsize n)
    { return this->write(s, n, (basic_null_sink<char_type>*) 0); }

    template<typename Sink>
    std::streamsize write(const char_type* s, std::streamsize n, Sink* snk)
    { return output_impl::write(t_, snk, s, n); }

    std::streampos seek( stream_offset off, QSBOOST_IOS::seekdir way,
                         QSBOOST_IOS::openmode which )
    { 
        return this->seek( off, way, which, 
                           (basic_null_device<char_type, seekable>*) 0); 
    }

    template<typename Device>
    std::streampos seek( stream_offset off, QSBOOST_IOS::seekdir way,
                         QSBOOST_IOS::openmode which, Device* dev )
    { return any_impl::seek(t_, dev, off, way, which); }

    void close(QSBOOST_IOS::openmode which)
    { this->close(which, (basic_null_device<char_type, seekable>*) 0); }

    template<typename Device>
    void close(QSBOOST_IOS::openmode which, Device* dev)
    { any_impl::close(t_, dev, which); }

    template<typename Device>
    bool flush( Device* dev )
    {
        bool result = any_impl::flush(t_, dev);
        if (dev && dev->QSBOOST_IOSTREAMS_PUBSYNC() == -1)
            result = false;
        return result;
    }

    template<typename Locale> // Avoid dependency on <locale>
    void imbue(const Locale& loc) { iostreams::imbue(t_, loc); }

    std::streamsize optimal_buffer_size() const
    { return iostreams::optimal_buffer_size(t_); }
public:
    concept_adapter& operator=(const concept_adapter&);
    value_type t_;
};

//------------------Specializations of device_wrapper_impl--------------------//

template<>
struct device_wrapper_impl<any_tag> {
    template<typename Device, typename Dummy>
    static std::streampos 
    seek( Device& dev, Dummy*, stream_offset off, 
          QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which )
    { 
        typedef typename category_of<Device>::type category;
        return seek(dev, off, way, which, category()); 
    }

    template<typename Device>
    static std::streampos 
    seek( Device&, stream_offset, QSBOOST_IOS::seekdir, 
          QSBOOST_IOS::openmode, any_tag )
    { 
        qsboost::throw_exception(cant_seek());
        QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(0)
    }

    template<typename Device>
    static std::streampos 
    seek( Device& dev, stream_offset off, 
          QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which, 
          random_access )
    { 
        return iostreams::seek(dev, off, way, which); 
    }

    template<typename Device, typename Dummy>
    static void close(Device& dev, Dummy*, QSBOOST_IOS::openmode which)
    { iostreams::close(dev, which); }

    template<typename Device, typename Dummy>
    static bool flush(Device& dev, Dummy*)
    { return iostreams::flush(dev); }
};


template<>
struct device_wrapper_impl<input> : device_wrapper_impl<any_tag>  {
    template<typename Device, typename Dummy>
    static std::streamsize
    read( Device& dev, Dummy*, typename char_type_of<Device>::type* s,
          std::streamsize n )
    { return iostreams::read(dev, s, n); }

    template<typename Device, typename Dummy>
    static std::streamsize 
    write( Device&, Dummy*, const typename char_type_of<Device>::type*,
           std::streamsize )
    { qsboost::throw_exception(cant_write());
      QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(0) }
};

template<>
struct device_wrapper_impl<output> {
    template<typename Device, typename Dummy>
    static std::streamsize
    read(Device&, Dummy*, typename char_type_of<Device>::type*, std::streamsize)
    { qsboost::throw_exception(cant_read());
      QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(0) }

    template<typename Device, typename Dummy>
    static std::streamsize 
    write( Device& dev, Dummy*, const typename char_type_of<Device>::type* s,
           std::streamsize n )
    { return iostreams::write(dev, s, n); }
};

//------------------Specializations of flt_wrapper_impl--------------------//

template<>
struct flt_wrapper_impl<any_tag> {
    template<typename Filter, typename Device>
    static std::streampos
    seek( Filter& f, Device* dev, stream_offset off,
          QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which )
    {
        typedef typename category_of<Filter>::type category;
        return seek(f, dev, off, way, which, category());
    }

    template<typename Filter, typename Device>
    static std::streampos
    seek( Filter&, Device*, stream_offset,
          QSBOOST_IOS::seekdir, QSBOOST_IOS::openmode, any_tag )
    { qsboost::throw_exception(cant_seek());
      QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(0) }

    template<typename Filter, typename Device>
    static std::streampos
    seek( Filter& f, Device* dev, stream_offset off,
          QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which,
          random_access tag )
    {
        typedef typename category_of<Filter>::type category;
        return seek(f, dev, off, way, which, tag, category());
    }

    template<typename Filter, typename Device>
    static std::streampos
    seek( Filter& f, Device* dev, stream_offset off,
          QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode,
          random_access, any_tag )
    { return f.seek(*dev, off, way); }

    template<typename Filter, typename Device>
    static std::streampos
    seek( Filter& f, Device* dev, stream_offset off,
          QSBOOST_IOS::seekdir way, QSBOOST_IOS::openmode which,
          random_access, two_sequence )
    { return f.seek(*dev, off, way, which);  }

    template<typename Filter, typename Device>
    static void close(Filter& f, Device* dev, QSBOOST_IOS::openmode which)
    { iostreams::close(f, *dev, which); }

    template<typename Filter, typename Device>
    static bool flush(Filter& f, Device* dev)
    { return iostreams::flush(f, *dev); }
};

template<>
struct flt_wrapper_impl<input> {
    template<typename Filter, typename Source>
    static std::streamsize
    read( Filter& f, Source* src, typename char_type_of<Filter>::type* s,
          std::streamsize n )
    { return iostreams::read(f, *src, s, n); }

    template<typename Filter, typename Sink>
    static std::streamsize 
    write( Filter&, Sink*, const typename char_type_of<Filter>::type*, 
           std::streamsize )
    { qsboost::throw_exception(cant_write());
      QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(0) }
};

template<>
struct flt_wrapper_impl<output> {
    template<typename Filter, typename Source>
    static std::streamsize
    read(Filter&, Source*, typename char_type_of<Filter>::type*,std::streamsize)
    { qsboost::throw_exception(cant_read());
      QSBOOST_IOSTREAMS_UNREACHABLE_RETURN(0) }

    template<typename Filter, typename Sink>
    static std::streamsize 
    write( Filter& f, Sink* snk, const typename char_type_of<Filter>::type* s,
           std::streamsize n )
    { return iostreams::write(f, *snk, s, n); }
};

//----------------------------------------------------------------------------//

} } } // End namespaces detail, iostreams, boost.

#include <qsboost/iostreams/detail/config/enable_warnings.hpp>  // MSVC.

#endif // #ifndef BOOST_IOSTREAMS_DETAIL_CONCEPT_ADAPTER_HPP_INCLUDED