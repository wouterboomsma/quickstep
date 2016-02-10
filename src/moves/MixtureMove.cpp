#include "quickstep/moves/MixtureMove.h"

namespace quickstep {

// Register move generator with factory
const MixtureMove::MoveGenerator::Registrator MixtureMove::MoveGenerator::registrator;

std::vector<std::unique_ptr<Move>> MixtureMove::MoveGenerator::operator()(const qsboost::property_tree::ptree &parameter_input,
																		  Topology &topology,
																		  const MoveParameters &move_parameters) {
    auto return_value = CompositeMove::MoveGenerator::operator()(parameter_input,
                                                                 topology,
                                                                 move_parameters);
    if (return_value.empty())
        return std::move(return_value);

    // Composite move is expected to return a vector with one element
    assert(return_value.size()==1);
    std::unique_ptr<CompositeMove> composite_move(dynamic_cast<CompositeMove*>(return_value.front().release()));
    //CompositeMove *composite_move = dynamic_cast<CompositeMove*>(return_value.front().get());
    //MixtureMove m(std::move(composite_move));
    //std::unique_ptr<Move> mixture_move = std::make_unique<MixtureMove>(*composite_move.release());
    std::unique_ptr<MixtureMove> mixture_move = std::make_unique<MixtureMove>(std::move(*composite_move.release()));
    for (auto &move:mixture_move->get_moves()) {
        move->set_log_bias_delegate(mixture_move.get());
    }
    return_value.front() = std::move(mixture_move);
    return std::move(return_value);
    //return {std::move(mixture_move)};
}

MoveInfo MixtureMove::propose(KinematicForest &kf) {
    return CompositeMove::propose(kf);
}

Eigen::Array<double, 2, 1> MixtureMove::calc_log_bias_impl(const MoveInfo &move_info) const {

    Eigen::Array<double, 2, 1> likelihood = Eigen::Array<double, 2, 1>::Zero();
    Eigen::Array<double, Eigen::Dynamic, 1> weights =
            Eigen::Array<double, Eigen::Dynamic, 1>::Map(this->accum_weights.data(), this->accum_weights.size());
    //std::cout << "weights before: " << weights << "\n";
    weights.bottomRows(weights.rows()-1) -= weights.topRows(weights.rows()-1);
    //std::cout << "weights after1: " << weights << "\n";
    weights /= weights.sum();
    //std::cout << "weights after2: " << weights << "\n";
    //Eigen::VectorXd
    for (int i=0; i<weights.size(); ++i) {
        likelihood += weights[i]*this->moves[i]->calc_log_bias_impl(move_info).exp();
    }
    return likelihood.log();
}
} /* namespace quickstep */
