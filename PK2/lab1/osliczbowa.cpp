#include "OsLiczbowa.h"

// Konstruktor domy�lny
OsLiczbowa::OsLiczbowa() : min(0.0), max(10.0), interval(1.0) {
    std::cout << "OsLiczbowa - konstruktor domy�lny" << std::endl;
}

// Konstruktor dwuargumentowy
OsLiczbowa::OsLiczbowa(double min, double max) : min(min), max(max), interval((max - min) / 10.0) {
    std::cout << "OsLiczbowa - konstruktor dwuargumentowy" << std::endl;
}

// Konstruktor tr�jargumentowy
OsLiczbowa::OsLiczbowa(double min, double max, double interval) : min(min), max(max), interval(interval) {
    std::cout << "OsLiczbowa - konstruktor tr�jargumentowy" << std::endl;
}

// Konstruktor kopiuj�cy
OsLiczbowa::OsLiczbowa(const OsLiczbowa& other) : min(other.min), max(other.max), interval(other.interval) {
    std::cout << "OsLiczbowa - konstruktor kopiuj�cy" << std::endl;
}

// Konstruktor przenosz�cy
OsLiczbowa::OsLiczbowa(OsLiczbowa&& other) noexcept : min(std::move(other.min)), max(std::move(other.max)), interval(std::move(other.interval)) {
    std::cout << "OsLiczbowa - konstruktor przenosz�cy" << std::endl;
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

// Metody dost�pu
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

// Zaprzyja�niony operator strumieniowy <<
std::ostream& operator<<(std::ostream& os, const OsLiczbowa& obj) {
    os << "Min: " << obj.min << ", Max: " << obj.max << ", Interval: " << obj.interval;
    return os;
}
OsLiczbowa& OsLiczbowa::operator*=(double scale) {
    double center = (max + min) / 2.0; // Aktualny �rodek osi
    double newInterval = interval * scale; // Nowy interwa�

    // Nowe minimalne i maksymalne warto�ci osi
    double newMin = center - (center - min) * (interval / newInterval);
    double newMax = center + (max - center) * (interval / newInterval);

    // Aktualizacja warto�ci osi
    min = newMin;
    max = newMax;
    interval = newInterval;

    return *this;
}
OsLiczbowa& OsLiczbowa::operator/=(double scale) {
    // Skalowanie przez odwrotno��
    if (scale != 0.0) {
        *this *= 1.0 / scale;
    }
    else {
        // Obs�uga dzielenia przez zero
        std::cerr << "B��d: Dzielenie przez zero" << std::endl;
    }

    return *this;
}


