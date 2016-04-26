#ifndef QUICKSTEP_DOF_H
#define QUICKSTEP_DOF_H

#include <vector>
#include <memory>

namespace quickstep {

class KinematicForest;

class Dof {
public:
    typedef enum {UNDEFINED=0, LENGTH=1, ANGLE=2, DIHEDRAL=3} Type;

    virtual double get_value() = 0;

    virtual void add_value(double value) = 0;

    virtual void set_value(double value);

    virtual Type get_type();

    static std::unique_ptr<Dof> construct(KinematicForest &forest,
                                          const std::vector<int> &atom_indices,
                                          const std::vector<std::string> &atom_names={});

    const int get_atom_index();

    const std::vector<std::vector<int>> get_atoms();

    KinematicForest &get_forest();

protected:
    Dof(KinematicForest &forest,
        int atom_index,
        Type type)
            : forest(forest),
              atom_index(atom_index),
              type(type){}

    KinematicForest &forest;
    int atom_index;
    Type type;
};

}

#endif //PHAISTOS_DOF_H
