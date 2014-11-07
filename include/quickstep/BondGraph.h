#ifndef BONDGRAPH_H
#define BONDGRAPH_H

#include <vector>

namespace quickstep{

/**
 * @brief A graph representation of the bonding relationship between all atoms in a molecule
 * TODO: Expand
 */
class BondGraph
{
public:
    /** Construct a bond graph with the specified number of atoms and
     * no bonds. */
    BondGraph(int atoms=0);

    /** Create bond between atoms a1 and a2. If bond already exist
     * nothing will be done. */
    void bond(int a1, int a2);

    /** Remove bond between atoms a1 and a2. If no bond exists nothing
     * will be done. */
    void unbond(int a1, int a2);

    void addAtom();//TODO:
    void removeAtom();//TODO:

    /** Return the number of atoms in this graph */
    int numberOfAtoms(){ return atoms; }

    void addChangeListener();//TODO: Finish

    void print();

private:
    int atoms;
    std::vector< std::vector<int> > adjacencyList;
    friend class KinematicForest;

};

}

#endif // BONDGRAPH_H
