#ifndef QUICKSTEP_GAUSSIAN_ABSOLUTE_MOVE_H
#define QUICKSTEP_GAUSSIAN_ABSOLUTE_MOVE_H

#include <qsboost/property_tree/ptree_fwd.hpp>

#include "quickstep/moves/Move.h"
#include "quickstep/MoveFactory.h"
#include "quickstep/dofs/Dof.h"
#include "quickstep/Kernel.h"

namespace quickstep {

class MoveCommonDefinitions;

class GaussianAbsoluteMove: public Move {
public:

    // Base class for Settings in energy terms
    const class Settings: public MoveSettings {
    public:

        // Minimum step size (sizes below this will have infinite bias)
        double minimum_delta;

        Settings(double minimum_delta = 0.)
          : minimum_delta(minimum_delta) {}
    } settings;

    class MoveGenerator: public MoveFactory::MoveGenerator {
    public:
        virtual std::vector<std::unique_ptr<Move>> operator()(const qsboost::property_tree::ptree &parameter_input,
                                                              Topology &topology,
                                                              const MoveCommonDefinitions &move_common_defs,
                                                              const std::vector<std::shared_ptr<MoveSettings>> &move_settings);

        // NOTE: the registrator variable must be explicitly defined in the .cpp file as well
        const static struct Registrator {
            Registrator() {
                MoveFactory::get().register_generator("GaussianAbsoluteMove", std::make_unique<GaussianAbsoluteMove::MoveGenerator>());
            }
        } registrator;
    };

    GaussianAbsoluteMove(const Eigen::VectorXd &mu, const Eigen::MatrixXd &cov,
                 std::vector<std::vector<int>> &dof_atoms,
                 std::vector<std::vector<std::string>> &dof_atom_names,
                 const Settings &settings = Settings());


    virtual void initialize(const Platform &platform);

    virtual MoveInfo propose(KinematicForest &forest);

//    virtual void step_fractional(KinematicForest&, MoveInfo&, double fraction);




    virtual Eigen::Array<double, 2, 1> calc_log_bias_impl(const MoveInfo &move_info) const override;

private:
    Kernel kernel;

    Eigen::VectorXd mean;
    Eigen::MatrixXd inverse_cov;
    Eigen::MatrixXd sampling_transform;

    //Eigen::VectorXd old_value;
    //Eigen::VectorXd new_value;

    std::vector<std::vector<int>> dof_atoms;
    std::vector<std::vector<std::string>> dof_atom_names;
    std::vector<std::shared_ptr<Dof>> dofs;

    //KinematicForest& last_used_forest;
};


//class GaussianMoveInfo: public SpecificMoveInfo
//{
//public:
//	GaussianMoveInfo(Eigen::VectorXd &s): sample(s){}
//	~GaussianMoveInfo(){}
//	Eigen::VectorXd sample;
//};


}

#endif // QUICKSTEP_GAUSSIAN_ABSOLUTE_MOVE_H
