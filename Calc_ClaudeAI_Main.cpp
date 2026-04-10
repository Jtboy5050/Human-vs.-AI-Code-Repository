// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: ClaudeAI

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

// Function to clear the screen (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to display the main menu
void displayMenu() {
    cout << "\n========== CALCULATOR MENU ==========\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exit\n";
    cout << "=====================================\n";
    cout << "Enter your choice (1-6): ";
}

// Function to get a valid menu choice
int getMenuChoice() {
    int choice;

    while (true) {
        cin >> choice;

        // Check for invalid input
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 6: ";
        }
        // Check if choice is in valid range
        else if (choice < 1 || choice > 6) {
            cout << "Invalid choice! Please enter a number between 1 and 6: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return choice;
        }
    }
}

// Function to get the count of numbers (between 2 and 20)
int getNumberCount() {
    int count;

    cout << "\nHow many numbers do you want to use? (2-20): ";

    while (true) {
        cin >> count;

        // Check for invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 2 and 20: ";
        }
        // Check if count is in valid range
        else if (count < 2 || count > 20) {
            cout << "Invalid count! Please enter a number between 2 and 20: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return count;
        }
    }
}

// Function to get numbers from the user
vector<double> getNumbers(int count) {
    vector<double> numbers;

    cout << "\nEnter " << count << " numbers:\n";

    for (int i = 0; i < count; i++) {
        double num;
        cout << "Number " << (i + 1) << ": ";

        while (true) {
            cin >> num;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid number: ";
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                numbers.push_back(num);
                break;
            }
        }
    }

    return numbers;
}

// Function to perform addition
void performAddition(const vector<double>& numbers) {
    double result = 0;

    cout << "\nCalculation: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        result += numbers[i];
        cout << numbers[i];
        if (i < numbers.size() - 1) cout << " + ";
    }

    cout << " = " << result << endl;
}

// Function to perform subtraction
void performSubtraction(const vector<double>& numbers) {
    double result = numbers[0];

    cout << "\nCalculation: " << numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {
        result -= numbers[i];
        cout << " - " << numbers[i];
    }

    cout << " = " << result << endl;
}

// Function to perform multiplication
void performMultiplication(const vector<double>& numbers) {
    double result = 1;

    cout << "\nCalculation: ";
    for (size_t i = 0; i < numbers.size(); i++) {
        result *= numbers[i];
        cout << numbers[i];
        if (i < numbers.size() - 1) cout << " × ";
    }

    cout << " = " << result << endl;
}

// Function to perform division
void performDivision(const vector<double>& numbers) {
    double result = numbers[0];

    // Check for division by zero
    for (size_t i = 1; i < numbers.size(); i++) {
        if (numbers[i] == 0) {
            cout << "\nError: Division by zero is not allowed!\n";
            return;
        }
    }

    cout << "\nCalculation: " << numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {
        result /= numbers[i];
        cout << " ÷ " << numbers[i];
    }

    cout << " = " << result << endl;
}

// Function to perform modulus
void performModulus(const vector<double>& numbers) {
    // Convert all numbers to integers for modulus operation
    vector<int> intNumbers;

    for (double num : numbers) {
        intNumbers.push_back(static_cast<int>(num));
    }

    int result = intNumbers[0];

    // Check for modulus by zero
    for (size_t i = 1; i < intNumbers.size(); i++) {
        if (intNumbers[i] == 0) {
            cout << "\nError: Modulus by zero is not allowed!\n";
            return;
        }
    }

    cout << "\nCalculation: " << intNumbers[0];
    for (size_t i = 1; i < intNumbers.size(); i++) {
        result %= intNumbers[i];
        cout << " % " << intNumbers[i];
    }

    cout << " = " << result << endl;
    cout << "(Note: Numbers were converted to integers for modulus operation)\n";
}

// Function to ask if user wants to continue
bool askToContinue() {
    char response;

    cout << "\nWould you like to perform another calculation? (y/n): ";

    while (true) {
        cin >> response;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        response = tolower(response);

        if (response == 'y') {
            return true;
        }
        else if (response == 'n') {
            return false;
        }
        else {
            cout << "Invalid input! Please enter 'y' for yes or 'n' for no: ";
        }
    }
}

int main() {
    bool continueProgram = true;

    // Welcome message
    clearScreen();
    cout << "========================================\n";
    cout << "   Welcome to the Advanced Calculator!  \n";
    cout << "========================================\n";

    // Main program loop
    while (continueProgram) {
        // Display menu and get user choice
        displayMenu();
        int choice = getMenuChoice();

        // Exit option
        if (choice == 6) {
            clearScreen();
            cout << "\n========================================\n";
            cout << "  Thank you for using the calculator!  \n";
            cout << "            Goodbye!                   \n";
            cout << "========================================\n\n";
            break;
        }

        clearScreen();

        // Get the count of numbers
        int count = getNumberCount();

        // Get the numbers from the user
        vector<double> numbers = getNumbers(count);

        // Perform the selected operation
        switch (choice) {
        case 1:
            performAddition(numbers);
            break;
        case 2:
            performSubtraction(numbers);
            break;
        case 3:
            performMultiplication(numbers);
            break;
        case 4:
            performDivision(numbers);
            break;
        case 5:
            performModulus(numbers);
            break;
        }

        // Ask if user wants to continue
        continueProgram = askToContinue();

        if (continueProgram) {
            clearScreen();
        }
    }

    return 0;
}