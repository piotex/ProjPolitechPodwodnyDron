#include "Dron.hh"

//----------------------------------------------------------------------------------konstruktor---------------------------------

 
//---------------------------------------------------------------------------------------strumienie-----------------------------
std::istream& operator>> (std::istream &strm, Dron& l)         
{
  
  return strm;
}
std::ostream & operator<< (std::ostream &wyjscie, const Dron &s) 
{
  wyjscie << "(" << "i)";
  return wyjscie;
}
