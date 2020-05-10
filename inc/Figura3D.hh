#ifndef FIGURA3D_HH
#define FIGURA3D_HH

#include<iostream>
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"

class Figura3D {    
  protected:
    Wektor<double,3> polozenie;
    Wektor<double,3> katy;
  public:  
    //funkcje zwracaja kod bledu
    virtual int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api, int* tab ) const = 0;         
    virtual void usunKsztalt(std::shared_ptr<drawNS::Draw3DAPI> &api, const int* id) =0;

    virtual int przesun(const Wektor<double,3> &wek) = 0;
    virtual int odroc(const Wektor<double,3> &kat) = 0;

    virtual drawNS::Point3D getPolozenie() const = 0;
    virtual void setPolozenie(const Wektor<double,3> &wek) =0;

};

#endif