#include "PlaneAbstract.h"

#include <iostream>

PlaneAbstract::PlaneAbstract(const std::string &name)
{
    _name = name;
}

PlaneAbstract::~PlaneAbstract()
{
//    std::cout << "----- Destructor : PlaneAbstract" << std::endl;
}

void PlaneAbstract::display()
{
    std::cout << _name << std::endl;
}
