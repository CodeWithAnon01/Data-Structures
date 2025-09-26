#include <iostream>
using namespace std;

bool findpath(int mazegrid[5][5], int answerarray[5][5], int rowpos, int colpos) {
    if (rowpos == 4 && colpos == 4) {
        answerarray[rowpos][colpos] = 1;
        return true;
    }
    
    if (rowpos >= 0 && rowpos < 5 && colpos >= 0 && colpos < 5 && mazegrid[rowpos][colpos] == 1) {
        answerarray[rowpos][colpos] = 1;
        
        if (findpath(mazegrid, answerarray, rowpos + 1, colpos)) {
            return true;
        }
        
        if (findpath(mazegrid, answerarray, rowpos, colpos + 1)) {
            return true;
        }
        
        if (findpath(mazegrid, answerarray, rowpos - 1, colpos)) {
            return true;
        }
        
        if (findpath(mazegrid, answerarray, rowpos, colpos - 1)) {
            return true;
        }
        
        answerarray[rowpos][colpos] = 0;
        return false;
    }
    
    return false;
}

void displayresult(int answerarray[5][5]) {
    cout << "\nSolution array after lion reched the meat:" << endl;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            cout << answerarray[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Solving the maze problm to help lion find meat..." << endl;
    
    int mazegrid[5][5] = {
        {1, 1, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };
    
    int answerarray[5][5];
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            answerarray[row][col] = 0;
        }
    }
    
    cout << "Original maze (1=open path, 0=wall/obstacl):" << endl;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            cout << mazegrid[row][col] << " ";
        }
        cout << endl;
    }
    
    if (findpath(mazegrid, answerarray, 0, 0)) {
        cout << "\nLion sucessfully found the meat!" << endl;
        displayresult(answerarray);
    }
    else {
        cout << "\nNo valid path exists for lion to reach meat!" << endl;
    }
    
    return 0;
}