#ifndef UTILS_H
#define UTILS_H

#include <random>

enum class Type_Plane
{
    COMMERCIAL = 0,
    CARGO = 1,
    MAX
};


const unsigned int MAX_PLANES = 30;
const unsigned int TIME_PER_PASSENGER = 100;
const unsigned int TIME_PER_MERCHANDISE = 50;

class RandomGeneratorInt
{
public:
    RandomGeneratorInt(int min, int max) : dist{min, max} {}
    int operator()() {return dist(engine);}

private:
//    std::default_random_engine engine;
    std::random_device engine;
    std::uniform_int_distribution<> dist;
};

#endif // UTILS_H
