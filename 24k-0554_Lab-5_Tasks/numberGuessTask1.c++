#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playgame(int secretnumber, int currentplayer, int totalpayers) {
    int playerguess;
    cout << "Player " << currentplayer << ", enter your gues: ";
    cin >> playerguess;
    
    if (playerguess == secretnumber) {
        cout << "Congratulashions! Player " << currentplayer << " wins the game!" << endl;
        return;
    }
    else if (playerguess > secretnumber) {
        cout << "Too hig! Next player's turn." << endl;
    }
    else {
        cout << "Too low! Next player's turn." << endl;
    }
    
    int nextplayer = (currentplayer % totalpayers) + 1;
    playgame(secretnumber, nextplayer, totalpayers);
}

int main() {
    cout << "Welcome to the number guesing game!" << endl;
    
    srand(time(0));
    int secretnumber = (rand() % 100) + 1;
    int totalpayers;
    
    cout << "Enter number of payers: ";
    cin >> totalpayers;
    
    cout << "select a number between 1 and 100." << endl;
    playgame(secretnumber, 1, totalpayers);
    
    return 0;
}