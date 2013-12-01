# Author: Paolo Di Prodi
# email: paolo@robomotic.com
# Copyright 2013 Robomotic ltd

/*
    This file is part of IslandGame.

    IslandGame is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    IslandGame is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;
class Vehicle
{
    public:
        enum class Locomotion { WHEEL, WING, LEG };
        Vehicle();
        virtual ~Vehicle();

        void SetLocomotion( Vehicle::Locomotion locomotion );
        void SetLocomotion( string value );
        const Vehicle::Locomotion GetLocomotion();
        void SetName(string name){this->name=name;};
    protected:
        Vehicle::Locomotion _type;
    private:
        string name;
};

#endif // VEHICLE_H
