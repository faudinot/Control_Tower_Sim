#include "ControlTower.h"

ControlTower::ControlTower()
{
    _count = 0;
    _can_continue = true;
}

void ControlTower::run()
{
    auto plane = _producer.createPlane();
    ++_count;

    plane->display();

    delete plane;
}

PlaneAbstract *ControlTower::getPlane()
{
    fillIfNeeded();

    return _container.getNextPlane();
}

void ControlTower::fillIfNeeded()
{
    if(_container.isEmpty() && isMaxCountReached() == false)
    {
        _container.addPlane(_producer.createPlane());
    }
}

bool ControlTower::isMaxCountReached()
{
    // ternaire ?

    bool res {false};

    if(_count > MAX_PLANES)
    {
        res = true;
    }

    return res;
}

void ControlTower::isRunCanContinue()
{
    if(_container.isEmpty() && isMaxCountReached())
    {
        _can_continue = false;
    }
}
