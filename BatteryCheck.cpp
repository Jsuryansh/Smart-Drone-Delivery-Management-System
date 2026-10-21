#include "BatteryCheck.h"
#include "DistanceCalculator.h"
#include <iostream>

using namespace std;

bool batteryCheck(const Drone &d, const DeliveryRequest &request,
                  double hubX, double hubY)
{
    double distanceToPickup =
        calculateDistance(d.x, d.y, request.sourceX, request.sourceY);

    double deliveryDistance =
        calculateDistance(request.sourceX, request.sourceY,
                          request.destinationX, request.destinationY);

    double returnDistance =
        calculateDistance(request.destinationX, request.destinationY,
                          hubX, hubY);

    double totalDistance =
        distanceToPickup + deliveryDistance + returnDistance;

    double requiredEnergy = totalDistance * d.energyPerKm;
    double safetyReserve = requiredEnergy * 0.20;
    double totalRequired = requiredEnergy + safetyReserve;

    cout << "\nDrone: " << d.name << " (ID " << d.id << ")\n";
    cout << "Total mission distance: " << totalDistance << " km\n";
    cout << "Required energy: " << requiredEnergy << "%\n";
    cout << "20% safety reserve: " << safetyReserve << "%\n";
    cout << "Total battery required: " << totalRequired << "%\n";
    cout << "Available battery: " << d.battery << "%\n";

    if (d.battery >= totalRequired)
    {
        cout << "Battery check: PASS\n";
        return true;
    }

    cout << "Battery check: FAIL\n";
    cout << "Drone rejected due to insufficient battery.\n";
    return false;
}
