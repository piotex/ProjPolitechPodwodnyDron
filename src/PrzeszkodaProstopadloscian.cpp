#include "PrzeszkodaProstopadloscian.hh"
#include "Dron.hh"


PrzeszkodaProstopadloscian::PrzeszkodaProstopadloscian(){
    dlugosciBokow = Wektor<double,3>(10,10,10);
}
PrzeszkodaProstopadloscian::PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> &_api, Wektor<double,3> dlB){
    for (int i = 0; i < 3; i++){
        if(dlB[i] < 0){
            std::cerr << "ujemna wartość boku" << std::endl;
            exit(1);
        }  
    }
    api = _api;
    dlugosciBokow = dlB;
}

bool PrzeszkodaProstopadloscian::czy_kolizja(InterfejsDron* dron){
    Wektor<double,3> tab[8];
    Wektor<double,3> tab_dron[8];
    get_wyliczonePunkty(tab);

}



