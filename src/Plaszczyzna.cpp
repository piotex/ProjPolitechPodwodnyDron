#include "Plaszczyzna.hh"

Plaszczyzna::Plaszczyzna(){

}

int Plaszczyzna::rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api) const{

    int aaaa = 100;
    // api->erase_shape(old_idk);

    std::cout<< polozenie[2] << "\n\n\n";

    std::vector<std::vector<drawNS::Point3D> > xd;
    for (int j = 0; j < 10; j++)
    {
      std::vector<drawNS::Point3D> cd;
      for (int i = 0; i < 10; i++)
      {
        cd.push_back(drawNS::Point3D(aaaa*i,aaaa*j,polozenie[2]));
      }
      xd.push_back(cd);
    }
    old_idk = api->draw_surface(xd,"black");
    return old_idk;
}


int Plaszczyzna::przesun(const Wektor<double,3> &wek) {

}     
int Plaszczyzna::obroc(const Wektor<double,3> &kat) {

}     

void Plaszczyzna::setPolozenie(const Wektor<double,3> &wek){
  for (int i = 0; i < 3; i++)
  {
    polozenie[i] = wek[i];
  }
  
}     


