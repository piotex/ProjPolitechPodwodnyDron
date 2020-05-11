#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Figura3D.hh"

class Plaszczyzna : public Figura3D{
    public:
        Plaszczyzna();
        int rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api)const override;     
        int przesun(const Wektor<double,3> &wek) override;     
        int obroc(const Wektor<double,3> &kat) override;     

        void setPolozenie(const Wektor<double,3> &wek)override;     
};

#endif