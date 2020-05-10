CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: workingFile

	./workingFile

workingFile: obj/main.o obj/LiczbaZespolona.o obj/Dron.o obj/Dr3D_gnuplot_api.o obj/Prostopadloscian.o obj/MacierzObrotu.o obj/Wektor.o obj/MacierzKw.o 
	g++ -Wall -pedantic -o workingFile obj/*.o  -lpthread 

obj/main.o: src/main.cpp inc/LiczbaZespolona.hh inc/Dron.hh inc/Dr3D_gnuplot_api.hh inc/Prostopadloscian.hh inc/MacierzObrotu.hh  inc/Wektor.hh inc/MacierzKw.hh 
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp	

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

inc/Prostopadloscian.hh: inc/Figura3D.hh
	touch inc/Prostopadloscian.hh

obj/LiczbaZespolona.o: src/LiczbaZespolona.cpp inc/LiczbaZespolona.hh 
	g++ ${CPPFLAGS} -o obj/LiczbaZespolona.o src/LiczbaZespolona.cpp

obj/MacierzObrotu.o: src/MacierzObrotu.cpp inc/MacierzObrotu.hh 
	g++ ${CPPFLAGS} -o obj/MacierzObrotu.o src/MacierzObrotu.cpp

obj/MacierzKw.o: src/MacierzKw.cpp inc/MacierzKw.hh src/MacierzKw_temp.cpp
	g++ ${CPPFLAGS} -o obj/MacierzKw.o src/MacierzKw_temp.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh src/Wektor_temp.cpp
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor_temp.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh 
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

obj/Dron.o: src/Dron.cpp inc/Dron.hh 
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

clean:
	rm -f obj/*.o workingFile