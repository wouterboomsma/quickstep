#include "quickstep/Kernel.h"

namespace quickstep {

quickstep::Kernel::Kernel()
        : impl(nullptr) {

}

Kernel::Kernel(std::unique_ptr<KernelImpl> &&impl)
        : impl(std::move(impl)) {
}

}


