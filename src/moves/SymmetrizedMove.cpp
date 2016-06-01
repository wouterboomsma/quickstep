#include "quickstep/moves/SymmetrizedMove.h"

#include <memory>
#include <assert.h>
#include <iostream>

#include <qsboost/property_tree/ptree.hpp>

#include "quickstep/random.h"

namespace quickstep {

// Register move generator with factory
const SymmetrizedMove::MoveGenerator::Registrator SymmetrizedMove::MoveGenerator::registrator;

std::vector<std::unique_ptr<Move>> SymmetrizedMove::MoveGenerator::operator()(const qsboost::property_tree::ptree &parameter_input,
                                                                              Topology &topology,
                                                                              const MoveCommonDefinitions &move_common_defs,
                                                                              const std::vector<std::shared_ptr<MoveSettings>> &move_settings) {
    auto root_node = parameter_input.begin();
    const std::string &node_name = root_node->first;

    if (MoveFactory::get().has_generator(node_name)) {
        qsboost::optional<double> child_total_weight_attr = root_node->second.begin()->second.get_optional<double>("weight");
        double child_weight = 1.0;
        if (child_total_weight_attr)
            child_weight = *child_total_weight_attr;
        auto &&child_moves = MoveFactory::get().at(node_name)(root_node->second, topology, move_common_defs, move_settings);

        if (child_moves.size() == 0)
            return {};

        assert(child_moves.size() == 1);

        std::unique_ptr<Move> child_move = std::move(child_moves.front());
        std::unique_ptr<Move> move(std::make_unique<SymmetrizedMove>(std::move(child_move)));
        std::vector<std::unique_ptr<Move>> return_value;
        return_value.push_back(std::move(move));
        return return_value;
    } else {
        QSBOOST_THROW_EXCEPTION(FatalError() <<
                                "No MoveGenerator found for : " << node_name);
    }
}

SymmetrizedMove::SymmetrizedMove(std::unique_ptr<Move> m):
		child_move(std::move(m)) {

    // Override the bias of the child move
    child_move->set_log_bias_delegate(this);

}

MoveInfo SymmetrizedMove::propose(KinematicForest& kf) {
	auto move_info = child_move->propose(kf);

    // With 50% change, reverse the direction of the move
	if (uniform_01_distribution() < 0.5) {
        for (auto &dof_delta: move_info.dof_deltas) {
            dof_delta.second *= -1;
        }
    }

	return move_info;
}

Eigen::Array<double, 2, 1> SymmetrizedMove::calc_log_bias_impl(const MoveInfo &move_info) const {
    // The symmetrized move has bias zero by construction
    return Eigen::Array<double, 2, 1>(0.,0.);
}

void SymmetrizedMove::set_log_bias_delegate(Move *move) {
    // No-Op: Ignore any requests by parent containers to delegate the bias calculation of this move
}

} /* namespace quickstep */
