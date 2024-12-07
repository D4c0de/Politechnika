#include "ZbiorOsi.h"

ZbiorOsi::ZbiorOsi(int size) {
    rozmiar = size;
    osie = new OsLiczbowa[size];
}

ZbiorOsi::ZbiorOsi(const ZbiorOsi& other) {
    rozmiar = other.rozmiar;
    osie = new OsLiczbowa[rozmiar];
    for (int i = 0; i < rozmiar; ++i) {
        osie[i] = other.osie[i];
    }
}
ZbiorOsi::ZbiorOsi(ZbiorOsi&& other) noexcept {
    rozmiar = other.rozmiar;
    osie = other.osie;
    other.osie = nullptr;
}
ZbiorOsi::ZbiorOsi(int rozmiar, OsLiczbowa* osie) : rozmiar(rozmiar), osie(osie) {
}

ZbiorOsi::~ZbiorOsi() {
    if (osie != nullptr) {
        delete[] osie;
    }
}

OsLiczbowa* ZbiorOsi::getOsie() {
    return osie;
}

int ZbiorOsi::getSize() {
    return rozmiar;
}

ZbiorOsi& ZbiorOsi::operator=(const ZbiorOsi& other) {
    delete[] osie;
    rozmiar = other.rozmiar;
    osie = new OsLiczbowa[rozmiar];

    for (int i = 0; i < rozmiar; ++i) {
        osie[i] = other.osie[i];
    }
    std::cout << *this << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ZbiorOsi& zbior) {
    for (int i = 0; i < zbior.rozmiar; ++i) {
        os << "Os " << i + 1 << ": " << zbior.osie[i] << std::endl;
    }
    return os;
}
ZbiorOsi& ZbiorOsi::operator=(ZbiorOsi&& other) {
    delete[] osie;
    rozmiar = other.rozmiar;
    osie = other.osie;
    other.osie = nullptr;
    return *this;
}
ZbiorOsi ZbiorOsi::operator+(const OsLiczbowa& nowaOs) {
    // Tworzenie nowej tablicy z osiami (stara tablica + nowa oœ)
    OsLiczbowa* noweOsie = new OsLiczbowa[rozmiar + 1];
    for (int i = 0; i < rozmiar; ++i) {
        noweOsie[i] = osie[i]; // Kopiowanie istniej¹cych osi
    }
    noweOsie[rozmiar] = nowaOs; // Dodanie nowej osi

    // Zwolnienie pamiêci po starej tablicy osi
    delete[] osie;

    // Utworzenie nowego obiektu ZbiorOsi z now¹ tablic¹ osi
    ZbiorOsi nowyZbior(rozmiar + 1, noweOsie);

    return nowyZbior;
}

ZbiorOsi& ZbiorOsi::operator++() {
    rozmiar++;
    OsLiczbowa* noweOsie = new OsLiczbowa[rozmiar];
    return *this;
}
ZbiorOsi& ZbiorOsi::operator++(int) {
    ZbiorOsi tymczasowa(*this);
    rozmiar++;
    OsLiczbowa* noweOsie = new OsLiczbowa[rozmiar];
    return tymczasowa;

}