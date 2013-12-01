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

#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "Vehicle.h"
#include "MapIsland.h"

using namespace std;

using namespace boost::filesystem;
using boost::lexical_cast;
using boost::bad_lexical_cast;

//! Class that contains an island Map and a set of competitors
/*!
This class models the tournament and manages the import and rules
*/
class Tournament
{
public:
    Tournament();
    virtual ~Tournament();
    //! This function imports the island map and all the players
    /*!
    \return true if correctly imported
    */
    bool import_all(string filename="data/");
    bool run_competition(const int steps);
protected:
    bool import_map(string filename);
    bool import_player(string filename);
    void add_vehicle(const Vehicle& v,Location start);

private:
    MapIsland* race_map;
    vector<Vehicle> playerList;
    vector<Location> positionStatus;
    std::string delims = "\t,| ";
    std::string mapname="map";
    std::string playername="player";
    int num_islands;
    int num_bridges;
    int num_players;

};

#endif // TOURNAMENT_H
