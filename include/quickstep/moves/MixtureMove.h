#ifndef MIXTURE_MOVE_H_
#define MIXTURE_MOVE_H_

#include <quickstep/moves/CompositeMove.h>

namespace quickstep {

// The only difference between a mixture move and a composite move, is that
// when evaluating the log_bias of a move, the components of a mixture move
// will delegate this calculate to the parent (summing over the biases of
// all mixture components
class MixtureMove: public CompositeMove {
public:

    class MoveGenerator: public CompositeMove::MoveGenerator {
	public:
		virtual std::vector<std::unique_ptr<Move>> operator()(const boost::property_tree::ptree &parameter_input,
															  Topology &topology,
															  const MoveParameters &move_parameters) override;

		// NOTE: the registrator variable must be explicitly defined in the .cpp file as well
		const static struct Registrator {
			Registrator() {
				MoveFactory::get().register_generator("MixtureMove", std::make_unique<MixtureMove::MoveGenerator>());
			}
		} registrator;
	};

	MixtureMove(CompositeMove &&other):
			CompositeMove(std::move(other)){}


	virtual MoveInfo propose(KinematicForest &kf) override;


protected:
    virtual Eigen::Array<double, 2, 1> calc_log_bias_impl(const MoveInfo &move_info) const override;
};


} /* namespace quickstep */

#endif /* MIXTURE_MOVE_H_ */
