/*
 * FreeBondRotateMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef FREEBONDROTATEMOVE_H_
#define FREEBONDROTATEMOVE_H_

#include <quickstep/moves/Move.h>
#include <quickstep/units.h>

#include <vector>

namespace quickstep {

class FreeBondRotateMove: public Move {
public:
	FreeBondRotateMove(units::Angle rotationMagnitude);
	~FreeBondRotateMove(){}

	MoveInfo propose(KinematicForest&);
//	void step_fractional(KinematicForest&, MoveInfo&, double fraction);

private:
	units::Angle rotationMagnitude;

//	/// Indices of atoms following a rotatable bond
//	std::vector<int> rotatableBonds;
	std::vector<int> rotatable_bonds;

	KinematicForest* last_used_forest;

	void prepareRotatableBonds(KinematicForest&);
};


//class FreeBondRotateMoveInfo: public SpecificMoveInfo
//{
//public:
//	~FreeBondRotateMoveInfo(){}
//	int bond_atom;
//	double delta_value;
//};

} /* namespace quickstep */

#endif /* FREEBONDROTATECHASSE_H_ */
