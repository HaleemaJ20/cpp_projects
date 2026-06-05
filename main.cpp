#include <iostream>
#include <stdexcept>
#include "StudentManager.h"

using namespace std;

int main() {
    StudentManager sm;
    int choice;

    do {
        try {
            sm.showMenu();
            cin >> choice;
            sm.handleChoice(choice);
        }
        catch (runtime_error &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 9);

    return 0;
}