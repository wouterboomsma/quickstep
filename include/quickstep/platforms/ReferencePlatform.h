#ifndef QUICKSTEP_REFERENCE_PLATFORM_H
#define QUICKSTEP_REFERENCE_PLATFORM_H

#include "quickstep/Platform.h"

extern "C" void quickstep_register_reference_kernels(quickstep::Platform &platform);

namespace quickstep {

class ReferencePlatform: public Platform {
public:

    static ReferencePlatform &get() {
        static ReferencePlatform instance;
        quickstep_register_reference_kernels(instance);
        return instance;
    }

private:

    // Private constructor (this is a singleton)
    ReferencePlatform(){};

    // Delete copy and assign operators
    ReferencePlatform(const ReferencePlatform &) = delete;
    ReferencePlatform &operator=(const ReferencePlatform &) = delete;

};

}

#endif // QUICKSTEP_REFERENCE_PLATFORM_H
