#ifndef FIGURA3D_HH
#define FIGURA3D_HH

#include<iostream>
#include "Wektor.hh"
#include "MacierzObrotu.hh"
#include "Dr3D_gnuplot_api.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Figura3DDron - klasa reprezentujaca obiekt 3D
*/
class Figura3D {    
  protected:
    /*!
    * \brief id - pole przechowujace wartosc id - sluzy do usuniecia zadanego ksztaltu
    */
    mutable int id;
    /*!
    * \brief api - pole przechowujace obiekt sluzacy do tworzenia grafiki w gnuplocie
    */
    std::shared_ptr<drawNS::Draw3DAPI> api;

  public: 
    /*!
    * \brief pSrodka - pole przechowujace pozycje srodka Figury
    */ 
    Wektor<double,3> pSrodka; 
    /*!
    * \brief orientacja - reprezentuje orientacje figury
    */ 
    MacierzObrotu orientacja;
    /*!
    * \brief Figura3D() - konstruktor bezparametryczny - sluzy ustawianiu wartosci Figura 
    */ 
    Figura3D();
    /*!
    * \brief Figura3D() - konstruktor ustawiajacy poczatkowe wartosci
    * \param api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    */ 
    Figura3D(std::shared_ptr<drawNS::Draw3DAPI> &api);

    //ogolnie te voidy mozna by zamienic na int i zwracac kod bledy ale na razie niech tak zostanie + wyjatki 
    /*!
    * \brief  rysuj() - funkcja sluzaca rysowania Figura3D - wymaga nadpisania
    */ 
    virtual void rysuj() = 0;         
    /*!
    * \brief usunFigure() - funkcja sluzaca do usuwania obecnego ksztaltu
    */ 
    virtual void usunFigure() ;

    /*!
    * \brief set_pSrodka() - funkcja sluzaca ustawieniu nowych wspolzednych srodka
    * \param wek - nowa wartosc srodka figury
    */ 
    virtual void set_pSrodka(const Wektor<double,3> &wek);
    /*!
    * \brief sluzy do ustawienia nowej orientacji Figura3D
    * \param mac - nowa wartosc orientacji Figura3D
    */ 
    virtual void set_orientacja(const MacierzObrotu &mac);
    /*!
    * \brief sluzy do ustawienia api Figura3D
    * \param mac - nowa wartosc api do rysowania w gnuplocie
    */ 
    virtual void set_api(std::shared_ptr<drawNS::Draw3DAPI> &api);

    /*!
    * \brief metoda sluzaca do orientacji wektora
    * \param wek - wektor do zorientowania
    */ 
    virtual void get_zorientowanyWektor(Wektor<double,3> &wek) const;
};

#endif