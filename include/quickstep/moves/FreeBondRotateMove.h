/*
 * FreeBondRotateMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef FREEBONDROTATEMOVE_H_
#define FREEBONDROTATEMOVE_H_

#include <quickstep/Move.h>
#include <quickstep/units.h>

#include <vector>

namespace quickstep {

class FreeBondRotateMove: public Move {
public:
	FreeBondRotateMove(units::Angle rotationMagnitude);
	~FreeBondRotateMove(){}

	MoveInfo step(KinematicForest&, bool suggest_only=false);
	void step_fractional(KinematicForest&, MoveInfo&, double fraction);

private:
	units::Angle rotationMagnitude;

	/// Indices of atoms following a rotatable bond
	std::vector<int> rotatableBonds;

	KinematicForest* cachedKinematicForest;

	void prepareRotatableBonds(KinematicForest&);
};


class FreeBondRotateMoveInfo: public SpecificMoveInfo
{
public:
	~FreeBondRotateMoveInfo(){}
	int bond_atom;
	double delta_value;
};

} /* namespace quickstep */

#endif /* FREEBONDROTATECHASSE_H_ */
