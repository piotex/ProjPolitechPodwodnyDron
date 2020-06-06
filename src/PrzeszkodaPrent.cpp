#include "PrzeszkodaPrent.hh"


PrzeszkodaPrent::PrzeszkodaPrent(){
}

PrzeszkodaPrent::PrzeszkodaPrent(std::shared_ptr<drawNS::Draw3DAPI> &_api, double dlB, Wektor<double,3> pol){
    if(dlB <= 0){
        std::cerr << "niedodatnia wartość dlugosci" << std::endl;
        exit(1);
    }  
    api = _api;
    dlugosc = dlB;
    pSrodka = pol;
        std::cerr << "xx\n\n" << std::endl;

    rysuj();
}

bool PrzeszkodaPrent::czy_kolizja(InterfejsDron* dron){
    vector<Wektor<double,3>> punkty;
    dron->get_punktyKrytyczne(punkty);
       std::cout<<"\n\n\n";

    for (int i = 0; i < 8; i++)
    {
       std::cout<<punkty[i]<<"\n";
    }
    
    return false;
}

void PrzeszkodaPrent::rysuj(){
    if(id != 0)
        usunFigure();

    double x1 = pSrodka[0] + dlugosc;
    double x2 = pSrodka[0] - dlugosc;
    id = api->draw_line(drawNS::Point3D(x1,pSrodka[1],pSrodka[2]), drawNS::Point3D(x2,pSrodka[1],pSrodka[2]));
}