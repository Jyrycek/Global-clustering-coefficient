#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

/**
 * Loads data from a file and stores it into the Graph object.
 * @param filename Name of the file to load from.
 * @param graph Reference to the Graph object.
 * @return True - successful file load, False - failed to load file.
 */
bool loadFromFile(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    int u;
    int v;
    while (file >> u >> v) {
        graph.add_edge(u, v);
    }
    return true;
}

int main() {
    const clock_t startTime = clock();

    auto* graph = new Graph();
    std::string filename = "Graph.txt";

    clock_t checkpoint = clock();

    if (!loadFromFile(filename, *graph)) {
        std::cout << "An error occurred while loading the file!" << std::endl;
        return 1;
    }
    else {
        std::cout << "File was successfully loaded!" << std::endl;
    }

    std::cout << "File load time: " << float(clock() - checkpoint) / CLOCKS_PER_SEC << "s" << std::endl;

    checkpoint = clock();

    std::cout << "Size of largest component K: " << graph->getLargestComponentSize() << std::endl;
    std::cout << "Time to find largest component: " << float(clock() - checkpoint) / CLOCKS_PER_SEC << "s" << std::endl;

    checkpoint = clock();

    std::cout << "Global clustering coefficient of component K: " << graph->getGlobalClusteringCoefficient() << std::endl;
    std::cout << "Time to compute global clustering coefficient: " << float(clock() - checkpoint) / CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Total runtime: " << float(clock() - startTime) / CLOCKS_PER_SEC << "s" << std::endl;

    return 0;
}
