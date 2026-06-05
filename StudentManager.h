#include <vector>
#include <algorithm>
#include "Student.h"

class StudentManager{
private:
    vector<Student> students;

public:
    void addStudent();
    void searchStudent(int id);
    void deleteStudent(int id);
    void updateStudent(int id);
    void displayAll();

//sorting functions
    void sortByName();
    void sortByMarks();
    void sortById();

//utility function
    bool isEmpty();

    void handleChoice(int choice);

    void showMenu();
};