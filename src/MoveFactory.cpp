//
// Created by Wouter Boomsma on 3/5/15.
//

#include "quickstep/MoveFactory.h"

namespace quickstep {

MoveFactory &MoveFactory::get() {
    static MoveFactory instance;
    return instance;
}

void MoveFactory::register_generator(std::string name, std::unique_ptr<MoveFactory::MoveGenerator> generator) {
    generators.insert(std::make_pair(name, std::move(generator)));
}

bool MoveFactory::has_generator(std::string name) {
    return (generators.count(name) > 0);
}

MoveFactory::MoveGenerator &MoveFactory::at(const std::string &name) {
    return *generators.at(name).get();
}

const MoveFactory::MoveGenerator &MoveFactory::at(const std::string &name) const {
    return *generators.at(name).get();
}

}