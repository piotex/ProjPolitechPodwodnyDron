#include "../inc/LiczbaZespolona.hh"
#include "../src/MacierzKw.cpp"

template class MacierzKw<LiczbaZespolona,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, MacierzKw<LiczbaZespolona,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const MacierzKw<LiczbaZespolona,ROZMIAR> &W);

template class MacierzKw<double,ROZMIAR>;
template std::istream & operator>>(std::istream &strm, MacierzKw<double,ROZMIAR> &W);
template std::ostream & operator<< (std::ostream &strm, const MacierzKw<double,ROZMIAR> &W);