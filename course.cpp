// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <sstream>
// #include <limits>

// using namespace std;

// // ==================== Класс-сущность "Тур" ====================
// class Tour {
// private:
//     string country;         // страна
//     string cityOrRoute;     // город или маршрут круиза
//     string accommodation;   // условия проживания
//     string transport;       // условия проезда
//     string excursions;      // экскурсионное обслуживание
//     string service;         // сервис принимающей стороны
//     double price;           // стоимость путёвки

// public:
//     // Конструктор по умолчанию
//     Tour() : price(0.0) {}

//     // Конструктор с параметрами
//     Tour(const string& country, const string& cityOrRoute, const string& accommodation,
//          const string& transport, const string& excursions, const string& service, double price)
//         : country(country), cityOrRoute(cityOrRoute), accommodation(accommodation),
//           transport(transport), excursions(excursions), service(service), price(price) {}

//     // Геттеры
//     string getCountry() const { return country; }
//     string getCityOrRoute() const { return cityOrRoute; }
//     string getAccommodation() const { return accommodation; }
//     string getTransport() const { return transport; }
//     string getExcursions() const { return excursions; }
//     string getService() const { return service; }
//     double getPrice() const { return price; }

//     // Сеттеры
//     void setCountry(const string& c) { country = c; }
//     void setCityOrRoute(const string& c) { cityOrRoute = c; }
//     void setAccommodation(const string& a) { accommodation = a; }
//     void setTransport(const string& t) { transport = t; }
//     void setExcursions(const string& e) { excursions = e; }
//     void setService(const string& s) { service = s; }
//     void setPrice(double p) { price = p; }

//     // Вывод в консоль
//     string toString() const {
//         stringstream ss;
//         ss << "Страна: " << country << "\n"
//            << "Город/Маршрут: " << cityOrRoute << "\n"
//            << "Проживание: " << accommodation << "\n"
//            << "Проезд: " << transport << "\n"
//            << "Экскурсии: " << excursions << "\n"
//            << "Сервис: " << service << "\n"
//            << "Стоимость: " << price << " руб.\n";
//         return ss.str();
//     }

//     // Преобразование в строку для файла
//     string toFileString() const {
//         stringstream ss;
//         ss << country << ';' << cityOrRoute << ';' << accommodation << ';'
//            << transport << ';' << excursions << ';' << service << ';' << price;
//         return ss.str();
//     }

//     // Загрузка из строки файла
//     static Tour fromFileString(const string& line) {
//         stringstream ss(line);
//         string country, city, accom, transport, excurs, service, priceStr;
//         getline(ss, country, ';');
//         getline(ss, city, ';');
//         getline(ss, accom, ';');
//         getline(ss, transport, ';');
//         getline(ss, excurs, ';');
//         getline(ss, service, ';');
//         getline(ss, priceStr, ';');
//         double price = stod(priceStr);
//         return Tour(country, city, accom, transport, excurs, service, price);
//     }
// };

// // ==================== Класс-менеджер ====================
// class AgencyManager {
// private:
//     vector<Tour> tours;

// public:
//     void addTour(const Tour& tour) {
//         tours.push_back(tour);
//     }

//     bool removeTour(int index) {
//         if (index >= 0 && index < (int)tours.size()) {
//             tours.erase(tours.begin() + index);
//             return true;
//         }
//         return false;
//     }

//     Tour* getTour(int index) {
//         if (index >= 0 && index < (int)tours.size()) {
//             return &tours[index];
//         }
//         return nullptr;
//     }

//     int size() const { return tours.size(); }

//     vector<int> findByCountry(const string& country) const {
//         vector<int> indices;
//         for (int i = 0; i < (int)tours.size(); ++i) {
//             if (tours[i].getCountry() == country) {
//                 indices.push_back(i);
//             }
//         }
//         return indices;
//     }

//     bool saveToFile(const string& filename) const {
//         ofstream fout(filename);
//         if (!fout.is_open()) return false;
//         for (const Tour& t : tours) {
//             fout << t.toFileString() << "\n";
//         }
//         fout.close();
//         return true;
//     }

//     bool loadFromFile(const string& filename) {
//         ifstream fin(filename);
//         if (!fin.is_open()) return false;
//         tours.clear();
//         string line;
//         while (getline(fin, line)) {
//             if (!line.empty()) {
//                 tours.push_back(Tour::fromFileString(line));
//             }
//         }
//         fin.close();
//         return true;
//     }

//     void printAll() const {
//         if (tours.empty()) {
//             cout << "Список туров пуст.\n";
//             return;
//         }
//         for (int i = 0; i < (int)tours.size(); ++i) {
//             cout << "--- Тур #" << i + 1 << " ---\n";
//             cout << tours[i].toString();
//         }
//     }
// };

// // ==================== Класс интерфейса (меню) ====================
// class Menu {
// private:
//     AgencyManager manager;

//     // Вспомогательная функция для безопасного ввода числа
//     int readInt() {
//         int value;
//         while (!(cin >> value)) {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "Ошибка ввода. Введите число: ";
//         }
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         return value;
//     }

//     double readDouble() {
//         double value;
//         while (!(cin >> value)) {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "Ошибка ввода. Введите число: ";
//         }
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         return value;
//     }

