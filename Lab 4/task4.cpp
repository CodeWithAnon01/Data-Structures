#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        cout << "gap = " << gap << endl;
        for (int i = gap; i < n; i++) {
            int tmp = arr[i];
            int j = i;
            while (j >= gap && arr[j-gap] > tmp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = tmp;
        }
    }
}

int insertionSortCount(int arr[], int n) {
    int shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
            shifts++;
        }
        arr[j+1] = key;
    }
    return shifts;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[20];
    cout << "enter 20 numbers: ";
    for (int i = 0; i < 20; i++) cin >> arr[i];

    cout << "gap sequence used by shell sort:" << endl;
    shellSort(arr, 20);
    cout << "shell sorted: ";
    printArr(arr, 20);

    int a1[5] = {50, 40, 30, 20, 10};
    int a2[5] = {50, 40, 30, 20, 10};

    cout << "\ncomparing on {50,40,30,20,10}:" << endl;
    cout << "shell sort gap sequence:" << endl;
    shellSort(a1, 5);

    int insShifts = insertionSortCount(a2, 5);
    cout << "insertion sort shifts: " << insShifts << endl;

    return 0;
}
