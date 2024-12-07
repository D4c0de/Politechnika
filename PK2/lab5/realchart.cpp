#include "RealChart.h"
#include "../lab3/Wykres.h"
#include "Series.h"

RealChart::RealChart(int rozmiar, int liczbaPunktow, char* nazwa) : 
    Column(rozmiar, nazwa), Series(liczbaPunktow, nazwa) {
    this->Column::nazwaWykresu = nazwa;
}

RealChart::RealChart() : 
    RealChart(5, 8, (char*)"ROB") {}

std::ostream& operator<<(std::ostream& out, const RealChart& chart) {
    out << chart;
    return out;
}