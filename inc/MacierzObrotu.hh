#ifndef MACIERZOBROTU_HH
#define MACIERZOBROTU_HH
#include<iostream>
#include "MacierzKw.hh"

enum TypObrotu{
    OsX,
    OsY,
    OsZ
};

class MacierzObrotu : public MacierzKw<double,3> {    
  
  public:           
    MacierzObrotu GetMacierz(TypObrotu typ, double kat);
    Wektor<double,3> CalculateLine(TypObrotu typ,Wektor<double,3> srodekMasy);
};

#endif