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
   setId();

    while(control_tower.continueToRun())
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

    if(control_tower.continueToRun() == false)
    {
        std::stringstream sstring;
        sstring << "\n----- " << _id  << " is closed. -----\n";
        sstring << _id << " processed " << _plane_consumed << " planes.";
        for(auto info : _planes_info)
        {
            sstring << "\n\t" << info;
        }
        sstring << "\n";
        writer.writeMessageOnCout(sstring.str());
    }
}

// --------- PRIVATE ---------

void Runway::setId()
{
    std::stringstream sstring;
    sstring << "Runway " << std::this_thread::get_id();
    _id = sstring.str();
}
