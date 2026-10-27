#ifndef MENU_H
#define MENU_H

#include "AgencyManager.h"

// Класс интерфейса (консольное меню)
class Menu {
private:
    AgencyManager manager;

    int readInt();
    double readDouble();

    void addTour();
    void editTour();
    void deleteTour();
    void searchByCountry();
    void saveToFile();
    void loadFromFile();

public:
    void run();
};

#endif