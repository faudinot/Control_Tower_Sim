#ifndef PLANECOMMERCIAL_H
#define PLANECOMMERCIAL_H

#include <PlaneAbstract.h>

class PlaneCommercial : PlaneAbstract
{
public:
    PlaneCommercial(const std::string& name);
    ~PlaneCommercial();

private:
    unsigned int _passengers_count;
};

#endif // PLANECOMMERCIAL_H
