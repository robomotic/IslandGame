#include "Island.h"

Island::Island()
{
    //ctor
    _type=Terrain::GRASSY;
}

Island::~Island()
{
    //dtor
}

void Island::SetTerrain( string value )
{
    std::size_t found = value.find("grassy");
    if (found!=std::string::npos)
        _type=Terrain::GRASSY;
    found = value .find("swampy");
    if (found!=std::string::npos)
        _type=Terrain::SWAMPY;
    found = value .find("mountainous");
    if (found!=std::string::npos)
        _type=Terrain::MOUNTAINOUS;
}

void Island::SetTerrain( Island::Terrain terrain )
{
  _type = terrain;
}

const Island::Terrain Island::GetTerrain()
{
  return _type ;
}

