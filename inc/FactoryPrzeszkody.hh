#ifndef FACTORYPRZESZKODA_HH
#define FACTORYPRZESZKODA_HH

#include "PrzeszkodaPrent.hh"
#include "PrzeszkodaProstopadloscian.hh"

class FactoryPrzeszkody {   
  public:
        FactoryPrzeszkody();
        FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &api);
        vector<PrzeszkodaProstopadloscian> dic1;
        vector<PrzeszkodaPrent> dic2;
        std::shared_ptr<drawNS::Draw3DAPI> api;
        void rysuj();
};



#endif
