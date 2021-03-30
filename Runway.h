#ifndef RUNWAY_H
#define RUNWAY_H

class ControlTower;
class Writer;

class Runway
{
public:
    Runway();

    void operator()(ControlTower& control_tower, Writer& writer);

private:
    unsigned int _plane_consumed;
};

#endif // RUNWAY_H
