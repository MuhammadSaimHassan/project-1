#include <iostream>
#include "../include/SimpleVector.h"
#include "../include/DataStructs.h"
#include "../include/FileParser.h"
#include "../include/Graph.h"
#include "../include/Algorithms.h"

using namespace std;

int main() {
    // ==========================================================
    // Step 1: Load data from files
    // ==========================================================
    SimpleVector<Port> ports;
    SimpleVector<Route> routes;
    FileParser parser;

    cout << "=== OceanRoute Nav - Algorithm Test ===" << endl;
    cout << endl;

    cout << "Loading Ports..." << endl;
    parser.loadPorts("../data/PortCharges.txt", ports);
    
    cout << "Loading Routes..." << endl;
    parser.loadRoutes("../data/Routes.txt", routes);

    cout << "Total Ports Loaded: " << ports.size() << endl;
    cout << "Total Routes Loaded: " << routes.size() << endl;
    cout << endl;

    // ==========================================================
    // Step 2: Build the Graph
    // ==========================================================
    Graph graph;

    // Add all ports to the graph
    for (int i = 0; i < ports.size(); i++) {
        graph.addPort(ports[i]);
    }
    cout << "Added " << graph.ports.size() << " ports to graph." << endl;

    // Add all routes as edges to the graph
    for (int i = 0; i < routes.size(); i++) {
        graph.addEdge(routes[i].origin, routes[i].destination, routes[i].cost, &routes[i]);
    }
    cout << "Added edges from " << routes.size() << " routes." << endl;
    cout << endl;

    // ==========================================================
    // Test 1: A* Cost - Karachi to Singapore
    // ==========================================================
    cout << "========================================" << endl;
    cout << "TEST 1: A* (Cost) - Karachi to Singapore (Dec 26)" << endl;
    cout << "========================================" << endl;

    PathResult resultCost1 = findPath(graph, "Karachi", "Singapore", MODE_ASTAR_COST, 26);

    if (resultCost1.path.size() > 0) {
        cout << "Path found!" << endl;
        cout << "Route: ";
        for (int i = 0; i < resultCost1.path.size(); i++) {
            cout << graph.ports[resultCost1.path[i]].name;
            if (i < resultCost1.path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Total Cost: $" << resultCost1.totalCost << endl;
    } else {
        cout << "No path found from Karachi to Singapore!" << endl;
    }
    cout << endl;

    // ==========================================================
    // Test 2: A* Time - Karachi to Singapore
    // ==========================================================
    cout << "========================================" << endl;
    cout << "TEST 2: A* (Time) - Karachi to Singapore (Dec 14)" << endl;
    cout << "========================================" << endl;

    PathResult resultTime1 = findPath(graph, "Karachi", "Singapore", MODE_ASTAR_TIME, 14);

    if (resultTime1.path.size() > 0) {
        cout << "Path found!" << endl;
        cout << "Route: ";
        for (int i = 0; i < resultTime1.path.size(); i++) {
            cout << graph.ports[resultTime1.path[i]].name;
            if (i < resultTime1.path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Total Time: " << resultTime1.totalCost << " minutes";
        cout << " (" << (int)(resultTime1.totalCost / 60) << " hours " 
             << (int)resultTime1.totalCost % 60 << " minutes)" << endl;
    } else {
        cout << "No path found from Karachi to Singapore!" << endl;
    }
    cout << endl;

    // ==========================================================
    // Test 3: Dijkstra Cost - Karachi to Singapore
    // ==========================================================
    cout << "========================================" << endl;
    cout << "TEST 3: Dijkstra (Cost) - Karachi to Singapore (Dec 26)" << endl;
    cout << "========================================" << endl;

    PathResult resultCost2 = findPath(graph, "Karachi", "Singapore", MODE_DIJKSTRA_COST, 26);

    if (resultCost2.path.size() > 0) {
        cout << "Path found!" << endl;
        cout << "Route: ";
        for (int i = 0; i < resultCost2.path.size(); i++) {
            cout << graph.ports[resultCost2.path[i]].name;
            if (i < resultCost2.path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Total Cost: $" << resultCost2.totalCost << endl;
    } else {
        cout << "No path found from Karachi to Singapore!" << endl;
    }
    cout << endl;

    // ==========================================================
    // Test 4: Dijkstra Time - Karachi to Singapore
    // ==========================================================
    cout << "========================================" << endl;
    cout << "TEST 4: Dijkstra (Time) - Karachi to Singapore (Dec 26)" << endl;
    cout << "========================================" << endl;

    PathResult resultTime2 = findPath(graph, "Karachi", "Singapore", MODE_DIJKSTRA_TIME, 26);

    if (resultTime2.path.size() > 0) {
        cout << "Path found!" << endl;
        cout << "Route: ";
        for (int i = 0; i < resultTime2.path.size(); i++) {
            cout << graph.ports[resultTime2.path[i]].name;
            if (i < resultTime2.path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Total Time: " << resultTime2.totalCost << " minutes";
        cout << " (" << (int)(resultTime2.totalCost / 60) << " hours " 
             << (int)resultTime2.totalCost % 60 << " minutes)" << endl;
    } else {
        cout << "No path found from Karachi to Singapore!" << endl;
    }
    cout << endl;

    // ==========================================================
    // Additional Tests for Comparison
    // ==========================================================
    cout << "========================================" << endl;
    cout << "COMPARISON: All 4 Modes - Karachi to Singapore (Dec 26)" << endl;
    cout << "========================================" << endl;

    // Dijkstra Cost
    PathResult r1 = findPath(graph, "Karachi", "Singapore", MODE_DIJKSTRA_COST, 26);
    cout << "Dijkstra (Cost): $" << r1.totalCost << " | Hops: " << r1.path.size() - 1 << endl;

    // Dijkstra Time
    PathResult r2 = findPath(graph, "Karachi", "Singapore", MODE_DIJKSTRA_TIME, 26);
    cout << "Dijkstra (Time): " << r2.totalCost << " min | Hops: " << r2.path.size() - 1 << endl;

    // A* Cost
    PathResult r3 = findPath(graph, "Karachi", "Singapore", MODE_ASTAR_COST, 26);
    cout << "A* (Cost):       $" << r3.totalCost << " | Hops: " << r3.path.size() - 1 << endl;

    // A* Time
    PathResult r4 = findPath(graph, "Karachi", "Singapore", MODE_ASTAR_TIME, 26);
    cout << "A* (Time):       " << r4.totalCost << " min | Hops: " << r4.path.size() - 1 << endl;

    cout << endl;
    
    // ==========================================================
    // Test 5: Multi-Leg Route - Karachi -> CapeTown -> Singapore
    // ==========================================================
    cout << "========================================" << endl;
    cout << "TEST 5: Multi-Leg Route (Dec 26)" << endl;
    cout << "Waypoints: Karachi -> CapeTown -> Singapore" << endl;
    cout << "========================================" << endl;
    
    SimpleVector<string> waypoints;
    waypoints.push_back("Karachi");
    waypoints.push_back("CapeTown");
    waypoints.push_back("Singapore");
    
    MultiLegResult multiLegResult = calculateMultiLegRoute(graph, waypoints, MODE_DIJKSTRA_TIME, 26);
    
    if (multiLegResult.isValid) {
        cout << "Multi-leg route VALID!" << endl;
        cout << "Total segments: " << multiLegResult.segments.size() << endl;
        cout << endl;
        
        double totalTime = 0.0;
        
        for (int seg = 0; seg < multiLegResult.segments.size(); seg++) {
            PathResult& segment = multiLegResult.segments[seg];
            
            cout << "--- Leg " << (seg + 1) << ": " 
                 << waypoints[seg] << " -> " << waypoints[seg + 1] << " ---" << endl;
            
            cout << "Route: ";
            for (int i = 0; i < segment.path.size(); i++) {
                cout << graph.ports[segment.path[i]].name;
                if (i < segment.path.size() - 1) {
                    cout << " -> ";
                }
            }
            cout << endl;
            
            cout << "Hops: " << (segment.path.size() - 1) << endl;
            cout << "Time: " << segment.totalCost << " minutes";
            cout << " (" << (int)(segment.totalCost / 60) << " hours " 
                 << (int)segment.totalCost % 60 << " minutes)" << endl;
            cout << endl;
            
            totalTime += segment.totalCost;
        }
        
        cout << "=== TOTAL JOURNEY ===" << endl;
        cout << "Total Time: " << totalTime << " minutes";
        cout << " (" << (int)(totalTime / 60) << " hours " 
             << (int)totalTime % 60 << " minutes)" << endl;
        cout << "Total Cost (with layover charges): $" << multiLegResult.totalCostWithCharges << endl;
        
    } else {
        cout << "Multi-leg route INVALID - No valid path found!" << endl;
    }
    
    cout << endl;
    cout << "=== Algorithm Tests Complete ===" << endl;

    return 0;
}