#include<iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Dron.hh"
#include "../inc/Wektor.hh"
#include "Prostopadloscian.hh"
#include "Plaszczyzna_Wody.hh"
#include "Graniastoslup.hh"

#include <unistd.h>
#include <termios.h>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


// char getch() {
//         char buf = 0;
//         struct termios old = {0};
//         if (tcgetattr(0, &old) < 0)
//                 perror("tcsetattr()");
//         old.c_lflag &= ~ICANON;
//         old.c_lflag &= ~ECHO;
//         old.c_cc[VMIN] = 1;
//         old.c_cc[VTIME] = 0;
//         if (tcsetattr(0, TCSANOW, &old) < 0)
//                 perror("tcsetattr ICANON");
//         if (read(0, &buf, 1) < 0)
//                 perror ("read()");
//         old.c_lflag |= ICANON;
//         old.c_lflag |= ECHO;
//         if (tcsetattr(0, TCSADRAIN, &old) < 0)
//                 perror ("tcsetattr ~ICANON");
//         return (buf);
// }

int main(int argc, char **argv)
{
        char c = 'x';
        double kat =0;;
        double r=0;

        //doxygen info
        //https://www.youtube.com/watch?v=KPN1y_vstjY


        std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-200,200,-200,200,-200,400,1000)); 
        api->change_ref_time_ms(0);
        
        Dron dron(api,Wektor<double,3>(50,80,20));
        dron.rysuj();

        Plaszczyzna_Wody woda(api,Wektor<double,3>(-300,-300,380));
        woda.rysuj();
        Plaszczyzna dno(api,Wektor<double,3>(-300,-300,-180));
        dno.rysuj();

        std::cout << "r - zadaj ruch na wprost\no - zadaj zmiane orientacji\nm - wyswietl menu\n\nk - koniec dzialania programu\n\n";

        while (c!='k')
        {
                std::cout << "\n>:" ;
                std::cin >> c;
                switch (c)
                {
                        case 'r':{
                                std::cout << "Podaj wartosc kata (wznoszenia/opadania) w stopniach.\n" ;
                                std::cin >> kat;
                                std::cout << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron.\n" ;
                                std::cin >> r;
                                std::cout<<kat<<"  "<<r;
                                dron.plyn(r,kat);
                                break;
                        }
                        case 'o':{
                                std::cout << "Podaj wartosc kata obrotu w stopniach.\n" ;
                                std::cin >> kat;
                                dron.obrot(OsZ,kat);
                                break;
                        }
                        case 'm':{
                                std::cout << "\n\nr - zadaj ruch na wprost\no - zadaj zmiane orientacji\nm - wyswietl menu\n\nk - koniec dzialania programu\n\n";
                                break;
                        }
                        case 'k':{
                                std::cout << "Koniec programu\n\n" ;
                                exit(1);
                                break;
                        }
                }
        }


}

