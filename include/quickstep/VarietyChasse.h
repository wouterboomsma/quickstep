/*
 * CompositeChasse.h
 *
 *  Created on: Nov 5, 2014
 *      Author: rfonseca
 */

#ifndef COMPOSITECHASSE_H_
#define COMPOSITECHASSE_H_

#include <quickstep/Chasse.h>
#include <quickstep/KinematicForest.h>

#include <vector>
#include <random>

namespace quickstep {

class VarietyChasse: public Chasse {
public:
	VarietyChasse();
//	virtual ~VarietyChasse();

	bool step(KinematicForest&);

	void addChasse(std::unique_ptr<Chasse> &c, double weight);

	static std::unique_ptr<VarietyChasse> createStandardVariety(std::default_random_engine &rand_eng);

private:
	std::vector<std::unique_ptr<Chasse>> chasses;
	std::vector<double> accumWeights;
};

} /* namespace quickstep */

#endif /* COMPOSITECHASSE_H_ */
