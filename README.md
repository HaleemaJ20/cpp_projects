# Student Management System (C++ OOP Project)

## Overview
This is a console-based Student Management System built using C++ and Object-Oriented Programming principles. 
The project demonstrates CRUD operations, sorting algorithms, exception handling, and use of STL (vectors and algorithms).

## Features
- Add new students
- Search student by ID
- Update student details
- Delete student records
- Display all students
- Sort students by:
  - ID
  - Name (alphabetically)
  - Marks
- Exception handling for invalid input (ID, marks)
- Uses STL vector for dynamic storage
- Menu-driven interface

## Concepts Used
- Object-Oriented Programming (Classes & Objects)
- Constructors (Default & Parameterized)
- Encapsulation (Getters & Setters)
- STL (vector, algorithm)
- Sorting using lambda functions
- Exception handling (runtime_error)
- Menu-driven programming

## Project Structure
- Student.h → Student class declaration  
- Student.cpp → Student class implementation  
- StudentManager.h → System operations declaration  
- StudentManager.cpp → Logic implementation (CRUD + sorting)  
- main.cpp → Program entry point and menu system  

## How to Run
g++ main.cpp Student.cpp StudentManager.cpp -o app
