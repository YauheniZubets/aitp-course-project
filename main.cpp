#include <iostream>
#include <locale.h>
#include "Menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Menu menu;
    menu.run();
    return 0;
}