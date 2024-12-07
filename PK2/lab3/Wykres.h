#pragma once
#include "../lab2/ZbiorOsi.h"
#include <cstring>

enum TypWykresu {
    XY,
    column,
    Sunburst,
    treemap
};

class Wykres : public ZbiorOsi {
protected:
    char* nazwaWykresu;
    TypWykresu typWykresu;
public:
    const char* getNazwa() const { return nazwaWykresu; }
    Wykres(int rozmiar, const char* nazwa, TypWykresu typ);
    Wykres() : Wykres(10, "Domyœlny Wykres", TypWykresu::XY) {}

    Wykres(const Wykres& other) : ZbiorOsi(other) {
        if (other.nazwaWykresu != nullptr) {
            size_t dlugosc = strlen(other.nazwaWykresu) + 1;
            nazwaWykresu = new char[dlugosc];
            strcpy_s(nazwaWykresu, dlugosc, other.nazwaWykresu);
        }
        else {
            nazwaWykresu = nullptr;
        }
    }
    Wykres(Wykres&& other) : ZbiorOsi(std::move(other)) {
        nazwaWykresu = other.nazwaWykresu;
        other.nazwaWykresu = nullptr;
    }

    ~Wykres();
    Wykres& operator=(Wykres& other);
    Wykres& operator=(Wykres&& other);
    friend std::ostream& operator<<(std::ostream& os, const Wykres& wykres) { // dopytac o dostep do nazy wykresu
        os << "Nazwa wykresu: ";
        if (wykres.nazwaWykresu != nullptr) {
            os << wykres.nazwaWykresu;
        }
        else {
            os << "Brak nazwy";
        }
        os << ", Typ wykresu: ";

        switch (wykres.typWykresu) {
        case TypWykresu::XY:
            os << "XY";
            break;
        case TypWykresu::column:
            os << "Column";
            break;
        case TypWykresu::Sunburst:
            os << "Sunburst";
            break;
        case TypWykresu::treemap:
            os << "Treemap";
            break;
        }
        os << static_cast<const ZbiorOsi&>(wykres);
        return os;
    }
    virtual void draw();
};


class Column : public Wykres {
    char* dodatkowyOpis;
public:

    Column(int rozmiar, char* nazwa) : Wykres(rozmiar, nazwa, TypWykresu::column), dodatkowyOpis(nullptr) {
        size_t dlugosc = strlen(nazwa) + 1;
        Wykres::nazwaWykresu = new char[dlugosc];
        strcpy_s(Wykres::nazwaWykresu, dlugosc, nazwa);
    };
    Column(char* nazwa, int rozmiar, char* opis) : Wykres(rozmiar, nazwa, TypWykresu::column) {
        dodatkowyOpis = new char[20];
        strcpy_s(dodatkowyOpis, 20, "Dodatkowy opis");
    };
    ~Column();
    void draw() override;
    const char* getNazwa() const { return nazwaWykresu; }
};
class Treemap : public Wykres {
    char* dodatkowyOpis;
public:
    Treemap(char* nazwa, int rozmiar);
    Treemap(char* nazwa, int rozmiar, char* opis);
    ~Treemap();
    void draw()  override;
    const char* getNazwa() const { return nazwaWykresu; }
};
