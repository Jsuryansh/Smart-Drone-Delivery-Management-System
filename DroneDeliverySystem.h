#ifndef DRONE_DELIVERY_SYSTEM_H
#define DRONE_DELIVERY_SYSTEM_H

#include <unordered_map>
#include "Drone.h"
#include "DeliveryRequest.h"
#include "RequestQueue.h"

class DroneDeliverySystem
{
private:
    RequestQueue requestQueue;
    std::unordered_map<int, Drone> drones;
    double hubX;
    double hubY;

public:
    DroneDeliverySystem();

    void addDrone(const Drone &d);
    void addRequest(const DeliveryRequest &request);
    void processAllRequests();
};

#endif
