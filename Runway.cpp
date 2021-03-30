#include "Runway.h"

#include <thread>
#include <sstream>

#include "ControlTower.h"
#include "Writer.h"


Runway::Runway()
{
    _plane_consumed = 0;
}

void Runway::operator()(ControlTower& control_tower, Writer& writer)
{
    while(true)
    {
        auto plane = control_tower.getPlane();

        if(plane)
        {
            writer.writeMessageOnCout(plane->getInfo());

            std::this_thread::sleep_for(plane->getTimeToWait());

            if(plane)
            {
                delete plane;
                ++_plane_consumed;

                std::stringstream sstring;
                sstring << "Runway " << std::this_thread::get_id()  << " consumed " << _plane_consumed << " planes.";
                writer.writeMessageOnCout(sstring.str());
            }
            else
            {
                writer.writeMessageOnCout("Error");
            }

        }
    }
}
