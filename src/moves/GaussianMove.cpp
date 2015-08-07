#include "quickstep/moves/GaussianMove.h"
#include "quickstep/MoveParameters.h"
#include "quickstep/FatalError.h"
#include <boost/property_tree/ptree.hpp>
#include <quickstep/random.h>

namespace quickstep {


// Register move generator with factory
const GaussianMove::MoveGenerator::Registrator GaussianMove::MoveGenerator::registrator;

std::vector<std::unique_ptr<Move>> GaussianMove::MoveGenerator::operator()(const boost::property_tree::ptree &parameter_input,
                                                              Topology &topology,
                                                              const MoveParameters &move_parameters) {
    auto root_node = parameter_input.begin();
    const std::string &node_name = root_node->first;

    int dimension = root_node->second.get<int>("dim");

    Eigen::VectorXd mean = Eigen::VectorXd::Zero(dimension);
    Eigen::MatrixXd cov = Eigen::MatrixXd::Identity(dimension, dimension);

    std::vector<std::string> dofs(dimension);

    double conversion_factor = 1.;
    boost::optional<std::string> unit = root_node->second.get_optional<std::string>("unit");
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

        boost::optional<double> mean_val;
        if ((        (mean_val = root_node->second.get_optional<double>(mean_label_suffixed))) ||
            (i==0 && (mean_val = root_node->second.get_optional<double>(mean_label)))) {
            mean(i) = *mean_val * conversion_factor;
        }

        boost::optional<std::string> dof_val;
        if ((        (dof_val = root_node->second.get_optional<std::string>(dof_label_suffixed))) ||
            (i==0 && (dof_val = root_node->second.get_optional<std::string>(dof_label)))) {
        	if(*dof_val=="")
        		BOOST_THROW_EXCEPTION(FatalError() << "Empty DOF while reading XML: "<<node_name);
            dofs[i] = *dof_val;
        }

        for (int j=i; j<dimension; ++j) {
            std::string stddev_label_suffixed1 = stddev_label + std::to_string(i + 1) + std::to_string(j + 1);
            std::string stddev_label_suffixed2 = stddev_label + std::to_string(j + 1) + std::to_string(i + 1);

            boost::optional<double> sigma_val;
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
                    BOOST_THROW_EXCEPTION(FatalError() <<
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
                            BOOST_THROW_EXCEPTION(FatalError() <<
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
                std::vector<const std::reference_wrapper<const Topology::Atom>> atoms;
                for (unsigned int d=0; d<dof_data.atom_names.size(); ++d) {
                    dof_atoms[i][dof_index][d] = match_atoms.at(template_data.atom_name_lookup.at(dof_data.atom_names[d])).get().index;
                }

            }
        }
    }

    std::vector<std::unique_ptr<Move>> return_value;
    for (auto &realization_dof_atoms: dof_atoms) {
        // std::cout << "GaussianMove residue: " << topology.get_atoms().at(realization_dof_atoms.front().front()).residue.index << " " << topology.get_atoms().at(realization_dof_atoms.front().front()).residue.name << "\n";
        return_value.push_back(std::move(make_unique<GaussianMove>(mean, cov, realization_dof_atoms, dof_atom_names)));
    }

    return std::move(return_value);
}

MoveInfo GaussianMove::propose(KinematicForest &forest) {

    if (dofs.empty()) {
        dofs.clear();
        for (unsigned int i=0; i<dof_atoms.size(); ++i) {
            dofs.push_back(  KinematicForest::DoF::construct(forest, dof_atoms[i], dof_atom_names[i])  );
        }
    }

    Eigen::VectorXd sample{(sampling_transform * Eigen::MatrixXd::NullaryExpr(sampling_transform.rows(), 1,
                                                                              [&](int, int = 0) {
                                                                                  return normal_distribution();
                                                                              })) + mean};
//    Eigen::VectorXd delta_vals(sample.rows(),1);

    MoveInfo ret;

    for (unsigned int d=0; d<sample.rows(); ++d) {
        double a = sample[d] - dofs[d]->get_value();
        //a = (a>180) ? -360 : (a<-180) ? 360 : 0;
        //a += (a>180) ? -360 : (a<-180) ? 360 : 0;
        a += (a>M_PI) ? -2*M_PI : (a<-M_PI) ? 2*M_PI : 0; // Might not strictly be necessary
//        delta_vals[d] = a;
//        dofs[d]->add_value(a);
        //ret.dof_deltas.push_back( std::make_pair( *dofs[d].get(), a ) );
        DOFIndex di = dofs[d]->get_dofindex();
        //ret.dof_deltas.push_back( std::make_pair( di, a ) );

        int parent_index = forest.parent(di.atom_index);

        //Add all children of parent
        for(size_t i=0; i<forest.adjacency_list[parent_index].size();++i){
            if( 	forest.adjacency_list[parent_index][i].first == parent_index){
                di.atom_index = forest.adjacency_list[parent_index][i].second;
                ret.dof_deltas.push_back( std::make_pair( di, a ) );
            }
        }


//    Eigen::VectorXd delta_vals(sample.rows(),1);
//
//    if(!suggest_only){
//        for (unsigned int d=0; d<sample.rows(); ++d) {
//            double a = sample[d] - dofs[d]->get_value();
//            a += (a>180) ? -360 : (a<-180) ? 360 : 0;
//            delta_vals[d] = a;
//            dofs[d]->add_value(a);
////            dofs[d]->set_value(sample[d]);
//        }
//        forest.updatePositions();

    }


    //Set up move info
//    MoveInfo ret{ make_unique<GaussianMoveInfo>(delta_vals) };
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

}
