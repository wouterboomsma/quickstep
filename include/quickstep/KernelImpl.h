#ifndef QUICKSTEP_KERNEL_IMPL_H
#define QUICKSTEP_KERNEL_IMPL_H

#include <memory>
#include <iostream>

namespace quickstep {

class KernelImpl {
public:

    virtual ~KernelImpl(){}

    //template <typename PlatformType, typename Derived>
    //struct Registrar {
    //    explicit Registrar() {
    //        PlatformType::get().add_kernel_factory(Derived::Name(),
    //                                               [](){ std::make_unique<Derived>(); });
    //        std::cout << "Registering: " << Derived::Name() << "\n";
    //    }
    //};



};

}

#endif // QUICKSTEP_KERNEL_IMPL_H
