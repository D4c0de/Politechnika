#pragma once
#include "../lab3/Wykres.h"
#include "Series.h"
class RealChart : public Column, public Series {

    RealChart(int rozmiar, int liczbaPunktow, char* nazwa);
    RealChart();
    ~RealChart();
    const char* getNazwaColumn() const { return Column::nazwaWykresu; }
    const char* getNazwaSeries() const { return Series::nazwaWykresu; }

};