#include "Graniastoslup.hh"

Graniastoslup::Graniastoslup(){
    MacierzObrotu mac(OsY,90);
    MacierzObrotu mac2(OsX,90);
    orientacja = orientacja * mac;
    orientacja = orientacja * mac2;
    wysokosc = 10;
    bok = 10;
}
Graniastoslup::Graniastoslup(std::shared_ptr<drawNS::Draw3DAPI> &_api, double b, double h){
    MacierzObrotu mac(OsY,90);
    MacierzObrotu mac2(OsX,90);
    orientacja = orientacja * mac;
    orientacja = orientacja * mac2;
    api = _api;
    bok = b;
    wysokosc = h;
}
void Graniastoslup::set_pro(double b, double w){
    bok = b;
    wysokosc = w;
}

void Graniastoslup::get_wyliczonePunkty(Wektor<double,3> *ret){
    double h = bok * sqrtl(3) /2;
    double _x = bok;
    double _x2 = bok / 2;
    //powoduje ze sroba jest w tym samym kierunku co dron


    Wektor<double,3> y(h,0,0);
    Wektor<double,3> x(0,_x,0);
    Wektor<double,3> x2(0,_x2,0);
    Wektor<double,3> bokZ(0,0,wysokosc);

    get_zorientowanyWektor(y);
    get_zorientowanyWektor(x);
    get_zorientowanyWektor(x2);
    get_zorientowanyWektor(bokZ);
    
    //ryzuje wzgledem srodka 
    ret[0] = pSrodka + bokZ + y + x2;
    ret[1] = pSrodka + bokZ + x ;
    ret[2] = pSrodka + bokZ - y + x2;
    ret[3] = pSrodka + bokZ - y - x2;
    ret[4] = pSrodka + bokZ - x;
    ret[5] = pSrodka + bokZ + y - x2;

    ret[6] = pSrodka - bokZ + y + x2;
    ret[7] = pSrodka - bokZ + x ;
    ret[8] = pSrodka - bokZ - y + x2;
    ret[9] = pSrodka - bokZ - y - x2;
    ret[10] = pSrodka - bokZ - x;
    ret[11] = pSrodka - bokZ + y - x2;

    
}
void Graniastoslup::rysuj() {
    
    if (id != 0)
        usunFigure();
    Wektor<double,3> tab[12];
    get_wyliczonePunkty(tab);
        
    vector<vector<Point3D>> prost = vector<vector<Point3D>> {{
                                        drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]), 
                                        drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]), 
                                        drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]), 
                                        drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]), 
                                        drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]), 
                                        drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])
                                    },{
                                        drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]), 
                                        drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2]), 
                                        drawNS::Point3D(tab[8][0],tab[8][1],tab[8][2]), 
                                        drawNS::Point3D(tab[9][0],tab[9][1],tab[9][2]), 
                                        drawNS::Point3D(tab[10][0],tab[10][1],tab[10][2]), 
                                        drawNS::Point3D(tab[11][0],tab[11][1],tab[11][2])
                                    }};

    id = api->draw_polyhedron(prost);
}


