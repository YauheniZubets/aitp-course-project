#include "Menu.h"
#include <iostream>
#include <limits>

int Menu::readInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Введите число: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

double Menu::readDouble() {
    double value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Введите число: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

void Menu::run() {
    int choice;
    do {
        cout << "\n=== Справочник туриста ===\n";
        cout << "1. Просмотреть все туры\n";
        cout << "2. Добавить тур\n";
        cout << "3. Редактировать тур\n";
        cout << "4. Удалить тур\n";
        cout << "5. Поиск по стране\n";
        cout << "6. Сохранить в файл\n";
        cout << "7. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        choice = readInt();

        switch (choice) {
            case 1: manager.printAll(); break;
            case 2: addTour(); break;
            case 3: editTour(); break;
            case 4: deleteTour(); break;
            case 5: searchByCountry(); break;
            case 6: saveToFile(); break;
            case 7: loadFromFile(); break;
            case 0: cout << "Выход.\n"; break;
            default: cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

void Menu::addTour() {
    string country, city, accom, transport, excurs, service;
    double price;
    cout << "Введите страну: "; getline(cin, country);
    cout << "Введите город или маршрут круиза: "; getline(cin, city);
    cout << "Условия проживания: "; getline(cin, accom);
    cout << "Условия проезда: "; getline(cin, transport);
    cout << "Экскурсионное обслуживание: "; getline(cin, excurs);
    cout << "Сервис принимающей стороны: "; getline(cin, service);
    cout << "Стоимость путевки: "; price = readDouble();
    manager.addTour(Tour(country, city, accom, transport, excurs, service, price));
    cout << "Тур добавлен.\n";
}

void Menu::editTour() {
    manager.printAll();
    if (manager.size() == 0) return;
    cout << "Введите номер тура для редактирования: ";
    int idx = readInt();
    Tour* tour = manager.getTour(idx - 1);
    if (!tour) {
        cout << "Неверный номер.\n";
        return;
    }
    string country, city, accom, transport, excurs, service;
    double price;
    cout << "Введите новую страну (" << tour->getCountry() << "): ";
    getline(cin, country);
    if (country.empty()) country = tour->getCountry();
    cout << "Новый город/маршрут (" << tour->getCityOrRoute() << "): ";
    getline(cin, city);
    if (city.empty()) city = tour->getCityOrRoute();
    cout << "Проживание (" << tour->getAccommodation() << "): ";
    getline(cin, accom);
    if (accom.empty()) accom = tour->getAccommodation();
    cout << "Проезд (" << tour->getTransport() << "): ";
    getline(cin, transport);
    if (transport.empty()) transport = tour->getTransport();
    cout << "Экскурсии (" << tour->getExcursions() << "): ";
    getline(cin, excurs);
    if (excurs.empty()) excurs = tour->getExcursions();
    cout << "Сервис (" << tour->getService() << "): ";
    getline(cin, service);
    if (service.empty()) service = tour->getService();
    cout << "Стоимость (" << tour->getPrice() << "): ";
    string priceStr;
    getline(cin, priceStr);
    if (!priceStr.empty()) {
        try {
            price = stod(priceStr);
        } catch (...) {
            cout << "Некорректная стоимость, оставлено старое значение.\n";
            price = tour->getPrice();
        }
    } else {
        price = tour->getPrice();
    }

    tour->setCountry(country);
    tour->setCityOrRoute(city);
    tour->setAccommodation(accom);
    tour->setTransport(transport);
    tour->setExcursions(excurs);
    tour->setService(service);
    tour->setPrice(price);
    cout << "Тур обновлён.\n";
}

void Menu::deleteTour() {
    manager.printAll();
    if (manager.size() == 0) return;
    cout << "Введите номер тура для удаления: ";
    int idx = readInt();
    if (manager.removeTour(idx - 1)) {
        cout << "Тур удалён.\n";
    } else {
        cout << "Неверный номер.\n";
    }
}

void Menu::searchByCountry() {
    cout << "Введите страну для поиска: ";
    string country;
    getline(cin, country);
    vector<int> indices = manager.findByCountry(country);
    if (indices.empty()) {
        cout << "Туры в страну " << country << " не найдены.\n";
    } else {
        for (int idx : indices) {
            cout << "--- Тур #" << idx + 1 << " ---\n";
            cout << manager.getTour(idx)->toString();
        }
    }
}

void Menu::saveToFile() {
    cout << "Введите имя файла для сохранения (например, tours.txt): ";
    string filename;
    getline(cin, filename);
    if (manager.saveToFile(filename)) {
        cout << "Сохранено.\n";
    } else {
        cout << "Ошибка сохранения.\n";
    }
}

void Menu::loadFromFile() {
    cout << "Введите имя файла для загрузки: ";
    string filename;
    getline(cin, filename);
    if (manager.loadFromFile(filename)) {
        cout << "Загружено.\n";
    } else {
        cout << "Ошибка загрузки.\n";
    }
}