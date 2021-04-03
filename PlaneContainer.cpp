#include "PlaneContainer.h"

PlaneContainer::PlaneContainer()
{
}

PlaneContainer::~PlaneContainer()
{
   for(auto elem : _container)
   {
       delete elem;
   }
}

void PlaneContainer::addPlane(PlaneAbstract* plane)
{
    _container.push_back(plane);
}

PlaneAbstract* PlaneContainer::getNextPlane()
{
    auto tmp_plane = _container.front();

    _container.pop_front();

    return tmp_plane;
}

bool PlaneContainer::isEmpty()
{
    return _container.empty();
}

int PlaneContainer::size()
{
    return _container.size();
}


