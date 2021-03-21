#include "PlaneProducer.h"

#include <PlaneCommercial.h>

PlaneProducer::PlaneProducer()
{
    _count = 0;
}

PlaneAbstract* PlaneProducer::createPlane()
{
    return new PlaneAbstract(createName());
}


// -------- PRIVATE

std::string PlaneProducer::createName()
{
    std::string name;

    name = std::to_string(_count);

    ++_count;

    return name;
}
