#include "Student.h"

Student::Student()
{
    id = 0;
    name = "";
    marks = 0.0;
    department = "";
}

Student::Student(int i, string n, float m, string d)
{
    id = i;
    name = n;
    marks = m;
    department = d;
}

int Student::getId() { return id; }

string Student::getName() { return name; }

float Student::getMarks() { return marks; }

string Student::getDepartment() { return department; }

void Student::setName(string n) { name = n; }

void Student::setMarks(float m) { marks = m; }

void Student::setDepartment(string d) { department = d; }

void Student::display(){
    cout << left;
    cout << "--------------------------------------\n";
    cout << setw(10) << "ID" << ": " << id << endl;
    cout << setw(10) << "Name" << ": " << name << endl;
    cout << setw(10) << "Marks" << ": " << marks << endl;
    cout << setw(10) << "Dept" << ": " << department << endl;
    cout << "--------------------------------------\n";
}