// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: PerplexityAI

#include <iostream>
#include <vector>
#include <limits> // For input validation
#include <cstdlib> // For system("clear") or system("CLS")

using namespace std;

// Function prototypes
void showMenu();
void performOperation(int choice);
void clearScreen();
bool runAgain();

int main() {
    int choice;
    bool keepRunning = true;

    while (keepRunning) {
        clearScreen();
        showMenu();
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        // Validate menu input
        while (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number from 1 to 6: ";
            cin >> choice;
        }

        // If user chooses to exit
        if (choice == 6) {
            cout << "Goodbye, and thanks for using the calculator!\n";
            break;
        }

        // Perform operation
        performOperation(choice);

        // Ask if user wants to run again
        keepRunning = runAgain();
    }

    return 0;
}

// Function to display the main menu
void showMenu() {
    cout << "=============================\n";
    cout << "        Simple Calculator     \n";
    cout << "=============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exit\n";
    cout << "=============================\n";
}

// Function to clear the screen (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

// Function to perform chosen operation
void performOperation(int choice) {
    int numCount;
    vector<double> numbers;

    clearScreen();
    cout << "How many numbers do you want to operate on? (2–20): ";
    cin >> numCount;

    // Validate number count
    while (cin.fail() || numCount < 2 || numCount > 20) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Please enter between 2 and 20: ";
        cin >> numCount;
    }

    numbers.resize(numCount);

    // Get user’s numbers
    for (int i = 0; i < numCount; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number: ";
            cin >> numbers[i];
        }
    }

    clearScreen();
    double result = numbers[0];

    // Perform the operation
    switch (choice) {
    case 1: // Addition
        for (int i = 1; i < numCount; i++) result += numbers[i];
        cout << "Result of addition = " << result << endl;
        break;

    case 2: // Subtraction
        for (int i = 1; i < numCount; i++) result -= numbers[i];
        cout << "Result of subtraction = " << result << endl;
        break;

    case 3: // Multiplication
        for (int i = 1; i < numCount; i++) result *= numbers[i];
        cout << "Result of multiplication = " << result << endl;
        break;

    case 4: // Division
        for (int i = 1; i < numCount; i++) {
            if (numbers[i] == 0) {
                cout << "Error: Cannot divide by zero.\n";
                return;
            }
            result /= numbers[i];
        }
        cout << "Result of division = " << result << endl;
        break;

    case 5: // Modulus
        // Ensure integers for modulus
    {
        vector<int> intNums(numCount);
        for (int i = 0; i < numCount; i++) intNums[i] = static_cast<int>(numbers[i]);

        int modResult = intNums[0];
        for (int i = 1; i < numCount; i++) {
            if (intNums[i] == 0) {
                cout << "Error: Cannot mod by zero.\n";
                return;
            }
            modResult %= intNums[i];
        }
        cout << "Result of modulus = " << modResult << endl;
    }
    break;
    }
}

// Ask user if they want to run again
bool runAgain() {
    char choice;
    cout << "\nWould you like to run the calculator again? (y/n): ";
    cin >> choice;

    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        cout << "Please enter 'y' or 'n': ";
        cin >> choice;
    }

    return (choice == 'y' || choice == 'Y');
}
