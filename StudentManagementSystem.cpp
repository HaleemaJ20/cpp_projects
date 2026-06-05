#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
private:
    int id;
    string name;
    float marks;
    string department;

public:
//default constructor
    Student() {
        id = 0;
        name = "";
        marks = 0.0;
        department = "";
    }

//parameterized constructor
    Student(int i, string n, float m, string d){
        id = i;
        name = n;
        marks = m;
        department = d;
    }

//getters
    int getId() { return id; }

    string getName() { return name; }

    float getMarks() { return marks; }

    string getDepartment() { return department; }

//setters
    void setName(string n) { name = n; }

    void setMarks(float m) { marks = m; }

    void setDepartment(string d) { department = d; }

//display
    void display() {
        cout << left;
        cout << "--------------------------------------\n";
        cout << setw(10) << "ID" << ": " << id << endl;
        cout << setw(10) << "Name" << ": " << name << endl;
        cout << setw(10) << "Marks" << ": " << marks << endl;
        cout << setw(10) << "Dept" << ": " << department << endl;
        cout << "--------------------------------------\n";
    }
};

class StudentManager{
private:
    vector<Student> students;

public:
    void addStudent(){
        int id;
        string name, department;
        float marks;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); //flush buffer

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

    void searchStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students[i].display();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int id){
        for(int i = 0; i < students.size(); i++){
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted. \n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void updateStudent(int id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {

                string name, department;
                float marks;

                cout << "Enter new name: ";
                cin.ignore();     
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

    void displayAll() {
        if (students.empty()) {
            cout << "No students found.\n";
            return;
        }

        for (int i = 0; i < students.size(); i++) {
            students[i].display();
        }
    }

//Sort by name
    void sortByName() {
        sort(students.begin(), students.end(),
            [](Student a, Student b) {     //lambda function
                return a.getName() < b.getName();
            }
        );

        cout << "Sorted by name.\n";
    }

//Sort by marks
    void sortByMarks() {
        sort(students.begin(), students.end(),
            [](Student a, Student b) {   
                return a.getMarks() > b.getMarks();
            }
        );

        cout << "Sorted by marks.\n";
    }

//Sort by id
    void sortById() {
    sort(students.begin(), students.end(),
        [](Student a, Student b) {
            return a.getId() < b.getId();
        }
    );

    cout << "Sorted by ID.\n";
}

//Utility Function
    bool isEmpty(){
        return students.empty();
    }

    void handleChoice(int choice)
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

    void showMenu() {
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
};

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