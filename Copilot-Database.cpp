// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: CoPilot

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;

// -----------------------------
// Structs for Students/Teachers
// -----------------------------
struct Student {
    string name;
    int age;
    int id;
    char grade;
};

struct Teacher {
    string name;
    int age;
    string subject;
    int id;
};

// -----------------------------
// Function Prototypes
// -----------------------------
void showMenu();
void addStudent(vector<Student>& students);
void addTeacher(vector<Teacher>& teachers);
void showAll(const vector<Student>& students, const vector<Teacher>& teachers);
void deleteEntry(vector<Student>& students, vector<Teacher>& teachers);

// Utility to pause before clearing screen
void pauseAndClear() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system(CLEAR);
}

// -----------------------------
// Main Program
// -----------------------------
int main() {
    vector<Student> students;
    vector<Teacher> teachers;

    int choice = 0;

    while (choice != 5) {
        showMenu();
        cin >> choice;

        // Clear leftover newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            showAll(students, teachers);
            pauseAndClear();
            break;
        case 2:
            addStudent(students);
            pauseAndClear();
            break;
        case 3:
            addTeacher(teachers);
            pauseAndClear();
            break;
        case 4:
            deleteEntry(students, teachers);
            pauseAndClear();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
            pauseAndClear();
        }
    }

    return 0;
}

// -----------------------------
// Menu Display
// -----------------------------
void showMenu() {
    system(CLEAR);
    cout << "===== SCHOOL DATABASE =====\n";
    cout << "1. See all entries\n";
    cout << "2. Add a student\n";
    cout << "3. Add a teacher\n";
    cout << "4. Delete an entry\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

// -----------------------------
// Add Student
// -----------------------------
void addStudent(vector<Student>& students) {
    Student s;

    cout << "Enter student name: ";
    getline(cin, s.name);

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter ID: ";
    cin >> s.id;

    cout << "Enter grade (A-F): ";
    cin >> s.grade;

    students.push_back(s);

    cout << "\nStudent added successfully.\n";
}

// -----------------------------
// Add Teacher
// -----------------------------
void addTeacher(vector<Teacher>& teachers) {
    Teacher t;

    cout << "Enter teacher name: ";
    getline(cin, t.name);

    cout << "Enter age: ";
    cin >> t.age;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline

    cout << "Enter subject: ";
    getline(cin, t.subject);

    cout << "Enter ID: ";
    cin >> t.id;

    teachers.push_back(t);

    cout << "\nTeacher added successfully.\n";
}

// -----------------------------
// Show All Entries
// -----------------------------
void showAll(const vector<Student>& students, const vector<Teacher>& teachers) {
    cout << "===== STUDENTS =====\n";
    if (students.empty()) {
        cout << "No students in database.\n";
    }
    else {
        for (const auto& s : students) {
            cout << "Name: " << s.name
                << ", Age: " << s.age
                << ", ID: " << s.id
                << ", Grade: " << s.grade << "\n";
        }
    }

    cout << "\n===== TEACHERS =====\n";
    if (teachers.empty()) {
        cout << "No teachers in database.\n";
    }
    else {
        for (const auto& t : teachers) {
            cout << "Name: " << t.name
                << ", Age: " << t.age
                << ", Subject: " << t.subject
                << ", ID: " << t.id << "\n";
        }
    }
}

// -----------------------------
// Delete Entry (by ID)
// -----------------------------
void deleteEntry(vector<Student>& students, vector<Teacher>& teachers) {
    int id;
    cout << "Enter the ID of the entry to delete: ";
    cin >> id;

    // Try deleting a student first
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted.\n";
            return;
        }
    }

    // Try deleting a teacher
    for (size_t i = 0; i < teachers.size(); i++) {
        if (teachers[i].id == id) {
            teachers.erase(teachers.begin() + i);
            cout << "Teacher deleted.\n";
            return;
        }
    }

    cout << "No entry found with that ID.\n";
}
