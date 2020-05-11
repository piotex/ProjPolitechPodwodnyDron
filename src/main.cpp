#include<iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "../inc/Wektor.hh"
#include "Prostopadloscian.hh"
#include "Plaszczyzna.hh"

#include <unistd.h>
#include <termios.h>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

int main(int argc, char **argv)
{
        std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,500,0,500,0,500,1000)); 
        api->change_ref_time_ms(0);

        int predkosc = 5;
        Dron p;
        Plaszczyzna pp;
        Plaszczyzna pp2;
        pp2.setPolozenie(Wektor<double,3>{0,0,10});
        pp2.rysuj(api);
        pp.setPolozenie(Wektor<double,3>{0,0,450});
        pp.rysuj(api);
        
        p.rysuj(api);
        while(1){
                double tab[] = {0,0,0};
                double kat[] = {0,0,0};
                char znak = getch();
                switch (znak)
                {
                        case '3':tab[0] = predkosc; break;
                        case '1':tab[0] = -predkosc; break;
                        case '5':tab[1] = predkosc; break;
                        case '2':tab[1] = -predkosc; break;
                        case '6':tab[2] = predkosc; break;
                        case '4':tab[2] = -predkosc; break;
                        case '7':kat[0] = predkosc; break;
                        case '8':kat[1] = predkosc; break;
                        case '9':kat[2] = predkosc; break;
                        case 'q':return 0;
                }  
                p.przesun(tab);
                p.obroc(kat);
                p.rysuj(api);
        }


}

