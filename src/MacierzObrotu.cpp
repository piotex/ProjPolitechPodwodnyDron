#include "MacierzObrotu.hh"
#include "Wektor.hh"


MacierzObrotu MacierzObrotu::GetMacierz(TypObrotu typ, double kat){
    
    switch (typ)
    {
        case OsX:
            (*this).set_Kolumna(0,Wektor<double,3>{cos(kat*PI/180), sin(kat*PI/180),0});
            (*this).set_Kolumna(1,Wektor<double,3>{-sin(kat*PI/180),cos(kat*PI/180),0});
            (*this).set_Kolumna(2,Wektor<double,3>{0,0,1});
            break;
        case OsY:
            (*this).set_Kolumna(0,Wektor<double,3>{cos(kat*PI/180),0,sin(kat*PI/180)});
            (*this).set_Kolumna(2,Wektor<double,3>{0,1,0});
            (*this).set_Kolumna(1,Wektor<double,3>{-sin(kat*PI/180),0,cos(kat*PI/180)});
            break;
        case OsZ:
            (*this).set_Kolumna(2,Wektor<double,3>{1,0,0});
            (*this).set_Kolumna(0,Wektor<double,3>{1,cos(kat*PI/180), sin(kat*PI/180)});
            (*this).set_Kolumna(1,Wektor<double,3>{0,-sin(kat*PI/180),cos(kat*PI/180)});
            break;
    }
    return (*this);
}
Wektor<double,3> MacierzObrotu::CalculateLine(TypObrotu typ,Wektor<double,3> srodekMasy){
    switch (typ)
    {
        case OsX:
            srodekMasy[0] =0;
            break;
        case OsY:
            srodekMasy[1] =0;
            break;
        case OsZ:
            srodekMasy[2] =0;
            break;
    }
    return srodekMasy;
}













