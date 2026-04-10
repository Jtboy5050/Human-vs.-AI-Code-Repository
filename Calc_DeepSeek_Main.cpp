// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: DeepSeek


#include <iostream>
#include <limits>  // For numeric_limits
#include <vector>  // For dynamic array of numbers
#include <cstdlib> // For system() function

using namespace std;

// Function to clear the screen
void clearScreen() {
    // Clear screen command (works on Windows, Linux, and macOS)
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to display the main menu
void displayMenu() {
    cout << "\n===================================\n";
    cout << "          CALCULATOR MENU\n";
    cout << "===================================\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "5. Modulus (%)\n";
    cout << "6. Exit Program\n";
    cout << "===================================\n";
    cout << "Enter your choice (1-6): ";
}

// Function to get a valid menu choice from user
int getMenuChoice() {
    int choice;

    while (true) {
        cin >> choice;

        // Check if input failed (non-numeric input)
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Invalid input. Please enter a number between 1 and 6: ";
        }
        else if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return choice;
        }
    }
}

// Function to get valid number of operands from user
int getNumberOfOperands() {
    int count;

    while (true) {
        cout << "How many numbers do you want to operate on? (2-20): ";
        cin >> count;

        // Check if input failed
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 2 and 20.\n";
        }
        else if (count < 2 || count > 20) {
            cout << "Number must be between 2 and 20. Please try again.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return count;
        }
    }
}

// Function to get numbers from user
vector<double> getNumbers(int count) {
    vector<double> numbers;
    double num;

    cout << "\nEnter " << count << " numbers:\n";
    for (int i = 0; i < count; i++) {
        cout << "Number " << (i + 1) << ": ";

        while (true) {
            cin >> num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid number: ";
            }
            else {
                numbers.push_back(num);
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                break;
            }
        }
    }

    return numbers;
}

// Function to perform addition
void performAddition(const vector<double>& numbers) {
    double result = numbers[0];

    cout << "\nPerforming Addition:\n";
    cout << numbers[0];

    for (size_t i = 1; i < numbers.size(); i++) {
        result += numbers[i];
        cout << " + " << numbers[i];
    }

    cout << " = " << result << endl;
}

// Function to perform subtraction
void performSubtraction(const vector<double>& numbers) {
    double result = numbers[0];

    cout << "\nPerforming Subtraction:\n";
    cout << numbers[0];

    for (size_t i = 1; i < numbers.size(); i++) {
        result -= numbers[i];
        cout << " - " << numbers[i];
    }

    cout << " = " << result << endl;
}

// Function to perform multiplication
void performMultiplication(const vector<double>& numbers) {
    double result = numbers[0];

    cout << "\nPerforming Multiplication:\n";
    cout << numbers[0];

    for (size_t i = 1; i < numbers.size(); i++) {
        result *= numbers[i];
        cout << " * " << numbers[i];
    }

    cout << " = " << result << endl;
}

// Function to perform division
void performDivision(const vector<double>& numbers) {
    double result = numbers[0];
    bool divisionByZero = false;

    cout << "\nPerforming Division:\n";
    cout << numbers[0];

    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] == 0) {
            cout << "\nError: Division by zero is not allowed!\n";
            divisionByZero = true;
            break;
        }
        result /= numbers[i];
        cout << " / " << numbers[i];
    }

    if (!divisionByZero) {
        cout << " = " << result << endl;
    }
}

// Function to perform modulus operation
void performModulus(const vector<double>& numbers) {
    // Modulus only works with integers, so we'll convert
    int intResult = static_cast<int>(numbers[0]);

    cout << "\nPerforming Modulus (using integer values):\n";
    cout << static_cast<int>(numbers[0]);

    for (size_t i = 1; i < numbers.size(); i++) {
        int intValue = static_cast<int>(numbers[i]);

        if (intValue == 0) {
            cout << "\nError: Modulus by zero is not allowed!\n";
            return;
        }

        intResult %= intValue;
        cout << " % " << intValue;
    }

    cout << " = " << intResult << endl;
}

// Function to ask if user wants to run the program again
bool askToContinue() {
    char choice;

    cout << "\n===================================\n";
    cout << "Do you want to perform another calculation? (y/n): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    return (choice == 'y' || choice == 'Y');
}

// Main function
int main() {
    bool running = true;

    while (running) {
        clearScreen();

        // Display menu and get user choice
        displayMenu();
        int choice = getMenuChoice();

        // If user chooses to exit
        if (choice == 6) {
            clearScreen();
            cout << "\n===================================\n";
            cout << "   Thank you for using the calculator!\n";
            cout << "           Goodbye!\n";
            cout << "===================================\n";
            break;
        }

        clearScreen();

        // Get number of operands
        int numCount = getNumberOfOperands();

        // Get the actual numbers
        vector<double> numbers = getNumbers(numCount);

        clearScreen();

        // Perform the selected operation
        switch (choice) {
        case 1: // Addition
            performAddition(numbers);
            break;

        case 2: // Subtraction
            performSubtraction(numbers);
            break;

        case 3: // Multiplication
            performMultiplication(numbers);
            break;

        case 4: // Division
            performDivision(numbers);
            break;

        case 5: // Modulus
            performModulus(numbers);
            break;
        }

        // Ask if user wants to continue
        if (!askToContinue()) {
            clearScreen();
            cout << "\n===================================\n";
            cout << "   Thank you for using the calculator!\n";
            cout << "           Goodbye!\n";
            cout << "===================================\n";
            running = false;
        }
    }

    return 0;
}