#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(){
    dlugosciBokow  = Wektor<double,3>{0,0,0};
}
Prostopadloscian::Prostopadloscian(double wymX,double wymY,double wymZ,double polX,double polY,double polZ){
    dlugosciBokow = Wektor<double,3>{wymX,wymY,wymZ};
    polozenie = Wektor<double,3>{polX,polY,polZ};
}

Wektor<double,3> obrotX(Wektor<double,3> a,Wektor<double,3> b,double kat){

    Wektor<double,3> ret ;//= (mkX * w1)+masPoint;
    ret[0]=a[0];
    ret[1] = (a[1]-b[1])*cos(kat*PI/180) - (a[2]-b[2])*sin (kat*PI/180) + (b[1]);
    ret[2] = (a[1]-b[1])*sin(kat*PI/180) + (a[2]-b[2])*cos (kat*PI/180) + (b[2]);
    return ret;
}
Wektor<double,3> obrotY(Wektor<double,3> a,Wektor<double,3> b,double kat){

    Wektor<double,3> ret ;//= (mkX * w1)+masPoint;
    ret[0] = (a[0]-b[0])*cos(kat*PI/180) - (a[2]-b[2])*sin (kat*PI/180) + (b[0]);
    ret[1]=a[1];
    ret[2] = (a[0]-b[0])*sin(kat*PI/180) + (a[2]-b[2])*cos (kat*PI/180) + (b[2]);
    return ret;
}
Wektor<double,3> obrotZ(Wektor<double,3> a,Wektor<double,3> b,double kat){

    Wektor<double,3> ret ;//= (mkX * w1)+masPoint;
    ret[0] = (a[0]-b[0])*cos(kat*PI/180) - (a[1]-b[1])*sin (kat*PI/180) + (b[0]);
    ret[1] = (a[0]-b[0])*sin(kat*PI/180) + (a[1]-b[1])*cos (kat*PI/180) + (b[1]);
    ret[2]=a[2];
    return ret;
}


//helper - konwertuje
drawNS::Point3D wektorToPoint( Wektor<double,3> figura){
    return drawNS::Point3D(figura[0],figura[1],figura[2]);
}
//laczy kropki 
void narysuj(std::shared_ptr<drawNS::Draw3DAPI> &api, int* id_ob, Wektor<double,3>* figura ){
    int id =0;
    int polaczenia[12][2] = {
        {0,1},
        {0,2},
        {3,1},
        {3,2},
        {4,5},
        {4,6},
        {7,5},
        {7,6},
        {0,4},
        {1,5},
        {2,6},
        {3,7}
    };
    
    for (int i = 0; i < 12; i++)
    {
        drawNS::Point3D p1 = wektorToPoint( figura[polaczenia[i][0]] );
        drawNS::Point3D p2 = wektorToPoint( figura[polaczenia[i][1]] );

        id_ob[id++] = api->draw_line( p1,p2 );
    }
}
void calculatePoints(const Wektor<double,3> polozenie,const Wektor<double,3> dlugosciBokow,const Wektor<double,3> katy, Wektor<double,3>* returnTable){
    double x=polozenie[0];
    double y=polozenie[1];
    double z=polozenie[2];
        
    double bx=dlugosciBokow[0];
    double by=dlugosciBokow[1];
    double bz=dlugosciBokow[2];
    
    returnTable[0]=  Wektor<double,3>(x+bx/2,y+by/2,z+bz/2);
    returnTable[1]=  Wektor<double,3>(x+bx/2,y+by/2,z-bz/2);
    returnTable[2]=  Wektor<double,3>(x+bx/2,y-by/2,z+bz/2);
    returnTable[3]=  Wektor<double,3>(x+bx/2,y-by/2,z-bz/2);

    returnTable[4]=  Wektor<double,3>(x-bx/2,y+by/2,z+bz/2);
    returnTable[5]=  Wektor<double,3>(x-bx/2,y+by/2,z-bz/2);
    returnTable[6]=  Wektor<double,3>(x-bx/2,y-by/2,z+bz/2);
    returnTable[7]=  Wektor<double,3>(x-bx/2,y-by/2,z-bz/2);
    for (int i = 0; i < 8; i++)
    {
        returnTable[i] = obrotX(returnTable[i],polozenie,katy[0]);
        returnTable[i] = obrotY(returnTable[i],polozenie,katy[1]);
        returnTable[i] = obrotZ(returnTable[i],polozenie,katy[2]);
    }
}

int Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api, int* id_ob) const {
    Wektor<double,3> figura[8];
    calculatePoints(polozenie,dlugosciBokow,katy,figura);
    narysuj(api,id_ob,figura);
    return 0;
}
int Prostopadloscian::przesun(const Wektor<double,3> &wek,const Wektor<double,3> &kat) {
    setPolozenie(polozenie+wek);
    katy+=kat;
    return 1;
}
drawNS::Point3D Prostopadloscian::getPolozenie() const {
    return drawNS::Point3D(polozenie[0],polozenie[1],polozenie[2]);
}
void Prostopadloscian::setPolozenie(const Wektor<double,3> &wek) {
    for (int i = 0; i < 3; i++)
    {
        polozenie[i]= wek[i];
    }
}
void Prostopadloscian::setDlugoscBokow(const Wektor<double,3> &wek) {
    for (int i = 0; i < 3; i++)
    {
        dlugosciBokow[i]= wek[i];
    }
}
void Prostopadloscian::usunKsztalt(std::shared_ptr<drawNS::Draw3DAPI> &api,const int* a) {
    for (int i = 0; i < ILOSC_SCIAN; i++)
    {
        api->erase_shape(a[i]);
    }
}





