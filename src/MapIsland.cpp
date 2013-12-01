#include "MapIsland.h"



MapIsland::MapIsland(bool directed)
{
    numVertices = 0;
    numEdges = 0;
    this->directed=directed;
}

Location MapIsland::GetStart()
{
    return start;
}

Location MapIsland::GetFinish()
{
    return finish;
}

int MapIsland::getNumVertices()
{
    return numVertices;
}
int MapIsland::getNumEdges()
{
    return numEdges;
}
bool MapIsland::isDirected()
{
    return directed;
}
void MapIsland::addVertex(const Location id,const Island& island)
{
    if(vertex_map.count(id))
    {
        // item already in the vertex list
        vertex_map.insert(std::make_pair(id,island));

    }
    else
    {
        //item not in the vertex list yet
        vertex_map.insert(std::make_pair(id,island));
        numVertices++;
    }
    if(island.isStart) start=id;
    else if(island.isEnd) finish=id;
}

vector<Bridge> MapIsland::getBridges(const Location id)
{
  vector<Bridge> list;
  // show content:
  for (map<Edge, Bridge>::iterator it=edge_map.begin(); it!=edge_map.end(); ++it)
  {
        if(it->first.first==id)
        {
            list.push_back(it->second);
        }

  }
  return list;
}

void MapIsland::addEdge(Edge anEdge,const Bridge& bridge)
{

    if(adj_list.size()==0)
    {
        set<Location> empty;
        for(int i=0; i<numVertices; i++)
            adj_list.push_back(empty);
    }

    try
    {
        if (!directed)
        {

            adj_list[anEdge.first].insert(anEdge.second);
            adj_list[anEdge.second].insert(anEdge.first);
            numEdges+=2;
        }
        else if (directed)
        {
            adj_list[anEdge.first].insert(anEdge.second);
            numEdges++;
        }
        edge_map.insert(std::make_pair(anEdge,bridge));
    }
    catch(std::exception& e)
    {
        std::cout << "Vertex non existent " << std::endl;
        throw;
    }

}
