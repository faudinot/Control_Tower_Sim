#include "PlaneCommercial.h"

#include <sstream>

PlaneCommercial::PlaneCommercial(const std::string& name) : PlaneAbstract(), _type(Type_Plane::COMMERCIAL)
{
    RandomGeneratorInt random_number{1, 100};
    _passengers_count = random_number();
    _name = name;
}

PlaneCommercial::~PlaneCommercial()
{
}

std::string PlaneCommercial::getInfo()
{
    std::stringstream sstring;
    sstring << _name << "\t" << "Passengers : " << _passengers_count;

    return sstring.str();
}

std::chrono::milliseconds PlaneCommercial::getTimeToWait()
{
    return std::chrono::milliseconds(_passengers_count * TIME_PER_PASSENGER);
}
