#pragma once
#include "../lab1/OsLiczbowa.h"
class ZbiorOsi {
    OsLiczbowa* osie;
    int rozmiar;

public:
    // Konstruktory
    ZbiorOsi(int size);
    ZbiorOsi(int rozmiar, OsLiczbowa* osie);
    ZbiorOsi(const ZbiorOsi& other); // Konstruktor kopiuj¹cy
    ZbiorOsi(ZbiorOsi&& other) noexcept; // Konstruktor przenosz¹cy
    ~ZbiorOsi();
    OsLiczbowa* getOsie();
    int getSize();
    ZbiorOsi& operator=(const ZbiorOsi& other);
    ZbiorOsi& operator=(ZbiorOsi&& other);
    ZbiorOsi operator+(const OsLiczbowa& nowaOs);
    friend std::ostream& operator<<(std::ostream& os, const ZbiorOsi& zbior);
    ZbiorOsi& operator++();
    ZbiorOsi& operator++(int);
};