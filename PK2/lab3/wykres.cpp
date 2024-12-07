
#include "Wykres.h"
#include <cstring>

Wykres::Wykres(int rozmiar, const char* nazwa, TypWykresu typ) : ZbiorOsi(rozmiar) {
    size_t dlugosc = strlen(nazwa) + 1;
    nazwaWykresu = new char[dlugosc];
    strcpy_s(nazwaWykresu, dlugosc, nazwa);
}

Wykres::~Wykres() {
    delete[] nazwaWykresu;
}

Wykres& Wykres::operator=(Wykres& other) {
    if (this == &other) {
        return other;
    }
    ZbiorOsi::operator=(other);
    typWykresu = other.typWykresu;
    delete[] nazwaWykresu;
    if (other.nazwaWykresu != nullptr) {
        size_t length = strlen(other.nazwaWykresu) + 1;
        nazwaWykresu = new char[length];
        strcpy_s(nazwaWykresu, length, other.nazwaWykresu);
    }
    else {
        nazwaWykresu = nullptr;
    }

    return *this;
}



Wykres& Wykres::operator=(Wykres&& other) {
    if (this == &other) {
        return other;
    }
    ZbiorOsi(std::move(other));
    typWykresu = other.typWykresu;
    delete[]nazwaWykresu;
    nazwaWykresu = other.nazwaWykresu;
    other.nazwaWykresu = nullptr;

    return *this;
}

void Wykres::draw() {
    std::cout << "Nazwa wykresu: " << std::endl;
}


/*Column::Column(char* nazwa, int rozmiar) : Wykres(rozmiar, nazwa, TypWykresu::column), dodatkowyOpis(nullptr) {
    size_t dlugosc = strlen(nazwa) + 1;
    Wykres::nazwaWykresu = new char[dlugosc];
    strcpy_s(Wykres::nazwaWykresu, dlugosc, nazwa);

}*/
/*Column::Column(char* nazwa, int rozmiar, char* dodatkowyOpis) : Wykres(rozmiar, nazwa, TypWykresu::column) {
    dodatkowyOpis = new char[20];
    strcpy_s(dodatkowyOpis, 20, "Dodatkowy opis");

}
*/
Column::~Column() {
    delete[] dodatkowyOpis;
}

void Column::draw() {
    Wykres::draw();
    std::cout << "Dodatkowy opis: " << std::endl;
    std::cout << "Rysowanie kolumn" << std::endl;
}





Treemap::Treemap(char* nazwa, int rozmiar) : Wykres(rozmiar, nazwa, TypWykresu::treemap), dodatkowyOpis(nullptr) {
    size_t dlugosc = strlen(nazwa) + 1;
    Wykres::nazwaWykresu = new char[dlugosc];
    strcpy_s(Wykres::nazwaWykresu, dlugosc, nazwa);

}
Treemap::Treemap(char* nazwa, int rozmiar, char* dodatkowyOpis) : Wykres(rozmiar, nazwa, TypWykresu::treemap) {
    dodatkowyOpis = new char[20];
    strcpy_s(dodatkowyOpis, 20, "Dodatkowy opis");

}
Treemap::~Treemap() {
    delete[] dodatkowyOpis;
}

void Treemap::draw() {
    Wykres::draw();
    std::cout << "Dodatkowy opis: " << std::endl;
    std::cout << "Rysowanie drzewa" << std::endl;
}