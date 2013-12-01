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

#ifndef MAPISLAND_H
#define MAPISLAND_H

#include <string>
#include <boost/graph/adjacency_list.hpp>

#include "Bridge.h"
#include "Island.h"

using namespace std;

typedef int Location;

typedef std::pair<Location, Location> Edge;

//! Class that implements the IslandMap
/*!
This class models the connections between Islands and Bridges
*/
class MapIsland
{
public:
    int getNumVertices();;
    int getNumEdges();
    bool isDirected();

    MapIsland(bool directed=false);

    Location GetStart();
    Location GetFinish();
    void addVertex(const Location id,const Island& island);

    void addEdge(Edge anEdge,const Bridge& bridge);

    vector<Bridge> getBridges(const Location id);
    //set<Island> getIslands(const Location id){return new set<Island>;};

protected:
    //! the adjancey list containing pair of location (edges)
    vector<set<Location> > adj_list;
    //! a lookup table to get the Island from the location index
    map<Location,Island> vertex_map;
    //! a lookup table to get the Bridge from the location pair
    map<Edge, Bridge> edge_map;
private:
    //! number of islands
    int numVertices;
    //! number of bridges
    int numEdges;
    bool directed;
    //! where is the start island
    Location start;
    //! where is the finish island
    Location finish;

};

#endif // MAPISLAND_H
