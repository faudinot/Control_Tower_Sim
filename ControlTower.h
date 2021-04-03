#ifndef CONTROLTOWER_H
#define CONTROLTOWER_H

#include <mutex>
#include <condition_variable>

#include "PlaneContainer.h"

class PlaneAbstract;

class ControlTower
{
public:
    ControlTower();

    PlaneAbstract* getPlane();
    void addPlane(PlaneAbstract* plane);
    bool containerIsEmpty();
    bool containerHasValues();
    void producerStopProduction();
    bool continueToRun();

private:
    bool _is_producer_product;
    unsigned int _count;
    std::mutex _mutex;
    std::condition_variable _condition;
    PlaneContainer _container;
};

#endif // CONTROLTOWER_H
