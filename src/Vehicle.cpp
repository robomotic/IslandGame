#include "Vehicle.h"

Vehicle::Vehicle()
{
    //ctor
}

Vehicle::~Vehicle()
{
    //dtor
}

void Vehicle::SetLocomotion( string value )
{
    std::size_t found = value .find("wheel");
    if (found!=std::string::npos)
        _type=Locomotion::WHEEL;
    found = value .find("leg");
    if (found!=std::string::npos)
        _type=Locomotion::LEG;
    found = value .find("wing");
    if (found!=std::string::npos)
        _type=Locomotion::WING;
}

void Vehicle::SetLocomotion( Vehicle::Locomotion strength )
{
  _type = strength;
}

const Vehicle::Locomotion Vehicle::GetLocomotion()
{
  return _type ;
}

