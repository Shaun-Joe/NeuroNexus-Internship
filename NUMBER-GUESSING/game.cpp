#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void playGame(int maxTries)
{
    srand(time(NULL));

    int num_to_guess = rand() % 100 + 1;
    int guess = 0;
    int tries = 0;

    cout << "Welcome to the Number Guessing Challenge!" << endl;
    cout << "The Computer is thinking of a number between 1 and 100." << endl;

    while ((maxTries == -1 || tries < maxTries) && guess != num_to_guess)
    {
        if (maxTries != -1)
        {
            cout << "You have " << (maxTries - tries) << " tries left." << endl;
        }

        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail() || guess < 1 || guess > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 100." << endl;
            continue;
        }


        if (guess < num_to_guess)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > num_to_guess)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You've guessed the number!" << endl;
            return;
        }

        tries++;
    }

    if (guess != num_to_guess)
    {
        cout << "Sorry, you've used all your tries. The number was " << num_to_guess << "." << endl;
    }
}
