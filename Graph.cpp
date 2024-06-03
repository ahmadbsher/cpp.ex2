// Graph.cpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace ariel {

    Graph::Graph() : numVertices(0) {}

    void Graph::loadGraph(const vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (const auto& row : matrix) {
            if (row.size() != n) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        adjMatrix = matrix;
        numVertices = n;
    }

    void Graph::printGraph() const {
        cout << "Graph with " << numVertices << " vertices and ";
        int edges = 0;
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                if (val != 0) ++edges;
            }
        }
        cout << edges << " edges." << endl;
    }

    Graph Graph::operator+(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw invalid_argument("Graphs must be of the same size for addition.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
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
            throw invalid_argument("Graphs must be of the same size for subtraction.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
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
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = -adjMatrix[i][j];
            }
        }
        return result;
    }

    Graph& Graph::operator++() {
        for (auto& row : adjMatrix) {
            for (auto& val : row) {
                ++val;
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
            for (auto& val : row) {
                --val;
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
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = adjMatrix[i][j] * scalar;
            }
        }
        return result;
    }

    Graph& Graph::operator*=(int scalar) {
        for (auto& row : adjMatrix) {
            for (auto& val : row) {
                val *= scalar;
            }
        }
        return *this;
    }

    Graph Graph::operator/(int scalar) const {
        if (scalar == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                result.adjMatrix[i][j] = adjMatrix[i][j] / scalar;
            }
        }
        return result;
    }

    Graph& Graph::operator/=(int scalar) {
        if (scalar == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        for (auto& row : adjMatrix) {
            for (auto& val : row) {
                val /= scalar;
            }
        }
        return *this;
    }

    Graph Graph::operator*(const Graph& other) const {
        if (numVertices != other.numVertices) {
            throw invalid_argument("Graphs must be of the same size for multiplication.");
        }
        Graph result;
        result.numVertices = numVertices;
        result.adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                for (int k = 0; k < numVertices; ++k) {
                    result.adjMatrix[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                }
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
        return numVertices < other.numVertices ||
               (numVertices == other.numVertices && adjMatrix < other.adjMatrix);
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

    std::ostream& operator<<(std::ostream& os, const Graph& g) {
        for (const auto& row : g.adjMatrix) {
            for (const auto& val : row) {
                os << val << " ";
            }
            os << std::endl;
        }
        return os;
    }
}
