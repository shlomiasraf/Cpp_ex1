//
// Created by Shlomi Asraf on 03/05/2024.
//

#ifndef DFS_H
#define DFS_H
#include "Graph.hpp"

using namespace std;

namespace ariel {
    class DFS
    {
        public:
            static void DFSAlgo(int, std::vector<bool>&, Graph&);
            static bool DFSToFindCycle(int, int, std::vector<bool>&, Graph&, std::vector<int>&);
    };
}


#endif //DFS_H
