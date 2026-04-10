// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: Google Gemini

#include <iostream>
#include <vector>
#include <limits> // For clearing the input buffer

using namespace std;

// Function to clear the screen based on the OS
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showMenu() {
    cout << "--- Professional Calculator ---" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exit" << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter your choice (1-6): ";
}

int main() {
    int choice = 0;

    while (true) {
        showMenu();
        cin >> choice;

        // Validation for menu choice
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearScreen();
            cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
            continue;
        }

        // Exit condition
        if (choice == 6) {
            cout << "Goodbye and thanks for using the calculator!" << endl;
            break;
        }

        // Ask for the count of numbers
        int count;
        while (true) {
            cout << "How many numbers would you like to use (2-20)? ";
            cin >> count;

            if (cin.fail() || count < 2 || count > 20) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please choose between 2 and 20." << endl;
            }
            else {
                break;
            }
        }

        // Collect the numbers from the user
        vector<double> nums(count);
        for (int i = 0; i < count; ++i) {
            cout << "Enter number " << (i + 1) << ": ";
            cin >> nums[i];

            // Basic check for non-numeric input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry. Try number " << (i + 1) << " again." << endl;
                i--;
            }
        }

        // Perform operations
        double result = nums[0];
        bool possible = true;

        for (int i = 1; i < count; ++i) {
            switch (choice) {
            case 1: result += nums[i]; break;
            case 2: result -= nums[i]; break;
            case 3: result *= nums[i]; break;
            case 4:
                if (nums[i] == 0) {
                    cout << "Error: Division by zero!" << endl;
                    possible = false;
                }
                else {
                    result /= nums[i];
                }
                break;
            case 5:
                if ((int)nums[i] == 0) {
                    cout << "Error: Modulo by zero!" << endl;
                    possible = false;
                }
                else {
                    // Modulo requires integers in C++
                    result = (int)result % (int)nums[i];
                }
                break;
            }
            if (!possible) break;
        }

        // Output result
        if (possible) {
            cout << "\n>>> The final result is: " << result << " <<<" << endl;
        }

        // Ask to run again
        char runAgain;
        cout << "\nWould you like to perform another calculation? (y/n): ";
        cin >> runAgain;

        if (runAgain == 'y' || runAgain == 'Y') {
            clearScreen();
        }
        else {
            cout << "Goodbye and thanks!" << endl;
            break;
        }
    }

    return 0;
}