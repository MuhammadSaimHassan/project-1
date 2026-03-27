#include <iostream>
#include "../include/FileParser.h"
#include "../include/Graph.h"

using namespace std;

int main() {
    // 1. Load Raw Data
    SimpleVector<Port> rawPorts;
    SimpleVector<Route> rawRoutes;
    FileParser parser;
    
    parser.loadPorts("../data/PortCharges.txt", rawPorts);
    parser.loadRoutes("../data/Routes.txt", rawRoutes);

    // 2. Build Graph
    Graph oceanGraph;

    // Add all ports first (Nodes)
    for(int i = 0; i < rawPorts.size(); i++) {
        oceanGraph.addPort(rawPorts[i]);
    }

    // Add all routes (Edges)
    // We pass the address of rawRoutes[i] so we don't duplicate data
    for(int i = 0; i < rawRoutes.size(); i++) {
        oceanGraph.addEdge(
            rawRoutes[i].origin, 
            rawRoutes[i].destination, 
            rawRoutes[i].cost, 
            &rawRoutes[i]
        );
    }

    // 3. Display
    oceanGraph.displayGraph();

    return 0;
}