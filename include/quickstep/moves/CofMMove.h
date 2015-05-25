/*
 * CofMMove.h
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#ifndef COFMMOVE_H_
#define COFMMOVE_H_

#include <quickstep/moves/Move.h>
#include <quickstep/MoveInfo.h>
#include <quickstep/KinematicForest.h>
#include <quickstep/math/primitives.h>

#include <vector>

namespace quickstep {

class CofMMoveInfo; //Forward declaration


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
	~CofMMove(){}

	/**
	 * Perform a conformational move of the kinematic forest that translates and rotates
	 * the kinematic forest.
	 */
	MoveInfo step(KinematicForest&, bool suggest_only=false);
	void step_fractional(KinematicForest&, MoveInfo&, double);

private:
	units::Length translationMagnitude;
	units::Angle rotationMagnitude;

	/** Each entry is a vector containing indices of all atoms in the corresponding chain. */
	std::vector< std::vector<int> > chainIndices;

	/** If this reference does not match the one passed to step then chainIndices will be
	 * recomputed. */
	KinematicForest* cachedKinematicForest;

	void prepareChainIndices(KinematicForest&);

	/**
	 * Changes \a move_info so it contains info for a rotation matrix that uniformly rotates
	 * points in such a way that the largest possible rotation of any point around the origin
	 * is \a amplitude.
	 */
	void randRotation( units::Angle amplitude, CofMMoveInfo& move_info); //Eigen::Transform<units::Length, 3, Eigen::Affine> &M );

	/**
	 * Changes \a move_info so it contains info for a translation matrix that uniformly moves
	 * points in such a way that the largest possible displacement of any point is \a amplitude.
	 */
	void randTranslation( units::Length amplitude, CofMMoveInfo& move_info); //Eigen::Transform<units::Length, 3, Eigen::Affine> &M );

};


class CofMMoveInfo: public SpecificMoveInfo{
public:
	int root;
	units::Vector3L center_of_mass;
	units::Angle rotation_angle;
	units::Vector3L rotation_axis;
	units::Length translation_length;
	units::Vector3L translation_axis;


//	Eigen::Transform<units::Length, 3, Eigen::Affine> translation;
//	Eigen::Transform<units::Length, 3, Eigen::Affine> rotation;
};

} /* namespace quickstep */

#endif /* COFMCHASSE_H_ */
