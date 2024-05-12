/* ID: 207970252
    Mail: Shlomi55577@gmail.com */
    
#include "Graph.hpp"
#include <iostream>
#include <vector>


ariel::Graph::Graph() = default;


void ariel::Graph::loadGraph(std::vector<std::vector<int> >& graph)
{
    // Check if the graph is matrix
    int numRows = graph.size();
    if(graph.size() == 0)
    {
        throw std::invalid_argument("Invalid graph: The graph is empty.");
    }
    else
    {
        int numCols = graph[0].size();
        if (numRows != numCols)
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    this-> graph = graph;
    this->numVertices = (int)graph.size();
    this->numEdges = 0;
    this->hasNegativeEdge = false;
    this->isDirected = false;
    this->hasWeight = false;
    this->neighbors = {};
    this->neighbors.resize(numVertices);
    this->edges = std::vector<Edge>();
    for(int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if(this->graph[i][j] < 0)
            {
                this->hasNegativeEdge = true;
            }
            if(this->graph[i][j] != this->graph[j][i])
            {
                this->isDirected = true;
            }
            if(this->graph[i][j] != 0)
            {
                Edge edge;
                edge.source = i;
                edge.dest = j;
                edge.weight = graph[i][j];
                this->edges.push_back(edge);
                this->numEdges++;
                this->neighbors[i].push_back(j);
            }
            if(this->graph[i][j] != 0 && this->graph[i][j] != 1)
            {
                this->hasWeight = true;
            }
        }
    }
}
void ariel::Graph::printGraph()
{
    if(this->isDirected)
    {
        std::cout << "Graph with " << this->numVertices << " vertices and " << this->numEdges << " edges." << std::endl;
    }
    else
    {
        std::cout << "Graph with " << this->numVertices << " vertices and " << this->numEdges/2 << " edges." << std::endl;
    }
}
int ariel::Graph::getNumVertices()
{
    return this->numVertices;
}
std::vector<std::vector<int>> ariel::Graph::getNeighbors()
{
    return this->neighbors;
}
bool ariel::Graph::getIfDirected()
{
    return this->isDirected;
}
std::vector<std::vector<int> > ariel::Graph::getMatrix() 
{
    return this->graph;
}
bool ariel::Graph::getIfHasNegetiveEdge()
{
    return this->hasNegativeEdge;
}
bool ariel::Graph::getIfHasWeight()
{
    return this->hasWeight;
}
int ariel::Graph::getNumEdges()
{
    return this->numEdges;
}
