#ifndef TOUR_H
#define TOUR_H

#include <string>

using namespace std;

// Класс-сущность "Тур"
class Tour {
private:
    string country;         // страна
    string cityOrRoute;     // город или маршрут круиза
    string accommodation;   // условия проживания
    string transport;       // условия проезда
    string excursions;      // экскурсионное обслуживание
    string service;         // сервис принимающей стороны
    double price;           // стоимость путёвки

public:
    Tour();
    Tour(const string& country, const string& cityOrRoute, const string& accommodation,
         const string& transport, const string& excursions, const string& service, double price);

    // Геттеры
    string getCountry() const;
    string getCityOrRoute() const;
    string getAccommodation() const;
    string getTransport() const;
    string getExcursions() const;
    string getService() const;
    double getPrice() const;

    // Сеттеры
    void setCountry(const string& c);
    void setCityOrRoute(const string& c);
    void setAccommodation(const string& a);
    void setTransport(const string& t);
    void setExcursions(const string& e);
    void setService(const string& s);
    void setPrice(double p);

    // Вспомогательные методы
    string toString() const;
    string toFileString() const;
    static Tour fromFileString(const string& line);
};

#endif