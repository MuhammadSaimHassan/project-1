#include <iostream>
#include "../include/Graph.h"
#include "../include/MinHeap.h"

using namespace std;

void testGraph() {
    cout << "========================================" << endl;
    cout << "         GRAPH TEST" << endl;
    cout << "========================================" << endl;

    Graph g;

    // Create 3 ports
    Port karachi = {"Karachi", 100, 0, 0};
    Port dubai = {"Dubai", 150, 0, 0};
    Port oslo = {"Oslo", 200, 0, 0};

    // Add ports to the graph
    g.addPort(karachi);
    g.addPort(dubai);
    g.addPort(oslo);

    cout << "Added 3 ports: Karachi, Dubai, Oslo" << endl;
    cout << endl;

    // Create some routes for edge data
    Route r1 = {"Karachi", "Dubai", "2025-01-01", "08:00", "14:00", 500, "ShipCo", 6};
    Route r2 = {"Karachi", "Oslo", "2025-01-02", "10:00", "22:00", 1200, "NordicLine", 12};
    Route r3 = {"Dubai", "Oslo", "2025-01-03", "09:00", "20:00", 800, "GulfShip", 11};
    Route r4 = {"Dubai", "Karachi", "2025-01-04", "12:00", "18:00", 450, "ShipCo", 6};

    // Add directed edges
    g.addEdge("Karachi", "Dubai", r1.cost, &r1);
    g.addEdge("Karachi", "Oslo", r2.cost, &r2);
    g.addEdge("Dubai", "Oslo", r3.cost, &r3);
    g.addEdge("Dubai", "Karachi", r4.cost, &r4);

    cout << "Added edges:" << endl;
    cout << "  Karachi -> Dubai ($500)" << endl;
    cout << "  Karachi -> Oslo ($1200)" << endl;
    cout << "  Dubai -> Oslo ($800)" << endl;
    cout << "  Dubai -> Karachi ($450)" << endl;
    cout << endl;

    // Display the graph
    cout << "Graph Adjacency List:" << endl;
    cout << "----------------------" << endl;
    g.displayGraph();
    cout << endl;

    // Test getIndex
    cout << "Testing getIndex():" << endl;
    cout << "  Index of 'Karachi': " << g.getIndex("Karachi") << " (expected: 0)" << endl;
    cout << "  Index of 'Dubai': " << g.getIndex("Dubai") << " (expected: 1)" << endl;
    cout << "  Index of 'Oslo': " << g.getIndex("Oslo") << " (expected: 2)" << endl;
    cout << "  Index of 'London': " << g.getIndex("London") << " (expected: -1)" << endl;
    cout << endl;
}

void testMinHeap() {
    cout << "========================================" << endl;
    cout << "         MIN-HEAP TEST" << endl;
    cout << "========================================" << endl;

    MinHeap<int> heap;

    // Push values: 50, 10, 30, 5, 20
    cout << "Pushing values: 50, 10, 30, 5, 20" << endl;
    heap.push(50);
    heap.push(10);
    heap.push(30);
    heap.push(5);
    heap.push(20);

    cout << "Heap size after pushes: " << heap.size() << " (expected: 5)" << endl;
    cout << "Top element (min): " << heap.top() << " (expected: 5)" << endl;
    cout << endl;

    // Pop all elements - should come out in sorted order
    cout << "Popping all elements (should be sorted ascending):" << endl;
    cout << "Expected: 5 10 20 30 50" << endl;
    cout << "Actual:   ";

    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;
    cout << endl;

    cout << "Heap empty after all pops: " << (heap.empty() ? "Yes" : "No") << " (expected: Yes)" << endl;
    cout << endl;
}

int main() {
    cout << endl;
    cout << "########################################" << endl;
    cout << "#       STEP 3 VERIFICATION TEST      #" << endl;
    cout << "########################################" << endl;
    cout << endl;

    testGraph();
    testMinHeap();

    cout << "========================================" << endl;
    cout << "         ALL TESTS COMPLETE" << endl;
    cout << "========================================" << endl;

    return 0;
}
