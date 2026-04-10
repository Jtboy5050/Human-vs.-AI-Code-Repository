// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Grok

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>  // For system() calls in clearScreen()

// Struct for Teacher: stores name, age, subject taught, and unique ID (int for simplicity)
struct Teacher {
    std::string name;
    int age;
    std::string subject;
    int id;
};

// Struct for Student: stores name, age, ID, and grade (int representing e.g. average score or grade level)
struct Student {
    std::string name;
    int age;
    int id;
    int grade;
};

// Clears the console screen for a clean menu each time (cross-platform using preprocessor)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Displays the main menu options
void displayMenu() {
    std::cout << "=== Simple School Database ===\n";
    std::cout << "1. See all entries\n";
    std::cout << "2. Add to students\n";
    std::cout << "3. Add to teachers\n";
    std::cout << "4. Delete an entry\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

// Displays all teachers and students in a readable format
void displayAll(const std::vector<Teacher>& teachers, const std::vector<Student>& students) {
    std::cout << "\n=== Teachers ===\n";
    if (teachers.empty()) {
        std::cout << "No teachers in the database.\n";
    }
    else {
        for (const auto& t : teachers) {
            std::cout << "ID: " << t.id
                << " | Name: " << t.name
                << " | Age: " << t.age
                << " | Subject: " << t.subject << "\n";
        }
    }

    std::cout << "\n=== Students ===\n";
    if (students.empty()) {
        std::cout << "No students in the database.\n";
    }
    else {
        for (const auto& s : students) {
            std::cout << "ID: " << s.id
                << " | Name: " << s.name
                << " | Age: " << s.age
                << " | Grade: " << s.grade << "\n";
        }
    }
}

// Adds a new student using getline + stoi for safe input handling (supports names with spaces)
void addStudent(std::vector<Student>& students) {
    Student s;
    std::string input;

    std::cout << "\n--- Add Student ---\n";
    std::cout << "Enter name: ";
    std::getline(std::cin, s.name);

    std::cout << "Enter age: ";
    std::getline(std::cin, input);
    s.age = std::stoi(input);

    std::cout << "Enter ID: ";
    std::getline(std::cin, input);
    s.id = std::stoi(input);

    std::cout << "Enter grade (e.g. 85): ";
    std::getline(std::cin, input);
    s.grade = std::stoi(input);

    students.push_back(s);
    std::cout << "Student added successfully!\n";
}

// Adds a new teacher using the same safe input method
void addTeacher(std::vector<Teacher>& teachers) {
    Teacher t;
    std::string input;

    std::cout << "\n--- Add Teacher ---\n";
    std::cout << "Enter name: ";
    std::getline(std::cin, t.name);

    std::cout << "Enter age: ";
    std::getline(std::cin, input);
    t.age = std::stoi(input);

    std::cout << "Enter subject: ";
    std::getline(std::cin, t.subject);

    std::cout << "Enter ID: ";
    std::getline(std::cin, input);
    t.id = std::stoi(input);

    teachers.push_back(t);
    std::cout << "Teacher added successfully!\n";
}

// Deletes an entry by asking for type (teacher/student) and ID, then removes the first match
void deleteEntry(std::vector<Teacher>& teachers, std::vector<Student>& students) {
    std::string input;
    int type, targetId;

    std::cout << "\n--- Delete Entry ---\n";
    std::cout << "Delete from:\n1. Teachers\n2. Students\nEnter choice: ";
    std::getline(std::cin, input);
    type = std::stoi(input);

    std::cout << "Enter ID to delete: ";
    std::getline(std::cin, input);
    targetId = std::stoi(input);

    bool found = false;

    if (type == 1) {  // Delete teacher
        for (auto it = teachers.begin(); it != teachers.end(); ++it) {
            if (it->id == targetId) {
                teachers.erase(it);
                std::cout << "Teacher with ID " << targetId << " deleted.\n";
                found = true;
                break;
            }
        }
    }
    else if (type == 2) {  // Delete student
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == targetId) {
                students.erase(it);
                std::cout << "Student with ID " << targetId << " deleted.\n";
                found = true;
                break;
            }
        }
    }
    else {
        std::cout << "Invalid type selected.\n";
        return;
    }

    if (!found) {
        std::cout << "No entry found with that ID.\n";
    }
}

// Pauses execution so the user can read the result of the previous action
void pressToContinue() {
    std::cout << "\nPress Enter to return to the menu...";
    std::string dummy;
    std::getline(std::cin, dummy);
}

int main() {
    std::vector<Teacher> teachers;
    std::vector<Student> students;

    std::cout << "Welcome to the School Database!\n";

    while (true) {
        clearScreen();          // Clean screen before every menu display
        displayMenu();

        int choice;
        std::cin >> choice;
        // Clear the input buffer after numeric choice (prevents getline issues later)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            displayAll(teachers, students);
            pressToContinue();
            break;
        case 2:
            addStudent(students);
            pressToContinue();
            break;
        case 3:
            addTeacher(teachers);
            pressToContinue();
            break;
        case 4:
            deleteEntry(teachers, students);
            pressToContinue();
            break;
        case 5:
            std::cout << "\nExiting program. Goodbye!\n";
            return 0;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
            pressToContinue();
            break;
        }
    }

    return 0;
}