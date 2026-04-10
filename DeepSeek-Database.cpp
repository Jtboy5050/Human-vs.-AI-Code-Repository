// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: DeepSeek

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>  // for system() calls

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

// Base class for common attributes
class Person {
protected:
    std::string name;
    int age;
    int id;

public:
    Person(const std::string& n, int a, int i) : name(n), age(a), id(i) {}
    virtual ~Person() {}

    // Virtual function for polymorphic display
    virtual void display() const = 0;

    // Getters for searching/deletion
    int getId() const { return id; }
    std::string getName() const { return name; }
};

// Teacher class derived from Person
class Teacher : public Person {
private:
    std::string subject;

public:
    Teacher(const std::string& n, int a, int i, const std::string& sub)
        : Person(n, a, i), subject(sub) {
    }

    void display() const override {
        std::cout << "TEACHER - ID: " << id
            << " | Name: " << name
            << " | Age: " << age
            << " | Subject: " << subject << std::endl;
    }
};

// Student class derived from Person
class Student : public Person {
private:
    double grade;

public:
    Student(const std::string& n, int a, int i, double g)
        : Person(n, a, i), grade(g) {
    }

    void display() const override {
        std::cout << "STUDENT - ID: " << id
            << " | Name: " << name
            << " | Age: " << age
            << " | Grade: " << grade << std::endl;
    }
};

// Database class to manage both teachers and students
class Database {
private:
    std::vector<Teacher> teachers;
    std::vector<Student> students;

    // Helper function to clear input buffer
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Helper function to get integer input with validation
    int getIntInput(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                clearInputBuffer();
                return value;
            }
            else {
                std::cout << "Invalid input. Please enter a number.\n";
                clearInputBuffer();
            }
        }
    }

    // Helper function to get double input with validation
    double getDoubleInput(const std::string& prompt) {
        double value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                clearInputBuffer();
                return value;
            }
            else {
                std::cout << "Invalid input. Please enter a number.\n";
                clearInputBuffer();
            }
        }
    }

    // Helper function to check if ID already exists
    bool idExists(int id) const {
        for (const auto& teacher : teachers) {
            if (teacher.getId() == id) return true;
        }
        for (const auto& student : students) {
            if (student.getId() == id) return true;
        }
        return false;
    }

public:
    // Display all entries (both teachers and students)
    void displayAll() const {
        std::cout << "\n=== ALL ENTITIES ===\n";

        if (teachers.empty() && students.empty()) {
            std::cout << "No entries found.\n";
            return;
        }

        if (!teachers.empty()) {
            std::cout << "\n--- TEACHERS (" << teachers.size() << ") ---\n";
            for (const auto& teacher : teachers) {
                teacher.display();
            }
        }

        if (!students.empty()) {
            std::cout << "\n--- STUDENTS (" << students.size() << ") ---\n";
            for (const auto& student : students) {
                student.display();
            }
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }

    // Add a new teacher
    void addTeacher() {
        std::cout << "\n=== ADD NEW TEACHER ===\n";

        std::string name, subject;
        int age, id;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        age = getIntInput("Enter age: ");

        // Ensure unique ID
        do {
            id = getIntInput("Enter ID: ");
            if (idExists(id)) {
                std::cout << "ID already exists. Please use a different ID.\n";
            }
        } while (idExists(id));

        std::cout << "Enter subject: ";
        std::getline(std::cin, subject);

        teachers.emplace_back(name, age, id, subject);
        std::cout << "Teacher added successfully!\n";
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }

    // Add a new student
    void addStudent() {
        std::cout << "\n=== ADD NEW STUDENT ===\n";

        std::string name;
        int age, id;
        double grade;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        age = getIntInput("Enter age: ");

        // Ensure unique ID
        do {
            id = getIntInput("Enter ID: ");
            if (idExists(id)) {
                std::cout << "ID already exists. Please use a different ID.\n";
            }
        } while (idExists(id));

        grade = getDoubleInput("Enter grade: ");

        students.emplace_back(name, age, id, grade);
        std::cout << "Student added successfully!\n";
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }

    // Delete an entry by ID
    void deleteEntry() {
        std::cout << "\n=== DELETE ENTRY ===\n";
        int id = getIntInput("Enter ID to delete: ");

        // Search and delete from teachers
        for (auto it = teachers.begin(); it != teachers.end(); ++it) {
            if (it->getId() == id) {
                teachers.erase(it);
                std::cout << "Teacher with ID " << id << " deleted successfully.\n";
                std::cout << "Press Enter to continue...";
                std::cin.get();
                return;
            }
        }

        // Search and delete from students
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                std::cout << "Student with ID " << id << " deleted successfully.\n";
                std::cout << "Press Enter to continue...";
                std::cin.get();
                return;
            }
        }

        std::cout << "No entry found with ID " << id << ".\n";
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }
};

// Display the main menu and get user choice
void displayMenu() {
    std::cout << "\n=== DATABASE MANAGEMENT SYSTEM ===\n";
    std::cout << "1. See all entries\n";
    std::cout << "2. Add a student\n";
    std::cout << "3. Add a teacher\n";
    std::cout << "4. Delete an entry\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice (1-5): ";
}

int main() {
    Database db;
    int choice;

    do {
        // Clear screen before showing menu
        system(CLEAR_SCREEN);

        displayMenu();

        // Input validation
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            std::cout << "Press Enter to continue...";
            std::cin.get();
            continue;
        }

        // Clear input buffer after reading choice
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            db.displayAll();
            break;
        case 2:
            db.addStudent();
            break;
        case 3:
            db.addTeacher();
            break;
        case 4:
            db.deleteEntry();
            break;
        case 5:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter 1-5.\n";
            std::cout << "Press Enter to continue...";
            std::cin.get();
        }

    } while (choice != 5);

    return 0;
}