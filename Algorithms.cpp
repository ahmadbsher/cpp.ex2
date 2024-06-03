// Algorithms.cpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#include "Algorithms.hpp"
#include <queue>
#include <stack>
#include <limits>
#include <functional>
#include <iostream>

using namespace std;

namespace ariel {

    bool Algorithms::isConnected(const Graph& g) {
        if (g.numVertices == 0) return false;

        vector<bool> visited(g.numVertices, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        int visitedCount = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i = 0; i < g.numVertices; ++i) {
                if (g.adjMatrix[v][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    ++visitedCount;
                }
            }
        }

        return visitedCount == g.numVertices;
    }

    vector<int> Algorithms::shortestPath(const Graph& g, int start, int end) {
        vector<int> dist(g.numVertices, numeric_limits<int>::max());
        vector<int> prev(g.numVertices, -1);
        vector<bool> visited(g.numVertices, false);

        dist[start] = 0;
        for (int i = 0; i < g.numVertices - 1; ++i) {
            int minDist = numeric_limits<int>::max();
            int u = -1;

            for (int j = 0; j < g.numVertices; ++j) {
                if (!visited[j] && dist[j] < minDist) {
                    minDist = dist[j];
                    u = j;
                }
            }

            if (u == -1) break;

            visited[u] = true;

            for (int v = 0; v < g.numVertices; ++v) {
                if (!visited[v] && g.adjMatrix[u][v] != 0 && dist[u] + g.adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + g.adjMatrix[u][v];
                    prev[v] = u;
                }
            }
        }

        if (dist[end] == numeric_limits<int>::max()) {
            return {-1};
        }

        vector<int> path;
        for (int v = end; v != -1; v = prev[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    bool Algorithms::isContainsCycle(const Graph& g) {
        vector<bool> visited(g.numVertices, false);
        vector<bool> recStack(g.numVertices, false);

        function<bool(int)> dfs = [&](int v) {
            visited[v] = true;
            recStack[v] = true;

            for (int i = 0; i < g.numVertices; ++i) {
                if (g.adjMatrix[v][i] != 0) {
                    if (!visited[i] && dfs(i)) {
                        return true;
                    } else if (recStack[i]) {
                        return true;
                    }
                }
            }

            recStack[v] = false;
            return false;
        };

        for (int i = 0; i < g.numVertices; ++i) {
            if (!visited[i] && dfs(i)) {
                return true;
            }
        }

        return false;
    }

    bool Algorithms::isBipartite(const Graph& g) {
        vector<int> colors(g.numVertices, -1);
        queue<int> q;

        for (int i = 0; i < g.numVertices; ++i) {
            if (colors[i] == -1) {
                colors[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    int v = q.front();
                    q.pop();

                    for (int j = 0; j < g.numVertices; ++j) {
                        if (g.adjMatrix[v][j] != 0) {
                            if (colors[j] == -1) {
                                colors[j] = 1 - colors[v];
                                q.push(j);
                            } else if (colors[j] == colors[v]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }

    bool Algorithms::negativeCycle(const Graph& g) {
        vector<int> dist(g.numVertices, numeric_limits<int>::max());
        dist[0] = 0;

        for (int k = 0; k < g.numVertices - 1; ++k) {
            for (int i = 0; i < g.numVertices; ++i) {
                for (int j = 0; j < g.numVertices; ++j) {
                    if (g.adjMatrix[i][j] != 0 && dist[i] != numeric_limits<int>::max() && dist[i] + g.adjMatrix[i][j] < dist[j]) {
                        dist[j] = dist[i] + g.adjMatrix[i][j];
                    }
                }
            }
        }

        for (int i = 0; i < g.numVertices; ++i) {
            for (int j = 0; j < g.numVertices; ++j) {
                if (g.adjMatrix[i][j] != 0 && dist[i] != numeric_limits<int>::max() && dist[i] + g.adjMatrix[i][j] < dist[j]) {
                    return true;
                }
            }
        }

        return false;
    }

}
