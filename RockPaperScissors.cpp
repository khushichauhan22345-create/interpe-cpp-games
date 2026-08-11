#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int choice, computer;

    srand(time(0));

    cout << "ROCK PAPER SCISSORS\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter your choice: ";
    cin >> choice;

    computer = rand() % 3 + 1;

    cout << "Computer chose: " << computer << endl;

    if (choice < 1 || choice > 3)
        cout << "Invalid choice!";
    else if (choice == computer)
        cout << "It's a draw!";
    else if ((choice == 1 && computer == 3) ||
             (choice == 2 && computer == 1) ||
             (choice == 3 && computer == 2))
        cout << "You win!";
    else
        cout << "Computer wins!";

    return 0;
}
