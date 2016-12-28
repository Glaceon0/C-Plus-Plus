#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int seed;
    cout << "Random Seed?" << endl << "? ";
    cin >> seed;
    srand(seed);
   
    int numberToGuess = (rand() % 100) + 1;

    cout << "Guess a number between 1 and 100." << std::endl << "? ";
    
    int guess;
    bool correct = false;
    
do {
    cin >> guess;
    if (guess == numberToGuess) {
        correct = true;
    }
    else if (guess > numberToGuess) {
        cout << "Try lower." << endl << "? ";
    }
    else {
        cout << "Try higher." << endl << "? ";
    }
} while (correct == false);

    cout << "You guessed right!!!" << endl;
    
    return 0;
}