//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2002. 
//  (C) Copyright Jens Maurer 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

// locate which platform we are on and define BOOST_PLATFORM_CONFIG as needed.
// Note that we define the headers to include using "header_name" not
// <header_name> in order to prevent macro expansion within the header
// name (for example "linux" is a macro on linux systems).

#if (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
// linux, also other platforms (Hurd etc) that use GLIBC, should these really have their own config headers though?
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/linux.hpp"

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
// BSD:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/bsd.hpp"

#elif defined(sun) || defined(__sun)
// solaris:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/solaris.hpp"

#elif defined(__sgi)
// SGI Irix:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/irix.hpp"

#elif defined(__hpux)
// hp unix:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/hpux.hpp"

#elif defined(__CYGWIN__)
// cygwin is not win32:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/cygwin.hpp"

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
// win32:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/win32.hpp"

#elif defined(__HAIKU__)
// Haiku
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/haiku.hpp"

#elif defined(__BEOS__)
// BeOS
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/beos.hpp"

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
// MacOS
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/macos.hpp"

#elif defined(__IBMCPP__) || defined(_AIX)
// IBM
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/aix.hpp"

#elif defined(__amigaos__)
// AmigaOS
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/amigaos.hpp"

#elif defined(__QNXNTO__)
// QNX:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/qnxnto.hpp"

#elif defined(__VXWORKS__)
// vxWorks:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/vxworks.hpp"

#elif defined(__SYMBIAN32__) 
// Symbian: 
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/symbian.hpp" 

#elif defined(_CRAYC)
// Cray:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/cray.hpp" 

#elif defined(__VMS) 
// VMS:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/vms.hpp" 

#elif defined(__CloudABI__)
// Nuxi CloudABI:
#  define QSBOOST_PLATFORM_CONFIG "qsboost/config/platform/cloudabi.hpp"
#else

#  if defined(unix) \
      || defined(__unix) \
      || defined(_XOPEN_SOURCE) \
      || defined(_POSIX_SOURCE)

   // generic unix platform:

#  ifndef QSBOOST_HAS_UNISTD_H
#     define QSBOOST_HAS_UNISTD_H
#  endif

#  include <qsboost/config/posix_features.hpp>

#  endif

#  if defined (QSBOOST_ASSERT_CONFIG)
      // this must come last - generate an error if we don't
      // recognise the platform:
#     error "Unknown platform - please configure and report the results to boost.org"
#  endif

#endif

#if 0
//
// This section allows dependency scanners to find all the files we *might* include:
//
#  include "qsboost/config/platform/linux.hpp"
#  include "qsboost/config/platform/bsd.hpp"
#  include "qsboost/config/platform/solaris.hpp"
#  include "qsboost/config/platform/irix.hpp"
#  include "qsboost/config/platform/hpux.hpp"
#  include "qsboost/config/platform/cygwin.hpp"
#  include "qsboost/config/platform/win32.hpp"
#  include "qsboost/config/platform/beos.hpp"
#  include "qsboost/config/platform/macos.hpp"
#  include "qsboost/config/platform/aix.hpp"
#  include "qsboost/config/platform/amigaos.hpp"
#  include "qsboost/config/platform/qnxnto.hpp"
#  include "qsboost/config/platform/vxworks.hpp"
#  include "qsboost/config/platform/symbian.hpp" 
#  include "qsboost/config/platform/cray.hpp" 
#  include "qsboost/config/platform/vms.hpp" 
#  include <qsboost/config/posix_features.hpp>



#endif

