#ifndef QUICKSTEP_REFERENCE_KERNEL_FACTORY_H
#define QUICKSTEP_REFERENCE_KERNEL_FACTORY_H

#include <ReferenceGaussianMoveKernel.h>
#include "quickstep/platforms/ReferencePlatform.h"

#include "ReferenceKinematicForestKernel.h"

using namespace quickstep;

extern "C" void quickstep_register_reference_kernels(Platform &platform) {
    platform.register_kernel<ReferenceKinematicForestKernel>();
    platform.register_kernel<ReferenceGaussianMoveKernel>();
}

#endif
