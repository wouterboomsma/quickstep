/*
 * CofMMove.cpp
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#include <quickstep/CofMMove.h>

#include <quickstep/math/primitives.h>

#include <stack>

namespace quickstep {

CofMMove::CofMMove(double translationMagnitude_, double rotationMagnitude_):
		translationMagnitude(translationMagnitude_),
		rotationMagnitude(rotationMagnitude_),
		cachedKinematicForest(0)
{

}

//CofMMove::~CofMMove() {
//	// TODO Auto-generated destructor stub
//}

bool CofMMove::step(KinematicForest& kf)
{
	//Ensure that chainIndices is in sync with kf
	prepareChainIndices(kf);

	// Select random chain
	int root = (int)(Math3D::Random01()*kf.getRoots());

	// Suggest random translation
	Math3D::RigidTransform t0;
	randTranslation(translationMagnitude, t0.t);

	// Compute center-of-mass
	Math3D::Vector3 cofm;
	for(int a=0;a<chainIndices[root].size();a++){
		cofm+=kf.pos(chainIndices[root][a]);
	}
	cofm/=chainIndices[root].size();

	// Suggest random rotation round center-of-mass
	Math3D::RigidTransform t1, t2, t3;
	t1.setTranslation( cofm);
	randRotation(rotationMagnitude, t2.R);
	t3.setTranslation(-cofm);

	// Compose transformations and apply to the kinematic forest
	Math3D::RigidTransform transform = t0*t1*t2*t3;
	kf.changeDOFglobal(root, transform);

	// This chassé is always succesful
	return true;
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


void CofMMove::randRotation( float amplitude, Math3D::Matrix3 &M )
{
	float theta = acos( Math3D::Random01()*2.0f-1.0f );
	float phi = Math3D::Random01()*2.0f*M_PI;
	Math3D::Vector3 rax(
			sin(theta)*cos(phi),
			sin(theta)*sin(phi),
			cos(theta)
	);
	double angle = Math3D::Random01()*amplitude;
	M.setRotate(rax, angle);
}

void CofMMove::randTranslation( float amplitude, Math3D::Vector3 &v )
{
	float theta = acos( Math3D::Random01()*2.0f-1.0f );
	float phi = Math3D::Random01()*2.0f*M_PI;
	float rad = pow(Math3D::Random01(),1.0/3.0)*amplitude;
	v[0] = rad*sin(theta)*cos(phi);
	v[1] = rad*sin(theta)*sin(phi);
	v[2] = rad*cos(theta);
}

} /* namespace quickstep */
