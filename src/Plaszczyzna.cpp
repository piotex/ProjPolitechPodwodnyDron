#include "Plaszczyzna.hh"

Plaszczyzna::Plaszczyzna(){
  pSrodka = Wektor<double,3>(0,0,0);
}
Plaszczyzna::Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &_api,Wektor<double,3> pol){
  pSrodka = pol;
  api = _api;
}
void Plaszczyzna::rysuj(){
    std::vector<std::vector<drawNS::Point3D> > macierz;
    for (int j = 0; j < numer; j++)
    {
      std::vector<drawNS::Point3D> cd;
      for (int i = 0; i < numer; i++)
      {
        cd.push_back(drawNS::Point3D(pSrodka[0]+rozmiar*i,pSrodka[1]+rozmiar*j,pSrodka[2]));
      }
      macierz.push_back(cd);
    }
    id = api->draw_surface(macierz,"red");
}