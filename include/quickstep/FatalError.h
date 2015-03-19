#ifndef QUICKSTEP_FATALERROR_H_
#define QUICKSTEP_FATALERROR_H_

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>

namespace quickstep {

//! Boost exception with additional simple message interface
//! Usage:
//!     BOOST_THROW_EXCEPTION(value_error() << "message");
//! It is also possible to add any additional information,
//! using boost::error_info:
//!     BOOST_THROW_EXCEPTION(value_error() << "message" << boost::errinfo_file_name("data.txt"));
class FatalError: public virtual std::exception, public virtual boost::exception {
public:
     typedef boost::error_info<struct message, std::string> message_info;

     virtual const char* what() const throw()  {
          // if (std::string const * mi=boost::get_error_info<fatal_error::message_info>(*this) ) {
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
            boost::exception(other),
            message_stream(other.message_stream.str()),
            prefix(other.prefix),
            suffix(other.suffix) {
     }

     FatalError& operator<<( const std::string& s)
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
