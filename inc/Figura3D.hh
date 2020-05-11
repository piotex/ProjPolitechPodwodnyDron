#ifndef FIGURA3D_HH
#define FIGURA3D_HH

#include<iostream>
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"

class Figura3D {    
  protected:
    // std::shared_ptr<drawNS::Draw3DAPI> api;
    Wektor<double,3> polozenie;
    Wektor<double,3> katy;
    void set_old_id(int new_id);
  public:  
    // Figura3D(std::shared_ptr<drawNS::Draw3DAPI> &api);
    virtual int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api) const = 0;         

    virtual int przesun(const Wektor<double,3> &wek) = 0;
    virtual int obroc(const Wektor<double,3> &kat) = 0;

    virtual void setPolozenie(const Wektor<double,3> &wek) =0;

    // virtual void usunFigure() ;

};

#endif