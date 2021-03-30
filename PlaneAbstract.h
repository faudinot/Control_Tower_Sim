#ifndef PLANEABSTRACT_H
#define PLANEABSTRACT_H

#include <string>
#include <chrono>


class PlaneAbstract
{
public:
    PlaneAbstract();
    virtual ~PlaneAbstract();

    virtual std::string getInfo();

    virtual std::chrono::milliseconds getTimeToWait() = 0;

protected:
    std::string _name;
};

#endif // PLANEABSTRACT_H
