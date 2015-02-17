/*
 * FreeBondRotateMove.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef FREEBONDROTATECHASSE_H_
#define FREEBONDROTATECHASSE_H_

#include <quickstep/Move.h>

#include <vector>

namespace quickstep {

class FreeBondRotateMove: public Move {
public:
	FreeBondRotateMove(float rotationMagnitude);
//	virtual ~FreeBondRotateMove();

	bool step(KinematicForest&);

private:
	float rotationMagnitude;

	/// Indices of atoms following a rotatable bond
	std::vector<int> rotatableBonds;

	KinematicForest* cachedKinematicForest;

	void prepareRotatableBonds(KinematicForest&);
};

} /* namespace quickstep */

#endif /* FREEBONDROTATECHASSE_H_ */
