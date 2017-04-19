/*
 * MoveInfo.h
 *
 *  Created on: 23/04/2015
 *      Author: rfonseca
 */

#ifndef QUICKSTEP_MOVE_INFO_H_
#define QUICKSTEP_MOVE_INFO_H_

#include <list>
#include <quickstep/dofs/Dof.h>
#include <utility>

namespace quickstep{

class Move;
class KinematicForest;
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
            : move(move),
              early_reject(false){} //, forest(forest) {}
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
            move(other.move),
            early_reject(other.early_reject) {}
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

    // A move can decide that a move should be rejected by setting this flag
    bool early_reject;
    //std::reference_wrapper<const KinematicForest> forest;  // Ended up including forest here, to make information retrieval possible in calc_log_bias
private:
    std::reference_wrapper<const Move> move;
};

}

#endif
