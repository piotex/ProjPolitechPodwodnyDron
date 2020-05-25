#include "Sruba.hh"


Sruba::Sruba(){
  bok = 10;
  wysokosc=10;
}
Sruba::Sruba(std::shared_ptr<drawNS::Draw3DAPI> &_api, double b, double h){
  api = _api;
  bok = b;
  wysokosc=h;
}


void Sruba::przesun(Wektor<double,3> dyst) {
    pSrodka = pSrodka + dyst ;
}  

void Sruba::obrot(TypObrotu typ, double kat){

    MacierzObrotu mac2(typ,kat);
    orientacja = orientacja * mac2;
}



