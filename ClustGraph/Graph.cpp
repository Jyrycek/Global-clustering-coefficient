#include "Graph.h"

void Graph::checkSize(int u, int v) {
    // Ensure the adjacency list is large enough to hold the vertices
    while (u >= static_cast<int>(vertices.size())) {
        vertices.emplace_back();
    }
    while (v >= static_cast<int>(vertices.size())) {
        vertices.emplace_back();
    }
}

void Graph::add_edge(int u, int v) {
    checkSize(u, v);

    vertices[u].push_back(v);
    vertices[v].push_back(u);
}

std::unordered_set<int> Graph::bfs(int v, std::vector<bool>& visited) {
    std::unordered_set<int> currentComponent;

    std::queue<int> queue;
    queue.push(v);

    while (!queue.empty()) {
        v = queue.front();
        queue.pop();

        currentComponent.insert(v);
        visited[v] = true;

        for (auto u : vertices[v]) {
            if (!visited[u]) {
                visited[u] = true;
                queue.push(u);
            }
        }
    }

    return currentComponent;
}

int Graph::getLargestComponentSize() {
    std::vector<bool> visited(vertices.size(), false);
    std::unordered_set<int> currentComponent;

    for (int i = 0; i < static_cast<int>(vertices.size()); i++) {
        if (!visited[i]) {
            currentComponent = bfs(i, visited);

            if (currentComponent.size() > largestComponent.size()) {
                largestComponent = currentComponent;
            }
        }
    }

    return static_cast<int>(largestComponent.size());
}

int Graph::countTriangles(int vertex) {
    int triangleCount = 0;
    std::vector<int> neighbors = vertices[vertex];

    for (size_t i = 0; i < neighbors.size(); i++) {
        for (size_t j = i + 1; j < neighbors.size(); j++) {
            if (isConnected(neighbors[i], neighbors[j])) {
                triangleCount++;
            }
        }
    }

    return triangleCount;
}

bool Graph::isConnected(int u, int v) {
    for (auto neighbor : vertices[u]) {
        if (neighbor == v) {
            return true;
        }
    }
    return false;
}

double Graph::getGlobalClusteringCoefficient() {
    double triangleSum = 0.0;
    double pairSum = 0.0;

    for (auto vertex : largestComponent) {
        int neighborCount = static_cast<int>(vertices[vertex].size());

        if (neighborCount < 2) {
            continue;
        }

        triangleSum += 2.0 * countTriangles(vertex);
        pairSum += neighborCount * (neighborCount - 1);
    }

    return triangleSum / pairSum;
}
