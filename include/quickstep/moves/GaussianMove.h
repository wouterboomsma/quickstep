#ifndef QUICKSTEP_GAUSSIANMOVE_H
#define QUICKSTEP_GAUSSIANMOVE_H

#include "quickstep/moves/Move.h"
#include "quickstep/MoveFactory.h"
#include <boost/property_tree/ptree_fwd.hpp>

namespace quickstep {

class MoveParameters;

class GaussianMove: public Move {
public:

    class MoveGenerator: public MoveFactory::MoveGenerator {
    public:
        virtual std::vector<std::unique_ptr<Move>> operator()(const boost::property_tree::ptree &parameter_input,
                                                              Topology &topology,
                                                              const MoveParameters &move_parameters);

        // NOTE: the registrator variable must be explicitly defined in the .cpp file as well
        const static struct Registrator {
            Registrator() {
                MoveFactory::get().register_generator("GaussianMove", make_unique<GaussianMove::MoveGenerator>());
            }
        } registrator;
    };

    GaussianMove(const Eigen::VectorXd &mu, const Eigen::MatrixXd &cov,
                 std::vector<std::vector<int>> &dof_atoms,
                 std::vector<std::vector<std::string>> &dof_atom_names);


    virtual MoveInfo step(KinematicForest &forest, bool suggest_only=false);

    virtual void step_fractional(KinematicForest&, MoveInfo&, double fraction);


private:
    Eigen::MatrixXd mean;
    Eigen::MatrixXd sampling_transform;

    std::vector<std::vector<int>> dof_atoms;
    std::vector<std::vector<std::string>> dof_atom_names;
    std::vector<std::unique_ptr<KinematicForest::DoF>> dofs;
};

}

#endif // QUICKSTEP_GAUSSIANMOVE_H