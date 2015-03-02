/*
 * CompositeMove.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include "quickstep/CompositeMove.h"

#include <memory>
#include <assert.h>
#include <quickstep/CofMMove.h>
#include <quickstep/FreeBondRotateMove.h>

namespace quickstep {

CompositeMove::CompositeMove() {
	// TODO Auto-generated constructor stub

}

bool CompositeMove::step(KinematicForest& kf)
{
	assert(accumWeights.size()>0);

	float randVal = accumWeights.back() * Math3D::Random01();

	for(int i=0;i<accumWeights.size();i++){
		if(randVal<=accumWeights[i]){
			bool status = moves[i]->step(kf);
			kf.updatePositions();
			return status;
		}
	}

	throw "Error: Sampled a random value higher than total accumulated weight";
}

//void CompositeMove::add_move(std::unique_ptr<Move> m, double weight)
void CompositeMove::add_move(utility::unique_ptr<Move> m, double weight)
{
	moves.push_back( std::move(m) );

	double weightSum = accumWeights.empty()?0.0:accumWeights[accumWeights.size()-1];
	accumWeights.push_back(weightSum+weight);
}

std::unique_ptr<CompositeMove> CompositeMove::create_standard_move(std::default_random_engine &rand_eng)
{
	std::unique_ptr<CompositeMove> ret(new CompositeMove());

//	std::unique_ptr<Move> cofm ( new CofMMove(0.01,0.05) ); 			//max-translation: 0.1Å, max-rotation ~1 degree
//	std::unique_ptr<Move> bondRot( new FreeBondRotateMove(0.17) ); 	//max-rotation: ~1 degree
	utility::unique_ptr<Move> cofm ( new CofMMove(0.01,0.05), &utility::delete_func_noop ); 			//max-translation: 0.1Å, max-rotation ~1 degree
	utility::unique_ptr<Move> bondRot( new FreeBondRotateMove(0.17), &utility::delete_func_noop); 	//max-rotation: ~1 degree

	ret->add_move( std::move(cofm), 0.5);
	ret->add_move( std::move(bondRot), 0.5);

	return ret;
}

} /* namespace quickstep */
