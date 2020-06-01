#ifndef PRZESZKODAPRENT_HH
#define PRZESZKODAPRENT_HH

#include "PrzeszkodaProstopadloscian.hh"

class PrzeszkodaPrent : public PrzeszkodaProstopadloscian {      
  protected:
  public:
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    */ 
    PrzeszkodaPrent();
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    PrzeszkodaPrent(std::shared_ptr<drawNS::Draw3DAPI> &_api, double promien, double dlugosc);
};



#endif
