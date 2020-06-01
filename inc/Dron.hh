#ifndef DRON_HH
#define DRON_HH
#include<iostream>
#include "Sruba.hh"
#include "Prostopadloscian.hh"
#include "InterfejsDron.hh"

/*!
* \brief Dron - klasa reprezentujaca drona
*/
class Dron : public Prostopadloscian, public InterfejsDron {   
  protected:
    /*!
    * \brief skok drona
    */
    double predkosc; 
    /*!
    * \brief g1 - reprezentuje jeden z wirnikow drona
    */
    Sruba g1;
    /*!
    * \brief g2 - reprezentuje jeden z wirnikow drona
    */
    Sruba g2;
  public:   
    /*!
    * \brief Dron() - konstruktor bezparametryczny 
    */     
    Dron();
    /*!
    * \brief Dron() - konstruktor 
    * \param _api - przekazywany przez referencje obiekt do tworzenia obrazu w gnuplocie  
    * \param boki - Wektor<double,3> reprezentujacy boki drona
    */  
    Dron(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> boki);

    /*!
    * \brief rysuj() - funkcja sluzaca rysowania drona
    */ 
    void rysuj() override;
    /*!
    * \brief obrot() - funkcja sluzaca do obrotu drona wzgledem zadanej osi
    * \param typ - typ osi obrotu
    * \param kat - kat o jaki ma zostac wykonany obrot 
    */ 
    void obrot(TypObrotu typ, double kat) override;
    /*!
    * \brief plyn() - funkcja sluzaca do zmiany polozenia drona
    * \param dyst - dystans jaki ma przebyc dron
    * \param kat - kat pod ktorym dron bedzie sie poruszal 
    */ 
    void plyn(double dyst,double kat) override;
 
    Wektor<double,3> get_srodek_masyDrona() override;
    Wektor<double,3> get_wymiary_Drona() override;

};

#endif