/*
 * CompositeMove.cpp
 *
 *  Created on: April 28, 2014
 *      Author: rfonseca
 */

#include "quickstep/InterpolatorMove.h"

#include <memory>
#include <assert.h>

namespace quickstep {

InterpolatorMove::InterpolatorMove(std::unique_ptr<Move> move): child_move(move)
{

}

MoveInfo InterpolatorMove::step(KinematicForest& kf, bool suggest_only)
{


	return MoveInfo();
}

} /* namespace quickstep */
