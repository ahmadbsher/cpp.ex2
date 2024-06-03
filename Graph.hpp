// Graph.hpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

using std::vector;
using std::ostream;
using std::invalid_argument;

namespace ariel {
    class Graph {
    private:
        vector<vector<int>> adjMatrix;
        int numVertices;
        int countEdges() const;

    public:
        Graph();
        void loadGraph(const vector<vector<int>>& matrix);
        void printGraph() const;

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator+() const; // Unary plus
        Graph operator-() const; // Unary minus

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Increment and decrement operators
        Graph& operator++();    // Prefix increment
        Graph operator++(int);  // Postfix increment
        Graph& operator--();    // Prefix decrement
        Graph operator--(int);  // Postfix decrement

        // Scalar multiplication
        Graph operator*(int scalar) const;
        Graph& operator*=(int scalar);

        // Graph multiplication
        Graph operator*(const Graph& other) const;

        // Output operator
        friend ostream& operator<<(ostream& os, const Graph& g);
    };
}

#endif // GRAPH_HPP
