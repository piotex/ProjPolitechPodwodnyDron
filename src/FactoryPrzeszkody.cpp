#include "FactoryPrzeszkody.hh"

FactoryPrzeszkody::FactoryPrzeszkody(){

}
FactoryPrzeszkody::FactoryPrzeszkody(std::shared_ptr<drawNS::Draw3DAPI> &_api){
    api = _api;

    PrzeszkodaProstopadloscian p1(api,Wektor<double,3>(25,100,40));
    PrzeszkodaProstopadloscian p2(api,Wektor<double,3>(40,40,40));
    PrzeszkodaProstopadloscian p3(api,Wektor<double,3>(60,30,100));

    p1.set_pSrodka(Wektor<double,3>(-10,10,140));
    p2.set_pSrodka(Wektor<double,3>(10,-100,140));
    p3.set_pSrodka(Wektor<double,3>(10,100,-100));

    dic1.push_back(p1);
    dic1.push_back(p1);
    dic1.push_back(p2);
    dic1.push_back(p3);

    PrzeszkodaPrent p4(api,2,100);
    PrzeszkodaPrent p5(api,2,150);
    PrzeszkodaPrent p6(api,2,30);

    p4.set_pSrodka(Wektor<double,3>(140,-10, 100));
    p5.set_pSrodka(Wektor<double,3>(140,-10, 140));
    p6.set_pSrodka(Wektor<double,3>(140,-10, 180));

    dic1.push_back(p4);
    dic1.push_back(p5);
    dic1.push_back(p6);

    // tak to powinno wygladac dla wszystkich pX ale sypie bledem...
    // dic.push_back(p1);
}

void FactoryPrzeszkody::rysuj(){

    for (unsigned int i = 0; i < dic1.size(); i++)
    {
        dic1[i].rysuj();
    }
    
}
bool FactoryPrzeszkody::wystapilaKolizja(InterfejsDron* dron){
    for (unsigned int i = 0; i < dic1.size(); i++)
    {
        if (dic1[i].czy_kolizja(dron))
            return true;
    }
    return false;    
}
