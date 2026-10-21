#ifndef REQUEST_COMPARATOR_H
#define REQUEST_COMPARATOR_H

#include "DeliveryRequest.h"

struct RequestComparator
{
    bool operator()(const DeliveryRequest &a,
                    const DeliveryRequest &b) const;
};

#endif
