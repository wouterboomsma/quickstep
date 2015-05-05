/*
 * CofMMove.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#include <quickstep/CofMMove.h>

#include <quickstep/math/primitives.h>
#include "quickstep/units.h"
#include "quickstep/utils.h"

#include <stack>


namespace quickstep {

CofMMove::CofMMove(units::Length translationMagnitude_, units::Angle rotationMagnitude_):
		translationMagnitude(translationMagnitude_),
		rotationMagnitude(rotationMagnitude_),
		cachedKinematicForest(0)
{

}

MoveInfo CofMMove::step(KinematicForest& kf, bool suggest_only)
{
	MoveInfo ret{ make_unique<CofMMoveInfo>() };
	CofMMoveInfo& spec_info = *dynamic_cast<CofMMoveInfo*>(ret.specific_info.get());

	//Ensure that chainIndices is in sync with kf
	prepareChainIndices(kf);

	// Select random chain
	spec_info.root = (int)(rand()%kf.getRoots());

	// Suggest random translation
	randTranslation(translationMagnitude, spec_info);

	//Suggest random rotation
	randRotation(rotationMagnitude, spec_info);

	// Compute center-of-mass
	for(int a=0;a<chainIndices[spec_info.root].size();a++){
		spec_info.center_of_mass = spec_info.center_of_mass + kf.pos(chainIndices[spec_info.root][a]).matrix();
	}
	spec_info.center_of_mass = spec_info.center_of_mass / chainIndices[spec_info.root].size();

	// Suggest random rotation around center-of-mass
	if(!suggest_only){
		Eigen::Transform<units::Length, 3, Eigen::Affine> transform =
				Eigen::Translation<units::Length, 3>(spec_info.translation_axis * spec_info.translation_length.value()) *
				Eigen::Translation<units::Length, 3>( spec_info.center_of_mass) *
				Eigen::AngleAxis<units::Length>(spec_info.rotation_angle, spec_info.rotation_axis) *
				Eigen::Translation<units::Length, 3>(-spec_info.center_of_mass);
		kf.changeDOFglobal(spec_info.root, transform);
	}



	SubTree affected_tree;
	affected_tree.root_atom = kf.getRootAtomIndex(spec_info.root);
	ret.affected_atoms.push_back(affected_tree);

	return ret;
}

MoveInfo CofMMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fraction)
{
	CofMMoveInfo* orig_info = dynamic_cast<CofMMoveInfo*>(mi.specific_info.get());

	//Ensure that chainIndices is in sync with kf
	prepareChainIndices(kf);

	Eigen::Transform<units::Length, 3, Eigen::Affine> transform =
					Eigen::Translation<units::Length, 3>( orig_info->translation_axis * orig_info->translation_length.value()*fraction) *
					Eigen::Translation<units::Length, 3>( orig_info->center_of_mass) *
					Eigen::AngleAxis<units::Length>(orig_info->rotation_angle*fraction, orig_info->rotation_axis) *
					Eigen::Translation<units::Length, 3>(-orig_info->center_of_mass);
	kf.changeDOFglobal(orig_info->root, transform);

	return mi;
};


void CofMMove::prepareChainIndices(KinematicForest& kf)
{
	//Use cachedKinematicForest to return quickly if we've seen kf before.
	if(cachedKinematicForest==&kf) return;

	chainIndices.clear();
	chainIndices.resize(kf.getRoots());

	for(int r=0;r<kf.getRoots();r++){
		//Perform depth-first search starting from root r and collect all indices
		std::stack<int> stack;
		stack.push(kf.roots[r]);
		while(!stack.empty()){
			int v = stack.top();
			stack.pop();
			chainIndices[r].push_back(v);

			for(int a=0;a<kf.adjacencyList[v].size();a++)
				if(kf.adjacencyList[v][a].first==v)
					stack.push(kf.adjacencyList[v][a].second);
		}
	}

	cachedKinematicForest = &kf;
}

void CofMMove::randRotation( units::Angle amplitude, CofMMoveInfo& move_info)
{
	double rand1 = (1.0 * rand()) / RAND_MAX;
	double rand2 = (1.0 * rand()) / RAND_MAX;
	double rand3 = (1.0 * rand()) / RAND_MAX;
	double theta = acos( rand1*2.0-1.0 );
	double phi = rand2*2.0*M_PI;

	move_info.rotation_axis = units::Vector3L(
			sin(theta)*cos(phi) * units::nm,
			sin(theta)*sin(phi) * units::nm,
			cos(theta) 			* units::nm
	);
	move_info.rotation_angle = (rand3-0.5)*amplitude;

//	units::Vector3L rax(
//			sin(theta)*cos(phi) * units::nm,
//			sin(theta)*sin(phi) * units::nm,
//			cos(theta) 			* units::nm
//	);
//	units::Angle angle = (rand3-0.5)*amplitude;
//	M.setIdentity();
//	M = M * Eigen::AngleAxis<units::Length>(angle, rax);
}

void CofMMove::randTranslation( units::Length amplitude, CofMMoveInfo& move_info )
{
	double rand1 = (1.0 * rand()) / RAND_MAX;
	double rand2 = (1.0 * rand()) / RAND_MAX;
	double rand3 = (1.0 * rand()) / RAND_MAX;
	double theta = acos( rand1*2.0f-1.0f );
	double phi = rand2*2.0*M_PI;

	move_info.translation_length = pow(rand3,1.0/3.0)*amplitude;
	move_info.translation_axis = units::Vector3L(
				sin(theta)*cos(phi) * units::nm,
				sin(theta)*sin(phi) * units::nm,
				cos(theta) 			* units::nm
		);

//	units::Length l = pow(rand3,1.0/3.0)*amplitude;
//	M.setIdentity();
//	M = M * Eigen::Translation<units::Length, 3>(
//			l*sin(theta)*cos(phi),
//			l*sin(theta)*sin(phi),
//			l*cos(theta)
//			);
}

} /* namespace quickstep */
