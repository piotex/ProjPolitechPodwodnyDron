#ifndef Prostopadloscian_HH
#define Prostopadloscian_HH
#include<iostream>
#include <math.h> 
#include "Figura3D.hh"
#include "MacierzKw.hh"
#define ILOSC_SCIAN 12

class Prostopadloscian : public Figura3D{    
  protected:
    Wektor<double,3> dlugosciBokow;
  public:
    Prostopadloscian();

    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api, int* tab) const override;         
    void usunKsztalt(std::shared_ptr<drawNS::Draw3DAPI> &api, const int* id) override;

    void setPolozenie(const Wektor<double,3> &wek) override;
    drawNS::Point3D getPolozenie() const override;

    int odroc(const Wektor<double,3> &kat) override;
    int przesun(const Wektor<double,3> &wek) override;

};

#endif