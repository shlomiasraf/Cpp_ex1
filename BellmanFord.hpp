//
// Created by Shlomi Asraf on 03/05/2024.
//

#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include "Graph.hpp"


using namespace std;

namespace ariel {
    class BellmanFord
    {
    public:
        static vector<int> BellmanFordAlgo(Graph&, int, int);
        static vector<int> BellmanFordToFindNegativeCycle(Graph&);
        static bool contains(std::vector<int>, int);
        static vector<int> checkVerTwice(std::vector<int>);

    };
}





#endif //BELLMANFORD_H
