#include "RequestQueue.h"
#include <cassert>
#include <iostream>

int main()
{
    RequestQueue queue;

    DeliveryRequest low(1, "Customer A", 0, 0, 1, 1, 1, 5);
    DeliveryRequest high(2, "Customer B", 0, 0, 2, 2, 3, 1);
    DeliveryRequest samePriorityLongWait(3, "Customer C", 0, 0, 3, 3, 3, 10);

    assert(queue.empty());
    queue.push(low);
    queue.push(high);
    queue.push(samePriorityLongWait);

    assert(queue.size() == 3);
    assert(queue.top().requestId == 3);
    queue.pop();
    assert(queue.top().requestId == 2);
    queue.pop();
    assert(queue.top().requestId == 1);
    queue.pop();
    assert(queue.empty());

    std::cout << "RequestQueue tests passed.\n";
    return 0;
}
