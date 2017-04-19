#ifndef QUICKSTEP_GAUSSIAN_MOVE_KERNEL_H
#define QUICKSTEP_GAUSSIAN_MOVE_KERNEL_H

#include <string>
#include "quickstep/KernelImpl.h"

namespace quickstep {

class GaussianMove;

class GaussianMoveKernel: public KernelImpl {
public:
    static const std::string Name() {
        return "GaussianMove";
    }

    virtual void initialize(const GaussianMove& move) = 0;

};

}

#endif // QUICKSTEP_GAUSSIAN_MOVE_KERNEL_H
