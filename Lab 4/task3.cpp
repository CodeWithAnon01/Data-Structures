#include <iostream>
using namespace std;

void insertionSortAsc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertionSortDesc(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "how many students marks: ";
    cin >> n;
    int* marks = new int[n];
    cout << "enter marks: ";
    for (int i = 0; i < n; i++) cin >> marks[i];

    insertionSortAsc(marks, n);
    cout << "sorted ascending: ";
    printArr(marks, n);
    delete[] marks;

    int arr2[5] = {15, 2, 78, 25, 63};
    cout << "\ntest descending on {15,2,78,25,63}: ";
    insertionSortDesc(arr2, 5);
    printArr(arr2, 5);

    return 0;
}
