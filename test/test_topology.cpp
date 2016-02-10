#include "quickstep.h"

using namespace quickstep;

int main(int argc, char *argv[]) {

    Topology topology;

    Topology::Chain& eth_chain = topology.add_chain();
    Topology::Residue& eth_res = topology.add_residue("ETH", eth_chain);

    auto atom_H11 = topology.add_atom("H11",quickstep::Element::HYDROGEN, eth_res);
    auto atom_H12 = topology.add_atom("H12",quickstep::Element::HYDROGEN, eth_res);
    auto atom_C1  = topology.add_atom( "C1",quickstep::Element::CARBON  , eth_res);
    auto atom_O1  = topology.add_atom( "O1",quickstep::Element::OXYGEN  , eth_res);
    auto atom_HO  = topology.add_atom( "HO",quickstep::Element::HYDROGEN, eth_res);
    auto atom_C2  = topology.add_atom( "C2",quickstep::Element::CARBON  , eth_res);
    auto atom_H21 = topology.add_atom("H21",quickstep::Element::HYDROGEN, eth_res);
    auto atom_H22 = topology.add_atom("H22",quickstep::Element::HYDROGEN, eth_res);
    auto atom_H23 = topology.add_atom("H23",quickstep::Element::HYDROGEN, eth_res);


    for (const auto &atom: topology.select("resi 0 and type C").get_atoms())
        std::cout << atom << "\n";

}
