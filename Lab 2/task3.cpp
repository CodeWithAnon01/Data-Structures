#include <iostream>
using namespace std;

int main() {
    int numDepts;
    cout << "how many departments: ";
    cin >> numDepts;

    int* deptStuCount = new int[numDepts];
    for (int i = 0; i < numDepts; i++) {
        cout << "students in dept " << i+1 << ": ";
        cin >> deptStuCount[i];
    }

    int subs = 5;

    int*** data = new int**[numDepts];
    for (int i = 0; i < numDepts; i++) {
        data[i] = new int*[deptStuCount[i]];
        for (int j = 0; j < deptStuCount[i]; j++) {
            data[i][j] = new int[subs];
            cout << "marks for dept " << i+1 << " student " << j+1 << " (5 subs): ";
            for (int k = 0; k < subs; k++)
                cin >> data[i][j][k];
        }
    }

    cout << "\nresults per department:" << endl;
    for (int i = 0; i < numDepts; i++) {
        int highest = -1, lowest = 10000, totalAll = 0, cnt = 0;
        for (int j = 0; j < deptStuCount[i]; j++) {
            for (int k = 0; k < subs; k++) {
                int m = data[i][j][k];
                if (m > highest) highest = m;
                if (m < lowest) lowest = m;
                totalAll += m;
                cnt++;
            }
        }
        cout << "dept " << i+1 << " -> highest: " << highest
             << ", lowest: " << lowest
             << ", avg: " << (float)totalAll/cnt << endl;
    }

    for (int i = 0; i < numDepts; i++) {
        for (int j = 0; j < deptStuCount[i]; j++)
            delete[] data[i][j];
        delete[] data[i];
    }
    delete[] data;
    delete[] deptStuCount;

    return 0;
}
