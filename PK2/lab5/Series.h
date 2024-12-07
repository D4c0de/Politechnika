#pragma once
#include <cstring>
#include <iostream>
class Series
{
protected:
    int liczbaPunktow;
    char* nazwaWykresu;
public:
    Series(int aLiczbaPunktow, char* aNazwa);
    Series();
    ~Series() {
        delete[] nazwaWykresu;
    }

    friend std::ostream& operator<<(std::ostream ser, const Series& nazwa);
};