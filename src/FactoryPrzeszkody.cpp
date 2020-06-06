#include "FactoryPrzeszkody.hh"

FactoryPrzeszkody::FactoryPrzeszkody(){

}
FactoryPrzeszkody::FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &_api){
    api = _api;

    std::shared_ptr<PrzeszkodaProstopadloscian> prostopadloscian_1(new PrzeszkodaProstopadloscian(api,Wektor<double,3>(25,100,40),Wektor<double,3>(125,100,120)));
    std::shared_ptr<PrzeszkodaProstopadloscian> prostopadloscian_2(new PrzeszkodaProstopadloscian(api,Wektor<double,3>(25,100,40),Wektor<double,3>(125,100,40)));
    std::shared_ptr<PrzeszkodaProstopadloscian> prostopadloscian_3(new PrzeszkodaProstopadloscian(api,Wektor<double,3>(25,100,40),Wektor<double,3>(125,100,-40)));
    dic1.push_back(prostopadloscian_1);
    dic1.push_back(prostopadloscian_2);
    dic1.push_back(prostopadloscian_3);
    std::shared_ptr<PrzeszkodaPrent> pret_4(new PrzeszkodaPrent(api,50,Wektor<double,3>(0,-100,120)));
    std::shared_ptr<PrzeszkodaPrent> pret_5(new PrzeszkodaPrent(api,100,Wektor<double,3>(0,-100,40)));
    std::shared_ptr<PrzeszkodaPrent> pret_6(new PrzeszkodaPrent(api,150,Wektor<double,3>(0,-100,-40)));
    dic1.push_back(pret_4);
    dic1.push_back(pret_5);
    dic1.push_back(pret_6);
}
void FactoryPrzeszkody::get_kolekcja(vector<std::shared_ptr<Przeszkoda>> &dic11){
    dic11 = dic1;
}
