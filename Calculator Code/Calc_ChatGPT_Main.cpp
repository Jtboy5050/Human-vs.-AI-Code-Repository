// Jonathan Andrews
// Calculator Project
// Dr. Michelle Talley- Introduction to Software Engineering
// Goal: This project is one of many to compare code created by humans versus code made by AI, to compare how they function, 
// ranging from simple projects to more complex ones to see how mulitple languages can handle programming.
// This program was written by: ChatGPT

#include <iostream>
#include <cstdlib>   // For system()
#include <limits>    // For input validation

using namespace std;

// Clears the screen depending on OS
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Displays the calculator menu
void displayMenu()
{
    cout << "===== Calculator Menu =====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exit\n";
    cout << "===========================\n";
}

int main()
{
    int choice;
    char runAgain = 'y';

    // Main program loop
    while (runAgain == 'y' || runAgain == 'Y')
    {
        clearScreen();

        // Menu choice validation
        do
        {
            displayMenu();
            cout << "Enter your choice (1-6): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 6)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                clearScreen();
                cout << "Invalid choice. Please try again.\n\n";
            }

        } while (choice < 1 || choice > 6);

        // Exit option
        if (choice == 6)
        {
            cout << "\nThanks for using the calculator. Goodbye!\n";
            return 0;
        }

        clearScreen();

        int count;

        // Number count validation
        do
        {
            cout << "How many numbers would you like to use? (2 - 20): ";
            cin >> count;

            if (cin.fail() || count < 2 || count > 20)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Please enter a number between 2 and 20.\n\n";
            }

        } while (count < 2 || count > 20);

        double numbers[20];

        // Input numbers
        for (int i = 0; i < count; i++)
        {
            cout << "Enter number " << (i + 1) << ": ";
            cin >> numbers[i];
        }

        clearScreen();

        double result = numbers[0];

        // Perform selected operation
        switch (choice)
        {
        case 1: // Addition
            for (int i = 1; i < count; i++)
                result += numbers[i];
            cout << "Result (Addition): " << result << endl;
            break;

        case 2: // Subtraction
            for (int i = 1; i < count; i++)
                result -= numbers[i];
            cout << "Result (Subtraction): " << result << endl;
            break;

        case 3: // Multiplication
            for (int i = 1; i < count; i++)
                result *= numbers[i];
            cout << "Result (Multiplication): " << result << endl;
            break;

        case 4: // Division
            for (int i = 1; i < count; i++)
            {
                if (numbers[i] == 0)
                {
                    cout << "Error: Division by zero is not allowed.\n";
                    break;
                }
                result /= numbers[i];
            }
            cout << "Result (Division): " << result << endl;
            break;

        case 5: // Modulus (integers only)
        {
            int modResult = static_cast<int>(numbers[0]);

            for (int i = 1; i < count; i++)
            {
                int value = static_cast<int>(numbers[i]);

                if (value == 0)
                {
                    cout << "Error: Modulus by zero is not allowed.\n";
                    break;
                }

                modResult %= value;
            }

            cout << "Result (Modulus): " << modResult << endl;
            break;
        }
        }

        // Ask user if they want to run again
        cout << "\nWould you like to run the calculator again? (y/n): ";
        cin >> runAgain;
    }

    cout << "\nThanks for using the calculator. Goodbye!\n";
    return 0;
}
