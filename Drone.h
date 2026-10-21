#ifndef DRONE_H
#define DRONE_H

#include <string>

class Drone
{
public:
    int id;
    std::string name;
    double battery;
    double energyPerKm;
    double x, y;
    bool available;

    Drone(int i, std::string n, double b, double e,
          double px, double py)
        : id(i), name(n), battery(b), energyPerKm(e),
          x(px), y(py), available(true)
    {
    }
};

#endif
