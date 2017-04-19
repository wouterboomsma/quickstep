#ifndef QUICKSTEP_REFERENCE_GAUSSIAN_MOVE_KERNEL_H
#define QUICKSTEP_REFERENCE_GAUSSIAN_MOVE_KERNEL_H

#include "quickstep/moves/GaussianMoveKernel.h"

namespace quickstep {

class GaussianMove;

class ReferenceGaussianMoveKernel: public GaussianMoveKernel {
public:

    void initialize(const GaussianMove &move);
};

}

#endif // QUICKSTEP_REFERENCE_GAUSSIAN_MOVE_KERNEL_H
