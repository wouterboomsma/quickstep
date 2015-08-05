#ifndef QUICKSTEP_SELECTION_H
#define QUICKSTEP_SELECTION_H

#include <memory>
#include <vector>
#include <string>

#include <Eigen/Dense>
#include <set>
#include <algorithm>
#include "quickstep/FatalError.h"
#include "Topology.h"

namespace quickstep {

class Topology;
class Filter;

/** \class Selection
  *
  * \brief Class representing atom selections in a \ref Topology.
  *
  * Makes it possible to select atoms using text-expressions. For instance,
  * all CA atoms from residue 2-4 can be selected by:
  *
  * \code
  * Selection::parse(topology, "resi 2 to 4 and name CA")
  *
  * Selections are typically created by calling \ref Topology::Select.
  *
  */
class Selection {
public:

    /** Create a selection from an expression.
     *  @param topology The topology
     *  @param selection_string The expression */
    static Selection parse(Topology &topology, const std::string &selection_string);

    /** Create a selection.
     *  @param active_atoms Incident matrix specifying which atoms are included in the selection
     *  @param active_bonds Set of vectors containing connected stretches of atoms */
    Selection(Topology &topology,
              const Eigen::Array<bool, Eigen::Dynamic, 1> &active_atoms={},
              std::set<std::vector<unsigned int> > active_bonds=std::set<std::vector<unsigned int> >{}):
            topology(topology), active_atoms(active_atoms), active_bonds(active_bonds){}

    /** And operation
     *  (overrides bitwise operator since this fits better with the semantics and return
     *  type (the operation is applied to all entries in the active_atoms vector.
     *  @param other Other selection operand. */
    Selection operator&(const Selection &other) const {
        std::set<std::vector<unsigned int> > intersect_active_bonds;
        std::set_intersection(active_bonds.begin(), active_bonds.end(),
                              other.active_bonds.begin(), other.active_bonds.end(),
                              std::inserter(intersect_active_bonds, intersect_active_bonds.begin()));
        return Selection(other.topology,
                         active_atoms && other.active_atoms,
                         std::move(intersect_active_bonds));
    }

    /** Or operation
     *  (overrides bitwise operator since this fits better with the semantics and return
     *  type (the operation is applied to all entries in the active_atoms vector.
     *  @param other Other selection operand. */
    Selection operator|(const Selection &other) const {
        std::set<std::vector<unsigned int> > union_active_bonds;
        std::set_union(active_bonds.begin(), active_bonds.end(),
                       other.active_bonds.begin(), other.active_bonds.end(),
                       std::inserter(union_active_bonds, union_active_bonds.begin()));
        return Selection(other.topology,
                         active_atoms || other.active_atoms,
                         std::move(union_active_bonds));
    }

    /** Not operation
     *  (overrides bitwise operator since this fits better with the semantics and return
     *  type (the operation is applied to all entries in the active_atoms vector.
     *  @param other Other selection operand. */
    Selection operator~() const {
        if (active_bonds.size() > 0) {
            BOOST_THROW_EXCEPTION(FatalError() <<
                                  "! operator not defined for bond selections.");
        }
        return Selection(topology,
                         active_atoms.unaryExpr(std::logical_not<void>()),
                         active_bonds);
    }

    /** \returns iterable over currently selected atoms */
    std::vector<std::reference_wrapper<Topology::Atom>> get_atoms();

    /** \returns iterable over currently selected bonds */
    std::vector<std::vector<std::reference_wrapper<Topology::Atom>>> get_bonds();

    /** \returns selected atom incident vector. */
    const Eigen::Array<bool, Eigen::Dynamic, 1> &get_active_atom_map() const {
        return active_atoms;
    };

    /**  Apply selection to filter a container over atom indices
     *   @param source Any container over atom indices
     *   @tparam TYPE Type of input container
     *   \returns container of the same type only selecting matched atoms. */
    template<typename TYPE>
    TYPE filter(const TYPE &source);

private:

    Eigen::Array<bool, Eigen::Dynamic, 1> active_atoms;
    std::set<std::vector<unsigned int> > active_bonds;

    Topology &topology;
};

/** Overloads for filter operation on specific containers: general vector
 *  @param selection Selection used as basis for filter
 *  @param source Object to be filtered
 *  \returns a vector consisting of the entries that matched the selection **/
template <typename TYPE>
std::vector<TYPE> filter(const Selection &selection, const std::vector<TYPE> &source) {
    std::vector<TYPE> output;
    if (source.size() != selection.get_active_atom_map().size())
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "Mismatch between filter and target sequence size.");
    for (unsigned int i = 0; i < source.size(); ++i) {
        if (selection.get_active_atom_map()[i])
            output.push_back(source[i]);
    }
    return output;
}

