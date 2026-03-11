#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, bool earlyStop) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = true;
            }
        }
        if (earlyStop && !swapped) {
            cout << "stopped early at pass " << i+1 << endl;
            break;
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[10];
    cout << "enter 10 integers: ";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    int arrCopy[10];
    for (int i = 0; i < 10; i++) arrCopy[i] = arr[i];

    cout << "before sort: ";
    printArr(arr, 10);

    bubbleSort(arr, 10, false);
    cout << "after normal bubble sort: ";
    printArr(arr, 10);

    cout << "\nnow with early stop on: ";
    int arr2[5] = {1, 2, 3, 5, 4};
    cout << "\ntest arr: ";
    printArr(arr2, 5);
    bubbleSort(arr2, 5, true);
    cout << "sorted: ";
    printArr(arr2, 5);

    return 0;
}
