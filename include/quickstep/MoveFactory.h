#ifndef QUICKSTEP_MOVEFACTORY_H
#define QUICKSTEP_MOVEFACTORY_H

#include <qsboost/property_tree/ptree_fwd.hpp>
#include <vector>
#include "quickstep/utils.h"
#include "quickstep/MoveSettings.h"

namespace quickstep {

class Move;
class MoveCommonDefinitions;
class Topology;

class MoveFactory {
public:

    class MoveGenerator {
    public:
        virtual std::vector<std::unique_ptr<Move>> operator()(const qsboost::property_tree::ptree &parameter_input,
                                                              Topology &topology,
                                                              const MoveCommonDefinitions &move_common_defs,
                                                              const std::vector<std::shared_ptr<MoveSettings>> &move_settings) = 0;
    };

    void register_generator(std::string name, std::unique_ptr<MoveGenerator> generator);

    bool has_generator(std::string name);

    static MoveFactory &get();

    MoveGenerator &at(const std::string &name);

    const MoveGenerator &at(const std::string &name) const;

private:

    std::map<std::string, std::unique_ptr<MoveGenerator> > generators;

    // Private constructor (this is a singleton)
    MoveFactory() = default;

    // Delete copy and assign operators
    MoveFactory(const MoveFactory &) = delete;

    MoveFactory &operator=(const MoveFactory &) = delete;

};

}

#endif // QUICKSTEP_MOVEFACTORY_H
