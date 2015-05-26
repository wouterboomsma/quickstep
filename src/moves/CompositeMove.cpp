/*
 * CompositeMove.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include "quickstep/moves/CompositeMove.h"

#include <memory>
#include <assert.h>
#include <quickstep/moves/CofMMove.h>
#include <quickstep/moves/FreeBondRotateMove.h>

namespace quickstep {

CompositeMove::CompositeMove() {

}

MoveInfo CompositeMove::step(KinematicForest& kf, bool suggest_only)
{
	assert(accumWeights.size()>0);

	float randVal = accumWeights.back() * (rand()*1.0/RAND_MAX);

	for(int i=0;i<accumWeights.size();i++){
		if(randVal<=accumWeights[i]){

			MoveInfo ret{ make_unique<CompositeMoveInfo>() };
			CompositeMoveInfo& spec_info = *dynamic_cast<CompositeMoveInfo*>(ret.specific_info.get());
			spec_info.chosen_info = make_unique<MoveInfo>( std::move(moves[i]->step(kf)) );

			return ret;
		}
	}

	throw "Error: Sampled a random value higher than total accumulated weight";
}

void CompositeMove::step_fractional(KinematicForest& kf, MoveInfo& mi, double fraction)
{
	CompositeMoveInfo* cmi = static_cast<CompositeMoveInfo*>(mi.specific_info.get());
	moves[cmi->chosen_move]->step_fractional(kf, *cmi->chosen_info.get(), fraction);
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
