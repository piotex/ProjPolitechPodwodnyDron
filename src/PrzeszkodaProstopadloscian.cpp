#include "PrzeszkodaProstopadloscian.hh"

PrzeszkodaProstopadloscian::PrzeszkodaProstopadloscian(){
    dlugosciBokow = Wektor<double,3>(10,10,10);
}
PrzeszkodaProstopadloscian::PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> dlB, Wektor<double,3> pol){
    for (int i = 0; i < 3; i++){
        if(dlB[i] <= 0){
            std::cerr << "niedodatnia wartość boku" << std::endl;
            exit(1);
        }  
    }
    api = _api;
    dlugosciBokow = dlB;
    pSrodka = pol;
    rysuj();
}

bool PrzeszkodaProstopadloscian::czy_kolizja(InterfejsDron* dron){
    Wektor<double,3> w1 = (*dron).get_srodek_masyDrona();
    Wektor<double,3> w2 = pSrodka;
    if (w1 == w2)
    {
        return true;
    }
    return false;
    
}



