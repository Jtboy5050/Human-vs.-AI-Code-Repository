// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Grok


#include <iostream>
#include <limits>
#include <cmath>     // for fmod (modulus with floats)
#include <cstdlib>   // for system("cls") or system("clear")

using namespace std;

// Function to clear the screen (works on both Windows and Unix-like systems)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to safely get an integer input with validation
int getValidInt(int min, int max, const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value >= min && value <= max) {
                return value;
            }
            else {
                cout << "Error: Please enter a number between " << min << " and " << max << ".\n";
            }
        }
        else {
            cout << "Error: Invalid input. Please enter a number.\n";
            cin.clear();                    // clear error flag
        }
        // Discard remaining input on the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to get a valid floating-point number
double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        else {
            cout << "Error: Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    char playAgain;

    do {
        clearScreen();
        cout << "=====================================\n";
        cout << "      Multi-Number Calculator        \n";
        cout << "=====================================\n\n";

        // Show menu
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus (remainder)\n";
        cout << "6. Exit\n\n";

        int choice = getValidInt(1, 6, "Enter your choice (1-6): ");

        if (choice == 6) {
            clearScreen();
            cout << "\nThank you for using the calculator!\n";
            cout << "Goodbye!\n\n";
            return 0;
        }

        // Get how many numbers the user wants to operate on
        int numCount = getValidInt(2, 20, "\nHow many numbers do you want to use? (2-20): ");

        // Array to store the numbers (max 20)
        double numbers[20];

        // Input the numbers
        cout << "\nEnter " << numCount << " numbers:\n";
        for (int i = 0; i < numCount; i++) {
            numbers[i] = getValidDouble("Number " + to_string(i + 1) + ": ");
        }

        clearScreen();
        cout << "\nYou entered:\n";
        for (int i = 0; i < numCount; i++) {
            cout << "  " << (i + 1) << ") " << numbers[i] << "\n";
        }
        cout << "\n";

        double result = numbers[0];  // start with first number

        // Perform the chosen operation
        switch (choice) {
        case 1: // Addition
            for (int i = 1; i < numCount; i++) {
                result += numbers[i];
            }
            cout << "Result of addition: " << result << "\n\n";
            break;

        case 2: // Subtraction
            for (int i = 1; i < numCount; i++) {
                result -= numbers[i];
            }
            cout << "Result of subtraction: " << result << "\n\n";
            break;

        case 3: // Multiplication
            for (int i = 1; i < numCount; i++) {
                result *= numbers[i];
            }
            cout << "Result of multiplication: " << result << "\n\n";
            break;

        case 4: // Division
        {
            bool valid = true;
            for (int i = 1; i < numCount; i++) {
                if (numbers[i] == 0) {
                    cout << "Error: Division by zero detected!\n";
                    valid = false;
                    break;
                }
                result /= numbers[i];
            }
            if (valid) {
                cout << "Result of division: " << result << "\n\n";
            }
        }
        break;

        case 5: // Modulus
        {
            bool valid = true;
            for (int i = 1; i < numCount; i++) {
                if (numbers[i] == 0) {
                    cout << "Error: Modulus by zero is undefined!\n";
                    valid = false;
                    break;
                }
                // Use fmod for floating-point modulus
                result = fmod(result, numbers[i]);
            }
            if (valid) {
                cout << "Result of modulus: " << result << "\n\n";
            }
        }
        break;
        }

        // Ask if user wants to play again
        cout << "Would you like to do another calculation? (y/n): ";
        cin >> playAgain;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

    } while (playAgain == 'y' || playAgain == 'Y');

    clearScreen();
    cout << "\nThanks for using the calculator!\n";
    cout << "See you next time!\n\n";

    return 0;
}