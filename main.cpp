#include <thread>
#include <vector>
#include <functional>


#include "ControlTower.h"
#include "Runway.h"
#include "PlaneProducer.h"


int main()
{
    Writer my_writer;
    ControlTower my_watch_tower(my_writer);

    try
    {
        std::thread producer { PlaneProducer(), std::ref(my_watch_tower), std::ref(my_writer) };

        std::vector<std::thread> my_runways;
        std::thread runway_0 { Runway(), std::ref(my_watch_tower), std::ref(my_writer) };
        std::thread runway_1 { Runway(), std::ref(my_watch_tower), std::ref(my_writer) };
        std::thread runway_2 { Runway(), std::ref(my_watch_tower), std::ref(my_writer) };

        my_runways.push_back(std::move(runway_0));
        my_runways.push_back(std::move(runway_1));
        my_runways.push_back(std::move(runway_2));

        for(std::thread& runway : my_runways)
        {
            if(runway.joinable())
            {
                runway.join();
            }
        }

        if(producer.joinable())
        {
            producer.join();
        }

    }
    catch(std::exception& e)
    {
        my_writer.writeMessageOnCout("Exception");
        my_writer.writeMessageOnCout(e.what());
    }

    return 0;
}
