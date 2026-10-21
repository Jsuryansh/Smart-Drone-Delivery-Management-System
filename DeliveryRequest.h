#ifndef DELIVERY_REQUEST_H
#define DELIVERY_REQUEST_H

#include <string>

class DeliveryRequest
{
public:
    int requestId;
    std::string customerName;
    double sourceX, sourceY;
    double destinationX, destinationY;
    int priority;
    int waitingTime;

    DeliveryRequest(int id, std::string customer,
                    double sx, double sy,
                    double dx, double dy,
                    int p, int wait)
        : requestId(id), customerName(customer),
          sourceX(sx), sourceY(sy),
          destinationX(dx), destinationY(dy),
          priority(p), waitingTime(wait)
    {
    }
};

#endif
