#include <iostream>
#include "../include/SimpleVector.h"
#include "../include/DataStructs.h"
#include "../include/FileParser.h"

using namespace std;

int main() {
    SimpleVector<Port> ports;
    SimpleVector<Route> routes;
    FileParser parser;
    
    cout << "Loading Ports..." << endl;
    parser.loadPorts("../data/PortCharges.txt", ports);
    
    cout << "Loading Routes..." << endl;
    parser.loadRoutes("../data/Routes.txt", routes);

    cout << "----------------Result----------------" << endl;
    cout << "Total Ports Loaded: " << ports.size() << endl;
    cout << "Total Routes Loaded: " << routes.size() << endl;

    if (ports.size() > 0) {
        cout << "First Port: " << ports[0].name << " (Charge: " << ports[0].dailyCharge << ")" << endl;
    }
    if (routes.size() > 0) {
        cout << "First Route: " << routes[0].origin << " to " << routes[0].destination 
             << " via " << routes[0].company << endl;
        cout << "First Route Duration: " << routes[0].durationMinutes << " minutes "
             << "(" << routes[0].depTime << " to " << routes[0].arrTime << ")" << endl;
    }

    return 0;
}