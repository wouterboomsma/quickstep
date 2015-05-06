/*
 * FreeBondRotateMove.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include "quickstep/moves/FreeBondRotateMove.h"

#include "quickstep/utils.h"


#include <algorithm>
#include <stack>

namespace quickstep {

FreeBondRotateMove::FreeBondRotateMove(units::Angle rotationMagnitude_):
		rotationMagnitude(rotationMagnitude_),
		cachedKinematicForest(0)
{

}

MoveInfo FreeBondRotateMove::step(KinematicForest& kf, bool suggest_only)
{
	//Ensure that rotatableBonds is in sync with kf
	prepareRotatableBonds(kf);

	//Find a random bond
	int bond_atom = rotatableBonds[ rand()%rotatableBonds.size() ];

	//Find a random angle
	units::Angle angle = rotationMagnitude * ((rand()*1.0)/RAND_MAX - 0.5);

	//Perform torsion-change on all children leaving bondAtom
	for(int a=0;a<kf.adjacencyList[bond_atom].size();a++){
		int childAtom = kf.adjacencyList[bond_atom][a].second;
		if(childAtom!=bond_atom) //Not the parent edge
			kf.changeDOFTorsion( childAtom, angle );
	}


	//Set up move info
	MoveInfo ret{ make_unique<FreeBondRotateMoveInfo>() };
	FreeBondRotateMoveInfo& info = *dynamic_cast<FreeBondRotateMoveInfo*>(ret.specific_info.get());
	info.bond_atom = bond_atom;
	info.delta_value = angle.value();


	SubTree affected_tree;
	//Note: bond_atom itself is not actually affected, but all children are
	affected_tree.root_atom = bond_atom;
	ret.affected_atoms.push_back(affected_tree);

	return ret;
}

void FreeBondRotateMove::step_fractional(KinematicForest& kf, MoveInfo& full_move_info, double fraction)
{
	FreeBondRotateMoveInfo* orig_move = dynamic_cast<FreeBondRotateMoveInfo*>(full_move_info.specific_info.get());

	//Ensure that rotatableBonds is in sync with kf
	prepareRotatableBonds(kf);

	//Find a random bond
	int bond_atom = orig_move->bond_atom;

	//Find a random angle
	units::Angle angle = orig_move->delta_value * fraction * units::radians;

	//Perform torsion-change on all children leaving bondAtom
	for(int a=0;a<kf.adjacencyList[bond_atom].size();a++){
		int childAtom = kf.adjacencyList[bond_atom][a].second;
		if(childAtom!=bond_atom) //Not the parent edge
			kf.changeDOFTorsion( childAtom, angle );
	}

//	//Set up move info
//	FreeBondRotateMoveInfo info;
//	info.bond_atom = bond_atom;
//	info.delta_value = angle.value();
//
////	MoveInfo ret(info);
////
////	SubTree affected_tree;
////	//Note: bond_atom itself is not actually affected, but all children are
////	affected_tree.root_atom = bond_atom;
////	ret.affected_atoms.push_back(affected_tree);
////
////	return ret;
//	return full_move_info;
}

void FreeBondRotateMove::prepareRotatableBonds(KinematicForest& kf)
{
	if(cachedKinematicForest == &kf) return;

	rotatableBonds.clear();

	for(int r=0;r<kf.getRoots();r++){
			//Perform depth-first search starting from root r and collect rotatable atoms
			std::stack<int> stack;
			stack.push(kf.roots[r]);
			while(!stack.empty()){
				int v = stack.top();
				stack.pop();

				//v is only rotatable if its not a root
				auto it0 = std::find(kf.roots.begin(), kf.roots.end(), v);
				if(it0==kf.roots.end())
					rotatableBonds.push_back(v);

				for(int a=0;a<kf.adjacencyList[v].size();a++)
					if(kf.adjacencyList[v][a].first==v)
						stack.push(kf.adjacencyList[v][a].second);
			}
		}

		cachedKinematicForest = &kf;
}

} /* namespace quickstep */
