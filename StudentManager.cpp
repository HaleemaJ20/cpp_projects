#include "StudentManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

void StudentManager::addStudent(){
    int id;
    string name, department;
    float marks;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    if (id <= 0) {
        throw runtime_error("Invalid ID! Must be positive.");
    }

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            throw runtime_error("Duplicate ID not allowed!");
        }
    }

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    if (marks < 0 || marks > 100) {
        throw runtime_error("Invalid marks! Must be between 0 and 100.");
    }

    cout << "Enter Department: ";
    cin >> department;

    Student s(id, name, marks, department);
    students.push_back(s);
}

void StudentManager::searchStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students[i].display();
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManager::deleteStudent(int id){
    for(int i = 0; i < students.size(); i++){
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted. \n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManager::updateStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {

            string name, department;
            float marks;

            cout << "Enter new name: ";
            cin.ignore();  //flush buffer
            getline(cin, name);

            cout << "Enter new marks: ";
            cin >> marks;

            if (marks < 0 || marks > 100) {
                throw runtime_error("Invalid marks!");
            }

            cout << "Enter new department: ";
            cin >> department;

            students[i].setName(name);
            students[i].setMarks(marks);
            students[i].setDepartment(department);

            cout << "Student updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void StudentManager::displayAll() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

void StudentManager::sortByName() {
    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.getName() < b.getName();
        }
    );

    cout << "Sorted by name.\n";
}

void StudentManager::sortByMarks() {
    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.getMarks() > b.getMarks();
        }
    );

    cout << "Sorted by marks.\n";
}

void StudentManager::sortById() {
    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.getId() < b.getId();
        }
    );

    cout << "Sorted by ID.\n";
}

bool StudentManager::isEmpty(){
    return students.empty();
}

void StudentManager::handleChoice(int choice)
{
    int id;

    switch (choice)
    {
    case 1:
        addStudent();
        break;

    case 2:
        cout << "Enter ID: ";
        cin >> id;
        searchStudent(id);
        break;

    case 3:
        cout << "Enter ID: ";
        cin >> id;
        deleteStudent(id);
        break;

    case 4:
        cout << "Enter ID: ";
        cin >> id;
        updateStudent(id);
        break;

    case 5:
        displayAll();
        break;

    case 6:
        sortByMarks();
        break;

    case 7:
        sortByName();
        break;

    case 8:
        sortById();
        break;

    case 9:
        cout << "Exiting...\n";
        break;

    default:
        cout << "Invalid choice!\n";
    }
}

void StudentManager::showMenu() {
    cout << "\n===== STUDENT SYSTEM =====\n";
    cout << "1. Add Student\n";
    cout << "2. Search Student\n";
    cout << "3. Delete Student\n";
    cout << "4. Update Student\n";
    cout << "5. Display All\n";
    cout << "6. Sort by Marks\n";
    cout << "7. Sort by Name\n";
    cout << "8. Sort by ID\n";
    cout << "9. Exit\n";
    cout << "Enter choice: ";
}