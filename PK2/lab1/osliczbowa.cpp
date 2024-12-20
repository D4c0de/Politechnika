#include "OsLiczbowa.h"

// Konstruktor domyślny
OsLiczbowa::OsLiczbowa() : min(0.0), max(10.0), interval(1.0) {
    std::cout << "OsLiczbowa - konstruktor domyślny" << std::endl;
}

// Konstruktor dwuargumentowy
OsLiczbowa::OsLiczbowa(double min, double max) : min(min), max(max), interval((max - min) / 10.0) {
    std::cout << "OsLiczbowa - konstruktor dwuargumentowy" << std::endl;
}

// Konstruktor trójargumentowy
OsLiczbowa::OsLiczbowa(double min, double max, double interval) : min(min), max(max), interval(interval) {
    std::cout << "OsLiczbowa - konstruktor trójargumentowy" << std::endl;
}

// Konstruktor kopiujący
OsLiczbowa::OsLiczbowa(const OsLiczbowa& other) : min(other.min), max(other.max), interval(other.interval) {
    std::cout << "OsLiczbowa - konstruktor kopiujący" << std::endl;
}

// Konstruktor przenoszący
OsLiczbowa::OsLiczbowa(OsLiczbowa&& other) noexcept : min(std::move(other.min)), max(std::move(other.max)), interval(std::move(other.interval)) {
    std::cout << "OsLiczbowa - konstruktor przenoszący" << std::endl;
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

// Metody dostępu
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

// Zaprzyjaźniony operator strumieniowy <<
std::ostream& operator<<(std::ostream& os, const OsLiczbowa& obj) {
    os << "Min: " << obj.min << ", Max: " << obj.max << ", Interval: " << obj.interval;
    return os;
}
OsLiczbowa& OsLiczbowa::operator*=(double scale) {
    double center = (max + min) / 2.0; // Aktualny środek osi
    double newInterval = interval * scale; // Nowy interwał

    // Nowe minimalne i maksymalne wartości osi
    double newMin = center - (center - min) * (interval / newInterval);
    double newMax = center + (max - center) * (interval / newInterval);

    // Aktualizacja wartości osi
    min = newMin;
    max = newMax;
    interval = newInterval;

    return *this;
}
OsLiczbowa& OsLiczbowa::operator/=(double scale) {
    // Skalowanie przez odwrotność
    if (scale != 0.0) {
        *this *= 1.0 / scale;
    }
    else {
        // Obsługa dzielenia przez zero
        std::cerr << "Błąd: Dzielenie przez zero" << std::endl;
    }

    return *this;
}


