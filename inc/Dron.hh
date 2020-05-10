#ifndef DRON_HH
#define DRON_HH
#include<iostream>

class Dron {    
  
  public:           
  double z;
    // void setDlugoscBokow(const Wektor<double,3> &wek) override;

};

std::istream& operator>>(std::istream &strm, Dron& l);
std::ostream& operator<<(std::ostream &wyjscie, const Dron &s);

#endif