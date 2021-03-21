#include "PlaneContainer.h"

PlaneContainer::PlaneContainer(const int max_planes)
{
    _max_planes = max_planes;
}

PlaneContainer::~PlaneContainer()
{
    while(_container.size()!= 0)
    {

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


