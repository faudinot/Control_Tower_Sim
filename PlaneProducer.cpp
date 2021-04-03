#include "PlaneProducer.h"

#include <thread>
#include <sstream>

#include "ControlTower.h"
#include "Writer.h"
#include "PlaneCommercial.h"
#include "PlaneCargo.h"


PlaneProducer::PlaneProducer()
{
    _count = 0;
}

void PlaneProducer::operator()(ControlTower& control_tower, Writer& writer)
{
    setId();

    while(_count < MAX_PLANES)
    {
        auto _plane = createPlane();

        if(_plane != nullptr)
        {
            control_tower.addPlane(_plane);

            std::stringstream sstring;
            sstring << _id << " creates : " << _plane->getInfo();
            writer.writeMessageOnCout(sstring.str());
        }

       waitBeforeToContinue(writer);
    }

    if(_count >= MAX_PLANES)
    {
        control_tower.producerStopProduction();
        std::stringstream sstring;
        sstring << "\n----- " << _id  << " stop to produce. -----\n";
        writer.writeMessageOnCout(sstring.str());
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

    ++_count;

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

void PlaneProducer::setId()
{
    std::stringstream sstring;
    sstring << "Producer " << std::this_thread::get_id();
    _id = sstring.str();
}

void PlaneProducer::waitBeforeToContinue(Writer &writer)
{
    RandomGeneratorInt randomInt{500, 999};
    const int time_to_wait = randomInt();

    std::stringstream sstring;
    sstring << _id << " time to wait : " << time_to_wait << "\tCount : " << _count;
    writer.writeMessageOnCout(sstring.str());

    std::this_thread::sleep_for(std::chrono::milliseconds(time_to_wait));
}


