#ifndef PLANEPRODUCER_H
#define PLANEPRODUCER_H

#include <string>

#include <PlaneAbstract.h>

class PlaneProducer
{
public:
    PlaneProducer();

    PlaneAbstract* createPlane();

private:
    unsigned int _count;

    std::string createName();
};

#endif // PLANEPRODUCER_H
