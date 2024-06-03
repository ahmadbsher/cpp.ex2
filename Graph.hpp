// Graph.hpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    public:
        std::vector<std::vector<int>> adjMatrix;
        int numVertices;

        Graph();

        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;

        // Arithmetic operators
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator+() const; // Unary plus
        Graph operator-() const; // Unary minus
        Graph& operator++();     // Prefix increment
        Graph operator++(int);   // Postfix increment
        Graph& operator--();     // Prefix decrement
        Graph operator--(int);   // Postfix decrement
        Graph operator*(int scalar) const;
        Graph& operator*=(int scalar);
        Graph operator/(int scalar) const;
        Graph& operator/=(int scalar);
        Graph operator*(const Graph& other) const;

        // Comparison operators
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // Output operator
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);
    };
}

#endif // GRAPH_HPP
