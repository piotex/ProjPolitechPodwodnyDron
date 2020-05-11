#include "Dron.hh"

 
Dron::Dron(){

  body.setDlugoscBokow( Wektor<double,3>{100,50,50});
  body.setPolozenie( Wektor<double,3>{100,50,50});

  srobaL.setDlugoscBokow( Wektor<double,3>{20,6,6});
  srobaL.setPolozenie( Wektor<double,3>{160,75,25});

  srobaR.setDlugoscBokow( Wektor<double,3>{20,6,6});
  srobaR.setPolozenie( Wektor<double,3>{160,25,25});

  srobaL.srodekMasy = body.srodekMasy;
  srobaR.srodekMasy = body.srodekMasy;
}


int Dron::rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api) const {
  body.rysuj(api);
  srobaL.rysuj(api);
  srobaR.rysuj(api);
}         
int Dron::obroc(const Wektor<double,3> &kat) {
  body.obroc(kat);
  srobaL.obroc(kat);
  srobaR.obroc(kat);
}
int Dron::przesun(const Wektor<double,3> &wek) {
  body.przesun(wek);
  srobaL.przesun(wek);
  srobaR.przesun(wek);
}