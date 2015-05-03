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

MoveInfo CompositeMove::step(KinematicForest& kf, bool suggest_only)
{
	assert(accumWeights.size()>0);

	float randVal = accumWeights.back() * (rand()*1.0/RAND_MAX);

	for(int i=0;i<accumWeights.size();i++){
		if(randVal<=accumWeights[i]){
			MoveInfo status = moves[i]->step(kf);
			kf.updatePositions();
			return status;
		}
	}

	throw "Error: Sampled a random value higher than total accumulated weight";
}

MoveInfo CompositeMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fraction)
{
	CompositeMoveInfo* cmi = static_cast<CompositeMoveInfo*>(&mi.specific_info);
	moves[cmi->chosen_move]->step_fractional(kf, cmi->chosen_info, fraction);
	return mi;
}

//void CompositeMove::add_move(std::unique_ptr<Move> m, double weight)
void CompositeMove::add_move(std::unique_ptr<Move> m, double weight)
{
	moves.push_back( std::move(m) );

	double weightSum = accumWeights.empty()?0.0:accumWeights[accumWeights.size()-1];
	accumWeights.push_back(weightSum+weight);
}

std::unique_ptr<CompositeMove> CompositeMove::create_standard_move(std::default_random_engine &rand_eng)
{
	std::unique_ptr<CompositeMove> ret(new CompositeMove());

	ret->add_move( make_unique<CofMMove>(0.01*units::nm, 0.05*units::radians), 0.05);      // max-translation: 0.1Å, max-rotation ~1 degree
	ret->add_move( make_unique<FreeBondRotateMove>(0.17*units::radians), 0.05);  // max-rotation: ~1 degree

	return ret;
}

} /* namespace quickstep */
