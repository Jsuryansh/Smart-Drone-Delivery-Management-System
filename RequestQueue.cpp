#include "RequestQueue.h"

void RequestQueue::push(const DeliveryRequest &request)
{
    requests.push(request);
}

bool RequestQueue::empty() const
{
    return requests.empty();
}

std::size_t RequestQueue::size() const
{
    return requests.size();
}

const DeliveryRequest &RequestQueue::top() const
{
    return requests.top();
}

void RequestQueue::pop()
{
    requests.pop();
}
