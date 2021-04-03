#ifndef RUNWAY_H
#define RUNWAY_H

#include <string>
#include <vector>


class ControlTower;
class Writer;


class Runway
{
public:
    Runway();

    void operator()(ControlTower& control_tower, Writer& writer);

private:
    unsigned int _plane_consumed;
    std::string _id;
    std::vector<std::string> _planes_info;

    void setId();
    void displayReport(Writer& writer);
};

#endif // RUNWAY_H
