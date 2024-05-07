#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace ariel;
using namespace std;


Graph::Graph() =default;


void Graph::loadGraph(vector<vector<int> >& graph)
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
            if(graph[i][j] < 0)
            {
                hasNegativeEdge = true;
            }
            if(graph[i][j] != graph[j][i])
            {
                isDirected = true;
            }
            if(graph[i][j] != 0)
            {
                Edge edge;
                edge.source = i;
                edge.dest = j;
                edge.weight = graph[i][j];
                edges.push_back(edge);
                numEdges++;
                neighbors[i].push_back(j);
            }
            if(graph[i][j] != 0 && graph[i][j] != 1)
            {
                hasWeight = true;
            }
        }
    }
}
void Graph::printGraph()
{
    cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << endl;
}
int Graph::getNumVertices()
{
    return numVertices;
}
std::vector<std::vector<int>> Graph::getNeighbors()
{
    return neighbors;
}
bool Graph::getIfDirected()
{
    return isDirected;
}
std::vector<std::vector<int> > Graph::getMatrix() {
    return graph;
}
bool Graph::getIfHasNegetiveEdge()
{
    return hasNegativeEdge;
}
bool Graph::getIfHasWeight()
{
    return hasWeight;
}
int Graph::getNumEdges()
{
    return numEdges;
}
