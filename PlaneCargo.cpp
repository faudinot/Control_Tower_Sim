#include "PlaneCargo.h"

#include <sstream>

PlaneCargo::PlaneCargo(const std::string& name) : PlaneAbstract(), _type(Type_Plane::CARGO)
{
    _name = name;
    RandomGeneratorInt random_number{1, 100};
    _fret = random_number();
}

PlaneCargo::~PlaneCargo()
{

}

std::string PlaneCargo::getInfo()
{
    std::stringstream sstring;
    sstring << _name << "\t" << "Fret : " << _fret;

    return sstring.str();
}

std::chrono::milliseconds PlaneCargo::getTimeToWait()
{
    return std::chrono::milliseconds(_fret * TIME_PER_MERCHANDISE);
}



