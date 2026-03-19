#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int maze[10][10];
int visited[10][10];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
string dirNames[] = {"D", "R", "U", "L"};

void findPaths(int r, int c, string path) {
    if (r == N-1 && c == N-1) {
        cout << "path: " << path << endl;
        return;
    }
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N && maze[nr][nc] == 1 && !visited[nr][nc]) {
            visited[nr][nc] = 1;
            findPaths(nr, nc, path + dirNames[d]);
            visited[nr][nc] = 0;
        }
    }
}

int main() {
    cout << "enter maze size N: ";
    cin >> N;
    cout << "enter maze (0=blocked, 1=open):" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            visited[i][j] = 0;
        }

    if (maze[0][0] == 0 || maze[N-1][N-1] == 0) {
        cout << "start or end is blocked" << endl;
        return 0;
    }

    visited[0][0] = 1;
    cout << "all possible paths from (0,0) to (" << N-1 << "," << N-1 << "):" << endl;
    findPaths(0, 0, "");

    return 0;
}
