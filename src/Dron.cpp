#include "Dron.hh"
#include "Graniastoslup.hh"
#include "Sruba.hh"
#include "PrzeszkodaProstopadloscian.hh"
#include "InterfejsDron.hh"

Dron::Dron(){
  predkosc = 5;
  dlugosciBokow = Wektor<double,3>(100,50,20);
}
Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> boki){
  api = _api;
  predkosc = 5;
  dlugosciBokow = boki;
  g1.set_api(_api);
  g2.set_api(_api);
  g1.set_pSrodka(Wektor<double,3> (-20,-45,0));
  g2.set_pSrodka(Wektor<double,3> (20,-45,0));
}

Wektor<double,3> obrotZ(Wektor<double,3> a,Wektor<double,3> osObroty,double kat){

    Wektor<double,3> ret ;//= (mkX * w1)+masPoint;
    ret[0] = (a[0]-osObroty[0])*cos(kat*PI/180) - (a[1]-osObroty[1])*sin (kat*PI/180) + (osObroty[0]);
    ret[1] = (a[0]-osObroty[0])*sin(kat*PI/180) + (a[1]-osObroty[1])*cos (kat*PI/180) + (osObroty[1]);
    ret[2]=a[2];
    return ret;
}




void Dron::obrot(TypObrotu typ, double kat){
  if (typ==OsZ)
  {
    double predkosc_lokal = 1 * ( kat / abs(kat) );
    kat= abs(kat);
    while (kat>0)
    {
      MacierzObrotu mac(typ,predkosc_lokal);

      orientacja = orientacja * mac;

      g1.pSrodka = obrotZ(g1.pSrodka,pSrodka,-predkosc_lokal);
      g1.obrot(OsZ,predkosc_lokal);

      g2.pSrodka = obrotZ(g2.pSrodka,pSrodka,-predkosc_lokal);
      g2.obrot(OsZ,predkosc_lokal);

      if (static_cast<int>(kat)%static_cast<int>(predkosc) == 0)    // szybciej sie porusza a na koncu i tak jest rysuj wiec zawszecos wyrysuje
      {
          g1.obrot(OsY,-120);
          g2.obrot(OsY,120);
          for (int i = 0; i < 3; i++)
          {
              g1.obrot(OsY,40);
              g2.obrot(OsY,-40);
              rysuj();
          }
      }
      kat-=1;
    }
    rysuj();
  }
  else
  {
    MacierzObrotu mac(typ,kat);
    orientacja = orientacja * mac;
  }
}



void Dron::plyn(double r,double kat){
    double predkosc_lokal = 1 * ( r / abs(r) );
    r= abs(r);

    while (r>0)
    {
        Wektor<double,3> dyst(0,predkosc_lokal,0);
        obrot(OsX,-kat); //zmiana wektora kierunkowego
        get_zorientowanyWektor(dyst);
        pSrodka = pSrodka + dyst;
        obrot(OsX,kat); //powrot wektora kierunkowego

        g1.przesun(dyst);
        g2.przesun(dyst);

        if (static_cast<int>(r)%static_cast<int>(predkosc) == 0)    // szybciej sie porusza a na koncu i tak jest rysuj wiec zawszecos wyrysuje
        {
            g1.obrot(OsY,-120);
            g2.obrot(OsY,-120);
            for (int i = 0; i < 3; i++)
            {
                g1.obrot(OsY,40);
                g2.obrot(OsY,40);
                rysuj();
            }
        }
        r--;
    }
    rysuj();
}

void Dron::rysuj(){
  Prostopadloscian::rysuj();
  g1.rysuj();
  g2.rysuj();

}



