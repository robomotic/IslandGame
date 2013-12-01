#include "Bridge.h"

Bridge::Bridge()
{
    //ctor
    _type=BridgeType::WEAK;
}

Bridge::~Bridge()
{
    //dtor
}

void Bridge::SetType( string value )
{
    std::size_t found = value .find("strong");
    if (found!=std::string::npos)
        _type=BridgeType::STRONG;
    found = value .find("weak");
    if (found!=std::string::npos)
        _type=BridgeType::WEAK;

}
void Bridge::SetType( BridgeType strength )
{
  _type = strength;
}

const BridgeType Bridge::GetType()
{
  return _type ;
}

ostream& operator<<(ostream& os, const Bridge& b)
{
    os << b.convert.at(b._type);
    return os;
}
