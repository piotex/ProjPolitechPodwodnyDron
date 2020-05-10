#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(){
    double d[]={10,10,10};
    dlugosciBokow  = Wektor<double,3>(d);
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
drawNS::Point3D wektorToPoint( Wektor<double,3> figura){
    return drawNS::Point3D(figura[0],figura[1],figura[2]);
}
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

int Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api, int* id_ob) const {

    double x=polozenie[0];
    double y=polozenie[1];
    double z=polozenie[2];
        
    double bx=dlugosciBokow[0];
    double by=dlugosciBokow[1];
    double bz=dlugosciBokow[2];
    
    
    Wektor<double,3> figura[12];
    figura[0]=  Wektor<double,3>(x+bx/2,y+by/2,z+bz/2);
    figura[1]=  Wektor<double,3>(x+bx/2,y+by/2,z-bz/2);
    figura[2]=  Wektor<double,3>(x+bx/2,y-by/2,z+bz/2);
    figura[3]=  Wektor<double,3>(x+bx/2,y-by/2,z-bz/2);

    figura[4]=  Wektor<double,3>(x-bx/2,y+by/2,z+bz/2);
    figura[5]=  Wektor<double,3>(x-bx/2,y+by/2,z-bz/2);
    figura[6]=  Wektor<double,3>(x-bx/2,y-by/2,z+bz/2);
    figura[7]=  Wektor<double,3>(x-bx/2,y-by/2,z-bz/2);

    for (int i = 0; i < 8; i++)
    {
        figura[i] = obrotX(figura[i],polozenie,katy[0]);
        figura[i] = obrotY(figura[i],polozenie,katy[1]);
        figura[i] = obrotZ(figura[i],polozenie,katy[2]);
    }
    narysuj(api,id_ob,figura);
    return 0;
}
int Prostopadloscian::przesun(const Wektor<double,3> &wek) {
    setPolozenie(polozenie+wek);
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
void Prostopadloscian::usunKsztalt(std::shared_ptr<drawNS::Draw3DAPI> &api,const int* a) {
    for (int i = 0; i < ILOSC_SCIAN; i++)
    {
        api->erase_shape(a[i]);
    }
}
int Prostopadloscian::odroc(const Wektor<double,3> &kat) {
    katy += kat;    
}





