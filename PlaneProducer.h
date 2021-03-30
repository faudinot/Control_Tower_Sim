#ifndef PLANEPRODUCER_H
#define PLANEPRODUCER_H

#include <string>

#include "PlaneAbstract.h"
#include "utils.h"

class ControlTower;
class Writer;

class PlaneProducer
{
public:
    PlaneProducer();

    void operator()(ControlTower& control_tower, Writer& writer);

private:
    unsigned int _count;

    PlaneAbstract* createPlane();
    std::string createName();
};

#endif // PLANEPRODUCER_H
