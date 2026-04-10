// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: CoPilot

#include <iostream>
#include <vector>
#include <limits>   // For input clearing
#include <cstdlib>  // For system("clear") or system("CLS")
using namespace std;

// Function to clear the screen depending on OS
void clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

// Function to safely get an integer with validation
int getInt() {
    int x;
    while (!(cin >> x)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return x;
}

int main() {
    bool runAgain = true;

    while (runAgain) {
        clearScreen();
        cout << "=============================\n";
        cout << "      SIMPLE CALCULATOR\n";
        cout << "=============================\n\n";

        int choice = 0;

        // Menu loop with validation
        while (true) {
            cout << "Choose an option:\n";
            cout << "1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Modulus\n";
            cout << "6. Exit\n";
            cout << "Enter choice (1-6): ";

            choice = getInt();

            if (choice >= 1 && choice <= 6)
                break;

            cout << "Invalid choice. Please try again.\n\n";
        }

        // Exit option
        if (choice == 6) {
            cout << "\nGoodbye and thanks for using the calculator!\n";
            return 0;
        }

        clearScreen();

        // Ask how many numbers
        int count = 0;
        while (true) {
            cout << "How many numbers do you want to use? (2–20): ";
            count = getInt();

            if (count >= 2 && count <= 20)
                break;

            cout << "Invalid amount. Please choose between 2 and 20.\n";
        }

        clearScreen();

        // Get the numbers
        vector<int> nums(count);
        cout << "Enter your " << count << " numbers:\n";
        for (int i = 0; i < count; i++) {
            cout << "Number " << i + 1 << ": ";
            nums[i] = getInt();
        }

        clearScreen();

        // Perform the chosen operation
        long long result = nums[0];  // Start with first number

        switch (choice) {
        case 1: // Addition
            for (int i = 1; i < count; i++)
                result += nums[i];
            cout << "Result (Addition): " << result << "\n";
            break;

        case 2: // Subtraction
            for (int i = 1; i < count; i++)
                result -= nums[i];
            cout << "Result (Subtraction): " << result << "\n";
            break;

        case 3: // Multiplication
            for (int i = 1; i < count; i++)
                result *= nums[i];
            cout << "Result (Multiplication): " << result << "\n";
            break;

        case 4: // Division
            for (int i = 1; i < count; i++) {
                if (nums[i] == 0) {
                    cout << "Error: Division by zero encountered.\n";
                    goto skipResult;
                }
                result /= nums[i];
            }
            cout << "Result (Division): " << result << "\n";
            break;

        case 5: // Modulus
            for (int i = 1; i < count; i++) {
                if (nums[i] == 0) {
                    cout << "Error: Modulus by zero encountered.\n";
                    goto skipResult;
                }
                result %= nums[i];
            }
            cout << "Result (Modulus): " << result << "\n";
            break;
        }

    skipResult:

        // Ask user if they want to run again
        cout << "\nWould you like to run the program again? (y/n): ";
        char again;
        cin >> again;

        if (again != 'y' && again != 'Y')
            runAgain = false;
    }

    cout << "\nThanks for using the calculator. Goodbye!\n";
    return 0;
}
