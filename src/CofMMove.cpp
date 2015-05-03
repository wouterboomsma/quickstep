/*
 * CofMMove.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#include <quickstep/CofMMove.h>

#include <quickstep/math/primitives.h>
#include "quickstep/units.h"

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
	//Ensure that chainIndices is in sync with kf
	prepareChainIndices(kf);

	// Select random chain
	int root = (int)(rand()%kf.getRoots());

	// Suggest random translation
	Eigen::Transform<units::Length, 3, Eigen::Affine> t0;
	randTranslation(translationMagnitude, t0);

	//Suggest random rotation
	Eigen::Transform<units::Length, 3, Eigen::Affine> t1;
	randRotation(rotationMagnitude, t1);


	// Compute center-of-mass
	units::Vector3L cofm;
	for(int a=0;a<chainIndices[root].size();a++){
		cofm = cofm + kf.pos(chainIndices[root][a]).matrix();
	}
	cofm = cofm/chainIndices[root].size();

	// Suggest random rotation around center-of-mass
	Eigen::Transform<units::Length, 3, Eigen::Affine> transform =
			t0*
			Eigen::Translation<units::Length, 3>( cofm)*
			t1*
			Eigen::Translation<units::Length, 3>(-cofm);
	kf.changeDOFglobal(root, transform);


	CofMMoveInfo spec_info;
	spec_info.root 				= root;
	spec_info.center_of_mass 	= cofm;
	spec_info.translation 		= t0;
	spec_info.rotation 			= t1;

	MoveInfo ret(spec_info);

	SubTree affected_tree;
	affected_tree.root_atom = kf.getRootAtomIndex(root);
	ret.affected_atoms.push_back(affected_tree);

	return ret;
}

MoveInfo CofMMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fractional)
{
	CofMMoveInfo& orig_info = dynamic_cast<CofMMoveInfo&>(mi.specific_info);

	//Ensure that chainIndices is in sync with kf
	prepareChainIndices(kf);

	// Select random chain
	int root = orig_info.root;

	// Retrieve translation
	Eigen::Transform<units::Length, 3, Eigen::Affine> t0 = orig_info.translation*(fractional*units::nm);

	// Retrieve rotation
	Eigen::Transform<units::Length, 3, Eigen::Affine> t1 = orig_info.rotation*(fractional*units::nm);
	randRotation(rotationMagnitude, t1);

	// Compute center-of-mass
	units::Vector3L& cofm = orig_info.center_of_mass;

	// Suggest random rotation around center-of-mass
	Eigen::Transform<units::Length, 3, Eigen::Affine> transform =
			t0*
			Eigen::Translation<units::Length, 3>( cofm)*
			t1*
			Eigen::Translation<units::Length, 3>(-cofm);
	kf.changeDOFglobal(root, transform);

	return mi;
}


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

void CofMMove::randRotation( units::Angle amplitude, Eigen::Transform<units::Length, 3, Eigen::Affine> &M )
{
	double rand1 = (1.0 * rand()) / RAND_MAX;
	double rand2 = (1.0 * rand()) / RAND_MAX;
	double rand3 = (1.0 * rand()) / RAND_MAX;

	double theta = acos( rand1*2.0-1.0 );
	double phi = rand2*2.0*M_PI;
	units::Vector3L rax(
			sin(theta)*cos(phi) * units::nm,
			sin(theta)*sin(phi) * units::nm,
			cos(theta) 			* units::nm
	);
	units::Angle angle = (rand3-0.5)*amplitude;
	M.setIdentity();
	M = M * Eigen::AngleAxis<units::Length>(angle, rax);
}

//void CofMMove::randTranslation( float amplitude, Math3D::Vector3 &v )
void CofMMove::randTranslation( units::Length amplitude, Eigen::Transform<units::Length, 3, Eigen::Affine> &M )
{
	double rand1 = (1.0 * rand()) / RAND_MAX;
	double rand2 = (1.0 * rand()) / RAND_MAX;
	double rand3 = (1.0 * rand()) / RAND_MAX;
	double theta = acos( rand1*2.0f-1.0f );
	double phi = rand2*2.0*M_PI;
	units::Length rad = pow(rand3,1.0/3.0)*amplitude;
	M.setIdentity();

	M = M * Eigen::Translation<units::Length, 3>(
			rad*sin(theta)*cos(phi),
			rad*sin(theta)*sin(phi),
			rad*cos(theta)
			);
}

} /* namespace quickstep */
