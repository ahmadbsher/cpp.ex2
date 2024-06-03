// Graph.cpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#include "Graph.hpp"

namespace ariel {

    Graph::Graph() : numVertices(0) {}

    void Graph::loadGraph(const vector<vector<int>>& matrix) {
        int size = matrix.size();
        for (const auto& row : matrix) {
            if (row.size() != size) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        adjMatrix = matrix;
        numVertices = size;
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << countEdges() << " edges." << std::endl;
    }

    int Graph::countEdges() const {
        int edges = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (adjMatrix[i][j] != 0) {
                    edges++;
                }
            }
        }
        return edges;
    }

    Graph Graph::operator+(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw invalid_argument("Graphs must be of the same size to add.");
        }
        Graph result;
        result.loadGraph(adjMatrix);
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] += other.adjMatrix[i][j];
            }
        }
        return result;
    }

    Graph& Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }

    Graph Graph::operator-(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw invalid_argument("Graphs must be of the same size to subtract.");
        }
        Graph result;
        result.loadGraph(adjMatrix);
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] -= other.adjMatrix[i][j];
            }
        }
        return result;
    }

    Graph& Graph::operator-=(const Graph& other) {
        *this = *this - other;
        return *this;
    }

    Graph Graph::operator+() const {
        return *this;
    }

    Graph Graph::operator-() const {
        Graph result;
        result.loadGraph(adjMatrix);
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = -adjMatrix[i][j];
            }
        }
        return result;
    }

    bool Graph::operator==(const Graph& other) const {
        return adjMatrix == other.adjMatrix;
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool Graph::operator<(const Graph& other) const {
        if (numVertices != other.numVertices) {
            return numVertices < other.numVertices;
        }
        return countEdges() < other.countEdges();
    }

    bool Graph::operator<=(const Graph& other) const {
        return *this < other || *this == other;
    }

    bool Graph::operator>(const Graph& other) const {
        return !(*this <= other);
    }

    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    Graph& Graph::operator++() {
        for (auto& row : adjMatrix) {
            for (auto& elem : row) {
                elem++;
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph& Graph::operator--() {
        for (auto& row : adjMatrix) {
            for (auto& elem : row) {
                elem--;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    Graph Graph::operator*(int scalar) const {
        Graph result;
        result.loadGraph(adjMatrix);
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] *= scalar;
            }
        }
        return result;
    }

    Graph& Graph::operator*=(int scalar) {
        *this = *this * scalar;
        return *this;
    }

    Graph Graph::operator*(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw invalid_argument("Graphs must be of the same size to multiply.");
        }
        Graph result;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        result.numVertices = numVertices;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                for (int k = 0; k < numVertices; ++k) {
                    result.adjMatrix[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
            }
        }
        return result;
    }

    ostream& operator<<(ostream& os, const Graph& g) {
        for (const auto& row : g.adjMatrix) {
            os << "[ ";
            for (const auto& elem : row) {
                os << elem << " ";
            }
            os << "]\n";
        }
        return os;
    }
}
