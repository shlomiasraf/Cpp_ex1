cmake_minimum_required(VERSION 3.28)
project(cpp_ex1)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_ex1
        Algorithms.cpp
        Algorithms.hpp
        Graph.cpp
        Graph.hpp
        DFS.cpp
        DFS.hpp
        Dijkstra.cpp
        Dijkstra.hpp
        BFS.cpp
        BFS.hPP
        BellmanFord.cpp
        BellmanFord.hpp
        tests.cpp
        doctest.h
        testCounter.cpp
        demo.cpp
)
