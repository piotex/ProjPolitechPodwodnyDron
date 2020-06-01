#ifndef INTERDRON_HH
#define INTERDRON_HH
#include<iostream>
#include "MacierzObrotu.hh"

class InterfejsDron {    
     /*!
    * \brief obrot() - funkcja sluzaca do obrotu drona wzgledem zadanej osi
    * \param typ - typ osi obrotu
    * \param kat - kat o jaki ma zostac wykonany obrot 
    */ 
    virtual void obrot(TypObrotu typ, double kat)=0;
    /*!
    * \brief plyn() - funkcja sluzaca do zmiany polozenia drona
    * \param dyst - dystans jaki ma przebyc dron
    * \param kat - kat pod ktorym dron bedzie sie poruszal 
    */ 
    virtual void plyn(double dyst,double kat)=0;
};

#endif