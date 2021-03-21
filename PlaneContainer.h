#ifndef PLANECONTAINER_H
#define PLANECONTAINER_H

//#include <queue>
#include <list>

#include <PlaneAbstract.h>

class PlaneContainer
{
public:
    PlaneContainer(const int max_planes=MAX_PLANES);
    ~PlaneContainer();

    void addPlane(PlaneAbstract* plane);
    PlaneAbstract* getNextPlane();
    bool isEmpty();

private:
    std::list<PlaneAbstract*> _container;
    int _max_planes;

    void fillIfNeeded();
};

#endif // PLANECONTAINER_H
