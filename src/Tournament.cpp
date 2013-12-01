#include "Tournament.h"

Tournament::Tournament()
{
    //ctor
    num_islands=0;
    num_bridges=0;
    num_players=0;
    race_map=new MapIsland();
}

Tournament::~Tournament()
{
    //dtor
    delete race_map;
}

void Tournament::add_vehicle(const Vehicle& v,Location start)
{
    playerList.push_back(v);
    positionStatus.push_back(start);
}
bool Tournament::import_all(string folder)
{

    path p(folder);
    try
    {
        if (exists(p))    // does p actually exist?
        {
            if (is_regular_file(p))        // is p a regular file?
                cout << p << " size is " << file_size(p) << '\n';

            else if (is_directory(p))      // is p a directory?
            {
                cout << p << " is a directory containing:\n";

                typedef vector<path> vec;             // store paths,
                vec v;                                // so we can sort them later

                copy(directory_iterator(p), directory_iterator(), back_inserter(v));

                sort(v.begin(), v.end());             // sort, since directory iteration
                // is not ordered on some file systems

                for (vec::const_iterator it (v.begin()); it != v.end(); ++it)
                {

                    string filename=(*it).string();

                    std::size_t found = filename.find(mapname);
                    if (found!=std::string::npos)
                    {
                        cout<<"Importing map "<< "   " << filename<< '\n';
                        import_map(filename);
                        cout<<"Done"<<endl;
                    }
                    found = filename.find(playername);
                    if (found!=std::string::npos)
                    {
                        cout<<"Importing player "<< "   " << filename<< '\n';
                        import_player(filename);
                        cout<<"Done"<<endl;
                    }
                }
            }

            else
                cout << p << " exists, but is neither a regular file nor a directory\n";
        }
        else
            cout << p << " does not exist\n";
    }

    catch (const filesystem_error& ex)
    {
        cout << ex.what() << '\n';
        return false;
    }

}
bool Tournament::run_competition(const int steps)
{
    bool aWinner=false;
    //! runs for a finite time steps in case noboy is winning!
    for(int i=1; i<=steps; i++)
    {
        //! for each player do the move
        for(int player_id=0;player_id<playerList.size();player_id++)
        {
            //for each player get the possible moves
            Vehicle aPlayer=playerList[player_id];
            //get the bridges from this position ....
            vector<Bridge> bridges= race_map->getBridges(positionStatus[player_id]);
            cout<<" Bridges from "<<positionStatus[player_id];
            for(Bridge aBridge: bridges)
            {
                cout<<"A bridge found "<<aBridge<<endl;
            }
            //TODO get the islands from this position

            //TODO then decide what to do ....

            // if the player arrived skip the moves and wait for the others
            if (positionStatus[player_id]==race_map->GetFinish())
                break;
        }
        if(aWinner) break;

    }
    return aWinner;
}
bool Tournament::import_player(string filename)
{
    string line;
    ifstream playerfile (filename);

    if (playerfile.is_open())
    {
        while ( playerfile.good() )
        {
            getline (playerfile,line);
            if(line.length()>0)
            {
                vector<string> elements;
                boost::split(elements,line,boost::is_any_of(delims));
                cout << line << endl;
                try
                {

                    if(elements.size()==2)
                    {

                        Vehicle aPlayer;
                        aPlayer.SetName(lexical_cast<string>(elements[0]));
                        string player_type=lexical_cast<string>(elements[1]);

                        boost::algorithm::to_lower(player_type);

                        aPlayer.SetLocomotion(player_type);

                        cout<<"Player type "<<player_type<<endl;
                        add_vehicle(aPlayer,race_map->GetStart());
                        num_players++;
                    }


                }
                catch(bad_lexical_cast &)
                {
                    cout<<"Erro importing player "<<endl;
                }
            }

        }
        playerfile .close();
        return true;
    }
    else return false;
}

bool Tournament::import_map(string filename)
{
    string line;
    ifstream mapfile (filename);

    bool is_a_edge=false;
    //bool is_a_vertex=false;

    if (mapfile.is_open())
    {
        while ( mapfile.good() )
        {
            getline (mapfile,line);
            if(line.length()>0)
            {
                vector<string> elements;
                boost::split(elements,line,boost::is_any_of(delims));
                /* for debug only  */
                /*
                cout << "* size of the vector: " << elements.size() << endl;
                for (size_t i = 0; i < elements.size(); i++)
                    cout << elements[i] << endl;
                */
                try
                {
                    Bridge aBridge;
                    Edge anEdge;
                    anEdge.first=lexical_cast<Location>(elements[0]);
                    anEdge.second=lexical_cast<Location>(elements[1]);
                    if(elements.size()==3)
                    {
                        string bridge_type=lexical_cast<string>(elements[2]);
                        boost::algorithm::to_lower(bridge_type);
                        aBridge.SetType(bridge_type);
                        //cout<<"Bridge type "<<bridge_type<<endl;

                    }

                    race_map->addEdge(anEdge,aBridge);
                    is_a_edge = true;
                    num_bridges++;

                }
                catch(bad_lexical_cast &)
                {
                    is_a_edge = false;
                }
                catch(std::exception& )
                {
                    return false;
                }

                if(!is_a_edge)
                {
                    try
                    {
                        Location location=lexical_cast<Location>(elements[0]);
                        string island_type=lexical_cast<string>(elements[1]);
                        boost::algorithm::to_lower(island_type);
                        Island anIsland;
                        anIsland.SetTerrain(island_type);
                        //cout<<"Island type "<<island_type<<endl;
                        if(elements.size()==3)
                        {

                            string marker=lexical_cast<string>(elements[2]);
                            boost::algorithm::to_lower(marker);
                            std::size_t found = marker.find("start");
                            if (found!=std::string::npos)
                                anIsland.isStart=true;
                            else anIsland.isEnd=true;

                            //cout<<"Island marker "<<anIsland.isStart<<endl;
                        }
                        race_map->addVertex(location,anIsland);
                        //is_a_vertex = true;
                    }
                    catch(bad_lexical_cast &)
                    {
                        //is_a_vertex = false;
                    }
                }
            }
            //cout << line << endl;
        }
        mapfile .close();
        return true;
    }
    else return false;
}
