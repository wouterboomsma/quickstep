#ifndef QUICKSTEP_MOLECULAR_COMMON_DEFINITIONS_H
#define QUICKSTEP_MOLECULAR_COMMON_DEFINITIONS_H

#include <string>
#include "quickstep/Topology.h"
#include "quickstep/FatalError.h"
#include <qsboost/property_tree/ptree_fwd.hpp>

namespace quickstep {

// Parameter utilities for forcefield and move parameters
class MolecularCommonDefinitions {
public:

    struct AtomTypeData {
        std::string class_attr;
        double mass;
        Element element;

        friend bool operator<(const AtomTypeData &atom_type1, const AtomTypeData &atom_type2) {
            return (atom_type1.mass < atom_type2.mass);
        }
        //! Overload output operator
        friend std::ostream& operator<<(std::ostream& o, const AtomTypeData &type) {
            o << "class:" << type.class_attr;
            return o;
        }
    };

    struct TemplateAtomData {
        std::string name;
        std::string type;
        Element element = Element::UNKNOWN;
        std::vector<int> bonded_to;
        int external_bonds = 0;

        //! Overload output operator
        friend std::ostream& operator<<(std::ostream& o, const TemplateAtomData &data) {
            o << "name:" << data.name;
            return o;
        }
    };

    struct VirtualSiteData {
        int index;
        std::string type;
        std::vector<int> atoms;
        std::vector<double> weights;
        std::vector<double> origin_weights;
        std::vector<double> x_weights;
        std::vector<double> y_weights;
        std::vector<double> local_position;
        int exclude_with;
    };

    struct TemplateData {
        std::string name;
        std::vector<TemplateAtomData> atoms;
        std::map<std::string, int> atom_name_lookup;
        std::vector<VirtualSiteData> virtual_sites;
        std::vector<std::pair<int, int> > bonds;
        std::vector<int> external_bonds;
        //! Overload output operator
        friend std::ostream& operator<<(std::ostream& o, const TemplateData &data) {
            o << "name:" << data.name;
            return o;
        }
    };


    virtual void parse_from_XML(const qsboost::property_tree::ptree &parameter_input);

    void parse_from_XML(const std::string &filename);

    bool find_atom_matches(const std::vector<unsigned int> residue_atom_indices,
                           const std::vector<Topology::Atom> &atoms,
                           const TemplateData &residue_template,
                           const std::vector<std::vector<int> > &bonded_to,
                           const std::vector<int> &external_bonds,
                           std::vector<int> &matches,
                           std::vector<bool> &has_match,
                           int position=0) const;

    std::vector<int> match_residue_atoms(const Topology::Residue &residue,
                                         const std::vector<Topology::Atom> &atoms,
                                         const TemplateData &residue_template,
                                         const std::vector<std::set<int> > &bonded_to_atom) const;

    std::string find_match_errors(const Topology::Residue &residue,
                                  const std::vector<Topology::Atom> &atoms) const;


    const TemplateData &get_residue_template(std::string residue_name) const {
    	if(templates.count(residue_name)==0){
    		QSBOOST_THROW_EXCEPTION(FatalError() <<
    		    	    		"Residue named " << residue_name << " not specified in xml");
    	}
        return templates.at(residue_name);
    }

    const std::string &get_residue_signature(std::string residue_name) const {
        return signature_from_residue_name.at(residue_name);
    }

    const std::map<std::string, std::vector<TemplateData> > &get_residue_signatures() const {
        return templates_from_signature;
    }


private:

    std::map<std::string, AtomTypeData> atom_types;


    std::map<std::string, TemplateData> templates;
    std::map<std::string, std::string> signature_from_residue_name;
    std::map<std::string, std::vector<TemplateData> > templates_from_signature;

};

}

#endif // QUICKSTEP_MOLECULAR_PARAMETERS_H
