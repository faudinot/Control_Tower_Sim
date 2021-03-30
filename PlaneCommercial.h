#ifndef PLANECOMMERCIAL_H
#define PLANECOMMERCIAL_H

#include "PlaneAbstract.h"
#include "utils.h"

class PlaneCommercial : public PlaneAbstract
{
public:
    PlaneCommercial(const std::string& name);
    ~PlaneCommercial();

    std::string getInfo();

    std::chrono::milliseconds getTimeToWait();

private:
    unsigned int _passengers_count;
    Type_Plane _type;
};

#endif // PLANECOMMERCIAL_H
