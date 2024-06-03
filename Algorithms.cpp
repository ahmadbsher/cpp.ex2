// Algorithms.cpp
// Author: [Your Name]
// Email: [Your Email]
// ID: [Your ID]

#include "Algorithms.hpp"
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
#include <sstream>

namespace ariel {

    bool Algorithms::isConnected(const Graph& g) {
        if (g.numVertices == 0) return true;
        
        std::vector<bool> visited(g.numVertices, false);
        std::queue<int> q;
        q.push(0);
        visited[0] = true;
        
        int visitedCount = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int i = 0; i < g.numVertices; ++i) {
                if (g.adjMatrix[node][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    visitedCount++;
                }
            }
        }
        
        return visitedCount == g.numVertices;
    }

    std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
        if (start < 0 || start >= g.numVertices || end < 0 || end >= g.numVertices) {
            throw std::invalid_argument("Invalid start or end vertex.");
        }
        
        std::vector<int> dist(g.numVertices, INT_MAX);
        std::vector<int> prev(g.numVertices, -1);
        std::vector<bool> visited(g.numVertices, false);
        
        dist[start] = 0;
        
        auto comp = [&dist](int left, int right) { return dist[left] > dist[right]; };
        std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);
        
        pq.push(start);
        
        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            
            for (int v = 0; v < g.numVertices; ++v) {
                if (g.adjMatrix[u][v] != 0) {
                    int alt = dist[u] + g.adjMatrix[u][v];
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        prev[v] = u;
                        pq.push(v);
                    }
                }
            }
        }
        
        if (dist[end] == INT_MAX) return "-1";
        
        std::ostringstream path;
        for (int at = end; at != -1; at = prev[at]) {
            path << at;
            if (at != start) path << "->";
        }
        
        std::string result = path.str();
        std::reverse(result.begin(), result.end());
        return result;
    }

    bool Algorithms::isContainsCycle(const Graph& g) {
        std::vector<bool> visited(g.numVertices, false);
        std::vector<int> parent(g.numVertices, -1);
        
        for (int i = 0; i < g.numVertices; ++i) {
            if (!visited[i]) {
                std::stack<int> s;
                s.push(i);
                
                while (!s.empty()) {
                    int v = s.top();
                    s.pop();
                    
                    if (!visited[v]) {
                        visited[v] = true;
                    }
                    
                    for (int j = 0; j < g.numVertices; ++j) {
                        if (g.adjMatrix[v][j] != 0) {
                            if (!visited[j]) {
                                s.push(j);
                                parent[j] = v;
                            } else if (parent[v] != j) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        
        return false;
    }

    std::string Algorithms::isBipartite(const Graph& g) {
        if (g.numVertices == 0) return "The graph is bipartite: A={}, B={}";
        
        std::vector<int> colors(g.numVertices, -1);
        colors[0] = 0;
        
        std::queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v = 0; v < g.numVertices; ++v) {
                if (g.adjMatrix[u][v] != 0 && colors[v] == -1) {
                    colors[v] = 1 - colors[u];
                    q.push(v);
                } else if (g.adjMatrix[u][v] != 0 && colors[v] == colors[u]) {
                    return "0"; // False
                }
            }
        }
        
        std::ostringstream setA, setB;
        setA << "A={";
        setB << "B={";
        
        for (int i = 0; i < g.numVertices; ++i) {
            if (colors[i] == 0) setA << i << ",";
            else if (colors[i] == 1) setB << i << ",";
        }
        
        std::string a = setA.str();
        std::string b = setB.str();
        
        if (a.back() == ',') a.pop_back();
        if (b.back() == ',') b.pop_back();
        
        a += "}";
        b += "}";
        
        return "The graph is bipartite: " + a + ", " + b;
    }
}
