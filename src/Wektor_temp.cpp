#include "Wektor.cpp"
#include "../inc/LiczbaZespolona.hh"

typedef double TYP;
typedef LiczbaZespolona TYP2;

template class Wektor<TYP,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, Wektor<TYP,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<TYP,ROZMIAR> &W);

template class Wektor<TYP2,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, Wektor<TYP2,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const Wektor<TYP2,ROZMIAR> &W);
