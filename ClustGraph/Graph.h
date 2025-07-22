#pragma once
#include <vector>
#include <queue>
#include <unordered_set>

/**
* @brief Class representing a graph
*/
class Graph {

private:
    /**
     * @brief Representation using adjacency list
     */
    std::vector<std::vector<int>> vertices;

    /**
     * @brief Set of vertices in the largest component K
     */
    std::unordered_set<int> largestComponent;

    /**
     * @brief Allocates space for vertices if needed
     * @param u First vertex
     * @param v Second vertex
     */
    void checkSize(int u, int v);

    /**
     * @brief Breadth-first search algorithm
     * @param v Vertex
     * @param visited Reference to vector of visited flags
     * @return Unordered set of visited vertices
     */
    std::unordered_set<int> bfs(int v, std::vector<bool>& visited);

    /**
     * @brief Checks if an edge exists between two vertices
     * @param u First vertex
     * @param v Second vertex
     * @return True if edge exists, False otherwise
     */
    bool isConnected(int u, int v);

    /**
     * @brief Counts the number of connected neighbors forming triangles at a vertex
     * @param vertex Vertex
     * @return Number of neighbors forming triangles
     */
    int countTriangles(int vertex);

public:

    /**
     * @brief Adds an edge between two vertices
     * @param u First vertex
     * @param v Second vertex
     */
    void add_edge(int u, int v);

    /**
     * @brief Calculates the largest component K in the graph G
     * @return Number of vertices in the largest component K
     */
    int getLargestComponentSize();

    /**
     * @brief Calculates the global clustering coefficient of component K
     * @return Global clustering coefficient value
     */
    double getGlobalClusteringCoefficient();
};
