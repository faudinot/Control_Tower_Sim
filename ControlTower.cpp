#include "ControlTower.h"

#include "utils.h"

ControlTower::ControlTower(Writer& writer) : _writer(writer)
{
    _count = 0;
    _is_producer_product = true;
}


PlaneAbstract *ControlTower::getPlane()
{
    std::unique_lock<std::mutex> lock{_mutex};

    _condition.wait(lock, [this]{return containerHasValues();} );

    return _container.getNextPlane();
}

void ControlTower::addPlane(PlaneAbstract *plane)
{
    std::unique_lock<std::mutex> lock {_mutex};

    _container.addPlane(plane);

    _condition.notify_one();
}

bool ControlTower::containerHasValues()
{
    return !_container.isEmpty();
}

void ControlTower::producerStopProduction()
{
    _is_producer_product = false;
}

bool ControlTower::continueToRun()
{
    bool res {true};

    if(_is_producer_product == false && _container.isEmpty() == true)
    {
        res = false;
    }

    return res;
}

bool ControlTower::containerIsEmpty()
{
    return _container.isEmpty();
}

bool ControlTower::isMaxCountReached()
{
    bool res {false};

    if(_count > MAX_PLANES)
    {
        res = true;
    }

    return res;
}

