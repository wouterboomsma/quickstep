/*
 * MoveInfo.h
 *
 *  Created on: 23/04/2015
 *      Author: rfonseca
 */

#ifndef EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_
#define EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_

#include <list>
#include <quickstep/dofs/Dof.h>
#include <utility> //pair

#include "quickstep/KinematicForest.h"

namespace quickstep{

class Move;
//struct SubTree{
//	int root_atom;
//	std::list<int> excluded_atoms;
//};

//class SpecificMoveInfo{
//public:
//	virtual ~SpecificMoveInfo();
//};


class MoveInfo {
public:
    MoveInfo(const Move &move, const KinematicForest &forest)
            : move(move) {} //, forest(forest) {}
    //MoveInfo(MoveInfo &&other)
    //        //: dof_deltas(other.dof_deltas),
    //        : dof_deltas(std::move(other.dof_deltas)),
    //          //forest(other.forest),
    //          move(std::move(other.move)){}
    //MoveInfo(const MoveInfo &other)
    //        //: dof_deltas(other.dof_deltas),
    //        : dof_deltas(other.dof_deltas),
    //          //forest(other.forest),
    //          move(other.move){}
    MoveInfo(const MoveInfo &other):
            dof_deltas(other.dof_deltas),
            move(other.move){}
    //operator=(const MoveInfo &other):
    //        dof_deltas(other.dof_deltas),
    //        move(other.move){}

    const Move &get_move() const {
        return move.get();
    }
//	MoveInfo(std::unique_ptr<SpecificMoveInfo>&& smi);
//	std::unique_ptr<SpecificMoveInfo> specific_info;
//	std::list<SubTree> affected_atoms;
//    std::list< std::pair<DOFIndex, double> > dof_deltas;

    //std::vector<std::list<std::pair<double, std::vector<int> > > > dof_deltas2;
    std::vector<std::pair<std::shared_ptr<Dof>, double> > dof_deltas;
    //std::reference_wrapper<const KinematicForest> forest;  // Ended up including forest here, to make information retrieval possible in calc_log_bias
private:
    std::reference_wrapper<const Move> move;
};

}

#endif /* EXTERNAL_QUICKSTEP_INCLUDE_QUICKSTEP_MOVEINFO_H_ */
