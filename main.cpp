#include <iostream>
#include <thread>
#include <vector>

#include <ControlTower.h>

class PlaneAbstract;

void processPlane(PlaneAbstract* plane);

int main()
{
    ControlTower my_watch_tower;

    std::vector<std::thread> my_runways;

    std::thread runway_0 {processPlane, my_watch_tower.getPlane()};
    std::thread runway_1 {processPlane, my_watch_tower.getPlane()};

    my_runways.push_back(std::move(runway_0));
    my_runways.push_back(std::move(runway_1));

//    for(int i=0 ; i < 10 ; ++i)
//    {
//        my_watch_tower.run();
//    }

    for(std::thread& runway : my_runways)
    {
        if(runway.joinable())
        {
            runway.join();
        }
    }


    return 0;
}



void processPlane(PlaneAbstract *plane)
{
    plane->display();
}
