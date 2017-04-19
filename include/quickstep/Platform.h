#ifndef QUICKSTEP_PLATFORM_H
#define QUICKSTEP_PLATFORM_H

#include <string>
#include <map>
#include <iostream>

#include "quickstep/Kernel.h"
#include "quickstep/KernelFactory.h"

namespace quickstep {

class Platform {
public:
    virtual ~Platform(){};

    template<typename KernelType>
    void register_kernel() {
        std::cout << "Registering: " << KernelType::Name() << "\n";
        kernel_factories.insert(std::make_pair(KernelType::Name(),
                                               [](){ return std::make_unique<KernelType>();}));
    };

    //virtual void add_kernel_factory(const std::string &name, const std::function<std::unique_ptr<KernelImpl>()> &kernel_factory) {
    //    kernel_factories.insert(std::make_pair(name, kernel_factory));
    //}

    virtual Kernel create_kernel(const std::string &name) const {
        return Kernel(std::move(kernel_factories.at(name)()));
    }

private:
    std::map<std::string, std::function<std::unique_ptr<KernelImpl>()>> kernel_factories;

};

}

#endif // QUICKSTEP_PLATFORM_H
