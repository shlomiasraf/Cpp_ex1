//
// Created by Shlomi Asraf on 30/04/2024.
//

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"

using namespace std;


namespace ariel
{
    class Algorithms
    {
        public:
            static int isConnected(Graph&);
            static string shortestPath(Graph&, int, int);
            static string isContainsCycle(Graph&);
            static string isBipartite(Graph&);
            static string negativeCycle(Graph&);

    };
}

#endif //ALGORITHMS_HPP