// public:
//     void run() {
//         int choice;
//         do {
//             cout << "\n=== Справочник туриста ===\n";
//             cout << "1. Просмотреть все туры\n";
//             cout << "2. Добавить тур\n";
//             cout << "3. Редактировать тур\n";
//             cout << "4. Удалить тур\n";
//             cout << "5. Поиск по стране\n";
//             cout << "6. Сохранить в файл\n";
//             cout << "7. Загрузить из файла\n";
//             cout << "0. Выход\n";
//             cout << "Выберите действие: ";
//             choice = readInt();

//             switch (choice) {
//                 case 1: manager.printAll(); break;
//                 case 2: addTour(); break;
//                 case 3: editTour(); break;
//                 case 4: deleteTour(); break;
//                 case 5: searchByCountry(); break;
//                 case 6: saveToFile(); break;
//                 case 7: loadFromFile(); break;
//                 case 0: cout << "Выход.\n"; break;
//                 default: cout << "Неверный выбор. Попробуйте снова.\n";
//             }
//         } while (choice != 0);
//     }

// private:
//     void addTour() {
//         string country, city, accom, transport, excurs, service;
//         double price;
//         cout << "Введите страну: "; getline(cin, country);
//         cout << "Введите город или маршрут круиза: "; getline(cin, city);
//         cout << "Условия проживания: "; getline(cin, accom);
//         cout << "Условия проезда: "; getline(cin, transport);
//         cout << "Экскурсионное обслуживание: "; getline(cin, excurs);
//         cout << "Сервис принимающей стороны: "; getline(cin, service);
//         cout << "Стоимость путевки: "; price = readDouble();
//         manager.addTour(Tour(country, city, accom, transport, excurs, service, price));
//         cout << "Тур добавлен.\n";
//     }

//     void editTour() {
//         manager.printAll();
//         if (manager.size() == 0) return;
//         cout << "Введите номер тура для редактирования: ";
//         int idx = readInt();
//         Tour* tour = manager.getTour(idx - 1);
//         if (!tour) {
//             cout << "Неверный номер.\n";
//             return;
//         }
//         string country, city, accom, transport, excurs, service;
//         double price;
//         cout << "Введите новую страну (" << tour->getCountry() << "): ";
//         getline(cin, country);
//         if (country.empty()) country = tour->getCountry();
//         cout << "Новый город/маршрут (" << tour->getCityOrRoute() << "): ";
//         getline(cin, city);
//         if (city.empty()) city = tour->getCityOrRoute();
//         cout << "Проживание (" << tour->getAccommodation() << "): ";
//         getline(cin, accom);
//         if (accom.empty()) accom = tour->getAccommodation();
//         cout << "Проезд (" << tour->getTransport() << "): ";
//         getline(cin, transport);
//         if (transport.empty()) transport = tour->getTransport();
//         cout << "Экскурсии (" << tour->getExcursions() << "): ";
//         getline(cin, excurs);
//         if (excurs.empty()) excurs = tour->getExcursions();
//         cout << "Сервис (" << tour->getService() << "): ";
//         getline(cin, service);
//         if (service.empty()) service = tour->getService();
//         cout << "Стоимость (" << tour->getPrice() << "): ";
//         string priceStr;
//         getline(cin, priceStr);
//         if (!priceStr.empty()) {
//             try {
//                 price = stod(priceStr);
//             } catch (...) {
//                 cout << "Некорректная стоимость, оставлено старое значение.\n";
//                 price = tour->getPrice();
//             }
//         } else {
//             price = tour->getPrice();
//         }

//         tour->setCountry(country);
//         tour->setCityOrRoute(city);
//         tour->setAccommodation(accom);
//         tour->setTransport(transport);
//         tour->setExcursions(excurs);
//         tour->setService(service);
//         tour->setPrice(price);
//         cout << "Тур обновлён.\n";
//     }

//     void deleteTour() {
//         manager.printAll();
//         if (manager.size() == 0) return;
//         cout << "Введите номер тура для удаления: ";
//         int idx = readInt();
//         if (manager.removeTour(idx - 1)) {
//             cout << "Тур удалён.\n";
//         } else {
//             cout << "Неверный номер.\n";
//         }
//     }

//     void searchByCountry() {
//         cout << "Введите страну для поиска: ";
//         string country;
//         getline(cin, country);
//         vector<int> indices = manager.findByCountry(country);
//         if (indices.empty()) {
//             cout << "Туры в страну " << country << " не найдены.\n";
//         } else {
//             for (int idx : indices) {
//                 cout << "--- Тур #" << idx + 1 << " ---\n";
//                 cout << manager.getTour(idx)->toString();
//             }
//         }
//     }

//     void saveToFile() {
//         cout << "Введите имя файла для сохранения (например, tours.txt): ";
//         string filename;
//         getline(cin, filename);
//         if (manager.saveToFile(filename)) {
//             cout << "Сохранено.\n";
//         } else {
//             cout << "Ошибка сохранения.\n";
//         }
//     }

//     void loadFromFile() {
//         cout << "Введите имя файла для загрузки: ";
//         string filename;
//         getline(cin, filename);
//         if (manager.loadFromFile(filename)) {
//             cout << "Загружено.\n";
//         } else {
//             cout << "Ошибка загрузки.\n";
//         }
//     }
// };

// // ==================== Главный класс ====================
// int main() {
//     setlocale(LC_ALL, "Russian");
//     Menu menu;
//     menu.run();
//     return 0;
// }