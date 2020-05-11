#ifndef DRON_HH
#define DRON_HH
#include<iostream>
#include "Prostopadloscian.hh"

class Dron : public Prostopadloscian {    
  
  public:           
    Dron();
    Prostopadloscian body;
    Prostopadloscian srobaL;
    Prostopadloscian srobaR;


    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api) const override;         
    int obroc(const Wektor<double,3> &kat) override;
    int przesun(const Wektor<double,3> &wek) override;

};

#endif