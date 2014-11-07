/*
 * FreeBondRotateChasse.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef FREEBONDROTATECHASSE_H_
#define FREEBONDROTATECHASSE_H_

#include <quickstep/Chasse.h>

#include <vector>

using namespace std;

namespace quickstep {

class FreeBondRotateChasse: public Chasse {
public:
	FreeBondRotateChasse(float rotationMagnitude);
//	virtual ~FreeBondRotateChasse();

	bool step(KinematicForest&);

private:
	float rotationMagnitude;

	/// Indices of atoms following a rotatable bond
	vector<int> rotatableBonds;

	KinematicForest* cachedKinematicForest;

	void prepareRotatableBonds(KinematicForest&);
};

} /* namespace quickstep */

#endif /* FREEBONDROTATECHASSE_H_ */
