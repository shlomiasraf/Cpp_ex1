/* ID: 207970252
    Mail: Shlomi55577@gmail.com */

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == 1);
}
TEST_CASE("Test isConnected2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph= {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}
TEST_CASE("Test isConnected3")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph= {
        {0, 2, 4, 5, 0},
        {2, 0, 0, 0, 0},
        {4, 0, 0, 0, 0},
        {5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}
TEST_CASE("Test shortestPath") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}
TEST_CASE("Test shortestPath2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test shortestPathWithWeight")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 3},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->1->4");

}
TEST_CASE("Test shortestPathWithWeight2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 3},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->4->3");

}
TEST_CASE("Test shortestPathWithNegativeWeight")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 2},
        {1, 0, 0, 2},
        {0, -1, 0, 5},
        {0, 0, 2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->3->2");

}
TEST_CASE("Test shortestPathWithNegativeWeight2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 4},
        {1, 0, 0, 2},
        {0, -1, 0, 5},
        {0, 0, 2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");

}
TEST_CASE("Test isContainsCycle") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
}
TEST_CASE("Test isContainsCycle2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");
}
TEST_CASE("Test isContainsCycle3")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, 4, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 0, -2, 0},
        {5, 0, 0, 0, -3},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->3->0");
}

TEST_CASE("Test isContainsNegativeCycle")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 2},
        {1, 0, 0, -2},
        {0, -1, 0, 5},
        {0, 0, 2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 1->3->2->1");

}
TEST_CASE("Test isContainsNegativeCycle2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 2, 4},
        {1, 0, -1, 0},
        {0, -1, 0, 0},
        {0, 0, 2, 0,}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 1->2->1");

}
TEST_CASE("Test isContainsNegativeCycle3")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, 4, 0, 0},
        {0, 0, 2, 0, 0},
        {0, 0, 0, -2, 0},
        {5, 0, 0, 0, -3},
        {0, 0, 4, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 3->4->2->3");

}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
}
TEST_CASE("Test isBipartite2")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test isBipartite3")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test empty graph")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {};
    CHECK_THROWS(g.loadGraph(graph));
}