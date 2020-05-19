#include "Dron.hh"
#include "Graniastoslup.hh"
#include "Sruba.hh"

Dron::Dron(){
  dlugosciBokow = Wektor<double,3>(100,50,20);
}
Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> boki){
  api = _api;
  dlugosciBokow = boki;
  g1.set_api(_api);
  g2.set_api(_api);
  g1.set_pSrodka(Wektor<double,3> (-20,-45,0));
  g2.set_pSrodka(Wektor<double,3> (20,-45,0));
}

Wektor<double,3> obrotZ(Wektor<double,3> a,Wektor<double,3> b,double kat){

    Wektor<double,3> ret ;//= (mkX * w1)+masPoint;
    ret[0] = (a[0]-b[0])*cos(kat*PI/180) - (a[1]-b[1])*sin (kat*PI/180) + (b[0]);
    ret[1] = (a[0]-b[0])*sin(kat*PI/180) + (a[1]-b[1])*cos (kat*PI/180) + (b[1]);
    ret[2]=a[2];
    return ret;
}

void Dron::obrot(TypObrotu typ, double kat){
  
  if (typ==OsZ)
  {
    double predkosc = 1 * ( kat / abs(kat) );
    kat= abs(kat);
    while (kat>0)
    {
      MacierzObrotu mac(typ,predkosc);
      MacierzObrotu macObrSr(OsX,predkosc);


      orientacja = orientacja * mac;
      g1.set_pSrodka(obrotZ(g1.pSrodka,pSrodka,-predkosc));
      g1.obrot(OsX,1);
      g2.set_pSrodka(obrotZ(g2.pSrodka,pSrodka,-predkosc));
      g2.obrot(OsX,1);

      rysuj();
      kat--;
    }
  }
  else
  {
    MacierzObrotu mac(typ,kat);
    orientacja = orientacja * mac;
  }
}
void Dron::plyn(double r,double kat){
  double predkosc = 1 * ( r / abs(r) );
  r= abs(r);

  while (r>0)
  {
    Wektor<double,3> dyst(0,predkosc,0);
    obrot(OsX,-kat); //zmiana wektora kierunkowego
    get_zorientowanyWektor(dyst);
    pSrodka = pSrodka + dyst;
    obrot(OsX,kat); //powrot wektora kierunkowego

    g1.przesun(dyst);
    g2.przesun(dyst);

    rysuj();

    r--;
  }

}

void Dron::rysuj(){
  Prostopadloscian::rysuj();
  g1.rysuj();
  g2.rysuj();
}
