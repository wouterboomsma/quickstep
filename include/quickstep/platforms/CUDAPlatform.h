#ifndef QUICKSTEP_CUDA_PLATFORM_H
#define QUICKSTEP_CUDA_PLATFORM_H

#include "quickstep/Platform.h"

namespace quickstep {

class CUDAPlatform: public Platform {
public:

    static CUDAPlatform &get() {
        static CUDAPlatform instance;
        return instance;
    }

private:

    // Private constructor (this is a singleton)
    CUDAPlatform(){};

    // Delete copy and assign operators
    CUDAPlatform(const CUDAPlatform &) = delete;
    CUDAPlatform &operator=(const CUDAPlatform &) = delete;

};

}

#endif // QUICKSTEP_CUDA_PLATFORM_H
