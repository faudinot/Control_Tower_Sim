#ifndef CONTROLTOWER_H
#define CONTROLTOWER_H

#include <PlaneProducer.h>
#include <PlaneContainer.h>

class PlaneAbstract;

class ControlTower
{
public:
    ControlTower();

    void run();

    PlaneAbstract* getPlane();

private:
    bool _can_continue;
    unsigned int _count;
    PlaneProducer _producer;
    PlaneContainer _container;

    void fillIfNeeded();
    bool isMaxCountReached();
    void isRunCanContinue();
};

#endif // CONTROLTOWER_H
