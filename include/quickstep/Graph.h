
#ifndef QUICKSTEP_GRAPH_H
#define QUICKSTEP_GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <cassert>

namespace quickstep {

class Graph {
public:

    void add_node(unsigned int index, double mass, double x, double y, double z){
        assert(index == nodes.size()); // sanity check on index
        nodes.push_back(mass);
    }

    void add_directed_edge(int index1, int index2) {
        if (index1 >= edges.size())
            edges.resize(index1+1);
        edges[index1].insert(index2);
    }

    void add_edge(int index1, int index2) {
        add_directed_edge(index1, index2);
        add_directed_edge(index2, index1);
    }

    friend std::ostream& operator<<(std::ostream& out, const Graph &g) {
        for (int i=0; i<g.edges.size(); ++i) {
            out << i << "(" << g.nodes[i] << "): ";
            for (int value: g.edges[i]) {
                out << value << " ";
            }
            out << "\n";
        }
        return out;
    }
private:
    std::vector<double> nodes;
    std::vector<std::set<int> > edges;
};

}

#endif // QUICKSTEP_GRAPH_H
