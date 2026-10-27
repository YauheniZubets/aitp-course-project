#ifndef AGENCYMANAGER_H
#define AGENCYMANAGER_H

#include <vector>
#include <string>
#include "Tour.h"

using namespace std;

// Класс-менеджер (бизнес-логика)
class AgencyManager {
private:
    vector<Tour> tours;

public:
    void addTour(const Tour& tour);
    bool removeTour(int index);
    Tour* getTour(int index);
    int size() const;
    vector<int> findByCountry(const string& country) const;

    bool saveToFile(const string& filename) const;
    bool loadFromFile(const string& filename);

    void printAll() const;
};

#endif