#include "PlaneProducer.h"

#include <thread>
#include <sstream>

#include "ControlTower.h"
#include "Writer.h"
#include "PlaneCommercial.h"
#include "PlaneCargo.h"
//#include "utils.h"


PlaneProducer::PlaneProducer()
{
    _count = 0;
}

void PlaneProducer::operator()(ControlTower& control_tower, Writer& writer)
{
    while(_count < MAX_PLANES)
    {
        auto _plane = createPlane();

        if(_plane != nullptr)
        {
            control_tower.addPlane(_plane);

            writer.writeMessageOnCout(_plane->getInfo());
        }

        RandomGeneratorInt randomInt{500, 999};
        const int time_to_wait = randomInt();

        std::stringstream sstring;
        sstring << "Time to wait : " << time_to_wait << "\tCount : " << _count;
        writer.writeMessageOnCout(sstring.str());

        std::this_thread::sleep_for(std::chrono::milliseconds(time_to_wait));

        ++_count;
    }

    if(_count >= MAX_PLANES)
    {
        writer.writeMessageOnCout("Producer stop to produce.");
    }

}


// -------- PRIVATE


PlaneAbstract *PlaneProducer::createPlane()
{
    PlaneAbstract* ptr_plane {nullptr};

    RandomGeneratorInt randomInt {0, (static_cast<int>(Type_Plane::MAX)-1)};
    int type = randomInt();

    switch(static_cast<Type_Plane>(type))
    {
        case Type_Plane::COMMERCIAL :
            ptr_plane = new PlaneCommercial(createName());
        break;

        case Type_Plane::CARGO :
            ptr_plane = new PlaneCargo(createName());
        break;

        case Type_Plane::MAX:
            throw std::logic_error("Bad type of plane.");
        break;
    }

    return ptr_plane;
}

std::string PlaneProducer::createName()
{
    std::string name{"Flight"};

    name.append(std::to_string(_count));

    name.append("-");

    RandomGeneratorInt randomInt {100, 999};
    int id = randomInt();

    name.append(std::to_string(id));

    return name;
}


