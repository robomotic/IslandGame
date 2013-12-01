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
#include <iostream>

#include "Tournament.h"
using namespace std;


void test_import_map()
{

    MapIsland* race_map=new MapIsland();
    Island anIsland;
    Bridge aBridge;

    anIsland.isStart=true;
    anIsland.SetTerrain(Island::Terrain::GRASSY);

    race_map->addVertex(0,anIsland);

    anIsland.SetTerrain(Island::Terrain::GRASSY);
    anIsland.isStart=false;
    anIsland.isEnd=true;

    race_map->addVertex(1,anIsland);

    aBridge.SetType(BridgeType::STRONG);


    Edge bridge1;
    bridge1.first=0;
    bridge1.second=1;
    race_map->addEdge(bridge1,aBridge);

    //race_map->print_edges();
    //cout<<"Total loaded islands "<<vertexList.size();
}


int main()
{
    Tournament* a_tournament=new Tournament();
    bool result=a_tournament->import_all();
    if(result)
    {
        cout << "Import successfull" << endl;
        cout << "Running competition" <<endl;
        bool winner=a_tournament->run_competition(1);
        if(winner)
            cout <<" We have a winner "<<endl;
        else
            cout<<" It was a draw"<<endl;

    }
    else
    {
        cout<< "Import failed!"<<endl;
    }
    delete a_tournament;
    return 0;
}
