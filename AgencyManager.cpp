#include "AgencyManager.h"
#include <iostream>
#include <fstream>

void AgencyManager::addTour(const Tour& tour) {
    tours.push_back(tour);
}

bool AgencyManager::removeTour(int index) {
    if (index >= 0 && index < (int)tours.size()) {
        tours.erase(tours.begin() + index);
        return true;
    }
    return false;
}

Tour* AgencyManager::getTour(int index) {
    if (index >= 0 && index < (int)tours.size()) {
        return &tours[index];
    }
    return nullptr;
}

int AgencyManager::size() const {
    return tours.size();
}

vector<int> AgencyManager::findByCountry(const string& country) const {
    vector<int> indices;
    for (int i = 0; i < (int)tours.size(); ++i) {
        if (tours[i].getCountry() == country) {
            indices.push_back(i);
        }
    }
    return indices;
}

bool AgencyManager::saveToFile(const string& filename) const {
    ofstream fout(filename);
    if (!fout.is_open()) return false;
    for (const Tour& t : tours) {
        fout << t.toFileString() << "\n";
    }
    fout.close();
    return true;
}

bool AgencyManager::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;
    tours.clear();
    string line;
    while (getline(fin, line)) {
        if (!line.empty()) {
            tours.push_back(Tour::fromFileString(line));
        }
    }
    fin.close();
    return true;
}

void AgencyManager::printAll() const {
    if (tours.empty()) {
        cout << "Список туров пуст.\n";
        return;
    }
    for (int i = 0; i < (int)tours.size(); ++i) {
        cout << "--- Тур #" << i + 1 << " ---\n";
        cout << tours[i].toString();
    }
}