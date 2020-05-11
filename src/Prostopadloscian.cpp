#include "Prostopadloscian.hh"


//helper - konwertuje
drawNS::Point3D wektorToPoint( Wektor<double,3> figura){
    return drawNS::Point3D(figura[0],figura[1],figura[2]);
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
void calculatePoints(const Wektor<double,3> srodekMasy,const Wektor<double,3> polozenie,const Wektor<double,3> dlugosciBokow,const Wektor<double,3> katy, Wektor<double,3>* returnTable){
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
        returnTable[i] = obrotX(returnTable[i],srodekMasy,katy[0]);
        returnTable[i] = obrotY(returnTable[i],srodekMasy,katy[1]);
        returnTable[i] = obrotZ(returnTable[i],srodekMasy,katy[2]);
    }
}

Prostopadloscian::Prostopadloscian(){
    dlugosciBokow  = Wektor<double,3>{0,0,0};
    srodekMasy = &polozenie;
}
Prostopadloscian::Prostopadloscian(double wymX,double wymY,double wymZ,double polX,double polY,double polZ){
    dlugosciBokow = Wektor<double,3>{wymX,wymY,wymZ};
    polozenie = Wektor<double,3>{polX,polY,polZ};
    srodekMasy = &polozenie;
}

int Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> &api) const {
    api->erase_shape(old_idk);

    Wektor<double,3> figura[8];
    calculatePoints(*srodekMasy,polozenie ,dlugosciBokow,katy,figura);
    old_idk = api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {
    {drawNS::Point3D(wektorToPoint(figura[0])),
     drawNS::Point3D(wektorToPoint(figura[1])), 
     drawNS::Point3D(wektorToPoint(figura[3])),
     drawNS::Point3D(wektorToPoint(figura[2]))},
    {drawNS::Point3D(wektorToPoint(figura[4])), 
     drawNS::Point3D(wektorToPoint(figura[5])),
     drawNS::Point3D(wektorToPoint(figura[7])),
     drawNS::Point3D(wektorToPoint(figura[6]))}
    });
    return old_idk;
}
int Prostopadloscian::przesun(const Wektor<double,3> &wek) {
    polozenie+=wek;
    return 1;
}
int Prostopadloscian::obroc(const Wektor<double,3> &kat) {
    katy+=kat;
    return 1;
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





