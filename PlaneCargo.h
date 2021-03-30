#ifndef PLANECARGO_H
#define PLANECARGO_H

#include "PlaneAbstract.h"
#include "utils.h"

class PlaneCargo : public PlaneAbstract
{
public:
    PlaneCargo(const std::string& name);
    ~PlaneCargo();

    std::string getInfo();

    std::chrono::milliseconds getTimeToWait();

private:
    int _fret;
    Type_Plane _type;
};

#endif // PLANECARGO_H
