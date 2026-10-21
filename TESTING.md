# Phase 2 Testing Notes

## Build the application
```bash
g++ -std=c++11 main.cpp DroneDeliverySystem.cpp DistanceCalculator.cpp BatteryCheck.cpp SuitabilityCalculator.cpp RequestComparator.cpp RequestQueue.cpp InputValidation.cpp SimulationRunner.cpp -o drone_delivery
```

## Build and run the request-queue tests separately
Do not include `main.cpp` or `SimulationRunner.cpp` in this test build because `RequestQueueTests.cpp` has its own `main()`.

```bash
g++ -std=c++11 RequestQueueTests.cpp RequestQueue.cpp RequestComparator.cpp -o request_queue_tests
./request_queue_tests
```

## Suggested manual scenarios
1. Enter invalid or zero drone count; the program should stop with a validation message.
2. Enter a battery value below 0 or above 100; the program should reject the input.
3. Add multiple requests with different priorities; the highest priority should be processed first.
4. Give two requests the same priority but different waiting times; the longer-waiting request should be processed first.
5. Use a drone with insufficient battery; it should be rejected for that request.
6. Use multiple requests and one drone; after assignment, the drone should be marked unavailable for subsequent requests.

## Known assumptions
- The fixed delivery hub is at `(0, 0)`.
- The suitability score formula is retained from the supplied Phase 2 implementation.
- This version preserves the original behavior of marking an assigned drone unavailable for the rest of the simulation.
