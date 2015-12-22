/*
 * FreeBondRotateMove.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include "quickstep/moves/FreeBondRotateMove.h"

#include "quickstep/utils.h"
#include "quickstep/FatalError.h"


#include <algorithm>
#include <stack>
#include <iostream>
#include <quickstep/dofs/DihedralDof.h>

namespace quickstep {

FreeBondRotateMove::FreeBondRotateMove(units::Angle rotationMagnitude_):
				rotationMagnitude(rotationMagnitude_),
				last_used_forest(0)
{

}

MoveInfo FreeBondRotateMove::propose(KinematicForest& kf)
{
	//Ensure that rotatableBonds is in sync with kf
	prepareRotatableBonds(kf);

	//Find a random bond
	int bond_atom = rotatable_bonds[ rand()%rotatable_bonds.size() ];

	//Find a random angle
	units::Angle angle = rotationMagnitude * ((rand()*1.0)/RAND_MAX - 0.5);

	MoveInfo ret(*this, kf);

	//Perform torsion-change on all children leaving bondAtom
	for(int a=0;a<kf.adjacency_list[bond_atom].size();a++){
		int child_atom = kf.adjacency_list[bond_atom][a].second;
		if(child_atom!=bond_atom){ //Not the parent edge
//			kf.changeDOFTorsion( child_atom, angle );

		    ret.dof_deltas.push_back(
		            std::make_pair(
							std::make_unique<DihedralDof>(kf, child_atom),
		                    angle.value()
		                    )
		    );
		}
	}


//	//Set up move info
//	MoveInfo ret{ make_unique<FreeBondRotateMoveInfo>() };
//	FreeBondRotateMoveInfo& info = *dynamic_cast<FreeBondRotateMoveInfo*>(ret.specific_info.get());
//	info.bond_atom = bond_atom;
//	info.delta_value = angle.value();
//
//
//	SubTree affected_tree;
//	//Note: bond_atom itself is not actually affected, but all children are
//	affected_tree.root_atom = bond_atom;
//	ret.affected_atoms.push_back(affected_tree);

	return ret;
}

//void FreeBondRotateMove::step_fractional(KinematicForest& kf, MoveInfo& full_move_info, double fraction)
//{
//	std::cout<<"FreeBondRotateMove::step_fractional(.. "<<fraction<<")"<<std::endl;
//	FreeBondRotateMoveInfo* orig_move = dynamic_cast<FreeBondRotateMoveInfo*>(full_move_info.specific_info.get());
//
//	//Ensure that rotatableBonds is in sync with kf
//	prepareRotatableBonds(kf);
//
//	//Find a random bond
//	int bond_atom = orig_move->bond_atom;
//
//	//Find a random angle
//	units::Angle angle = orig_move->delta_value * fraction * units::radians;
//
//	//Perform torsion-change on all children leaving bondAtom
//	for(int a=0;a<kf.adjacency_list[bond_atom].size();a++){
//		int childAtom = kf.adjacency_list[bond_atom][a].second;
//		if(childAtom!=bond_atom) //Not the parent edge
//			kf.changeDOFTorsion( childAtom, angle );
//	}
//
//	//	//Set up move info
//	//	FreeBondRotateMoveInfo info;
//	//	info.bond_atom = bond_atom;
//	//	info.delta_value = angle.value();
//	//
//	////	MoveInfo ret(info);
//	////
//	////	SubTree affected_tree;
//	////	//Note: bond_atom itself is not actually affected, but all children are
//	////	affected_tree.root_atom = bond_atom;
//	////	ret.affected_atoms.push_back(affected_tree);
//	////
//	////	return ret;
//	//	return full_move_info;
//}

void FreeBondRotateMove::prepareRotatableBonds(KinematicForest& kf)
{
	if(last_used_forest == &kf) return;

	rotatable_bonds.clear();
//	rotatableBonds.clear();

	for(int r=0;r<kf.get_num_roots();r++){
		//Perform depth-first search starting from root r and collect rotatable atoms
		std::stack<int> stack;
		stack.push(kf.roots[r]);
		while(!stack.empty()){
			int v = stack.top();
			stack.pop();

			//v is only rotatable if its not a root or a leaf
			if( std::find(kf.roots.begin(), kf.roots.end(), v)==kf.roots.end() &&
			        kf.adjacency_list[v].size()>1){
				rotatable_bonds.push_back(v);
			}

			for(int a=0;a<kf.adjacency_list[v].size();a++)
				if(kf.adjacency_list[v][a].first==v)
					stack.push(kf.adjacency_list[v][a].second);
		}
	}

	if(rotatable_bonds.size()==0){
		BOOST_THROW_EXCEPTION(FatalError() <<
				"FreeBondRotateMove: No rotatable bonds identified");
	}

	last_used_forest = &kf;


}

} /* namespace quickstep */
