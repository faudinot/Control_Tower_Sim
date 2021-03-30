#ifndef PLANECONTAINER_H
#define PLANECONTAINER_H

//#include <queue>
#include <list>

#include "PlaneAbstract.h"
#include "utils.h"

class PlaneContainer
{
public:
    PlaneContainer();
    ~PlaneContainer();

    void addPlane(PlaneAbstract* plane);
    PlaneAbstract* getNextPlane();
    bool isEmpty();
    int size();

private:
    std::list<PlaneAbstract*> _container;

    void fillIfNeeded();
};

#endif // PLANECONTAINER_H
