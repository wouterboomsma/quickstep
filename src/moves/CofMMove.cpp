/*
 * CofMMove.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#include <quickstep/moves/CofMMove.h>

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

MoveInfo CofMMove::propose(KinematicForest& kf)
{
    MoveInfo ret(*this, kf);
//	MoveInfo ret{ make_unique<CofMMoveInfo>() };
//	CofMMoveInfo& spec_info = *dynamic_cast<CofMMoveInfo*>(ret.specific_info.get());

	//Ensure that chainIndices is in sync with kf
	prepare_chain_indices(kf);

	// Select random chain
	int root = (int)(rand()%kf.get_num_roots());
//	spec_info.root = (int)(rand()%kf.get_num_roots());

	auto rand_tra = rand_translation(translationMagnitude);
	auto rand_rot = rand_rotation(rotationMagnitude);

	// Compute center-of-mass
	Vector3d center_of_mass;
	for(int a=0;a<chain_indices[root].size();a++){
	    center_of_mass = center_of_mass + kf.pos(chain_indices[root][a]).matrix();
	}
	center_of_mass = center_of_mass / chain_indices[root].size();

	// Compose the full chain transformation
	Eigen::Transform<double, 3, Eigen::Affine> full_transform =
	        rand_tra *
	        Eigen::Translation<double, 3>( center_of_mass) *
	        rand_rot *
	        Eigen::Translation<double, 3>(-center_of_mass);



//	// Suggest random translation
//	randTranslation(translationMagnitude, spec_info);
//
//	//Suggest random rotation
//	randRotation(rotationMagnitude, spec_info);
//
//	// Compute center-of-mass
//	for(int a=0;a<chainIndices[spec_info.root].size();a++){
//		spec_info.center_of_mass = spec_info.center_of_mass + kf.pos(chainIndices[spec_info.root][a]).matrix();
//	}
//	spec_info.center_of_mass = spec_info.center_of_mass / chainIndices[spec_info.root].size();
//
//	// Suggest random rotation around center-of-mass
//	if(!suggest_only){
//		Eigen::Transform<units::Length, 3, Eigen::Affine> transform =
//				Eigen::Translation<units::Length, 3>(spec_info.translation_axis * spec_info.translation_length.value()) *
//				Eigen::Translation<units::Length, 3>( spec_info.center_of_mass) *
//				Eigen::AngleAxis<units::Length>(spec_info.rotation_angle, spec_info.rotation_axis) *
//				Eigen::Translation<units::Length, 3>(-spec_info.center_of_mass);
//		kf.changeDOFglobal(spec_info.root, transform);
//	}
//
//
//
//	SubTree affected_tree;
//	affected_tree.root_atom = kf.getRootAtomIndex(spec_info.root);
//	ret.affected_atoms.push_back(affected_tree);
//
//	return ret;


	return ret;
}

//void CofMMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fraction)
//{
//	CofMMoveInfo& orig_info = *dynamic_cast<CofMMoveInfo*>(mi.specific_info.get());
//
//	//Ensure that chainIndices is in sync with kf
//	prepare_chain_indices(kf);
//
//	Eigen::Transform<units::Length, 3, Eigen::Affine> transform =
//					Eigen::Translation<units::Length, 3>( orig_info.translation_axis * orig_info.translation_length.value()*fraction) *
//					Eigen::Translation<units::Length, 3>( orig_info.center_of_mass) *
//					Eigen::AngleAxis<units::Length>(orig_info.rotation_angle*fraction, orig_info.rotation_axis) *
//					Eigen::Translation<units::Length, 3>(-orig_info.center_of_mass);
//	kf.changeDOFglobal(orig_info.root, transform);
//
//};


void CofMMove::prepare_chain_indices(KinematicForest& kf)
{
	//Use cachedKinematicForest to return quickly if we've seen kf before.
	if(cachedKinematicForest==&kf) return;

	chain_indices.clear();
	chain_indices.resize(kf.get_num_roots());

	for(int r=0;r<kf.get_num_roots();r++){
		//Perform depth-first search starting from root r and collect all indices
		std::stack<int> stack;
		stack.push(kf.roots[r]);
		while(!stack.empty()){
			int v = stack.top();
			stack.pop();
			chain_indices[r].push_back(v);

			for(int a=0;a<kf.adjacency_list[v].size();a++)
				if(kf.adjacency_list[v][a].first==v)
					stack.push(kf.adjacency_list[v][a].second);
		}
	}

	cachedKinematicForest = &kf;
}

Eigen::Transform<double, 3, Eigen::Affine> CofMMove::rand_rotation( units::Angle amplitude )
{
	double rand1 = (1.0 * rand()) / RAND_MAX;
	double rand2 = (1.0 * rand()) / RAND_MAX;
	double rand3 = (1.0 * rand()) / RAND_MAX;
	double theta = acos( rand1*2.0-1.0 );
	double phi = rand2*2.0*M_PI;

//	move_info.rotation_axis = units::Vector3L(
//			sin(theta)*cos(phi) * units::nm,
//			sin(theta)*sin(phi) * units::nm,
//			cos(theta) 			* units::nm
//	);
//	move_info.rotation_angle = (rand3-0.5)*amplitude;

	Vector3d rax(
			sin(theta)*cos(phi),
			sin(theta)*sin(phi),
			cos(theta)
	);
	units::Angle angle = (rand3-0.5)*amplitude;
//	M.setIdentity();
//	M = M * Eigen::AngleAxis<units::Length>(angle, rax);

	return Eigen::Transform<double, 3, Eigen::Affine>(Eigen::AngleAxis<double>(angle.value(), rax));
}

Eigen::Transform<double, 3, Eigen::Affine> CofMMove::rand_translation( units::Length amplitude )
{
	double rand1 = (1.0 * rand()) / RAND_MAX;
	double rand2 = (1.0 * rand()) / RAND_MAX;
	double rand3 = (1.0 * rand()) / RAND_MAX;
	double theta = acos( rand1*2.0f-1.0f );
	double phi = rand2*2.0*M_PI;

//	move_info.translation_length = pow(rand3,1.0/3.0)*amplitude;
//	move_info.translation_axis = units::Vector3L(
//				sin(theta)*cos(phi) * units::nm,
//				sin(theta)*sin(phi) * units::nm,
//				cos(theta) 			* units::nm
//		);

	double l = pow(rand3,1.0/3.0)*amplitude.value();
//	M.setIdentity();
//	M = M * Eigen::Translation<units::Length, 3>(
//			l*sin(theta)*cos(phi),
//			l*sin(theta)*sin(phi),
//			l*cos(theta)
//			);

	return Eigen::Transform<double, 3, Eigen::Affine>(Eigen::Translation<double, 3>(
	                  l*sin(theta)*cos(phi),
	                  l*sin(theta)*sin(phi),
	                  l*cos(theta)
	                  ));
}

} /* namespace quickstep */
