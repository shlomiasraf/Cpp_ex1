//
// Created by Shlomi Asraf on 03/05/2024.
//

#include "BellmanFord.hpp"
using namespace ariel;
vector<int> BellmanFord::BellmanFordAlgo(Graph &graph, int source, int dest)
{
    std::vector<int> pathVertices;
    std::vector<int> distances(graph.getNumVertices(), std::numeric_limits<int>::max()); // Distance array
    std::vector<int> pi(graph.getNumVertices(), -1); // Predecessor array

    // Initialize distances
    if(graph.getNumVertices() > source)
    {
        distances[source] = 0;
    }
    // Relax edges repeatedly (n-1 times)
    for (int i = 0; i < graph.getNumVertices()-1; i++)
    {
        for (int j = 0; j < graph.getNumEdges(); j++)
        {
            int w = graph.edges[j].weight;

            if (distances[graph.edges[j].source] != std::numeric_limits<int>::max() && distances[graph.edges[j].source] + w < distances[graph.edges[j].dest])
            {
                distances[graph.edges[j].dest] = distances[graph.edges[j].source] + w;
                pi[graph.edges[j].dest] = graph.edges[j].source;
            }
        }
    }
    // Check for negative cycles
    for (int i = 0; i < graph.getNumEdges(); i++)
    {
            int w = graph.edges[i].weight;
            if (distances[graph.edges[i].source] + w < distances[graph.edges[i].dest])
            {
                // Indicates a negative cycle
                return pathVertices;
            }
    }
    while (dest != source)
    {
        pathVertices.push_back(dest);
        dest = pi[dest];
    }
    return pathVertices;
}
std::vector<int> BellmanFord::BellmanFordToFindNegativeCycle(Graph &graph)
{
    // Create a 2D vector to represent the adjacency matrix
    vector<vector<int>> gd(graph.getNumVertices()+1, vector<int>(graph.getNumVertices()+1, 0));

    // Set the first row to represent edges from the new vertex to existing vertices
    for (int j = 1; j < graph.getNumVertices()+1; j++)
    {
        gd[0][j] = std::numeric_limits<int>::max();
    }

    // Copy the existing graph's adjacency matrix into gd, shifting indices by 1
    for (int i = 1; i <= graph.getNumVertices(); i++)
    {
        gd[i][0] = 0;
        for (int j = 1; j <= graph.getNumVertices(); j++)
        {
            gd[i][j] = graph.getMatrix()[i-1][j-1]; // Copy edge weights from the original graph
        }
    }
    // Load the graph from the adjacency matrix
    graph.loadGraph(gd);
    std::vector<int> pathVertices;
    std::vector<int> distances(graph.getNumVertices(), 1000); // Distance array
    std::vector<int> pi(graph.getNumVertices(), -1); // Predecessor array

    // Initialize distances
    if(graph.getNumVertices() > 0)
    {
        distances[0] = 0;
    }
    // Relax edges repeatedly (n-1 times)
    for (int i = 0; i < graph.getNumVertices()-1; i++)
    {
        for (int j = 0; j < graph.getNumEdges(); j++)
        {
            int w = graph.edges[j].weight;
            if (distances[graph.edges[j].source] != std::numeric_limits<int>::max() && distances[graph.edges[j].source] + w < distances[graph.edges[j].dest])
            {
                distances[graph.edges[j].dest] = distances[graph.edges[j].source] + w;
                pi[graph.edges[j].dest] = graph.edges[j].source;
            }
        }
    }
    // Check for negative cycles
    for (int i = 0; i < graph.getNumEdges(); i++)
    {
        int w = graph.edges[i].weight;
        if (distances[graph.edges[i].source] + w < distances[graph.edges[i].dest])
        {
            // Indicates a negative cycle
            int dest = graph.edges[i].dest;
            while(!contains(pathVertices,dest-1))
            {
                pathVertices.push_back(dest-1);
                dest = pi[dest];
            }
            if(pathVertices.size() > 0)
            {
                pathVertices.push_back(dest-1);
                break;
            }
        }
    }
    return pathVertices;
}
bool BellmanFord::contains(std::vector<int> pathVertices, int ver)
{
    for(int i = 0; i < pathVertices.size(); i++)
    {
        if(pathVertices[i] == ver)
        {
            return true;
        }
    }
    return false;
}
