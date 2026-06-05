#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student{
private:
    int id;
    string name;
    float marks;
    string department;

public:
    Student();

    Student(int i, string n, float m, string d);

    int getId();
    string getName();
    float getMarks();
    string getDepartment();

    void setName(string n);
    void setMarks(float m);
    void setDepartment(string d);

    void display();
};