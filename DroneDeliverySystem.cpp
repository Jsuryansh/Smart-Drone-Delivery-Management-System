#include "DroneDeliverySystem.h"
#include "BatteryCheck.h"
#include "SuitabilityCalculator.h"

#include <iostream>
#include <limits>

using namespace std;

DroneDeliverySystem::DroneDeliverySystem()
    : hubX(0), hubY(0)
{
}

void DroneDeliverySystem::addDrone(const Drone &d)
{
    if (drones.find(d.id) != drones.end())
    {
        cout << "Drone ID already exists. Skipping drone.\n";
        return;
    }

    drones.emplace(d.id, d);
    cout << "Drone " << d.name << " added successfully.\n";
}

void DroneDeliverySystem::addRequest(const DeliveryRequest &request)
{
    requestQueue.push(request);
    cout << "Request " << request.requestId
         << " added successfully.\n";
}

void DroneDeliverySystem::processAllRequests()
{
    if (requestQueue.empty())
    {
        cout << "\nNo delivery requests available.\n";
        return;
    }

    while (!requestQueue.empty())
    {
        DeliveryRequest request = requestQueue.top();
        requestQueue.pop();

        cout << "\n\n=============================================================\n";
        cout << "     PROCESSING DELIVERY REQUEST\n";
        cout << "=============================================================\n";
        cout << "Request ID: " << request.requestId << "\n";
        cout << "Customer: " << request.customerName << "\n";
        cout << "Priority: " << request.priority << "\n";
        cout << "Waiting time: " << request.waitingTime << " minutes\n";
        cout << "\n========== DRONE EVALUATION ==========\n";

        int bestDroneId = -1;
        double bestScore = numeric_limits<double>::max();

        for (auto it = drones.begin(); it != drones.end(); ++it)
        {
            Drone &d = it->second;

            if (!d.available)
            {
                cout << "\nDrone " << d.name
                     << " is unavailable. Skipping.\n";
                continue;
            }

            if (!batteryCheck(d, request, hubX, hubY))
                continue;

            double score = calculateSuitabilityScore(d, request);
            cout << "Suitability score: " << score << "\n";

            if (score < bestScore)
            {
                bestScore = score;
                bestDroneId = d.id;
            }
        }

        cout << "\n====================================\n";

        if (bestDroneId == -1)
        {
            cout << "NO SUITABLE DRONE FOR REQUEST "
                 << request.requestId << "\n";
            cout << "Moving to the next delivery request...\n";
            cout << "====================================\n";
            continue;
        }

        auto bestIt = drones.find(bestDroneId);
        if (bestIt != drones.end())
        {
            Drone &bestDrone = bestIt->second;
            cout << "       BEST DRONE SELECTED\n";
            cout << "Drone ID: " << bestDrone.id << "\n";
            cout << "Drone name: " << bestDrone.name << "\n";
            cout << "Suitability score: " << bestScore << "\n";
            bestDrone.available = false;
            cout << "Drone assigned to request "
                 << request.requestId << ".\n";
        }

        cout << "====================================\n";
    }

    cout << "\nAll delivery requests have been processed.\n";
}
