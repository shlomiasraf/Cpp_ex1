//
// Created by Shlomi Asraf on 03/05/2024.
//

#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Graph.hpp"

using namespace std;

namespace ariel {
    class Dijkstra
    {
        public:
            static vector<int> DijkstraAlgo(Graph&, int, int);
    };
}



#endif //DIJKSTRA_H
