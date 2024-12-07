#include "OsLiczbowa.h"

// Konstruktor domyúlny
OsLiczbowa::OsLiczbowa() : min(0.0), max(10.0), interval(1.0) {
    std::cout << "OsLiczbowa - konstruktor domyúlny" << std::endl;
}

// Konstruktor dwuargumentowy
OsLiczbowa::OsLiczbowa(double min, double max) : min(min), max(max), interval((max - min) / 10.0) {
    std::cout << "OsLiczbowa - konstruktor dwuargumentowy" << std::endl;
}

// Konstruktor trÛjargumentowy
OsLiczbowa::OsLiczbowa(double min, double max, double interval) : min(min), max(max), interval(interval) {
    std::cout << "OsLiczbowa - konstruktor trÛjargumentowy" << std::endl;
}

// Konstruktor kopiujπcy
OsLiczbowa::OsLiczbowa(const OsLiczbowa& other) : min(other.min), max(other.max), interval(other.interval) {
    std::cout << "OsLiczbowa - konstruktor kopiujπcy" << std::endl;
}

// Konstruktor przenoszπcy
OsLiczbowa::OsLiczbowa(OsLiczbowa&& other) noexcept : min(std::move(other.min)), max(std::move(other.max)), interval(std::move(other.interval)) {
    std::cout << "OsLiczbowa - konstruktor przenoszπcy" << std::endl;
}

// Destruktor
OsLiczbowa::~OsLiczbowa() {
    std::cout << "OsLiczbowa - destruktor" << std::endl;
}

// Operator przypisania
OsLiczbowa& OsLiczbowa::operator=(const OsLiczbowa& other) {
    std::cout << "OsLiczbowa - operator przypisania" << std::endl;
    if (this != &other) {
        min = other.min;
        max = other.max;
        interval = other.interval;
    }
    return *this;
}

// Metody dostÍpu
void OsLiczbowa::setMin(double min) {
    this->min = min;
}

void OsLiczbowa::setMax(double max) {
    this->max = max;
}

void OsLiczbowa::setInterval(double interval) {
    this->interval = interval;
}

double OsLiczbowa::getMin() const {
    return min;
}

double OsLiczbowa::getMax() const {
    return max;
}

double OsLiczbowa::getInterval() const {
    return interval;
}

// Zaprzyjaüniony operator strumieniowy <<
std::ostream& operator<<(std::ostream& os, const OsLiczbowa& obj) {
    os << "Min: " << obj.min << ", Max: " << obj.max << ", Interval: " << obj.interval;
    return os;
}
OsLiczbowa& OsLiczbowa::operator*=(double scale) {
    double center = (max + min) / 2.0; // Aktualny úrodek osi
    double newInterval = interval * scale; // Nowy interwa≥

    // Nowe minimalne i maksymalne wartoúci osi
    double newMin = center - (center - min) * (interval / newInterval);
    double newMax = center + (max - center) * (interval / newInterval);

    // Aktualizacja wartoúci osi
    min = newMin;
    max = newMax;
    interval = newInterval;

    return *this;
}
OsLiczbowa& OsLiczbowa::operator/=(double scale) {
    // Skalowanie przez odwrotnoúÊ
    if (scale != 0.0) {
        *this *= 1.0 / scale;
    }
    else {
        // Obs≥uga dzielenia przez zero
        std::cerr << "B≥πd: Dzielenie przez zero" << std::endl;
    }

    return *this;
}


