// Algorithms.hpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <queue>

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(const Graph& g);
        static std::vector<int> shortestPath(const Graph& g, int start, int end);
        static bool isContainsCycle(const Graph& g);
        static bool isBipartite(const Graph& g);
        static bool negativeCycle(const Graph& g);
    };
}

#endif // ALGORITHMS_HPP
