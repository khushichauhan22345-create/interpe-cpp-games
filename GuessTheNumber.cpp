#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secretNumber, guess;
    int attempts = 0;

    // Generate a random number between 1 and 100
    srand(time(0));
    secretNumber = rand() % 100 + 1;

    cout << "==============================" << endl;
    cout << "      GUESS THE NUMBER GAME   " << endl;
    cout << "==============================" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "\nCongratulations! You guessed the number." << endl;
            cout << "Number of attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
