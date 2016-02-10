/*
 * StdDoFMove.cpp
 *
 *  Created on: Jan. 21, 2015
 *      Author: rfonseca
 */

#include <quickstep/moves/StdDoFMove.h>
#include <quickstep/FatalError.h>

#include <vector>
#include <qsboost/algorithm/string.hpp>
#include <quickstep/dofs/Dof.h>
#include "quickstep/utils.h"

namespace quickstep {

// "N-CA-C-N,C-N-CA-C,CA-C,N-CA-C"

StdDoFMove::StdDoFMove(std::string dofs, double std):
		dofs(dofs),
		std_deviation(std)

{
}

MoveInfo StdDoFMove::propose(KinematicForest& kf) {
    if (!dof_controller || dof_controller->kinematic_forest != &kf) {
        std::vector<std::string> dof_tokens;
        qsboost::split(dof_tokens, dofs, qsboost::is_any_of(","));
        dof_controller = std::make_unique<StdDoFController>(kf, dof_tokens);
        if (dof_controller->numberOfDoFs() == 0) {
            QSBOOST_THROW_EXCEPTION(FatalError() <<
                                    "DOF specification (" << dofs << ") resulted in 0 actual DOFs");
        }
    }

    int dof_num = dof_controller->numberOfDoFs();
    int dof_idx = rand() % dof_num;
    double value = ((rand() / (double)RAND_MAX) - 0.5) * std_deviation;
//	units::Angle angle = ((rand()/RAND_MAX)-0.5)*2*3.1415/180.0 * units::rad;

    //if(!suggest_only)
    //	dof_controller->changeDoF(dof_idx, value);

    //MoveInfo ret{ make_unique<StdDoFMoveInfo>() };
    MoveInfo ret(*this, kf);

    //StdDoFMoveInfo& info = *dynamic_cast<StdDoFMoveInfo*>(ret.specific_info.get());
    //DOFIndex dof = {dof_controller->dof_atoms[dof_idx], dof_controller->dof_types[dof_idx]};
    int atom_index = dof_controller->dof_atoms[dof_idx];
    int dof_type = dof_controller->dof_types[dof_idx];
    std::vector<int> atoms(dof_type+1);
    atoms[0] = atom_index;
    int current_atom_index = atom_index;
    for (int i=1; i<dof_type+1; ++i) {
        current_atom_index = kf.get_parent(current_atom_index);
        atoms[i] = current_atom_index;
    }

    //info.index = dof;
    //info.std_dof_index = dof_idx;
    //info.delta_value = value;

    ret.dof_deltas.push_back(std::make_pair(Dof::construct(kf, atoms), value));

    //SubTree affected_tree;
    //affected_tree.root_atom = dof_controller->dof_atoms[dof_idx];
    //ret.affected_atoms.push_back(affected_tree);

    return ret;
}

//void StdDoFMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fraction)
//{
//	StdDoFMoveInfo& orig_info = *dynamic_cast<StdDoFMoveInfo*>(mi.specific_info.get());
//
//	int dof_idx = orig_info.std_dof_index;
//	double value = orig_info.delta_value*fraction;
//	dof_controller->changeDoF(dof_idx, value);
//}

} /* namespace quickstep */
