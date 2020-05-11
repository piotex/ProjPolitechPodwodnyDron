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
    mutable int old_idk;
    Wektor<double,3>* srodekMasy;
    Prostopadloscian();
    Prostopadloscian(double wymX,double wymY,double wymZ,double polX,double polY,double polZ);

    void setPolozenie(const Wektor<double,3> &wek) override;
    virtual void setDlugoscBokow(const Wektor<double,3> &wek);

    int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api) const override;         
    int obroc(const Wektor<double,3> &kat) override;
    int przesun(const Wektor<double,3> &wek) override;

};

#endif