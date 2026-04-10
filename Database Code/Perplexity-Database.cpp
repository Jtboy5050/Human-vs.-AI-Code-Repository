// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Perplexity

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

// Basic data type for a student record.
struct Student {
    string name;
    int age;
    int id;
    string grade;
};

// Basic data type for a teacher record.
struct Teacher {
    string name;
    int age;
    string subject;
    int id;
};

vector<Student> students;
vector<Teacher> teachers;

// Clears the screen in a simple cross-platform way by printing blank lines.
// This avoids relying on system-specific commands.
void clearScreen() {
    for (int i = 0; i < 50; i++) {
        cout << '\n';
    }
}

// Pauses so the user can read output before returning to the menu.
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Reads a full line of text safely.
string getLine(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin >> ws, value);
    return value;
}

// Reads an integer safely.
int getInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

void addStudent() {
    Student s;
    s.name = getLine("Enter student name: ");
    s.age = getInt("Enter student age: ");
    s.id = getInt("Enter student ID: ");
    s.grade = getLine("Enter student grade: ");

    students.push_back(s);
    cout << "\nStudent added successfully.\n";
    waitForEnter();
}

void addTeacher() {
    Teacher t;
    t.name = getLine("Enter teacher name: ");
    t.age = getInt("Enter teacher age: ");
    t.subject = getLine("Enter subject taught: ");
    t.id = getInt("Enter teacher ID: ");

    teachers.push_back(t);
    cout << "\nTeacher added successfully.\n";
    waitForEnter();
}

void displayAllEntries() {
    cout << "===== TEACHERS =====\n";
    if (teachers.empty()) {
        cout << "No teachers stored.\n";
    }
    else {
        for (size_t i = 0; i < teachers.size(); i++) {
            cout << i + 1 << ". Name: " << teachers[i].name
                << ", Age: " << teachers[i].age
                << ", Subject: " << teachers[i].subject
                << ", ID: " << teachers[i].id << '\n';
        }
    }

    cout << "\n===== STUDENTS =====\n";
    if (students.empty()) {
        cout << "No students stored.\n";
    }
    else {
        for (size_t i = 0; i < students.size(); i++) {
            cout << i + 1 << ". Name: " << students[i].name
                << ", Age: " << students[i].age
                << ", ID: " << students[i].id
                << ", Grade: " << students[i].grade << '\n';
        }
    }

    waitForEnter();
}

void deleteEntry() {
    cout << "Delete from:\n";
    cout << "1. Students\n";
    cout << "2. Teachers\n";

    int type = getInt("Choose an option: ");

    if (type == 1) {
        if (students.empty()) {
            cout << "\nNo students to delete.\n";
            waitForEnter();
            return;
        }

        displayAllEntries();
        int id = getInt("Enter the student ID to delete: ");

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "\nStudent deleted successfully.\n";
                waitForEnter();
                return;
            }
        }

        cout << "\nStudent ID not found.\n";
        waitForEnter();
    }
    else if (type == 2) {
        if (teachers.empty()) {
            cout << "\nNo teachers to delete.\n";
            waitForEnter();
            return;
        }

        displayAllEntries();
        int id = getInt("Enter the teacher ID to delete: ");

        for (auto it = teachers.begin(); it != teachers.end(); ++it) {
            if (it->id == id) {
                teachers.erase(it);
                cout << "\nTeacher deleted successfully.\n";
                waitForEnter();
                return;
            }
        }

        cout << "\nTeacher ID not found.\n";
        waitForEnter();
    }
    else {
        cout << "\nInvalid choice.\n";
        waitForEnter();
    }
}

void showMenu() {
    cout << "=============================\n";
    cout << "   SCHOOL DATABASE PROGRAM   \n";
    cout << "=============================\n";
    cout << "1. See all entries\n";
    cout << "2. Add a student\n";
    cout << "3. Add a teacher\n";
    cout << "4. Delete an entry\n";
    cout << "5. Exit\n";
    cout << "=============================\n";
}

int main() {
    int choice;

    while (true) {
        clearScreen();
        showMenu();
        choice = getInt("Enter your choice: ");

        clearScreen();

        switch (choice) {
        case 1:
            displayAllEntries();
            break;
        case 2:
            addStudent();
            break;
        case 3:
            addTeacher();
            break;
        case 4:
            deleteEntry();
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
            waitForEnter();
        }
    }

    return 0;
}