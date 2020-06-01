#include "PrzeszkodaPrent.hh"


PrzeszkodaPrent::PrzeszkodaPrent(){
    dlugosciBokow = Wektor<double,3>(10,10,10);
}
PrzeszkodaPrent::PrzeszkodaPrent(std::shared_ptr<drawNS::Draw3DAPI> &_api, double r, double h){
    api = _api;
    dlugosciBokow = Wektor<double,3>(r,h,r);
}

bool PrzeszkodaPrent::czy_kolizja(InterfejsDron* dron){
    Wektor<double,3> tab[8];
    Wektor<double,3> tab_dron[8];
    get_wyliczonePunkty(tab);
    Wektor<double,3> w1 = (*dron).get_srodek_masyDrona();
    Wektor<double,3> w2 = pSrodka;
    if (w1 == w2)
    {
        return true;
    }
    return false;
}