// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: ChatGPT

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// -------------------- CLASS DEFINITIONS --------------------

class Student {
public:
    string name;
    int age;
    int id;
    string grade;
};

class Teacher {
public:
    string name;
    int age;
    int id;
    string subject;
};

// -------------------- FUNCTION DECLARATIONS --------------------

void clearScreen();
void pause();

void showMenu();
void displayAll(Student* students, int sCount, Teacher* teachers, int tCount);

void addStudent(Student*& students, int& sCount);
void addTeacher(Teacher*& teachers, int& tCount);

void deleteEntry(Student*& students, int& sCount, Teacher*& teachers, int& tCount);

// -------------------- MAIN --------------------

int main() {
    Student* students = nullptr;
    Teacher* teachers = nullptr;

    int sCount = 0;
    int tCount = 0;

    int choice;

    do {
        clearScreen();
        showMenu();

        cin >> choice;

        // Input validation guard
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            clearScreen();
            displayAll(students, sCount, teachers, tCount);
            pause();
            break;

        case 2:
            clearScreen();
            addStudent(students, sCount);
            pause();
            break;

        case 3:
            clearScreen();
            addTeacher(teachers, tCount);
            pause();
            break;

        case 4:
            clearScreen();
            deleteEntry(students, sCount, teachers, tCount);
            pause();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
            pause();
        }

    } while (choice != 5);

    // Clean up dynamic memory before exit
    delete[] students;
    delete[] teachers;

    return 0;
}

// -------------------- FUNCTION DEFINITIONS --------------------

// Clears console screen (Windows-compatible)
void clearScreen() {
    system("cls"); // If on Mac/Linux, use "clear"
}

// Simple pause so user can read output
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// Displays main menu
void showMenu() {
    cout << "===== DATABASE MENU =====\n";
    cout << "1. See all entries\n";
    cout << "2. Add Student\n";
    cout << "3. Add Teacher\n";
    cout << "4. Delete Entry\n";
    cout << "5. Exit\n";
    cout << "Choose: ";
}

// Display all students and teachers
void displayAll(Student* students, int sCount, Teacher* teachers, int tCount) {
    cout << "----- STUDENTS -----\n";
    if (sCount == 0) {
        cout << "No students available.\n";
    }
    else {
        for (int i = 0; i < sCount; i++) {
            cout << i << ") Name: " << students[i].name
                << ", Age: " << students[i].age
                << ", ID: " << students[i].id
                << ", Grade: " << students[i].grade << endl;
        }
    }

    cout << "\n----- TEACHERS -----\n";
    if (tCount == 0) {
        cout << "No teachers available.\n";
    }
    else {
        for (int i = 0; i < tCount; i++) {
            cout << i << ") Name: " << teachers[i].name
                << ", Age: " << teachers[i].age
                << ", ID: " << teachers[i].id
                << ", Subject: " << teachers[i].subject << endl;
        }
    }
}

// Adds a student by resizing the dynamic array
void addStudent(Student*& students, int& sCount) {
    Student* temp = new Student[sCount + 1];

    // Copy existing data
    for (int i = 0; i < sCount; i++) {
        temp[i] = students[i];
    }

    // Input new student
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, temp[sCount].name);

    cout << "Enter age: ";
    cin >> temp[sCount].age;

    cout << "Enter ID: ";
    cin >> temp[sCount].id;

    cout << "Enter grade: ";
    cin >> temp[sCount].grade;

    // Replace old array
    delete[] students;
    students = temp;
    sCount++;

    cout << "Student added successfully.\n";
}

// Adds a teacher by resizing the dynamic array
void addTeacher(Teacher*& teachers, int& tCount) {
    Teacher* temp = new Teacher[tCount + 1];

    for (int i = 0; i < tCount; i++) {
        temp[i] = teachers[i];
    }

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, temp[tCount].name);

    cout << "Enter age: ";
    cin >> temp[tCount].age;

    cout << "Enter ID: ";
    cin >> temp[tCount].id;

    cout << "Enter subject: ";
    cin.ignore();
    getline(cin, temp[tCount].subject);

    delete[] teachers;
    teachers = temp;
    tCount++;

    cout << "Teacher added successfully.\n";
}

// Deletes either a student or teacher entry
void deleteEntry(Student*& students, int& sCount, Teacher*& teachers, int& tCount) {
    int type;
    cout << "Delete from:\n1. Students\n2. Teachers\nChoice: ";
    cin >> type;

    if (type == 1 && sCount > 0) {
        int index;
        cout << "Enter student index to delete: ";
        cin >> index;

        if (index < 0 || index >= sCount) {
            cout << "Invalid index.\n";
            return;
        }

        Student* temp = new Student[sCount - 1];

        for (int i = 0, j = 0; i < sCount; i++) {
            if (i != index) {
                temp[j++] = students[i];
            }
        }

        delete[] students;
        students = temp;
        sCount--;

        cout << "Student deleted.\n";
    }
    else if (type == 2 && tCount > 0) {
        int index;
        cout << "Enter teacher index to delete: ";
        cin >> index;

        if (index < 0 || index >= tCount) {
            cout << "Invalid index.\n";
            return;
        }

        Teacher* temp = new Teacher[tCount - 1];

        for (int i = 0, j = 0; i < tCount; i++) {
            if (i != index) {
                temp[j++] = teachers[i];
            }
        }

        delete[] teachers;
        teachers = temp;
        tCount--;

        cout << "Teacher deleted.\n";
    }
    else {
        cout << "No entries available to delete.\n";
    }
}