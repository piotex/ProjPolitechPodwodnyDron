#include<iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "../inc/Wektor.hh"
#include "Prostopadloscian.hh"

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
        std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,100,0,100,0,100,1000)); 
        api->change_ref_time_ms(0);

        Prostopadloscian p;
        int a[12];
        double tab[] = {50,50,50};
        double obrX[] = {1,0,0};
        double obrY[] = {0,1,0};
        double obrZ[] = {0,0,1};

        char znak = 'X';

        p.setPolozenie(Wektor<double,3>(tab));
        Wektor<double,3> www(tab);
        p.rysuj(api,a);

        while(1){
                double tab2[] = {0,0,0};
                znak = getch();
                switch (znak)
                {
                        case '1':tab2[0] = 1; break;
                        case '3':tab2[0] = -1; break;
                        case '5':tab2[1] = 1; break;
                        case '2':tab2[1] = -1; break;
                        case '4':tab2[2] = 1; break;
                        case '6':tab2[2] = -1; break;
                        case '7':p.odroc(Wektor<double,3>(obrX)); break;
                        case '8':p.odroc(Wektor<double,3>(obrY)); break;
                        case '9':p.odroc(Wektor<double,3>(obrZ)); break;
                }  
                p.usunKsztalt(api,a);
                p.przesun(tab2);
                p.rysuj(api,a);
        }


}

