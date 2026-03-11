#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target, int& comps) {
    int lo = 0, hi = n - 1;
    comps = 0;
    while (lo <= hi) {
        comps++;
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    int rolls[] = {101, 105, 110, 120, 135, 150};
    int n = 6;

    int target;
    cout << "enter roll number to search: ";
    cin >> target;

    int comps = 0;
    int idx = binarySearch(rolls, n, target, comps);

    if (idx != -1)
        cout << "Roll number found at index " << idx << endl;
    else
        cout << "Roll number not found" << endl;

    cout << "comparisons made: " << comps << endl;

    return 0;
}
