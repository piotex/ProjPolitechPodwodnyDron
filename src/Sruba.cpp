#include "Sruba.hh"


Sruba::Sruba(){
  bok = 10;
  wysokosc=5;
}
Sruba::Sruba(std::shared_ptr<drawNS::Draw3DAPI> &api, double b, double h){
//   korekta=Wektor<double,3> (-20,-50,0);
}


void Sruba::przesun(Wektor<double,3> dyst) {
    pSrodka = pSrodka + dyst ;
}  

void Sruba::obrot(TypObrotu typ, double kat){
    MacierzObrotu mac(typ,kat);
    orientacja = orientacja * mac;
}



