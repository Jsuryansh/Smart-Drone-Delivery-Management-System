#include "SimulationRunner.h"
#include "DroneDeliverySystem.h"
#include "InputValidation.h"

#include <iostream>
#include <string>

using namespace std;

void runSimulation()
{
    DroneDeliverySystem system;
    int numberOfDrones;

    cout << "====================================\n";
    cout << "   SMART DRONE DELIVERY SYSTEM\n";
    cout << "====================================\n\n";

    if (!readPositiveInt("Enter number of drones: ", numberOfDrones))
        return;

    for (int i = 1; i <= numberOfDrones; i++)
    {
        int id;
        string name;
        double battery, energyPerKm, x, y;

        cout << "\n--- Enter details for Drone " << i << " ---\n";

        if (!readNonNegativeInt("Drone ID: ", id))
            return;
        if (!readNonEmptyLine("Drone name: ", name))
            return;
        if (!readBatteryValue("Current battery percentage (0-100): ", battery))
            return;
        if (!readDoubleValue("Energy consumption (% per km): ", energyPerKm)
            || energyPerKm <= 0)
        {
            cout << "Energy consumption must be positive.\n";
            return;
        }
        if (!readDoubleValue("Current X coordinate: ", x))
            return;
        if (!readDoubleValue("Current Y coordinate: ", y))
            return;

        Drone d(id, name, battery, energyPerKm, x, y);
        system.addDrone(d);
    }

    int numberOfRequests;
    cout << "\n";
    if (!readPositiveInt("Enter number of delivery requests: ", numberOfRequests))
        return;

    for (int i = 1; i <= numberOfRequests; i++)
    {
        int requestId;
        string customerName;
        double pickupX, pickupY, destinationX, destinationY;
        int priority, waitingTime;

        cout << "\n--- Enter details for Request " << i << " ---\n";

        if (!readNonNegativeInt("Request ID: ", requestId))
            return;
        if (!readNonEmptyLine("Customer name: ", customerName))
            return;
        if (!readDoubleValue("Pickup X coordinate: ", pickupX))
            return;
        if (!readDoubleValue("Pickup Y coordinate: ", pickupY))
            return;
        if (!readDoubleValue("Destination X coordinate: ", destinationX))
            return;
        if (!readDoubleValue("Destination Y coordinate: ", destinationY))
            return;
        if (!readNonNegativeInt("Priority (higher number = higher priority): ", priority))
            return;
        if (!readNonNegativeInt("Waiting time in minutes: ", waitingTime))
            return;

        DeliveryRequest request(requestId, customerName,
                                pickupX, pickupY,
                                destinationX, destinationY,
                                priority, waitingTime);
        system.addRequest(request);
    }

    system.processAllRequests();
}
