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

#ifndef BRIDGE_H
#define BRIDGE_H
#include <string>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>

using namespace std;
using boost::assign::map_list_of;

enum BridgeType { STRONG,WEAK };

class Bridge
{
    public:
        //enum class Type { STRONG,WEAK };
        Bridge();
        virtual ~Bridge();
        void SetType( BridgeType strength );
        void SetType( string strength);
        const BridgeType GetType();
        friend ostream& operator<<(ostream& os, const Bridge& b);
    protected:
    private:
        BridgeType _type;
        const boost::unordered_map<BridgeType,const char*> convert = map_list_of(STRONG, "STRONG")(WEAK, "WEAK");
};

#endif // BRIDGE_H
