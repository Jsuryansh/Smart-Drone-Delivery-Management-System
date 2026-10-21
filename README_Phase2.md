# Smart Drone Delivery System — Phase 2

## Build
Compile the application from this directory:

```bash
g++ -std=c++11 main.cpp DroneDeliverySystem.cpp DistanceCalculator.cpp BatteryCheck.cpp SuitabilityCalculator.cpp RequestComparator.cpp RequestQueue.cpp InputValidation.cpp SimulationRunner.cpp -o drone_delivery
```

Run:
```bash
./drone_delivery
```

On Windows, run `drone_delivery.exe`.

## Module overview
- `Drone.h`, `DeliveryRequest.h`: core data models.
- `DistanceCalculator.*`: Euclidean distance calculation.
- `BatteryCheck.*`: route energy calculation and 20% safety reserve.
- `SuitabilityCalculator.*`: score used to rank eligible drones.
- `RequestComparator.*`, `RequestQueue.*`: priority ordering and queue operations.
- `DroneDeliverySystem.*`: request processing, drone evaluation and assignment.
- `InputValidation.*`, `SimulationRunner.*`, `main.cpp`: input checks and application entry point.

## Current model assumptions
- The hub is fixed at `(0, 0)`.
- The mission route is drone → pickup → customer → hub for battery feasibility.
- A drone assigned to a request is marked unavailable for the remainder of this run.
- Requests are ordered by higher priority first, then longer waiting time.
