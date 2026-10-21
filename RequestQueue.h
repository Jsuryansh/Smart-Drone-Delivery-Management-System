#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include <queue>
#include <vector>
#include "RequestComparator.h"

class RequestQueue
{
private:
    std::priority_queue<DeliveryRequest,
                        std::vector<DeliveryRequest>,
                        RequestComparator> requests;

public:
    void push(const DeliveryRequest &request);
    bool empty() const;
    std::size_t size() const;
    const DeliveryRequest &top() const;
    void pop();
};

#endif
