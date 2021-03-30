#ifndef CONTROLTOWER_H
#define CONTROLTOWER_H

#include <mutex>
#include <condition_variable>

#include "PlaneContainer.h"
#include "Writer.h"

class PlaneAbstract;

class ControlTower
{
public:
    ControlTower(Writer& writer);

    PlaneAbstract* getPlane();
    void addPlane(PlaneAbstract* plane);
    bool containerIsEmpty();
    bool containerHasValues();

private:
    unsigned int _count;
    std::mutex _mutex;
    std::condition_variable _condition;
    PlaneContainer _container;
    Writer& _writer;

    bool isMaxCountReached();

};

#endif // CONTROLTOWER_H
