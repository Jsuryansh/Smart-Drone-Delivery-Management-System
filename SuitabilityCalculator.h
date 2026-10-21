#ifndef SUITABILITY_CALCULATOR_H
#define SUITABILITY_CALCULATOR_H

#include "Drone.h"
#include "DeliveryRequest.h"

double calculateSuitabilityScore(
    const Drone &d, const DeliveryRequest &request);

#endif
