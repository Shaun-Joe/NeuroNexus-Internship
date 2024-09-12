#include <bits/stdc++.h>
#include "game.h"

using namespace std;

int main()
{
    int choice;

    cout << "Welcome to the Number Guessing Game Menu!" << endl;
    cout << "1. Play with a maximum number of tries" << endl;
    cout << "2. Play with 10 tries" << endl;
    cout << "3. Play with unlimited tries" << endl;
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int maxTries;
        cout << "Enter the maximum number of tries: ";
        cin >> maxTries;

        if (cin.fail() || maxTries <= 0)
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer." << endl;
            return 1;
        }

        playGame(maxTries);
        break;
    }
    case 2:
        playGame(10);
        break;
    case 3:
        playGame(-1);
        break;
    default:
        cout << "Invalid choice. Exiting the game." << endl;
        return 1;
    }

    return 0;
}
