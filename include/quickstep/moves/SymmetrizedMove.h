#ifndef SYMMETRIZEDMOVE_H
#define SYMMETRIZEDMOVE_H

#include <quickstep/moves/Move.h>
#include "quickstep/MoveFactory.h"
#include <quickstep/MoveInfo.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/utils.h>

namespace quickstep {

class SymmetrizedMove: public Move {
public:

    class MoveGenerator: public MoveFactory::MoveGenerator {
    public:
        virtual std::vector<std::unique_ptr<Move>> operator()(const qsboost::property_tree::ptree &parameter_input,
                                                              Topology &topology,
                                                              const MoveCommonDefinitions &move_common_defs,
                                                              const std::vector<std::shared_ptr<MoveSettings>> &move_settings);

        // NOTE: the registrator variable must be explicitly defined in the .cpp file as well
        const static struct Registrator {
            Registrator() {
                MoveFactory::get().register_generator("SymmetrizedMove", std::make_unique<SymmetrizedMove::MoveGenerator>());
            }
        } registrator;
    };


	SymmetrizedMove(std::unique_ptr<Move> move);

	MoveInfo propose(KinematicForest&);

    virtual Eigen::Array<double, 2, 1> calc_log_bias_impl(const MoveInfo &move_info) const override;

    virtual void set_log_bias_delegate(Move *move);

private:

	std::unique_ptr<Move> child_move;
};

} /* namespace quickstep */

#endif /* SYMMETRIZEDMOVE_H */
