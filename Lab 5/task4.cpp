#include <iostream>
using namespace std;

int N;
int board[20][20];
int solutionCount = 0;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row-1, j = col+1; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;
    return true;
}

void printBoard() {
    cout << "solution " << solutionCount << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

void solve(int row) {
    if (solutionCount >= 2) return;
    if (row == N) {
        solutionCount++;
        printBoard();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "enter N for N-Queens: ";
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    solve(0);
    if (solutionCount == 0)
        cout << "no solution found" << endl;
    return 0;
}