/** Overloads for filter operation on specific containers: Eigen array<fixed,dynamic>
 *  @param selection Selection used as basis for filter
 *  @param source Object to be filtered
 *  \returns a vector consisting of the entries that matched the selection **/
template <typename TYPE, template <typename,int,int,int,int,int> class EIGEN_TYPE, int DIM1, int _Options, int _MaxRows, int _MaxCols>
const EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols> filter(const Selection &selection, const Eigen::ArrayBase<EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols>> &source) {
    if (source.cols() != selection.get_active_atom_map().size())
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "Mismatch between filter and target sequence size.");

    int entries = selection.get_active_atom_map().count();
    EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols> output(DIM1, entries);
    int added = 0;
    for (unsigned int i = 0; i < source.cols(); ++i) {
        if (selection.get_active_atom_map()[i]) {
            output.col(added) = source.col(i);
            added++;
        }
    }
    return output;
}

/** Overloads for filter operation on specific containers: Eigen array<dynamic,fixed>
 *  @param selection Selection used as basis for filter
 *  @param source Object to be filtered
 *  \returns a vector consisting of the entries that matched the selection **/
template <typename TYPE, template <typename,int,int,int,int,int> class EIGEN_TYPE, int DIM1, int _Options, int _MaxRows, int _MaxCols, typename Unit>
const Eigen::Quantity<EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols>, Unit> filter(const Selection &selection, const Eigen::Quantity<EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols>, Unit> &source) {
    if (source.cols() != selection.get_active_atom_map().size())
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "Mismatch between filter and target sequence size.");

    int entries = selection.get_active_atom_map().count();
    Eigen::Quantity<EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols>,Unit> output(EIGEN_TYPE<TYPE, DIM1, Eigen::Dynamic, _Options, _MaxRows, _MaxCols>(DIM1, entries));
    int added = 0;
    for (unsigned int i = 0; i < source.cols(); ++i) {
        if (selection.get_active_atom_map()[i]) {
            output.col(added) = source.col(i);
            added++;
        }
    }
    return output;
}

/** Overloads for filter operation on specific containers: Eigen Quantity array<fixed, dynamic>
 *  @param selection Selection used as basis for filter
 *  @param source Object to be filtered
 *  \returns a vector consisting of the entries that matched the selection **/
template <typename TYPE, template <typename,int,int,int,int,int> class EIGEN_TYPE, int DIM2, int _Options, int _MaxRows, int _MaxCols>
const EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols> filter(const Selection &selection, const Eigen::ArrayBase<EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols>> &source) {
    if (source.rows() != selection.get_active_atom_map().size())
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "Mismatch between filter and target sequence size.");

    int entries = selection.get_active_atom_map().count();
    EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols> output(entries, DIM2);
    int added = 0;
    for (unsigned int i = 0; i < source.rows(); ++i) {
        if (selection.get_active_atom_map()[i]) {
            output.row(added) = source.row(i);
            added++;
        }
    }
    return output;
}

/** Overloads for filter operation on specific containers: Eigen Quantity array<dynamic, fixed>
 *  @param selection Selection used as basis for filter
 *  @param source Object to be filtered
 *  \returns a vector consisting of the entries that matched the selection **/
template <typename TYPE, template <typename,int,int,int,int,int> class EIGEN_TYPE, int DIM2, int _Options, int _MaxRows, int _MaxCols, typename Unit>
const Eigen::Quantity<EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols>, Unit> filter(const Selection &selection, const Eigen::Quantity<EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols>, Unit> &source) {
    if (source.rows() != selection.get_active_atom_map().size())
        BOOST_THROW_EXCEPTION(FatalError() <<
                              "Mismatch between filter and target sequence size.");

    int entries = selection.get_active_atom_map().count();
    Eigen::Quantity<EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols>,Unit> output(EIGEN_TYPE<TYPE, Eigen::Dynamic, DIM2, _Options, _MaxRows, _MaxCols>(entries, DIM2));
    int added = 0;
    for (unsigned int i = 0; i < source.rows(); ++i) {
        if (selection.get_active_atom_map()[i]) {
            output.row(added) = source.row(i);
            added++;
        }
    }
    return output;
}

template<typename TYPE>
TYPE Selection::filter(const TYPE &source) {
    return quickstep::filter(*this, source);
}

}

#endif // QUICKSTEP_SELECTION_H
