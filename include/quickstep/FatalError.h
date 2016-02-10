#ifndef QUICKSTEP_FATALERROR_H_
#define QUICKSTEP_FATALERROR_H_

#include <qsboost/exception/exception.hpp>
#include <qsboost/exception/info.hpp>

namespace quickstep {

//! Boost exception with additional simple message interface
//! Usage:
//!     BOOST_THROW_EXCEPTION(value_error() << "message");
//! It is also possible to add any additional information,
//! using qsboost::error_info:
//!     BOOST_THROW_EXCEPTION(value_error() << "message" << qsboost::errinfo_file_name("data.txt"));
class FatalError: public virtual std::exception, public virtual qsboost::exception {
public:
     typedef qsboost::error_info<struct message, std::string> message_info;

     virtual const char* what() const throw()  {
          // if (std::string const * mi=qsboost::get_error_info<fatal_error::message_info>(*this) ) {
          //      return mi->c_str();
          // }
          // return "";
          message_tmp = prefix + std::string(message_stream.str()) + suffix;
          return message_tmp.c_str();
     }


     FatalError(std::string prefix="", std::string suffix="")
          : message_stream(""),
            prefix(prefix),
            suffix(suffix) {
     }

     FatalError(const FatalError &other)
          : std::exception(other),
            qsboost::exception(other),
            message_stream(other.message_stream.str()),
            prefix(other.prefix),
            suffix(other.suffix) {
     }

     template <typename T>
     FatalError& operator<<( const T& s)
          {
               // *this << message_info(s);
               message_stream << s;
               return *this;
          }

     virtual ~FatalError() throw(){};

private:
     std::stringstream message_stream;
     mutable std::string message_tmp;

     const std::string prefix;
     const std::string suffix;
};

}

#endif /* FATALERROR_H_ */
