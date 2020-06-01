#include "PrzeszkodaPrent.hh"


PrzeszkodaPrent::PrzeszkodaPrent(){
    dlugosciBokow = Wektor<double,3>(10,10,10);
}
PrzeszkodaPrent::PrzeszkodaPrent(std::shared_ptr<drawNS::Draw3DAPI> &_api, double r, double h){
    api = _api;
    dlugosciBokow = Wektor<double,3>(r,h,r);
}

bool PrzeszkodaPrent::czy_kolizja(InterfejsDron* dron){

}