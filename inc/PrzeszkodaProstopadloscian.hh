#ifndef PRZESZKODAPROSTOPADLOSCIAN_HH
#define PRZESZKODAPROSTOPADLOSCIAN_HH

#include "Przeszkoda.hh"

class PrzeszkodaProstopadloscian : public Przeszkoda {      
  protected:
  public:
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    */ 
    PrzeszkodaProstopadloscian();
    /*!
    * \brief konstruktor ustawiajacy poczatkowe wartosci PrzeszkodaProstopadloscian
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &api);
    /*!
    * \brief metoda - sprawdza kolizje
    * \param dron - instancja klasy dron przekazana ponieważ zawiera wszystkie punkty drona potrzebne do wykrycia kolizji
    */ 
    bool czy_kolizja(InterfejsDron dron) override; 
};



#endif
