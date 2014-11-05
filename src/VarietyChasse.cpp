/*
 * CompositeChasse.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#include "quickstep/VarietyChasse.h"

#include <assert.h>
#include <quickstep/CofMChasse.h>
#include <quickstep/FreeBondRotateChasse.h>

namespace quickstep {

VarietyChasse::VarietyChasse() {
	// TODO Auto-generated constructor stub

}

//VarietyChasse::~VarietyChasse() {
//}

bool VarietyChasse::step(KinematicForest& kf)
{
	assert(accumWeights.size()>0);

	float randVal = accumWeights.back() * Math3D::Random01();

	for(int i=0;i<accumWeights.size();i++){
		if(randVal<=accumWeights[i]){
			bool status = chasses[i]->step(kf);
			kf.updatePositions();
			return status;
		}
	}

	throw "Error: Sampled a random value higher than total accumulated weight";
}

void VarietyChasse::addChasse(std::unique_ptr<Chasse> &c, double weight)
{
	chasses.push_back( std::move(c) );

	double weightSum = accumWeights.empty()?0.0:accumWeights[accumWeights.size()-1];
	accumWeights.push_back(weightSum+weight);
}

unique_ptr<VarietyChasse> VarietyChasse::createStandardVariety(std::default_random_engine &rand_eng)
{
	unique_ptr<VarietyChasse> ret(new VarietyChasse());

	std::unique_ptr<Chasse> chasse_cofm( new CofMChasse(0.0001,0.05) ); 			//max-translation: 0.1Å, max-rotation ~1 degree
	std::unique_ptr<Chasse> chasse_bondRot( new FreeBondRotateChasse(0.17) ); 	//max-rotation: ~1 degree

	ret->addChasse(chasse_cofm		, 0.5);
	ret->addChasse(chasse_bondRot	, 0.5);

	return ret;
}

} /* namespace quickstep */
