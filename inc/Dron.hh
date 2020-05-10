#ifndef DRON_HH
#define DRON_HH
#include<iostream>

class Dron {    
  
  public:           
    Dron();
    Dron(double x, double y, double z);
  double x;    
  double y;
  double z;
};

std::istream& operator>>(std::istream &strm, Dron& l);
std::ostream& operator<<(std::ostream &wyjscie, const Dron &s);

#endif