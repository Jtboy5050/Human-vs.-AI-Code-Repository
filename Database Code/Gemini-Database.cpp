// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Gemini

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

// Standard cleanup function to handle different operating systems
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Base class to handle shared attributes between Students and Teachers
class Person {
public:
    std::string name;
    int age;
    int id;

    virtual void display() const = 0; // Pure virtual function for polymorphism
    virtual ~Person() {}
};

class Student : public Person {
public:
    std::string grade;

    void display() const override {
        std::cout << "[Student] ID: " << id << " | Name: " << name
            << " | Age: " << age << " | Grade: " << grade << std::endl;
    }
};

class Teacher : public Person {
public:
    std::string subject;

    void display() const override {
        std::cout << "[Teacher] ID: " << id << " | Name: " << name
            << " | Age: " << age << " | Subject: " << subject << std::endl;
    }
};

// Database class to manage the collections
class SchoolDatabase {
private:
    std::vector<Student> students;
    std::vector<Teacher> teachers;

public:
    void addStudent() {
        Student s;
        std::cout << "Enter Student Name: ";
        std::getline(std::cin >> std::ws, s.name);
        std::cout << "Enter Age: ";
        std::cin >> s.age;
        std::cout << "Enter ID: ";
        std::cin >> s.id;
        std::cout << "Enter Grade: ";
        std::cin >> s.grade;
        students.push_back(s);
    }

    void addTeacher() {
        Teacher t;
        std::cout << "Enter Teacher Name: ";
        std::getline(std::cin >> std::ws, t.name);
        std::cout << "Enter Age: ";
        std::cin >> t.age;
        std::cout << "Enter ID: ";
        std::cin >> t.id;
        std::cout << "Enter Subject: ";
        std::getline(std::cin >> std::ws, t.subject);
        teachers.push_back(t);
    }

    void displayAll() const {
        if (students.empty() && teachers.empty()) {
            std::cout << "The database is currently empty.\n";
            return;
        }
        std::cout << "--- Current Entries ---\n";
        for (const auto& t : teachers) t.display();
        for (const auto& s : students) s.display();
    }

    void deleteEntry(int id) {
        // Look for ID in teachers
        auto itT = std::remove_if(teachers.begin(), teachers.end(), [id](const Teacher& t) { return t.id == id; });
        if (itT != teachers.end()) {
            teachers.erase(itT, teachers.end());
            std::cout << "Teacher with ID " << id << " deleted.\n";
            return;
        }

        // Look for ID in students
        auto itS = std::remove_if(students.begin(), students.end(), [id](const Student& s) { return s.id == id; });
        if (itS != students.end()) {
            students.erase(itS, students.end());
            std::cout << "Student with ID " << id << " deleted.\n";
            return;
        }

        std::cout << "Entry with ID " << id << " not found.\n";
    }
};

int main() {
    SchoolDatabase db;
    int choice = 0;

    while (true) {
        std::cout << "\n--- SCHOOL DATABASE MENU ---\n";
        std::cout << "1. See All Entries\n";
        std::cout << "2. Add Student\n";
        std::cout << "3. Add Teacher\n";
        std::cout << "4. Delete Entry (by ID)\n";
        std::cout << "5. Exit\n";
        std::cout << "Selection: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        clearScreen();

        if (choice == 5) break;

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
            int idToDelete;
            std::cout << "Enter ID to delete: ";
            std::cin >> idToDelete;
            db.deleteEntry(idToDelete);
            break;
        default:
            std::cout << "Invalid selection. Try again.\n";
        }

        std::cout << "\nPress Enter to return to menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        clearScreen();
    }

    return 0;
}