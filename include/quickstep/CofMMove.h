/*
 * CofMMove.h
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#ifndef COFMCHASSE_H_
#define COFMCHASSE_H_

#include <quickstep/Move.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/math/primitives.h>

#include <vector>

namespace quickstep {

/**
 * A chassé that picks a random chain and performs a translation and rotation around the
 * chains center-of-mass.
 */
class CofMMove: public Move{
public:
	/**
	 * Construct the chassé. The \a translationMagnitude indicates the largest possible
	 * translation performed and the \a rotationMagnitude indicates the largest possible
	 * rotation-angle (in radians) around the center-of-mass.
	 */
	CofMMove(units::Length translationMagnitude, units::Angle rotationMagnitude);
//	virtual ~CofMMove();

	/**
	 * Perform a conformational move of the kinematic forest that translates and rotates
	 * the kinematic forest.
	 */
	bool step(KinematicForest&);

private:
	units::Length translationMagnitude;
	units::Angle rotationMagnitude;

	/** Each entry is a vector containing indices of all atoms in the corresponding chain. */
	std::vector< std::vector<int> > chainIndices;

	/** If this reference does not match the one passed to step then chainIndices will be
	 * recomputed. */
	KinematicForest* cachedKinematicForest;

	void prepareChainIndices(KinematicForest&);

	/** Changes \a M so it contains a rotation matrix that uniformly rotates points
	 *  in such a way that the largest possible rotation of any point around the origin
	 *  is \a amplitude. */
	void randRotation( units::Angle amplitude, Eigen::Transform<units::Length, 3, Eigen::Affine> &M );
//	void randRotation(float amplitude, Math3D::Matrix3 &M);

	/** Changes \a v to a random direction with length at most \a amplitude. */
	void randTranslation( units::Length amplitude, Eigen::Transform<units::Length, 3, Eigen::Affine> &M );
//	void randTranslation( float amplitude, Math3D::Vector3 &v );

};

} /* namespace quickstep */

#endif /* COFMCHASSE_H_ */
