#ifndef QUICKSTEP_KERNEL_H
#define QUICKSTEP_KERNEL_H

#include <memory>
#include "quickstep/KernelImpl.h"

namespace quickstep {

class Kernel {
public:
    Kernel();

    Kernel(std::unique_ptr<KernelImpl> &&impl);

    template <class T>
    const T& get_as() const {
        return dynamic_cast<T&>(*impl);
    }

    template <class T>
    T& get_as() {
        return dynamic_cast<T&>(*impl);
    }

private:
    std::unique_ptr<KernelImpl> impl;
};

}

#endif // QUICKSTEP_KERNEL_H
