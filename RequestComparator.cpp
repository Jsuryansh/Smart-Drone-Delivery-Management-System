#include "RequestComparator.h"

bool RequestComparator::operator()(const DeliveryRequest &a,
                                   const DeliveryRequest &b) const
{
    if (a.priority != b.priority)
        return a.priority < b.priority;

    return a.waitingTime < b.waitingTime;
}
