// Jonathan Andrews
// Object Oritented Development Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Me

#include <iostream>
#include <Windows.h>

// Builds for both classes, Student and Teacher, which are stored in the database
class Student
{
private: 
	std::string name;
	int age;
	int student_ID;
	std::string grade;

public: 
	
	Student() : name(""), age(0), student_ID(0), grade("") {}		

	Student(std::string n, int a, int stu_ID, std::string g)
	{
		name = n;
		age = a;
		student_ID = stu_ID;
		grade = g;
	}

	std::string getName() const 
	{ 
		return name; 
	}

	int getAge() const 
	{ 
		return age; 
	}

	int getStudentID() const 
	{ 
		return student_ID; 
	}
	
	std::string getGrade() const 
	{
		return grade; 
	}

	void setName(std::string n) 
	{ 
		name = n; 
	}
	
	void setAge(int a) 
	{ 
		age = a; 
	}
	
	void setStudentID(int stu_ID) 
	{ 
		student_ID = stu_ID; 
	}
	
	void setGrade(std::string g) 
	{ 
		grade = g; 
	}
};

class Teacher
{
	std::string name;
	int age;
	std::string subject;
	int teacher_ID;
	
public:
	Teacher() : name(""), age(0), teacher_ID(0), subject("") {}

	Teacher(std::string n, int a, std::string sub, int t_ID)
	{
		name = n;
		age = a;
		subject = sub;
		teacher_ID = t_ID;	
	}
	std::string getName() const 
	{ 
		return name; 
	}
	
	int getAge() const 
	{ 
		return age; 
	}
	
	std::string getSubject() const 
	{ 
		return subject; 
	}
	
	int getTeacherID() const 
	{ 
		return teacher_ID; 
	}
	
	void setName(std::string n)
	{ 
		name = n; 
	}

	void setAge(int a)
	{ 
		age = a; 
	}
	
	void setSubject(std::string sub) 
	{ 
		subject = sub; 
	}
	
	void setTeacherID(int t_ID) 
	{ 
		teacher_ID = t_ID; 
	}
};

void addTeacher(Teacher teach[], int numInputTeachers);
void addStudent(Student student[], int numInputStudents);
int menu();
void viewEntries(Teacher teach[], Student student[], int numStudents, int numTeachers);
int numEntriesStudent(int numInputStudents);
int numEntriesTeacher(int numInputStudents);
void deleteEntry(Teacher teach[], int& numTeachers, Student student[], int& numStudents);

const int MAXSIZE = 20;

int main()
{
	Student studs[MAXSIZE];
	Teacher teach[MAXSIZE];
	int numInputStudents = 0;
	int numInputTeachers = 0;

	// Main loop for the menu that loops until the user is done with the program. Handles input for any option, including exiting the program.
	while (true)
	{
		int input = menu();
		Sleep(1000);
		system("cls");

		// Switch statement that handles the input for the menu, calls the appropriate function for each option, and has a case for exiting the program.
		switch (input)
		{
		case 1: viewEntries(teach, studs, numInputStudents, numInputTeachers);
			break;
		case 2:numInputStudents = numEntriesStudent(numInputStudents);
			addStudent(studs, numInputStudents);
			break;
		case 3: numInputTeachers = numEntriesTeacher(numInputTeachers);
			addTeacher(teach, numInputTeachers);
			break;
		case 4: deleteEntry(teach, numInputTeachers, studs, numInputStudents);
			break;
		case 5:
			std::cout << "Thanks you for your use. Goodbye!" << std::endl;
			Sleep(2000);
			return 0;
			break;
		}
	}
}

int menu()
{
	int input;


	std::cout << "School Database\n";
	std::cout << "1.View Entries.\n2.Add To Student Database.\n"
		<< "3.Add to Teacher Database.\n4.Delete Entry.\n5.Exit\n\n";
	std::cout << "Please input entry." << std::endl;

	std::cin >> input;
	
	// Low level input validation
	while (input < 1 || input > 5)
	{
		std::cout << "Error: Input out of range, try again\n";
		std::cin >> input;
	}

	return input;
}

