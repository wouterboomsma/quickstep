#ifndef QUICKSTEP_CPU_PLATFORM_H
#define QUICKSTEP_CPU_PLATFORM_H

#include "quickstep/Platform.h"

namespace quickstep {

class CPUPlatform: public Platform {
public:

    static CPUPlatform &get() {
        static CPUPlatform instance;
        return instance;
    }

private:

    // Private constructor (this is a singleton)
    CPUPlatform(){};

    // Delete copy and assign operators
    CPUPlatform(const CPUPlatform &) = delete;
    CPUPlatform &operator=(const CPUPlatform &) = delete;

};

}

#endif // QUICKSTEP_CPU_PLATFORM_H
