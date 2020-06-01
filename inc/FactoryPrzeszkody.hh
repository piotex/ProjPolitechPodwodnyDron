#ifndef FACTORYPRZESZKODA_HH
#define FACTORYPRZESZKODA_HH

#include "InterfejsDron.hh"
#include "PrzeszkodaPrent.hh"
#include "PrzeszkodaProstopadloscian.hh"

class FactoryPrzeszkody {   
  public:
        FactoryPrzeszkody();
        FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &api);
        vector<PrzeszkodaProstopadloscian> dic1;
        // vector<Przeszkoda> dic;

        std::shared_ptr<drawNS::Draw3DAPI> api;
        void rysuj();
        bool wystapilaKolizja(InterfejsDron* dron);
};



#endif
