#include "SuitabilityCalculator.h"
#include "DistanceCalculator.h"

double calculateSuitabilityScore(
    const Drone &d, const DeliveryRequest &request)
{
    double distanceToPickup =
        calculateDistance(d.x, d.y, request.sourceX, request.sourceY);

    double deliveryDistance =
        calculateDistance(request.sourceX, request.sourceY,
                          request.destinationX, request.destinationY);

    double energy =
        (distanceToPickup + deliveryDistance) * d.energyPerKm;

    double score =
        distanceToPickup * 2.0
        + energy * 1.5
        - request.waitingTime * 0.5;

    return score;
}
