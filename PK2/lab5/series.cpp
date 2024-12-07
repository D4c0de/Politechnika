#include "Series.h"

Series::Series(int aLiczbaPunktow, char* aNazwa) {
    size_t dlugosc = strlen(aNazwa) + 1;
    nazwaWykresu = new char[dlugosc];
    strcpy_s(nazwaWykresu, dlugosc, aNazwa);

}

Series::Series() : Series(0, (char*)"BOB") {
}

std::ostream& operator<<(std::ostream out, const Series& seria) {
    out << seria.liczbaPunktow << " " << seria.nazwaWykresu << std::endl;
    return out;
}
