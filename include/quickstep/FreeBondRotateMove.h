/*
 * FreeBondRotateMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef FREEBONDROTATECHASSE_H_
#define FREEBONDROTATECHASSE_H_

#include <quickstep/Move.h>
#include <quickstep/units.h>

#include <vector>

namespace quickstep {

class FreeBondRotateMove: public Move {
public:
	FreeBondRotateMove(units::Angle rotationMagnitude);
//	virtual ~FreeBondRotateMove();

	bool step(KinematicForest&);

private:
	units::Angle rotationMagnitude;

	/// Indices of atoms following a rotatable bond
	std::vector<int> rotatableBonds;

	KinematicForest* cachedKinematicForest;

	void prepareRotatableBonds(KinematicForest&);
};

} /* namespace quickstep */

#endif /* FREEBONDROTATECHASSE_H_ */
