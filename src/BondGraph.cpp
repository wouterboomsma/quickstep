#include "quickstep/BondGraph.h"

#include <iostream>
namespace quickstep{

BondGraph::BondGraph(int atoms_):
    atoms(atoms_),
    adjacencyList(atoms_)
{
}

void BondGraph::bond(int a1, int a2)
{
    if(a1==a2 || a1>=atoms || a2>=atoms || a1<0 || a2<0) return;

    //Return if they are already bonded
    for(size_t i=0;i<adjacencyList[a1].size();i++)
        if(adjacencyList[a1][i]==a2)
            return;

    adjacencyList[a1].push_back(a2);
    adjacencyList[a2].push_back(a1);
}

void BondGraph::unbond(int a1, int a2)
{
    if(a1==a2 || a1>=atoms || a2>=atoms || a1<0 || a2<0) return;

    for(size_t i=0;i<adjacencyList[a1].size();i++)
        if(adjacencyList[a1][i]==a2){
            adjacencyList[a1].erase(adjacencyList[a1].begin()+i);
            break;
        }
    for(size_t i=0;i<adjacencyList[a2].size();i++)
        if(adjacencyList[a2][i]==a1){
            adjacencyList[a2].erase(adjacencyList[a2].begin()+i);
            break;
        }
}

void BondGraph::addChangeListener()
{
    //TODO: Implement
}


void BondGraph::print()
{
    std::cout<<"BondGraph:"<<std::endl;
    for(int v=0;v<adjacencyList.size();v++){
        std::cout<<"  adjacencies["<<v<<"]: ";
        for(int a=0;a<adjacencyList[v].size();a++)
            std::cout<<" "<<adjacencyList[v][a];

        std::cout<<std::endl;
    }

}

}

