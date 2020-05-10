#include "Dron.hh"

//----------------------------------------------------------------------------------konstruktor---------------------------------
Dron::Dron():x{0},y{0},z{0}{}
Dron::Dron( double x,double y,double z ) : x(x),y(y),z(z){}
 
//---------------------------------------------------------------------------------------strumienie-----------------------------
std::istream& operator>> (std::istream &strm, Dron& l)         
{
  strm>>l.x;
  return strm;
}
std::ostream & operator<< (std::ostream &wyjscie, const Dron &s) 
{
  wyjscie << "(" << "i)";
  return wyjscie;
}
