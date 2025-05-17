#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumberGenerator() {
    srand(time(0));
    return rand() % 10 + 1;
}

void checkGuess() {
    int chance = 3;
    int random = RandomNumberGenerator();
    int guess;
    int guesses[3];
    int index = 0;
    while (chance > 0) {
        cout << "\nGuess a number between (1-10): ";
        cin >> guess;
        guesses[index++]=guess;
        
        if (random == guess) {
            cout << "You are correct!";
            cout << "\nThe number is " << random << " and you guessed " << guess;
            cout << "\nYou win!";
            return; 
        } else {
            chance--;
            cout << "Oops, wrong guess. Remaining chances: " << chance;

            if (chance == 0) {
                cout << "\nThe number was " << random << " and you guessed " << guesses[0]<<" , "<<guesses[1]<<" And "<<guesses[2];
                cout << "\nYou lose!";
                return;
            }
        }
    }
}

int main() {
    int choice;

    do {
        cout << "--- Guessing Game ---";
        checkGuess();

        cout << "\n\nDo you want to play again? (1-Yes, 2-No): ";
        cin >> choice;
    } while (choice == 1);
    cout<<"\n****************************************";
    cout<<"\nThank You For Playing! Have A Great Day!";
    cout<<"\n****************************************";
    return 0;
}
