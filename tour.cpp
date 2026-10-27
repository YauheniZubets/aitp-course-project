#include "Tour.h"
#include <sstream>

// Конструктор по умолчанию
Tour::Tour() : price(0.0) {}

// Конструктор с параметрами
Tour::Tour(const string& country, const string& cityOrRoute, const string& accommodation,
           const string& transport, const string& excursions, const string& service, double price)
    : country(country), cityOrRoute(cityOrRoute), accommodation(accommodation),
      transport(transport), excursions(excursions), service(service), price(price) {}

// Геттеры
string Tour::getCountry() const { return country; }
string Tour::getCityOrRoute() const { return cityOrRoute; }
string Tour::getAccommodation() const { return accommodation; }
string Tour::getTransport() const { return transport; }
string Tour::getExcursions() const { return excursions; }
string Tour::getService() const { return service; }
double Tour::getPrice() const { return price; }

// Сеттеры
void Tour::setCountry(const string& c) { country = c; }
void Tour::setCityOrRoute(const string& c) { cityOrRoute = c; }
void Tour::setAccommodation(const string& a) { accommodation = a; }
void Tour::setTransport(const string& t) { transport = t; }
void Tour::setExcursions(const string& e) { excursions = e; }
void Tour::setService(const string& s) { service = s; }
void Tour::setPrice(double p) { price = p; }

// Вывод в консоль
string Tour::toString() const {
    stringstream ss;
    ss << "Страна: " << country << "\n"
       << "Город/Маршрут: " << cityOrRoute << "\n"
       << "Проживание: " << accommodation << "\n"
       << "Проезд: " << transport << "\n"
       << "Экскурсии: " << excursions << "\n"
       << "Сервис: " << service << "\n"
       << "Стоимость: " << price << " руб.\n";
    return ss.str();
}

// Преобразование в строку для файла
string Tour::toFileString() const {
    stringstream ss;
    ss << country << ';' << cityOrRoute << ';' << accommodation << ';'
       << transport << ';' << excursions << ';' << service << ';' << price;
    return ss.str();
}

// Загрузка из строки файла
Tour Tour::fromFileString(const string& line) {
    stringstream ss(line);
    string country, city, accom, transport, excurs, service, priceStr;
    getline(ss, country, ';');
    getline(ss, city, ';');
    getline(ss, accom, ';');
    getline(ss, transport, ';');
    getline(ss, excurs, ';');
    getline(ss, service, ';');
    getline(ss, priceStr, ';');
    double price = stod(priceStr);
    return Tour(country, city, accom, transport, excurs, service, price);
}