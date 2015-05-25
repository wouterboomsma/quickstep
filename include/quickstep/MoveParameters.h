#ifndef QUICKSTEP_MOVE_PARAMETERS_H
#define QUICKSTEP_MOVE_PARAMETERS_H

#include <string>
#include "quickstep/MolecularParameters.h"
#include <boost/property_tree/ptree_fwd.hpp>

namespace quickstep {

class MoveParameters: public MolecularParameters {
private:

    void parse_dofs(const boost::property_tree::ptree &parameter_input, std::vector<std::string> group_names = {});

public:

    struct DofData {
        std::string name;
        std::vector<std::string> residue_names;
        std::vector<std::string> atom_names;

        std::vector<int> atom_types;
        friend std::ostream& operator<<(std::ostream& o, const DofData &data) {
            o << data.name << " ";
            o << data.residue_names << " ";
            o << data.atom_names << " ";
            o << data.atom_types;
            return o;
        }
    };

    virtual void parse_from_XML(const boost::property_tree::ptree &parameter_input);

    std::map<std::string, MoveParameters::DofData> dof_data;

};

}

#endif // QUICKSTEP_MOVE_PARAMETERS_H
