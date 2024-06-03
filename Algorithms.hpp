// Algorithms.hpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"

namespace ariel {
    class Algorithms {
    public:
        static bool isConnected(const Graph& g);
        static std::string shortestPath(const Graph& g, int start, int end);
        static bool isContainsCycle(const Graph& g);
        static std::string isBipartite(const Graph& g);
    };
}

#endif // ALGORITHMS_HPP
