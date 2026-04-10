// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Me

// Necessary inclusions
#include <iostream>
#include <windows.h>

// Function Prototypes
int menu();
int howManyNum();
int* whatNums(int nums[], int howMany);
int addNums(int nums[], int howMany);
int subNums(int nums[], int howMany);
int multNums(int nums[], int howMany);
int divNums(int nums[], int howMany);
int modNums(int nums[], int howMany);

// The absolute most numbers the program handles, constant so an array can be created
const int MAXNUMS = 20;

// Handles most of the logic of the program
int main() {
	// What allows the program to repeat itself
	char choice = 'y';

	// A do loop is used for if the user wants to run the program again
	do {
		// Will hold the total of all numbers later
		int theTotal = 0;

		int menuChoice = menu();
		system("cls");

		if (menuChoice == 6) {
			std::cout << "Thank you for using the program! Have a good day!" << std::endl;

			return 0;
		}

		// Finds out how many numbers the user plans to use
		int howManyUser = howManyNum();
		int* numbers = new int[howManyUser];
		system("cls");
		
		// Once the user figures out how many numbers they want, this lets them choose their numbers
		whatNums(numbers, howManyUser);
		system("cls");

		// Uses the menu input in order to properly send the user to the correct function that they chose, as well as keeps a track of their total 
		// after function execution
		switch (menuChoice) {
		case 1: theTotal = addNums(numbers, howManyUser);
			std::cout << "Your total after adding " << howManyUser << " numbers is " << theTotal << std::endl;
			break;

		case 2: theTotal = subNums(numbers, howManyUser);
			std::cout << "Your total after subtracting " << howManyUser << " numbers is " << theTotal << std::endl;
			break;

		case 3: theTotal = multNums(numbers, howManyUser);
			std::cout << "Your total after multiplying " << howManyUser << " numbers is " << theTotal << std::endl;
			break;

		case 4: theTotal = divNums(numbers, howManyUser);
			std::cout << "Your total after dividing " << howManyUser << " numbers is " << theTotal << std::endl;
			break;

		case 5: theTotal = modNums(numbers, howManyUser);
			std::cout << "Your total after modulus-ing " << howManyUser << " numbers is " << theTotal << std::endl;
			break;
		}

		// Clears the memory to prevent memory overflow
		delete[] numbers;

		// The prompt for if the user wants to run the program again: clears the screen and restarts if yes, exits if no
		std::cout << "\nWould you like to run the program again? Y/N" << std::endl;
		std::cin >> choice;
		
		if (choice == 'y' || choice == 'Y') {
			system("cls");
		}
		else {
			std::cout << "Understood! Have a good day!" << std::endl;
			Sleep(500);
		}
	} while (choice == 'y' || choice == 'Y');
}

// Builds the menu and takes in a number from 1 to 6 for menu choices
int menu() {
	int choice;

	std::cout << "Please select your choice from the following:\n\n";
	std::cout << "1. Addition.\n2. Subtraction.\n3. Multiplication.\n4. Division.\n5. Modulus.\n6. Exit.\n\n";
	std::cin >> choice;

	while (choice < 1 || choice > 6) {
		std::cout << "Error! Number not between 1 and 6. Please try again.\n";
		std::cin >> choice;
	}

	return choice;
}

// Finds out how many numbers the user plans on using between 2 and 20
int howManyNum() {
	int howMany;

	std::cout << "How many numbers would you like to use? Pick between 2 and 20.\n";
	std::cin >> howMany;

	while (howMany < 2 || howMany > 20) {
		std::cout << "Error! The number you picked is larger than 20 or less 2. Please try again.\n";
		std::cin >> howMany;
	}

	return howMany;
}

// Let's the user pick their specific numbers
int* whatNums(int nums[], int howMany) {
	for (int i = 0; i < howMany; i++) {
		std::cout << "Enter Number " << i + 1 << ":\n";
		std::cin >> nums[i];
	}

	return nums;
}

// Adds the user's numbers
int addNums(int nums[], int howMany) {
	int runningTotal = nums[0];

	for (int i = 1; i < howMany; i++) {
		runningTotal += nums[i];
	}

	return runningTotal;
}

// Subtracts the user's numbers
int subNums(int nums[], int howMany) {
	int runningTotal = nums[0];

	for (int i = 1; i < howMany; i++) {
		runningTotal -= nums[i];
	}

	return runningTotal;
}

// Mulitiplys the user's numbers
int multNums(int nums[], int howMany) {
	int runningTotal = nums[0];

	for (int i = 1; i < howMany; i++) {
		runningTotal *= nums[i];
	}

	return runningTotal;
}

// Divides the user's numbers
int divNums(int nums[], int howMany) {
	int runningTotal = nums[0];

	for (int i = 1; i < howMany; i++) {
		// divide by 0 protection
		if (nums[i] == 0) {
			nums[i] = 1;
			std::cout << "Since the number was 0, it has been set to 1 due to dividing by 0 errors\n";
		}
		runningTotal /= nums[i];
	}

	return runningTotal;
}

// Uses modulus on the user's numbers
int modNums(int nums[], int howMany) {
	int runningTotal = nums[0];

	for (int i = 1; i < howMany; i++) {
		// divide by 0 protection
		if (nums[i] == 0) {
			nums[i] = 1;
			std::cout << "Since the number was 0, it has been set to 1 due to dividing by 0 errors\n";
		}
		runningTotal &= nums[i];
	}

	return runningTotal;
}