void viewEntries(Teacher teach[], Student student[], int numStudents, int numTeachers)
{
	Sleep(1500);
	system("cls");

	std::cout << "All Entries In Database:\n\n";
	std::cout << "Teachers:\n";
	
	// Both for loops display any and all teachers and students that are stored in the database
	for (int i = 0; i < numTeachers; i++)
	{
		std::cout << "Teacher " << (i + 1) << ": " << teach[i].getName() << ", Age: " << teach[i].getAge() << ", Subject: " 
			<< teach[i].getSubject() << ", Teacher ID: " << teach[i].getTeacherID() << std::endl;
	}
	std::cout << "\nStudents:\n";

	for (int i = 0; i < numStudents; i++)
	{
		std::cout << "Student " << (i + 1) << ": " << student[i].getName() << ", Age: " << student[i].getAge() << ", Student ID: "
			<< student[i].getStudentID() << ", Grade: " << student[i].getGrade() << std::endl;
	}
}

void addStudent(Student student[], int numInputStudents)
{
	std::string name;
	int age;
	int student_ID;
	std::string grade;

	// Asks for all information on the student being added to the Database
	for (int i = 0; i < numInputStudents; i++)
	{
		std::cout << "Enter the name of Student " << (i + 1) << ": ";
		std::cin >> name;
		std::cout << "Enter the age of Student " << (i + 1) << ": ";
		std::cin >> age;
		std::cout << "Enter the student ID of Student " << (i + 1) << ": ";
		std::cin >> student_ID;
		std::cout << "Enter the grade of Student " << (i + 1) << ": ";
		std::cin >> grade;

		student[i] = Student(name, age, student_ID, grade);
	}
}

void addTeacher(Teacher teach[], int numInputTeachers)
{
	std::string name;
	int age;
	std::string subject;
	int teacher_ID;

	// Asks for all information on the teacher being added to the Database
	for (int i = 0; i < numInputTeachers; i++)
			{
		std::cout << "Enter the name of Teacher " << (i + 1) << ": ";
		std::cin >> name;
		std::cout << "Enter the age of Teacher " << (i + 1) << ": ";
		std::cin >> age;
		std::cout << "Enter the subject of Teacher " << (i + 1) << ": ";
		std::cin >> subject;
		std::cout << "Enter the teacher ID of Teacher " << (i + 1) << ": ";
		std::cin >> teacher_ID;

		teach[i] = Teacher(name, age, subject, teacher_ID);
	}
}

// Finds out how many students the user wants to add, used for logic later 
int numEntriesStudent(int numInputStudents)
{
	int input;
	std::cout << "How many students would you like to add to the database?" << std::endl;
	std::cin >> input;

	numInputStudents += input;

	return numInputStudents;
}

// Finds out how many teachers the user wants to add, used for logic later
int numEntriesTeacher(int numInputTeachers)
{
	int input;
	std::cout << "How many teachers would you like to add to the database?" << std::endl;
	std::cin >> input;

	numInputTeachers += input;

	return numInputTeachers;
}

// Used to delete either a teacher or student entry, takes the numEntries to do this and the arrays to shift the entries down after deletion, also has input validation for the index of the entry to delete
void deleteEntry(Teacher teach[], int& numTeachers, Student student[], int& numStudents)
{
	int choice;
	int index;

	std::cout << "Delete Entry:\n1. Teacher\n2. Student\n";
	std::cin >> choice;

	while (choice < 1 || choice > 2)
	{
		std::cout << "Error: Input out of range, try again\n";
		std::cin >> choice;
	}

	if (choice == 1)
	{
		std::cout << "Enter the index of the teacher to delete (1-" << numTeachers << "): " << std::endl;
		std::cin >> index;

		// Adjust index to be 0-based for array access
		index--;

		// Error handling for index out of range and no entries to delete
		if (index < 0 || index >= numTeachers)
		{
			std::cout << "Error: Index out of range.\n";
			return;
		}
		else if (index == 0)
		{
			std::cout << "Error: No Teachers to Delete.\n";
			return;
		}

		for (int i = index; i < numTeachers - 1; i++)
		{
			teach[i] = teach[i + 1];
		}

		numTeachers--;

		std::cout << "Teacher entry deleted successfully.\n";

		return;
	}
	else if (choice == 2)
	{
		std::cout << "Enter the index of of the student to delete (1-" << numStudents << "):" << std::endl;
		std::cin >> index;

		index--;

		if (index < 0 || index >= numStudents)
		{
			std::cout << "Error: Index out of range.\n";
			return;
		}
		else if (index == 0)
		{
			std::cout << "Error: No Students to Delete.\n";
			return;
		}

		for (int i = index; i < numStudents - 1; i++)
		{
			student[i] = student[i + 1];
		}

		numStudents--;

		std::cout << "Student entry deleted successfully.\n";

		return;
	}
}