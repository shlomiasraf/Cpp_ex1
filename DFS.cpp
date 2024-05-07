//
// Created by Shlomi Asraf on 03/05/2024.
//

#include "DFS.hpp"
#include <queue>
#include <string>
using namespace ariel;
void DFS::DFSAlgo(int v, std::vector<bool> &visited, Graph &graph)
{
    visited[v] = true;
    std::vector<int> neighborsOfV = graph.getNeighbors()[v];
    for (int u : neighborsOfV)
    {
        if (!visited[u])
        {
            DFSAlgo(u, visited, graph);
        }
    }
}
bool DFS::DFSToFindCycle(int v, int parent, std::vector<bool>& visited, Graph& graph, std::vector<int>& path)
{
    visited[v] = true;
    path.push_back(v);
    std::vector<int> neighborsOfV = graph.getNeighbors()[v];
    for (int u : neighborsOfV)
    {
        if (!visited[u])
        {
            if (DFSToFindCycle(u, v, visited, graph, path)) // pass 'v' as parent
            {
                return true;
            }
        }
        else if (u != parent || graph.getIfDirected())
        {
            // Found a back edge, cycle detected
            path.push_back(u);
            return true;
        }
    }
    path.pop_back(); // backtrack
    return false;
}
