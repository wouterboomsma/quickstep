#include "quickstep/moves/GaussianMove.h"
#include "quickstep/MoveParameters.h"
#include "quickstep/FatalError.h"
#include <qsboost/property_tree/ptree.hpp>
#include <quickstep/random.h>
#include <quickstep/dofs/DihedralDof.h>

namespace quickstep {


// Register move generator with factory
const GaussianMove::MoveGenerator::Registrator GaussianMove::MoveGenerator::registrator;

std::vector<std::unique_ptr<Move>> GaussianMove::MoveGenerator::operator()(const qsboost::property_tree::ptree &parameter_input,
                                                              Topology &topology,
                                                              const MoveParameters &move_parameters) {
    auto root_node = parameter_input.begin();
    const std::string &node_name = root_node->first;

    int dimension = root_node->second.get<int>("dim");

    Eigen::VectorXd mean = Eigen::VectorXd::Zero(dimension);
    Eigen::MatrixXd cov = Eigen::MatrixXd::Identity(dimension, dimension);

    std::vector<std::string> dofs(dimension);

    double conversion_factor = 1.;
    qsboost::optional<std::string> unit = root_node->second.get_optional<std::string>("unit");
    if (unit) {
        // TODO: General strategy for units in parameters files
        if (*unit == "degr")
            conversion_factor = M_PI/180.;
    }

    std::string mean_label = "mean";
    std::string dof_label = "dof";
    std::string stddev_label = "stddev";
    for (int i=0; i<dimension; ++i) {
        std::string mean_label_suffixed = mean_label + std::to_string(i+1);
        std::string dof_label_suffixed = dof_label + std::to_string(i+1);

        qsboost::optional<double> mean_val;
        if ((        (mean_val = root_node->second.get_optional<double>(mean_label_suffixed))) ||
            (i==0 && (mean_val = root_node->second.get_optional<double>(mean_label)))) {
            mean(i) = *mean_val * conversion_factor;
        }

        qsboost::optional<std::string> dof_val;
        if ((        (dof_val = root_node->second.get_optional<std::string>(dof_label_suffixed))) ||
            (i==0 && (dof_val = root_node->second.get_optional<std::string>(dof_label)))) {
        	if(*dof_val=="")
        		QSBOOST_THROW_EXCEPTION(FatalError() << "Empty DOF while reading XML: "<<node_name);
            dofs[i] = *dof_val;
        }

        for (int j=i; j<dimension; ++j) {
            std::string stddev_label_suffixed1 = stddev_label + std::to_string(i + 1) + std::to_string(j + 1);
            std::string stddev_label_suffixed2 = stddev_label + std::to_string(j + 1) + std::to_string(i + 1);

            qsboost::optional<double> sigma_val;
            if ((          (sigma_val = root_node->second.get_optional<double>(stddev_label_suffixed1))) ||
                (          (sigma_val = root_node->second.get_optional<double>(stddev_label_suffixed2))) ||
                (i == 0 && (sigma_val = root_node->second.get_optional<double>(stddev_label)))) {
                cov(i, j) = (*sigma_val * conversion_factor) * (*sigma_val * conversion_factor);
                cov(j, i) = (*sigma_val * conversion_factor) * (*sigma_val * conversion_factor);
            }
        }
    }

    //auto dof_atoms = make_unique<std::vector<std::vector<std::vector<int>>>>();
    std::vector<std::vector<std::vector<int>>> dof_atoms;  // [implementation-matches][dim-index][dof-type-dihedral-dimension]
    std::vector<std::vector<std::string>> dof_atom_names = std::vector<std::vector<std::string>>(dofs.size());
    for (unsigned int dof_index=0; dof_index<dofs.size(); ++dof_index) {
        const auto &dof = dofs[dof_index];
        const auto &dof_data = move_parameters.dof_data.at(dof);
        // std::cout << "dof: " << dof << " " << dof_data.atom_names << "\n";
        dof_atom_names[dof_index] = dof_data.atom_names;
        for (const auto &residue_name: dof_data.residue_names) {
            auto template_data = move_parameters.get_residue_template(residue_name);
            std::string signature = move_parameters.get_residue_signature(residue_name);
            auto residue_matches = topology.get_residues_by_signature(signature);
//            if (residue_matches.empty()) {
//                std::cout << residue_name << " " << signature << "\n";
//                std::cout << topology.residue_template_signatures << "\n";
//            }
            for (unsigned int i=0; i<residue_matches.size(); ++i) {
                const auto residue = residue_matches[i];
                std::vector<int> matches = move_parameters.match_residue_atoms(residue, topology.get_atoms(), template_data,
                                                                               topology.get_bond_adjacency_list());
                if (matches.empty()) {
                    QSBOOST_THROW_EXCEPTION(FatalError() <<
                                          "No residue template found for residue: "
                                          << std::to_string(residue.get().index + 1) << " ("
                                          << residue.get().name << "). "
                                          << move_parameters.find_match_errors(residue, topology.get_atoms()));
                } else {
                    if (dof_atoms.empty()) {
                        dof_atoms.resize(residue_matches.size());
                        for (unsigned int j=0; j<residue_matches.size(); ++j) {
                            dof_atoms[j] = std::vector<std::vector<int>>(dofs.size(),
                                                                         std::vector<int>(
                                                                                 dof_data.atom_names.size()));
                        }
                    } else {
                        if (dof_atoms.size() != residue_matches.size()) {
                            QSBOOST_THROW_EXCEPTION(FatalError() <<
                                                  "Different number of DOF matches for different dimensions in Gaussian: "
                                                  << dof << " (" << residue_matches.size() << ") vs "
                                                  << dofs[0]<< " (" << dof_atoms.size() << ")");
                        }
                    }
                }

                std::map<int, const std::reference_wrapper<const Topology::Atom>> match_atoms;
                for (unsigned int i = 0; i < matches.size(); ++i) {
                    match_atoms.insert(std::make_pair(matches[i], std::ref(topology.get_atoms()[residue.get().atom_indices[i]])));
                }
                // std::vector<const std::reference_wrapper<const Topology::Atom>> atoms;
                for (unsigned int d=0; d<dof_data.atom_names.size(); ++d) {
                    dof_atoms[i][dof_index][d] = match_atoms.at(template_data.atom_name_lookup.at(dof_data.atom_names[d])).get().index;
                }

            }
        }
    }

    std::vector<std::unique_ptr<Move>> return_value;
    for (auto &realization_dof_atoms: dof_atoms) {
        // std::cout << "GaussianMove residue: " << topology.get_atoms().at(realization_dof_atoms.front().front()).residue.index << " " << topology.get_atoms().at(realization_dof_atoms.front().front()).residue.name << "\n";
        return_value.push_back(std::move(std::make_unique<GaussianMove>(mean, cov, realization_dof_atoms, dof_atom_names)));
    }

    return std::move(return_value);
}

MoveInfo GaussianMove::propose(KinematicForest &forest) {

    if (dofs.empty()) {
        dofs.clear();
        for (unsigned int i=0; i<dof_atoms.size(); ++i) {
            dofs.push_back(Dof::construct(forest, dof_atoms[i], dof_atom_names[i])  );
        }
    }

    //Eigen::VectorXd sample;
    //if (sample_means_only) {
    //    sample = mean;
    //} else {
    Eigen::VectorXd sample{(sampling_transform * Eigen::MatrixXd::NullaryExpr(sampling_transform.rows(), 1,
                                                                              [&](int, int = 0) {
                                                                                  return normal_distribution();
                                                                              })) + mean};
    //}
//    Eigen::VectorXd delta_vals(sample.rows(),1);

    MoveInfo ret(*this, forest);

    Eigen::VectorXd new_value(sample.rows());
    for (unsigned int d=0; d<sample.rows(); ++d) {

        //ret.dof_deltas2.push_back({});

        //old_value[d] = dofs[d]->get_value();
        //new_value[d] = sample[d];
        sample[d] = std::fmod(std::fmod(sample[d]+M_PI, 2*M_PI)+2*M_PI, 2*M_PI)-M_PI;
        //std::cout << "New torsion: " << sample[d] << "(" << mean << ")    previous: " << dofs[d]->get_value() << "\n";
        //std::cout << "New torsion: " << new_value[d];
        double value = sample[d] - dofs[d]->get_value();
        //a = (a>180) ? -360 : (a<-180) ? 360 : 0;
        //a += (a>180) ? -360 : (a<-180) ? 360 : 0;
        value += (value>M_PI) ? -2*M_PI : (value<-M_PI) ? 2*M_PI : 0; // Might not strictly be necessary
//        delta_vals[d] = a;
//        dofs[d]->add_value(a);
        //ret.dof_deltas.push_back( std::make_pair( *dofs[d].get(), a ) );
        //DOFIndex di = dofs[d]->get_dofindex();
        int dof_atom_index = dofs[d]->get_atom_index();
        //ret.dof_deltas.push_back( std::make_pair( di, a ) );

        //int parent_index = forest.parent(dof_atom_index);
        //
        //int atom_index3 = forest.parent(parent_index);
        //int atom_index4 = forest.parent(atom_index3);

        // The primary dof always appears first
        //ret.dof_deltas2.back().push_back(std::make_pair(a, std::vector<int>{dof_atom_index, parent_index, atom_index3, atom_index4}));
        ret.dof_deltas.push_back(std::make_pair(std::make_unique<DihedralDof>(forest, dof_atom_index), value));
        //ret.atoms.push_back({(int)di.atom_index, parent_index, atom_index3, atom_index4});



        ////Add all children of parent
        //for(size_t i=0; i<forest.adjacency_list[parent_index].size();++i){
        //    if(forest.adjacency_list[parent_index][i].first == parent_index){
        //
        //        int a0 = dof_atom_index;
        //        int a1 = forest.parent(a0);
        //        int a2 = forest.parent(a1);
        //        int a3 = forest.parent(a2);
        //
        //        if (a0 != dof_atom_index)
        //            ret.dof_deltas2.back().push_back(std::make_pair(a, std::vector<int>{a0, a1, a2, a3}));
        //
        //        dof_atom_index = forest.adjacency_list[parent_index][i].second;
        //        //ret.dof_deltas.push_back( std::make_pair( di, a ) );
        //    }
        //}

    }

    //Set up move info
//    MoveInfo ret{ std::make_unique<GaussianMoveInfo>(delta_vals) };
//    GaussianMoveInfo& info = *dynamic_cast<GaussianMoveInfo*>(ret.specific_info.get());

//    SubTree affected_tree;
//    affected_tree.root_atom = dofs[0]->get_atom_index();
//    ret.affected_atoms.push_back(affected_tree);
    return ret;
}

//void GaussianMove::step_fractional(KinematicForest &forest, MoveInfo &info, double fraction) {
////    if (dofs.empty()) {
////        for (unsigned int i=0; i<dof_atoms.size(); ++i) {
////            dofs.push_back(  KinematicForest::DoF::construct(forest, dof_atoms[i], dof_atom_names[i])  );
////        }
////    }
//    GaussianMoveInfo& spec_info = *dynamic_cast<GaussianMoveInfo*>(info.specific_info.get());
//    Eigen::VectorXd& delta_vals = spec_info.sample;
//
//    for (unsigned int d=0; d<delta_vals.rows(); ++d) {
//        dofs[d]->add_value(delta_vals[d]*fraction);
//    }
////    forest.updatePositions();
//}

GaussianMove::GaussianMove(const Eigen::VectorXd &mean, const Eigen::MatrixXd &cov,
                           std::vector<std::vector<int>> &dof_atoms,
                           std::vector<std::vector<std::string>> &dof_atom_names)
        : mean(mean),
          inverse_cov(cov.inverse()),
          //old_value(mean.rows()),
          //new_value(mean.rows()),
          dof_atoms(dof_atoms),
          dof_atom_names(dof_atom_names) {


//    std::cout << "covariance: " << cov << "\n";
//    std::cout << "mean: " << mean << "\n";

    // Use Cholesky decomposition if the matrix is symmetric and positive-definite
    Eigen::LLT<Eigen::MatrixXd> cholesky_solver(cov);
    if (cholesky_solver.info() == Eigen::Success) {
        sampling_transform = cholesky_solver.matrixL();
    }
    // Otherwise, use Eigen solver
    else {
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigen_solver(cov);
        sampling_transform = eigen_solver.eigenvectors() * eigen_solver.eigenvalues().cwiseMax(0).cwiseSqrt().asDiagonal();
    }


}

Eigen::Array<double, 2, 1> GaussianMove::calc_log_bias_impl(const MoveInfo &move_info) const {

    //std::cout << "mean: " << mean << "   cov: " << inverse_cov.inverse()<< "\n";


    int k = mean.rows();
    //Eigen::VectorXd x_new = new_value - mean;
    //x_new = x_new.array().min(2*M_PI-x_new.array());
    //Eigen::VectorXd x_old = old_value - mean;
    //x_old = x_old.array().min(2*M_PI-x_old.array());
    //double log_likelihood_new = ((k/2.) * -std::log(2*M_PI) - std::log(sampling_transform.trace()) +
    //        -0.5*(x_new).dot(inverse_cov * (x_new)));
    //double log_likelihood_old = ((k/2.) * -std::log(2*M_PI) - std::log(sampling_transform.trace()) +
    //        -0.5*(x_old).dot(inverse_cov * (x_old)));
    //std::cout << "Old value likelihood: " << old_value << " " << mean << " " << inverse_cov.inverse() << " " << inverse_cov << " " << log_likelihood_old << "\n";
    //std::cout << "New value likelihood: " << new_value << " " << mean << " " << inverse_cov.inverse() << " " << inverse_cov << " " << log_likelihood_new << "\n";

    Eigen::VectorXd new_value(move_info.dof_deltas.size());
    Eigen::VectorXd old_value(move_info.dof_deltas.size());
    for (unsigned int d=0; d<move_info.dof_deltas.size(); ++d) {
        new_value[d] = move_info.dof_deltas[d].first->get_value();
        //new_value[d] = move_info.forest.get().get_torsion(move_info.dof_deltas[d].front().second[0]).value();
    }

    Eigen::VectorXd delta(move_info.dof_deltas.size());
    for (unsigned int d=0; d<move_info.dof_deltas.size(); ++d) {
        delta[d] = move_info.dof_deltas[d].second;
    }
    old_value = new_value - delta;
    for (unsigned int d=0; d<move_info.dof_deltas.size(); ++d) {
        //std::cout << "old value: " << old_value[d] << " " << std::fmod((old_value[d] + 3*M_PI),(2*M_PI)) - M_PI << " " << std::fmod(std::fmod(old_value[d], 2*M_PI)+2*M_PI, 2*M_PI) << "\n";
        old_value[d] = std::fmod(std::fmod(old_value[d]+M_PI, 2*M_PI)+2*M_PI, 2*M_PI)-M_PI;
    }

    //std::cout << "1: " << new_value << " 2: " << mean << " !!" << std::endl;

    //{
        Eigen::VectorXd x_new = new_value - mean;
    //std::cout << "x_new: " << x_new << "\n";
        //x_new = x_new.array().min(2 * M_PI - x_new.array());
        //x_new += ((x_new.array()>M_PI).select(-2*M_PI, 0.) + (x_new.array()<-M_PI).select(+2*M_PI, 0.))
        Eigen::VectorXd x_old = old_value - mean;
    for (unsigned int d=0; d<x_new.size(); ++d) {
        x_new[d] += (x_new[d]>M_PI) ? -2*M_PI : (x_new[d]<-M_PI) ? 2*M_PI : 0;
        x_old[d] += (x_old[d]>M_PI) ? -2*M_PI : (x_old[d]<-M_PI) ? 2*M_PI : 0;
    }
    //std::cout << "x_new*: " << x_new << "\n";


            //x_old = x_old.array().min(2 * M_PI - x_old.array());
        //x_old += ((x_old>M_PI).select(-2*M_PI, 0.) + (x_old<-M_PI).select(+2*M_PI, 0.))
    double log_likelihood_new = ((k / 2.) * -std::log(2 * M_PI) - std::log(sampling_transform.trace()) +
                              -0.5 * (x_new).dot(inverse_cov * (x_new)));
        double log_likelihood_old = ((k / 2.) * -std::log(2 * M_PI) - std::log(sampling_transform.trace()) +
                              -0.5 * (x_old).dot(inverse_cov * (x_old)));
        //std::cout << "*Old value likelihood: " << old_value.transpose() << " " << mean.transpose() << " " << log_likelihood_old << "\n";
        //std::cout << "*New value likelihood: " << new_value.transpose() << " " << mean.transpose() << " " << log_likelihood_new << "\n";
    return Eigen::Array<double, 2, 1>(log_likelihood_old, log_likelihood_new);
        //return -(log_likelihood_new - log_likelihood_old);
    //}
    //return -(log_likelihood_new - log_likelihood_old);
    //return 0.0;
}
}
