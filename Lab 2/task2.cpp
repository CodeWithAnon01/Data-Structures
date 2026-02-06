#include <iostream>
using namespace std;

int main() {
    int studs = 5, subs = 4;
    int** marks = new int*[studs];
    for (int i = 0; i < studs; i++)
        marks[i] = new int[subs];

    cout << "enter marks for 5 students in 4 subjects:" << endl;
    for (int i = 0; i < studs; i++) {
        cout << "student " << i+1 << ": ";
        for (int j = 0; j < subs; j++)
            cin >> marks[i][j];
    }

    int topperIdx = 0, maxTotal = 0;
    cout << "\ntotals per student:" << endl;
    for (int i = 0; i < studs; i++) {
        int tot = 0;
        for (int j = 0; j < subs; j++)
            tot += marks[i][j];
        cout << "student " << i+1 << " total = " << tot << endl;
        if (tot > maxTotal) {
            maxTotal = tot;
            topperIdx = i;
        }
    }

    cout << "\navg marks per subject:" << endl;
    for (int j = 0; j < subs; j++) {
        int sum = 0;
        for (int i = 0; i < studs; i++)
            sum += marks[i][j];
        cout << "subject " << j+1 << " avg = " << (float)sum/studs << endl;
    }

    cout << "\ntopper is student " << topperIdx+1 << " with total " << maxTotal << endl;

    for (int i = 0; i < studs; i++)
        delete[] marks[i];
    delete[] marks;

    return 0;
}
