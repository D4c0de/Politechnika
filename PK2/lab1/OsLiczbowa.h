#pragma once
#include <iostream>


class OsLiczbowa {
private:
    double min;
    double max;
    double interval;

public:
    // Konstruktory
    OsLiczbowa();
    OsLiczbowa(double min, double max);
    OsLiczbowa(double min, double max, double interval);
    OsLiczbowa(const OsLiczbowa& other); // Konstruktor kopiuj¹cy
    OsLiczbowa(OsLiczbowa&& other) noexcept; // Konstruktor przenosz¹cy

    // Destruktor
    ~OsLiczbowa();

    // Operator przypisania
    OsLiczbowa& operator=(const OsLiczbowa& other);

    // Metody dostêpu
    void setMin(double min);
    void setMax(double max);
    void setInterval(double interval);
    double getMin() const;
    double getMax() const;
    double getInterval() const;

    OsLiczbowa& operator*=(double scale);
    OsLiczbowa& operator/=(double scale);

    friend std::ostream& operator<<(std::ostream& os, const OsLiczbowa& obj);
};