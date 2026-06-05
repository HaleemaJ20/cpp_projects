#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int id;
    string name;
    float marks;
    string department;

public:
//Default Constructor
    Student();

//Parameterized Constructor
    Student(int i, string n, float m, string d);

//getters
    int getId();
    string getName();
    float getMarks();
    string getDepartment();

//setters
    void setName(string n);
    void setMarks(float m);
    void setDepartment(string d);

    void display();
};