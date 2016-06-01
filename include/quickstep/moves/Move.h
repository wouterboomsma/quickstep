/*
 * Move.h
 *
 *  Created on: Oct 29, 2014
 *      Author: rfonseca
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "quickstep/KinematicForest.h"
#include <quickstep/MoveInfo.h>
#include <quickstep/MoveSettings.h>

#include <boost/optional/optional.hpp>

namespace quickstep {

/**
 * Interface for classes that can perform a conformational move to a kinematic forest.
 */
class Move {
public:

	Move()
            : log_bias_delegate(nullptr){};

	static std::unique_ptr<Move> parse(const std::string &xml_filename,
									   const std::shared_ptr<Topology> &topology,
									   std::vector<std::shared_ptr<MoveSettings>> move_settings={});

	virtual ~Move(){}

	/** Suggest a conformational move using the provided kinematic forest.  */
	virtual MoveInfo propose(KinematicForest&) = 0;

	void perform(KinematicForest&, MoveInfo&);

    virtual double calc_log_bias(const MoveInfo &move_info) const final;

	virtual Eigen::Array<double, 2, 1> calc_log_bias_impl(const MoveInfo &move_info) const;

	virtual void set_log_bias_delegate(Move *move);

    virtual double calc_jacobian(const MoveInfo &move_info) const;

	virtual void accept();

	virtual void reject();


	template <typename T>
	static T find_settings(const std::vector<std::shared_ptr<MoveSettings> > &move_settings) {
		for (const auto &settings_it: move_settings) {
			auto *settings = dynamic_cast<T *>(settings_it.get());
			if (settings) {
				return T(*settings);
			}
		}
		return T{};
	}

	template <typename T>
	static boost::optional<T> find_settings_optional(const std::vector<std::shared_ptr<MoveSettings> > &move_settings) {
		for (const auto &settings_it: move_settings) {
			auto *settings = dynamic_cast<T *>(settings_it.get());
			if (settings) {
				return boost::optional<T>(T(*settings));
			}
		}
		return boost::optional<T>();
	}

protected:

    // In certain cases, a move cannot determine its own bias, and needs to consult its parent.
    // In cases where this is true (e.g. MixtureMove), this variable points to the relevant parent.
    Move *log_bias_delegate;

};

} /* namespace quickstep */

#endif /* MOVE_H_ */
