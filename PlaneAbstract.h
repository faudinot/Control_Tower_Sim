#ifndef PLANEABSTRACT_H
#define PLANEABSTRACT_H

#include <string>
#include <utils.h>


class PlaneAbstract
{
public:
    PlaneAbstract(const std::string& name);
    ~PlaneAbstract();

    void display();

private:
    std::string _name;
    Type_Plane _type;
};

#endif // PLANEABSTRACT_H
