#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include "Drone.h"
#include "DeliveryRequest.h"

bool batteryCheck(const Drone &d, const DeliveryRequest &request,
                  double hubX, double hubY);

#endif
