#ifndef FACTORYPRZESZKODA_HH
#define FACTORYPRZESZKODA_HH

#include "PrzeszkodaProstopadloscian.hh"

class FactoryPrzeszkody {   
  public:
        FactoryPrzeszkody();
        FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &api);
        vector<PrzeszkodaProstopadloscian> dic1;

        void rysuj();
};



#endif
