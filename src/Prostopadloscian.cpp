#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(){
    dlugosciBokow = Wektor<double,3>(10,10,10);
}
Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> dlB){
    for (int i = 0; i < 3; i++){
        if(dlB[i] < 0){
            std::cerr << "ujemna wartość boku" << std::endl;
            exit(1);
        }  
    }
    api = _api;
    dlugosciBokow = dlB;
}

void Prostopadloscian::get_wyliczonePunkty(Wektor<double,3> *ret){

  Wektor<double,3> idn = orientacja * (dlugosciBokow/2);

  Wektor<double,3> bokX(dlugosciBokow[0],0,0);
  Wektor<double,3> bokY(0,dlugosciBokow[1],0);
  Wektor<double,3> bokZ(0,0,dlugosciBokow[2]);

  get_zorientowanyWektor(bokX);
  get_zorientowanyWektor(bokY);
  get_zorientowanyWektor(bokZ);
  
  //ryzuje wzgledem pierwszego punktu zamiast srodka jak wczesniej 
  ret[0] = pSrodka + idn;
  ret[1] = pSrodka + idn - bokX;
  ret[2] = pSrodka + idn - bokX - bokY;
  ret[3] = pSrodka + idn - bokY;
  ret[4] = pSrodka + idn - bokZ;
  ret[5] = pSrodka + idn - bokX - bokZ;
  ret[6] = pSrodka + idn - bokY - bokZ - bokX;
  ret[7] = pSrodka + idn - bokY - bokZ;
}
void Prostopadloscian::rysuj() {
    usunFigure();
    Wektor<double,3> tab[8];
    get_wyliczonePunkty(tab);
    vector<vector<Point3D>> prost = vector<vector<Point3D>> {{
                                        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), 
                                        drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), 
                                        drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), 
                                        drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
                                    },{
                                        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), 
                                        drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]), 
                                        drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), 
                                        drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
                                    }};
    id = api->draw_polyhedron(prost);
 
}


bool Prostopadloscian::czy_kolizja(InterfejsDron dron){

}