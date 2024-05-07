//
// Created by Shlomi Asraf on 03/05/2024.
//

#ifndef BFS_H
#define BFS_H
#include "Graph.hpp"


using namespace std;

namespace ariel {
    class BFS
    {
    public:
        static vector<int> BFSAlgo(Graph&, int, int);
    };
}


#endif //BFS_H
